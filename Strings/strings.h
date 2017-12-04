#define OK -2
#define ERROR -1
#define POLYNDROM 1
#define NOT_POLYNDROM 0



int reverseStr(char *str); /* Descriptionfunction that reverses string, example "Vadim" ==> "midaV"
										Input: A string
										Output: returns ERROR if str==NULL */
										
										
int isPolindrom(char *str); // function that checks if a string is a polindrom, return POLYNDROM, NOT_POLYNDROM and ERROR


int printBinary(size_t num); /* Description: function that prints binary representation of a number
										  Input: unsigned long inteer
										  Output: regular integer which looks like "110000101010100" */ 


int myatoi(char* str); /* 	Description: function that converts a string to an integer
									Input: String with number
									Output: Int with number */ 



char* myitoa(int value, char * str); /* Description: function that converts integer to a string
													 Input: Integer and buffer string
													 Output: String that contains integer */


char* myStrStr(char *s1, char *s2); /* Description: Finds the substring s2 inside s1
													Input: Two strings, NOT Const
													Output: Point to the start of string s1 inside s2 */
