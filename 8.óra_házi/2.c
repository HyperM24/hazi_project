#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 99
#define DB 10

typedef struct{
    int min;
    int max;
    double atlag;
} Eredmenyek;



void random_tomb(int tomb[], int meret){

srand(time(NULL));
for (int i = 0; i < meret; i++)
{
    tomb[i] = rand() % (MAX-MIN+1) + MIN;
}

}




Eredmenyek ertekek(int tomb[], int meret){

 Eredmenyek eredmeny;

 eredmeny.min = tomb[0];
 eredmeny.max = tomb[0];
 int sum = 0;

 for (int i = 0; i < meret; i++)
 {
    if (tomb[i] < eredmeny.min)
    {
        eredmeny.min = tomb[i];
    }
    else if (tomb[i] > eredmeny.max)
    {
        eredmeny.max = tomb[i];
    }
    
    sum = sum + tomb[i];
    
 }
 
 eredmeny.atlag = (double)sum/meret;

 return eredmeny;


}



int main(){

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

Eredmenyek eredmeny = ertekek(tomb,DB);

printf("Legkisebb: %d\n",eredmeny.min);
printf("Legnagyobb: %d\n",eredmeny.max);
printf("Az atlag: %.1f\n",eredmeny.atlag);


return 0;

}