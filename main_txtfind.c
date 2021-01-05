#include <stdio.h>
#include "txtfind.h"

int main() { 
	char word[WORD] = {};
	getword(word);
	char option = getchar();
	if(option == 'a') { //print all lines with "word" 
		print_lines(word);
	} else if(option == 'b') { //print all similar words to "word"
		print_similar_words(word);
	} else {
		printf("I can't recognize this char, try again \n");
	}
	
	return 0;
}
