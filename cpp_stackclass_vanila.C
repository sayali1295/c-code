//This program is implementing stack functions without validation
//cpp_stackclass.C


#include<iostream>
using namespace std;

class stack
{
	private:
		int data[10];
		int index;
	public:
		// constructor is seting index of stack
		stack()
		{
			index = -1;	
		}
		
		// function is Pushing data in stack

		void push_stack(int value)
		{

			{
				data[index++] = value;
				cout << "Value " << value << " pushed into stack" <<index << endl;
			}
		
		}
		
		//function is popping data out of stack

		int pop_stack(void)
		{

			 return data[--index];

		}
	
};


int main()
{

	stack obj;
	//obj[0].pop_stack();
	obj.push_stack(52);
	obj.push_stack(10);
	obj.push_stack(12);
	obj.push_stack(34);
	obj.push_stack(525);

	int pop = obj.pop_stack();
	cout <<"popped" << pop << endl;
	

return 0;
}
