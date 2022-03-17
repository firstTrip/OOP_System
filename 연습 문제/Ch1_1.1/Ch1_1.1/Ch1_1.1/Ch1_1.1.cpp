#include<iostream>


int main()
{
	int arr[5];
	int sum =0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "번 째 숫자를 입력 하세요." << '\n';
		std ::cin >> arr[i];

		sum += arr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "번 째의 숫자는 " << arr[i]<<" 입니다." << '\n';
	}

	std::cout << "총 합은  " << sum << " 입니다." << '\n';

}