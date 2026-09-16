
//This program is working on heap memory allocation
//This uses unique pointer
//cpp_new_heap.C

#include <iostream>
#include<memory>
using namespace std;
int main()
{

	auto i = std::make_unique<int> (10); // logic to free up heap
	cout << *i <<endl;
/*	int *i = new int(10);
	cout << i << endl;
//	delete(i);
	
	//delete(i); deleting heap memory consecutively two times is not possible as it crashes program
      
	i = new int(20);
	cout << *i <<endl ;

        delete(i);
	i=nullptr; // declaring i as null pointer to remove its address in stack
	delete(i);

	delete(i);

	i = new int(52);
	cout << *i <<endl ;
        delete(i);

	i = new int(86);
	cout << *i <<endl;
        delete(i);

	i = new int(26);
	cout << *i <<endl;
        delete(i);*/
}
