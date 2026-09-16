//Memory allocation using new in class
//cpp_newinclass.C


#include<iostream>
using namespace std;

class A
{
	private:
		int i;

	public:
		A(){}

		A(int l)
		{
			i=l;
		};
		void set_i(int i)
		{
			this->i = i;
		}

		int get_i(void)
		{
			return i;
		}
};

int main()
{
	A x;
	A *obj = new A (10);
	obj->set_i(26);
	cout << "Value of i : " << obj->get_i() << endl;
	delete obj;
	obj = nullptr;

return 0;
}

