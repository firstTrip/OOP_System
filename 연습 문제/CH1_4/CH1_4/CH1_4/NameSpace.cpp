#include "NameSpace.h"

void BestComImpl::SimpleFunc(void)
{
	cout << "BestCom �� ������ �Լ�" << endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	cout << "So pretty!!!!" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
	cout << "ProgCom �� ������ �Լ�" << endl;

}
