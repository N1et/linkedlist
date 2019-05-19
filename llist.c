/* Exercício de lista ligada do livro Low Level programming 
 * Niet
 * 0.1v
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
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
void list_free(struct No* list){
	struct No* node;
	struct No* n_node;
	for(node=list; node!=NULL; node=n_node){
		//printf("free: %p - %d ", (void *) node, node->number);
		n_node = node->next;
		free(node);
		
	}
}
//others
// Executa a função *func em cada elemento da lista
void foreach(struct No* list, void (*func)(int)) {
	struct No* node;
	for(node=list; node != NULL ; node=node->next) 
		func(node->number);
}
// Retorna uma nova *lista com o resultado de *func aplicado aos elementos
// da lista original
struct No* map(struct No* list, int (*func) (int) ) {
	struct No* cpnode = list_create(0);
	struct No* node;
	struct No* renode;
	for(node=list; node != NULL ; node=node->next)
		list_add_back(func(node->number), cpnode);
	
	renode = cpnode->next;
	free(cpnode);
	return renode; 
}
// Altera os elementos da lista original pelo resultado da função *func aplicado 
// neles mesmos.
void map_mut(struct No* list, int (*func)(int)){
	struct No* node;
	for(node=list; node != NULL ; node=node->next)
		node->number = func(node->number);
}
// f(x,a) = x * a
int foldl(struct No* list, int a, int (*func)(int, int)){
	struct No* node;
	for(node=list; node != NULL; node=node->next)
		a = func(a, node->number);
	return a;
}
struct No* iterate(int s, size_t n, int (*func) (int) ) {
	struct No* nwl = list_create(s);
	size_t count;
	for(count=0; count<n; count++){
		s = func(s);
		list_add_back(s, nwl);
	}
	return nwl;
}
bool save(struct No* list, const char* filename){
	struct No* node;
	FILE *fd;
	fd = fopen(filename, "w");
	if( fd == NULL ) return false;	
	for(node=list; node != NULL ; node=node->next)
		fprintf(fd, "%d ", node->number);
	fclose(fd);
	return true;
}
bool load(struct No** list, const char* filename){
	FILE *fd;
	int element;
	fd = fopen(filename, "r");
	if( fd == NULL ) return false;
	while(1){
		fscanf(fd, "%d ", &element); 
		if( element == EOF) break;
		list_add_back(element, *list);
	}
	return true;
}
