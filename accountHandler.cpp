#include "accountHandler.h"
#include "common.h"

void accountHandler::ShowMenu() const {
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void accountHandler::MakeAccount() {
	int id, balance;
	char name[MAX_NAME_LEN];

	cout << "[���°���]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;

	account[curCount++] = new Account(id, name, balance);
}

void accountHandler::DepositMoney() {
	int money, id;

	cout << "[�Ա�]" << endl;
	cout << "ID �Է�: ";
	cin >> id;

	for (int i = 0; i < curCount; i++) {
		if (account[i]->GetAccountID() == id) {
			cout << "�Աݾ�: ";
			cin >> money;
			account[i]->Deposit(money);
			return;
		}
	}
	cout << "��ġ�ϴ� ID�� �����ϴ�." << endl;
}

void accountHandler::WithdrawMoney() {
	int id, money;

	cout << "[���]" << endl;
	cout << "ID �Է�: ";
	cin >> id;

	for (int i = 0; i < curCount; i++) {
		if (account[i]->GetAccountID() == id) {
			while (true) {
				cout << "��ݾ�(������['-1' �Է�]): ";
				cin >> money;
				if (account[i]->GetBalance() < money) {
					cout << "�ܾ��� �����մϴ�. ���� �ܾ� " << account[i]->GetBalance() << "��" << endl;
					continue;
				}
				else if (money == -1)
					;
				else
					account[i]->Withdraw(money);
				return;
			}
		}
	}
	cout << "��ġ�ϴ� ID�� �����ϴ�." << endl;
}

void accountHandler::ShowAllInfo() const {
	cout << "[����� ����]" << endl;
	for (int i = 0; i < curCount; i++) {
		cout << "--------" << i + 1 << "--------" << endl;
		cout << "���� ID: " << account[i]->GetAccountID() << endl;
		cout << "�̸�: " << account[i]->GetUserName() << endl;
		cout << "�ܾ�: " << account[i]->GetBalance() << endl;
		cout << endl;
	}
}

accountHandler::~accountHandler() {
	delete []account;
}