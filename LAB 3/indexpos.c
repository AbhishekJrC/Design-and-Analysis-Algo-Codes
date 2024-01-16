#include <stdio.h>
int binarySearch(int arr[], int n, int key, int *comparisons) {
    int left = 0;
    int right = n - 1;
int position = -1;
while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;

        if (arr[mid] == key) {
            position = mid;
            right = mid - 1;  // Move left to find the leftmost appearance
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
}
return position;
}
int main() {
    int n, key;
    printf("Enter the size of the array: ");
scanf("%d", &n);
int arr[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
}
printf("Enter the key to be searched: ");
scanf("%d", &key);
int comparisons = 0;
int position = binarySearch(arr, n, key, &comparisons);
if (position != -1) {
        printf("%d found at index position %d\n", key, position);
    } else {
        printf("%d not found in the array.\n");
}
printf("Number of comparisons: %d\n", comparisons);
return 0;
}