//This program is implementing stack functions with validations
//cpp_stackclass_validate.C


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
                        if (index >= 9)
                        {
                                cout << "Stack is full! can't push more data" << endl;
                        }

			else
			{
				index++;
				data[index] = value;
				cout << "Value " << value << " pushed into stack " << index << endl;
				
			}
		}
		
		//function is popping data out of stack

		int pop_stack(void)
		{
			int pop_value;

                        if (index < 0)
                        {
                                cout << "Stack is empty! can't pop more data" << endl;
				return -1;
                        }
			else
			{
				pop_value = data[index];
				index--;
				return pop_value;
			}
		}
};

int main()
{

	stack obj;

	obj.pop_stack();
	obj.push_stack(52);
	obj.push_stack(10);
	obj.push_stack(12);
	obj.push_stack(34);
	obj.push_stack(15);
	obj.push_stack(63);
	obj.push_stack(18);
	obj.push_stack(49);
	obj.push_stack(13);


	int pop = obj.pop_stack();
	cout << "Value " << pop << " popped from stack" << endl;

	obj.push_stack(39);

	cout << '\n';
	cout << '\n';

	stack ob[5];
	ob[0].push_stack(5);
	ob[0].push_stack(1);
	ob[0].push_stack(14);
	ob[0].push_stack(1);
	ob[1].push_stack(7);
	ob[1].push_stack(8);
	ob[1].push_stack(3);
	ob[2].push_stack(9);
	ob[2].push_stack(6);

	int p = ob[0].pop_stack();

	cout << "Value " << p << " popped from stack" << endl;
	

return 0;
}
