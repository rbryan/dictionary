#include <stdio.h>
#include <stdlib.h>
#include <gdsl.h>
#include "dictionary.h"

void help(){
	printf("p\t-\tPrint the current dictionary.\n");
	printf("a\t-\tAdd a word.\n");
	printf("s\t-\tSearch for a word.\n");
	printf("h\t-\tPrint this message.\n");
	getchar();
}

void search(gdsl_bstree_t dict){
	char *buffer=NULL;
	size_t len;
	gdsl_element_t result;
	getchar();
	printf("Input a word to search: ");
	getline(&buffer,&len,stdin);
	result = search_word(dict,buffer);
	if(result==NULL){
		printf("Could not find word: %s",buffer);
	}else{
		printf("That word is in the dictionary.\n");
	}
	//getchar();


}

void add(gdsl_bstree_t dict){
	char *buffer=NULL;
	size_t len;
	gdsl_constant_t result;
	getchar();//gets rid of the newline.
	printf("Input a word to add: ");
	getline(&buffer,&len,stdin);
	insert_word(dict,buffer,&result);
	if(result!=GDSL_INSERTED){
		printf("That word already exists in the dictionary.\n");
	}else{
		printf("Word added.\n");
	}
	//getchar();
	
}

void print(gdsl_bstree_t dict){
	print_tree(dict);
	getchar();
	
}

int main(int argc,char **argv){
	char input;
	gdsl_bstree_t dict;
	dict = init();	
	load_dictionary("random_words.txt",dict);

	while(1){
		printf("\nInput a command(h-help): ");
		input = getchar();
		switch(input){
			case('h'):
				help();
				break;
			case('s'):
				search(dict);
				break;
			case('a'):
				add(dict);
				break;
			case('p'):
				print(dict);
				break;
			default:
				printf("Invalid command.\n");
				break;

		}

	}
	return 1;
}


