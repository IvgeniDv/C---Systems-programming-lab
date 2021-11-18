#include <stdio.h>

/* 
	Function checkBalance - checks for balanced brackets in an input.
	Returns 0 if NOT balanced.
	The function checks if the input is of type string, meaning - inside quotation marks.
	If so, it will go through the input until its out of the string.
	The function checks if the input is a comment (ANSI-C standard).
	If so, it will go through the input until its out of the comment.
	Comments may sprad multiple lines, thus the function gets an indictaor called "commentIndicator[]".
	commentIndicator[] = 0 if input is not in a comment.
	The function returns a variable called "balance" which hold the vlaues 0 if line is Not balnced and 1 if it is.
*/
int checkBalance(char str[], int commentIndicator[], int lim); 


/* 
	Function checkSpecial - check if a line is a special line as defined in maman 11 q2. 
	Returns 0 if NOT a special line.
	The function goes through the input to check if it meets the requirements.
	If the line IS special, an indicator called "special" is changed from 1 to 0 and returned.
*/
int checkSpecial(char str[], int curlyOpen[], int curlyClose[], int lim);  


/*
	str - hold user input.
	commentIndicator[] - an indicator if an input is inside a comment.
	lim - the limit of the length of an input.
	curlyOpen[] - holds the total number of opening curly brackets in special lines of all the input.
	curlyClose[] - holds the total number of closing curly brackets in special lines of all the input.
	Returns  0 if line is balanced. 1 if not.
*/
int inputTest(char str[], int commentIndicator[], int lim, int curlyOpen[], int curlyClose[]){
		
	printf("User input: %s\n", str);

	/* check if line is balanced */
	if ( (checkBalance(str, commentIndicator, lim)) != 0)
			printf("~This line is perfectly balanced.\n"); 
	else {
		/* if line is not balanced, check if its a special line */
		printf("~This line is NOT perfectly balanced.\n");
		if ( (checkSpecial(str, curlyOpen, curlyClose, lim)) != 0){
			if (curlyOpen[0] < curlyClose[0])
				return 1;
		} /* end of if */
		else	
			return 1;
	} /* end of else*/


	return 0;

} /* end of inputTest */








