#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"



void  AccountHandler::CreateAccount()
{

	int x;
	cout << "[계좌종류 선택]" << '\n';
	cout << "1.보통예금 계좌 2. 신용신뢰 계좌" << '\n';
	cout << "선택 : ";

	cin >> x;


	if (x == NORMAL)
		CreateNomalAccount();
	else
		CreateHighCreditAccount();


}

void  AccountHandler::CreateNomalAccount()
{

	int num, money, interest;
	String name;

	cout << "[보통예금 계좌]" << '\n';


	cout << "계좌 번호를 입력 해주세요." << '\n';
	cin >> num;
	cout << "현재 금액을 입력 해주세요. " << '\n';
	cin >> money;
	cout << "이름을 입력 해주세요. " << '\n';
	cin >> name;
	cout << "이자율 :. " << '\n';
	cin >> interest;

	user[idx++] = new NormalAccount(num, money, name, interest);
}

void  AccountHandler::CreateHighCreditAccount()
{

	int num, money, interest;
	String name;
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

			user[i]->Deposit(money);

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