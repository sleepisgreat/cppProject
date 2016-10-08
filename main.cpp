#include "account.h"
#include "common.h"

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOWINFO, EXIT };

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllInfo();

Account* account[100]; // 가입한 고객 정보
int curCount = 0;

int main() {
	int num;

	while (true) {

		ShowMenu();
		cout << "선택: ";
		cin >> num;

		switch (num) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case SHOWINFO:
			ShowAllInfo();
			break;
		case EXIT:
			return 0;
		}
	}

	return 0;
}

void ShowMenu() {
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount() {
	int id, balance;
	char name[MAX_NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;

	account[curCount++] = new Account(id, name, balance);
}

void DepositMoney() {
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

void WithdrawMoney() {
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

void ShowAllInfo() {
	cout << "[사용자 정보]" << endl;
	for (int i = 0; i < curCount; i++) {
		cout << "--------" << i + 1 << "--------" << endl;
		cout << "계좌 ID: " << account[i]->GetAccountID() << endl;
		cout << "이름: " << account[i]->GetUserName() << endl;
		cout << "잔액: " << account[i]->GetBalance() << endl;
		cout << endl;
	}
}