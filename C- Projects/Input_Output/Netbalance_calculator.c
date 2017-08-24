// NET BALANCE CALCULATOR PROGRAM BY ATER AKROFI //

#include <stdio.h>
#include <math.h>


// variable declarations  //

FILE*reportfile;         /* report file for output*/
FILE*datafile;           /* disk file for inpu t*/
char  type[7];           /*Export or import*/
float amount;            /*Export or Import value*/
float Net;               /*Net balance after import and exports of goods*/
int   count;             /*Number of times export/import data is processed*/



// Functional prototypes //

void Header(void);        /*Prototype for Header function*/
void Process(void);       /*Pprototype for Process function*/
void Summary(void);       /*Prototype for Summary function*/


int main(void)
 {
    datafile=fopen("input.txt","r");    /* Open input file */

    count=0;     /* Initialize accumulating variable */
    

    // Produce Report //
    
    Header();
    Process();
    Summary();
    
    fclose(datafile);


    system("pause");
    return 0;
}



void Header(void)
{
    reportfile = fopen("report.txt","w");
    
    // Prints header to report file //
    
    fprintf(reportfile,"The MoneyMaking Corporation\n");
    fprintf(reportfile,"550 Warm Sands Drive\n");
    fprintf(reportfile,"Palm Springs, CA 92262\n\n");
    
    fprintf(reportfile,"Type              Amount             Net\n");
    fprintf(reportfile,"----              ------             ---\n");


}


void Process(void) {

   // Process import and export data  //

datafile=fopen("c:\\class\\ie.txt","r");

     while(!feof(datafile))           /*loop condition*/
	{
     
     fscanf(datafile,"%s%f\n",&type,&amount);
     
     Net=Net+ amount;
     
     
     fprintf(reportfile,"%s%18.2f%18.2f\n",type,fabs(amount),Net);
     
     
    // Update accumulators //

     
       count++;
   }
   



}


void Summary()

{
   // Prints to reportfile  //

   fprintf(reportfile,"\n");
   fprintf(reportfile,"The net total for the month is $%.2f\n",Net);
   fprintf(reportfile,"Transactions processed : %d",count);




fclose(reportfile);
      
}

