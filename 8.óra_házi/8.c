#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *inputFile = fopen("in.txt", "r");
    if (inputFile == NULL) {
        printf("Hiba: in.txt fajl nem nyithato meg!\n");
        return 1; 
    }
    printf("# in.txt sikeresen megnyitva\n");


    FILE *outputFile = fopen("out.txt", "w");
    if (outputFile == NULL) {
        printf("Hiba: out.txt fajl nem nyithato meg!\n");
        fclose(inputFile);
        return 1; 
    }

    printf("# out.txt sikeresen megnyitva\n");

    printf("# 0,5-nel nagyobb szamok szurese...\n");
    
    char szam[500];

    int count = 0;
    while(fgets(szam, 500, inputFile)!=NULL){
        if(atof(szam) > 0.5){
            count++;
            szam[strlen(szam)-1] = '\0';
            fprintf(outputFile,"%s\n",szam);
        }
    }


    fclose(inputFile);
    fclose(outputFile);

    printf("# szures vege\n");
    printf("# out.txt bezarva\n");
    printf("# out.txt-be kiirt szamok mennyisege: %d db\n", count);

    return 0;
}
