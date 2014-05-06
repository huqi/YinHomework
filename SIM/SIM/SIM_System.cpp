#include <iostream>
#include <fstream>
#include "SIM_System.h"

using namespace std;

SIM_System::SIM_System(void)
{
	running = true;
	current_time = 0;
}

SIM_System::SIM_System(char *filename)
{
	running = true;
	current_time = 0;
	next_order_time = 0;
	next_complete_time = 0;

	init(filename);
}

SIM_System::~SIM_System(void)
{

}

void SIM_System::init(char *filename)
{
	load_parameter(filename);

	supplier.set_container_empty(parameter.get_container());
}

void SIM_System::load_parameter(char *filename)
{
	char comment[1024] = {0};
	ifstream in_file(filename, ios::in);

	cout << "Load system parameter from " << filename << endl;

	if (!in_file)
	{
		cerr << "File " << filename << " could not be opened" << endl;
		exit(1);
	}

	unsigned container;
	in_file >> container;
	in_file.getline(comment, sizeof(comment));
	parameter.set_container(container);

	unsigned truck;
	in_file >> truck; 
	in_file.getline(comment, sizeof(comment));
	parameter.set_truck(truck);

	unsigned truck_capacity;
	in_file >> truck_capacity;
	in_file.getline(comment, sizeof(comment));
	parameter.set_truck_capacity(truck_capacity);

	unsigned container_capacity;
	in_file >> container_capacity;
	in_file.getline(comment, sizeof(comment));
	parameter.set_container_capacity(container_capacity);

	unsigned order_part_num;
	in_file >> order_part_num;
	in_file.getline(comment, sizeof(comment));
	parameter.set_order_part_num(order_part_num);

	double folding_ratio;
	in_file >> folding_ratio;
	in_file.getline(comment, sizeof(comment));
	parameter.set_folding_ratio(folding_ratio);

	double production_rate;
	in_file >> production_rate;
	in_file.getline(comment, sizeof(comment));
	parameter.set_production_rate(production_rate);

	double loading_time;
	in_file >> loading_time;
	in_file.getline(comment, sizeof(comment));
	parameter.set_loading_time(folding_ratio);

	double unloading_time;
	in_file >> unloading_time;
	in_file.getline(comment, sizeof(comment));
	parameter.set_unloading_time(unloading_time);

	double transport_time;
	in_file >> transport_time;
	in_file.getline(comment, sizeof(comment));
	parameter.set_transport_time(transport_time);

	double working_time;
	in_file >> working_time;
	in_file.getline(comment, sizeof(comment));
	parameter.set_working_time(working_time);

	double order_rate;
	in_file >> order_rate;
	in_file.getline(comment, sizeof(comment));
	parameter.set_order_rate(order_rate);
}

enum event_t SIM_System::get_next_event(void)
{
	if (current_time == next_order_time)
	{
		return NEW_ORDER;
	}

	if (next_complete_time == 0)
	{
		return NEW_ORDER;
	}

	if (next_order_time < next_complete_time)
	{
		return NEW_ORDER;
	}

	return PRODUCE_COMPLETE;
}

void SIM_System::generate_event(double time, enum event_t evt)
{
	SIM_Event event(time, evt);

	event_queue.push_back(event);
}


void SIM_System::produce_complete_process(void)
{
	double time = next_complete_time - current_time;
	current_time = next_complete_time;

	cout << "produce complete!" << endl;
	next_complete_time = 0;
}


void SIM_System::new_order_process(void)
{
	double time = 0;
	vector<double> time_vec;
	current_time = next_order_time;

	cout << "new order!" << endl;

	supplier.set_order(parameter.get_order_part_num());

	for (unsigned i = 0; i < supplier.get_order(); ++i)
	{
		time += parameter.get_production_rate();
		supplier.increase_part();

		if (supplier.get_part() == parameter.get_container_capacity())
		{
			supplier.set_part(0);
			supplier.increase_container_filled();
		}

		if (supplier.get_container_filled() == parameter.get_truck_capacity())
		{
			supplier.set_container_filled(0);
			time_vec.push_back(time);
		}
	}

	for (vector<double>::iterator iter = time_vec.begin(); iter != time_vec.end(); ++iter)
	{
		double departure_time_p = *iter + parameter.get_loading_time();
		double arrival_factory_time_p = departure_time_p + parameter.get_transport_time();

		double offset_time = time - *iter;
		//if (offset - parameter.)

	}

	if (next_complete_time == 0)
	{
		next_complete_time = current_time + time;
	}
	else
	{
		cout << endl << "[ERROR] supplier new order comming, but pre order have not done yet" << endl;
		next_complete_time += time;
	}

	next_order_time = current_time + parameter.get_order_rate();
}


bool SIM_System::is_running(void)
{
	return running;
}

void SIM_System::run(void)
{
	while (is_running())
	{
		switch(get_next_event())
		{
		case NEW_ORDER:
			new_order_process();
			break;
		case PRODUCE_COMPLETE:
			produce_complete_process();
			break;
		default:
			break;
		}
	}
}