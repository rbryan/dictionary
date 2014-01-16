#include <stdio.h>
#include <stdlib.h>
#include <gdsl.h>
#include <string.h>

long int compare(const gdsl_element_t node, void *string);


gdsl_element_t insert_word(gdsl_bstree_t tree, const char *word, int *result){
	return gdsl_bstree_insert(tree,(void *)word,result);
}

gdsl_element_t search_word(gdsl_bstree_t tree, const char *word){
	return gdsl_bstree_search(tree,compare,(void *)word);	
}

gdsl_element_t new_word(void *word){
	return (void *)word;
}
static void print(const gdsl_element_t word,FILE *ignored_this, gdsl_location_t this_too, void *even_this){
	printf("%s",(char*)word);
}
void print_tree(gdsl_bstree_t tree){
	gdsl_bstree_write(tree,print,NULL,NULL);
}
void free_word(gdsl_element_t word){
	free((char *)word);

}

void load_dictionary(const char *filename,gdsl_bstree_t tree){
	FILE *f;
	char *word;
	size_t len;
	int fend;
	gdsl_constant_t status;

	f = fopen(filename,"r");
	fseek(f,0,SEEK_END);
	fend = ftell(f);
	rewind(f);
	while(ftell(f) < fend){
		word=NULL;
		getline(&word,&len,f);
		insert_word(tree,word,&status);
		if(status != GDSL_INSERTED) fprintf(stderr,"DOH! Could not insert word %s\n",word);

	}

}

long int compare(const gdsl_element_t node, void *string){
	int cmpr;
	char *node_val;
	char *string_val;

	node_val = (char *)node;
	string_val = (char *)string;

	cmpr = strcmp(string_val,node_val);
	return (long int) cmpr;

}

gdsl_bstree_t init(){
	gdsl_bstree_t new_tree;
	new_tree = gdsl_bstree_alloc("DICTIONARY", new_word, free_word, compare);

	return new_tree;

}
