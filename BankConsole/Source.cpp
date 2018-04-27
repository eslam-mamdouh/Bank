#include <iostream>
#include <string>
#include "accounts.h"
#include <fstream>
#include <istream>
#include <ostream>
using namespace std;
int main(){
	int choice;
	cout << "\t\t\t*************************************************\n" << "\t\t\t\t     Bank Management System \n" << "\t\t\t*************************************************\n\n";
	cout << "\t\t\t\t1-) Create An Account.\n";
	cout << "\t\t\t\t2-) Login To Your Account.\n";
	cout << "\t\t\t\t3-) Transactions.\n";
	cout << "\t\t\t\t4-) Exit\n\n\n";
	cout << "Enter Your Choice  ( 1 - 4 ): "; cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  int ch, id = rand() % 10000;
			  cout << "\n\n\n\t\t\t\t1-) Checking Account.\n\n";
			  cout << "\t\t\t\t2-) Saving Account.\n\n";
			  cout << "\t\t\t\t3-) Make a Loan .\n\n";
			  cout << "Enter Your Choice ( 1 - 3 ) : "; cin >> ch;
			  switch (ch)
			  {	
			  case 1:
			  {			
						Client customer;
						Checking_account checking_acc;
						customer.set_data("Checking", id); // Account Type w  Id  
						customer.put_in_file(customer);  
						checking_acc.put_in_file(customer, id);
						break;
			  }
			  case 2:
			  {
						Client customer;
						Saving_account saving_acc;
						customer.set_data("Saving",id);   // Account Type w  Id  
						customer.put_in_file(customer);
						saving_acc.put_in_file(customer, id);
						break;
			  }
			  case 3:
			  {
						Client customer;
						loan loan_acc;
						customer.set_data("Loan", id);
						customer.put_in_file(customer);
						loan_acc.put_in_file(customer, id);
						break;
					 
			  }
			  default:
				  break;
			  }



		break;
	}
	case 2:
	{
			      

			   break;
	}
	case 3:
	{
			  cout << 3 << endl;
			  break;
	}

	default:
		return 0;
		break;
	}





	return 0;
}