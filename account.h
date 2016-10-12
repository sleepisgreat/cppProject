#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define RATE	2		// 이율

enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

class Account {
private:
	int accID;
	int balance;
	char *name;

public:
	Account(const Account &ref);
	Account(int id, char *name, int balance);
	int GetAccountID() const;			// 계좌번호 반환
	virtual void Deposit(int money);	// 입금
	int GetBalance() const;				// 잔액 반환
	char* GetUserName() const;			// 고객 이름 반환
	void Withdraw(int money);			// 출금
	virtual void ShowAccInfo() const;	// 정보출력
	virtual ~Account();
};

#endif