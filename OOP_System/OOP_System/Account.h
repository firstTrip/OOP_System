#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account // Entity 클래스 , 데이터를 저장하고 보관하는 클래스 
{
private: //정보은닉 
	int ID;
	int Money;
	String cusName;

public:


	Account(int ID, int Money, String Name); // 생성자

	Account(const Account& ref); // 참조자 

	Account& operator=(const Account& ref);

	void ShowInfo() const; // virtual 함수를 사용하여 다형성을 사용
	int GetID() const;
	virtual void Deposit(int money);
	int Remove(int money);

	~Account(); // 소멸자 
};

#endif

