#include <stdio.h>

/*
	curlyOpen[] - holds the total number of opening curly brackets in special lines of all the input.
	curlyClose[] - holds the total number of closing curly brackets in special lines of all the input.
	balance - indication of total balance of the input.
	Returns nothing. prints a summary.
*/
void summarize(int curlyOpen[], int curlyClose[], int balance) {

	printf("\n~~~~~~~~~~~~~~~~~\n");
	printf("Input Summery:\n");
	if (curlyClose[0] != curlyOpen[0])
		printf("Input NOT balanced\n");
	else if (balance != 0)
		printf("Input NOT balanced\n");
	else
		printf("Input perfectly balanced. As all things should be.\n");
} /* end of summarize */
