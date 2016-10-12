#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "account.h"

class NormalAccount : public Account {
private:
	float rate;

public:
	NormalAccount(int id, char *name, int balance, float rate);
	virtual void Deposit(int money);		// 입금
	virtual void ShowAccInfo() const;		// 정보출력
	virtual ~NormalAccount();
};

#endif