#include <iostream>
#include "SIM_System.h"

using namespace std;

void init_parameter(SIM_System_Parameter &param)
{
	cout << "Init system parameter" << endl;
	
	unsigned container;
	cout << "Enter container num:";
	cin >> container;
	param.set_container(container);

	unsigned truck;
	cout << "Enter truck num:";
	cin >> truck; 
	param.set_truck(truck);

	unsigned truck_capacity;
	cout << "Enter truck capacity:";
	cin >> truck_capacity;
	param.set_truck_capacity(truck_capacity);

	unsigned container_capacity;
	cout << "Enter container capacity:";
	cin >> container_capacity;
	param.set_container_capacity(container_capacity);

	double folding_ratio;
	cout << "Enter folding ratio:";
	cin >> folding_ratio;
	param.set_folding_ratio(folding_ratio);

	double loading_time;
	cout << "Enter loading time:";
	cin >> loading_time;
	param.set_loading_time(folding_ratio);

	double unloading_time;
	cout << "Enter unloading time:";
	cin >> unloading_time;
	param.set_unloading_time(unloading_time);

	double transport_time;
	cout << "Enter transport time:";
	cin >> transport_time;
	param.set_transport_time(transport_time);

	double working_time;
	cout << "Enter working time:";
	cin >> working_time;
	param.set_working_time(working_time);

	double production_rate;
	cout << "Enter production rate:";
	cin >> production_rate;
	param.set_production_rate(production_rate);

	double order_rate;
	cout << "Enter order rate:";
	cin >> order_rate;
	param.set_order_rate(order_rate);
}

int main(int argc, char *argv[])
{
	SIM_System sim_system("system_parameter.txt");

	sim_system.run();

	return 0;
}