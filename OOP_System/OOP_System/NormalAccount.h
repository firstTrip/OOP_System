#ifndef __NIMAL_ACCOUNT_H__
#define __NIMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account // Account �� �θ�� �� �ڽ� Ŭ���� , interst ������ �߰��ȴ�.
{
private:
	const int interRate;

public:
	NormalAccount(int ID, int Money, char* Name, int interRate) : 
		Account(ID, Money, Name), interRate(interRate)
	{
		// �̴ϼ� ������
	}

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0)); // ���� ���

	}

};

#endif