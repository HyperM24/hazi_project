#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vizsgal(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void csere(int array[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int N, lower, upper;

    printf("Hany db random szamot kersz?\n");
    scanf("%d", &N);

    printf("Also hatar: ");
    scanf("%d", &lower);

    printf("Felso hatar (zarva): ");
    scanf("%d", &upper);

    srand(time(0));


    int random_nums[N];
    for (int i = 0; i < N; i++) {
        random_nums[i] = (rand() % (upper - lower + 1)) + lower;
    }


    qsort(random_nums, N, sizeof(int), vizsgal);

    
    printf("A generalt szamok rendezve: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", random_nums[i]);
    }
    printf("\n");

    return 0;
}
