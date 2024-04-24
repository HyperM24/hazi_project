#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 99
#define DB 10


void random_tomb(int tomb[], int meret){

srand(time(NULL));
for (int i = 0; i < meret; i++)
{
    tomb[i] = rand() % (MAX-MIN+1) + MIN;
}

}


void ertekek(int tomb[], int meret, int* min, int* max, double* atlag){

 *min = tomb[0];
 *max = tomb[0];
 int sum = 0;

 for (int i = 0; i < meret; i++)
 {
    if (tomb[i] < *min)
    {
        *min = tomb[i];
    }
    else if (tomb[i] > *max)
    {
        *max = tomb[i];
    }
    
    sum = sum + tomb[i];
 }
 
 *atlag = (double)sum/meret;



}



int main(){

int min;
int max;
double atlag;

int tomb[DB];
random_tomb(tomb,DB);

printf("Tombnek az elemei (10 db): ");
for (int i = 0; i < DB; i++)
{
    printf("%d", tomb[i]);

    if (i != 9)
    {
        printf(",");
    }
    
}

printf("\n");

ertekek(tomb,DB,&min,&max,&atlag);

printf("Legkisebb: %d\n",min);
printf("Legnagyobb: %d\n",max);
printf("Az atlag: %.1f\n",atlag);


return 0;

}