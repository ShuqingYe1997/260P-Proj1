#include <stdlib.h>

/**
 * @Description: Find the indices of a private array containing n distinct elements
 *              that have the k largest values in descending value order.
 *              Store the k indices in an integer array Best[]
 * @Return: normally return 1, but return 0 if any errors occurred
 * @Date: 2020-10-22
 */

// Solution 3
// use binary search rather than compare one by one
// n=10000,  k=40:  maximum= 11583,  avg=11334.12
int binarySearch(int Best[], int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(COMPARE(target, Best[mid]) == 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int doalg(int n, int k, int Best[]) {
    int pointer = 0;
    Best[pointer] = 1;
    for (int i = 2; i <= n; i++) {
        if (COMPARE(i, Best[pointer]) == 1) {
            int p = binarySearch(Best, 0, pointer - 1, i);
            int j = pointer + 1;
            for (; j > p ; j--) {
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


// Solution 4
int doalg_(int n, int k, int Best[]) {
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
            int p = binarySearch(Best, 0, pointer, i);
            int j = pointer + 1;
            for (; j > p ; j--) {
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


