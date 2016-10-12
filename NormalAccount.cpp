#include "common.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int id, char *name, int balance, float rate)
	: Account(id, name, balance), rate(rate)
{ }

void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
	Account::Deposit( (int)(money * (rate / 100.0f)) );
}

void NormalAccount::ShowAccInfo() const {
	Account::ShowAccInfo();
	cout << "ÀÌÀ²: " << this->rate << "%" << endl;
}

NormalAccount::~NormalAccount() {
	;
}