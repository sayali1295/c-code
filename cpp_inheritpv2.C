// This program is for inheritance
// cpp_inheritpv.C


#include<iostream>
#include<string.h>
using namespace std;

class vehicle
{
	private:
		int wheels;
		int seats;
		char fuel[10];
		int maxspeed;
	public:
		void set_wheels(int w)
		{
			wheels = w;
		}

		void set_seats(int s)
		{
			seats = s;
		}

		void set_fuel(char f[])
		{
			strcpy(fuel, f);
		}

		int get_seats(void)
		{
			return seats;
		}

		char* get_fuel(void)
		{
			return fuel;
		}
		int get_wheels(void)
		{
			return wheels;	
		}
		void set_maxspeed(int p)
		{
			maxspeed = p;
		}
		int get_maxspeed(void)
		{
			return maxspeed;
		}
};

class car : private vehicle
{
	private: 
		char brand[10];
		/* These private and public of vehicle class to be derived in private of car class
		 *
		 * int wheels, int seats, int maxspeed, char fuel
		 * set_wheels(), set_seats(), set_fuels(), get_seats(), get_fuel(), get_wheels
		 */
		public:
		void set_brand(char b[])
		{
			strcpy(brand,b);
			set_wheels(4);
			set_seats(5);
			set_maxspeed(100);

			char str[] = "Petrol";
			set_fuel(str);
		}	
		
		char* get_brand(void)
		{
			return brand;
		}
		
/*		void get_allveh_fun(void)
		{
			int wh = get_wheels();
			cout << "No of wheels: " << wh << '\n';
			int se = get_seats();
			cout << "No of seats: " << se << '\n';
			char *fu = get_fuel();
			cout << "Fuel type: " << fu << '\n';
		}	*/
		void get_allveh_fun(int &wh, int &se, int &spd)
		{
			wh = get_wheels();
			se = get_seats();
			spd = get_maxspeed();
		}	
		
		
};
		
int main()
{
	car obj;
	int x, y, z;
	char str1[] = "TATA";
	obj.set_brand(str1);
	
	cout << "Brand name: " << obj.get_brand() << '\n';

	obj.get_allveh_fun(x, y, z);

	cout << "No. of wheels: " << x << '\n';
	cout << "No. of seats: " << y << '\n';
	cout << "Max speed : " << z << '\n';

return 0;
}
