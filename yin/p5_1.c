
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <memory.h>

#ifdef __1000_HOURS__
#define SIM_TIME			1000*60
#elif defined(__10000_CUSTOMER__)
#define SIM_CUSTOMER	10000
#else
#define SIM_TIME			0xffff
#endif

#define MAX(A,B)			((A > B) ? (A) : (B))

enum event_type_t { ARRIVAL, DEPARTURE };

struct customer_t
{
    int id;
    double arrival_time;
};

struct customer_node_t
{
    struct customer_t customer;
    struct customer_node_t *next;
};

struct queue_t
{
    unsigned int count;
    struct customer_node_t *head;
};

struct system_t
{
    double current_time;
    double arrival_time;
    double service_time;
    double departure_time;
    double idle_time;
    double total_delay_time;
    double total_idle_time;
    double total_service_time;
    unsigned int total_queue;
    unsigned int total_queue_customer;
    unsigned int total_arrived;
    unsigned int total_served;
    unsigned int delay_customer_count;
    unsigned int max_queue_len;
    unsigned int total_4_5_customer;
    struct queue_t queue;
};

/* output method */
static void performance_begin(void)
{
    printf("--------------------------------------------\n");
    printf("SYSTEM-TIME        CUSTOMER-ID        EVENT\n");
    printf("--------------------------------------------\n");
}

static void performance(double time, unsigned int id, enum event_type_t event)
{
    char *str_event = (event == ARRIVAL) ? "ARRIVED" : "SERVED";

    printf("%12.6f        %5d           %8s\n", time, id, str_event);
}

static void performance_end(struct system_t *system)
{
    unsigned int remain = system->total_arrived - system->total_served;
    double ad = system->total_delay_time / system->total_served;
    double aqc = (double)system->total_queue_customer / system->total_queue;
#ifdef __10000_CUSTOMER__
    double total = system->current_time;
#else
    double total = SIM_TIME;
#endif

    //printf("--------------------------------------------\n");
#ifdef __10000_CUSTOMER__
    //printf("SIM-TIME:%.6f\n", system->current_time);
#else
    //printf("SIM-TIME:%.6f\n", (double)SIM_TIME);
#endif
    //printf("TOTAL-IDLE:%.6f\n", system->total_idle_time);
    //printf("TOTAL-SERVICE:%.6f\n", system->total_service_time);
    //printf("ARRIVAED:%d\n", system->total_arrived);
    //printf("SERVED:%d\n", system->total_served);
    //printf("REMAIN:%d\n", remain);
    //printf("TOTAL-QUEUE-CUSTOMER:%d\n", system->total_queue_customer);
    //printf("TOTAL-QUEUE:%d\n", system->total_queue);
    //printf("AVG-QUQUE-CUSTOMER:%.6f\n", aqc);
    //printf("TOTAL-DELAY:%.6f\n", system->total_delay_time);
    //printf("TOTAL-DELAY-CUSTOMER:%d\n", system->delay_customer_count);
    printf("average time that a customer waits in queue:%.6f\n", ad);
    printf("average number of customers in the queue:%.6f\n", aqc);
    //printf("MAX-QUEUE-LENGTH:%d\n", system->max_queue_len);
    //printf("4.5 CUSTOMER:%d\n", system->total_4_5_customer);
    printf("fraction of customers that spent more than 4.5 minutes in the system:%.6f%%\n",
            (double)system->total_4_5_customer / system->total_served * 100);
    printf("fraction of time that the system is busy:%.6f%%\n",
            (double)system->total_service_time / total * 100);
    //printf("--------------------------------------------\n");
}

/* get random time */
static double get_random(long long *init, double param)
{
    double u1 = 0;
    double result = 0;
    unsigned long long temp = 16807 * (*init);

    *init = temp % 2147483647;
    u1 = (double)(*init) / 2147483647;
    result = -1 / param * log(u1);

    return result;
}

static double get_time(enum event_type_t type)
{
    static long long arrival_initial = 1155192168;
    static long long service_initial = 1806794933;

    if (type == ARRIVAL)
        return get_random(&arrival_initial, 0.2);
    else
#ifdef __MD1__
        return 4.0;
#else
        return get_random(&service_initial, 0.25);
#endif
}

/* build customer */
static struct customer_t generate_customer(double arrival_time)
{
    static int id = 0;
    struct customer_t customer;

    memset(&customer, 0, sizeof(struct customer_t));

    customer.id = ++id;
    customer.arrival_time = arrival_time;

    return customer;
}

/* slim queue push method */
static void queue_push(struct queue_t *queue, struct customer_t *customer)
{
    struct customer_node_t **temp = &queue->head;
    struct customer_node_t *node = NULL;

    node = (struct customer_node_t *)malloc(sizeof(struct customer_node_t));
    memset(node, 0, sizeof(struct customer_node_t));

    node->customer = *customer;
    node->next = NULL;

    while (*temp != NULL)
        temp = &(*temp)->next;

    *temp = node;

    queue->count++;
}

/* slim queue pop method */
static struct customer_t queue_pop(struct queue_t *queue)
{
    struct customer_node_t *node = queue->head;
    struct customer_t customer;

    customer = node->customer;
    queue->head = node->next;

    free(node);
    queue->count--;

    return customer;
}

/* slim queue front method */
static struct customer_t queue_front(struct queue_t *queue)
{
    struct customer_node_t *node = queue->head;
    struct customer_t customer;

    memset(&customer, 0, sizeof(customer));
    if (queue->head != NULL)
        customer = queue->head->customer;

    return customer;
}

static enum event_type_t get_next_event(struct system_t *system)
{
    if (system->queue.count == 0)
        return ARRIVAL;

    if (system->arrival_time < system->departure_time)
        return ARRIVAL;

    return DEPARTURE;
};

static void arrival_process(struct system_t *system)
{
    struct customer_t customer;

    system->current_time = system->arrival_time;

    /* time 1000 hours check */
#ifdef __1000_HOURS__
    if (system->current_time > SIM_TIME)
    {
        if (system->idle_time != 0)
        {
            /* record idle time */
            system->total_idle_time += SIM_TIME - system->idle_time;
            system->idle_time = 0;
        }
        return ;
    }
#endif

    system->total_arrived++;

    /* queue up */
    customer = generate_customer(system->current_time);
    queue_push(&system->queue, &customer);

    //performance(system->current_time, customer.id, ARRIVAL);

    /* calculate next customer arrival time */
    system->arrival_time = system->current_time + get_time(ARRIVAL);

    if (system->queue.count == 1)
    {
        /* calculate service time */
        system->service_time = get_time(DEPARTURE);
        system->total_service_time += system->service_time;
        system->departure_time = system->current_time + system->service_time;
    }
    else if (system->queue.count > 1)
    {
        /* new queue */
        system->total_queue++;
        system->total_queue_customer += system->queue.count - 1;   /* 1 for serverd */
        system->max_queue_len = MAX(system->max_queue_len , system->queue.count - 1);
    }

    if (system->idle_time != 0)
    {
        /* record idle time */
        system->total_idle_time += system->current_time - system->idle_time;
        system->idle_time = 0;
    }
}

static void departure_process(struct system_t *system)
{
    struct customer_t customer = queue_pop(&system->queue);
    struct customer_t next_customer = queue_front(&system->queue);

    system->current_time = system->departure_time;
    system->total_served++;

    //performance(system->current_time, customer.id, DEPARTURE);

    /* delay record */
    if (next_customer.arrival_time != 0)
    {
        double delay_time = system->current_time - next_customer.arrival_time;
        if (delay_time > 0)
        {
            system->total_delay_time += delay_time;
            system->delay_customer_count++;
        }
    }

    /* 4.5 min */
    if (system->current_time - customer.arrival_time > 4.5)
        system->total_4_5_customer++;

    if (system->queue.count == 0)
    {
        /* idle */
        system->service_time = 0;
        system->departure_time = 0;
        system->idle_time = system->current_time;
    }
    else
    {
        if (system->queue.count > 1)
        {
            system->total_queue++;
            system->total_queue_customer += system->queue.count - 1;   /* 1 for serverd */
            system->max_queue_len = MAX(system->max_queue_len , system->queue.count - 1);
        }
        /* serve next customer */
        system->service_time = get_time(DEPARTURE);
        system->total_service_time += system->service_time;
        system->departure_time = system->current_time + system->service_time;
    }
}

static void init(struct system_t *system)
{
    memset(system, 0, sizeof(struct system_t));
    srand((unsigned int)time(NULL));

    /* first arrival time */
    system->arrival_time = get_time(ARRIVAL);
    system->total_idle_time = system->arrival_time;
}

static void deinit(struct system_t *system)
{
    /* free remaind customer */
    while (system->queue.count != 0)
        queue_pop(&system->queue);

    memset(system, 0, sizeof(struct system_t));
}

int main(int argc, char **argv)
{
    struct system_t system;

    init(&system);
    //performance_begin();

#ifdef __10000_CUSTOMER__
    while (system.total_served < SIM_CUSTOMER)
#else
    while (system.current_time < SIM_TIME)
#endif
    {
        enum event_type_t event = get_next_event(&system);
        switch (event)
        {
        case ARRIVAL:
            arrival_process(&system);
            break;
        case DEPARTURE:
            departure_process(&system);
            break;
        default:
            break;
        }
    }

    performance_end(&system);
    deinit(&system);

    return 0;
}
