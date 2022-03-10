#define _CRT_SECURE_NO_WARNINGS 

// Account��  �Լ� ���ǰ� �Ǿ��ִ� ����

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h" 



Account::Account(int ID, int Money, String Name) : ID(ID), balance(Money)
{
	cusName = Name;
	//cusName = new char[strlen(Name) + 1];
	//strcpy(cusName, Name);
	// �̴ϼ� ������
}

/*
Account::Account(const Account& ref) : ID(ref.ID), Money(ref.Money)
{
	cout << "new Copy obj :" << endl;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref)
{
	ID = ref.ID;
	Money = ref.Money;

	delete []cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	

	return *this;
}
*/

int Account::GetID() const
{
	return ID;
}

void Account::ShowInfo() const // virtual �Լ��� ����Ͽ� �������� ���
{
	cout << "���� ��ȣ :" << ID << '\n';
	cout << "���� �ݾ� :" << balance << '\n';
	cout << "�� �� :" << cusName << '\n';
}


void Account::Deposit(int money)
{
	if (money < 0)
		DepositException expn(money);

	this->balance += money;
	
}

int Account::Remove(int money)
{
	if (money > balance)
		throw WithdrawException(money);

	if(balance<money)
		throw WithdrawException(money);

	balance -= money;
	return this->balance;
}

/*
Account ::  ~Account()
{
	// �Ҹ���
	cout << "delete obj :" << endl;
	delete[]cusName;

}
*/