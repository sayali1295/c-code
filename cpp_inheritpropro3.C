// This program is checking protected access specifier
// cpp_inheritpropro3.C


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

class car : protected vehicle
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

class truck : protected car
{
	private:
		float fuel_cap;
	protected:
		int load_cap;

	public:
		void set_fuelcap(float c, int i, int j)
		{
			fuel_cap = c;
			set_seats(3);
			set_gears(5);
		}	
		
		float get_fuelcap(void)
		{
			return fuel_cap;
		}
		
		void get_allcar(int &a, int &b)
		{
			a = get_seats();
			b = get_gears();	
		}

		void get_allveh(int f, int u, int &v, int &p)
		{
			set_wheels(10);
			set_speed(180);
			v = get_wheels();
			p = get_speed();
		}

};
int main()
{

	truck c;
	int x, y;
	int q, m;

	c.set_fuelcap(10.5, 3, 5);
	c.get_allcar(x, y);
	c.get_allveh(10, 180, q, m);


	cout << "speed: " << m << '\n'; 
	
	cout << "wheels: " << q << '\n'; 

	cout << "seats: " <<  x << '\n'; 
	
	cout << "gears: " << y << '\n'; 

	cout << "Fuel capacity: " << c.get_fuelcap() << '\n'; 

return 0;
}



