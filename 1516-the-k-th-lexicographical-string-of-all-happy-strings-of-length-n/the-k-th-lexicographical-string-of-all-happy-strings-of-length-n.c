#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Backtracking to generate happy strings
void backtrack(int n, int pos, char* current, char** result, int* count, int maxResults) {
    if (pos == n) {
        current[n] = '\0';
        if (*count < maxResults) {
            result[*count] = strdup(current);
            (*count)++;
        }
        return;
    }

    for (char ch = 'a'; ch <= 'c'; ++ch) {
        if (pos == 0 || current[pos - 1] != ch) {
            current[pos] = ch;
            backtrack(n, pos + 1, current, result, count, maxResults);
        }
    }
}

// Main function to return the k-th happy string
char* getHappyString(int n, int k) {
    if (n == 0) return strdup("");

    // Correct number of happy strings: 3 * 2^(n-1)
    int pow2 = 1;
    for (int i = 1; i < n; ++i) pow2 *= 2;
    int maxResults = 3 * pow2;

    char** result = (char**)malloc(maxResults * sizeof(char*));
    char* current = (char*)malloc((n + 1) * sizeof(char));
    int count = 0;

    backtrack(n, 0, current, result, &count, maxResults);

    // Sort results lexicographically
    qsort(result, count, sizeof(char*), cmp);

    char* output;
    if (k <= count) {
        output = strdup(result[k - 1]);
    } else {
        output = strdup(""); // Return empty string if k is too large
    }

    // Cleanup
    for (int i = 0; i < count; ++i) free(result[i]);
    free(result);
    free(current);

    return output;
}


