#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

dict_t * new_dict(){
	dict_t *new;
	new = malloc(sizeof(dict_t));
	new->size = 0;
	new->root = NULL;
	return new;
}

word_t *new_word(char *word){
	word_t *new;

	if((new = malloc(sizeof(word_t)))==NULL){
		fprintf(stderr,"OUT OF MEM.\n");

	}

	new->word = word;
	new->left = NULL;
	new->right = NULL;
	
	return new;
}
void print_dict(word_t *root){
	if(root->right != NULL){
		print_dict(root->left);
	}	
	if(root->left != NULL){
		print_dict(root->right);
	}
	printf("%s\n",root->word);

}

dict_t *load_dict(const char *filename){
	dict_t *new;
	char *buffer;
	FILE *f;
	size_t len;
	int fend;
	word_t *temp_word;

	f = fopen(filename,"r");
	fseek(f,0,SEEK_END);
	fend = ftell(f);
	rewind(f);
	

	new = new_dict();
	
	while(ftell(f) < fend){
		buffer = NULL;
		getline(&buffer,&len,f);
		temp_word = new_word(buffer);
		if(new->root == NULL){
			new->root = temp_word;
		}else{
			add_word(new,temp_word);
		}
		new->size++;
		
	}

	return new;
}
word_t *search(word_t *root, char *word){
	word_t *pass;
	printf("%s%s",root->word,word);
	if(root->left != NULL){
		pass = search(root->left,word);
		if(pass != NULL){
			return pass;
		}
	}else if(root->right != NULL){
		pass = search(root->right,word);
		if(pass != NULL){
			return pass;
		}
	
	}else if(strcmp(root->word,word)==0){
		return root;
	}
	
	return NULL;
	

}
int add_word(dict_t *dict, word_t *word){
	word_t *current = dict->root;
	int cmp;

	while(1){
		cmp = strcmp(current->word,word->word);
		if(cmp > 0){
			if(current->left==NULL){
				current->left = word;
				return 1;
			}else{
				current = current->left;
			}
		}else if(cmp < 0){
			if(current->right==NULL){
				current->right = word;
				return 1;
			}else{
				current = current->right;
			}
		}else{
			return 0;
		}

	}
	
}
