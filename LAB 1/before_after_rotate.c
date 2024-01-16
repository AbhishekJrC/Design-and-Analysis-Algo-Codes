#include <stdio.h>
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void ROTATE_RIGHT(int arr[], int n, int p2) {
    for (int i = 0; i < p2; i++) {
        EXCHANGE(&arr[n - 1], &arr[0]);
        for (int j = 0; j < n - 2; j++) {
            EXCHANGE(&arr[j], &arr[j + 1]);
        }
    }
}
int main() {
    int N;
    printf("Enter the size of the array: ");
scanf("%d", &N);
int arr[N];
printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
}
int p2;
    printf("Enter the number of elements to rotate: ");
scanf("%d", &p2);
printf("Before ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
printf("\n");
ROTATE_RIGHT(arr, N, p2);
printf("After ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
printf("\n");
return 0;
}