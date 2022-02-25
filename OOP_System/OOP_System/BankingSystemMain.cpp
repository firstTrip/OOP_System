#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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
		case MAKE:
			cout << "계좌를 개설 합니다." << '\n';
			manager.CreateAccount();
			break;

		case DEPOSIT:
			manager.CallInsert();
			break;

		case WITHRAW:
			manager.CallRemove();
			break;

		case INQUIRE:
			cout << "모든 계좌를 출력합니다." << '\n';
			manager.ShowAllAccount();
			break;

		case EXIT:
			return 0;

		default:
			cout << "잘못된 숫자를 입력 하였습니다" << '\n';
			break;
		}
	}
	return 0;
}