//This program is trial to reference variable
//cpp_ref_var_trial.C



#include<iostream>
using namespace std;
int main()
{
	int k=10;
	int &s=k;
	s=100;
	cout << s << k;
}
