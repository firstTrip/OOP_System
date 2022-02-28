#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler // 컨트롤 클래스 추가 , 전반적인 기능을 담당하는 클래스
{
private:

	Account* user[100];
	int idx;
	BoundCheckAccountPtrArray accArr;

public:

	AccountHandler(); // 생성자
	~AccountHandler(); // 소멸자

	void CreateAccount(void);
	void ShowAllAccount(void) const; // 값의 변환을 허용하지 않기 때문에 const 를 선언 해준다.
	void CallInsert(void);
	void CallRemove(void);
	void ShowMenu(void);

protected:
	void CreateNomalAccount(void);
	void CreateHighCreditAccount(void);
};

#endif // !__ACCOUNT_HANDLER__

