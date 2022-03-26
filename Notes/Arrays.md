# Arrays

Arrays

C does not have run time array bounds checking 

```c
Address - &A[i] or (A+i)
Value   - A[i]  or *(A+i)
```

```c
/* Storing arrays when you don't know the quantity */
int A[1000];
int size = 0;

while (scanf("%d", &A[size]) == 1)
{
		size++;
}

or

int num, i;
while (scanf("%d", &num) == 1)
{
		A{i] = num;
		i++;
}
```

## Arrays as function arguments

Arrays are not interpreted as arrays but pointers

```c
void printSize(int A[]) // takes starting address of the array as pointer (int* A)
{
    int size = sizeof(A)/sizeof(A[0]);
    printf("%d", size);
}

int main() 
{
    int A[] = {1,2,3,4,5};
    printSize(A);
    return 0;
}

OUTPUT
>>> 1
---------------------------------------------------------------
void printSize(int A[], int size)
{
    printf("%d", size);
}

int main() 
{
    int A[] = {1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);

    printSize(A, size);
    return 0;
}

OUTPUT
>>> 5
```