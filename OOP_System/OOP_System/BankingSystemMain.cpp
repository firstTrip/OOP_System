#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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
		case MAKE:
			cout << "���¸� ���� �մϴ�." << '\n';
			manager.CreateAccount();
			break;

		case DEPOSIT:
			manager.CallInsert();
			break;

		case WITHRAW:
			manager.CallRemove();
			break;

		case INQUIRE:
			cout << "��� ���¸� ����մϴ�." << '\n';
			manager.ShowAllAccount();
			break;

		case EXIT:
			return 0;

		default:
			cout << "�߸��� ���ڸ� �Է� �Ͽ����ϴ�" << '\n';
			break;
		}
	}
	return 0;
}