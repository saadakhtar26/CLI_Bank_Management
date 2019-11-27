/*
	Name: Bank Management System
	Copyright: GNU General Public Liscence v3.0
	Author: Saad Rajpoot
	Date: 14/06/19 05:35
	Description: C++ code for Bank Management System Program.
	
	Features:
	
		1.  Open New Account
		2.  Deposit Money
		3.  Withdraw Money
		4.  Display Info
		5.  Transfer Money
		6.  Client Information
		7.  Total Money in Bank
		8.  Bill Payment
		9.  Clear Screen
		10. Return Exit to DOS
*/


#include<iostream>
#include<fstream>
using namespace std;

struct accounts{
	string name;
	int pin;
	int balance;
};
accounts ac[50];

fstream file;

class bank{
	public:
		int pin,balance;
		string name;
		void open(){
			system("cls");
			file.open("bank.txt",ios::app);
			cout<<"Enter name : ";
			cin>>name;
			cout<<"Enter pin : ";
			cin>>pin;
			cout<<"opening balance : ";
			cin>>balance;
			file<<name<<" "<<pin<<" "<<balance<<"\n";
			cout<<"account open successfully :";
			file.close();
		}
		void deposit(){
			system("cls");
			int i=0,dep=0,j=0;
			string nm;
			file.open("bank.txt",ios::in);
			cout<<"Enter the name :"<<endl;
			cin>>nm;
			cout<<"Enter Deposit New Money :"<<endl;
			cin>>dep;
			while(file>>ac[i].name>>ac[i].pin>>ac[i].balance){
				if(nm==ac[i].name){
					ac[i].balance+=dep;
				}
				i++;
			}
			file.close();
			file.open("bank.txt",ios::out);
			while(j<i){
				file<<ac[j].name<<" "<<ac[j].pin<<" "<<ac[j].balance<<"\n";
				j++;
			}
			file.close();
			cout<<"successfully deposit amount !!"<<endl;
		}
		void withdraw(){
			system("cls");
			int i=0,with=0,j=0;
			string nm;
			file.open("bank.txt",ios::in);
			cout<<"Enter the name :"<<endl;
			cin>>nm;
			cout<<"Enter withdraw money :"<<endl;
			cin>>with;
			while(file>>ac[i].name>>ac[i].pin>>ac[i].balance){
				if(nm==ac[i].name){
					ac[i].balance-=with;
				}
				i++;
			}
			file.close();
			file.open("bank.txt",ios::out);
			while(j<i){
				file<<ac[j].name<<" "<<ac[j].pin<<" "<<ac[j].balance<<"\n";
				j++;
			}
			file.close();
			cout<<"successfully withdraw amount !!"<<endl;
		}
		void display(){
			file.open("bank.txt",ios::in);
			while(file>>name>>pin>>balance){
				cout<<"Name: "<<name<<endl;
				cout<<"Pin: "<<pin<<endl;
				cout<<"Balance: "<<balance<<"\n"<<endl;
			}
			file.close();
		}
		void transfer(){
			system("cls");
			int i=0,trans=0,j=0;
			string nm,rec;
			file.open("bank.txt",ios::in);
			cout<<"Enter the name user name :"<<endl;
			cin>>nm;
			cout<<"Enter transfer money :"<<endl;
			cin>>trans;
			cout<<"Enter the  receiver name :"<<endl;
			cin>>rec;
			while(file>>ac[i].name>>ac[i].pin>>ac[i].balance){
				if(nm==ac[i].name){
					ac[i].balance-=trans;
					}
				if(ac[i].name==rec){
						ac[i].balance+=trans;
					}
				i++;
			}
			file.close();
			file.open("bank.txt",ios::out);
			while(j<i){
				file<<ac[j].name<<" "<<ac[j].pin<<" "<<ac[j].balance<<"\n";
				j++;
			}
			file.close();
			cout<<"successfully transfer  amount !!"<<endl;
		}
		void info(){
			system("cls");
			int i=0;
			string nm;
			file.open("bank.txt",ios::in);
			cout<<"Enter the name :"<<endl;
			cin>>nm;
			while(file>>ac[i].name>>ac[i].pin>>ac[i].balance){
				if(nm==ac[i].name){
					cout<<"Name: "<<ac[i].name<<endl;
					cout<<"Pin: "<<ac[i].pin<<endl;
					cout<<"Balance: "<<ac[i].balance<<"\n"<<endl;
				}
				i++;
			}
			file.close();
		}
		void total(){
			system("cls");
			int total=0;
			file.open("bank.txt",ios::in);
			while(file>>name>>pin>>balance){
				total+=balance;
			}
			cout<<"Total Balance: "<<total<<"\n"<<endl;
			file.close();
		}
		void bill(){
			system("cls");
			int i=0,bill=0,j=0;
			string nm;
			file.open("bank.txt",ios::in);
			cout<<"Enter the name :"<<endl;
			cin>>nm;
			cout<<"Enter bill money :"<<endl;
			cin>>bill;
			while(file>>ac[i].name>>ac[i].pin>>ac[i].balance){
				if(nm==ac[i].name){
					ac[i].balance-=bill;
				}
				i++;
			}
			file.close();
			file.open("bank.txt",ios::out);
			while(j<i){
				file<<ac[j].name<<" "<<ac[j].pin<<" "<<ac[j].balance<<"\n";
				j++;
			}
			file.close();
			cout<<"successfully bill paid !!"<<endl;
		}
	
};

int main(){
	bank obj;
	int op;
	cout<<"1.open account"<<endl;
	cout<<"2.deposit money"<<endl;
	cout<<"3.withdraw money"<<endl;
	cout<<"4.display Info"<<endl;
	cout<<"5.transfer money"<<endl;
	cout<<"6.client information"<<endl;
	cout<<"7.total money in bank"<<endl;
	cout<<"8.bill payment"<<endl;
	cout<<"9.Clear Screen"<<endl;
	cout<<"10.exit"<<endl;
	cin>>op;
	
	if(op==1){
		obj.open();
		main();
	}
	else if(op==2){
		obj.deposit();
		main();
	}
	else if(op==3){
		obj.withdraw();
		main();
	}
	else if(op==4){
		obj.display();
		main();
	}
	else if(op==5){
		obj.transfer();
		main();
	}
	else if(op==6){
		obj.info();
		main();
	}
	else if(op==7){
		obj.total();
		main();
	}
	else if(op==8){
		obj.bill();
		main();
	}
	else if(op==9){
		system("cls");
		main();
	}
	else if(op==10){
		system("exit");
	}
	else{
		system("cls");
		cout<<"wrong option selected\n\n";
		main();
	}
	
	return 0;
}
