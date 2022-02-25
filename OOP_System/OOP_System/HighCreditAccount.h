#pragma once
#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // NomalAccount�� �θ�� ����ϴ� Ŭ���� �߰� ���ڰ� �����Ѵ�.
{
private:
	const int specialInterest;



public:
	HighCreditAccount(int ID, int Money, char* Name, int rate, int special) : NormalAccount(ID, Money, Name, rate), specialInterest(special)
	{
		// �̴ϼ� ������
	}
	/*
	NomalAccount(const NomalAccount& copy) :Account(copy.ID, Money, Name), grade(copy.grade)
	{
		cout << "new Copy obj :" << endl;
	}*/

	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (specialInterest / 100.0)); // ���� ���

	}

};

#endif // !__HIGH_CREDIT_ACCOUNT__