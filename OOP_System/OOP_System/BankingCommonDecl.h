#pragma once
#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream> 
#include <cstring>

using namespace std;
// �̸��� �ִ� ���� 
const int NAME_LEN = 20;

// ���α׷� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHRAW, INQUIRE, EXIT };

// �ſ���
enum { Level_A = 7, Level_B = 4, Level_C = 2 };

//���� ����
enum { NORMAL = 1, CREDIT = 2 };

#endif // !__BANKING_COMMON_H__
