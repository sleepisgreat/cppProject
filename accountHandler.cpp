#include "accountHandler.h"
#include "common.h"
#include "NormalAccount.h"

void accountHandler::ShowMenu() const {
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void accountHandler::MakeAccount() {
	char rank;
	int num, rate;
	int id, balance;
	char name[MAX_NAME_LEN];

	while (true) {
		cout << "[계좌개설]" << endl;
		cout << "계좌 선택(보통계좌[1], 상위계좌[2] : ";
		cin >> num;

		cout << "계좌 ID: ";
		cin >> id;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;

		if (num == 1) {
			account[curCount++] = new NormalAccount(id, name, balance, RATE);
			break;
		}
		else if (num == 2) {
			cout << "신용등급: ";
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

	cout << "[입금]" << endl;
	cout << "ID 입력: ";
	cin >> id;

	for (int i = 0; i < curCount; i++) {
		if (account[i]->GetAccountID() == id) {
			cout << "입금액: ";
			cin >> money;
			account[i]->Deposit(money);
			return;
		}
	}
	cout << "일치하는 ID가 없습니다." << endl;
}

void accountHandler::WithdrawMoney() {
	int id, money;

	cout << "[출금]" << endl;
	cout << "ID 입력: ";
	cin >> id;

	for (int i = 0; i < curCount; i++) {
		if (account[i]->GetAccountID() == id) {
			while (true) {
				cout << "출금액(나가기['-1' 입력]): ";
				cin >> money;
				if (account[i]->GetBalance() < money) {
					cout << "잔액이 부족합니다. 현재 잔액 " << account[i]->GetBalance() << "원" << endl;
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
	cout << "일치하는 ID가 없습니다." << endl;
}

void accountHandler::ShowAllInfo() const {
	
	cout << "[사용자 정보]" << endl;
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