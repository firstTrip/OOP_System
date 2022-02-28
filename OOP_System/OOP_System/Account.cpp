#define _CRT_SECURE_NO_WARNINGS 

// Account��  �Լ� ���ǰ� �Ǿ��ִ� ����

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int Money, char *Name) : ID(ID), Money(Money)
{

	cusName = new char[strlen(Name) + 1];
	strcpy(cusName, Name);
	// �̴ϼ� ������
}

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

int Account::GetID() const
{
	return ID;
}

void Account::ShowInfo() const // virtual �Լ��� ����Ͽ� �������� ���
{
	cout << "���� ��ȣ :" << ID << '\n';
	cout << "���� �ݾ� :" << Money << '\n';
	cout << "�� �� :" << cusName << '\n';
}


void Account::Deposit(int money)
{
	this->Money += money;
}

int Account::Remove(int money)
{
	if (money > Money)
		return 0;

	this->Money -= money;
	return this->Money;
}

Account ::  ~Account()
{
	// �Ҹ���
	cout << "delete obj :" << endl;
	delete[]cusName;

}