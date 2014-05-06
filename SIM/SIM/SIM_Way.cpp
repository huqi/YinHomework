#include <iostream>
#include "SIM_Way.h"

using namespace std;

SIM_WAY::SIM_WAY(void)
{
	truck = 0;
}

SIM_WAY::~SIM_WAY(void)
{

}

void SIM_WAY::set_truck(unsigned truck)
{
	this->truck = truck;
}

unsigned SIM_WAY::get_truck(void)
{
	return truck;
}