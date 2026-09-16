// This program is checking protected access specifier
// cpp_inheritpropb2.c


#include<iostream>
using namespace std;

class vehicle
{
	private:
		int speed;
	protected:
		int wheels;
	public:
		void set_wheels(int w)
		{
			wheels = w;
		}

		int get_wheels(void)
		{
			return wheels;
		}

		void set_speed(int s)
		{
			speed = s;
		}

		int get_speed(void)
		{
			return speed;
		}
};

class car : public vehicle
{
	private:
		int gears;
	protected:
		int seats;

	public:
		void set_seats(int s)
		{
			seats = s;
		}

		int get_seats(void)
		{
			return seats;
		}

		void set_gears(int g)
		{
			gears = g;
		}

		int get_gears(void)
		{
			return gears;
		}
	
};

class truck : public car
{
	private:
		float fuel_cap;
	protected:
		int load_cap;

	public:
		void set_fuelcap(float c)
		{
			fuel_cap = c;
		}	
		
		float get_fuelcap(void)
		{
			return fuel_cap;
		}


};
int main()
{

	truck c;
	c.set_speed(120);
	c.set_wheels(4);
	c.set_seats(5);
	c.set_gears(5);
	c.set_fuelcap(10.5);


	cout << "speed: " << c.get_speed() << '\n'; 
	
	cout << "wheels: " << c.get_wheels() << '\n'; 

	cout << "seats: " << c.get_seats() << '\n'; 

	cout << "gears: " << c.get_gears() << '\n'; 

	cout << "Fuel capacity: " << c.get_fuelcap() << '\n'; 

return 0;
}



