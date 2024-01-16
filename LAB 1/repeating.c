#include <stdio.h>
int main() {
    int n;
    printf("Enter how many numbers you want to read from file: ");
scanf("%d", &n);
Int arr[n];
    int duplicateCount = 0;
    int maxRepeatCount = 0;
int mostRepeatedElement = -1;
printf("Enter the content of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
}
for (int i = 0; i < n; i++) {
        int repeatCount = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                repeatCount++;
            }
        }
if (repeatCount > 0) {
            duplicateCount++;
        }
if (repeatCount > maxRepeatCount) {
            maxRepeatCount = repeatCount;
            mostRepeatedElement = arr[i];
        }
}
printf("Total number of duplicate values = %d\n", duplicateCount);
printf("The most repeating element in the array = %d\n", mostRepeatedElement);
return 0;
}