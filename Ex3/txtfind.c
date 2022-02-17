#include <stdio.h>

#include "txtfind.h"

// The function receives a string (character after character) 
// which input a standard and saves it in a string s. 
// The function returns the amount of characters actually absorbed.
int get_line(char s[]){
	int i;
	// gerchar - get char from the beginning 
	for(i = 0; i < LINE; i++){
		fflush(NULL);
		if((s[i] = getchar())=='\n'){
			//s[i]=0;
			break;
		}
	}
	return i+1;
}

// The function receives a string (character after character) 
// which is the input standard and stores it in the string w. 
// The function returns the amount of characters actually absorbed.
int getword(char w[]){
	int i;
	// gerchar - get char from the beginning 

	for(i = 0; i < WORD; i++){
		if((w[i] = getchar()) == '\n' || w[i] == ' ' || w[i] == '\t' || w[i] == '\r'){
			w[i] = 0;
			break;
		}
	}
	return i+1;
}

// The function gets two str1 and str2 strings 
// and checks if str2 is contained in str1.
// str1[i] is equvalent to *(str1 + i1)
int substring( char * str1, char * str2){

	for(int i1 = 0; str1[i1] !=0; i1++){
		int i2 = 0;
		for (i2 = 0; str2[i2] != 0 && str1[i1 + i2] !=0 && str2[i2] == str1[i1 + i2]; i2++);
		if (str2[i2] == 0) {
			return 1;
		} 
	
	}
	return 0;
}

// The function will get two strings t s and a number n. 
// The function will check if it is possible to get from the 
// string S to the string t by omitting n characters.
int similar (char *s, char *t, int n){
	
	int counter = 0;
	int i = 0;
	for(i = 0; t[i] != 0; i++){
		while(s[i + counter] != t[i] && counter <= n && s[i + counter] != 0){
			counter ++;
		}
		if(counter > n || s[i + counter] == 0){
			return 0;
		}
	}
	
	while(s[i + counter] != 0 && counter <= n){
		counter ++;
	}
			
	return (counter <= n && s[i + counter] == 0); // 1- true; 0- false
}

// The function gets the desired string for the search, 
// picks up the lines of text, and prints the lines in them appears
void print_lines(char * str){

	char arr[NUM_OF_LINES][LINE];
	int row = 0;
	for (row = 0; row < NUM_OF_LINES && get_line(arr[row]) != 1; row ++); // make sure that all printed right

	// Here, row contains the number of lines inserted
	for (int row_i = 0; row_i < row; row_i++) {
		if (substring(arr[row_i], str)) {
			printf("%s", arr[row_i]);
		}
	}
}

// Copies a word from line + index to dest returns its length
int get_word_from_line(char* line, char* dest){

	int i;
	for (i = 0; i < WORD; i++) {
		if (line[i] == 0 || line[i] == '\n' || line[i] == ' ' || line[i] == '\t' || line[i] == '\r') {
			break;
		}
		dest[i] = line[i];
	}
	dest[i] = 0;
	
	return i;
}

// The function gets the desired string for the search, 
// picks up the text words and prints the words similar 
// to a string The search to the point of omitting one 
// letter from the words that appear in the text, 
// includes the same words as the string the search.
void print_similar_words(char * str){

	char arr[NUM_OF_LINES][LINE] = {{0}};
	int row = 0;
	for (row = 0; row < NUM_OF_LINES; row ++){ //make sure that all printed right
		if(get_line(arr[row]) == 1){
			break;
		}
	}
	
	// Here, row contains the number of lines inserted
	for (int row_i = 0; row_i < row; row_i++) {
		int char_i = 0;
		while(char_i < LINE && arr[row_i][char_i] != 0) {
			char word[WORD] = {0};
			int word_len = get_word_from_line((char*)arr[row_i] + char_i, word);
			if (similar(word, str, 1)) {
				printf("%s\n", word);
			} 
			if(word_len == 0){
				break;
			}
			char_i += word_len + 1;
		}	
	}
}

