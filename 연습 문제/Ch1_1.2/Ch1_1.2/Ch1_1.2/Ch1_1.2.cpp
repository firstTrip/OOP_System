#include<iostream>

int main()
{
	char name[10];
	char number[20];

	std::cout << "이름을 입력 하세요" << '\n';
	std::cin >> name;

	std::cout << "번호를 입력 하세요" << '\n';
	std::cin >> number;


	std::cout << "이름은 "<< name << "입니다." << '\n';
	std::cout << "번호는 " << number << "입니다." << '\n';


	return 0;
}