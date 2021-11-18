#include <stdio.h>

#define SIZE 100 /* The max length of a line */


/* 
	Function getLine - reads an input to a variable named str. Returns 0 if EOF.
	getLine runs a while loop until '\n' or EOF is detected.
	If EOF is detected, an indicator named "endOfFile" is changed from 1 to 0 and returned.
*/
int getLine(char str[], int lim); 

/* 
	Function summarize - prints a summery of all the input. 
	If curlyOpen[0] != curlyClose[0] - meaning special lines are out of balance.
	If balance indicator != 0 - meaning a regular input line is Not balanced  
	The function doesnt return anything. it just prints a summary.
*/
void summarize(int curlyOpen[], int curlyClose[], int balance); 

/*
	Function inputTest - prints user input. prints a message if the line of input is balanced or not.
	The function returns 0 if line is balanced. 1 if not.
	This function uses the functions "checkBalance" and "checkSpecial" to check for a balanced line and for a special line.
*/
int inputTest(char str[], int commentIndicator[], int lim, int curlyOpen[], int curlyClose[]);

/*
	The program "par" reads user input.
	It checks for balanced brackets in an input.
	The program can identify strings and multiple line comments.
	It can also identify curly brackets spreading on multiple lines.
	par returns a summery of evry line stating if it's balanced or not and a complete summary of al the input at the end.
*/
int main() {

	char str[SIZE]; /* holds user input */
	int c;
	int balance = 0; /* balanced line indicator. 0 = balanced */
	int commentIndicator[1]; /* used to indicate if input is a comment. 0 = not in comment */
	int curlyOpen[1], curlyClose[1]; /* used to check balance of special lines*/ 
	
	commentIndicator[0] = curlyOpen[0] = curlyClose[0] =  0;


	
	printf("Input your text.\nBe advised, Strings must end on the same line; Comments must be in ANSI-C standard.\nTo finish input use EOF.\n");
	
	/* read lines while not EOF*/
	while ((c = getLine(str, SIZE)) > 0){

		/* check if line is balanced */
		balance += inputTest(str, commentIndicator, SIZE, curlyOpen, curlyClose);

	} /* end of while */
	
	/* used to check the last input befor EOF is met */
	balance += inputTest(str, commentIndicator, SIZE, curlyOpen, curlyClose);


	/* summarize al input */
	summarize(curlyOpen, curlyClose, balance);
	
	return 0;
} /* end of main */




































