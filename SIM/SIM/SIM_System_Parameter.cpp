#include <iostream>
#include "SIM_System_Parameter.h"

SIM_System_Parameter::SIM_System_Parameter(void)
{
	container = 0;
	truck = 0;
	truck_capacity = 0;
	container_capacity = 0;
	folding_ratio = 0;
	loading_time = 0;
	unloading_time = 0;
	transport_time = 0;
	working_time = 0;
	production_rate = 0;
	order_rate = 0;
}

SIM_System_Parameter::~SIM_System_Parameter(void)
{
	
}

void SIM_System_Parameter::set_container(unsigned container)
{
	this->container = container;
}

void SIM_System_Parameter::set_truck(unsigned truck)
{
	this->truck = truck;
}

void SIM_System_Parameter::set_truck_capacity(unsigned truck_capacity)
{
	this->truck_capacity = truck_capacity;
}

void SIM_System_Parameter::set_container_capacity(unsigned container_capacity)
{
	this->container_capacity = container_capacity;
}

void SIM_System_Parameter::set_order_part_num(unsigned order_part_num)
{
	this->order_part_num = order_part_num;
}

void SIM_System_Parameter::set_folding_ratio(double folding_ratio)
{
	this->folding_ratio = folding_ratio;
}

void SIM_System_Parameter::set_loading_time(double loading_time)
{
	this->loading_time = loading_time;
}

void SIM_System_Parameter::set_unloading_time(double unloading_time)
{
	this->unloading_time = unloading_time;
}

void SIM_System_Parameter::set_transport_time(double transport_time)
{
	this->transport_time = transport_time;
}

void SIM_System_Parameter::set_working_time(double working_time)
{
	this->working_time = working_time;
}

void SIM_System_Parameter::set_production_rate(double production_rate)
{
	this->production_rate = production_rate;
}

void SIM_System_Parameter::set_order_rate(double order_rate)
{
	this->order_rate = order_rate;
}

unsigned SIM_System_Parameter::get_container(void)
{
	return container;
}

unsigned SIM_System_Parameter::get_truck(void)
{
	return truck;
}

unsigned SIM_System_Parameter::get_truck_capacity(void)
{
	return truck_capacity;
}

unsigned SIM_System_Parameter::get_container_capacity(void)
{
	return container_capacity;
}

unsigned SIM_System_Parameter::get_order_part_num(void)
{
	return order_part_num;
}

double SIM_System_Parameter::get_folding_ratio(void)
{
	return folding_ratio;
}

double SIM_System_Parameter::get_loading_time(void)
{
	return loading_time;
}

double SIM_System_Parameter::get_unloading_time(void)
{
	return unloading_time;
}

double SIM_System_Parameter::get_transport_time(void)
{
	return transport_time;
}

double SIM_System_Parameter::get_working_time(void)
{
	return working_time;
}

double SIM_System_Parameter::get_production_rate(void)
{
	return production_rate;
}

double SIM_System_Parameter::get_order_rate(void)
{
	return order_rate;
}