#include <iostream>
#include <string>	
using namespace std;


class date{
public:
	int day;
	int month;
	int year;
	date() :day(0), month(0), year(0){}
}; 

//==========================================================================================================================


class person : public date {
public:
	char Name[100];
	char Email[100];
	char phone[100];
	int Id;
public:
	person() : date() // : Name("Ahmed"), Email("Bank@yahoo.com"), Gender("Male"), phone("01120647765"), Id(1){}
	{
		Id = 1;
	}
};

class Admin : public person{
	Admin() :person(){}
};
class Client : public person{

public:
	Client() :person(){ type_account = "Account"; }
	void set_data(string type, int id);
	void put_in_file(Client n);
public:
	double deposite;
	double withard;
	string type_account;
	int AccountNumber;
	double date_creat_acc;
	double balance;

};


//==========================================================================================================================
 class account : public date{

public:
	account();
	virtual bool deposite(double n);
	virtual bool withard(double n);
	virtual void put_in_file(Client obj, int Id);
	double balance_Enq();

public:
	double balance;
	date acc_created;
	date acc_deposite_date;
	date acc_withard_date;


};
//==========================================================================================================================
class Checking_account : public account{
public:
	Checking_account();
	bool deposite(double n) override;
	bool withard(double n) override;
	void put_in_file(Client obj, int Id)override;
	double get_payment(){ return payment; }
	double get_limit() { return limit_card; }

protected:
	double limit_card;
	double payment;
};
//==========================================================================================================================
class Saving_account :public account{
public:
	Saving_account();
	bool make_account(double n);
	bool withard(double n) override;
	void put_in_file(Client obj, int Id) override;
	void add_interest();
protected:
	double interest_rate;
	double monthly;
};
//==========================================================================================================================
 class loan :public account{
public:
	loan();
	bool make_loan(double n);
	bool pay_part(double n);
	void put_in_file(Client obj, int Id)override;

public:
	double duration_monthly;
	double interest;
};


//==========================================================================================================================

