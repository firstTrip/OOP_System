#include <iostream>


int main()
{
	int num =0;

	std::cout << "���ڸ� �Է� �ϼ���." << std::endl;

	std::cin >> num;

	std::cout << num << "�� ������" << std::endl;

	for (int i = 0; i < 9; i++)
	{
		std::cout << num <<" * "<< i +1 << " = " <<(i+1)*num  << std::endl;

	}


	return 0;
}