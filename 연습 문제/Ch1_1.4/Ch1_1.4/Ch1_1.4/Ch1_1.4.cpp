#include <iostream>


int main()
{
	int num = 0;


	while (true)
	{
		std::cout << "판매 금액을 만원단위로 입력(-1 to end)" << std::endl;
		std::cin >> num;

		if (num == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;

			return 0;

		}

		std::cout << "이번달 판매 급액은 " << 50 + (num *0.12) << "만원" << std::endl;

	}

}