#include<iostream>

int main()
{
	char name[10];
	char number[20];

	std::cout << "�̸��� �Է� �ϼ���" << '\n';
	std::cin >> name;

	std::cout << "��ȣ�� �Է� �ϼ���" << '\n';
	std::cin >> number;


	std::cout << "�̸��� "<< name << "�Դϴ�." << '\n';
	std::cout << "��ȣ�� " << number << "�Դϴ�." << '\n';


	return 0;
}