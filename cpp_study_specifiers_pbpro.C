//This program to study scope of access specifiers
//cpp_study_specifiers_pbpv.C


#include<iostream>
using namespace std;

class B
{
	private:
		int i;
	protected:
		int j;
	public:
		//implementation of public member function

		int u;
		void set_u(int n1)
		{
			u = n1;
		}
		int get_u(void)
		{
			return u;
		}

		//implementation of private, protected member functions

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
		int get_j(void)
		{
			return j;
		}
};

class D1 : public B
{
	private: 
		int f;
	protected:
		int y;
	public: 
		//implementation of public member function

		int k;
		void set_k(int n2)
		{
			k = n2;
		}
		int get_k(void)
		{
			return k;
		}

		//implementation of private, protected member functions

		void set_f(int num3)
		{
			f = num3;	
		}
		int get_f(void)
		{
			return f;
		}
		void set_y(int num4)
		{
			y = num4;	
		}
		int get_y(void)
		{
			return y;
		}
};

class D2 : protected D1
{
	private:
		int e;
	protected:
		int z;
	public:		
		//implementation of public member function
		
		
		int q;
		void set_q(int n3)
		{
			q = n3;
		}
		int get_q(void)
		{
			return q;
		}
	
		//implementation of private, protected member functions

		void set_e(int num5)
		{
			e = num5;	
		}
		int get_e(void)
		{
			return e;
		}

		void set_z(int num6)
		{
			z = num6;	
		}
		int get_z(void)
		{
			return z;
		}
};

int main()
{
	// here public, private, protected of class B got access
/*	D1 v;
	v.set_j(3);
	cout << "j = " << v.get_j() <<endl;
	v.set_i(10);
	cout << "i = " << v.get_i() <<endl; 


	v.set_u(7);
	cout << "u = " << v.get_u() <<endl;*/
	 
	D2 c;

	// class B member functions
	c.set_j(3); //protected
	cout << "j = " << c.get_j() <<endl;
	c.set_i(10); //private
	cout << "i = " << c.get_i() <<endl; 

	c.set_u(8); //public
	cout << "u = " << c.get_u() <<endl;

	
	// class D1 member functions
	c.set_f(9); //private
	cout << "j = " << c.get_f() <<endl;
	c.set_y(15); //protected
	cout << "i = " << c.get_y() <<endl; 

	c.set_k(7); //public
	cout << "k = " << c.get_k() <<endl;
}

