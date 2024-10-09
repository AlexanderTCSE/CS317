//Alexander Tattersall
//CS317 - Professor Kabir
//RE to NFA Postfix Converter, C version
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nfa.h"
#include"stack.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage: RE2NFA <file>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Error opening file\n");
		return 1;
	}

	char line[256];
	while(fgets(line,sizeof(line),fp)){
		printf("Postfix RE: %s\n",line);
	}

	fclose(fp);

	return 0;
}
