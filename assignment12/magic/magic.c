#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
matrix for tests is taken from: https://www.dcode.fr/magic-square
*/


#define N 3 /* Dimension of matrix */
#define MAXOP 10 /* Number of digits in the largest int */


typedef struct matrix{
	int data;
	struct matrix *next_member;
} matrixGrid;


/*
	insert - gets a pointer to the head of the matrix and a data value to insert to the list. 
	(in this case the data is a simple integer).
	The function iterates over the list nodes untill it reaches the end of the list. 
	It then inserts the "data" passed to it, to the end of the list.
*/
void insert(matrixGrid * head, int data) {
	
	matrixGrid * current = head;

	while (current->next_member != NULL) {
		current = current->next_member;
	} /* end of while */


	/* now we can add a new variable */
	current->next_member = (matrixGrid *) malloc(sizeof(matrixGrid));
	current->next_member->data = data;
	current->next_member->next_member = NULL;
		
} /* end of inseret */


/*
	read_matrix reads user input.
	the main purpose is to get a full number from input.
	While numbers appear in a consecutive order ,read_matrix takes each char and puts it in an array.
	The array size is set to MAXOP . 
	Because the largest int is 2147483647, we only need an array of size 10.
	
	each "complete" array is a member in the matrix.
	The matrix is represented by a linked list.
	
	read_matrix makes checks to user input. it skips white spaces.
	Prints errors accordingly.

	retrurn -1 if not a number is entered.
	Otherwise, returns the total of members in matrix.
*/
/* read user input */
int read_matrix(matrixGrid *head){

	int counter = 0; /* counts total members in matrix as entered by user*/
	char number[MAXOP]; /* hold the int */
	int num, i, c, sign; 
	
	sign = 1; /* int of positive value */
	

	while ((c = getchar()) != EOF) {

		i = 0; 

		while (isspace(c) != 0) /* white space handling */
			c = getchar();

		if (c == '-'){ /* sign handling */
			if (sign == -1){
				counter = -1;
				return counter; /* error too many minus chars */
			}
			else
				sign = -1; /* int of negative value */	
			c = getchar();		
		}
		
		

		if (isdigit(c) != 0){ /* Argument is a numeric character. */
			number[i] = c;
			i++;

			while (isdigit(number[i] = c = getchar()))
				i++;

			number[i]='\0';
			num = atoi(number);
			
			if (sign == -1)
				num = (-1)*num;

			insert(head, num);
			counter++;
			sign = 1; /* back to positive */
		}
		
		if (isdigit(c) == 0) /* Argument is not a numeric character. */
			if (  ((c != ' ') && (c != '\t') && (c != '\n') && (c != EOF)) || (c == ' ' && sign == -1)   ){
				counter = -1;
				return counter;
			}
		
	}

	return counter;

} /* end of read_matrix */


/*
	The print_matrix function gets a pointer to the head of the matrix.
	It iterates over the list. 
	Prints the list as a grid of N*N.
*/
void print_matrix(matrixGrid * head) {
	
	int i;
	matrixGrid* current = head->next_member;

	i = 0;
	while (current != NULL) {
		
		if (i % N == 0)
			printf("\n");
		printf("%d\t", current->data);
        	current = current->next_member;
		++i;
		
	}
	printf("\n");

} /* end of print_matrix */


/*_______________________________

	Comparing functions
_________________________________*/

/*
	checkForMagic function gets a pointer to the head of the matrix. goes over the list. 
	It check if the memebers of the matrix are between 1 and N^2.	returns 0 if false.
	It checks if member appears more than once. returns 1 if false.
	returns 2 if all ok. 
*/ 
int checkForMagic(matrixGrid *head) {

	int member, i;
	matrixGrid * current = head->next_member;
	int magicIndicator = 2;
	int counterArr[N*N];
		
	for(i = 0; i < N*N; i++)		
		counterArr[i] = 0;

	
	while (current != NULL) {

		member = current->data;
		if (member < 1 || member > N*N){
			magicIndicator = 0;
			return magicIndicator;
		} 
		
		counterArr[member] = counterArr[member] + 1;
		current = current->next_member;
	}

	for(i = 0; i < N*N; i++){
		if (counterArr[i] > 1){
			magicIndicator = 1;
			return magicIndicator;
		}	
	}	

	return magicIndicator;

} /* end of checkForMagic */ 


/*
	checkRow function gets a pointer to the head of the matrix.
	The function sums every N members of the list.
	The sum of each row is kept in an array of size N.
	When its done going over the list, it compares every two values in the sum array.
	If all equal - return rowEqual = 0 : sum of all the rows is equal
	If checkrow found a different sum - return rowEqual = -1 : not all rows have the same sum.
*/
int checkRow(matrixGrid *head){
	
	matrixGrid* current = head;
	int sumArray[N];
	int sum = 0;
	int i, j;
	int rowEqual = 0;
	
	for (j = 0; j < N; j++){
		for(i = 0; i < N; i++){
			sum += current->next_member->data;
			current = current->next_member;
		}

		sumArray[j] = sum;
		sum = 0;
	}

	for(i = 0; i < N - 1; i++) {
		if(sumArray[i] != sumArray[i + 1])
			 rowEqual = -1;
	} /* end of for */
	
	return rowEqual;

} /* end of checkRows */


/*
	checkCol function gets a pointer to the head of the matrix.

	If the function is called, we can assume our grid is of size N*N .
	The function loops through the list N times. 
	Each time it sums the N-th member of the i-th position.

	For example, if our list is a 3*3 matrix (containing 9 values): { 1 2 3 4 5 6 7 8 9 }
	Then the sum of the first col is: 1 + 4 + 7
	The sum of the second cols  is 2 + 5 + 8 and so on.

	The sum of each column is kept in an array of size N.
	When its done going over the list, it compares every two values in the sum array.
	If all equal - return colEqual = 0 : sum of all the cols is equal
	If found a different sum - return colEqual = -1 : not all cols have the same sum.
*/
int checkCol(matrixGrid *head){

	matrixGrid* current = head->next_member;
	int sumArray[N];
	int sum = 0;
	int i, j, k;
	int colEqual = 0;

	for (j = 0; j < N ; j++){	
		for(i = 0; i < N - 1; i++){
			sum += current->data;
			for (k = 0; k < N; k++)
				current = current->next_member;
		}
		
		sum += current->data;
	
		sumArray[j] = sum;
		sum = 0;
		current = head->next_member;
		for(k = 0; k <= j; k++)
			current = current->next_member;
	}


	for(i = 0; i < N - 1; i++) {
		if(sumArray[i] != sumArray[i + 1])
			 colEqual = -1;
	} /* end of for */

	return colEqual;

} /* end of checkCols */


/*
	checkDiag function gets a pointer to the head of the matrix.
	It iterates though the list twice.

	If the function is called, we can assume our grid is of size N*N .
	main diagonal = first member of list + every N+1 member until end of list.
	secondary diag = (N)-th member + every (N-1)-th member; until end of list.

	The sum of each diagonal is kept in an array of size 2 (only two diagonals).
	When its done going over the list, it compares the two values in the sum array.
	If equal - return diagEqual = 0  sum of the diagonals is equal
	Else - return diagEqual = -1  diagonals are not of equal sum.
*/
int checkDiag(matrixGrid *head){

	matrixGrid* current = head->next_member;
	int sumArray[2];
	int sum = 0;
	int j, k;
	int diagEqual = 0;

	for (j = 0; j < N - 1 ; j++){
		sum += current->data;
		for (k = 0; k <= N; k++)
			current = current->next_member;
	}
		
	sum += current->data;
	sumArray[0] = sum;

	sum = 0;
	current = head->next_member;	

	for (j = 0; j < N ; j++){
		for (k = 0; k < N - 1; k++)
			current = current->next_member;
		sum += current->data;
	}

	sumArray[1] = sum;
	
	if (sumArray[0] != sumArray[1])
		diagEqual = -1;

	return diagEqual;

} /* end of checkDiag */


/*
	The program magic.c reads user input.
	User can choose size of matrix.
	It validates the matrix.
	Checks if (sum of rows of matrix == sum of cols of matrix == sum of both diagonals)
	returns proper error or validation of the matrix being a magic square.
	Prints the matrix in a pleasing to the eye manner.
*/
int main() 
{
	
	matrixGrid *root = NULL; /* head of list */
	int test;
	

	root = (matrixGrid *) malloc(sizeof(matrixGrid)); /* alocate memory to head */

	printf("Matrix dimension is set to: %d\n", N);
	printf("Please enter %d integer values.\nSeparate each value with spaces.\n%d integers for every line.\n%d lines in total.\n", N*N, N, N);

	test = read_matrix(root); /* start reading user input */

	if(test < 0) {
		printf("Error - the program has encountered a non numeric value .\nNot a magic square!\n");
		print_matrix(root);
	} /* end of if */

	if(test >= 0 && test < N*N) {
		printf("Error - Not enough values entered.\nNot a magic square!\n");
		print_matrix(root);
	} /* end of if */
		
	if(test > N*N) {
		printf("Error - too many values entered.\nNot a magic square!\n");
		print_matrix(root);
	} /* end of if */

	if(test == N*N) {
		if(checkForMagic(root) == 1){
			printf("Error - numbers appear more than once.\nNot a magic square!\n");
			print_matrix(root);
		}
		else if(checkForMagic(root) == 0){
			printf("Error - numbers out of bounds.\nNot a magic square!\n");
			print_matrix(root);
		}
		else if (checkDiag(root) == 0 && checkCol(root) == 0 && checkRow(root) == 0){
			printf("\nWOW COOL! The following matrix is a magic square!\n");
			print_matrix(root);
		} /* end of if */
		else {
			printf("\nOH SNAP! The following matrix is NOT magic square!\n");
			print_matrix(root);
		} /* end of else */
			
	} /* end of if */
	
	return 0;

}














































































































