#include "account.h"
#include "common.h"
#include "accountHandler.h"

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOWINFO, EXIT };

int main() {
	accountHandler accHandler;
	int num;

	while (true) {

		accHandler.ShowMenu();
		cout << "¼±ÅÃ: ";
		cin >> num;

		switch (num) {
		case MAKE:
			accHandler.MakeAccount();
			break;
		case DEPOSIT:
			accHandler.DepositMoney();
			break;
		case WITHDRAW:
			accHandler.WithdrawMoney();
			break;
		case SHOWINFO:
			accHandler.ShowAllInfo();
			break;
		case EXIT:
			return 0;
		}
	}

	return 0;
}

