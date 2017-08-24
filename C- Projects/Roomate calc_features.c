// A workin-in progress c++ program to compute expenses shared by roomates in an apartment

#include <stdio.h>
#include <math.h>



// variable declarations  //

FILE*reportfile;         /* report file for output*/
FILE*datafile;           /* disk file for inpu t*/
char Name[10] ;
char Type[21];
char Date[21];
float Expense;
char  Repeat;
//int Total;
//int Expense1;
//int Expense2;
//int Expense3;
//int Share;
//int Payments;
//int OwedbyA;
//int OwedbyB;
//int OwedbyC;
//int OwedbyD;
//int TotalOwed;




// Functional prototypes //

void Header(void);        /*Prototype for Header function*/
void GetInfo(void);
void Process(void);       /*Pprototype for Process function*/
void Summary(void);       /*Prototype for Summary function*/


int main(void)
 {
    
    // Produce Report //
        
	Header();
    GetInfo();
	Process();
    Summary();
    
    fclose(datafile);


    system("pause");
    return 0;
}




   
   void Header(void)
	
{
    
    printf("*****ROOMATE EXPENSE CALCULATOR*****\n\n");
    printf("Expense statement as at .........\n");
    printf("----------------------------------\n\n");
    
    reportfile = fopen("OUPUT.txt","w");
    // Prints header to report file //
    fprintf(reportfile,"*****ROOMATE EXPENSE CALCULATOR*****\n\n");
    fprintf(reportfile,"Expense statement as at .........\n");
    fprintf(reportfile,"----------------------------------\n\n");
    
    fprintf(reportfile,"Name    Share    Payments    OwedbyA     OwedbyB     OwedbyC     OwedbyD     Total\n");
    fprintf(reportfile,"----    ------   --------    --------    --------    -------     --------    -----\n");	
        
	
	fclose(reportfile);

datafile=fopen("INPUT.txt","w");

	//fprintf(datafile,"*****ROOMATE EXPENSE CALCULATOR*****\n\n");
	
//	fprintf(datafile,"NAME       EXPENSE1       EXPENSE2      EXPENSES3");
	
//	fclose(datafile);

std::fstream fs;
  fs.open ("INPUT.txt", std::fstream::in | std::fstream::out | std::fstream::app);

  fs << " more lorem ipsum";

  fs.close();




}



void GetInfo(void)
{
   printf("Today's Date mm/dd/yr : ",Date);
   gets(Date);
   
   //scanf("%s",&Date);
   
   do{
   	
   
   printf("What is your Name : ",Name);
   scanf("%s",&Name);
   
   printf("Type of Expense paid : ",Type );
   scanf("%s",&Type);
   
   
   printf("Expense : ",Expense );
   scanf("%f",&Expense);
   
    	
   	printf("\n");
      printf("Add another Expense? ");
      scanf ("%s", &Repeat);
      
      
    printf("\n");
       
       
   } while (Repeat == 'Y' || Repeat == 'y');
   
   printf("End of processing.\n");
   
   
   }
   
	
	


void Process(void) 
{
	


   // Process import and export data  //

datafile=fopen("INPUT.txt","r");

     while(!feof(datafile))           /*loop condition*/
	{
     
	 fscanf(datafile,"%s%f\n",&type,&amount);
     
     Net=Net+ amount;
     
     
     fprintf(reportfile,"%s%18.2f%18.2f\n",type,fabs(amount),Net);
     
     
     
     
     
  }
   






void Summary()

{
   // Prints to reportfile  //





fclose(reportfile);
      
}

