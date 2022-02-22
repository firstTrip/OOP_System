#include<iostream>

using namespace std;


class User
{
private: //정보은닉 
	const int ID;
	int Money;
	const string Name;

public :

	void ShowInfo() const
	{
		cout << "계좌 번호 :" << ID << '\n';
		cout << "현재 금액 :" << Money << '\n';
		cout << "이 름 :" << Name << '\n';
	}

	int GetID() const
	{
		return ID;
	}


	void Insert(int money)
	{
		this->Money += money;
	}
	int Remove(int money)
	{
		if (money > Money)
			return;

		this->Money -= money;
		return this->Money;
	}

	User(int ID, int Money, string Name) : ID(ID), Money(Money), Name(Name)
	{
		// 이니셜 라이저
	}

	User(const User& copy) : ID(copy.ID) , Money(copy.Money), Name(copy.Name)
	{
		cout << "new Copy obj :" << endl;
	}

	~User()
	{
		// 소멸자
		cout << "delete obj :" << endl;

	}
};


User *user[100];
int idx = 0;

void CreateAccount(void);
void ShowAllAccount(void);


void CallInsert(void);
void CallRemove(void);

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
			CallInsert();
			break;

		case 3:
			CallRemove();
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


void  CreateAccount()
{
	int num, money;
	string name;

	cout << "계좌 번호를 입력 해주세요." << '\n';
	cin >> num;
	cout << "현재 금액을 입력 해주세요. " << '\n';
	cin >> money;
	cout << "이름을 입력 해주세요. " << '\n';
	cin >> name;

	user[idx++] = new User(num, money, name);
}

void  ShowAllAccount()
{
	for (int i = 0; i < idx; i++)
	{
		user[i]->ShowInfo();

	}
}


void CallInsert()
{
	int inputdata;
	cout << "입금할 계좌를 입력하세요." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i]->GetID() == inputdata)
		{
			int money;
			cout << "입금할 금액을 적어 주세요." << '\n';
			cin >> money;

			user[i]->Insert(money);

			return;
		}

	}

	cout << "일치하는 계좌가 없습니다." << '\n';

}

void CallRemove()
{
	int inputdata;
	cout << "출금할 계좌를 입력하세요." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i]->GetID() == inputdata)
		{
			int money;
			cout << "출금할 금액을 적어 주세요." << '\n';
			cin >> money;

			user[i]->Remove(money);

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