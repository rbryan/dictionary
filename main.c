#include <stdio.h>
#include <stdlib.h>
#include <gdsl.h>
#include "dictionary.h"

int main(int argc,char **argv){
	gdsl_constant_t result;
	gdsl_bstree_t dictionary;
	dictionary = init();	
	insert_word(dictionary,"test",(int *)&result);
	if((result == GDSL_INSERTED)) printf("inserted\n");
	search_word(dictionary,"test");
	return 1;
}


