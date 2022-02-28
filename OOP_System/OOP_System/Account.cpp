#define _CRT_SECURE_NO_WARNINGS 

// Account의  함수 정의가 되어있는 공간

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int Money, char *Name) : ID(ID), Money(Money)
{

	cusName = new char[strlen(Name) + 1];
	strcpy(cusName, Name);
	// 이니셜 라이저
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

void Account::ShowInfo() const // virtual 함수를 사용하여 다형성을 사용
{
	cout << "계좌 번호 :" << ID << '\n';
	cout << "현재 금액 :" << Money << '\n';
	cout << "이 름 :" << cusName << '\n';
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
	// 소멸자
	cout << "delete obj :" << endl;
	delete[]cusName;

}