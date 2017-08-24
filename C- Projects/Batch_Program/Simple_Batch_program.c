// Batchprogram by Ater Akrofi //


#include <stdio.h>
#include <math.h>


// variable declarations  //

FILE*reportfile;      /* report file for output*/
FILE*inputfile;       /* disk file (for inpu t) */
char  CName[31];      /* Name of th company */
float CA1;            /* Current Assets in 2010 */
float CA2;            /* Current Assets in 2011 */
float CA3;            /* Current Assets in 2012 */
float CL1;            /* Current Liabilities in 2010 */
float CL2;            /* Current Liabilities in 2011 */
float CL3;            /* CurrentLiabilities in 2012 */
float CR1;            /* Current Ratio in 2010 */
float CR2;            /* Current Ratio in 2011*/
float CR3;            /* Current Ratio in 2012 */
float ACA;            /* Average Current Assets for 2010-2012 */
float ACL;            /* Average Current Liabilities for 2010-2012 */
float ACR;            /* Average Current Ratio for 2010-2012 */


// Functional prototypes //

void ReadFile(void);       /* Prototype for ReadFile function */
void DoCalc(void);         /* Prototype for DoCalc function  */
void Report(void);         /* Prototype for Report function */


int main(void) {
    
    ReadFile();           /* Reads information from diskfile */
    DoCalc();             /* Calculates CR1,CR2,CR3,ACA,ACL,ACR */
    Report();             /* Prints output report to file */
    
    system("pause");
    return 0;
}

void ReadFile(void) {
    
     inputfile=fopen("current.txt","r");  /* Reads input file from disk */

     fgets(CName,31,inputfile);                      /* Reads company name from input file */
     fscanf(inputfile,"%f%f\n",&CA1,&CL1);           /* Reads first line of numbers from input file */
     fscanf(inputfile,"%f%f\n",&CA2,&CL2);           /* Reads second line of numbers from input file */
     fscanf(inputfile,"%f%f\n",&CA3,&CL3);           /* Reads third line of numbers from input file */
     
    fclose(inputfile);
    

}


void DoCalc(void){
    
    // Calculates Current ratio for 2010-2012//
    
            CR1= CA1/CL1;
            CR2= CA2/CL2;
            CR3= CA3/CL3;
    
    // Calculate  Averages for current assets, current liabilities, current ratio //
    
            ACA=(CA1+CA2+CA3)/3;
            ACL=(CL1+CL2+CL3)/3;
            ACR=(CR1+CR2+CR3)/3;

}

void Report(void) {
    
     //  Prints output file to disk //

     reportfile = fopen("report.txt","w");
     
     fprintf(reportfile,"%s",CName);
     fprintf(reportfile,"Current Ratio Report\n\n");

    
     fprintf(reportfile,"            Current           Current              Current\n");
     fprintf(reportfile,"Year        Assets            Liabilities          Ra tio\n");
     fprintf(reportfile,"----------------------------------------------------------\n");
     fprintf(reportfile,"2010         %6.f            %6.f                 %0.2f\n",CA1,CL1,CR1);
     fprintf(reportfile,"2011         %6.f            %6.f                 %0.2f\n",CA2,CL2,CR2);
     fprintf(reportfile,"2012         %6.f            %6.f                 %0.2f\n",CA3,CL3,CR3);
     fprintf(reportfile,"----------------------------------------------------------\n");
     fprintf(reportfile,"Average      %6.f            %6.f               %6.2f\n",ACA,ACL,ACR);
     
     fprintf(reportfile,"\n""\n");
     
     fprintf(reportfile,"This report produced by Ater Akrofi.");

}
















