#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Hiba! A %s nevű fájlt nem sikerült megnyitni!\n", argv[1]);
        return 2;
    }

    int line_count = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;
    }

    fclose(file);

    printf("%d\n", line_count);

    return 0;
}
