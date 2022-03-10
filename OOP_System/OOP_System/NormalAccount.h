#ifndef __NIMAL_ACCOUNT_H__
#define __NIMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "AccountException.h" 


class NormalAccount : public Account // Account 를 부모로 둔 자식 클래스 , interst 변수가 추가된다.
{
private:
	const int interRate;

public:
	NormalAccount(int ID, int Money, String Name, int interRate) :
		Account(ID, Money, Name), interRate(interRate)
	{
		// 이니셜 라이저
	}

	virtual void Deposit(int money)
	{
		if (money < 0)
			DepositException expn(money);

		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0)); // 이자 계산

	}

};

#endif