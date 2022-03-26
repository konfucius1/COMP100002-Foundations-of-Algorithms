# Pointers

Pointers

[https://www.youtube.com/watch?v=zuegQmMdy8M](https://www.youtube.com/watch?v=zuegQmMdy8M)

God Tier Resource

> Pointers allow the efficient implementation of advanced data structures such as trees and lists.
> 

The values of variables are stored in the computer's memory, each at a particular location. Each memory location is identified and referenced with an *address*, just as the houses on a street can be located by their address. 

*Pointer* is just another name for an address; at *pointer variable* is a variable whose value is the address of some other memory location. 

<aside>
💡 If you need to modify a string, store it in an *array* instead

</aside>

# Benefits of Pointers

- Pointers allow passing of arrays and strings to functions more efficiently.
- Pointers make it possible to return more than one value from the function.
- Pointers reduce the length and complexity of a program.
- Pointers increase the processing speed.
- Pointers save the memory.

# Static variables

Allows functions to maintain state from one call to the next without that information being accessible outside the function. 

**For the love of god, do not mix this with recursive functions**

# Pointer Operations

Any **variable declared** in a program is **stored** in a location in the **computer's memory**. In order to **access** that variable, the hardware uses the **address** of that **location** *instead of the variable name.* 

- The compiler's job is to convert symbolic names into addresses in memory, so that variables can be accessed.
- Modern computers have around a billion of ***words*** of memory
    - each word can hold one `int` or `float` variable
    - `1 word == 4 or 8 bytes`
        - `1 bytes == 1 char` and `1 char == 8 bits`  //bit (binary digit) "0"/"1"
    - each byte in memory has an ***address***
        - we can visualise the computer memory as a long list of byte-sized boxes each with a number and can store a single character
    - Addresses count upward at the rate of one per byte
    - If `one int == 4 bytes` and `stored at address n`, next is stored at address `n+4`
    
    <aside>
    💡 A pointer variable stores the memory address of another variable.
    
    </aside>
    
    `"&" == "the address of"` → applied to variables and returns the location in memory that is currently allocated to that variable.
    
    pointer dereference operator "*"/unary operator → takes as its operand a pointer-valued expression.
    
    `"*" operator ⇒ "use this address to access the underlying variable stored at the indicated memory location"`
    
    ```c
    // proper **declaration** of a pointer
    int *x;
    
    // gives the **memory address** of integer variable x
    &x;
    
    // gives the **memory address of a variable pointed to by pointer** x
    x;
    
    // gives the **value stored at the address pointed to by pointer** x
    *a;
    ```
    
    # How to use pointers
    
    1. Define a pointer variable
    2. Assign address of a variable to a pointer
    3. Access the value at the address in the pointer variable
    
    ```c
    															**/* How to use pointers */**
    
    #include <stdio.h>
    
    int
    main()
    {
            int x = 20;     //  actual variable declaration
            int *ip;        //  pointer variable declaration (1)
    
            ip = &x;        // store address of x in pointer variable (2)
    
            printf("Address of x variable is: %x\n", &x); 
    
            // address stored in pointer variable
            printf("Address stored in ip variable: %x\n", ip);
    
            // access the value using the pointer 
            printf("Value of *ip variable: %d\n", *ip);
    
            return 0;
    }
    
    ------------------------------------------------------------------------------------
    Address of x variable is: 61ff18
    Address stored in ip variable: 61ff18
    Value of *ip variable: 20
    ```
    
    # Pointers in Detail
    
    - Pointer Arithmetic
        - `++`, `--`, `+`, `-`
    - Array of Pointers
        - Can define arrays to hold a number of pointers
    - Pointer to Pointer
    - Passing pointers to functions // Pointer perimeter
        - Passing an argument by reference or by address enable the passed argument to be changed in the calling function by the called function
    - Return pointer from functions
        - Function can return pointer to the local variable, static variable, and dynamically allocated memory
    
    # Pointers and Arrays
    
    ## One-Dimensional Array
    
    ![Untitled](Pointers%20fd949/Untitled.png)
    
    ```c
    int A[5]
    int *p = A; /* this points to the first element of the array */
    p -> 200
    *p -> 2
    *(p+2) -> 6
    
    p = A also works
    A = p wont
    
    THIS ALSO WORKS FOR
    print A // 200    | A = &A[0]
    print *A // 2     | *A = A[0]
    print *(A+2) // 6 | *(A+2) = A[2]
    
    because
    *(A+i) is same as A[i]
    (A+i) is same as &A[i]
    ```
    
    ## Two Dimensional Array
    
    ![Untitled](Pointers%20fd949/Untitled%201.png)
    
    ```c
    int B[2][3]
    B[0] and B[1] // 1-D arrays of 3 integers
    
    int *p = B; X
    		// this will return a pointer to 1-D array of 3 ints
    
    int (*p)[3] = B;
    
    print B or &B[0] -> 400
    print *B or B[0] or &B[0][0] -> 400
    print B+1 -> 400 + 3 ints of 4 = 412
    print *(B+1) or B[1] or &B[1][0] -> 412
    print *(B+1) + 2 or B[1]+2 or &B[1][2] -> 420
    print *(*B+1) // *(&B[0][1]) // *(404) // 3
    
    FOR 2-D ARRAYS
    B[i][j] = *(B[i]+j) = *(*(B+i)+j)
    
    int B[2][3] = {2,3,6,4,5,8};
        printf("%d\n", B);
        printf("%d\n", *B);
        printf("%d\n", B[0]);
        printf("%d\n", &B[0][0]);
        printf("%d\n", &B[0][3]);
    
        printf("\n");
        printf("%d\n", B[1]);
        printf("%d\n", &B[1][0]);
    ------------------------------------
    6422280
    6422280
    6422280
    6422280
    6422292
    
    6422292
    6422292
    ```
    
    ## Multi-Dimensional Arrays
    
    ```c
    int main()
    {
        int C[3][2][2] = {  {{2,5},{7,9}},
                            {{3,4},{6,1}},
                            {{0,8},{11,13}}};
        printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);
    
        printf("%d\n", *(C[0][0]+1)); // C[0][0][1]
        printf("%d\n", C[0][0][1]);
        return 0;
    }
    ```
    
    # Pointer Function
    
    ```c
    //pointer function
    int Add(int a, int b)
    {
        return a + b;
    }
    
    int main()
    {
        int a = 2, b = 3;
    
    		/* pointer to function */
        int (*p)(int, int);
        p = &Add;
    
        int sum = (*p)(a, b); // de-referencing and executing the function.
    		//or
    		int sum = p(a,b);
        printf("%d", sum);
    }
    ---------------------------------------------------------------------------------
    void PrintHello(char *name)
    {
        printf("Hello %s\n", name);
    }
    
    int main()
    {
        void (*ptr)(char*);
        ptr = PrintHello;
        ptr("Tom");
    }
    >>> Hello Tom
    ```