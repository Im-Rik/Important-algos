#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void matrixChainOrder(int dims[], int n, int M[MAX_SIZE][MAX_SIZE], int S[MAX_SIZE][MAX_SIZE]) {
    int i, j, k, l, q;

    for (i = 1; i <= n; i++) {
        M[i][i] = 0; // Chain of length 1 has no cost
    }

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            M[i][j] = INT_MAX; // Initialize to a large value

            for (k = i; k < j; k++) {
                q = M[i][k] + M[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParentheses(int S[MAX_SIZE][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParentheses(S, i, S[i][j]);
        printOptimalParentheses(S, S[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i;
    int dims[MAX_SIZE];

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions of the matrices:\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }

    int M[MAX_SIZE][MAX_SIZE]; // Stores the minimum scalar multiplications
    int S[MAX_SIZE][MAX_SIZE]; // Stores the split position

    matrixChainOrder(dims, n, M, S);

    printf("Optimal Parenthesization: ");
    printOptimalParentheses(S, 1, n);

    printf("\nMinimum Scalar Multiplications: %d\n", M[1][n]);

    return 0;
}
