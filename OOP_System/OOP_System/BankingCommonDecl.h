#pragma once
#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream> 
#include <cstring>

using namespace std;
// 이름의 최대 길이 
const int NAME_LEN = 20;

// 프로그램 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHRAW, INQUIRE, EXIT };

// 신용등급
enum { Level_A = 7, Level_B = 4, Level_C = 2 };

//계좌 종류
enum { NORMAL = 1, CREDIT = 2 };

#endif // !__BANKING_COMMON_H__
