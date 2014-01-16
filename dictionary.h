
typedef struct word_t word_t;
struct word_t{
	char *word;
	word_t *left;
	word_t *right;
};

typedef struct dict_t dict_t;
struct dict_t{
	word_t *root;
	int size;
	
};
int add_word(dict_t *dict, word_t *word);
dict_t *load_dict(const char *filename);
void print_dict(word_t *root);
word_t *search(word_t *root, char *word);
