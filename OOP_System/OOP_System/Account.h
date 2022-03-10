#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account // Entity Ŭ���� , �����͸� �����ϰ� �����ϴ� Ŭ���� 
{
private: //�������� 
	int ID;
	int balance;
	String cusName;

public:


	Account(int ID, int balance, String Name); // ������
	int GetID() const;
	virtual void Deposit(int money);
	int Remove(int money);
	void ShowInfo() const; // virtual �Լ��� ����Ͽ� �������� ���
};

#endif

