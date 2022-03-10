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
		cout << "���� �޽��� : " << reqDep << "�� �Ա� �Ұ�" << '\n';
	} 
};

#endif // !__DEPOSIT_EXCEPTION_H__
