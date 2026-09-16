
//This program is for constant to int pointer, int to constant pointer study
//cpp_const_pointer_auto.C


#include <iostream>
using namespace std;
int main()
{

	auto i = 0x12;
	auto f = 3.14;

	int j=45;

//	int* const p = &i; //1 p is constant to int pointer
//	int const *p = &i; //2 p is a pointer to int const/const int


	int const * const p = &i; //3 both 1 & 2 combines here
        
	p = &j; //1
	*p = 87; //2

	printf("\n%i\t%f\n",*p , f);


	return  0;
}
