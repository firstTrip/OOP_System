#include<iostream>

using namespace std;


class User // Entity 클래스 , 데이터를 저장하고 보관하는 클래스 
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
			return Money;

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

class AccountHandler // 컨트롤 클래스 추가 , 전반적인 기능을 담당하는 클래스
{
private:

	User* user[100];
	int idx;

public :

	AccountHandler(); // 생성자
	~AccountHandler(); // 소멸자

	void CreateAccount(void);
	void ShowAllAccount(void) const; // 값의 변환을 허용하지 않기 때문에 const 를 선언 해준다.
	void CallInsert(void);
	void CallRemove(void);
	void ShowMenu(void);
	void Menu(int val);
};





void  AccountHandler::Menu(int val)
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

	default:
		cout << "잘못된 숫자를 입력 하였습니다" << '\n';
		break;
	}
}

void  AccountHandler::CreateAccount()
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

void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < idx; i++)
	{
		user[i]->ShowInfo();

	}
}


void AccountHandler::CallInsert()
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

void AccountHandler::CallRemove()
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


void AccountHandler::ShowMenu()
{
	cout << "----------Menu-----------" << '\n';
	cout << "1. 계좌개설" << '\n';
	cout << "2. 입 금" << '\n';
	cout << "3. 출 급" << '\n';
	cout << "4. 계좌 정보 전체 출력" << '\n';
	cout << "5. 프로그램 종료" << '\n';
}

AccountHandler::AccountHandler() : idx(0) // AccountHandler 의 생성자 선언
{ } 

AccountHandler::~AccountHandler() // AccountHandler 의 소멸자 선언 사용된 메모리를 삭제 시킨다.
{
	for (int i = 0; i < idx; i++)
		delete user[i];
}

int main()
{

	AccountHandler manager;
	int val;

	while (1)
	{
		manager.ShowMenu();
		

		switch (val)
		{
		case 1:
			cout << "계좌를 개설 합니다." << '\n';
			manager.CreateAccount();
			break;

		case 2:
			manager.CallInsert();
			break;

		case 3:
			manager.CallRemove();
			break;

		case 4:
			cout << "모든 계좌를 출력합니다." << '\n';
			manager.ShowAllAccount();
			break;

		case 5 :
			return 0;

		default:
			cout << "잘못된 숫자를 입력 하였습니다" << '\n';
			break;
		}
	}
	return 0;
}