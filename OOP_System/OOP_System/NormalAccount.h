#ifndef __NIMAL_ACCOUNT_H__
#define __NIMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "AccountException.h" 


class NormalAccount : public Account // Account �� �θ�� �� �ڽ� Ŭ���� , interst ������ �߰��ȴ�.
{
private:
	const int interRate;

public:
	NormalAccount(int ID, int Money, String Name, int interRate) :
		Account(ID, Money, Name), interRate(interRate)
	{
		// �̴ϼ� ������
	}

	virtual void Deposit(int money)
	{
		if (money < 0)
			DepositException expn(money);

		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0)); // ���� ���

	}

};

#endif