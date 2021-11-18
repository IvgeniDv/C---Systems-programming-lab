
/*
	str - hold user input.
	commentIndicator[] - an indicator if an input is inside a comment.
	lim - the limit of the length of an input.
	Returns var named "balance" = 0 if line is out of balance.
*/
int checkBalance(char str[], int commentIndicator[], int lim) {
	
	
	int i, j;
	int balance = 1; /* 0 = not balanced line*/
	int inString = 0; /* indication if  inside quotation marks. 0 = not in string*/
	char brackets[100]; /* will hold all brackets that not in a comment or a string. up to 100 characters.*/

	 /* initializing the array */
    	for (i = 0; i < lim; ++i) {
        	brackets[i] = 0;
    	} /* end of for */

	i = j = 0;

	while (i < lim){
		
		/* if not already in a comment, check if input starts with a comment.  */
		if (commentIndicator[0] == 0) {
			if ( (str[i] == '/') && (str[i +1] == '*')){
				commentIndicator[0] = 1;
				++i; /*  str[i] = '*'  */
				++i; /* move to the start of the actual comment */
			} /* end of if */
		} /* end of if */
		
			
		
		/* if in a comment use while loop to end of input or until out of comment */
		if (commentIndicator != 0) {
			while( (commentIndicator[0] != 0) && (i < lim) ) {
				if( (str[i] == '*') && (str[i + 1] == '/') ) {
					commentIndicator[0] = 0;
					++i; /*  str[i] = '/'  */
					++i;
				} /*end of if */
				else
					++i;	
			} /* end of while */
		} /* end of if */

		/* check if in a string, and if so, use the while loop to get out */
		if (str[i] == '"'){
			inString = 1;
			++i;
			while (inString != 0) {
				if (str[i] != '"')
					++i;
				else{
					++i;
					inString = 0;
				} /* end of else */
			} /* end  of while */
		} /* end of if */	
		
		
		
		/* the following if statments use the array brackets[] as a stack.
			adding opening brakets when met and removing them if met the same closing bracket*/
       		if (str[i] == '{' || str[i] == '[' || str[i] == '('){
            		brackets[j] = str[i];
            		++j;
        	} /* end of if */
        
       		if (str[i] == '}') {
           		if (j > 0  && brackets[j - 1] == '{' ) 
               			brackets[--j] = 0;
           		else
           	     		balance = 0;
       		} /* end of if */
       
		if (str[i] == ')') {
			if (j > 0  && brackets[j - 1] == '(' ) 
				brackets[--j] = 0;
			else
				balance = 0;
		} /* end of if */
		       
		if (str[i] == ']') {
			if (j > 0  && brackets[j - 1] == '[' ) 
			       brackets[--j] = 0;
			else
				balance = 0;
		} /* end of if */
		
		++i;			
	} /* end of while */
	
	/* if at the end of the process there are brackets left in the array - the line was not balanced */
	for (i = 0; i < lim; ++i) {
      		if (brackets[i] != 0)
        		balance = 0;
   	} /* end of for */


	return balance;
} /* end of checkBalance */
