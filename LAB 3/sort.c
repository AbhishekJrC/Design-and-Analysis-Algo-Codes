#include <stdio.h>
void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }
arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int option, n;
    printf("MAIN MENU (INSERTION SORT)\n");
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
            strcpy(outputFileName, "outInsAsce.dat");
            break;
        case 2:
            strcpy(inputFileName, "inDesc.dat");
            strcpy(outputFileName, "outInsDesc.dat");
            break;
        case 3:
            strcpy(inputFileName, "inRand.dat");
            strcpy(outputFileName, "outInsRand.dat");
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
FILE *outputFile = fopen(outputFileName, "w");
if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
}
fscanf(inputFile, "%d", &n);
int arr[n];
for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
}
int comparisons = 0;
insertionSort(arr, n, &comparisons);
printf("Before Sorting: ");
printArray(arr, n);
for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
}
fclose(inputFile);
fclose(outputFile);
printf("After Sorting: Content of the output file\n");
printf("Number of Comparisons: %d\n", comparisons);
if (comparisons == n - 1) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (n * (n - 1)) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Average-case\n");
}
return 0;
}