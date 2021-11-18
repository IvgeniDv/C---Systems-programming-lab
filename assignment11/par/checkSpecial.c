

/*
	str - hold user input.
	curlyOpen[] - holds the total number of opening curly brackets in special lines of all the input.
	curlyClose[] - holds the total number of closing curly brackets in special lines of all the input.
	lim - the limit of the length of an input.
	Returns var named "special" = 0 if line is not special.
*/
int checkSpecial(char str[], int curlyOpen[], int curlyClose[], int lim) {

	int i, j ,k, l;
	int special = 1; /* indicator of special line. Will be changed to 0 if not special */ 

	i = j = k = l = 0;
	
	while( i < lim ){
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '{' || str[i] == '}' || str[i] == '\n' || str[i] == '\0'))
			++l;	
		if (str[i] == '{'){
			++j;
		}
		if(str[i] == '}'){
			++k;
		}
		++i;
	} /* end of while */

	if (l > 0)
		special = 0; /* not a special line - contains a different symbole than white chars or curly brakcets*/	
	if (j > 1) 
		special = 0; /* not a special line - to many curly brackets */	
	if (k > 1) 
		special = 0; /* not a special line - to many curly brackets */
	if ((j == k) && (j != 0))
		special = 0; /* not a special line - to many curly brackets */

	if (j == 1)
		++curlyOpen[0];
	if (k == 1)
		++curlyClose[0];
	
	return special;
} /* end of checkSpecial */
