#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"


class AccountHandler // ��Ʈ�� Ŭ���� �߰� , �������� ����� ����ϴ� Ŭ����
{
private:

	Account* user[100];
	int idx;
	BoundCheckArray<Account *> accArr;

public:

	AccountHandler(); // ������
	~AccountHandler(); // �Ҹ���

	void CreateAccount(void);
	void ShowAllAccount(void) const; // ���� ��ȯ�� ������� �ʱ� ������ const �� ���� ���ش�.
	void CallInsert(void);
	void CallRemove(void);
	void ShowMenu(void);

protected:
	void CreateNomalAccount(void);
	void CreateHighCreditAccount(void);
};

#endif // !__ACCOUNT_HANDLER__

