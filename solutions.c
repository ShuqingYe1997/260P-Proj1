#include <stdlib.h>

// Solution 1: brute force, can't get results in quite a long time
// O(n2)
// Efficiency score: 0
int doalg_brute( int n, int k, int Best[] ) {
    if (n < 10 || n > 10000) {
        printf(" *** invalid value for n, n should be 10 ~ 10000");
        return 0;
    }
    if (k < 1 || k > 100) {
        printf(" *** invalid value for k, n should be 1 ~ 100");
        return 0;
    }

    // smaller[i] means the number of elements which elements[i] is smaller than
    int* smaller = (int*)malloc((n + 1) * sizeof(int));
    if (smaller == NULL) {
        printf(" *** malloc failed! ");
        return 0;
    }
    // init
    for (int i = 1; i <= n;i++)
        smaller[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && COMPARE(i , j) == 2)
                smaller[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (smaller[i] < k)
            Best[smaller[i]] = i;
    }

    free(smaller);
    return 1;
}


// Solution 2: using an extra stack with depth == k (at most), also treat Best as a stack
// n=  100,  k=40:  maximum= 3201,  avg= 2571.49

// Solution 3: using an array with size = k
// O(kn)
// n=10000,  k=40:  maximum= 16609,  avg=15388.86
int doalg_array(int n, int k, int Best[]) {
    if (n < 10 || n > 10000) {
        printf(" *** invalid value for n, n should be 10 ~ 10000");
        return 0;
    }
    if (k < 1 || k > 100) {
        printf(" *** invalid value for k, n should be 1 ~ 100");
        return 0;
    }

    int pointer = 0;
    Best[pointer] = 1;
    for (int i = 2; i <= n; i++) {
        if (COMPARE(i, Best[pointer]) == 1) {
            int p = pointer;
            while (p >= 0 && COMPARE(i, Best[p]) == 1) {
                p--;
            }
            int j;
            for (j = pointer + 1; j > p + 1 ; j--) {
                Best[j] = Best[j - 1];
            }
            Best[j] = i;
            pointer++;
        }
        else {  // i < Best[pointer]
            Best[++pointer] = i;
        }
        if (pointer >= k)
            pointer = k - 1;  // keep pointer < k
    }
    return 1;
}
