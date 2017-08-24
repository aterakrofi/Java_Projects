/*LESSONS : IT IS BETTER TO STRING Q&A FORMAT QUESTIONS
 FOR NUMBERS USE SSTREAM TO
 CONVERT STRING NUMBER INTO INTEGER */
 
 //WHEN DECLARING STRINGS, DO NOT DECLARE IN SAME LINE EG. string a,b,c)




#include <iostream>
#include <string>
#include <sstream>

using namespace std;



string Name ;
string Age;
string SSN;
string ST;
int Years;
//int Y;

//int age ;

int main ()

{


do{
	cout<<"Input NAME : "; getline (cin,Name) ;
cout<<"AGE : "; getline (cin,Age) ;
stringstream(Age)>>Years ;
if (Years>21)
{
	cout<<"You are not eligible for this loan: " <<endl;
}
else {
	
cout<<"Input SSN : "; getline (cin,SSN) ;
cout<<"Input State : "; getline (cin,ST); 

cout<<endl<<endl<<endl;

cout<<"SUMMARY PROFILE";cout<<endl;
cout<<"----------------" ;cout<<endl;cout<<endl;cout<<endl;
cout<<"NAME : "<<Name <<endl;
cout<<"AGE  : "<<Age <<endl;
cout<<"SSN  : "<<SSN <<endl;
cout<<"State: "<<ST<<endl;
}
cout<<"Do you wish to input more data  ?"; //cin>>Y;
}


while (Y=Y);

return 0 ;
	
	
}
