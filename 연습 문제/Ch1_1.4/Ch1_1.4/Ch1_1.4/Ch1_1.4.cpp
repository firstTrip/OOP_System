#include <iostream>


int main()
{
	int num = 0;


	while (true)
	{
		std::cout << "�Ǹ� �ݾ��� ���������� �Է�(-1 to end)" << std::endl;
		std::cin >> num;

		if (num == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;

			return 0;

		}

		std::cout << "�̹��� �Ǹ� �޾��� " << 50 + (num *0.12) << "����" << std::endl;

	}

}