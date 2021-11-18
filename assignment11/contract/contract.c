#include <stdio.h>
#include <ctype.h>



#define SIZE 81 /* max size of strings is 80 + '\0' */

/*	
	The program gets a string - s1. 
	Returns a string - s2 in a shortened version using the function contract.
	Every maximal sequence of alphanumeric chars in s1 will be shotened to 3 chars:
	starting char, a hyphen and the ending char. non alphanumeric chars will be untouched.
*/


/* 
	The function contract gets two arrays of type char.
	The function then proceeds to go over the first array of chars - s1.
	Non alphanumeric chars will be untouched and copied "as is" to the new array - s2.
	Every maximal sequence of alphanumeric chars in s1 will be shotened to 3 chars:
	starting char, a hyphen and the ending char.
	A sequence of 1 or 2 alphanumeric chars will also be untouched and copied "as is".
*/
void contract(char s1[], char s2[]);



int main(){

	char str1[SIZE], str2[SIZE]; /* The arrays that will be used to hold user input */
	int i;
	
	/* Initializing the arrays */
	for (i = 0; i < SIZE; ++i){
		str1[i] = 0;
		str2[i] = 0;
	}
		

	printf("Please input a string of up to 80 characters\n");

	fgets(str1, SIZE, stdin);
	contract(str1, str2);
	
	printf("\nYour original input line is:\n%s\n", str1);
	printf("The new contracted line is:\n%s\n", str2);


	return 0;
} /* end of main */



void contract(char s1[], char s2[]){

	int i, j = 0;	

	for (i = 0; s1[i] != '\0'; ++i){  /* Go over the input of the user */ 
		
		/* Copy the char from user input to new output
		 it's the starting char of the contracted alphanumeric sequence or a non alphanumeric char*/ 
		s2[j] = s1[i];  
		

		/* condition: is it an alphanumeric char? */
		if ( (isalpha(s1[i])) || (isdigit(s1[i])) ) {  

			/* condition: is the next char is a consecutive alphanumeric char?*/
			if ( ( (isalpha(s1[i + 1])) || (isdigit(s1[i + 1])))  && (s1[i + 1] == (s2[j] + 1)) ){ 

				/* condition: is the second next char is a consecutive alphanumeric char?*/
				if (((isalpha(s1[i + 2])) || (isdigit(s1[i + 2])))  && (s1[i + 2] == (s2[j] + 2))) {

					s2[++j] = '-'; /* add the hyphen */

					/* while it's not the end of user input and it's a consecutive alphanumeric char */
					while ( (s1[i + 1] != '\0') && (s1[i + 1] == (s1[i] + 1)) && ( (isalpha(s1[i + 1])) || (isdigit(s1[i + 1])) ) ){
						++i;  /* advnace forward on user input - the actuall act of contraction  */
					} /* end of while*/

					/* copy the ending alphanumeric char of the contraction */
					s2[++j] = s1[i]; 
					++j;
				} /* end of if */
				else
					++j;
			} /* end of if */
			else
				++j;
		} /* end of if */
		else
			++j;

			
	} /* end of for */
	
	/* end the new output string */	
	s2[j] = '\0';

} /* end of contruct */




























