#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void legrovidebb_szo(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Nem adtal meg egyetlen szot sem!\n");
        exit(1);
    }

    int hossz = strlen(argv[1]);

    for (int i = 2; i < argc; i++) {
        int jelenlegi_hossz = strlen(argv[i]);
        if (jelenlegi_hossz < hossz) {
            hossz = jelenlegi_hossz;
        }
    }

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) == hossz) {
            printf("%s\n", argv[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    legrovidebb_szo(argc, argv);
    return 0;
}
