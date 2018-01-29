/*
Project 0
Jake Bedard
Carroll
CS570
Due Date: 1/25/18

This functions purpose is to read from standard input and place one word
from the input stream into the memory location w, which is taken as an
argument. This function then returns the number of characters in that word.

Possible return values:
 -10 if the word is a newline ('\n') and nothing else
 -1 if the word is '#' and nothing else
 0 if the word is EOF and nothing else
 else, an integer equating to the number of chars in the word at memory location w
  
*/

#include "getword.h"

int getword(char *w){
	int input;
	int word_size = 0;

	/*
	While there are still chars in the input stream,
	loop through the input and get the next char	
	*/
	while((input = getchar()) != EOF){
		/*
		If there is a '#' at the beginning of the word
		then add the '#' and end the word.	
		*/
		if(input == '#' && word_size == 0){
			*w = input;
			w++;
			*w = '\0';
			return -1;
		}
		/*
		Checking to see if char is a spacebar	
		*/
		if(input == ' '){
			/*if spacebar isn't starting a word, end the word*/
			if(word_size != 0){
				*w = '\0';
				return word_size;
			}
		/*only enter below conditions if not a spacebar
		  if it's a newline, replace newline with end word.		
		*/
		}else if(input == '\n'){
			*w = '\0';
			/*Check to see if \n is alone (not ending a word)*/
			if(word_size == 0)
				return -10;
			/*if ending a word, put \n back on the input stream
			  and return the word size. \n needs to be put back 
			  on the input stream because in this program it needs
			  to be treated as a word and return -10.
			*/
			else{	
				ungetc('\n',stdin);
				return word_size;
			}
		/*If this case is reached, that means it is a normal char.
		  add the char to the string.
		*/		
		}else {
			*w = input;
			w++;
			word_size++;
			*w = '\0';
			
		}

	}
/*EOF has been reached*/
	*w = '\0';
	return word_size;
}

