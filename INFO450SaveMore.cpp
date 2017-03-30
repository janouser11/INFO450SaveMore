// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Account {
public:
	int accountNum;
	double interest, balance;
	const char *Type;

public: Account() {
	interest = 0;
	balance = 0;
	accountNum = 222;
}
public:
	virtual int deposit(double deposit);
	virtual void displaySummary();
	virtual int withdraw(double withdrawal);
};

void Account::displaySummary() {
	cout << "Account Number: " << accountNum << endl;
	cout << "Interest Rate: " << interest << endl;
	cout << "Balance: " << balance << endl;
	cout << "Type of Account: " << Type << endl;
}

int Account::deposit(double deposit) {
	if (deposit > 0) {
		balance = deposit + balance;
		return 0;
	}
	else {
		cout << "No negative deposits allowed!";
		return -1;
	}
}

class Savings : public Account {
public:
	Savings() {
		Type = "Savings Account";
	}
	double calculateSavings() {
		if (balance >= 10000)
		{
			interest = .02;
		}
		else {
			interest = .01;
		} return balance;
	}
};

int Account::withdraw(double withdrawal) {
	balance = balance - withdrawal;
	if (balance < 0) {
		cout << "#########ERROR!!!!! NOT ENOUGH FUNDS FOR WITHDRAWL#########\n";
		balance = balance + withdrawal;
		return 0;
	}
	else {
		cout << "\nWithdraw was successful!!\n\n";
		return 1;
	}
}

class Checking : public Account {
public:
	Checking() {
		Type = "Checking";
	}
	void calculateCheck() {
		if (balance < 500)
		{
			balance -= 5;
		}
	}
	double orderCheck(int order) {
		const int CHECKOUT_AMOUNT = 15;
		balance = balance - (order * CHECKOUT_AMOUNT);
		if (balance <0) {
			cout << "Can not order that amount of checks\n";
			balance = balance + (order * CHECKOUT_AMOUNT);
			return balance;
		}
		else {
			cout << "Order successful!\n";
			return balance;
		}
	}
};

//inherits from account class
class CoD : public Account {
public:
	CoD() {
		Type = " Certificate of deposit";
	}
	void calculateCoD(int term) {
		if (term >= 5) {
			interest = .10;
		}
		else {
			interest = .05;
		}
		balance = balance - (balance * interest);
	}
};

int main() {

	int usersDepositAmount, usersWithdrawalAmount, term, order;
	const int WITHDRAW_FEE = 2;
	Savings SavingsAccount;
	Checking CheckingAccount;
	CoD CoD_Account;

	cout << "#####################################\n";
	cout << "Welcome to Save-More Banking Service\n";
	cout << "Creating Bank Accounts...\n\n";
	cout << "Enter deposit for savings account: ";
	cin >> usersDepositAmount;
	SavingsAccount.deposit(usersDepositAmount);
	cout << "******Interest for Savings account Calculated***** \n";
	SavingsAccount.calculateSavings();
	SavingsAccount.displaySummary();

	cout << "Enter amount you want to withdraw from savings account: ";
	cin >> usersWithdrawalAmount;
	SavingsAccount.withdraw(usersWithdrawalAmount + WITHDRAW_FEE);
	SavingsAccount.displaySummary();

	cout << "Enter deposit amount for checking account: ";
	cin >> usersDepositAmount;
	CheckingAccount.deposit(usersDepositAmount);
	CheckingAccount.calculateCheck();
	CheckingAccount.displaySummary();

	cout << "Enter amount to withdraw from checking account" ;
	cin >> usersWithdrawalAmount;
	CheckingAccount.withdraw(usersWithdrawalAmount);
	CheckingAccount.displaySummary();
	cout << "\nAmount of checks to order\n";
	cin >> order;

	CheckingAccount.orderCheck(order);
	CheckingAccount.displaySummary();

	cout << "Enter deposit for Certificate of deposit: ";
	cin >> usersDepositAmount;
	CoD_Account.deposit(usersDepositAmount);

	cout << "Enter years for Certificate of deposit: ";
	cin >> term;
	CoD_Account.calculateCoD(term);
	CoD_Account.displaySummary();

	cout << "Enter amount you want to withdraw from Certificate of Deposit: ";
	cin >> usersWithdrawalAmount;
	CoD_Account.withdraw(usersWithdrawalAmount*1.1);
	SavingsAccount.displaySummary();
	CheckingAccount.displaySummary();
	CoD_Account.displaySummary();
}






