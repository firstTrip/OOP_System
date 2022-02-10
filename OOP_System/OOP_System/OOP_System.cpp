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
			cout << "���¸� ���� �մϴ�." << '\n';
			CreateAccount();
			break;

		case 2:
			Insert();
			break;

		case 3:
			Remove();
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

void CreateAccount()
{
	int num, money;
	string name;

	cout << "���� ��ȣ�� �Է� ���ּ���." << '\n';
	cin >> num;
	cout << "���� �ݾ��� �Է� ���ּ���. " << '\n';
	cin >> money;
	cout << "�̸��� �Է� ���ּ���. " << '\n';
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
		cout << (i + 1) << " ��° ����" << '\n';
		cout << "���� ��ȣ :" << user[i].ID << '\n';
		cout << "���� �ݾ� :" << user[i].Money << '\n';
		cout << "�� �� :" << user[i].Name << '\n';
		cout << "--------------------------" << '\n';

	}
}

void Insert()
{
	int inputdata;
	cout << "�Ա��� ���¸� �Է��ϼ���." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i].ID == inputdata)
		{
			int money;
			cout << "�Ա��� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;

			user[i].Money += money;

			return;

		}
	}

	cout << "��ġ�ϴ� ���°� �����ϴ�." << '\n';

}

void Remove()
{
	int inputdata;
	cout << "����� ���¸� �Է��ϼ���." << '\n';
	cin >> inputdata;

	for (int i = 0; i < idx; i++)
	{
		if (user[i].ID == inputdata)
		{
			int money;
			cout << "����� �ݾ��� ���� �ּ���." << '\n';
			cin >> money;

			user[i].Money -= money;

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