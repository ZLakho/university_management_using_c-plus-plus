#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<cstdio>

//#include<graphics.h>
using namespace std;


int n;
int main();



class Student{
	string name,father_name,dept,course,address,dob,domicile;
	//string Computing_fundamental,Functional_English,Applied_Physics,Pakistan_Studies,Calculus_and_Analytical_Geometry;
	string subj_1,subj_2,subj_3,subj_4,subj_5;
	string t_marks1,t_marks2,t_marks3,t_marks4,t_marks5;
	string o_marks1,o_marks2,o_marks3,o_marks4,o_marks5;
	string roll_no,cont_no,yoa;
	int n;
	public:
		void menu();
		void insert();
		void Student_details();
		void personal_info();
		void display_personal_info();
		void academic_details();
		void edit();
		void first_semester();
		void display_f_sem();
		void view();
		void search();
		void deleted();
		void modify();

};

void Student::menu()
{
	int ch;
	system("cls");
	cout<<"\t\t\t-----------------------------"<<endl;
	cout<<"\t\t\t| STUDENT MANAGEMENT SYSTEM |"<<endl;
	cout<<"\t\t\t-----------------------------"<<endl;
	cout<<"\t\t\t 1. Insert a new entry "<<endl;
	cout<<"\t\t\t 2. Find and edit the saved entries "<< endl;
	cout<<"\t\t\t 3.Exit "<<endl;
	
	
	cout<<"\t\t\t-----------------------------"<<endl;
	cout<<"\t\t\t Choose option 1-3:"<<endl;
	cout<<"\t\t\t-----------------------------"<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
			system("cls");
			edit();
		case 3:
			exit(0);
		default:
			cout<<"Invalid Choice.... "<<endl;
			
	}
}

void Student::insert()
{
	insert_strt:
	int choice;
	system("cls");
	cout<<"\t\t\t Insert a new entry "<<endl;
	cout<<"\t\t\t1. Student Details "<<endl;
	cout<<"\t\t\t2. Exit "<<endl;
	cin>>choice;
	switch(choice)
	{
		char t;
		case 1:
			do{
				Student_details();
				cout<<"Do you want to insert another entry(Y,N)? "<<endl;
				cin>>t;
			}while(t=='Y' || t=='y');
		    break;
		case 2:
			main();
			break;
		default:
			cout<<"Invalid choice.... "<<endl;
			
			
	}
	goto insert_strt;
	
}

void Student::Student_details()
{
	student_start:
	system("cls");
	int ch;
	cout<<"\t\t\tStudent Details "<<endl;
	cout<<"\t\t\t1. Personal Details "<<endl;
	cout<<"\t\t\t2. Academic Details "<<endl;
	cout<<"Enter choice: "<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			
			personal_info();
		break;
		case 2:
			
			academic_details();
		break;
		default:
		cout<<"error"<<endl;	
	}
	goto student_start;
}
 void Student::personal_info()
 {
 	
 		system("cls");
 		int ch2;
 		
 		
	cout<<"\t\t\tPersonal Details "<<endl;
	
	
	cout<<"How many students data you want to enter? "<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cout<<"Student "<<i<<endl;
	fstream file;
	system("cls");
	cin.get();
	cout<<"\t\t\tPersonal Details "<<endl;
	cout<<"Name: "<<endl;
	getline(cin,name);
	cout<<"Father name: "<<endl;
	cin>>father_name;
	cout<<"Roll no: "<<endl;
	cin>>roll_no;
	cout<<"Contact no: "<<endl;
	cin>>cont_no;
	cout<<"Date of Birth: "<<endl;
	cin>>dob;
	cout<<"Domicile: "<<endl;
	cin>>domicile;
	cout<<"Year of Admission: "<<endl;
	cin>>yoa;
	cout<<"Department: "<<endl;
	cin>>dept;
	file.open("Personalinfo.txt",ios::app | ios::out); //writing in file
	file<< roll_no <<" "<< name <<" "<< father_name <<" "<<cont_no<< " "<< dob << " " <<domicile << " "<< yoa << " "<<dept <<" "<<endl;
	file.close();
}
	
	
	system("cls");
	//display_personal_info();
	
	cout<<endl<<endl<<endl;
	cout<<"Enter Academic Details "<<endl;
	cout<<"Enter 1 for yes And 2 for no"<<endl;
	cin>>ch2;
	if(ch2==1)
	{
		
		academic_details();
		
	}
	else
	{
	main();	
	}

	}	
 
 
 void Student::display_personal_info()
{
	system("cls");
	cout<<"Personal Information\n\n";
	int i=0;
	
//	for( i=0;i<=n;i++){
			fstream file, marks;
	
	system("cls");
	//cout<<"/t/t/tStudent's Personal Info "<<endl;
	file.open("Personalinfo.txt",ios::in);
	marks.open("Marks.txt", ios::in);
	if(!marks)
	{		
	cout<<"No academic data present"<<endl;
	marks.close();
	}
	if(!file)
	{
		cout<<"/t/t/tNo Personal data of student is present. "<<endl;
		file.close();
	}
		string rollno;
		file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
		while(!file.eof()) 
		{	
			if(file.eof())
			{
				file.close();
				break;
			}	
			cout<<"\t\t\tStudent's Personal Info "<<endl;
			cout<<"Student No: "<<++i<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Father Name: "<<father_name<<endl;
			cout<<"Roll No: "<<roll_no<<endl;
			cout<<"Contact No: "<<cont_no<<endl;
			cout<<"Date of birth: "<<dob<<endl;
			cout<<"Domicile: "<<domicile<<endl;
			cout<<"Year of Admission: "<<yoa<<endl;
			cout<<"Department: "<<dept<<endl;
			cout<<"===============================================\n\n\n";
		//	cout<<roll_no;
		//	system("pause");
	//	marks.open("Marks.txt", ios::in);		
			marks.seekg(0, ios::beg);
		//	marks>>rollno;

			while(!marks.eof())
			{
			marks>>rollno;	
			marks>>subj_1>>t_marks1>>o_marks1;
			marks>>subj_2>>t_marks2>>o_marks2;
			marks>>subj_3>>t_marks3>>o_marks3;
			marks>>subj_4>>t_marks4>>o_marks4;
			marks>>subj_5>>t_marks5>>o_marks5;
			if(rollno==roll_no) 
			{	
			//marks>>rollno;	
			//	while(!file.eof()) 
			//	{
		//	marks>>subj_1>>t_marks1>>o_marks1;
		//	marks>>subj_2>>t_marks2>>o_marks2;
		//	marks>>subj_3>>t_marks3>>o_marks3;
		//	marks>>subj_4>>t_marks4>>o_marks4;
		//	marks>>subj_5>>t_marks5>>o_marks5;
			
			cout<<"Academic Details"<<endl;
			cout<<"Subject\t\t\tTotal Marks\t\t\tObtained Marks "<<endl;
			cout<<subj_1<<"\t\t\t"<<t_marks1<<"\t\t\t"<<o_marks1<<endl;
			cout<<subj_2<<"\t\t\t"<<t_marks2<<"\t\t\t"<<o_marks2<<endl;
			cout<<subj_3<<"\t\t\t"<<t_marks3<<"\t\t\t"<<o_marks3<<endl;
			cout<<subj_4<<"\t\t\t"<<t_marks4<<"\t\t\t"<<o_marks4<<endl;
			cout<<subj_5<<"\t\t\t"<<t_marks5<<"\t\t\t"<<o_marks5<<endl;
			cout<<"======================================================================"<<endl;
			system("pause");
			break;
				
			}
			if(marks.eof())
			{
				cout<<"Student Academic Data not found"<<endl;
				cout<<"===============================================\n\n\n";
			//	cout<<"\nEnd of marks file "<<endl;
				system("pause");
				break;
			}
		//	if(rollno!=roll_no)
		//	{
		//		cout<<"Student Academic Data not found"<<endl;
		//		cout<<"===============================================\n\n\n";
		//		system("pause");
		//		break;
		//	}
//		}
		//	file >> name >> father_name >> roll_no >> cont_no >> dob >> domicile >> yoa >> dept;

	}
			//marks.close();
//	if(i==0)
//	{
//		cout<<"No Data IS present."<<endl;
//	}
			file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
	}

	file.close();
	marks.close();
	system("pause");
	
	main();

		}

void Student::academic_details()
{
	system("cls");
	int c;
	cout<<"\t\t\tAcademic Details "<<endl;
	cout<<"\t\t\t1. Ist Semester "<<endl;
	cout<<"\t\t\t2. 2nd Semester "<<endl;
	cout<<"\t\t\t3. 3rd Semester "<<endl;
	cout<<"\t\t\t4. 4th Semester "<<endl;
	cout<<"\t\t\t5. 5th Semester "<<endl;
	cout<<"\t\t\t6. 6th Semester "<<endl;
	cout<<"\t\t\t7. 7th Semester "<<endl;
	cout<<"\t\t\t8. 8th Semester "<<endl;
	cout<<"\t\t\t9. Back "<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			first_semester();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			cout<<"Invalid choice.. "<<endl;
	}
}

void Student::first_semester()
{
	system("cls");
	fstream file;
	int i;
//	for(  i=1;i<=n;i++)
//	{
	cout<<"Enter roll no: "<<endl;
	cin>>roll_no;
	cout<<"Enter subj1,total1,obt1: "<<endl;
	cin>>subj_1>>t_marks1>>o_marks1;
	cout<<"Enter subj2,total2,obt2: "<<endl;
	cin>>subj_2>>t_marks2>>o_marks2;
	cout<<"Enter subj3,total3,obt3: "<<endl;
	cin>>subj_3>>t_marks3>>o_marks3;
	cout<<"Enter subj4,total4,obt4: "<<endl;
	cin>>subj_4>>t_marks4>>o_marks4;
	cout<<"Enter subj5,total5,obt5: "<<endl;
	cin>>subj_5>>t_marks5>>o_marks5;
	file.open("Marks.txt",ios::app | ios::out); //writing in file
	file<<roll_no<<" ";
	file<<subj_1<<" "<<t_marks1<<" "<<o_marks1<<" ";
	file<<subj_2<<" "<<t_marks2<<" "<<o_marks2<<" ";
	file<<subj_3<<" "<<t_marks3<<" "<<o_marks3<<" ";
	file<<subj_4<<" "<<t_marks4<<" "<<o_marks4<<" ";
	file<<subj_5<<" "<<t_marks5<<" "<<o_marks5<<endl;
	file.close();

    system("cls");
//	display_f_sem();
main();	
	
}

void Student::display_f_sem()
{
	system("cls");
	fstream file;
	int i;
//	delay(120);
	cout<<"\t\t\tIST SEMESTER "<<endl;
	//	for(  i=1;i<=n;i++)
	//	{
		
		
	file.open("Marks.txt",ios::in);
	if(!file)
	{
		cout<<"/t/t/tNo Data is present. "<<endl;
		file.close();
	}
	else
	{
	file>>roll_no;
	file>>subj_1>>t_marks1>>o_marks1;
	file>>subj_2>>t_marks2>>o_marks2;
	file>>subj_3>>t_marks3>>o_marks3;
	file>>subj_4>>t_marks4>>o_marks4;
	file>>subj_5>>t_marks5>>o_marks5;
	//	while(!file.eof()) 
	//	{
	cout<<"Academic Details"<<i<<endl;
	cout<<"Subject\t\t\tTotal Marks\t\t\ttObtained Marks "<<endl;
	cout<<subj_1<<"\t\t\t"<<t_marks1<<"\t\t\t"<<o_marks1<<endl;
	cout<<subj_2<<"\t\t\t"<<t_marks2<<"\t\t\t"<<o_marks2<<endl;
	cout<<subj_3<<"\t\t\t"<<t_marks3<<"\t\t\t"<<o_marks3<<endl;
	cout<<subj_4<<"\t\t\t"<<t_marks4<<"\t\t\t"<<o_marks4<<endl;
	cout<<subj_5<<"\t\t\t"<<t_marks5<<"\t\t\t"<<o_marks5<<endl;
	cout<<"======================================================================"<<endl;
	
	
	
	// 0-========
}
file.close();

}
	

	

void Student::edit()
{
	system("cls");
	int ch1;
	cout<<"EDIT RECORD "<<endl;
	cout<<"1. View Record "<<endl;
	cout<<"2.Modify Record "<<endl;
	cout<<"3.Search Record "<<endl;
	cout<<"4.Delete Record"<<endl;
	cout<<"5. Return to main menu "<<endl;
	cout<<"===>"<<endl;
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			view();
			break;
		case 2:
			modify();
			break;
		case 3:
			search();
			break;
		case 4:
			deleted();
			break;
		default:
			cout<<"SHUTUP "<<endl;
	}

	
}

void Student:: view()
{
	system("cls");
	display_personal_info();
//	display_f_sem();
}

void Student::modify()
{
	system("cls");
		fstream file,marks;
		string rollno,n;
	file.open("Personalinfo.txt",ios::in);
	marks.open("Marks.txt",ios::in);
	if(!file)
	{
		cout<<"---------------Search Student Data------------------"<<endl;
		cout<<" No Data Is present...."<<endl;
	}
	if (!marks)
	{
		cout<<"\n\t\t\t No Academic data present";
	}
	else
	{
		cout<<"----------------------Modify Student Data-----------------------"<<endl;
		cout<<"\n Enter Roll No: of student you want to modify?"<<endl;
		cin>>rollno;
		cin.get();
		n=rollno;
		while(!file.eof())
		{	
		file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
			if(file.eof())
			{
				cout<<"Personal Details Not Found"<<endl;
				cout<<"===============================================\n\n\n";
				break;
			}
			if(roll_no==n)
			{	
				
				cout<<"Name: "<<name<<endl;
			    cout<<"Father Name: "<<father_name<<endl;
			    cout<<"Roll No: "<<roll_no<<endl;
			    cout<<"Contact No: "<<cont_no<<endl;
			    cout<<"Date of birth: "<<dob<<endl;
			    cout<<"Domicile: "<<domicile<<endl;
			    cout<<"Year of Admission: "<<yoa<<endl;
			    cout<<"Department: "<<dept<<endl;
			    cout<<"===============================================\n\n\n";
			//    system("pause");
				break;
			}
	
		}
		while(!marks.eof())
			{	
			marks>>roll_no;
			if(marks.eof())
			{
				cout<<"Student Academic Data not found"<<endl;
				cout<<"===============================================\n\n\n";
				break;
			}
			if(roll_no==rollno) 
			{	
			//marks>>rollno;	
			marks>>subj_1>>t_marks1>>o_marks1;
			marks>>subj_2>>t_marks2>>o_marks2;
			marks>>subj_3>>t_marks3>>o_marks3;
			marks>>subj_4>>t_marks4>>o_marks4;
			marks>>subj_5>>t_marks5>>o_marks5;
			//	while(!file.eof()) 
			//	{
			cout<<"Academic Details"<<endl;
			cout<<"Subject\t\t\tTotal Marks\t\t\tObtained Marks "<<endl;
			cout<<subj_1<<"\t\t\t"<<t_marks1<<"\t\t\t"<<o_marks1<<endl;
			cout<<subj_2<<"\t\t\t"<<t_marks2<<"\t\t\t"<<o_marks2<<endl;
			cout<<subj_3<<"\t\t\t"<<t_marks3<<"\t\t\t"<<o_marks3<<endl;
			cout<<subj_4<<"\t\t\t"<<t_marks4<<"\t\t\t"<<o_marks4<<endl;
			cout<<subj_5<<"\t\t\t"<<t_marks5<<"\t\t\t"<<o_marks5<<endl;
			cout<<"======================================================================"<<endl;
			system("pause");
			break;
			}
			}
	file.close();
	marks.close();
	}
	

	fstream temp1,temp2;
	int a;
	file.open("Personalinfo.txt",ios::in);
	marks.open("Marks.txt",ios::in);
	n=rollno;
	cout<<"--------------------------------- Student Modify Details ---------------------------------\n\n\n"<<endl;
	cout<<"Enter 1 to Modify Personal Details."<<endl;
	cout<<"Enter 2 to Modify Academic Details."<<endl;
	cout<<"Enter your Choice: ";
	cin>>a;
	switch(a)
	{
		case 1:
		temp1.open("Record.txt",ios::app | ios::out);
		file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
		while(!file.eof())
		{
			if(file.eof())
			{
				cout<<"======================================================================\n\n\n"<<endl;
				cout<<"\n\t\t\t No Student Personal Details For Given Roll Number ....."<<endl;
				cout<<"\n\n\n======================================================================"<<endl;
				break;
			}
			if(rollno!=roll_no)
			{
			   temp1<< roll_no <<" "<< name <<" "<< father_name <<" "<<cont_no<< " "<< dob << " " <<domicile << " "<< yoa << " "<<dept <<endl;	
			}
			if (rollno==roll_no)
			{	
				cout<<"Name: "<<endl;
	            cin>>name;
            	cout<<"Father name: "<<endl;
            	cin>>father_name;
            	cout<<"Roll no: "<<endl;
            	cin>>roll_no;
            	cout<<"Contact no: "<<endl;
            	cin>>cont_no;
            	cout<<"Date of Birth: "<<endl;
            	cin>>dob;
	            cout<<"Domicile: "<<endl;
	            cin>>domicile;
            	cout<<"Year of Admission: "<<endl;
             	cin>>yoa;
	            cout<<"Department: "<<endl;
              	cin>>dept;
              	temp1<< roll_no <<" "<< name <<" "<< father_name <<" "<<cont_no<< " "<< dob << " " <<domicile << " "<< yoa << " "<<dept <<endl;
			}
			file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
		system("pause");
		}
		temp1.close();
		file.close();
		remove("Personalinfo.txt");	
		rename("Record.txt","Personalinfo.txt");
		break;
	case 2:
	temp1.open("Temp.txt",ios::app | ios::out);
	do	
		{
		marks>>roll_no;
		marks>>subj_1>>t_marks1>>o_marks1;
		marks>>subj_2>>t_marks2>>o_marks2;
		marks>>subj_3>>t_marks3>>o_marks3;
		marks>>subj_4>>t_marks4>>o_marks4;
		marks>>subj_5>>t_marks5>>o_marks5;
			if(marks.eof())
			{
				cout<<"======================================================================\n\n\n"<<endl;
				cout<<"\n\t\t\t No Student Academic Details For Given Roll Number ....."<<endl;
				cout<<"\n\n\n======================================================================"<<endl;
				system("pause");
				system("pause");
				break;
			}
			if(rollno!=roll_no)
			{
			   	temp1<<roll_no;
				temp1<<" "<<subj_1<<" "<<t_marks1<< " "<<o_marks1;
				temp1<<" "<<subj_2<<" "<<t_marks2<<" "<<o_marks2;
				temp1<<" "<<subj_3<<" "<<t_marks3<<" "<<o_marks3;
				temp1<<" "<<subj_4<<" "<<t_marks4<<" "<<o_marks4;
				temp1<<" "<<subj_5<<" "<<t_marks5<<" "<<o_marks5<<endl;;
			}
			if (rollno==roll_no)
			{	
				cin.get();
				cout<<"Enter roll no: "<<endl;
				cin>>roll_no;
				cout<<"Enter subj1,total1,obt1: "<<endl;
				cin>>subj_1>>t_marks1>>o_marks1;
				cout<<"Enter subj2,total2,obt2: "<<endl;
				cin>>subj_2>>t_marks2>>o_marks2;
				cout<<"Enter subj3,total3,obt3: "<<endl;
				cin>>subj_3>>t_marks3>>o_marks3;
				cout<<"Enter subj4,total4,obt4: "<<endl;
				cin>>subj_4>>t_marks4>>o_marks4;
				cout<<"Enter subj5,total5,obt5: "<<endl;
				cin>>subj_5>>t_marks5>>o_marks5;
				temp1<<roll_no;
				temp1<<" "<<subj_1<<" "<<t_marks1<< " "<<o_marks1;
				temp1<<" "<<subj_2<<" "<<t_marks2<<" "<<o_marks2;
				temp1<<" "<<subj_3<<" "<<t_marks3<<" "<<o_marks3;
				temp1<<" "<<subj_4<<" "<<t_marks4<<" "<<o_marks4;
				temp1<<" "<<subj_5<<" "<<t_marks5<<" "<<o_marks5<<endl;
			}
		//	marks>>roll_no;
		//	marks>>subj_1>>t_marks1>>o_marks1;
		//	marks>>subj_2>>t_marks2>>o_marks2;
		//	marks>>subj_3>>t_marks3>>o_marks3;
		//	marks>>subj_4>>t_marks4>>o_marks4;
		//2	marks>>subj_5>>t_marks5>>o_marks5;
			system("pause");
		}while(!marks.eof());
		temp1.close();
		marks.close();
		remove("Marks.txt");	
		rename("Temp.txt","Marks.txt");
		break;
		
		default:
			cout<<"Invalid Choice ";
			system("pause");
			break;
	
	}
main();
}

void Student::search()
{
	system("cls");
	fstream file,marks;
	file.open("Personalinfo.txt",ios::in);
	marks.open("Marks.txt",ios::in);
	if(!file)
	{
		cout<<"---------------Search Student Data------------------"<<endl;
		cout<<" No Data Is present...."<<endl;
	}
	else
	{
		string rollno,n;
		cout<<"----------------------Search Student Data-----------------------"<<endl;
		cout<<"\n Enter Roll No: of student you want to search?"<<endl;
		cin>>rollno;
		cin.get();
		n=rollno;
		while(!file.eof())
		{	
		file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
			if(file.eof())
			{
				cout<<"Personal Details Not Found"<<endl;
				cout<<"===============================================\n\n\n";
				break;
			}
			if(roll_no==n)
			{	
				
				cout<<"Name: "<<name<<endl;
			    cout<<"Father Name: "<<father_name<<endl;
			    cout<<"Roll No: "<<roll_no<<endl;
			    cout<<"Contact No: "<<cont_no<<endl;
			    cout<<"Date of birth: "<<dob<<endl;
			    cout<<"Domicile: "<<domicile<<endl;
			    cout<<"Year of Admission: "<<yoa<<endl;
			    cout<<"Department: "<<dept<<endl;
			    cout<<"===============================================\n\n\n";
			//    system("pause");
				break;
			}
	
		}
		while(!marks.eof())
			{	
			marks>>roll_no;
			if(marks.eof())
			{
				cout<<"Student Academic Data not found"<<endl;
				cout<<"===============================================\n\n\n";
				break;
			}
			if(roll_no==rollno) 
			{	
			//marks>>rollno;	
			marks>>subj_1>>t_marks1>>o_marks1;
			marks>>subj_2>>t_marks2>>o_marks2;
			marks>>subj_3>>t_marks3>>o_marks3;
			marks>>subj_4>>t_marks4>>o_marks4;
			marks>>subj_5>>t_marks5>>o_marks5;
			//	while(!file.eof()) 
			//	{
			cout<<"Academic Details"<<endl;
			cout<<"Subject\t\t\tTotal Marks\t\t\tObtained Marks "<<endl;
			cout<<subj_1<<"\t\t\t"<<t_marks1<<"\t\t\t"<<o_marks1<<endl;
			cout<<subj_2<<"\t\t\t"<<t_marks2<<"\t\t\t"<<o_marks2<<endl;
			cout<<subj_3<<"\t\t\t"<<t_marks3<<"\t\t\t"<<o_marks3<<endl;
			cout<<subj_4<<"\t\t\t"<<t_marks4<<"\t\t\t"<<o_marks4<<endl;
			cout<<subj_5<<"\t\t\t"<<t_marks5<<"\t\t\t"<<o_marks5<<endl;
			cout<<"======================================================================"<<endl;
			system("pause");
			break;
			}
			}
//		if(found==0)
//		{
//			cout<<"\n\t\t\tStudent Roll No not found"<<endl;
//		}
	//	file >> name >> father_name >> roll_no >> cont_no >> dob >> domicile >> yoa >> dept;
	}
	
	file.close();
	marks.close();
}

void Student::deleted()
{
    system("cls");
	fstream file,marks,temp1;
	string rollno;
	cout<<"------- Delete Student Details --------"	<<endl;
	file.open("Personalinfo.txt",ios::in);
	marks.open("Marks.txt",ios::in);
	temp1.open("temp.txt", ios::app|ios::out);
	if(!file)
	{
		cout<<"---------------Search Student Data------------------"<<endl;
		cout<<" No Data Is present...."<<endl;
	}
	else
	{	
		cout<<"---------------Search Student Data------------------"<<endl;
		cout<<"Enter roll no. of student which you want to delete"<<endl;
		cin>>rollno;
		file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
		while(!file.eof())
		{
			if(roll_no==rollno)
			{
				cout<<"******Personal Details Deleted Successfully******"<<endl;
			}
			if(rollno!=roll_no)
			{
				temp1<< roll_no <<" "<< name <<" "<< father_name <<" "<<cont_no<< " "<< dob << " " <<domicile << " "<< yoa << " "<<dept <<endl;
			}
	    	file >> roll_no >> name >> father_name >> cont_no >> dob >> domicile >> yoa >> dept;
	    	if(file.eof())
	    	{
	    		cout<<"======================================================================\n\n"<<endl;
	    		cout<<"Student Personal data not found"<<endl;
	    		cout<<"\n\n======================================================================\n\n"<<endl;
			}
		}	
		file.close();
		temp1.close();
		remove("Personalinfo.txt");
		rename("temp.txt","Personalinfo.txt");
	}
	temp1.open("temp.txt", ios::app|ios::out);
	if(!marks)
	{
		cout<<"---------------Search Student Data------------------"<<endl;
		cout<<" No Marks Data Is present...."<<endl;
	}
	else
	{	
		marks>>roll_no;
		marks>>subj_1>>t_marks1>>o_marks1;
		marks>>subj_2>>t_marks2>>o_marks2;
		marks>>subj_3>>t_marks3>>o_marks3;
		marks>>subj_4>>t_marks4>>o_marks4;
		marks>>subj_5>>t_marks5>>o_marks5;
		while(!marks.eof())
		{
			if(rollno!=roll_no)
			{
				temp1<<roll_no;
				temp1<<" "<<subj_1<<" "<<t_marks1<< " "<<o_marks1;
				temp1<<" "<<subj_2<<" "<<t_marks2<<" "<<o_marks2;
				temp1<<" "<<subj_3<<" "<<t_marks3<<" "<<o_marks3;
				temp1<<" "<<subj_4<<" "<<t_marks4<<" "<<o_marks4;
				temp1<<" "<<subj_5<<" "<<t_marks5<<" "<<o_marks5<<endl;	
			}
			if(roll_no==rollno)
			{
				cout<<"******Academic Details Deleted Successfully******"<<endl;
			}
	    	marks>>roll_no;
			marks>>subj_1>>t_marks1>>o_marks1;
			marks>>subj_2>>t_marks2>>o_marks2;
			marks>>subj_3>>t_marks3>>o_marks3;
			marks>>subj_4>>t_marks4>>o_marks4;
			marks>>subj_5>>t_marks5>>o_marks5;
	    	if(marks.eof() && rollno!=roll_no)
	    	{
	    		cout<<"======================================================================\n\n"<<endl;
	    		cout<<"Student Academic data not found"<<endl;
	    		cout<<"\n\n======================================================================"<<endl;
				
			}
		}
			
		marks.close();
		temp1.close();
		remove("Marks.txt");
		rename("temp.txt","Marks.txt");
	}	
	//	cout<<"No Data Found"<<endl;
		system("pause");
		main();
}

int main()
{
	Student std;
	std.menu();
	
	
	return 0;
	getch();
}
