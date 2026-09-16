//This is a basic program of function overloading
//Here we have used sum function (public)
//cpp_foverldng.cpp


#include<iostream>
using namespace std;

class Addition
{

	public:
		int sum(int a, int b)
		{
			int sum2 = a + b;
			return sum2;
		}

		int sum(int a, int b, int c)
		{
			int sum3 = a + b;
			return sum3;
		}

		float sum(float a, float b, float c, float d)
		{
			float sum4 = a + b;
			return sum4;
		}
};

int main()
{

Addition obj;

cout << "Sum of 3 numbers : " << obj.sum(15,12,8) << '\n';

int sum2 = obj.sum(5,9);
cout << "Sum of 2 numbers : " << sum2 << '\n';

float sum4 = obj.sum(1.9,3.6,2.7,1.8);
cout << "Sum of 4 numbers : " << sum4 << '\n';

return 0;
}
