# LINKED LIST
Leason from Low Level Programming book.<br>
_Singly Linked List. A linked list is a way to store a collection of elements. Like an array these can be character or integers. Each element in a linked list is stored in the form of a node._
Make functions to create, add and remove nodes from linked list

## Node Structure
```C
struct No 
{ // Node
    int number;
    struct No* next; // next node
};
```
Each node have this structure, __number integer__, and the __address of next node__.
## Functions
# LINKED LIST
Leason from Low Level Programming book.<br>
_Singly Linked List. A linked list is a way to store a collection of elements. Like an array these can be character or integers. Each element in a linked list is stored in the form of a node._
Make functions to create, add and remove nodes from linked list

## Node Structure
```C
struct No 
{ // Node
    int number;
    struct No* next; // next node
};
```
Each node have this structure, __number integer__, and the __address of next node__.
## Functions

| functions                                                           | descriptions                                                                                                                                                  |
|---------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
|` struct No* list_create(const int n);  `                              | Create a list with n and return a pointer                                                                                                                     |
| `void list_add_front(const int n, struct No** list); `                | add the n element in front of list                                                                                                                            |
| `void list_add_back(const int n, struct No* list);`                   | add the n element in back of list                                                                                                                             |
| `size_t list_length(struct No* list);`                                | return list length                                                                                                                                            |
| `int list_sum(struct No* list);`                                      | return the sum of all element                                                                                                                                 |
| `struct No* list_node_at(const unsigned int index, struct No* list);` | return a node of index.                                                                                                                                       |
| `int list_get(const unsigned int index, struct No* list);`            |  return a element of index                                                                                                                                    |
| `void list_free(struct No* list);`                                    | remove a list / free memory of list and all it's element                                                                                                      |
| `void foreach(struct No* list, void (*func)(int)); `                  | executes void func(int) in each element of a list. This has no effect on the original list.                                                                   |
| `struct No* map(struct No* list, int (*func) (int) );  `              |  returns a copy of the list with the result of the function executed to the elements                                                                          |
| `void map_mut(struct No* list, int (*func)(int)); `                   | Executes int func(int) in each element of a list. **This has effect on the original list**                                                                    |
| `int foldl(struct No* list, int a, int (*func)(int, int));`           |  Executes func(element, a) and store in **a**. a - acumulator.                                                                                                |
| `struct No* iterate(int s, size_t n, int (*func) (int));  `           | Get a **n**(size of list), integer **s** and a function int func(int). So, makes a new list like this:   [s, func(s), func(func(s)), func(func(func(s))) ...] |
| `bool save(struct No* list, const char* filename); `                  | Saves all elements of a list to a file in text mode.                                                                                                          |
| `bool load(struct No** list, const char* filename);`                  | Loads all elements of a list from file in text mode.                                                                                                          |
| `bool serialize(struct No* list, const char* filename); `             | Saves all elements of a list to a file in binary mode.                                                                                                        |
| `bool deserialize(struct No** list, const char* filename);`           | Loads all elements of a list from file in binary mode.                                                                                                        |

## Compiler
    gcc version 8.3.0 (GCC
## License
 This project is licensed under the [GPL 3](https://choosealicense.com/licenses/agpl-3.0/) License.
