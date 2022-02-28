#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler // ��Ʈ�� Ŭ���� �߰� , �������� ����� ����ϴ� Ŭ����
{
private:

	Account* user[100];
	int idx;
	BoundCheckAccountPtrArray accArr;

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

