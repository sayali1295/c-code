//This program is performing function overloading
//Here we have used (set data function) to set private members of class
//and (get data function) to get values after arithmetic operations
//performed on private members 
//cpp_fun_overload.C


#include<iostream>
using namespace std;

class A
{
	private:
		int i, j, k, l, m, n, o, p; // p is not set anywhere so it should show garbage
		char a, b, d;
		float z, x, w, q;

	public:
		A ()
		{
			p = 0;	
		}
		void set_data(int num)
		{
			i = num;		
		}

		void set_data(int num1, int num2)
		{
			j = num1 + num2;	
		}
	
	//	void set_data(int num1, int num2, int num3, int num4 = 5, int num5 = 2) makes ambiguity
		
		void set_data(int num1, int num2, int num3, int num4, int num5)
		{
			k = num1,
			l = num1 + num2;
			m = num3;
			n = num4 + num1;
			o = num5;
		}

		void set_data(char ch1, char ch2, char ch3)
		{
			a = ch1;
			b = ch2;
			d = ch3;
		}

		void set_data(float n1, float n2, float n3, float n4)
		{
			z = n1 - n2;
			x = n2;
			w = n4 * n1;
			q = n3 - n1 + n2;	
		}

		int get_dataI (void) {return i;}
		int get_dataJ (void) {return j;}
		int get_dataK (void) {return k;}
		int get_dataL (void) {return l;}
		int get_dataM (void) {return m;}
		int get_dataN (void) {return n;}
		int get_dataO (void) {return o;}
		int get_dataP (void) {return p;}
		 
		char get_dataA (void) {return a;}
	 	char get_dataB (void) {return b;}
		char get_dataD (void) {return d;}

		float get_dataZ (void) {return z;}
		float get_dataX (void) {return x;}
		float get_dataW (void) {return w;}
		float get_dataQ (void) {return q;}
};

int main()
{

	A obj;
	obj.set_data(1.2, 9.5, 5.6, 4.3);

	obj.set_data(15, 20);

	obj.set_data('D', 'U', 'E');

	obj.set_data(12);

	obj.set_data(5, 4, 1, 7, 2);

	cout << "value of i : " << obj.get_dataI() << endl;
	cout << "value of j : " << obj.get_dataJ() << endl;
	cout << "value of k : " << obj.get_dataK() << endl;
	cout << "value of l : " << obj.get_dataL() << endl;
	cout << "value of m : " << obj.get_dataM() << endl;
	cout << "value of n : " << obj.get_dataN() << endl;
	cout << "value of o : " << obj.get_dataO() << endl;
	cout << "value of p : " << obj.get_dataP() << endl;

	cout << "value of a : " << obj.get_dataA() << endl;
	cout << "value of b : " << obj.get_dataB() << endl;
	cout << "value of d : " << obj.get_dataD() << endl;

	cout << "value of z : " << obj.get_dataZ() << endl;
	cout << "value of x : " << obj.get_dataX() << endl;
	cout << "value of w : " << obj.get_dataW() << endl;
	cout << "value of q : " << obj.get_dataQ() << endl;


return 0;
}
