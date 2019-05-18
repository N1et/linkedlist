// declarations
struct No;

struct No* list_create(const int n);
void list_add_front(const int n, struct No** list);
void list_add_back(const int n, struct No* list);
size_t list_length(struct No* list);
int list_sum(struct No* list);
struct No* list_node_at(const unsigned int index, struct No* list);
int list_get(const unsigned int index, struct No* list);


