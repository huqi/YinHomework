#ifndef SIM_SYSTEM_PARAMETER_H
#define SIM_SYSTEM_PARAMETER_H

class SIM_System_Parameter
{
public:
	SIM_System_Parameter(void);
	~SIM_System_Parameter(void);
	void set_container(unsigned container);
	void set_truck(unsigned truck);
	void set_truck_capacity(unsigned truck_capacity);
	void set_container_capacity(unsigned container_capacity);
	void set_order_part_num(unsigned order_part_num);
	void set_folding_ratio(double folding_ratio);
	void set_loading_time(double loading_time);
	void set_unloading_time(double unloading_time);
	void set_transport_time(double transport_time);
	void set_working_time(double working_time);
	void set_production_rate(double production_rate);
	void set_order_rate(double order_rate);

	unsigned get_container(void);
	unsigned get_truck(void);
	unsigned get_truck_capacity(void);
	unsigned get_container_capacity(void);
	unsigned get_order_part_num(void);
	double get_folding_ratio(void);
	double get_loading_time(void);
	double get_unloading_time(void);
	double get_transport_time(void);
	double get_working_time(void);
	double get_production_rate(void);
	double get_order_rate(void);

private:
	unsigned container;
	unsigned truck;
	unsigned truck_capacity;
	unsigned container_capacity;
	unsigned order_part_num;

	double folding_ratio;
	double loading_time;
	double unloading_time;
	double transport_time;
	double working_time;
	double production_rate;
	double order_rate;
};

#endif /* SIM_SYSTEM_PARAMETER_H */