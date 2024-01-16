#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
scanf("%d", &n);
int arr[n];
 for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
}
int firstMin, secondMin, firstMax, secondMax;
if (n < 2) {
        printf("Array size is too small.\n");
    } else {
        if (arr[0] < arr[1]) {
            firstMin = arr[0];
            secondMin = arr[1];
            firstMax = arr[1];
            secondMax = arr[0];
        } else {
            firstMin = arr[1];
            secondMin = arr[0];
            firstMax = arr[0];
            secondMax = arr[1];
        }
for (int i = 2; i < n; i++) {
            if (arr[i] < firstMin) {
                secondMin = firstMin;
                firstMin = arr[i];
            } else if (arr[i] < secondMin && arr[i] != firstMin) {
                secondMin = arr[i];
            }
 if (arr[i] > firstMax) {
                secondMax = firstMax;
                firstMax = arr[i];
            } else if (arr[i] > secondMax && arr[i] != firstMax) {
                secondMax = arr[i];
            }
        }
printf("Second smallest element: %d\n", secondMin);
        printf("Second largest element: %d\n", secondMax);
}
return 0;
}
