//This program is checking if function call in array declaration works or not
//cpp_f_in_arr.C


#include<iostream>
using namespace std;

constexpr int sum(int , int );
int main()
{
	cout << "\nProgram is checking if function call in array declaration works or not\n";

	int i;
	int x, y;
	cout << "Enter two numbers: " << '\n';
	cin >> x >> y;
	int arr[i = sum(x,y)];


	cout << "\nProgram is working\n";
	cout << "The sum is: " << i << '\n';

	arr[0]=12;
	cout << arr[0];
}

constexpr int sum(int a, int b)
{
	int total = a + b;
	return total;
}
