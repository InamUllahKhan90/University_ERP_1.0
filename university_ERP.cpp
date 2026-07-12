#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
class University{
	private:
		string RollNo,Name,Subject,Address;
	public:
	 void setRollNo(string rollNo){
	 	RollNo=rollNo;
	 }
	 void setName(string name){
	 	Name=name;
	 }
	 void setSubject(string subject){
	 	Subject=subject;
	 }
	 void setAddress(string address){
	 	Address=address;
	 }
	 string getRollNo(){
	 	return RollNo;
	 }
	 string getName(){
	 	return Name;
	 }
	 string getSubject(){
	 	return Subject;
	 }
	 string getAddress(){
	 	return Address;
	 }
};
void inputData(University student){
	string rollNo,name,subject,address;
	cout<<"\t---Add Student Info---\n\n";
	
	cout<<"\tEnter RollNo:";
	cin>>rollNo;
	student.setRollNo(rollNo);
	cin.ignore();
	cout<<"\tEnter Name:";
	getline(cin,name);
	student.setName(name);
	
	cout<<"\tEnter Subject:";
	getline(cin,subject);
	student.setSubject(subject);
	
	cout<<"\tEnter Address:";
	getline(cin,address);
	student.setAddress(address);
	
	ofstream out("student.txt",ios::app);
	out<<"\t"<<student.getRollNo()<<" : "<<student.getName()<<" : "
	<<student.getSubject()<<" : "<<student.getAddress()<<endl<<endl;
	cout<<"\tStudent Added Successfully!"<<endl<<endl;
}

void searchStudent(){
	ifstream in("student.txt");
	cout<<"\t---Search / Display Data---\n\n";
	string rollNo;
	char option;
	bool found=false;
	cout<<"\tD:For display All\n\tS:For Search\n";
	cout<<"\t-------------\n";
	cout<<"\tEnter any choice:";
	cin>>option;
	if(option=='D' || option=='d'){
		string line;
		while(getline(in,line)){
			cout<<"\t"<<line<<endl;
			found=true;
		}
	cout<<"\t\t--------------------------------\n\n";
	}else if(option=='S' || option=='s'){
		cout<<"\tEnter Student RollNo:";
		cin>>rollNo;
		cout<<"\t\t--------------------------------\n\n";
		string line;
		while(getline(in,line)){
			int pos=line.find(rollNo);
			if(pos!=string::npos){
				cout<<"\t"<<line<<endl;
				found=true;
			}
		}
	}
	if(!found){
		cout<<"\tError:File Can't Open\n"<<endl;
	in.close();
}
}

void updateStudent(University student){
	cout<<"\t\t---Update Section---\n\n";
	ofstream outfile("student temp.txt");
	ifstream infile("student.txt");
	
	string rollNo;
	cout<<"\tEnter Student RollNo:";
	cin>>rollNo;
	cout<<"\t\t--------------------------------\n\n";
	if(!infile || !outfile){
		cout<<"\tError:File can't Open\n";
	}
	string line;
	bool found=false;
	while(getline(infile,line)){
		int pos=line.find(rollNo);
		if(pos!=string::npos){
			cin.ignore();
			string address;
			cout<<"\tEnter New Address:";
			getline(cin,address);
			student.setAddress(address);
		int newPos=line.find_last_of(':');
		line.replace(newPos+2,string::npos,student.getAddress());
		}
		outfile<<line<<endl;
		found=true;
	}
	if(!found){
		cout<<"\tStudent Not found!"<<endl;
	}
	outfile.close();
	infile.close();
	remove("student.txt");
	rename("student temp.txt","student.txt");
	cout<<"\tStudent Data Updated!"<<endl;
	
}
int main(){
  cout<<"\t\t****------------------------****\n\n";
  cout<<"\t\t   STUDENT MANAGEMENT SYSTEM\n\n";
  cout<<"\t\t****------------------------****\n\n";
	University student;
	bool istrue=true;
	while(istrue){
		int choice;
	 cout<<"\t\t 1:Add Student\n";
     cout<<"\t\t 2:Search Student\n";
     cout<<"\t\t 3:Edit Student\n";
     cout<<"\t\t 4:Exit\n";
     cout<<"\t\t--------------------------------\n\n";
     cout<<"\t\tEnter Your Choice:";
     cin>>choice;
      if(cin.fail()){
      	cin.clear();
      	cin.ignore();
      	system("cls");
      	cout<<"\tEnter Digit Not Chracters."<<endl<<endl;
      	continue;
	  }
     	if(choice==1){
     	 system("cls");
     	 inputData(student);
     	 Sleep(3000);
	   }else if(choice==2){
	   	system("cls");
	   	searchStudent();
	   	Sleep(3000);
	   }else if(choice==3){
	   	system("cls");
	   	updateStudent(student);
	   	Sleep(3000);   
	   }else if(choice==4){
	   	system("cls");
	   	cout<<"\tThank You, You are going to Exit."<<endl;
	   	istrue=false;
	   	Sleep(3000);
	   }else{
	   		cout<<"\tYou Entered Invalid choice,Try again."<<endl<<endl;
	   }
 }
return 0
}
