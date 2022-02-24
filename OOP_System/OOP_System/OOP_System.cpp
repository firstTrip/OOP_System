#include<iostream>

using namespace std;


class User // Entity Ŭ���� , �����͸� �����ϰ� �����ϴ� Ŭ���� 
{
private: //�������� 
	const int ID;
	int Money;
	const string Name;

public :

	void ShowInfo() const
	{
		cout << "���� ��ȣ :" << ID << '\n';
		cout << "���� �ݾ� :" << Money << '\n';
		cout << "�� �� :" << Name << '\n';
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
		// �̴ϼ� ������
	}

	User(const User& copy) : ID(copy.ID) , Money(copy.Money), Name(copy.Name)
	{
		cout << "new Copy obj :" << endl;
	}

	~User()
	{
		// �Ҹ���
		cout << "delete obj :" << endl;

	}
};

class AccountHandler // ��Ʈ�� Ŭ���� �߰� , �������� ����� ����ϴ� Ŭ����
{
private:

	User* user[100];
	int idx;

public :

	AccountHandler(); // ������
	~AccountHandler(); // �Ҹ���

	void CreateAccount(void);
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
	int num, money;
	string name;

	cout << "���� ��ȣ�� �Է� ���ּ���." << '\n';
	cin >> num;
	cout << "���� �ݾ��� �Է� ���ּ���. " << '\n';
	cin >> money;
	cout << "�̸��� �Է� ���ּ���. " << '\n';
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