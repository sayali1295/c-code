//This program is implementing stack functions
//cpp_stackclass_trial.C


#include<iostream>
using namespace std;

class stack
{
	private:
		int i[10];
	public:
		// function is taking array i
		void get_i(int i[])
		{
			this-> i[0] = i[0];
			get_size_i(i);
		}
		
		//function is calculating size of array i
		int get_size_i(int a[])
		{
			int j = 0;
			int size = 0;

			while(a[j] != 0)
			{
				j++;
				size++;
			}
			return size;
		}

		//function is pushing elements in stack

		int is_full = 0;

		int* push_stack(int b[], int s)
		{		
			s = get_size_i(i);
			
			int k = 0;
			int c[s];
			
			if (is_full != s)
			{
				while(b[k] != 0)
				{
					c[k] = b[k];
					k++;
					is_full++;		
				}
				return c;
			}
			else	
				cout << "Stack full" <<'\n';
		}
		//function is pulling out elements from stack
		void pop_stack(int g[])
		{
			int j;
			return g[j];
		
		}
};


int main()
{

	stack obj[10];




return 0;
}
