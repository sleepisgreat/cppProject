#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;
	int balance;
	char *name;

public:
	Account(const Account &ref);
	Account(int id, char *name, int balance);
	int GetAccountID() const; // ���¹�ȣ ��ȯ
	void Deposit(int money); // �Ա�
	int GetBalance() const; // �ܾ� ��ȯ
	char* GetUserName() const; // �� �̸� ��ȯ
	void Withdraw(int money); // ���
	~Account();
};

#endif