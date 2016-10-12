#include "accountHandler.h"
#include "common.h"
#include "NormalAccount.h"

void accountHandler::ShowMenu() const {
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void accountHandler::MakeAccount() {
	char rank;
	int num, rate;
	int id, balance;
	char name[MAX_NAME_LEN];

	while (true) {
		cout << "[���°���]" << endl;
		cout << "���� ����(�������[1], ��������[2] : ";
		cin >> num;

		cout << "���� ID: ";
		cin >> id;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;

		if (num == 1) {
			account[curCount++] = new NormalAccount(id, name, balance, RATE);
			break;
		}
		else if (num == 2) {
			cout << "�ſ���: ";
			cin >> rank;
			account[curCount++] = new NormalAccount(id, name, balance, RATE);
			break;
		}
		else
			continue;
	}
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
		cout << "-------- " << i + 1 << " --------" << endl;
		account[i]->ShowAccInfo();
		cout << endl;
	}
}

accountHandler::~accountHandler() {
	for (int i = 0; i < curCount; i++) {
		delete account[i];
	}
}