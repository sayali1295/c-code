// This program is checking protected access specifier
// cpp_inheritpropb2.c


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

class car : public vehicle
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
	
};
int main()
{

	car c;
	c. set_wheels(4);
	c.set_seats(5);

	cout << "wheels: " << c.get_wheels() << '\n'; 

	cout << "seats: " << c.get_seats() << '\n'; 



return 0;
}



