#include <iostream>


void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}

void swap(char* num1, char* num2)
{
	char temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}

void swap(double* num1, double* num2)
{
	double temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}

int main()
{

	int num1 = 10,num2 = 20;
	swap(&num1, &num2);
	std::cout << num1 << "   " << num2 << std::endl;
	

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << "   " << ch2 << std::endl;


	double d1 = 1.1111, d2 = 5.5555555;
	swap(&d1, &d2);
	std::cout << d1 << "   " << d2 << std::endl;



	return 0;
}