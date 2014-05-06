#include <iostream>
#include "SIM_Supplier.h"

using namespace std;

SIM_Supplier::SIM_Supplier(void)
{
	order = 0;
	part = 0;
	container_empty = 0;
	container_filled = 0;
}

SIM_Supplier::~SIM_Supplier(void)
{

}

void SIM_Supplier::increase_part(void)
{
	part++;
}

void SIM_Supplier::increase_container_filled(void)
{
	container_filled++;
}

void SIM_Supplier::set_part(unsigned part)
{
	this->part = part;
}

void SIM_Supplier::set_container_empty(unsigned container_empty)
{
	this->container_empty = container_empty;
}

void SIM_Supplier::set_container_filled(unsigned container_filled)
{
	this->container_filled = container_filled;
}


void SIM_Supplier::set_order(unsigned order)
{
	this->order = order;
}

unsigned SIM_Supplier::get_part(void) const
{
	return part;
}

unsigned SIM_Supplier::get_container_empty(void) const
{
	return container_empty;
}

unsigned SIM_Supplier::get_container_filled(void) const
{
	return container_filled;
}

unsigned SIM_Supplier::get_order(void) const
{
	return order;
}

void SIM_Supplier::show(void)
{
	cout << "--------------------Supplier Status----------------" << endl
		 << "Order:" << order << endl
		 << "Part: " << part << endl
		 << "Container empty:" << container_empty << endl
		 << "Container filled:" << container_filled << endl
		 << "---------------------------------------------------" << endl;

	system("pause");
}