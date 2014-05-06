#include <iostream>
#include "SIM_Event.h"


SIM_Event::SIM_Event(void)
{
	time = 0;
	type = NONE;
}

SIM_Event::SIM_Event(const SIM_Event &other_event)
{
	time = other_event.get_time();
	type = other_event.get_type();
}

SIM_Event::SIM_Event(double time, enum event_t type)
{
	this->time = time;
	this->type = type;
}

SIM_Event::~SIM_Event(void)
{

}

void SIM_Event::set_time(double time)
{
	this->time = time;
}

double SIM_Event::get_time(void) const
{
	return time;
}

void SIM_Event::set_type(enum event_t event)
{
	this->type = event;
}

enum event_t SIM_Event::get_type(void) const
{
	return type;
}

SIM_Event &SIM_Event::operator=(const SIM_Event &other_event)
{
	time = other_event.get_time();
	type = other_event.get_type();

	return *this;
}