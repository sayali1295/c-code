//This is first program in cpp for structure practice
//cpp_struct


#include<stdio.h>
int main()
{
	struct emp
	{
		private:
			int i,j,k;
		public:
			void set_i(int x)
			{
				i = x; 
				printf("Value set for i is: %d\n", i);
			}
			
			int set_j(int y)
			{
				j = y; 
				printf("Value set for j is: %d\n", j);
				return 1;
			}
	
			void set_k(int z)
			{
				k = z; 
				printf("Value set for k is: %d\n", k);
			}

			void get_j()
			{
				printf("Value of j is: %d\n", j);
			}
	};

	emp e;
	int num;

	e.set_i(25);

	e.set_k(63);

	if (num == 1)
		e.get_j();
	else
		printf("no out \n");

	num = e.set_j(72);

	return 0;
}
