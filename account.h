#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;
	int balance;
	char *name;

public:
	Account(int id, char *name, int balance);
	int GetAccountID(); // ���¹�ȣ ��ȯ
	void Deposit(int money); // �Ա�
	int GetBalance(); // �ܾ� ��ȯ
	char* GetUserName(); // �� �̸� ��ȯ
	void Withdraw(int money); // ���
	~Account();
};

#endif