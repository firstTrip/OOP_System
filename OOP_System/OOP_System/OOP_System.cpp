#include<iostream>

using namespace std;

//신용등급 
enum { Level_A =7, Level_B = 4,Level_C = 2};

class Account // Entity 클래스 , 데이터를 저장하고 보관하는 클래스 
{
private: //정보은닉 
	const int ID;
	int Money;
	const string Name;

public :

	virtual void ShowInfo() const // virtual 함수를 사용하여 다형성을 사용
	{
		cout << "계좌 번호 :" << ID << '\n';
		cout << "현재 금액 :" << Money << '\n';
		cout << "이 름 :" << Name << '\n';
	}

	int GetID() const
	{
		return ID;
	}


	virtual void Insert(int money)
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


	Account(int ID, int Money, string Name) : ID(ID), Money(Money), Name(Name)
	{
		// 이니셜 라이저
	}

	Account(const Account& copy) : ID(copy.ID) , Money(copy.Money), Name(copy.Name)
	{
		cout << "new Copy obj :" << endl;
	}

	~Account() 
	{
		// 소멸자
		cout << "delete obj :" << endl;

	}
};

class NomalAccount : public Account // Account 를 부모로 둔 자식 클래스 , interst 변수가 추가된다.
{
private:
	const int interest;



public:
	NomalAccount(int ID, int Money, string Name ,int interest) : Account(ID,Money,Name), interest(interest)
	{
		// 이니셜 라이저
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void ShowInfo() const
	{
		Account::ShowInfo();// 부모의 ShowInfo 를 호출 
		cout << "이자율 :" << interest << '\n';

	}

	virtual void Insert(int money)
	{
		Account::Insert(money);
		Account::Insert(money *(interest/100.0)); // 이자 계산

	}

	~NomalAccount()
	{
		// 소멸자
		cout << "delete obj :" << endl;

	}
};

class HighCreditAccount : public NomalAccount // NomalAccount를 부모로 사용하는 클래스 추가 이자가 존재한다.
{
private:
	const int specialInterest;



public:
	HighCreditAccount(int ID, int Money, string Name,int rate ,int special ) : NomalAccount(ID, Money, Name,rate), specialInterest(special)
	{
		// 이니셜 라이저
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void Insert(int money)
	{
		Account::Insert(money);
		Account::Insert(money * (specialInterest / 100.0)); // 이자 계산

	}

	virtual void ShowInfo() const
	{
		Account::ShowInfo();
		cout << "이자율 :" << specialInterest << '\n';


	}
	~HighCreditAccount()
	{
		// 소멸자
		cout << "delete obj :" << endl;

	}
};

class AccountHandler // 컨트롤 클래스 추가 , 전반적인 기능을 담당하는 클래스
{
private:

	Account* user[100];
	int idx;

public :

	AccountHandler(); // 생성자
	~AccountHandler(); // 소멸자

	void CreateAccount(void);
	void CreateNomalAccount(void);
	void CreateHighCreditAccount(void);
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

	int x;
	cout << "[계좌종류 선택]" << '\n';
	cout << "1.보통예금 계좌 2. 신용신뢰 계좌" << '\n';
	cout << "선택 : ";

	cin >> x;


	switch (x)
	{
	case 1:

		CreateNomalAccount();
		break;

	case 2:

		CreateHighCreditAccount();
		break;

	default:

		cout << "잘못 입력 하셨습니다." << '\n';

		break;
	}



	
}

void  AccountHandler::CreateNomalAccount()
{

	int num, money, interest;
	string name;

	cout << "[보통예금 계좌]" << '\n';


	cout << "계좌 번호를 입력 해주세요." << '\n';
	cin >> num;
	cout << "현재 금액을 입력 해주세요. " << '\n';
	cin >> money;
	cout << "이름을 입력 해주세요. " << '\n';
	cin >> name;
	cout << "이자율 :. " << '\n';
	cin >> interest;

	user[idx++] = new NomalAccount(num, money, name, interest);
}

void  AccountHandler::CreateHighCreditAccount()
{

	int num, money, interest;
	string name;

	int grade;

	cout << "[신용신뢰 계좌]" << '\n';


	cout << "계좌 번호를 입력 해주세요." << '\n';
	cin >> num;
	cout << "현재 금액을 입력 해주세요. " << '\n';
	cin >> money;
	cout << "이름을 입력 해주세요. " << '\n';
	cin >> name;
	cout << "이자율 :. " << '\n';
	cin >> interest;
	cout << "신용 등급(1toA , 2toB, 3toC) :. " << '\n';
	cin >> grade;


	switch (grade)
	{

	case 1:
		user[idx++] = new HighCreditAccount(num, money, name, interest, Level_A);
		break;
	case 2:
		user[idx++] = new HighCreditAccount(num, money, name, interest, Level_B);
		break;
	case 3:
		user[idx++] = new HighCreditAccount(num, money, name, interest, Level_C);
		break;
	default:
		break;
	}
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
		
		cout << "번호를 선택 해 주세요 " << '\n';

		cin >> val;
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