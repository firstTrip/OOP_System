#include <iostream>


int main()
{
	int num =0;

	std::cout << "숫자를 입력 하세요." << std::endl;

	std::cin >> num;

	std::cout << num << "의 구구단" << std::endl;

	for (int i = 0; i < 9; i++)
	{
		std::cout << num <<" * "<< i +1 << " = " <<(i+1)*num  << std::endl;

	}


	return 0;
}