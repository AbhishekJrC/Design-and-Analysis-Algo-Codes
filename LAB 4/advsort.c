#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int n1 = mid - left + 1;
int n2 = right - mid;
int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
}
int i = 0, j = 0, k = left;
while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
}
while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
}
while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}
int main() {
    int option, n;
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
scanf("%d", &option);
char inputFileName[20];
char outputFileName[20];
switch (option) {
        case 1:
            strcpy(inputFileName, "inAsce.dat");
            strcpy(outputFileName, "outMergeAsce.dat");
            break;
        case 2:
            strcpy(inputFileName, "inDesc.dat");
            strcpy(outputFileName, "outMergeDesc.dat");
            break;
        case 3:
            strcpy(inputFileName, "inRand.dat");
            strcpy(outputFileName, "outMergeRand.dat");
            break;
        case 4:
            printf("Program terminated.\n");
            return 0;
        default:
            printf("Invalid option.\n");
            return 1;
}
FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
}
fscanf(inputFile, "%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
}
fclose(inputFile);
int comparisons = 0;
    clock_t start = clock();
    mergeSort(arr, 0, n - 1, &comparisons);
    clock_t end = clock();

    double executionTime = (double)(end - start)

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(outputFile);

    printf("After Sorting: Content of the output file\n");
    printf("Number of Comparisons: %d\n", comparisons);
    printf("Execution Time: %f nanoseconds\n", executionTime);

    return 0;
}