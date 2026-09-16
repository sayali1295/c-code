//This program is implementing friend class
//cpp_friend_class.C


#include<iostream>
using namespace std;

class A
{

	private:
		friend class B;
		int i ;
	public:
		A(){}

		A(int value)
		{
			i = value;
		}
	/*	int get_i(void)
		{
			return i;
		}*/
};

class B
{
	private:
	       	int j;

	public:
		B(){}
       		
		B(int num1)
		{
			j = num1;
		}		
		int get_j()
		{
			return j;
		}

		int get_classA(A  a)
		{
			return a.i;
		}
};

int main()
{
	int num;
	A objA(2);
	B objB(10);
//	cout << objA.get_i();
	cout << "value of j: " << objB.get_j() << endl;
	cout << "value of i: " << objB.get_classA(objA) << endl;


}
