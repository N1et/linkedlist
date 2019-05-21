// declarations
#define bool _Bool
struct No;
struct No* list_create(const int n);
void list_add_front(const int n, struct No** list);
void list_add_back(const int n, struct No* list);
size_t list_length(struct No* list);
int list_sum(struct No* list);
struct No* list_node_at(const unsigned int index, struct No* list);
int list_get(const unsigned int index, struct No* list);
void list_free(struct No* list);
void foreach(struct No* list, void (*func)(int));
struct No* map(struct No* list, int (*func) (int) );
void map_mut(struct No* list, int (*func)(int));
int foldl(struct No* list, int a, int (*func)(int, int));
struct No* iterate(int s, size_t n, int (*func) (int));
bool save(struct No* list, const char* filename);
bool load(struct No** list, const char* filename);
bool serialize(struct No* list, const char* filename);
bool deserialize(struct No** list, const char* filename);
