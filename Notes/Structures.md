# Structures

Structures

---

# Why structures?

Simple terms, we can create data structures within data structures (imagine a box within a box *unboxing a MacBook Pro*).

# What is a struct?

It's a collection of values of different types. Arrays are limited to one type so in cases where we want to pack character and integer arrays together we can use structures. 

# Basic Code Snippet

```c
int main()
{
    typedef struct 
    {
        int age;
        char *name;
    } PERSON;

    PERSON thanakon = {19, "Thanakon"};
		
		/* how to modify after declaring */
		thanakon.age = 21;    

    printf("Name: %s\nAge : %d", thanakon.name, thanakon.age);
		
    return 0;
}
OUTPUT
Name: Thanakon
Age : 19
```

```c
#define N 3

typedef struct {
		char *title;
		char *author;
		int year;
		int pages;
		double price;
		int checked_out;
} book_t;

typedef struct {
		book_t books[N];
		char *name;
} trilogy_t

double get_trilogy_price(trilogy_t trilogy) {
		int i, totalPrice = 0;
		for (i = 0; i < N; i++) {
				totalPrice += trilogy.books[i].price;
		}
		return tot_price;
}

book_t checkout(book_t book) {
		book.checked_out = 1;
		return book;
}

//using pointers to pass around structs
void checkoutPtr(book_t* book) {
		(*book).checked_out = 1;
		book->checked_out = 1;
}

trilogy_t* create_trilogy_ptr() {
		trilogy_t* trilogy;
		trilogy = (trilogy_t*)malloc(sizeof(trilogy_t));
		assert(trilogy);
		trilogy->name = "Harry Potter";
		trilogy->books[0].title = "The philosopher's stone";
		trilogy->books[0].author = "J.K Rowling";
		trilogy->books[1].title = "The cursed child";
		trilogy->books[1].author = "J.K Rowling";
		trilogy->books[2].title = "Prisoner of Dadada";
		trilogy->books[2].author = "J.K Rowling";
		return trilogy;
}

//initialize a struct
trilogy_t create_trilogy() {
		trilogy_t trilogy;
		trilogy.name = "Harry Potter";
		trilogy.books[0].title = "The philosopher's stone";
		trilogy.books[0].author = "J.K Rowling";
		trilogy.books[1].title = "The cursed child";
		trilogy.books[1].author = "J.K Rowling";
		trilogy.books[2].title = "Prisoner of Dadada";
		trilogy.books[2].author = "J.K Rowling";
		return trilogy;
}
```

![Untitled](Structures%20b096f/Untitled.png)