#include <stdio.h>
#include <math.h>


// variable declarations  //


float Amount;         
int   Days;
float Contribution;
float SavingsPlan;
float Myplan;


// Functional prototypes //

void Header(void);
void Getinfo(void);
void DoCalc(void);
void Report(void);


int main(void) {
    
    Header();
    Getinfo();
    Docalc();
    Report();            
    
    system("pause");
    return 0;
}

void Header(void) {

     printf(              "**** SAVINGS PLANNER ****\n\n ");
    
   
   
    }


void Getinfo(void)

{
     printf("Amount of required  :  ");
     scanf("%.2f\n",&Amount);

     printf("Number of days left :  ");
     scanf("%d\n",&Days);

     printf("Estimated daily contribution :  ");
     scanf("%d\n",&Contribution);

}

void Docalc(void)

{
    SavingsPlan= (Amount/Days) ;
    
    Myplan= (Amount/Contribution);

    
}


void Report(void) {
    
    
     printf("Recommended savings plan  :%.2f\n ",SavingsPlan);
     
     printf("Your Savings Plan  : %.2f\n",Myplan);
         

}
















