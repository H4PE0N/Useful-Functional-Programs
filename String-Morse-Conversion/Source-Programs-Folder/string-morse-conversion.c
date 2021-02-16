
// INCLUDES ALL PACKAGES AND LIBRARIES FOR THIS PROGRAM
// THIS LIBRARY CONTAINS THE BASIC FUNCTIONS LIKE PRINT
#include <stdio.h>
// THIS LIBRARY CONTAINS
#include <stdlib.h>
//THE LIBRARY CONTAINS FUNCTIONS THAT HELP WITH STRINGS
#include <string.h>
// THIS LIBRARY CONTAINS THE SIZE  OF  EVERY  DATA-TYPE
#include <limits.h>
// THIS LIBRARY CONTAINS THE FALSE AND THE TRUE OBJECTS
#include <stdbool.h>

// INCLUDING THE HEADER FILE  FOR  THIS  EXACT  PROGRAM
#include "string-morse-conversion.h"

// THIS IS THE MAIN FUNCTION THAT IS GOING  TO  BE  RAN
int main(int arg_length, char* arguments[])
{
  // CREATING SOME VARIABLES FOR DEALING WITH THE TABLE
  char* file_name = "Source-Programs-Folder/\
morse-code-table.csv";
  const int file_lines = 53, line_size = 200;
  // THIS IS THE TABLE WITH ALL MORSE CODES AND LETTERS
  char*** morse_table = generate_morse_table(file_name,
    file_lines, line_size);
  // CHECKS IF THE ACTION IS "morse", IF IT CAN BE DONE
  if(arg_length >= 3 && !strcmp(arguments[1], "morse"))
  {
    // THIS IS THE VARIABLES NEEDED FOR THIS  OPERATION
    char*string=arguments[2];int length=strlen(string);
    // THIS IS THE CONVERTED MORSE CODE FROM THE STRING
    printf("STRING: %s LENGTH: %d\n", string, length);
    char** morse_code=convert_string_morse(morse_table,
      file_lines, string, length);
    // THIS FUNCTION OUTPUTS THE CODES FROM  THE  ARRAY
    int output=output_morse_string(morse_code, length);
  }
  //CHECKS IF THE ACTION IS "string", IF IT CAN BE DONE
  if(arg_length >= 3 && !strcmp(arguments[1],"string"))
  {
    // THIS IS THE ARRAY  OF  MORSE  CODES  TO  CONVERT
    char**morse_code=extract_morse_string(arguments[2],
      strlen(arguments[2]));
    // THIS IS THE  AMOUNT  OF  DIFFERENT  MORSE  CODES
    int length = string_morse_amount(morse_code);
    //THIS IS THE CONVERTED STRING FROM THE MORSE CODES
    char* string = convert_morse_string(morse_table,
      file_lines, morse_code, length);
    printf("%s\n", string); // PRINTS  OUT  THE  STRING
  }
  return false;// THE FUNCTION RETURNS FALSE AT THE END
}

// THIS FUNCTION COUNTS THE AMOUNT OF  DIFFERENT  CODES
int string_morse_amount(char** morse_code)
{
  int morse_amount = 0; // VARIABLE TO COUNT CODES WITH
  // LOOPS THROGH UNTIL THE MORSE CODE DOES  NOT  EXIST
  while(*(morse_code + morse_amount) != NULL)
    // INCREASES THE AMOUNT OF MORSE CODES  EVERY  LOOP
    morse_amount = (morse_amount + 1);
  return morse_amount; // RETURNS THE AMOUNT  OF  CODES
}

// THIS FUNCTION DIVIDES  A  STRING  INTO  MORSE  CODES
char** extract_morse_string(char* string, int length)
{
  // CREATING AN ARRAY TO STORE THE MORSE CODES  INSIDE
  char** morse_code = malloc(sizeof(char*) * INT_MAX);
  // THIS IS THE FIRST MORSE CODE IN THE INUTTED STRING
  char* current_code = strtok(string, " ");
  int morse_amount = 0; // CREATING  COUNTER   VARIABLE
  while(current_code != NULL)//UNTIL CODE DOESN'T EXIST
  {
    *(morse_code + morse_amount) = current_code;
    // INCREASES THE AMOUNT OF MORSE CODES  EVERY  LOOP
    morse_amount = (morse_amount + 1);
    current_code = strtok(NULL, " ");//NEW CURRENT CODE
  }
  return morse_code; // RETURNS ALL OF THE MORSE  CODES
}

// THIS  FUNCTION  OUTPUTS  AN  ARRAY  OF  MORSE  CODES
int output_morse_string(char** morse_string,int length)
{
  // ITERATING THROUGH ALL THE CODES IN THE MORSE ARRAY
  for(int index = 0; index < length; index = index + 1)
    // PRINTING OUT THE CURRENT MORSE CODE IN THE ARRAY
    printf("%s ", *(morse_string+index)); printf("\n");
}

// THIS FUNCTION  CONERTS  MORSE  CODE  INTO  A  STRING
char* convert_morse_string(char*** table, int lines,
  char** morse, int length)
{
  // CREATING VARIABLE TO STORE THE CONVERTED STRING IN
  char* string = malloc(sizeof(char) * length);
  // ITERATING THROUGH ALL CHARS IN THE INPUTTED STRING
  for(int index = 0; index < length; index = index + 1)
  {
    // THIS IS THE CURRENT MORSE CODE IN THE CODE ARRAY
    char* current_morse = *(morse + index);
    // THIS IS THE MATCHING LETTER FOR THE CURRENT CODE
    char character=convert_morse_character(table,lines,
      current_morse);
    // ADDING THE CHARACTER  TO  THE  CONVERTED  STRING
    *(string + index) = character;
  }
  return string; // RETURNING THE CONVERTED CHAR STRING
}

// THIS FUNCTION CONVERTS A  STRING  INTO  MORSE  CODES
char** convert_string_morse(char*** table, int lines,
  char* string, int length)
{
  // CREATING VARIABLE  TO  STORE  THE  MORSE  CODE  IN
  char** morse_code = malloc(sizeof(char*) * length);
  // ITERATING THROUGH THE  CHARACTERS  IN  THE  STRING
  for(int index = 0; index < length; index = index + 1)
  {
    // THIS IS THE CURRENT CHAR OF THE INPUTTED  STRING
    char current_letter = *(string + index);
    // THIS IS THE MATCHING MORSE CODE FOR  THE  LETTER
    char* letter_morse = convert_character_morse(table,
      lines, current_letter);
    // ADDING THE CURRENT MORSE CODE TO THE CODE  ARRAY
    *(morse_code + index) = letter_morse;
  }
  return morse_code;//RETURNING THE LIST OF MORSE CODES
}

// THIS FUNCTION CONVERTS MORSE CODE INTO  A  CHARACTER
char convert_morse_character(char*** table, int lines,
  char* morse)
{
  char character = '\0'; // CREATING CHARACTER VARIABLE
  // ITERATING THROUGH ALL THE MORSE CODES IN THE TABLE
  for(int index = 0; index < lines; index = index + 1)
  {
    // THIS IS THE CURRENT MORSE CODE  FROM  THE  TABLE
    char* current_morse = *(*(table + index) + 1);
    // THIS  IS  THE  CURRENT  LETTER  FROM  THE  TABLE
    char* current_letter = *(*(table + index) + 0);
    // CHECKING IF THE CURRENT MORSE MATCHES THE  INPUT
    if(strcmp(current_morse, morse)) continue;
    // IF IT MATCHES, THE CARACTER IS THE CURRENT  CHAR
    character = *(current_letter + 0); break;
  }
  return character; // RETURNING  THE  MATCHING  LETTER
}

// THIS FUNCTION CONVERTS A  CHARACTER  TO  MORSE  CODE
char* convert_character_morse(char*** table, int lines,
  char character)
{
  // CREATING VARIABLE  TO  STORE  THE  MORSE  CODE  IN
  char* morse_code = malloc(sizeof(char) * INT_MAX);
  // ITERATING THROUGH ALL MORSE  CODES  IN  THE  TALBE
  for(int index = 0; index < lines; index = index + 1)
  {
    // THIS IS THE CURRENT MORSE CODE  FROM  THE  TABLE
    char* current_morse = *(*(table + index) + 1);
    // THIS  IS  THE  CURRENT  LETTER  FROM  THE  TABLE
    char* current_letter = *(*(table + index) + 0);
    // CHECKING IF THE CURRENT LETTER MATCHES THE  CHAR
    if(*(current_letter + 0) != character) continue;
    // IF IT MATCHES, THE MORSE  CODE  IS  THE  CURRENT
    morse_code = current_morse; break;
  }
  return morse_code; // RETURNING  THE  MATCHING   CODE
}

// THIS FUNCTION GENERATES A TABLE OF LETTERS AND MORSE
char*** generate_morse_table(char* file_name,int lines,
  int line_size)
{
  // EXTRACTS THE LINES FROM THE MORSE CODE CSV 1  FILE
  char** file_lines=extract_file_information(file_name,
    lines, line_size);
  // CREATING A VARIABLE TO  STORE  LETTERS  AND  MORSE
  char*** morse_table = malloc(sizeof(char**) * lines);
  // ITERATING THROUGH THE LINES OF THE MORSE CSV  FILE
  for(int index = 0; index < lines; index = index + 1)
  {
    // THIS IS THE CURRENT LINE  OF  THE  FILE  (INDEX)
    char* current = *(file_lines + index);
    // ALLOCATING NEW PAIR OF LETTER AND MORSE TO TABLE
    morse_table[index] = extract_letter_morse(current);
  }
  return morse_table; // RETURNING THE MORSE CODE TABLE
}

// THIS FUNCTION DIVIDES A LINE INTO A LETTER AND MORSE
char** extract_letter_morse(char* current_line)
{
  //THIS IS THE VECTOR OF THE LETTER AND THE MORSE CODE
  char** letter_morse = malloc(sizeof(char*) * 2);
  // THIS IS THE LETTER FROM THE  CURRENT  LINE  STRING
  char* line_letter = strtok(current_line, ",");
  //THIS IS THE MORSE CODE FROM THE CURRENT LINE STRING
  char* line_morse = strtok(NULL, ",");
  // REMOVES THE " CHARS AND STORE THE LETTER IN VECTOR
  letter_morse[0] =remove_outer_characters(line_letter,
    strlen(line_letter));
  // REMOVES THE " CHARACTERS AND STORE THE MORSE  CODE
  letter_morse[1] = remove_outer_characters(line_morse,
    strlen(line_morse));
  return letter_morse; // RETURNS THE VECTOR WITH L + M
}

// THIS FUNCTION TRIMS THE STRING CHARS FROM THE STRING
char* remove_outer_characters(char* string, int length)
{
  // CREATING NEW STRING TO STORE  THE  TRIMMED  STRING
  char* trimmed = malloc(sizeof(char) * (length - 2));
  // CHECKING  IF  THE  STRING   ALREADY   IS   TRIMMED
  if(string[0] != '"' || string[length - 1] != '"')
    return string; // RETURNING  THE   TRIMMED   STRING
  // ITERATING THROUGH  THE  STRINGS  INNER  MOST  PART
  for(int index = 0; index < (length - 2); index += 1)
  {
    // ALLOCATING CHARS FROM STRING TO  TRIMMED  STRING
    *(trimmed + index) = *(string + (index + 1));
  }
  return trimmed; // RETURNING   THE   TRIMMED   STRING
}

// THIS  FUNCTION   EXTRACTS   THE   FILE   INFORMATION
char** extract_file_information(char* file_name,
  int lines, int line_size)
{
  // CREATING  AN  ARRAY  TO   STORE   THE   LINES   IN
  char** file_lines = malloc(sizeof(char*) * lines);
  // CREATING  A  POINTER  TO  READ   THE   FILE   WITH
  FILE* file_pointer = fopen(file_name, "r");
  // CREATING  A  VARIABLE  TO  STORE  TEMP   LINE   IN
  char current_line[line_size];
  // ITERATING  THROUGH   ALL   LINES   IN   THE   FILE
  for(int index = 0; index < lines; index = index + 1)
  {
    // CHECKS IF LINE EXISTS AND STORING IT IN VARIABLE
    if(!fgets(current_line, line_size, file_pointer))
      break; // BREAKING THE LOOP IF LINE  DONT  EXISTS
    // THIS IS  THE  LENGTH  OF  THE  CURRENT  LINE - 1
    int current_length = (strlen(current_line) - 1);
    // ADDING THE CURRENT LINE TO THE  ARRAY  OF  LINES
    *(file_lines + index) = strncpy(malloc(line_size),
      current_line, current_length);
  }
  return file_lines; // RETURNING THE  ARRAY  OF  LINES
}
