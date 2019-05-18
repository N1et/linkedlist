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
### Create list
```c 
struct No* list_create(const int n);
```
Make a new list, first element, with a __n__ value. And return element struct.

### Add elements 
```c 
void list_add_front(const int n, struct No** list);
```
Adds a new node, with __n__ value, in front of __list__


```c 
void list_add_back(const int n, struct No* list);
```
Adds a new node, with __n__ value, in back of __list__

### Get list lenght
```c 
size_t list_length(struct No* list);
```
return the a size_t value with __list__ size
# Others
```c 
int list_sum(struct No* list);
```
returns the sum of all elements of the __list__ 
```c 
struct No* list_node_at(const unsigned int index, struct No* list);
```
returns the element(__struct node__) of the __index__.

```c 
int list_get(const unsigned int index, struct No* list);
```
return the element number int(__struct node.number__) of the __index__.


