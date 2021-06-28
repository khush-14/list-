#include<vector>
#include<iostream>
#include<iterator>
using namespace std;


class entity{
	string name;
	int pages;
	
	public:
		void create(string nam){
			name=nam;
			cout<<"\t\tEnter the number of pages";
			cin>>pages;
		}
		string returnName(){
			return name;
		}
		void display(){
			cout<<"\t\t"<<name<<" \t";
			cout<<pages<<endl;
		}
};

int checkForNam(vector<entity> vec,string str )
{
	vector<entity>:: iterator it;
	int count=0;
	for(it=vec.begin(); it!=vec.end(); it++){
		int com=str.compare(vec[count].returnName());
		if(com==0)
		{
			return count;
			break;
		}
		count++;
	} 
	return -1;
}
class material{
	string name;
	vector<entity> mat;
	
	public:
		material(string nam)
		{
			name=nam;
		}
		string returnName(){
			return name;
		}
		void addEntity(){
			char EntityName[25];
			cout<<"\t\tEnter the new entity name in material "<<name<<" : ";
			cin>>EntityName;
			int check=checkForNam(mat,EntityName);
			if(check!=-1)
			cout<<"Already present";
			else
			{
				entity obj;
				obj.create(EntityName);
				mat.push_back(obj);
				cout<<"\t\tADDED";
			}
		}
		void display()
		{
			cout<<name<<endl;
		}
		void displayEntity(){
			string EntityName;
			cout<<"\t\tEnter the name of Entit for display: ";
			cin>>EntityName;
			int check=checkForNam(mat,EntityName);
			if(check==-1)
			cout<<"Not present Such Entity in material";
			else
			{
				mat[check].display();
			}
		}
		void displayFullEntity(){
			cout<<"\t\t"<<name<<endl;
			cout<<"\t\tName \t\t  Pages"<<endl;
			for(int i=0; i<mat.size(); i++)
			{
				mat[i].display();
				
			}
		}
};

int checkForName(vector<material> vec,string str )
{
	vector<material>:: iterator it;
	int count=0;
	for(it=vec.begin(); it!=vec.end(); it++){
		
		int com=str.compare(vec[count].returnName());
		if(com==0)
		{
			return count;
			break;
		}
		count++;
	} 
	return -1;
}
int main()
{
    vector<material> vec;
 	int choice;
 	cout<<"1.create new material\n2.create new entity in material\n3. display entity in material\n4.Display all material name\n";
	 cout<<"5.display all entity of given material\n6.end"<<endl;
 	cin>>choice;
 	while(choice!=6)
 	{
 		if(choice==1)
 		{
 			system("cls");
 			string name;
 			cout<<"\t\tEnter the name of material: ";
 			cin>>name;
 			int check=checkForName(vec,name);
 			if(check!=-1)
 			cout<<"\t\tALready present: ";
 			else{
 				material obj(name);
 				vec.push_back(obj);
 				cout<<"\t\tAdded";
			}
		}
		if(choice==2)
		{
			system("cls");
			string name;
			cout<<"\n\t\tEnter Name of material: ";
			cin>>name;
			int check=checkForName(vec,name);
			if(check==-1)
			cout<<"\n\t\tNot present material: ";
			
			else{
				vec[check].addEntity();
			}
		}
		if(choice==3)
		{
			system("cls");
			string name;
			cout<<"\n\t\tEnter the name of material: ";
			cin>>name;
			int check=checkForName(vec,name);
			if(check==-1)
			cout<<"\n\t\tNot present such material: ";
			else
			vec[check].displayEntity();
		}
		if(choice==5){
			
			system("cls");
			string name;
			cout<<"\n\t\tEnter the name of material: ";
			cin>>name;
			int check=checkForName(vec,name);
			if(check==-1)
			cout<<"\n\t\tNot present such material: ";
			else{
				vec[check].displayFullEntity();
			}
		}
		if(choice==4)
		{
			
			system("cls");
			for(int i=0; i<vec.size(); i++)
			vec[i].display();
		}
		cout<<endl<<endl; 
 	    cout<<"1.create new material\n2.create new entity in material\n3. display entity in material\n4.display all material name\n";
		cout<<"5.display all entity of given material\n6.end"<<endl;
		cin>>choice;
		system("cls");
	}
}
