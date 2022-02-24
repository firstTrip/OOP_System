#include<iostream>

using namespace std;

//�ſ��� 
enum { Level_A =7, Level_B = 4,Level_C = 2};

class Account // Entity Ŭ���� , �����͸� �����ϰ� �����ϴ� Ŭ���� 
{
private: //�������� 
	const int ID;
	int Money;
	const string Name;

public :

	virtual void ShowInfo() const // virtual �Լ��� ����Ͽ� �������� ���
	{
		cout << "���� ��ȣ :" << ID << '\n';
		cout << "���� �ݾ� :" << Money << '\n';
		cout << "�� �� :" << Name << '\n';
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
		// �̴ϼ� ������
	}

	Account(const Account& copy) : ID(copy.ID) , Money(copy.Money), Name(copy.Name)
	{
		cout << "new Copy obj :" << endl;
	}

	~Account() 
	{
		// �Ҹ���
		cout << "delete obj :" << endl;

	}
};

class NomalAccount : public Account // Account �� �θ�� �� �ڽ� Ŭ���� , interst ������ �߰��ȴ�.
{
private:
	const int interest;



public:
	NomalAccount(int ID, int Money, string Name ,int interest) : Account(ID,Money,Name), interest(interest)
	{
		// �̴ϼ� ������
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void ShowInfo() const
	{
		Account::ShowInfo();// �θ��� ShowInfo �� ȣ�� 
		cout << "������ :" << interest << '\n';

	}

	virtual void Insert(int money)
	{
		Account::Insert(money);
		Account::Insert(money *(interest/100.0)); // ���� ���

	}

	~NomalAccount()
	{
		// �Ҹ���
		cout << "delete obj :" << endl;

	}
};

class HighCreditAccount : public NomalAccount // NomalAccount�� �θ�� ����ϴ� Ŭ���� �߰� ���ڰ� �����Ѵ�.
{
private:
	const int specialInterest;



public:
	HighCreditAccount(int ID, int Money, string Name,int rate ,int special ) : NomalAccount(ID, Money, Name,rate), specialInterest(special)
	{
		// �̴ϼ� ������
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void Insert(int money)
	{
		Account::Insert(money);
		Account::Insert(money * (specialInterest / 100.0)); // ���� ���

	}

	virtual void ShowInfo() const
	{
		Account::ShowInfo();
		cout << "������ :" << specialInterest << '\n';


	}
	~HighCreditAccount()
	{
		// �Ҹ���
		cout << "delete obj :" << endl;

	}
};

class AccountHandler // ��Ʈ�� Ŭ���� �߰� , �������� ����� ����ϴ� Ŭ����
{
private:

	Account* user[100];
	int idx;

public :

	AccountHandler(); // ������
	~AccountHandler(); // �Ҹ���

	void CreateAccount(void);
	void CreateNomalAccount(void);
	void CreateHighCreditAccount(void);
	void ShowAllAccount(void) const; // ���� ��ȯ�� ������� �ʱ� ������ const �� ���� ���ش�.
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
		cout << "���¸� ���� �մϴ�." << '\n';
		CreateAccount();
		break;

	case 2:
		CallInsert();
		break;

	case 3:
		CallRemove();
		break;

	case 4:
		cout << "��� ���¸� ����մϴ�." << '\n';
		ShowAllAccount();
		break;

	default:
		cout << "�߸��� ���ڸ� �Է� �Ͽ����ϴ�" << '\n';
		break;
	}
}

void  AccountHandler::CreateAccount()
{

	int x;
	cout << "[�������� ����]" << '\n';
	cout << "1.���뿹�� ���� 2. �ſ�ŷ� ����" << '\n';
	cout << "���� : ";

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

		cout << "�߸� �Է� �ϼ̽��ϴ�." << '\n';

		break;
	}



	
}

void  AccountHandler::CreateNomalAccount()
{

	int num, money, interest;
	string name;

	cout << "[���뿹�� ����]" << '\n';


	cout << "���� ��ȣ�� �Է� ���ּ���." << '\n';
	cin >> num;
	cout << "���� �ݾ��� �Է� ���ּ���. " << '\n';
	cin >> money;
	cout << "�̸��� �Է� ���ּ���. " << '\n';
	cin >> name;
	cout << "������ :. " << '\n';
	cin >> interest;

	user[idx++] = new NomalAccount(num, money, name, interest);
}

void  AccountHandler::CreateHighCreditAccount()
{

	int num, money, interest;
	string name;

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
	cout << "�Ա��� ���¸� �Է��ϼ���." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i]->GetID() == inputdata)
		{
			int money;
			cout << "�Ա��� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;

			user[i]->Insert(money);

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
		if (user[i]->GetID() == inputdata)
		{
			int money;
			cout << "����� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;

			user[i]->Remove(money);

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
		delete user[i];
}

int main()
{

	AccountHandler manager;
	int val;



	while (1)
	{
		manager.ShowMenu();
		
		cout << "��ȣ�� ���� �� �ּ��� " << '\n';

		cin >> val;
		switch (val)
		{
		case 1:
			cout << "���¸� ���� �մϴ�." << '\n';
			manager.CreateAccount();
			break;

		case 2:
			manager.CallInsert();
			break;

		case 3:
			manager.CallRemove();
			break;

		case 4:
			cout << "��� ���¸� ����մϴ�." << '\n';
			manager.ShowAllAccount();
			break;

		case 5 :
			return 0;

		default:
			cout << "�߸��� ���ڸ� �Է� �Ͽ����ϴ�" << '\n';
			break;
		}
	}
	return 0;
}