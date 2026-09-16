// This program is for inheritance
// cpp_inheritpb.C


#include<iostream>
using namespace std;

class vehicle
{
	private:
		char br_name[10]= "NEXA";
	public:
		int no_of_wheels = 4;
		char fuel[10] = "Petrol";
		int seat = 5;

		void get_br_name(char name[])
		{
			cout << "Brand name : " << br_name << '\n'; 
		}
};

class car : public vehicle
{
	private:
		char o_name[20]= "Suhas Patil";
	public: 
		char variant[20] = "GRAND VITARA";
		void get_o_name(char arr[])
		{
			cout << "Owner name: " << o_name << '\n';
		}
};

int main()
{
	car mycar;
	char bname[10];
	char oname[10];

	mycar.get_o_name(oname);
	mycar.get_br_name(bname);
	
	cout << "variant is: " << mycar.variant << '\n';
	cout << "No. of wheels: " << mycar.no_of_wheels << '\n';

	cout << "Fuel type is: " << mycar.fuel << '\n';

	cout << "No. of seats: " << mycar.seat << '\n';

return 0;
}
