#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "account.h"


class accountHandler {
private:
	Account* account[100]; // ������ �� ����
	int curCount = 0; // ������ �� ��

public:
	void ShowMenu() const;		// �޴� ���
	void MakeAccount();			// ���� ����
	void DepositMoney();		// �Ա�
	void WithdrawMoney();		// ���
	void ShowAllInfo() const;	// ��� �� ���� ���
	~accountHandler();
};


#endif