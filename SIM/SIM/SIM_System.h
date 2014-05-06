#ifndef SIM_SYSTEM_H
#define SIM_SYSTEM_H

#include <iostream>
#include <vector>

#include "SIM_System_Parameter.h"
#include "SIM_Supplier.h"
#include "SIM_Way.h"
#include "SIM_Event.h"

using namespace std;

class SIM_System
{
public:
	SIM_System::SIM_System(void);
	SIM_System::SIM_System(char *filename);
	SIM_System::~SIM_System(void);
	void init(char *filename);
	void run(void);
	bool is_running(void);

private:
	enum event_t get_next_event(void);
	void produce_complete_process(void);
	void new_order_process(void);
	void generate_event(double time, enum event_t evt);
	void load_parameter(char *filename);

private:
	double current_time;
	double next_order_time;
	double next_complete_time;
	SIM_WAY way;
	SIM_Supplier supplier;
	SIM_System_Parameter parameter;
	vector<SIM_Event> event_queue;
	bool running;
};


#endif /* SIM_SYSTEM_H */