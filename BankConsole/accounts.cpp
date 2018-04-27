#include <iostream>
using namespace std;
#include "accounts.h"
#include <fstream>


account::account() : date(), balance(0){}
bool account::deposite(double n) {
	return true;
}
bool account::withard(double n){
	return true;
}
double account::balance_Enq(){
	return balance;
}
void account::put_in_file(Client obj, int Id){
	cout << "To Write On My File " << endl;
}
//==========================================================================================================================
Checking_account::Checking_account() : account(), limit_card(1000), payment(0) {}
bool Checking_account::deposite(double n) {
	if (n < 0)
		return 0;
	if (payment)
	{
		if (n >= payment)
		{
			balance += (n - payment);
			payment = 0;
			return 1;
		}
		if (n < payment)
		{
			payment -= n;
			return 1;
		}

	}

	this->balance += n;
	return 1;
}

bool Checking_account::withard(double n){

	if (n > (limit_card + balance) || (n < 0))
		return 0;
	if (n <= balance)
	{
		balance -= n;
		return 1;
	}
	if (n > balance)
	{
		payment = n - balance;
		if (limit_card)
			limit_card -= payment;
		payment *= 0.1;
		return 1;
	}
 
}

void Checking_account::put_in_file(Client obj,int Id){
	ofstream myfile("CheckingAccounts.txt", ios::app);
	myfile << "Id=" << Id << "$Name=" << obj.Name << "$AccountNumber=" << obj.AccountNumber 
		   << "$Balance=" << obj.balance << "$DateOfCreate=" << obj.month << endl;
	myfile.close();
}

 

//==========================================================================================================================
Saving_account::Saving_account() : account(), interest_rate(0.1), monthly(1){}
bool Saving_account::make_account(double n){

	if (n < 0)
		return 0;
	balance = n;
	return 1;
}

bool Saving_account::withard(double n){

	if (n > balance || n < 0)
		return 0;
	balance -= n;
	return 1;
}

void Saving_account::put_in_file(Client obj, int id){
	ofstream myfile("SavingAccounts.txt", ios::app);
	myfile << "Id=" << id << "$Name=" << obj.Name << "$AccountNumber=" << obj.AccountNumber
		<< "$Balance=" << obj.balance << "$DateOfCreate=" << obj.month << endl;

}


void Saving_account::add_interest(){ cout << "WAIT" << endl; }
//==========================================================================================================================



loan::loan() :account(), interest(0.1), duration_monthly(10){}

bool loan::make_loan(double n){
	if (n < 0)
		return 0;
	balance = n;
	return 1;
}
bool loan::pay_part(double n){
	if (n < 0 || balance == 0)
		return 0;
	balance -= n;
	return 1;
}
void loan::put_in_file(Client obj, int Id) {
	ofstream myfile("LoanAccounts.txt", ios::app);
	myfile << "Id=" << Id << "$Name=" << obj.Name << "$AccountNumber=" << obj.AccountNumber
		<< "$Balance=" << obj.balance << "$DateOfCreate=" << obj.month << endl;

}


//==========================================================================================================================

void Client::set_data(string type = "Checking" , int id = 0 ){
	if (type == "Checking") this->type_account = "Checking";
	else if (type == "Saving") this->type_account = "Saving";
	else this->type_account = "Loan";
	cout << "Enter Your Name :";							cin.ignore(); cin.getline(Name, sizeof(Name));
	cout << "Enter Your Phone: ";							cin.getline(phone, sizeof(phone));
	cout << "Enter Email : ";								cin.getline(Email, sizeof(Email));
	cout << "You Will Open An Account With Balance :  $";   cin >> this->balance;
	cout << "Account Number Please : ";						cin >> this->AccountNumber;
	cout << "The Date In Month : ";						    cin >> this->month;
	this->Id = id;
}

void Client::put_in_file( Client obj ){
	ofstream myfile("Customers.txt", ios::app);
	
	myfile <<"Id=" << obj.Id <<"$Name=" << obj.Name << "$Email=" << obj.Email << "$Phone=" << obj.phone << "$AccountType=" << obj.type_account << "$Balance=" << obj.balance
		<< "$AccountNumber=" << obj.AccountNumber << "$DateOfCreate=" << obj.month << endl ;
	
	myfile.close();
}



//==========================================================================================================================




















