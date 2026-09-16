/*This program is implementing class B a friend class of class A
In this program we are checking largest number among 2 numbers using ternary operator 
cpp_frndcls_largest.C */


#include<iostream>
using namespace std;

class A
{

	private:
		friend class B;
		int i, j;
	public:
		A(){}

		A(int value1, int value2)
		{
			i = value1;
			j = value2;
		}
};

class B
{
	public:
		int get_classA(A a, A b)
		{
			int largest;
			largest = (a.i > a.j) ? a.i : a.j;
			return largest;	
		}
};

int main()
{
	A a(2, 5);
	B b;
	cout << b.get_classA(a, a) << " is largest number" << endl;


}
