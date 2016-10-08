#include "account.h"
#include "common.h"

Account::Account(int id, char *name, int balance)
	: accID(id), balance(balance)
{
	this->name = new char[MAX_NAME_LEN];
	strcpy_s(this->name, MAX_NAME_LEN, name);
}

int Account::GetAccountID() {
	return this->accID;
}

int Account::GetBalance() {
	return this->balance;
}

char* Account::GetUserName() {
	return this->name;
}

void Account::Deposit(int money) {
	this->balance += money;
}

void Account::Withdraw(int money) {
	this->balance -= money;
}

Account::~Account() {
	delete[]this->name;
}