#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Factorization;

Factorization* factorize(int number, int* count) {
    Factorization* factors = malloc(number * sizeof(Factorization));
    *count = 0;

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            factors[*count].p = i;
            factors[*count].q = number / i;
            (*count)++;
            break;
        }
    }

    return factors;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 0;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found: %s\n", filename);
        return 0;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        int count;
        Factorization* results = factorize(number, &count);
        for (int i = 0; i < count; i++) {
            printf("%d=%d*%d\n", number, results[i].p, results[i].q);
        }
        free(results);
    }

    fclose(file);
    return 0;
}