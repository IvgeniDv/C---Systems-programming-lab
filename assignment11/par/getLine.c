#include <stdio.h>



/*
	str - hold user input.
	lim - the limit of the length of an input.
	Returns var named "endOfFile" = 0 if input is EOF.
*/
int getLine(char str[], int lim) {
	
	int i, c;
	int endOfFile = 1; /* EOF indicator. Will be changed to 0 if  EOF*/ 
	
	/* initialize the array */
	for (i = 0; i < lim; ++i) {
		str[i] = 0;
	} /* end of for */	

	i = 0;
	
	while( (i < lim) && ((c = getchar()) != EOF) && (c != '\n') ) {
		str[i] = c;
		++i;
	} /* end of while */

	++i;
	str[i] = '\0';
	
	if (c == EOF)
		endOfFile = 0;
	
	return endOfFile;
} /* end of getLine */

