#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class bank_account{
	int account_no;
	char name[25];
	char type;
	int amt;
	public:
		int get_account_no();
		void new_account();
		void deposit_amt();
		void withdraw_amt();
		void balance_inquiry();
		void account_details();
		void modify_account();
		
};

int bank_account::get_account_no(){
	return this->account_no;
}

void bank_account::new_account(){
	system("cls");
	cout<<"\n\tAccount holder number: ";
	cin>>this->account_no;
	cout<<"\tName: ";
	cin>>this->name;
	cout<<"\tAccount Type(c/s): ";
	cin>>this->type;
	cout<<"\tIntial amount(500-S)/(1000-C)";
	cin>>this->amt;
	cout<<"\t\tACCOUNT CREATED";
}

void bank_account::deposit_amt(){
	cout<<"\n\tAccount holder name:"<<name;
	cout<<"\n\tAccountholder type:"<<type<<endl;
	cout<<"\tEnter amount for Deposition: ";
	int dep_amt;
	cin>>dep_amt;
	amt+=dep_amt;
}

void bank_account::withdraw_amt(){
	
	cout<<"\n\tAccount holder name:"<<name;
	cout<<"\n\tAccountholder type:"<<type;
	int with_amt;
	cout<<"\n\tEnter the Withdraw amount: ";
	cin>>with_amt;
	if(amt<with_amt+500)
	cout<<"\tSORRY YOUR BALANCE IS NOT SUFFICIENT";
	else{
		amt-=with_amt;
	}
}

void bank_account::balance_inquiry(){
	
	cout<<"\n\tAccount holder name:"<<name<<endl;
	cout<<"\tAccountholder type:"<<type<<endl;
	cout<<"\tYOUR CURRENT BALANCE IS: "<<amt<<endl;
	cout<<"\tTHANKS FOR ENQUIRY......"<<endl;
}

void bank_account::account_details(){
	cout<<"\t"<<name<<"\t\t"<<this->account_no<<"\t\t"<<this->type<<"\t"<<this->amt<<endl;
}

void bank_account::modify_account(){
	cout<<"\n\tNAME: ";
	cin>>name;
	cout<<"\n\tTYPE: ";
	cin>>type;
	int add_amt;
	cout<<"\n\tENTER ADDITIONAL AMOUNT: ";
	cin>>add_amt;
	amt+=add_amt;
}

int menu(){
	int choice;
	system("cls");
	cout<<"\n\tMAIN MENU\n";
	cout<<"\t01. NEW ACCOUNT\n";
	cout<<"\t02. DEPOSIT AMOUNT\n";
	cout<<"\t03. WITHDAW AMOIUNT\n";
	cout<<"\t04. BALANCE INQUIRY\n";
	cout<<"\t05. ALL ACCOUNT DETAILS\n";
	cout<<"\t06. CLOSE AN ACCOUNT\n";
	cout<<"\t07. MODIFY AN ACCOUNT\n";
	cout<<"\t08. EXIT\n";
	cout<<"\tSELECT OPTION: ";
	cin>>choice;
	return choice;
}
void select_quiry(int choice,vector<bank_account> s){
	switch(choice)
	{
		case 1:{
			bank_account obj;
			obj.new_account();
			s.push_back(obj);
			break;
		}
		case 2:{
			int no,count=0;
			
			system("cls");
			cout<<"\tEnter Account Number: ";
			cin>>no;
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				if(s[count-1].get_account_no()==no)
				break;
			}
			if(it==s.end())
			cout<<"\t\tNO SUCH ACCOUNT EXIST";
			else
			s[count-1].deposit_amt();
			break;
		}
		case 3:{
			int no,count=0;
			
			system("cls");
			cout<<"\tEnter Account Number: ";
			cin>>no;
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				if(s[count-1].get_account_no()==no)
				break;
			}
			if(it==s.end())
			cout<<"\t\tNO SUCH ACCOUNT EXIST";
			else
			s[count-1].withdraw_amt();		
			break;
		}
		case 4:{
			int no,count=0;
			system("cls");
			cout<<"\tEnter Account Number: ";
			cin>>no;
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				if(s[count-1].get_account_no()==no)
				break;
			}
			if(it==s.end())
			cout<<"\t\tNO SUCH ACCOUNT EXIST";
			else
			s[count-1].balance_inquiry();
			break;
		}
		case 5:{
			int count=0;
			cout<<endl;
			cout<<"\t-------------------------------------------\n";
			cout<<"\tNAME |    \tACCOUNT NUMBER | TYPE | BALANCE \n";
			cout<<"\t-------------------------------------------\n";
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				s[count-1].account_details();
			}
			break;
		}
		case 6:{			
		    int no,count=0;
			system("cls");
			cout<<"\tEnter Account Number: ";
			cin>>no;
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				if(s[count-1].get_account_no()==no)
				break;
			}
			if(it==s.end())
			cout<<"\t\tNO SUCH ACCOUNT EXIST";
			else
			s.erase(it);
			break;
		}
		case 7:{
		    int no,count=0;
			system("cls");
			cout<<"\tEnter Account Number: ";
			cin>>no;
			vector<bank_account>::iterator it;
			for(it=s.begin(); it!=s.end(); it++)
			{
				count++;
				if(s[count-1].get_account_no()==no)
				break;
			}
			if(it==s.end())
			cout<<"\t\tNO SUCH ACCOUNT EXIST";
			else
			s[count-1].modify_account();
			break;
		}
	}
	int value;
	cout<<"\n\t1.MAIN MENU\n2.EXIT\n";
	cout<<"\tEnter the choice: ";
	cin>>value;
	if(value==1)
	{
		int option=menu();
		select_quiry(option,s);
	}
	else
	return ;
	
}

int main(){
	vector<bank_account> s;
	int value=menu();
	select_quiry(value,s);
}
