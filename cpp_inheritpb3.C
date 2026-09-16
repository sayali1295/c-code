
//This program is 3 level inheritance using public specifier
//cpp_inheritpb3.C


#include<iostream>
using namespace std;


class vehicle
{
	private:
		int wheels;
		int seats;

	public:
		void set_wheels(int w)
		{
			wheels = w;	
		}

		void set_seats(int s)
		{
			seats = s;
		}

		int get_wheels(void)
		{
			return wheels;
		}

		int get_seats(void)
		{
			return seats;
		}
};

class car : public vehicle
{
	private: 
		int maxspeed;

	public:
		void set_maxspeed(int sp)
		{
			maxspeed = sp;
		}

		int get_maxspeed(void)
		{
			return maxspeed;
		}
};

class truck : public car
{
	private:
		int maxload;

	public:
		void set_maxload(int l)
		{
			maxload = l;
		}

		int get_maxload(void)
		{
			return maxload;
		}

};

int main()
{
	truck t;
	
	t.set_wheels(4);

	t.set_seats(5);
	t.set_maxspeed(120);
	t.set_maxload(1000);

	cout << "Wheels = " << t.get_wheels() << '\n';

	cout << "Seats = " << t.get_seats() << '\n';

	cout << "maxspeed = " << t.get_maxspeed() << '\n';

	cout << "Load capacity of truck = " << t.get_maxload() << '\n';




}
