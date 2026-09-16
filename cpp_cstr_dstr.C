//This program is of Constructor Overloading
//cpp_cstr_dstr.cpp


#include<iostream>
using namespace std;


class abc
{
	public:
		abc()
		{
			cout << "Default constructor\n";
		}
		abc(int a, int b)
		{
			x=a;
			y=b;
			cout << "Inside Parameterized Constructor\n";
		}
		~abc()
		{
			
			cout << "Inside Destructor\n";
		}
	private:
		int x;
		int y;
		

};

int main()
{
	abc obj(12,20);
}
