#include <gdsl.h>

gdsl_bstree_t init();

gdsl_element_t new_word(void *word);

gdsl_element_t insert_word(gdsl_bstree_t tree, const char *word, int *result);

gdsl_element_t search_word(gdsl_bstree_t tree, const char *word);

void load_dictionary(const char *filename,gdsl_bstree_t tree);
void print_tree(gdsl_bstree_t tree);

