/*6. Write a program using binary search to find 7.88, 9.22, 7.14 from the 
following list of CGPA 
8.12, 5.67, 9.22, 6.55, 7.88, 5.03, 9.93, 6.79, 8.50, 7.14 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp_double(const void *a, const void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

int binary_search(const double arr[], int n, double key) {
    int l = 0, r = n - 1;
    const double eps = 1e-6;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (fabs(arr[m] - key) < eps) return m;
        if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main(void) {
    double cgpa[] = {8.12, 5.67, 9.22, 6.55, 7.88, 5.03, 9.93, 6.79, 8.50, 7.14};
    int n = sizeof(cgpa) / sizeof(cgpa[0]);

    qsort(cgpa, n, sizeof(double), cmp_double);

    printf("Sorted CGPA list: ");
    for (int i = 0; i < n; ++i) printf("%.2f ", cgpa[i]);
    printf("\n\n");

    double targets[] = {7.88, 9.22, 7.14};
    int tcount = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < tcount; ++i) {
        double key = targets[i];
        int idx = binary_search(cgpa, n, key);
        if (idx != -1)
            printf("%.2f found at index %d in the sorted array.\n", key, idx);
        else
            printf("%.2f not found.\n", key);
    }

    return 0;
}