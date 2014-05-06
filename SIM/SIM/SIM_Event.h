#ifndef SIM_EVENT_H
#define SIM_EVENT_H

typedef enum event_t
{
	PRODUCE_COMPLETE,
	NEW_ORDER,
	NONE
};

class SIM_Event
{
public:
	SIM_Event(void);
	SIM_Event(double time, enum event_t type);
	SIM_Event(const SIM_Event &other_event);
	~SIM_Event(void);

	void set_time(double time);
	void set_type(enum event_t type);
	double get_time(void) const;
	enum event_t get_type(void) const;
	SIM_Event &operator=(const SIM_Event &other_event);

private:
	double time;
	enum event_t type;
};


#endif /* SIM_EVENT_H */