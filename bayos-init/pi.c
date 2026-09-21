#include <stdio.h>
#include <stdlib.h>

/* Computes the first `digits` decimal digits of pi using
   a spigot algorithm (based on Rabinowitz/Wagon's method). */

int main(void) {
    int digits = 100;              // number of digits of pi to compute
    int n = digits + 10;          // extra guard digits for accuracy
    int len = (n * 10) / 3 + 1;   // size of the working array

    int *a = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) a[i] = 2;

    int nines = 0, predigit = 0;
    int printed = 0;

    printf("pi = ");

    for (int j = 0; j < n; j++) {
        int q = 0;
        for (int i = len - 1; i >= 0; i--) {
            int x = 10 * a[i] + q * (i + 1);
            a[i] = x % (2 * i + 1);
            q = x / (2 * i + 1);
        }
        a[0] = q % 10;
        q /= 10;

        if (q == 9) {
            nines++;
        } else if (q == 10) {
            printf("%d", predigit + 1);
            printed++;
            for (int k = 0; k < nines; k++) {
                printf("0");
                printed++;
            }
            predigit = 0;
            nines = 0;
        } else {
            if (j > 0) {
                printf("%d", predigit);
                printed++;
                if (printed == 1) printf(".");
            }
            predigit = q;
            for (int k = 0; k < nines; k++) {
                printf("9");
                printed++;
            }
            nines = 0;
        }

        if (printed >= digits) break;
    }

    printf("\n");
    free(a);
    return 0;
}
