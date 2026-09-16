#include<cstdio>
#include<iostream>
using namespace std;

class emp
{
	private:
		int i;
	public: 

		void set_i(int);
		int get_i (void);
		~emp()
		{
			cout << "\nInside Destructor\n";
		}
};

void emp :: set_i(int i)
{
	this-> i = i;	
};

int emp :: get_i(void)
{
	return i;
}

int main()
{
	
emp e[4];
int j = 0;
int k = 0;
int a;

cout << "Program of c++ for class object array\n";
cout << "\nThis program is storing 5 values of i\n\n";

while (j <= 4)
{
	cout << "Please enter " << j+1 << " value of i\n";	
	cin >> a;
	e[j].set_i(a);
	j++; 
} 

cout << "\nBelow is the output of the program :\n";
cout << "\nValues of i\tAddress of i\n";

while (k <= 4)
{
	cout << e[k].get_i() << '\t' << '\t' << &e[k] << '\n';
	k++;
}

return 0;
}
