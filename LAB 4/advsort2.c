#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
}
int temp = arr[i + 1];
    arr[i + 1] = arr[high];
arr[high] = temp;
return (i + 1);
}
void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}
int main() {
    int option, n;
    printf("MAIN MENU (QUICK SORT)\n");
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
            strcpy(outputFileName, "outQuickAsce.dat");
            break;
        case 2:
            strcpy(inputFileName, "inDesc.dat");
            strcpy(outputFileName, "outQuickDesc.dat");
            break;
        case 3:
            strcpy(inputFileName, "inRand.dat");
            strcpy(outputFileName, "outQuickRand.dat");
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
    quickSort(arr, 0, n - 1, &comparisons);
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
if (comparisons == n - 1) {
        printf("Scenario: Best-case partitioning\n");
    } else if (comparisons == (n * (n - 1)) / 2) {
        printf("Scenario: Worst-case partitioning\n");
    } else {
        printf("Scenario: Average-case partitioning\n");
}
printf("Execution Time: %f nanoseconds\n", executionTime);
return 0;
}