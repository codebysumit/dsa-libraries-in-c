## LINKEDLIST - A Generic Singly Linked List Library in C
#### Overview 🚀
The **LinkedList** library (`linkedlist.h` / `linkedlist.c`) provides a **generic**, **type-safe**, and **lightweight** implementation of a **singly linked list** in pure C.  
It allows developers to store and manipulate data of any type (integers, floats, structs, etc.) using `void*` pointers — making it ideal for reusable data structure handling.

Designed for educational clarity and real-world usability, the library provides functions for **list creation**, **insertion**, **deletion**, **length retrieval**, and **printing** with user-defined callbacks.

---

#### Features ✨
* **Generic Data Handling:** Store any data type using `void*` and customizable data size.
* **Dynamic Memory Management:** Automatic memory allocation and deallocation.
* **Flexible Insertion:** Insert nodes at the front, end, or any index.
* **Safe Deletion:** Remove nodes individually or free the entire list safely.
* **User-Defined Printing:** Print any data type using user-provided print functions.
* **Portable and Lightweight:** No external dependencies — just standard C.

---

### Installation 🛠️

Follow these steps to compile the **LinkedList** library into a static `.a` library and link it with your C projects.

#### 1. Download the Library Files 📥
Download both `linkedlist.h` and `linkedlist.c` from the official repository (or your local version):
- linkedlist.h
- linkedlist.c


Make sure they are in the same directory.

---

#### 2. Compile the Source Code ⚙️

Run the following command to compile the library source file into an object file:

```bash
gcc -c linkedlist.c
```
This generates a compiled object file named `linkedlist.o`.

#### 3. Create the Static Library 📦

Use the `ar` tool to create a static library:

```bash
ar rcs liblinkedlist.a linkedlist.o
```
This will create a static library named `liblinkedlist.a`.

#### 4. Organize File Structure 🗂️

You can use the following recommended structure:
```bash
.
├── include/
│   └── linkedlist.h
├── lib/
│   └── liblinkedlist.a
└── your_application.c
```

Move the header to `include/` and the static library to `lib/`.

---

#### 5. Compile Your Application 💻

Use GCC (or any C compiler) to compile your project and link it with the LinkedList library:

```bash
gcc -I./include -L./lib your_application.c -o your_application -llinkedlist
```

**Flags Explained:**

* `-I./include` → Path to header files
* `-L./lib` → Path to static libraries
* `-llinkedlist` → Links `liblinkedlist.a`
* `-o your_application` → Output executable name

---

### Usage 💡

Once installed, include the header in your project:

```c
#include "linkedlist.h"
#include <stdio.h>
```

You can now create and manipulate linked lists generically.

---

## 📘 Function Reference

Below is a complete reference of all public functions in the library.

---

### 🧱 `sllist* sllist_create(size_t data_size)`

**Description:**
Initializes a new singly linked list that can store elements of any data type.

**Parameters:**

* `data_size` → Size (in bytes) of the data each node will store.

**Returns:**
A pointer to the new list, or `NULL` if memory allocation fails.

**Example:**

```c
sllist* list = sllist_create(sizeof(int));
if (!list) {
    printf("Memory allocation failed!\n");
    return 1;
}
```

---

### 🔼 `void insert_front(sllist* list, void* data)`

**Description:**
Inserts a new node at the beginning of the list.

**Parameters:**

* `list` → Pointer to the list.
* `data` → Pointer to the data to be stored.

**Example:**

```c
int x = 42;
insert_front(list, &x);
insert_front(list, &(int){99});
```

---

### 🔽 `void insert_end(sllist* list, void* data)`

**Description:**
Inserts a new node at the end of the list.

**Example:**

```c
int a = 10, b = 20;
insert_end(list, &a);
insert_end(list, &b);
```

---

### 🔢 `void insert_at_index(sllist* list, void* data, size_t index)`

**Description:**
Inserts a new node at the specified position (0-based index).

**Example:**

```c
insert_at_index(list, &(int){30}, 0); // Insert at front
insert_at_index(list, &(int){40}, 1); // Insert at index 1
insert_at_index(list, &(int){50}, sll_len(list)); // Insert at end
```

---

### 🗑️ `void free_sllist(sllist* list)`

**Description:**
Frees all nodes and the list structure itself.

**Example:**

```c
free_sllist(list);
```

---

### ⛔ `void free_at_front(sllist* list)`

**Description:**
Removes and frees the node at the front of the list.

**Example:**

```c
free_at_front(list);
```

---

### 🧨 `void free_at_end(sllist* list)`

**Description:**
Removes and frees the node at the end of the list.

**Example:**

```c
free_at_end(list);
```

---

### ⚙️ `void free_at_index(sllist* list, size_t index)`

**Description:**
Removes and frees the node at the specified index.

**Example:**

```c
free_at_index(list, 2); // Remove node at index 2
free_at_index(list, 0); // Remove front node
```

---

### 📏 `size_t sll_len(sllist* list)`

**Description:**
Returns the number of nodes in the list.

**Example:**

```c
printf("Length: %zu\n", sll_len(list));
```

---

### 🖨️ `void print_sllist(sllist* list, void (*print_func)(void*))`

**Description:**
Prints the contents of the list using a user-provided print function.

**Example:**

```c
void print_int(void* data) {
    printf("%d -> ", *(int*)data);
}

print_sllist(list, print_int);
```

---

## 🧩 Full Example Program

```c
#include "linkedlist.h"
#include <stdio.h>

void print_int(void* data) {
    printf("%d -> ", *(int*)data);
}

int main() {
    sllist* my_list = sllist_create(sizeof(int));

    insert_end(my_list, &(int){5});
    insert_end(my_list, &(int){10});
    insert_end(my_list, &(int){15});

    printf("Initial List:\n");
    print_sllist(my_list, print_int);

    insert_at_index(my_list, &(int){20}, 3);
    insert_at_index(my_list, &(int){25}, 0);

    printf("\nAfter Insertions:\n");
    print_sllist(my_list, print_int);

    printf("\nLength of list: %zu\n", sll_len(my_list));

    free_at_index(my_list, 2);
    printf("\nAfter Deletion at index 2:\n");
    print_sllist(my_list, print_int);

    free_sllist(my_list);
    return 0;
}
```

**Sample Output:**

```
Initial List:
5 -> 10 -> 15 -> NULL

After Insertions:
25 -> 5 -> 10 -> 15 -> 20 -> NULL

Length of list: 5

After Deletion at index 2:
25 -> 5 -> 15 -> 20 -> NULL
```

---

### Memory Management 💾

All nodes and data are dynamically allocated.
Always call `free_sllist()` to release memory when done.

```c
sllist* list = sllist_create(sizeof(int));
insert_end(list, &(int){100});
free_sllist(list);
```

---

### License 📜

This project is licensed under the MIT License.

---

### Contributing 🤝

Contributions, bug reports, and suggestions are welcome!
Submit pull requests or issues on the project repository.

---

### Contact 📬

* Project Maintainer 👨‍💻: **Sumit Das**
* Email ✉️: [codebysumit@gmail.com](mailto:codebysumit@gmail.com)
