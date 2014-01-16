#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int main(int argc,char **argv){
	char *buffer=NULL;
	size_t len;
	dict_t *dictionary;
	dictionary = load_dict("random_words.txt");
	//printf("%d\n",dictionary->size);
	print_dict(dictionary->root);
	//getline(&buffer,&len,stdin);
	//printf("%s",buffer);
	//printf("%s",search(dictionary->root,buffer)->word);
	return 1;
}


