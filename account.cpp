#include "account.h"
#include "common.h"

Account::Account(const Account &ref) 
	: accID(ref.accID), balance(ref.balance) 
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy_s(this->name, strlen(ref.name) + 1, ref.name);
}

Account::Account(int id, char *name, int balance)
	: accID(id), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Account::GetAccountID() const {
	return this->accID;
}

int Account::GetBalance() const{
	return this->balance;
}

char* Account::GetUserName() const{
	return this->name;
}

void Account::Deposit(int money) {
	this->balance += money;
}

void Account::Withdraw(int money) {
	this->balance -= money;
}

void Account::ShowAccInfo() const {
	cout << "°èÁÂ ID: " << this->accID << endl;
	cout << "ÀÌ¸§: " << this->name << endl;
	cout << "ÀÜ¾×: " << this->balance << endl;
}

Account::~Account() {
	delete[]this->name;
}

