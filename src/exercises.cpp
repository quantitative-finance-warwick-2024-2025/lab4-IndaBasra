#include <iostream>
#include <array>
#include <vector>

/*
day_to_name takes an integer as a parameter and returns the day of the week
corresponding to that number.
For example: day 1 is Monday, day 7 is Sunday.

Write the return statement to complete the day_to_name function.
*/
std::string day_to_name(int day_number)
{
    const std::string invalid = "Invalid number";
    const std::array<std::string, 7> days =
        {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"};

    return day_number >= 1 && day_number <= 7 ? days[day_number - 1] : invalid;
}

/*
Implement the function swap(int* x, int* y), which copies the value of
x to the value of y and the value of y to the value of x.

Use print_swap to check your implementation.
*/
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_swap()
{
    int x = 123, y = 456;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    swap(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';
}

/*
Implement the function swap_in_place(int* x, int* y), which performs the same
operation as swap(), but does not declare any new variables to achieve this.

Use print_swap_in_place to check your implementation.
*/
void swap_in_place(int *x, int *y)
{
    *x = *x ^ *y;  // Step 1: x now holds x XOR y
    *y = *x ^ *y;  // Step 2: y is now (x XOR y) XOR y, which is the original value of x
    *x = *x ^ *y;  // Step 3: x is now (x XOR y) XOR x (the original y value)
}

// Function to test swap_in_place
void print_swap_in_place()
{
    int x = 123, y = 456;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    swap_in_place(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';
}

/*
Implement the function add_vector(int* a, int* b, int* result, int size), which performs
vector addition on two arrays 'a' and 'b' of a given size. The result should be stored in
the 'result' array.

Use print_add_vector to check your implementation.
*/
// Function to perform element-wise addition of two arrays
void add_vector(int *a, int *b, int *result, int size)
{
    // Loop through each element up to the specified size
    for (int i = 0; i < size; ++i)
    {
        result[i] = a[i] + b[i]; // Add corresponding elements from 'a' and 'b' and store in 'result'
    }
}

// Function to test the add_vector function
void print_add_vector()
{
    std::array<int, 4> a = {1, 2, 3, 4}; // Initialize array 'a' with four elements
    std::array<int, 4> b = {5, 6, 7, 8}; // Initialize array 'b' with four elements
    int result[4];                        // Declare an array to store the result
    int size = 4;                         // Set the size of the arrays

    // Call add_vector with pointers to 'a' and 'b' arrays, and store the result in 'result' array
    add_vector(a.data(), b.data(), result, size);

    // Print the resulting array after addition
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << ' '; // Print each element in 'result', expected output: 6, 8, 10, 12
    }
    std::cout << '\n'; // Print newline for formatting
}

/*
Implement the function swap_vector(int** a, int** b), which swaps the contents of vectors
which are pointed at by the parameters a and b.

Hint: you do not need to copy/swap every single value in the vectors.

Use print_swap_vector to check your implementation.
*/
void swap_vector(int **a, int **b)
{
    int *temp = *a; // Store the address pointed to by 'a' in a temporary pointer
    *a = *b;        // Set 'a' to point to the address pointed to by 'b'
    *b = temp;      // Set 'b' to point to the original address of 'a' (stored in temp)
}

// Function to test the swap_vector function
void print_swap_vector()
{
    std::array<int, 4> a = {1, 2, 3, 4}; // Initialize array 'a' with four elements
    std::array<int, 4> b = {5, 6, 7, 8}; // Initialize array 'b' with four elements

    int *pa = a.data(); // Obtain a pointer to the first element of array 'a'
    int *pb = b.data(); // Obtain a pointer to the first element of array 'b'

    swap_vector(&pa, &pb); // Swap pointers 'pa' and 'pb' using swap_vector

    // Print the elements of 'pa' after the swap (should print elements of 'b')
    for (int i = 0; i < 4; ++i)
    {
        std::cout << pa[i] << ' '; // Expected output: 5 6 7 8
    }
    std::cout << '\n';

    // Print the elements of 'pb' after the swap (should print elements of 'a')
    for (int i = 0; i < 4; ++i)
    {
        std::cout << pb[i] << ' '; // Expected output: 1 2 3 4
    }
    std::cout << '\n';
}

/*
Implement the function matrix_multiplication(int* a, int* b, int a_cols, int b_cols, int* result),
which multiplies two matrices 'a' and 'b' and stores the result in the 'result' matrix.
It should work for matrices of any dimension where a_cols == b_rows.
a, b and c are all correctly sized before calling the function

Note: 
result[i * b_cols + j] is the element at the ith row and jth column of the result matrix.
result_i_j = sum(a_i_k * b_k_j) for k = 0 to k = b_rows - 1
*/
void matrix_multiplication(int *a, int *b, size_t a_rows, size_t a_cols, size_t b_cols, int *result)
{
    // Iterate over each row in the result matrix
    for (size_t i = 0; i < a_rows; ++i)
    {
        // Iterate over each column in the result matrix
        for (size_t j = 0; j < b_cols; ++j)
        {
            // Initialize the result cell to 0
            result[i * b_cols + j] = 0;

            // Calculate the value of result[i * b_cols + j]
            for (size_t k = 0; k < a_cols; ++k)
            {
                result[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j];
            }
        }
    }
}

// Function to test the matrix_multiplication function
void print_matrix_multiplication()
{
    size_t a_cols = 2, b_cols = 2;                  // Set the number of columns for matrices a and b
    std::vector<int> a = {1, 2, 3, 4};              // Matrix 'a' with 2x2 elements
    std::vector<int> b = {5, 6, 7, 8};              // Matrix 'b' with 2x2 elements
    size_t a_rows = a.size() / a_cols;              // Calculate the number of rows in 'a'
    std::vector<int> result(a_rows * b_cols);       // Initialize the result matrix

    // Perform matrix multiplication and store the result in 'result'
    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());

    // Print the result matrix
    for (size_t i = 0; i < a_rows; ++i)
    {
        for (size_t j = 0; j < b_cols; ++j)
        {
            std::cout << result[i * b_cols + j] << ' '; // Print each element in the result matrix
        }
        std::cout << '\n';
    }
}