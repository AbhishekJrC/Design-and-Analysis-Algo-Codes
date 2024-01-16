#include <stdio.h>
#include <stdlib.h>
struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left;
    struct SYMBOL *right;
};
struct MinHeap {
    int size;
    int capacity;
    struct SYMBOL *array;
};
void swap(struct SYMBOL *a, struct SYMBOL *b) {
    struct SYMBOL temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
int right = 2 * idx + 2;
if (left < minHeap->size && minHeap->array[left].frequency < minHeap->array[smallest].frequency)
        smallest = left;
if (right < minHeap->size && minHeap->array[right].frequency < minHeap->array[smallest].frequency)
        smallest = right;
f (smallest != idx) {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}
struct MinHeap *createMinHeap(int capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct SYMBOL *)malloc(capacity * sizeof(struct SYMBOL));
    return minHeap;
}
void buildMinHeap(struct MinHeap *minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}
void insertMinHeap(struct MinHeap *minHeap, struct SYMBOL symbol) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && symbol.frequency < minHeap->array[(i - 1) / 2].frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = symbol;
}
struct SYMBOL extractMin(struct MinHeap *minHeap) {
    struct SYMBOL temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeapNode(struct MinHeap *minHeap, struct SYMBOL *left, struct SYMBOL *right) {
    struct SYMBOL temp;
    temp.alphabet = '-';
    temp.frequency = left->frequency + right->frequency;
    temp.left = left;
    temp.right = right;
    insertMinHeap(minHeap, temp);
}
void buildHuffmanTree(struct MinHeap *minHeap) {
    while (minHeap->size > 1) {
        struct SYMBOL *left = (struct SYMBOL *)malloc(sizeof(struct SYMBOL));
        struct SYMBOL *right = (struct SYMBOL *)malloc(sizeof(struct SYMBOL));
        *left = extractMin(minHeap);
        *right = extractMin(minHeap);
        insertMinHeapNode(minHeap, left, right);
    }
}
void printHuffmanTree(struct SYMBOL *root) {
    if (root) {
        if (root->alphabet != '-')
            printf("%c ", root->alphabet);
        printHuffmanTree(root->left);
        printHuffmanTree(root->right);
    }
}
int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
scanf("%d", &n);
struct SYMBOL symbols[n];
printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
}
printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
        symbols[i].left = NULL;
        symbols[i].right = NULL;
}
struct MinHeap *minHeap = createMinHeap(n);
    minHeap->size = n;
    minHeap->capacity = n;
minHeap->array = symbols;
buildMinHeap(minHeap);
buildHuffmanTree(minHeap);
printf("In-order traversal of the tree (Huffman): ");
printHuffmanTree(minHeap->array);
return 0;
}
