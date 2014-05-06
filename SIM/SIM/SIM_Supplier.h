#ifndef SIM_SUPPLIER_H
#define SIM_SUPPLIER_H

class SIM_Supplier
{
public:
	SIM_Supplier(void);
	~SIM_Supplier(void);
	void increase_part(void);
	void increase_container_filled(void);
	void set_part(unsigned part);
	void set_container_empty(unsigned container_empty);
	void set_container_filled(unsigned container_filled);
	void set_order(unsigned order);
	unsigned get_part(void) const;
	unsigned get_container_empty(void) const;
	unsigned get_container_filled(void) const;
	unsigned get_order(void) const;
	void show(void);

private:
	unsigned order;
	unsigned part;
	unsigned container_empty;
	unsigned container_filled;
};


#endif /* SIM_SUPPLIER_H */