#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account // Entity Ŭ���� , �����͸� �����ϰ� �����ϴ� Ŭ���� 
{
private: //�������� 
	int ID;
	int Money;
	String cusName;

public:


	Account(int ID, int Money, String Name); // ������

	Account(const Account& ref); // ������ 

	Account& operator=(const Account& ref);

	void ShowInfo() const; // virtual �Լ��� ����Ͽ� �������� ���
	int GetID() const;
	virtual void Deposit(int money);
	int Remove(int money);

	~Account(); // �Ҹ��� 
};

#endif

