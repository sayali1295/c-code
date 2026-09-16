/*This program is implementing 1 friend function of 2 classes A & B
 * In this we are summing class A (i) with class B (i) and
 * same class A (j) with class B (j)
 * cpp_frndfunof_2class.C */

#include<iostream>
using namespace std;

//class B;

class A
{
	private:
		int i, j;
		friend void sum(class A, class B, int &, int &); // friend function of a class


	public: 
		A(){}

		A(int a, int b)
		{
			i = a;
			j = b;
		}
		~A(){cout << "DA" << endl;}
};

class B
{
	private:
		int i, j;
		friend void sum(class A, class B, int &, int &);


	public: 
		B(){}

		B(int a, int b)
		{
			i = a;
			j = b;
		}
		~B(){cout << "DB" << endl;}
};

void sum(class A obj1, class B obj2, int &sumI, int &sumJ)
{

	sumI = obj1.i + obj2.i;
	sumJ = obj1.j + obj2.j;

}
int main()
{
	int sum1, sum2;
	A obj1 (10, 6);
	B obj2 (5, 8);
	sum (obj1, obj2, sum1, sum2);

	cout << "Sum of both i is: " << sum1 << endl;
	
	cout << "Sum of both j is: " << sum2 << endl;

return 0;
}
