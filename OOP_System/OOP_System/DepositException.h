#pragma once
#ifndef __DEPOSIT_EXCEPTION_H__
#define __DEPOSIT_EXCEPTION_H__

#include "AccountException.h"
#include "String.h"

class DepositException : AccountException
{
private :
	int reqDep;

public:
	DepositException(int money) :reqDep(money){ }

	void ShowAccountException()
	{
		cout << "예외 메시지 : " << reqDep << "는 입금 불가" << '\n';
	} 
};

#endif // !__DEPOSIT_EXCEPTION_H__
