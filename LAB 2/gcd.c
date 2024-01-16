#include <stdio.h>
#include <stdlib.h>
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        return 1;
}
FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
}
int num1, num2;
    while (fscanf(inputFile, "%d %d", &num1, &num2) != EOF) {
        int gcd = findGCD(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, gcd);
}
fclose(inputFile);
fclose(outputFile);
return 0;
}