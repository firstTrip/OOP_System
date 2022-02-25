#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account // Entity Ŭ���� , �����͸� �����ϰ� �����ϴ� Ŭ���� 
{
private: //�������� 
	const int ID;
	int Money;
	char* cusName;

public:


	Account(int ID, int Money, char* Name); // ������

	Account(const Account& ref); // ������ 


	void ShowInfo() const; // virtual �Լ��� ����Ͽ� �������� ���
	int GetID() const;
	virtual void Deposit(int money);
	int Remove(int money);

	~Account(); // �Ҹ��� 
};

#endif

