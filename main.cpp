#include <iostream>

using namespace std;

void passByAddress(int* arr, int size) {
    arr[0] = 1;
    for(int i=0;i<size;++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void basicPointer() {
    int arr[2] = {0, 1};

    // pass by address
    // passByAddress(arr, 2);

    // get the 1st element of array
    // 1. use *p = arr
    int* p = arr;
    cout<<*p<<endl;
    cout<<*(p+1)<<endl;

    // 2. use p2 = &arr[0]
    int *p2 = &arr[0];
    cout<<*p2<<endl;

    // 1st element of array
    cout<<arr<<endl;
    // the entire address of array, means the 1st element address
    cout<<&arr<<endl;
}

void mallocAndFree() {
    size_t INT_LEN = 2;
    // malloc and free
    int* pointer = (int*) malloc(INT_LEN*sizeof(int));
    // use (p+i) to get into the next memory place
    *pointer = 0;
    *(pointer+1) = 1;
    for(int i=0;i<INT_LEN;++i) {
        cout<<*(pointer+i)<<" ";
    }
    cout<<endl;
    free(pointer);
}

void genericPointer() {
    int val = 10;
    // if system is 16 bits, the size of generic pointer is 2 bytes
    void* genericPointer = &val;
    cout<<*(static_cast<int*>(genericPointer))<<endl;
}

/*
 * https://www.codingninjas.com/studio/library/pointers-interview-questions
 *
 *
 * What is a dangling pointer in C?
    Ans: A pointer pointing to a non-existing memory location is a dangling pointer.
        A dangling pointer is a pointer that has a value (not NULL) which refers to
        some memory that is not valid or does not exists.
 */

void doublePointers() {
    // https://www.geeksforgeeks.org/cpp-pointer-to-pointer-double-pointer/
    // https://stackoverflow.com/questions/5580761/why-use-double-indirection-or-why-use-pointers-to-pointers
    /*
     * Why double pointers?
     * char character
     * char* word
     * char** sentence
     */
    int SIZE_OF_SENTENCE = 5;
    char** sentence = (char**) malloc(SIZE_OF_SENTENCE*sizeof(char*));
    char c = 'a';
    for(int i=0;i<SIZE_OF_SENTENCE;++i){
        sentence[i] = (char*) malloc(sizeof(char));
        *sentence[i] = c; // copy the value
        // dont know why "sentence[i] = &c" will print some unknown string
    }
    for(int i=0;i<SIZE_OF_SENTENCE;++i){
        cout<<sentence[i]<<" ";
    }
}

/*
 * https://www.geeksforgeeks.org/null-pointer-in-c/#:~:text=The%20Null%20Pointer%20is%20the,called%20a%20null%20pointer%20constant.
 * According to C11 standard: “An integer constant expression with the value 0,
 * or such an expression cast to type void *, is called a null pointer constant.
 *
 * NULL itself is a macro that is defined in #include<stdio.h> header files
 *  char *ptr = NULL;
    printf("%s",ptr);// compile error
    return 0;
 */

/*
void constPointer() {
    // https://www.codingninjas.com/studio/library/pointers-interview-questions
    const int p1; // constant int
    const int *p2; // pointer to constant int
    int * const p3; // constant pointer to integer
    int const * p4 const; // constant pointer to constant integer
}
 */

/*
 * 17. Where is the pointer variable stored in memory?
    Ans: Pointer variables are stored in stack memory.
 */

/*
 * int* arr[10] array of integer pointers
 */

void dereference() {
    int i = 10,*ptr; // ptr is int*
    ptr= &i; // ptr (int*) points to i
    void *vptr;
    vptr = &ptr; // vptr (void*) point to ptr (int*)
    // 1. cast to int**, because void* is pointing to int*
    // 2. now it is int**, then dereference to the value i (10) **(int**)
    printf("\nValue of iptr = %d ",  **(int **)vptr);
}

void addressDifference() {
    int a = 5,b = 10,c;
    int *p = &a,*q = &b;
    c = p-q;
    // c might be 1, it means p and q are stored in stack
    printf("%d, %d, %d",p, q, c);
}

/*
 * 28. State the equivalent pointer expression which refer the given array element arr[i][j][k][l]?
    Ans: Above pointer expression can be written as *(*(*(*(arr+i)+j)+k)+l).
 */


void generaicPointerOnString() {
    char *ptr = "void pointer";
    void *vptr;
    vptr = &ptr;
    printf("%s" , *(char **)vptr);
    cout<<endl;
    cout<<**(char **)vptr<<endl;
}

/*
void pointerCasting() {
    int a, b, c;
    char *p = 0;
    int *q = 0;
    double *r = 0;
    a = (int)(p + 1); // error: cast from pointer to smaller type 'int' loses information
    b = (int)(q + 1);
    c = (int)(r + 1);
    printf("%d %d  %d",a, b, c);
}
*/

void movePointer() {
    char *pcData="codingninjas";
    /*
     * Because a[b] means *(a+b)
     * so 6[pcData] means *(6+pcData)
     */
    printf("%c ",6[pcData]);
}

void pointerArray() {
    // This is not a correct way to malloc array of int pointers
    // int* a[1] = (int*) malloc(sizeof(int*)*1);

    // This is a correct way
    int** a = (int**) malloc(sizeof(int*)*1);
    int val = 10;
    // a is int**, so dereference first: *a is (int*)
    *a = &val;
    cout<<**a<<endl;

    int val1 = 1;
    int val2 = 2;
    /*
     *  int arr[2]; declares arr as an array of 2 integers.
        int *ptr; declares ptr as a pointer to an integer.
        So, int (*ptr)[2]; declares ptr as a pointer to an "array of 2 integers".
     */
    int (*ptr)[2];
    int arr[2] = {0, 1};
    ptr = &arr;
    cout<<(*ptr)[0]<<" "<<(*ptr)[1]<<endl;
}

int main() {
    pointerArray();
    return 0;
}
