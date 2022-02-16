#include<iostream>

using namespace std;


class User
{
private: //�������� 
	int ID;
	int Money;
	string Name;

public :

	void ShowInfo()
	{
		cout << "���� ��ȣ :" << ID << '\n';
		cout << "���� �ݾ� :" << Money << '\n';
		cout << "�� �� :" << Name << '\n';
	}

	int GetID()
	{
		return ID;
	}


	void Insert(int money)
	{
		this->Money += money;
	}
	void Remove(int money)
	{
		if (money > Money)
			return;

		this->Money -= money;
	}

	User(int ID, int Money, string Name) : ID(ID), Money(Money), Name(Name)
	{
		// �̴ϼ� ������
	}

	~User()
	{
		// �Ҹ���
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

		default :
			cout << "�߸��� ���ڸ� �Է� �Ͽ����ϴ�" << '\n';
			break;
	}
}


void  CreateAccount()
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

void CallRemove()
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



int main()
{

	int val;

	while (1)
	{

		cout << "----------Menu-----------" << '\n';
		cout << "1. ���°���" << '\n';
		cout << "2. �� ��" << '\n';
		cout << "3. �� ��" << '\n';
		cout << "4. ���� ���� ��ü ���" << '\n';
		cout << "5. ���α׷� ����" << '\n';

		cin >> val;
		cout << "���� : " << val << '\n';

		if (val == 5)
		{
			cout << "���α׷��� ���� �մϴ�." << '\n';
			break;

		}

		Menu(val);
	}
	return 0;
}