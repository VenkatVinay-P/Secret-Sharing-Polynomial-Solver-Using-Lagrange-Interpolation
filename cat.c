#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert a number from a given base to decimal
long long baseToDecimal(const char *value, int base) {
    long long decimalValue = 0;
    int len = strlen(value);
    for (int i = 0; i < len; i++) {
        int digit;
        if (value[i] >= '0' && value[i] <= '9') {
            digit = value[i] - '0';
        } else if (value[i] >= 'a' && value[i] <= 'f') {
            digit = value[i] - 'a' + 10;
        } else if (value[i] >= 'A' && value[i] <= 'F') {
            digit = value[i] - 'A' + 10;
        } else {
            fprintf(stderr, "Invalid character in value: %c\n", value[i]);
            exit(EXIT_FAILURE);
        }

        if (digit >= base) {
            fprintf(stderr, "Invalid digit %c for base %d\n", value[i], base);
            exit(EXIT_FAILURE);
        }
        decimalValue = decimalValue * base + digit;
    }
    return decimalValue;
}

// Function to calculate Lagrange interpolation and find the constant term
double lagrangeInterpolation(int x[], long long y[], int k) {
    double result = 0;
    for (int i = 0; i < k; i++) {
        double term = y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Test Case 1 data
    int x1[] = {1, 2, 3, 6};  // x values
    char *values1[] = {"4", "111", "12", "213"};  // y values in various bases
    int bases1[] = {10, 2, 10, 4};  // The bases of the y values
    int n1 = 4;  // Number of points provided
    int k1 = 3;  // Minimum points needed to solve the polynomial
    long long y1[n1];

    // Decode the y values for test case 1
    for (int i = 0; i < n1; i++) {
        y1[i] = baseToDecimal(values1[i], bases1[i]);
        printf("Decoded y1[%d] = %lld\n", i, y1[i]);
    }

    // Find the constant term (c) for test case 1
    double secret1 = lagrangeInterpolation(x1, y1, k1);
    printf("Test Case 1 - The constant term (c) is: %.0f\n\n", secret1);

    // Test Case 2 data
    int x2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // x values
    char *values2[] = {
        "13444211440455345511", "aed7015a346d63", "6aeeb69631c227c", "e1b5e05623d881f",
        "316034514573652620673", "2122212201122002221120200210011020220200",
        "20120221122211000100210021102001201112121", "20220554335330240002224253",
        "45153788322a1255483", "1101613130313526312514143"
    };
    int bases2[] = {6, 15, 15, 16, 8, 3, 3, 6, 12, 7};  // The bases of the y values
    int n2 = 10;  // Number of points provided
    int k2 = 7;  // Minimum points needed to solve the polynomial
    long long y2[n2];

    // Decode the y values for test case 2
    for (int i = 0; i < n2; i++) {
        y2[i] = baseToDecimal(values2[i], bases2[i]);
        printf("Decoded y2[%d] = %lld\n", i, y2[i]);
    }

    // Find the constant term (c) for test case 2
    double secret2 = lagrangeInterpolation(x2, y2, k2);
    printf("Test Case 2 - The constant term (c) is: %.0f\n", secret2);

    return 0;
}
