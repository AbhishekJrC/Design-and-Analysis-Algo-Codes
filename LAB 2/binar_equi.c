#include <stdio.h>
#include <stdlib.h>
void decToBinary(int n, FILE *outputFile) {
    if (n > 1) {
        decToBinary(n / 2, outputFile);
    }
    fprintf(outputFile, "%d", n % 2);
}
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number_of_decimals> <input_file_name> <output_file_name>\n", argv[0]);
        return 1;
}
int numberOfDecimals = atoi(argv[1]);
FILE *inputFile = fopen(argv[2], "r");
FILE *outputFile = fopen(argv[3], "w");
if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
}
int decimal;
    for (int i = 0; i < numberOfDecimals; i++) {
        fscanf(inputFile, "%d", &decimal);
        fprintf(outputFile, "The binary equivalent of %d is ", decimal);
        decToBinary(decimal, outputFile);
        fprintf(outputFile, "\n");
}
fclose(inputFile);
fclose(outputFile);
return 0;
}