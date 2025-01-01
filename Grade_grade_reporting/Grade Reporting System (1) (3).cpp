#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<string>
using namespace std;
 
void studentInfo();     void updateStudInfo();     void deleteStudInfo();
void courseResult();    void updateResult();       void deleteResult();

void studentLogin();	  void teacherLogin();      void registrarLogin();
void depttChoice();        void gradeReport();

struct dept  { char dpt[30]; };
struct isCourses
		{
			float cpp, acc, math, eco, is, stat, incl;
		};
struct itCourses
		{
			float cpp, db, coa, elic, gt, stat, incl;
		};		
struct csCourses
		{
			float cpp, db, alg, eco, gt, stat, incl;
		};
struct student
	{   char prog[30];      char idno[10];
	    char age[3];        char f_name[25];
		char l_name[25];    char sex[10];
		struct isCourses s;    struct itCourses t;
		struct csCourses c;    struct dept d1;
		};

int main (){
system("color 5B");	
int choice, deptChoice;   string tpassword, spassword, rpassword;
outerloop:
system("cls");	
cout<<"\t\t\t\t      HAWASSA UNIVERSITY"<<endl;
cout<<"\t\t\t\t   INSTITUTE  OF TECHNOLOGY"<<endl;
cout<<"\t\t\t\t    FACULTY OF INFORMATICS"<<endl;
cout<<"==============================================================================================================="<<endl;
cout<<" \t\t\t\tStudent Grade Reporting System"<<endl;
cout<<"==============================================================================================================="<<endl;
cout<<"\n\t\t 1. STUDNET LOGIN"<< "\t 2. TEACHER LOGIN"  << "\t 3. REGISTRAR LOGIN"<<endl;
cout<<"\n\t\t  :"; cin>>choice;
 
 switch(choice){
 	
    case 1:  retry1: 
 		   cout<<"\n\n\tENTER PASSWORD: ";	cin>>spassword;
 	    if(spassword=="1234")      { studentLogin();}
	    else    {cout<<"\n\tINVALID PASSWORD. Please Try Again...";
        goto retry1; }   break;
	case 2: retry2:  system("cls");
 		      cout<<"\n\n\tENTER PASSWORD: ";   cin>>tpassword;
     	if(tpassword=="4321")     { teacherLogin();	}
        else       {cout<<"\n\tINVALID PASSWORD. Please Try Again...";
 	    goto retry2; }   break;
	  case 3: retry3: 
 		     cout<<"\n\n\tENTER PASSWORD: ";   cin>>rpassword;
     	if(rpassword=="0102")      {registrarLogin(); }
        else    {cout<<"\n\tINVALID PASSWORD. Please Try Again...";
 	    goto retry3; }  break;
	  
	default:  system("cls");   cout<<" \n\n\tINVALID CHOICE, PLEASE TRY AGIAN "<<endl;  break;
 }
  char ny;
  cout<<"\n\tDo You Want to Return to the Main Menu? Press 'y' for Yes or 'n' for No : "; cin>>ny;
 if(ny =='y'|| ny =='Y') { goto outerloop;}
  else exit(0);
 
 return 0; 
}
 
 void depttChoice()
 {
  struct dept d1;     ofstream studDeptFile;
	studDeptFile.open("studDeptFile.txt",ios::out);
int deptChoice;
cout<<"*******************CHOOSE DEPARTMENT******************"<<endl;
	cout<<"------------------------------------------------------"<<endl;	
	cout<<"\n   1.Information System"<<endl;
	cout<<"\n   2.Information Technology"<<endl;
	cout<<"\n   3.Computer Science"<<endl;
	cout<<"     :";cin>>deptChoice;   
char dtChoice [40];
   switch(deptChoice)
	{
	case 1:	system("cls");  strcpy (d1.dpt, "Information_System"); cout<<endl;
	    cout<<"\t\t**************************************************"<<endl;	
		cout<<"\t\t\tDEPARTMENT OF INFORMATION SYSTEM"<<endl;
		cout<<"\t\t**************************************************"<<endl;	
		break;
	case 2: system("cls");	strcpy (d1.dpt, "Information_Technology");  cout<<endl;
	    cout<<"\t*****************************************************"<<endl;	
		cout<<"\t\tDEPARTMENT OF INFORMATION TECHNOLOGY"<<endl;
		 cout<<"\t****************************************************"<<endl;	
		break;
	case 3:  system("cls");  strcpy (d1.dpt, "Computer_Science");	cout<<endl;
		cout<<"\t*************************************************"<<endl;	
		cout<<"\t\tDEPARTMENT OF COMPUTER SCIENCE"<<endl;
		cout<<"\t*************************************************"<<endl;	
		break;
	default:	system("cls");  cout<<"Invalid Choice";
    }
	studDeptFile <<d1.dpt<<endl;        studDeptFile.close();
}



void studentLogin(){
loops:  system("cls");
int choice;
cout<<"\n\t\t1. Display Grade Report"<<endl;	
cout<<"\n\t\t2. Exit"<<endl;   cout<<"\t\t   :";cin>> choice;

switch(choice){
	case 1:  system("cls");  gradeReport();  break;
	case 2:  exit(0);  break;
	default:  cout<<" \n\n\tINVALID CHOICE, PLEASE TRY AGIAN "<<endl;  
    goto loops;
    }
  char yn; 
  cout<<"\n\tDo You Want to Return to the STUDENT MENU? Press 'y' for Yes or 'n' for No : "; cin>>yn;
  if(yn =='y'|| yn =='Y')  { goto loops;}  else exit(0);
}



void teacherLogin(){
loopt:  system("cls");
int choice;
cout<<"\n\n\t\tPlease Choose from the following Options"<<endl;
cout<<"\n\t\t1.Register Students Course Results"<<endl;    cout<<"\n\t\t2.Update Students Course Results"<<endl;
cout<<"\n\t\t3.Delete Students Course Results"<<endl;      cout<<"\n\t\t4.Exit"<<endl;  cout<<"\t\t:";cin>> choice;

switch(choice){
case 1: system("cls");    courseResult();  break;
case 2:	system("cls");	  updateResult();  break;
case 3:	system("cls");    deleteResult();  break;
case 4: system("cls");	  exit(0);         break;
default: cout<<" \n\n\tINVALID CHOICE, PLEASE TRY AGIAN "<<endl;  
goto loopt;}
 
  char yn; 
  cout<<"\n\tDo You Want to Return to the TEACHER MENU? Press 'y' for Yes or 'n' for No : "; cin>>yn;
  if(yn =='y'|| yn =='Y')  { goto loopt;}  else exit(0); 
}



void registrarLogin(){	
int choice;
loopr:  system("cls");
cout<<"\n\tPlease Choose from the following Options";
cout<<"\n\t1.REGISTER Students";   cout<<"\n\t2.UPDATE Registered Students Information";
cout<<"\n\t3.DELETE Registered Students Information";  cout<<"\n\t4.Exit"<<endl;   cout<<"\t\t:";cin>> choice;

switch(choice){
case 1: system("cls");	  depttChoice();	studentInfo();   break;
case 2:	system("cls");	  updateStudInfo();	break;
case 3:	system("cls");	  deleteStudInfo();	break;
case 4: exit(0);  break;	
default:cout<<" \n\n\tINVALID CHOICE, PLEASE TRY AGIAN "<<endl;  
goto loopr; }
 
  char ny; 
  cout<<"\n\tDo You Want to Return to the REGISTRAR MENU? Press 'y' for Yes or 'n' for No : "; cin>>ny;
  if(ny =='y'|| ny =='Y') { goto loopr;}    else exit(0);
}	



void studentInfo()
{
	struct dept d1;   
	string	dept,prog ,id, f_name, l_name , age , sex;
	char dpt[40];    
	ofstream stdInfoFile;    ifstream studDeptFile;  
		
	stdInfoFile.open("stdInfoFile.txt", ios::out|ios::app);
	studDeptFile.open("studDeptFile.txt",ios::in);
	
	studDeptFile.getline(dpt,40); //to copy the line in the (studDeptFile.txt) file to the
 	                              //arry that has beeb chosen in the (deptChoice) function
    cout<<"\n\t\t======================================================";
	cout<<"\n\t\t--------------STUDENTS INFORMATION MENU---------------"<<endl;
	int n;
		cout<<"\n For how many students do you want to enter data:"<<endl;
		cout<<"\t\t:";cin>>n;
	
    student studArr [n]; // an array of type students called studArr 
	cout<<"\t_-_-_-_-_-_-_-_-_-_STUDENT DETAILS_-_-_-_-_-_-_-_-_-_"<<endl;
  
  for(int i=0;i<n;i++) {
	
	cout<<"\n\t\tDetails for Student: "<<i+1;
	
	cout<<"\n\tEnter Student "<<i+1<<" PROGRAM:";  cin>>studArr[i].prog;
	
	cout<<"\n\tEnter Student "<<i+1<<" ID NUMBER:"; cin>> studArr[i].idno; 
	  
    cout<<"\n\tEnter Student "<<i+1<<" FIRST NAME:"; cin>>studArr[i].f_name;
	
	cout<<"\n\tEnter Student "<<i+1<<" LAST NAME:"; cin>>studArr[i].l_name;
		
	cout<<"\n\tEnter Student " <<i+1<<" AGE:"; cin>>studArr[i].age; 
	
	cout<<"\n\tEnter Student " <<i+1<<" SEX:"; cin>>studArr[i].sex; cout<<endl;
	
	stdInfoFile    <<dpt<<" " <<studArr[i].prog<<" "     <<studArr[i].idno<<" "     <<studArr[i].f_name<<" "             
	                          <<studArr[i].l_name<<" "   <<studArr[i].age<<" "      <<studArr[i].sex<<" "<<endl;
		}
	stdInfoFile.close();
}
   
	
		
void courseResult()
	{   
     	int n, count=0;
		cout<<"\n\tFor how many students do you want to enter course marks?"<<endl;
		cout<<"     :";cin>>n;
        crLoop:
	struct isCourses s;    struct itCourses t;     struct csCourses c;
	string srch, idno,dept, prog, age, sex, f_name ,l_name;
	 
    ofstream outFile;                   ifstream inFile;    
	inFile.open("stdInfoFile.txt");    outFile.open("stdCourseFile.txt", ios::out|ios::app);
     if(!inFile.is_open())       {cout<<"File Not Found"<<endl;       exit(1);}
	 	
	cout<<"\n\tEnter the Id Number of the Student you want to record marks for:"<<endl;
	cout<<"\t\t:"; cin>>srch;

        while(inFile>>dept>>prog >>idno >> f_name>> l_name >> age >> sex){
	         if(srch==idno){   
	    cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl; 
	    cout<<"\n\tDepartment: "<<dept;    cout<<"\tFull Name: "<<f_name <<" "<<l_name<<endl;
		cout<<"\n\tProgram: "<<prog;    cout<<"\tID Number: "<<idno; cout<<"\tAge: "<<age;  cout<<"\t Sex: "<<sex<<endl;
		cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl; 
			
	     cout<<"\n\tEnter "<<f_name <<" "<<l_name<<"'s " <<" marks to corresponding courses:\n";
	
		    label1:
		    if (dept=="Information_System") {cout<<"\n\t Fundamentals of Programming in c++ result: ";cin>>s.cpp;  if(s.cpp<0||s.cpp>100){
			cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label1;}}
			            else if (dept=="Information_Technology") {cout<<"\n\t Fundamentals of Programming in c++ result: ";cin>>t.cpp;  if(t.cpp<0||t.cpp>100){
		          	     cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label1;}}
		          	             else if (dept=="Computer_Science") {cout<<"\n\t Fundamentals of Programming in c++ result: ";cin>>c.cpp;  if(c.cpp<0||c.cpp>100){
			                         cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label1;}}
		  
		    label2:
		    if (dept=="Information_System")    {cout<<"\n\t Accounting result: "; cin>>s.acc;
			if(s.acc<0||s.acc>100) {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;goto label2;}  }
			
			      else if(dept=="Information_Technology")    {cout<<"\n\t Database Systems result: "; cin>>t.db;
			      if(t.db<0||t.db>100)  {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;  goto label2;}  }
			       
			              else if(dept=="Computer_Science")      {cout<<"\n\t Database Systems result: "; cin>>c.db;
			              if(c.db<0||c.db>100)     {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label2;}  }
			
			label3:
		 
			if (dept=="Information_System") {	cout<<"\n\t Economics result: "; cin>>s.eco;   if(s.eco<0||s.eco>100){
			cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;  goto label3;}}
			       else if (dept=="Information_Technology") {cout<<"\n\t Computer Organization and Architecture Result: "; cin>>t.coa;  
				        if(t.coa<0||t.coa>100) {cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label3;}}
		          	            
								   else if(dept=="Computer_Science") {cout<<"\n\t Economics result: "; cin>>c.eco;  if(c.eco<0||c.eco>100){
			                         cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label3;}}
		  
			       
			label4:
		    if (dept=="Information_System") {cout<<"\n\t Discrete Maths result: "; cin>>s.math;  if(s.math<0||s.math>100){
			cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label4;}}
			     
				 else if(dept=="Information_Technology")    {cout<<"\n\t Fundamentals of Electricity result: "; cin>>t.elic;
			      if(t.elic<0||t.elic>100)  {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;  goto label4;}  }
			       
			              else if(dept=="Computer_Science")      {cout<<"\n\t Abstract Algebra result: "; cin >>c.alg; if(c.alg<0||c.alg>100)  
						     {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label4;}  }
			
			label5:
			if (dept=="Information_System") { cout<<"\n\t Statistics result: ";cin>>s.stat; if(s.stat<0||s.stat>100) 
			   {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;  goto label5;}}
			     	else if (dept=="Information_Technology") {cout<<"\n\t Statistics result: "; cin>>t.stat;  if(t.stat<0||t.stat>100){
		          	     cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label5;}}
		          	              else if (dept=="Computer_Science") { cout<<"\n\t Statistics result: "; cin>>c.stat;  if(c.stat<0||c.stat>100){
			                         cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label5;}} 
		    
			label6:
			if (dept=="Information_System")   {cout<<"\n\t Inclusiveness: "; cin>>s.incl; if(s.incl<0||s.incl>100){
			cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;goto label6;}}
		            else if (dept=="Information_Technology") {cout<<"\n\t Inclusiveness: ";  cin>>t.incl;  if(t.incl<0||t.incl>100){
		          	     cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label6;}}
		          	             else if (dept=="Computer_Science") {cout<<"\n\t Inclusiveness: "; cin>>c.incl;  if(c.incl<0||c.incl>100){
			                         cout<<"\n\tINVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label6;}} 
		    
		    
			label7:
		   	if (dept=="Information_System") {cout<<"\n\t Information Systems result: "; cin>>s.is;
			if(s.incl<0||s.incl>100){cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label7;}}
			
			     else if(dept=="Information_Technology")    {cout<<"\n\t Global Trends result: "; cin>>t.gt;
			           if(t.gt<0||t.gt>100)  {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl;  goto label7;}  }
			       
			              else if(dept=="Computer_Science")      {cout<<"\n\t Global Trends result: "; cin>>c.gt;
			                   if(c.gt<0||c.gt>100)     {cout<<"\n\t INVALID MARK, The mark range must be (0-100). Try agian!"<<endl; goto label7;}  }
			
		if (dept=="Information_System") {outFile   <<dept<<" "   <<prog<<" "  <<idno<<" "  <<f_name<<" "  <<l_name<<" "   <<age<<" "  <<sex<<" "       
		                                 <<s.cpp<<" "  <<s.acc<<" "  <<s.eco<<" "  <<s.math<<" "  <<s.stat<<" "  <<s.incl<<" "  <<s.is<<endl;}
		else if (dept=="Information_Technology") {outFile   <<dept<<" "   <<prog<<" "  <<idno<<" "  <<f_name<<" "  <<l_name<<" "   <<age<<" "  <<sex<<" "       
		                                 <<t.cpp<<" "  <<t.db<<" "  <<t.coa<<" "  <<t.elic<<" "  <<t.gt<<" "  <<t.stat<<" "  <<t.incl<<endl;}
	    else if (dept=="Computer_Science") {outFile   <<dept<<" "   <<prog<<" "  <<idno<<" "  <<f_name<<" "  <<l_name<<" "   <<age<<" "  <<sex<<" "       
		                                 <<c.cpp<<" "  <<c.db<<" "  <<c.alg<<" "  <<c.eco<<" "  <<c.gt<<" "  <<c.stat<<" "  <<c.incl<<endl;}	
		 	}} count++;   if (n>count){ goto crLoop;}
		 outFile.close();  inFile.close();
		}
			
	
	
void updateStudInfo()
	{ 
	int n;
	cout<<"\n\tFor how many students do you want to UPDATE Information?"<<endl;
	cout<<"     :";cin>>n;
	int count=0;
	loopLabel:
	string srch;
	string dept, prog ,idno,age, sex,f_name ,l_name;
	 
	 ofstream outFile;                     ifstream inFile;
	 outFile.open("newupdated.txt");      inFile.open("stdInfoFile.txt");
	 
	 if(!inFile.is_open())    {cout<<"File Not Found"<<endl;exit(1); }
	       
	cout<<"\n\tEnterthe Id Number of the Student you want to update for."<<endl;
	cout<<"\t\t"; cin>>srch;
	
	while(inFile>>dept>>prog >>idno >> f_name>> l_name >>age>>sex){
	 	if(srch==idno) {
	 cout<<"========================================================================================================================"<<endl;
     cout<<"\tDEPARTMENT: "<<dept;    cout  <<"\t\tPROGRAM: "<<prog;       cout <<"\tID NUMBER: "<<idno<<endl;  
     cout<<"\tFULL NAME: "<<f_name<<" "<<l_name;  cout<<  " \t\tSEX: " <<sex;   cout<< "\t\tAGE: "<<age <<endl;  
	 cout<<"========================================================================================================================"<<endl;  
		cout<<"\n\tEnter New Program:";      cin>>prog;
		cout<<"\n\tEnter New First Name:";   cin>>f_name;
		cout<<"\n\tEnter New Last Name:";    cin>>l_name;
		cout<<"\n\tUpdate sex to:";          cin>>sex;
		cout<<"\n\tEnter New Age:";          cin>>age;
		}
		outFile    <<dept<<" "    <<prog<<" "  <<idno<<" "    <<f_name <<" "  <<l_name<<" "     <<age <<" "     <<sex <<" " <<endl;	
		}count ++;
	  if(n>count){goto loopLabel;}
     
	 inFile.close();   outFile.close();
     remove("stdInfoFile.txt");    rename("newupdated.txt","stdInfoFile.txt");
		}
	 
	 
	 
	 
void updateResult()
	{ 
	int n;
	cout<<"\n\tFor how many students do you want to UPDATE course marks?"<<endl;
	cout<<"\t\t:";cin>>n;
	int count=0;
	urLoop:
	struct isCourses s;    struct itCourses t;     struct csCourses c;
	string srch, dpt, age, idno, prog, f_name, l_name, sex, mark1, mark2, mark3, mark4, mark5, mark6, mark7;
	float db, coa, elic, gt, cpp, acc, eco ,math ,stat ,incl ,is, alg;
	   //FOR IS---mark1=cpp  mark2=acc mark3=eco   mark4=math  mark5=stat  mark6=incl  mark7=is
       //FOR IT---mark1=cpp  mark2=db mark3=coa   mark4=elic  mark5=gt  mark6=stat  mark7=incl
       //FOR CS---mark1=cpp  mark2=db mark3=alg   mark4=eco  mark5=gt  mark6=stat  mark7=incl
	 ofstream outFile;                    ifstream inFile;
	 outFile.open("newupdated.txt",ios::out|ios::app);     inFile.open("stdCourseFile.txt");
	
	 if(!inFile.is_open())  {cout<<"File Not Found"<<endl;  exit(1); }

	cout<<"\n\tEnter the ID NUMBER of the Student you want update Result for."<<endl;
	cout<<"\t\t"; cin>>srch;
	
	while(inFile>>dpt>>prog>>idno>>f_name>> l_name>>  age>> sex>> mark1>>mark2>>mark3>>mark4>>mark5>>mark6>>mark7){
	if(srch==idno ){
	 cout<<"========================================================================================================================"<<endl;
     cout<<"\tDEPARTMENT: "<<dpt;    cout  <<"\t\tPROGRAM: "<<prog;       cout <<"\tID NUMBER: "<<idno<<endl;  
     cout<<"\tFULL NAME: "<<f_name<<" "<<l_name;  cout<<  " \t\tSEX: " <<sex;   cout<< "\t\tAGE: "<<age <<endl;  
	 cout<<"========================================================================================================================"<<endl;  
	
	if(dpt=="Information_System"){
	 
		cout<<"\n\tEnter New Fundamentals of Programming in c++ Mark:" ; cin>>mark1;
		cout<<"\n\tEnter New Accounting Mark:" ;	                     cin>>mark2;
		cout<<"\n\tEnter New Economics Mark:" ;		                     cin>>mark3;
		cout<<"\n\tEnter New Discrete Mathematics Mark:" ;	        	 cin>>mark4;
		cout<<"\n\tEnter New Statistics Mark:" ;		                 cin>>mark5;
		cout<<"\n\tEnter New Inclusiveness Mark:" ;		                 cin>>mark6;
		cout<<"\n\tEnter New Information Systems Mark:" ;		         cin>>mark7;
		}
	else if( dpt=="Information_Technology"){
	    cout<<"\n\tEnter New Fundamentals of Programming in c++ Mark:" ;	  cin>>mark1;
		cout<<"\n\tEnter New Database Systems Mark:" ;	                      cin>>mark2;
		cout<<"\n\tEnter New Computer Organization and Architecture Mark:" ;  cin>>mark3;
		cout<<"\n\tEnter New Fundamentals of Electricity Mark:" ;		      cin>>mark4;
		cout<<"\n\tEnter New Global Trends Mark:" ;		                      cin>>mark5;
		cout<<"\n\tEnter New Probability Statistics Mark:" ;		          cin>>mark6;
		cout<<"\n\tEnter New Inclusiveness Mark:" ;		                      cin>>mark7;
	     	}
	else if(dpt=="Computer_Science"){
	    cout<<"\n\tEnter New Fundamentals of Programming in c++ Mark:" ; cin>>mark1;
		cout<<"\n\tEnter New Database Systems:" ;	                     cin>>mark2;
		cout<<"\n\tEnter New Abstract Algebra:" ;		                 cin>>mark3;
		cout<<"\n\tEnter New Economics Mark:" ;		                     cin>>mark4;
		cout<<"\n\tEnter New Global Trends Mark:" ;		                 cin>>mark5;
		cout<<"\n\tEnter New Probability Statistics Mark:" ;		     cin>>mark6;
		cout<<"\n\tEnter New Inclusiveness Mark:" ;		                 cin>>mark7;
	}
	cout<<"\n\n\tRESULTS SUCCESSFULLY MODIFIED";
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
	}
	outFile   <<dpt<<" "   <<prog<<" "  <<idno<<" "  <<f_name<<" "  <<l_name<<" "   <<age<<" "  <<sex<<" "       
		                                 <<mark1<<" "  <<mark2<<" "  <<mark3<<" "  <<mark4<<" "  <<mark5<<" "  <<mark6<<" "  <<mark7<<endl;
	}
   inFile.close();                   outFile.close();
   remove("stdCourseFile.txt");      rename("newupdated.txt","stdCourseFile.txt");
   count++; if(n>count)  {goto urLoop;}
	}
	
		
		
void deleteStudInfo()
	{

cout<<"\n\t1.To DELETE Students Information FILE "<<endl;
cout<<"\t2.To DELETE DETAILS of the student"<<endl;	
int n; cout<<"\t\t:";  cin>>n;
switch(n)
{case 1:
	char ny; 
	cout<<"\n\tAre you you want to DELETE students Information FILE?...Press 'y' for Yes or 'n' for No :";cin>>ny;
	if(ny =='y'|| ny =='Y') { 
       if(remove("stdInfoFile.txt")!=0) perror("stdInfoFile.txt");
	   else puts("\n\tFILE SUCCESSFULLY DELETED");}
      break;
case 2:
	int n, choice;
	cout<<"\n\tFor how many students do you want to DELETE Information?"<<endl;
	cout<<"     :";cin>>n;
	int count=0;
  dsLoop:
  string srch, dept, age, prog ,idno, sex,f_name ,l_name;
  ofstream outFile;                      ifstream inFile;
   outFile.open("newupdated.txt");       inFile.open("stdInfoFile.txt");
  if(!inFile.is_open())  {cout<<"File Not Found"<<endl; 	exit(1);}
  	
  cout<<"\n\tEnter the Id Number of the Student :"; cin>>srch;

	while(inFile>>dept>>prog>>idno>>f_name>>l_name>>age>>sex){
	if(srch==idno){ 
	
	 cout<<"========================================================================================================================"<<endl;
     cout<<"\tDEPARTMENT: "<<dept;    cout  <<"\t\tPROGRAM: "<<prog;       cout <<"\tID NUMBER: "<<idno<<endl;  
     cout<<"\tFULL NAME: "<<f_name<<" "<<l_name;  cout<<  " \t\tSEX: " <<sex;   cout<< "\t\tAGE: "<<age <<endl;  
	 cout<<"========================================================================================================================"<<endl;  
		cout<<"\n\t1.Delete the Stedent's Program:";             cout<<"\n\t2.Delete the Stedent's First Name:";     
		cout<<"\n\t3.Delete the Stedent's Last Name:";           cout<<"\n\t4.Delete the Stedent'sex:";
	    cout<<"\n\t5.Delete the Stedent's Age:"<<endl;
		cout<<"\n\t: "; cin>>choice; 
		switch(choice){
		case 1:	prog=" ";   cout<<"\n\tProgram Successfully Deleted"<<endl; break;
	    case 2: f_name=" "; cout<<"\n\tFirst Name Successfully Deleted"<<endl; break;
		case 3: l_name=" "; cout<<"\n\tLast Name Successfully Deleted"<<endl; break;
		case 4: sex=" ";    cout<<"\n\tSex Successfully Deleted"<<endl; break;
		case 5: age=" ";    cout<<"\n\tAge Successfully Deleted"<<endl; break;
	}}
     outFile    <<dept<<" "     <<prog<<" "   <<idno<<" "  <<f_name<<" "   <<l_name<<" " <<age<<" "    <<sex<<" "<<endl;
	} count ++; if(n>count){   goto dsLoop;}
     inFile.close();     outFile.close();
	remove("stdInfoFile.txt");   rename("newupdated.txt","stdInfoFile.txt");
	
  	break;	
    }}
	
		
		
void deleteResult()
	{
cout<<"\n\n\t1.To DELETE Course Results FILE";
cout<<"\n\t2.To DELETE Course Results of students"<<endl;	
int n; cout<<"\t\t:"; cin>>n;
switch(n)
{ 
case 1:
	char ny; 
	cout<<"\n\tAre you you want to DELETE students Information FILE?...Press 'y' for Yes or 'n' for No :";cin>>ny;
	if(ny =='y'|| ny =='Y') { 
	if(remove("stdCourseFile.txt")!=0)    perror("stdCourseFile.txt");
	else   puts("\n\tFILE SUCCESSFULLY DELETED");}	break;
case 2:
	int n, choice, count=0;
	cout<<"\n\tFor how many students do you want to DELETE Information?"<<endl;
	cout<<"     :";cin>>n;
    dsLoop:
	  
	  string srch, dpt, prog, idno,age,f_name,l_name, sex,mark1, mark2, mark3, mark4, mark5, mark6, mark7;
	  ofstream outFile;                    ifstream inFile;
	  outFile.open("newupdated.text");     inFile.open("stdCourseFile.txt");
	 if(!inFile.is_open())       {cout<<"File Not Found"<<endl;     exit(1); }
	
	cout<<"\tEnter the ID NUMBER of the Student you want to delete Marks for."<<endl;   cout<<"\t\t:"; cin>>srch;

	while(inFile>>dpt>>prog>>idno>>f_name>>l_name>>age>>sex>>mark1>>mark2>>mark3>>mark4>>mark5>>mark6>>mark7){
     if (srch==idno){       int y;
     cout<<"========================================================================================================================"<<endl;
     cout<<"\tDEPARTMENT: "<<dpt;    cout  <<"\t\tPROGRAM: "<<prog;       cout <<"\tID NUMBER: "<<idno<<endl;  
     cout<<"\tFULL NAME: "<<f_name<<" "<<l_name;  cout<<  " \t\tSEX: " <<sex;   cout<< "\t\tAGE: "<<age <<endl;  
	 cout<<"========================================================================================================================"<<endl;
	  
	  if( dpt=="Information_System")  { 
	  
	    cout<<"\n\t1.To Delete Programming Mark"<<endl;             cout<<"\n\t2.To Delete Accounting Mark"<<endl;
		cout<<"\n\t3.To Delete Economics Mark"<<endl;               cout<<"\n\t4.To Delete Discrete Mathematics Mark"<<endl;
		cout<<"\n\t5.To Delete Statistics Mark"<<endl;              cout<<"\n\t6.To Delete Inclusiveness Mark"<<endl;
	    cout<<"\n\t7.To Delete Information Systems Mark"<<endl;    cout<<" : "; cin>>y; 
	    } 
		  else if( dpt=="Information_Technology"){    
		cout<<"\n\t1.To Delete Programming Mark"<<endl;                   cout<<"\n\t2.To Delete Database Systems Mark"<<endl;
		cout<<"\n\t3.To Delete Computer Architecture Mark"<<endl;         cout<<"\n\t4.To Delete Fundamentals of Electricity Mark"<<endl;
		cout<<"\n\t5.To Delete Global Trends Mark"<<endl;                 cout<<"\n\t6.To Delete Statistics Mark"<<endl;
	    cout<<"\n\t7.To Delete Inclusiveness Mark"<<endl;    cout<<" : "; cin>>y; 
	     } 
		  else if( dpt=="Computer_Science"){  
		cout<<"\n\t1.To Delete Programming Mark"<<endl;             cout<<"\n\t2.To Delete Database Systems Mark"<<endl;
		cout<<"\n\t3.To Delete Algebra Mark"<<endl;               cout<<"\n\t4.To Delete Economics Mark"<<endl;
		cout<<"\n\t5.To Delete Global Trends Mark"<<endl;              cout<<"\n\t6.To Delete Statistics Mark"<<endl;
	    cout<<"\n\t7.To Delete Inclusivenes Mark"<<endl;    cout<<" : "; cin>>y; 
	    }
	    switch(y){
		case 1:	mark1=" ";  break;     case 2: mark2=" ";  break;   case 3: mark3=" ";  break;    case 4: mark4=" "; break; 
		case 5: mark5=" "; break;     case 6: mark6=" "; break;   case 7: mark7=" ";   break;    default: cout<<"\n\tINVALID CHOICE";}
		
		cout<<"\n\tRESULTS SUCCESSFULLY DELETED";
	    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
		  }
	     
      outFile     <<dpt<<" "   <<prog<<" "  <<idno<<" "  <<f_name<<" "  <<l_name<<" "   <<age<<" "  <<sex<<" "       
		                               <<mark1<<" "  <<mark2<<" "  <<mark3<<" "  <<mark4<<" "  <<mark5<<" "  <<mark6<<" "  <<mark7<<endl;
	}	count++;
    inFile.close();   outFile.close();
	remove("stdCourseFile.txt");    rename("newupdated.text","stdCourseFile.txt");
	 if(n>count){   goto dsLoop;}
	break;
	}}





void gradeReport(){
	string srch, dept, prog, idno,age,f_name,sex, l_name;
	float mark1, mark2, mark3, mark4, mark5, mark6, mark7;
	ifstream inFile;
	float marks[7];  string grd[7];  float grdPt[7];   float gpa=0;  float totalPt=0; int totalCrHr=32;
	inFile.open("stdCourseFile.txt");
	if(!inFile.is_open())       {cout<<"File Not Found"<<endl;     exit(1); }
	
cout<<" \n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl; 	
cout<<"\t\t\t\t\t      HAWASSA UNIVERSITY"<<endl;
cout<<"\t\t\t\t\t   INSTITUTE  OF TECHNOLOGY"<<endl;
cout<<"\t\t\t\t\t    FACULTY OF INFORMATICS"<<endl;
cout<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl;	 	
cout<<" \t\t\t\t\t    STUDENTS GRADE REPORT"<<endl;

cout<<"\n\tENTER YOUR ID NUMBER"<<endl;      cout<<"\t\t:"; cin>>srch;

    while(inFile>>dept>>prog>>idno>>f_name>>l_name>>age>>sex>>mark1>>mark2>>mark3>>mark4>>mark5>>mark6>>mark7){   
       //FOR IS---mark1=cpp  mark2=acc mark3=eco   mark4=math  mark5=stat  mark6=incl  mark7=is
       //FOR IT---mark1=cpp  mark2=db mark3=coa   mark4=elic  mark5=gt  mark6=stat  mark7=incl
       //FOR CS---mark1=cpp  mark2=db mark3=alg   mark4=eco  mark5=gt  mark6=stat  mark7=incl
    
	if(srch==idno){
    int  crHr[7]={5,4,5,5,4,4,5};  float total[7];
     cout<<"========================================================================================================================"<<endl;
     cout<<"\tDEPARTMENT: "<<dept;    cout  <<"\t\tPROGRAM: "<<prog;       cout <<"\tID NUMBER: "<<idno<<endl;  
     cout<<"\tFULL NAME: "<<f_name<<" "<<l_name;  cout<<  " \t\tSEX: " <<sex;   cout<< "\t\tAGE: "<<age <<endl;
  
  for(int i=0;i<7;i++){}
   
   marks[0]= mark1;   marks[1]= mark2;  marks[2]= mark3;  marks[3]= mark4;  marks[4]= mark5;  marks[5]= mark6;  marks[6]= mark7;
    
     for(int i=0;i<7;i++){
	if(marks[i]>=90 && marks[i]<=100)         {grd[i]="A+"; grdPt[i]=4;}
    
	else if(marks[i]>=85 && marks[i]<90)      {grd[i]="A";  grdPt[i]=4;}
    
	else if(marks[i]>=80 && marks[i]<85)      {grd[i]="A-";  grdPt[i]=3.75;}
    
	else if(marks[i]>=75 && marks[i]<80)      {grd[i]="B+";  grdPt[i]=3.5;}
    
	else if(marks[i]>=70 && marks[i]<75)      {grd[i]="B";  grdPt[i]=3;}
   
    else if(marks[i]>=65 && marks[i]<70)      { grd[i]="B-";  grdPt[i]=2.75;}
   
    else if(marks[i]>=60 && marks[i]<65)      {grd[i]="C+";  grdPt[i]=2.5;}
   
    else if(marks[i]>=55 && marks[i]<60)      {grd[i]="C";  grdPt[i]=2;}
   
    else if(marks[i]>=50 && marks[i]<55)       {grd[i]="C-";  grdPt[i]=1.75;}
   
    else if(marks[i]>=40 && marks[i]<50)       {grd[i]="D";  grdPt[i]=1;}
   
    else if(marks[i]>=1 && marks[i]<40)       {grd[i]="F"; grdPt[i]=0;}
   
    else  cout<<"Invalid Number";
    
    total[i]=(crHr[i]) * (grdPt[i]);          totalPt+= total[i];
	 }
	 if(dept=="Information_System"){
  cout<<"========================================================================================================================"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\tCourses"  <<"\t\t\t\tResults" <<"\tGrade"  <<"\tGrade Point" <<"\tCredit Hour"   <<"\tTotal(Gr.Pt. * Cr.Hr.)"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n 1. Fundamentals of Programming in c++" <<"     "<<mark1  <<"\t  "<< grd[0]  <<"\t  "<< grdPt[0]  <<"\t\t  5"  <<"\t\t "<<total[0]; 
  cout<<"\n 2. Principles of Accounting" <<" \t\t   "<<mark2         <<"\t  " <<grd[1]  <<"\t  "<< grdPt[1]  <<"\t\t  4"  <<"\t\t "<<total[1];
  cout<<"\n 3. Introduction to Economics" <<"\t\t   "<<mark3         <<"\t  "<< grd[2]  <<"\t  "<< grdPt[2]  <<"\t\t  5"  <<"\t\t "<<total[2];
  cout<<"\n 4. Discrete Mathematics and Combinatory" <<"   "<<mark4  <<"\t  "<< grd[3]  <<"\t  "<< grdPt[3]  <<"\t\t  5"  <<"\t\t "<<total[3];
  cout<<"\n 5. Statistics and Probability"<<"\t\t   " <<mark5        <<"\t  "<< grd[4]  <<"\t  "<< grdPt[4]  <<"\t\t  4"  <<"\t\t "<<total[4];
  cout<<"\n 6. Inclusiveness"<<"\t\t\t   " <<mark6                   <<"\t  "<< grd[5]  <<"\t  "<< grdPt[5]  <<"\t\t  4"  <<"\t\t "<<total[5];
  cout<<"\n 7. Information Systems" <<"\t\t\t   " <<mark7            <<"\t  "<< grd[6]  <<"\t  "<< grdPt[6]  <<"\t\t  5"  <<"\t\t "<<total[6] <<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"========================================================================================================================"<<endl;
}
          else if(dept=="Information_Technology"){
  cout<<"========================================================================================================================"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\tCourses"  <<"\t\t\t\t  Results" <<" Grade"  <<" GradePoint" <<"  CreditHour"   <<"   Total(Gr.Pt. * Cr.Hr.)"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n 1. Fundamentals of Programming in c++" <<"\t    "<<mark1  <<"\t    "<< grd[0]  <<"\t   "<< grdPt[0]  <<"\t\t  5"  <<"\t\t "<<total[0]; 
  cout<<"\n 2. Fundamentals of Database Systems" <<" \t    "<<mark2   <<"\t    " <<grd[1]  <<"\t   "<< grdPt[1]  <<"\t\t  4"  <<"\t\t "<<total[1];
  cout<<"\n 3. Computer Organization and Architecture" <<"  "<<mark3  <<"\t    "<< grd[2]  <<"\t   "<< grdPt[2]  <<"\t\t  5"  <<"\t\t "<<total[2];
  cout<<"\n 4. Fundamentals of Electricity"<<"\t\t    "<<mark4        <<"\t    "<< grd[3]  <<"\t   "<< grdPt[3]  <<"\t\t  5"  <<"\t\t "<<total[3];
  cout<<"\n 5. Global Trends"<<"\t\t\t    " <<mark5                   <<"\t    "<< grd[4]  <<"\t   "<< grdPt[4]  <<"\t\t  4"  <<"\t\t "<<total[4];
  cout<<"\n 6. Probability and Statistics"<<"\t\t    " <<mark6        <<"\t    "<< grd[5]  <<"\t   "<< grdPt[5]  <<"\t\t  4"  <<"\t\t "<<total[5];
  cout<<"\n 7. Inclusiveness" <<"\t\t\t    " <<mark7                  <<"\t    "<< grd[6]  <<"\t   "<< grdPt[6]  <<"\t\t  5"  <<"\t\t "<<total[6] <<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"========================================================================================================================"<<endl;
}
       else if(dept=="Computer_Science"){
  cout<<"========================================================================================================================"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\tCourses"  <<"\t\t\t\tResults" <<"\tGrade"  <<"\tGrade Point" <<"\tCredit Hour"   <<"\tTotal(Gr.Pt. * Cr.Hr.)"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n 1. Fundamentals of Programming in c++" <<"\t  "<<mark1 <<"\t  "<< grd[0]  <<"\t  "<< grdPt[0]  <<"\t\t  5"  <<"\t\t "<<total[0]; 
  cout<<"\n 2. Fundamentals of Database Systems" <<" \t  "<<mark2  <<"\t  " <<grd[1]  <<"\t  "<< grdPt[1]  <<"\t\t  4"  <<"\t\t "<<total[1];
  cout<<"\n 3. Abstract Algebra" <<"\t\t\t  "<<mark3               <<"\t  "<< grd[2]  <<"\t  "<< grdPt[2]  <<"\t\t  5"  <<"\t\t "<<total[2];
  cout<<"\n 4. Introduction to Economics" <<"\t\t  "<<mark4        <<"\t  "<< grd[3]  <<"\t  "<< grdPt[3]  <<"\t\t  5"  <<"\t\t "<<total[3];
  cout<<"\n 5. Global Trends"<<"\t\t\t  " <<mark5                  <<"\t  "<< grd[4]  <<"\t  "<< grdPt[4]  <<"\t\t  4"  <<"\t\t "<<total[4];
  cout<<"\n 6. Probability and Statistics"<<"\t\t  " <<mark6       <<"\t  "<< grd[5]  <<"\t  "<< grdPt[5]  <<"\t\t  4"  <<"\t\t "<<total[5];
  cout<<"\n 7. Inclusiveness" <<"\t\t\t  " <<mark7                 <<"\t  "<< grd[6]  <<"\t  "<< grdPt[6]  <<"\t\t  5"  <<"\t\t "<<total[6] <<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"========================================================================================================================"<<endl;
}

    cout<<"\n\tTHE SUM OF TOTAL POINTS OF THE SEVEN SUBJECTS IS: "<<totalPt<<endl;
    cout<<"\n\tTHE SUM OF CREDIT HOURS OF THE SEVEN SUBJECTS IS: "<<totalCrHr<<endl;
    cout<<"\n\tSEMESTER GPA = TOTAL POINTS / TOTAL CREDIT HOURS"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
   gpa= totalPt/totalCrHr;   cout<<"\n\tSEMESTER GPA: "<<gpa<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"========================================================================================================================"<<endl;

}
}
  cout<<"\n\tId Number Not Found. Please Try Again";
}
   


		
		



