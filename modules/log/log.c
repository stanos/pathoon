#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>

#define TRY do { jmp_buf buf_state; if ( !setjmp(buf_state)) {
#define CATCH } else {
#define ENDTRY }} while(0)
#define THROW longjmp(buf_state, 1)

char* filepath;
bool is_file_opened;
FILE *fptr;
int lineIndex;
char fileText[10];
int ch;
int count=0;

int logfileInit(char* path) {
	filepath = path;
	TRY {
		fptr = fopen(path, "w+");
		is_file_opened = true;
	
		while ((ch=fgetc(fptr))!=EOF) {
			if(ch=='\n')  //counts number of lines
				count++;


		}		
		return 0;
	} CATCH {
		is_file_opened = false;
		printf("Error: Exception while opening file");
		return 1;
	} ENDTRY;
}

int print(char* content) {
	if (is_file_opened)	{
		
		return 0;
	} else {
		print("Error: File not openned succesful");
		return 1;
	}
}
