//This program to study scope of access specifiers
//cpp_study_specifiers_pbpb.C


#include<iostream>
using namespace std;

class B
{
	private:
		int i;
	protected:
		int j;
	public:
		int k;

};
class D1 : private B
{
	protected:
		int y;
	public: 
		int o;
		void set_i(int num1)
		{
			i = num1;	
		}
		int get_i(void)
		{
			return i;
		}
		
		void set_j(int num2)
		{
			j = num2;	
		}
		
		void set_k(int num3)
		{
			k = num3;	
		}	
		
};

class D2 : private D1
{
	private:
		int e;
	protected:
		int z;
	public:		
		int u;
		void set_o(int num5)
		{
			o = num5;	
		}
		int get_o(void)
		{
			return o;
		}
		
		void set_f(int num6)
		{
			f = num6;	
		}

		void set_y(int num7)
		{
			y = num7;	
		}
		void set_i(int num8)
		{
			i = num8;	
		}

		void set_j(int num9)
		{
			j = num9;	
		}

		void set_k(int num10)
		{
			k = num10;	
		}

};

/*int main()
{
	// here public, private, protected of class B got access
	D1 v;
	v.set_j(3);
	cout << "j = " << v.get_j() <<endl;
	v.set_i(10);
	cout << "i = " << v.get_i() <<endl; 
	
	// here public, private of class B got access but protected didn't
	D2 c;
	v.set_j(3);
	cout << "j = " << c.get_j() <<endl;
	c.set_i(10);
	cout << "i = " << c.get_i() <<endl; 

	// here public, private, protected of class D1 got access	
	v.set_f(5);
	cout << "f = " << v.get_f() <<endl;
	v.set_y(6);
	cout << "y = " << v.get_y() <<endl; 
}*/

