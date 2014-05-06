#ifndef SIM_WAY_H
#define SIM_WAY_H

class SIM_WAY
{
public:
	SIM_WAY::SIM_WAY(void);
	SIM_WAY::~SIM_WAY(void);
	void set_truck(unsigned truck);
	unsigned get_truck(void);

private:
	unsigned truck;
};

#endif /* SIM_WAY_H */