//This program is template of inheritance
//cpp_temp_inherit.C

#include <iostream>
#include <cstring>
using namespace std;

class base
{
	private:
	int i;
	char p[10];

	public:
	void set_i(int x, char k[])
	{
		this->i = x;
		strcpy(&p[0],&k[0]);

	}
	int get_i(void)
	{
		cout << "NAme" << p << " ";
		return i;
	}
	
};


class derived : private base
{

	private:
	int j;
	/* public members fron base class  became private members in this(derived) class
	 int i;
	 set_i(int x)
	 get_i(void)
	 */
	public:
	void set_j(int x)
	{
		this->j = x;
		char str[] = "manali";
		set_i(23, str);
		//i=987;

	}
	int get_j(void)
	{
		return get_i();;
	}
	
};
int main()
{

/*	base obj;
	char str[]="sarali";
	obj.set_i(23, str);
	obj.get_i();*/

	derived d;
	d.set_j(10);
	cout << d.get_j();
	
}
