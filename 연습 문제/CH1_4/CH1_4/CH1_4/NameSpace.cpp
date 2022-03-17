#include "NameSpace.h"

void BestComImpl::SimpleFunc(void)
{
	cout << "BestCom 이 정의한 함수" << endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	cout << "So pretty!!!!" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
	cout << "ProgCom 이 정의한 함수" << endl;

}
