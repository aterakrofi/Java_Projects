#include <stdio.h>
#include <math.h>


// variable declarations  //

FILE*reportfile;
FILE*inputfile;
char  CName[31];
float CA1;
float CA2;
float CA3;
float CL1;
float CL2;
float CL3;
float CR1;
float CR2;
float CR3;
float ACA;
float ACL;
float ACR;


// Functional prototypes //

void ReadFile(void);
void DoCalc(void);
void Report(void);


int main(void) {
    
    ReadFile();
    DoCalc();
    Report();
    
    system("pause");
    return 0;
}

void ReadFile(void) {
    
     inputfile=fopen("c:\\class\\current.txt","r");

     fgets(CName,31,inputfile);
     fscanf(inputfile,"%f%f\n",&CA1,&CL1);
     fscanf(inputfile,"%f%f\n",&CA2,&CL2);
     fscanf(inputfile,"%f%f\n",&CA3,&CL3);
     
    fclose(inputfile);
    

}

void DoCalc(void){
    CR1=(CA1/CL1);
    CR2=(CA2/CL2);
    CR3=(CA3/CL3);
    ACA=(CA1+CA2+CA3)/3;
    ACL=(CL1+CL2+CL3)/3;
    ACR=(CR1+CR2+CR3)/3;

}

void Report(void) {

     reportfile = fopen("c:\\class\\report.txt","w");
     fprintf(reportfile,"%s",CName);
     fprintf(reportfile,"Current Ratio Report\n\n");

    
     fprintf(reportfile,"            Current           Current              Current\n");
     fprintf(reportfile,"Year        Assets            Liabilities          Ra tio\n");
     fprintf(reportfile,"----------------------------------------------------------\n");
     fprintf(reportfile,"2010         %6.f            %6.f               %6.2f\n",CA1,CL1,CR1);
     fprintf(reportfile,"2011         %6.f            %6.f               %6.2f\n",CA2,CL2,CR2);
     fprintf(reportfile,"2012         %6.f            %6.f               %6.2f\n",CA3,CL3,CR3);
     fprintf(reportfile,"----------------------------------------------------------\n");
     fprintf(reportfile,"Average      %6.f            %6.f               %6.2f\n",ACA,ACL,ACR);

}
















