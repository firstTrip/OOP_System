#include<iostream>


int main()
{
	int arr[5];
	int sum =0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "�� ° ���ڸ� �Է� �ϼ���." << '\n';
		std ::cin >> arr[i];

		sum += arr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "�� °�� ���ڴ� " << arr[i]<<" �Դϴ�." << '\n';
	}

	std::cout << "�� ����  " << sum << " �Դϴ�." << '\n';

}