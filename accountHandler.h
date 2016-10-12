#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "account.h"


class accountHandler {
private:
	Account* account[100]; // 가입한 고객 정보
	int curCount = 0; // 가입한 고객 수

public:
	void ShowMenu() const;		// 메뉴 출력
	void MakeAccount();			// 계좌 생성
	void DepositMoney();		// 입금
	void WithdrawMoney();		// 출금
	void ShowAllInfo() const;	// 모든 고객 정보 출력
	~accountHandler();
};


#endif