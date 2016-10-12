#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define RATE	2		// ����

enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

class Account {
private:
	int accID;
	int balance;
	char *name;

public:
	Account(const Account &ref);
	Account(int id, char *name, int balance);
	int GetAccountID() const;			// ���¹�ȣ ��ȯ
	virtual void Deposit(int money);	// �Ա�
	int GetBalance() const;				// �ܾ� ��ȯ
	char* GetUserName() const;			// �� �̸� ��ȯ
	void Withdraw(int money);			// ���
	virtual void ShowAccInfo() const;	// �������
	virtual ~Account();
};

#endif