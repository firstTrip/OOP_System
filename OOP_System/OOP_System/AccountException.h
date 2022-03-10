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
		cout << "���� �޽��� : " << reqDep << "�� �Ա� �Ұ�" << '\n';
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
		cout << "���� �޽��� : " << reqDep << "�� ��� �Ұ�" << '\n';
	}
};
#endif // ! __ACCOUNT_EXCEPTION_H__
