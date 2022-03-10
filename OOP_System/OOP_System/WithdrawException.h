#pragma once
#ifndef __WITHDRAW_EXCEPTION_H__
#define __WITHDRAW_EXCEPTION_H__

#include "AccountException.h"
#include "String.h"


class WithdrawException
{
private :
	int reqDep;

public :
	WithdrawException(int money) : reqDep(money) {}

	void ShowAccountException()
	{
		cout << "예외 메시지 : " << reqDep << "는 출금 불가" << '\n';
	}
};
#endif // !__WITHDRAW_EXCEPTION_H__
