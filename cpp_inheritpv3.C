
//This program is 3 level inheritance using private specifier
//cpp_inheritpv3.C


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
	protected:

};

class car : private vehicle
{
	private: 
		int maxspeed;

	public:
		void set_maxspeed(int sp)
		{
			maxspeed = sp;
			set_wheels(4);
			set_seats(5);
		}

		int get_maxspeed(void)
		{
			return maxspeed;
		}
		void get_allveh_fun(int &wh, int &se)
		{
			wh = get_wheels();
			se = get_seats();
		}
};

class truck : private car
{
	private:
		int maxload;

	public:
		void set_maxload(int l)
		{
			maxload = l;
			set_maxspeed(120);		
		}

		int get_maxload(void)
		{
			return maxload;
		}

		void get_allcar_fun(int &wh, int &se, int &sp)
		{
			get_allveh_fun(wh, se);
			sp = get_maxspeed();	
		}

};

int main()
{
	truck t;
	int x, y, z;

	t.set_maxload(1000);

	t.get_allcar_fun(x,y,z);

	cout << "Wheels = " << x << '\n';

	cout << "seats = " << y << '\n';

	cout << "maxspeed = " << z << '\n';

	cout << "Load capacity of truck = " << t.get_maxload() << '\n';

return 0;
}
