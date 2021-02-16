
//DO THE COMPILOR KNOW ALL THESE FUNCTIONS INSIDE HERE?
#ifndef STRING_MORSE_CONVERSION_H
// ELSE THE COMPILOR WILL LOOK AT THE VARIUOS FUNCTIONS
#define STRING_MORSE_CONVERSION_H

// THIS FUNCTION CONVERTS A  STRING  INTO  MORSE  CODES
char** convert_string_morse(char***, int, char*, int);

// THIS FUNCTION DIVIDES A LINE INTO A LETTER AND MORSE
char** extract_letter_morse(char*);

// THIS  FUNCTION   EXTRACTS   THE   FILE   INFORMATION
char** extract_file_information(char*, int, int);

// THIS FUNCTION TRIMS THE STRING CHARS FROM THE STRING
char* remove_outer_characters(char*, int);

// THIS  FUNCTION  OUTPUTS  AN  ARRAY  OF  MORSE  CODES
int output_morse_string(char**, int);

// THIS FUNCTION CONVERTS A  CHARACTER  TO  MORSE  CODE
char* convert_character_morse(char***, int, char);

// THIS FUNCTION DIVIDES  A  STRING  INTO  MORSE  CODES
char** extract_morse_string(char*, int);

// THIS FUNCTION CONVERTS MORSE CODE INTO  A  CHARACTER
char convert_morse_character(char***, int, char*);

// THIS FUNCTION COUNTS THE AMOUNT OF  DIFFERENT  CODES
int string_morse_amount(char**);

// THIS FUNCTION GENERATES A TABLE OF LETTERS AND MORSE
char*** generate_morse_table(char*, int, int);

// THIS FUNCTION  CONERTS  MORSE  CODE  INTO  A  STRING
char* convert_morse_string(char***, int, char**, int);

#endif // NOW THE COMPILOR IS DONE LOOKING AT FUNCTIONS
