//This program is implementing friend function of a class
//cpp_friend_fun.C 

#include<iostream>
using namespace std;

class A
{

	private:
		int i, j;
		friend int sum(class A); // friend function of a class


	public: 
		A(){}

		A(int a, int b)
		{
			i = a;
			j = b;
		}
	//	friend int sum(class A); prototype of friend function can be written anywhere in private, protected and public

};

int sum(class A obj)
{

	int u =  obj.i + obj.j;
	
	
	return u;
}

int main()
{

	int num1, num2;
	cout << "Please enter 2 numbers: " << endl;
	cin >> num1 >> num2;

	A obj(num1, num2);

//	A obj (10, 56);

	cout << "Sum is: " << sum(obj)<< endl;

return 0;
}
