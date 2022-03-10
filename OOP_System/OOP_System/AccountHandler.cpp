#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "AccountException.h" 



void  AccountHandler::CreateAccount()
{

	int x;
	cout << "[�������� ����]" << '\n';
	cout << "1.���뿹�� ���� 2. �ſ�ŷ� ����" << '\n';
	cout << "���� : ";

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

	cout << "[���뿹�� ����]" << '\n';


	cout << "���� ��ȣ�� �Է� ���ּ���." << '\n';
	cin >> num;
	cout << "���� �ݾ��� �Է� ���ּ���. " << '\n';
	cin >> money;
	cout << "�̸��� �Է� ���ּ���. " << '\n';
	cin >> name;
	cout << "������ :. " << '\n';
	cin >> interest;

	accArr[idx++] = new NormalAccount(num, money, name, interest);
}

void  AccountHandler::CreateHighCreditAccount()
{

	int num, money, interest;
	String name;
	int grade;

	cout << "[�ſ�ŷ� ����]" << '\n';


	cout << "���� ��ȣ�� �Է� ���ּ���." << '\n';
	cin >> num;
	cout << "���� �ݾ��� �Է� ���ּ���. " << '\n';
	cin >> money;
	cout << "�̸��� �Է� ���ּ���. " << '\n';
	cin >> name;
	cout << "������ :. " << '\n';
	cin >> interest;
	cout << "�ſ� ���(1toA , 2toB, 3toC) :. " << '\n';
	cin >> grade;


	switch (grade)
	{

	case 1:
		accArr[idx++] = new HighCreditAccount(num, money, name, interest, Level_A);
		break;
	case 2:
		accArr[idx++] = new HighCreditAccount(num, money, name, interest, Level_B);
		break;
	case 3:
		accArr[idx++] = new HighCreditAccount(num, money, name, interest, Level_C);
		break;
	default:
		break;
	}
}


void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < idx; i++)
	{
		accArr[i]->ShowInfo();

	}
}


void AccountHandler::CallInsert()
{
	int inputdata;
	cout << "�Ա��� ���¸� �Է��ϼ���." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (accArr[i]->GetID() == inputdata)
		{
			int money;
			cout << "�Ա��� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;
			try
			{
				accArr[i]->Deposit(money);

			}
			catch (DepositException &expn)
			{
				expn.ShowAccountException();
			}

			return;
		}

	}

	cout << "��ġ�ϴ� ���°� �����ϴ�." << '\n';

}

void AccountHandler::CallRemove()
{
	int inputdata;
	cout << "����� ���¸� �Է��ϼ���." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (accArr[i]->GetID() == inputdata)
		{
			int money;
			cout << "����� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;

			try
			{
				accArr[i]->Remove(money);

			}
			catch (WithdrawException& expn)
			{
				expn.ShowAccountException();

			}

			return;
		}

	}

	cout << "��ġ�ϴ� ���°� �����ϴ�." << '\n';
}


void AccountHandler::ShowMenu()
{
	cout << "----------Menu-----------" << '\n';
	cout << "1. ���°���" << '\n';
	cout << "2. �� ��" << '\n';
	cout << "3. �� ��" << '\n';
	cout << "4. ���� ���� ��ü ���" << '\n';
	cout << "5. ���α׷� ����" << '\n';
}

AccountHandler::AccountHandler() : idx(0) // AccountHandler �� ������ ����
{ }

AccountHandler::~AccountHandler() // AccountHandler �� �Ҹ��� ���� ���� �޸𸮸� ���� ��Ų��.
{
	for (int i = 0; i < idx; i++)
		delete accArr[i];
}