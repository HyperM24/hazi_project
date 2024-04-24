#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    double num, sum = 0.0;
    char line[256];

    fp = fopen("valos_szamok.txt", "r");
    if (fp == NULL) {
        printf("Hiba a fajl megnyitasakor.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {

        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == ',') {
                line[i] = '.';
            }
        }

        if (sscanf(line, "%lf", &num) == 1) {
            sum += num;
        }
    }

    
    fclose(fp);

    
    printf("Az osszeg: %.20lf\n", sum);

    return 0;
}
