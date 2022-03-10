#pragma once
#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__

#include "NormalAccount.h"
#include "String.h"


class HighCreditAccount : public NormalAccount // NomalAccount를 부모로 사용하는 클래스 추가 이자가 존재한다.
{
private:
	const int specialInterest;



public:
	HighCreditAccount(int ID, int Money, String Name, int rate, int special) : NormalAccount(ID, Money, Name, rate), specialInterest(special)
	{
		// 이니셜 라이저
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void Deposit(int money)
	{
		if (money < 0)
			DepositException expn(money);

		Account::Deposit(money);
		Account::Deposit(money * (specialInterest / 100.0)); // 이자 계산

	}

};

#endif // !__HIGH_CREDIT_ACCOUNT__
