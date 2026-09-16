// This program is checking protected access specifier
// cpp_inheritpropv2.c


#include<iostream>
using namespace std;

class vehicle
{
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
};

class car : private vehicle
{
	
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

		void get_vehfunc(int &a, int &r)
		{
			set_wheels(4);
			r = get_wheels();
			
		}
	
};
int main()
{

	car c;
	int w, y;

	c.set_seats(5);
	c.get_vehfunc(w, y);

	cout << "wheels: " << y << '\n'; 

	cout << "seats: " << c.get_seats() << '\n'; 



return 0;
}



