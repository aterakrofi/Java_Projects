#include <stdio.h>
#include <math.h>


// variable declarations  //

FILE*reportfile;
FILE*datafile;
char type1[7];
char type2[7];
char type3[7];
char type4[7];
char type5[7];
char type6[7];
char type7[7];
float Import1;
float Import2;
float Import3;
float Export1;
float Export2;
float Export3;
float Export4;
float Net1;
float Net2;
float Net3;
float Net4;
float Net5;
float Net6;
float Net7;

// Functional prototypes //

void Header(void);
void ReadFile(void);
void Process(void);
void Sumarry(void);


int main(void)
 {

    Header();
    ReadFile();
    Process();
    Sumarry();

    system("pause");
    return 0;
}

void Header(void)
{
    fprintf(datafile,"The MoneyMaking Corporation\n");
    fprintf(datafile,"550 Warm Sands Drive\n");
    fprintf(datafile,"Palm Springs, CA 92262\n");
}


void ReadFile(void) {

     while(!feof(datafile))
	{
     fscanf(datafile,"%s%f",&type1,&Import1);
     fscanf(datafile,"%s%f",&type2,&Export1);
     fscanf(datafile,"%s%f",&type3,&EXport2);
     fscanf(datafile,"%s%f",&type4,&Import2);
     fscanf(datafile,"%s%f",&type5,&Export3);
     fscanf(datafile,"%s%f",&type6,&Import3);
     fscanf(datafile,"%s%f",&type7,&Export4);

     
   }


}

void Process(void)

{
    
    
    
}
