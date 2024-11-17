#include <stdio.h>
#include <stdbool.h>

// Function Prototypes
bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos);
void insert_element(int arr[], int length, int pos, int value);
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]);
void print_array(const int arr[], int length);
void print_matrix(const int mat[][3], int nRows);

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int length = 10;

    // 1D to 2D reshaping variables
    int arr2d[4][3];

    // Testing print_array
    printf("Original Array:\n");
    print_array(arr, length);

    // Testing remove_element
    printf("\nRemoving element at index 2:\n");
    remove_element(arr, length, 2);
    print_array(arr, length - 1);

    // Testing insert_element
    printf("\nInserting value 25 at index 2:\n");
    insert_element(arr, length, 2, 25);
    print_array(arr, length);

    // Testing reshape
    printf("\nReshaping array into 2D (4x3):\n");
    reshape(arr, 12, 4, 3, arr2d); // Reshape with first 12 elements
    print_matrix(arr2d, 4);

    return 0;
}

// Function Definitions

// 1. Check if an index is valid
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

// 2. Remove an element
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid index %d.\n", pos);
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Element removed at index %d.\n", pos);
}

// 3. Insert an element
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid index %d.\n", pos);
        return;
    }
    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    printf("Element %d inserted at index %d.\n", value, pos);
}

// 4. Reshape a 1D array into a 2D array (column-major order)
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Size mismatch: Cannot reshape array.\n");
        return;
    }
    for (int i = 0, index = 0; i < nCols; i++) {
        for (int j = 0; j < nRows; j++) {
            arr2d[j][i] = arr[index++];
        }
    }
    printf("Array reshaped into %dx%d.\n", nRows, nCols);
}

// Print a 1D array
void print_array(const int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Print a 2D matrix
void print_matrix(const int mat[][3], int nRows) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
