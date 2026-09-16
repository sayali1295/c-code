#include<cstdio>
#include<iostream>
using namespace std;
	class emp
	{
		private:
			int i;
		public:
			emp()
			{
				this->i=100;
				cout << "I am in constructor" << endl;
			}
			void set_i (int i);
			int get_i(void)
			{
				return i;
			}
			~emp()
			{
				cout <<  " Destructor"<<endl;
			}
				
	};

	void emp::set_i(int i)
	{
		this->i=i;
		cout << "My Adrress is " << this << endl;
	};

int main()
{
	emp e;

//	e.set_i(10);
	printf("%d", e.get_i());
	cout << "Addres of "<< &e;

return 0;
}
