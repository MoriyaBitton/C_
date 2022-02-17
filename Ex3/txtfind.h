#pragma once

#define LINE 256
#define WORD 30
#define NUM_OF_LINES 250

int get_line(char s[]);
int getword(char w[]);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);
int get_word_from_line(char* line, char* dest);
