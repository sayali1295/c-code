//This program is performing swapping using reference variable
//cpp_swap_ref_var.C



#include<iostream>
using namespace std;

int main()
{
	int q;
	int f;
	cout << "Program for swapping numbers using reference variable\n";	
	cout << "Enter two integer numbers\n";
	cin >> q >> f;

	int &a = q;
	int &b = f;

	cout << "Values before swapping: " << a << '\t' << b << '\n'; 
	
	swap(a, f);
	cout << "Values after swapping:  " << a << '\t' << b << '\n'; 
}

void swap (int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
