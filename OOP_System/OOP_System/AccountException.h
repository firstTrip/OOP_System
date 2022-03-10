#pragma once
#ifndef  __ACCOUNT_EXCEPTION_H__
#define  __ACCOUNT_EXCEPTION_H__

class DepositException
{
private:
	int reqDep;

public:
	DepositException(int money) :reqDep(money) { }

	void ShowAccountException()
	{
		cout << "예외 메시지 : " << reqDep << "는 입금 불가" << '\n';
	}
};

class WithdrawException
{
private:
	int reqDep;

public:
	WithdrawException(int money) : reqDep(money) {}

	void ShowAccountException()
	{
		cout << "예외 메시지 : " << reqDep << "는 출금 불가" << '\n';
	}
};
#endif // ! __ACCOUNT_EXCEPTION_H__
