#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;
if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;
if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;
if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;
if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
void buildMaxHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void displayYoungestWeight(struct person arr[], int n) {
    if (n > 0) {
        printf("Weight of youngest student: %.2f kg\n", (float)arr[0].weight / 2.20462);
    } else {
        printf("Heap is empty.\n");
    }
}
void insertMinHeap(struct person arr[], int *n, struct person newPerson) {
    int i = (*n)++;
arr[i] = newPerson;
while (i > 0 && arr[i].age < arr[(i - 1) / 2].age) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
printf("New person inserted into the min-heap.\n");
}
void deleteMaxHeapRoot(struct person arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return;
    }
if (*n == 1) {
        (*n)--;
        printf("Oldest person deleted from the max-heap.\n");
        return;
    }
arr[0] = arr[(*n) - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
    printf("Oldest person deleted from the max-heap.\n");
}
int main() {
    int option, n = 0;
struct person *students = NULL;
printf("MAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on age\n");
    printf("3. Create a Max-heap based on weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
while (1) {
        printf("Enter option: ");
        scanf("%d", &option);
if (option == 1) {
            if (students) {
                printf("Data already loaded. Please free the memory before reloading.\n");
                continue;
            }
FILE *file = fopen("student_data.txt", "r");
            if (file == NULL) {
                printf("Error opening file.\n");
                return 1;
            }
fscanf(file, "%d", &n);
            students = (struct person *)malloc(n * sizeof(struct person));
for (int i = 0; i < n; i++) {
                students[i].id = i;
                students[i].name = (char *)malloc(100 * sizeof(char));
                fscanf(file, "%s %d %d %d", students[i].name, &students[i].age, &students[i].height, &students[i].weight);
            }
fclose(file);
        } else if (option == 2) {
            if (!students) {
                printf("Data not loaded yet.\n");
                continue;
            }
buildMinHeap(students, n);
            printf("Min-heap created based on age.\n");
        } else if (option == 3) {
            if (!students) {
                printf("Data not loaded yet.\n");
                continue;
            }
buildMaxHeap(students, n);
            printf("Max-heap created based on weight.\n");
        } else if (option == 4) {
            if (!students) {
                printf("Data not loaded yet.\n");
                continue;
            }
displayYoungestWeight(students, n);
        } else if (option == 5) {
            if (!students) {
                printf("Data not loaded yet.\n");
                continue;
            }
struct person newPerson;
            newPerson.id = n;
            newPerson.name = (char *)malloc(100 * sizeof(char));
            printf("Enter the name, age, height, and weight of the new person: ");
            scanf("%s %d %d %d", newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
            insertMinHeap(students, &n, newPerson);
        } else if (option == 6) {
            if (!students) {
                printf("Data not loaded yet.\n");
                continue;
            }
deleteMaxHeapRoot(students, &n);
        } else if (option == 7) {
            if (students) {
                for (int i = 0; i < n; i++) {
                    free(students[i].name);
                }
                free(students);
            }
            printf("Program terminated.\n");
            return 0;
        } else {
            printf("Invalid option. Please select a valid option.\n");
        }
    }
}