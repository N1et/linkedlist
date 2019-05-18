/* Exercício de lista ligada do livro Low Level programming 
 * Niet
 * 0.1v
*/

#include <stdio.h>
#include <malloc.h>
#include "llist.h"

// Estrutura padrão do node.
struct No 
{ // Node
    int number;
    struct No* next; // Node seguinte
};


struct No* list_create(const int n){
    struct No* newl;
    newl = malloc( sizeof(struct No) );
    newl->number = n;
    newl->next = NULL;
    
    return newl;
    
}

// Adiciona um elemento em primeiro lugar
void list_add_front(const int n, struct No** list){
    struct No* newl;
    newl = list_create(n);
    
    newl->next = *list;
    *list = newl;
    
    
}

// adiciona um elemento em ultimo lugar
void list_add_back(const int n, struct No* list){
    struct No* newl;
    size_t lsize;
    struct No* last_l;
    newl = list_create(n);
    
    lsize = list_length(list);
    last_l = list_node_at(lsize-1, list); // retorna o ultimo elemento
    
    last_l->next = newl;
    
}

// Retorna um size_t com o tamanho total de elementos da lista passado
size_t list_length(struct No* list) {
        size_t lsize;
        struct No *node;
        for(node=list, lsize=0; node != NULL; node=node->next, lsize++);
        return lsize;
}

//Soma todos os elementos da lista passada
int list_sum(struct No* list){
    struct No *node;
    int sum = 0;
    for(node=list; node != NULL ; node=node->next)
        sum += node->number;
    return sum;
        
}

// retorna o node pelo seu indice na lista
struct No* list_node_at(const unsigned int index, struct No* list){
    size_t length, lsize;
    struct No* node;
    length = list_length(list);
    if(index >= length)
        return NULL;
    
    for(node=list, lsize=0; lsize<index; node=node->next, lsize++);
        
    return node;
}

// retorna o elemento(node.number) pelo seu indice
int list_get(const unsigned int index, struct No* list){
    struct No* node;
    int r_number;
    node = list_node_at(index, list);
    if(node == NULL)
        return 0;
    r_number = node->number;
    return r_number;
	}

//end
