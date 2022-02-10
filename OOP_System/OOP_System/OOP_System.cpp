#include<iostream>

using namespace std;


typedef struct user
{
	int ID;
	int Money;
	string Name;

}User;


User user[100];
int idx = 0;

void CreateAccount(void);
void ShowAllAccount(void);
void Insert(void);
void Remove(void);
void Menu(int);




void Menu(int val)
{	
	switch (val)
	{
		case 1:
			cout << "계좌를 개설 합니다." << '\n';
			CreateAccount();
			break;

		case 2:
			Insert();
			break;

		case 3:
			Remove();
			break;

		case 4:
			cout << "모든 계좌를 출력합니다." << '\n';
			ShowAllAccount();
			break;

		default :
			cout << "잘못된 숫자를 입력 하였습니다" << '\n';
			break;
	}
}

void CreateAccount()
{
	int num, money;
	string name;

	cout << "계좌 번호를 입력 해주세요." << '\n';
	cin >> num;
	cout << "현재 금액을 입력 해주세요. " << '\n';
	cin >> money;
	cout << "이름을 입력 해주세요. " << '\n';
	cin >> name;

	user[idx].ID = num;
	user[idx].Money = money;
	user[idx].Name = name;
	idx++;
}

void ShowAllAccount()
{
	for (int i = 0; i < idx; i++)
	{
		cout << (i + 1) << " 번째 계좌" << '\n';
		cout << "계좌 번호 :" << user[i].ID << '\n';
		cout << "현재 금액 :" << user[i].Money << '\n';
		cout << "이 름 :" << user[i].Name << '\n';
		cout << "--------------------------" << '\n';

	}
}

void Insert()
{
	int inputdata;
	cout << "입금할 계좌를 입력하세요." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i].ID == inputdata)
		{
			int money;
			cout << "입금할 금액을 적어 주세요." << '\n';
			cin >> money;

			user[i].Money += money;

			return;

		}
	}

	cout << "일치하는 계좌가 없습니다." << '\n';

}

void Remove()
{
	int inputdata;
	cout << "출금할 계좌를 입력하세요." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i].ID == inputdata)
		{
			int money;
			cout << "출금할 금액을 적어 주세요." << '\n';
			cin >> money;

			user[i].Money -= money;

			return;

		}
	}

	cout << "일치하는 계좌가 없습니다." << '\n';
}

int main()
{

	int val;

	while (1)
	{

		cout << "----------Menu-----------" << '\n';
		cout << "1. 계좌개설" << '\n';
		cout << "2. 입 금" << '\n';
		cout << "3. 출 급" << '\n';
		cout << "4. 계좌 정보 전체 출력" << '\n';
		cout << "5. 프로그램 종료" << '\n';

		cin >> val;
		cout << "선택 : " << val << '\n';

		if (val == 5)
		{
			cout << "프로그램을 종료 합니다." << '\n';
			break;

		}

		Menu(val);
	}
	return 0;
}