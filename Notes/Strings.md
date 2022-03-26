# Strings

Strings

Stored in character arrays or dynamically allocated memory

- A string is a sequence of zero or more characters.
- **The sequence is terminated by a *NUL byte*.**
    
    *NUL byte → byte whose bits are all zero, used as a terminator*
    
- The length of a string is the number of characters it contains (*excludes NUL*).
- Most of string functions exists in `string.h`
- `strlen` computes the length of a string. Value that is returned is ***unsigned***
    
    *An unsigned integer is a 32-bit datum that encodes a nonnegative integer in the range [0 to 4294967295].*
    

```c
char *p = "Hello World!";
    while (*p) {
        printf("p = %12p, string at p = %s\n", p, p);
        p++;
    }

OUTPUT>>>
p =     0x400604, string at p = Hello World!
p =     0x400605, string at p = ello World!
p =     0x400606, string at p = llo World!
p =     0x400607, string at p = lo World!
p =     0x400608, string at p = o World!
p =     0x400609, string at p =  World!
p =     0x40060a, string at p = World!
p =     0x40060b, string at p = orld!
p =     0x40060c, string at p = rld!
p =     0x40060d, string at p = ld!
p =     0x40060e, string at p = d!
p =     0x40060f, string at p = !
```

## Reading Strings

For `char str[100];`

`str` can be read by the user in three ways:

1. `scanf`
2. `gets()`
3. `getchar(), getch() or getche()`

### `scanf()`

`scanf("%s", str);`

function terminates as soon as it finds a blank space

`%s` does not require the ampersand before the variable `str`

### `gets(str);`

The string inputted using `gets()` is automatically terminated with a null character.

### `getchar();`

used repeatedly to read a sequence of single characters (unless a terminating character is entered) and simultaneously storing it in a character array

```c
i = 0; 
ch = getchar; 
while (ch != '*')
{
		str[i] = ch;
		i++;
		ch = getchar();
}
str[i] = '\0';
```

## Writing Strings

Strings can be written by the user in three ways:

1. `printf()`
2. `puts()`
3. `putchar()`

### `printf()`

`char str[100];`

`printf("%s", str);`

`printf ("%5.3s", str);` *print only the first three characters in a total of five characters. (right justified)*

### `puts()`

`puts(str);`

`puts()` is a simple function that overcomes the drawbacks of the `printf()`

### `putchar()`

```c
i = 0;
while (str[i] != '\0')
{
		putchar(str[i]);
		i++;
}
```

# Character Arrays and Pointers

```c
char c1[6] = "Hello";
char* c2;
c2 = c1; /* this is valid: holds mem. address of first element in c1 */
c1 = c2; // not valid
c1 = c1 ++; // not valid because cannot increment char type
c2++; /* valid because incrementing memory address */
```

Version 1 and Version 2 are equivalent

```c
/*  version 1 */
void print(char C[])
{
    int i;
    while (C[i] != '\0')
    {
        printf("%c", C[i]);
        i++;
    }
    printf("\n");
}

/* version 2 */
void print(char *C)
{
    while (*C != '\0')
    {
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main() {
    char C[20] = "Hello";
    print(C);
}

```

```c
char *C = "Hello"; // string gets stored as compile time constant
C[0] = 'A'; // ERROR CANNOT MODIFY THE CONSTANT
print(C) /* function from prev */

```

## String Operations

### Length of a String

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() 
{
    char str[1000], i = 0, length; 
    printf("\n Enter the string : ");
    gets(str);
    while (str[i] != '\0')
    {
        i++;
    }    
    length = i;
    printf("\n The length of the string is : %d", length);
    getch();
    return 0;
}
```

### Convert Lower Case to Upper

```c
#include <stdio.h>

int main()
{
    char str[100], upper_str[100];
    int i = 0; 

    printf("Enter the string : ");
    gets(str);
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            upper_str[i] = str[i] - 32;
        }
        else
        {
            upper_str[i] = str[i];
        }
        i++;
    }

    upper_str[i] = '\0';
    printf("\nThe string converted into upper case is : \n");
    puts(upper_str);
    return 0;
}
/*-----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    int i = 0; 

    printf("Enter the string : ");
    char word[100];
    gets(word);
    char chr;

    printf("Output: ");
    while (word[i])
    {
        chr = word[i];
        printf("%c", toupper(chr));
				/* OR */
				putchar(toupper(chr));
        i++;
    }

    return 0;
}
```

### Appending String to Another String

```c
/* MANUAL WAY */
#include <stdio.h>

int main() {
    char s1[100], s2[100];
    // enter string 1
    printf("Enter string 1: ");
    gets(s1);

    //enter string 2
    printf("Enter string 2: ");
    gets(s2);

    int length, i;

    // store length of s1 in the length variable
    length = 0;
    while (s1[length] != '\0') {
        length++;
    }

    // concatenate s2 to s1
    for (i = 0; s2[i] != '\0'; i++, length++) {
        s1[length] = s2[i];
    }

    // terminating the s1 string
    s1[length] = '\0';

    printf("After concatenation: ");
    puts(s1);
}
/*----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    printf("First name: ");
    gets(s1);

    printf("Last name : ");
    gets(s2);

    strcat(s1, " ");
    strcat(s1, s2);

    printf("Concatenated : |%s|", s1);

    return 0;
}

OUTPUT
>>>
First name: Thanakon
Last name : Kimsan
Concatenated : |Thanakon Kimsan|
```

### Compare Two Strings

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20];
    char str2[20];
    int output;

    printf("String One: ");
    gets(str1);

    printf("String Two: ");
    gets(str2);

    output = strcmp(str1, str2);

    if (output < 0) {
        printf("str1 is less than str2");
    } 
    else if (output > 0) {
        printf("str2 is less than str1");
    }
    else {
        printf("str1 is equal to str2");
    }

    return 0;
}
```

### Reversing a String

```c
#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[20];
    printf("String: ");
    gets(str1);
    printf("str1 reverse is: %s", strrev(str1));
    return 0;
}
```