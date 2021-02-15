
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "string-morse-conversion.h"

int main(int arg_length, char* arguments[])
{
  const int file_lines = 36, line_size = 200;
  char*** morse_table = generate_morse_table(file_lines, line_size);

  if(arg_length >= 3 && !strcmp(arguments[1], "morse"))
  {
    char* string = arguments[2];
    int length = strlen(string);
    char** morse_string = convert_string_morse(morse_table, file_lines, string, length);
    output_morse_string(morse_string, length);
  }
  else if(arg_length >= 3 && !strcmp(arguments[1], "string"))
  {
    char** morse_string = extract_morse_string(arguments, arg_length);
    int length = arg_length - 2;

    char* string = convert_morse_string(morse_table, file_lines, morse_string, length);
    printf("%s\n", string);
  }

  return 0;
}

char** extract_morse_string(char* arguments[], int arg_length)
{
  int length = (arg_length - 2);
  char** morse_strings = malloc(sizeof(char*) * length);
  for(int index = 0; index < arg_length - 2; index = index + 1)
  {
    char* morse_char = *(arguments + index + 2);
    *(morse_strings + index) = morse_char;
  }
  return morse_strings;
}

void output_morse_string(char** morse_string, int length)
{
  for(int index = 0; index < length; index = index + 1)
  {
    printf("%s ", *(morse_string + index));
  }
  printf("\n");
}

char* convert_morse_string(char*** table, int lines, char** morse, int length)
{
  char* string = malloc(sizeof(char) * length);
  for(int index = 0; index < length; index = index + 1)
  {
    char* current_morse = *(morse + index);
    if(!strcmp(current_morse, "/"))
    {
      *(string + index) = ' ';
      continue;
    }
    char character = convert_morse_character(table, lines, current_morse);
    *(string + index) = character;
  }

  return string;
}

char** convert_string_morse(char*** table, int lines, char* string, int length)
{
  char** morse = malloc(sizeof(char*) * length);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = *(string + index);
    if(character == ' ')
    {
      *(morse + index) = "/";
      continue;
    }
    char* current_code = convert_character_morse(table, lines, character);
    *(morse + index) = current_code;
  }
  return morse;
}

char convert_morse_character(char*** table, int lines, char* morse)
{
  char character = '\0';
  for(int index = 0; index < lines; index = index + 1)
  {
    char** letter_code = *(table + index);
    if(strcmp(*(letter_code + 1), morse)) continue;
    character = *(*(letter_code + 0) + 0); break;
  }
  return character;
}

char* convert_character_morse(char*** table, int lines, char character)
{
  char* morse_code = malloc(sizeof(char) * 10);
  for(int index = 0; index < lines; index = index + 1)
  {
    char** letter_code = *(table + index);
    if(*(*(letter_code + 0) + 0) != character) continue;
    morse_code = *(letter_code + 1); break;
  }
  return morse_code;
}

char*** generate_morse_table(int lines, int line_size)
{
  char** file_lines = extract_file_information("Source-Programs-Folder/morse-code-table.csv", lines, line_size);
  char*** morse_table = malloc(sizeof(char**) * lines);
  for(int index = 0; index < lines; index = index + 1)
  {
    char* current_line = *(file_lines + index);
    char** letter_code = malloc(sizeof(char*) * 2);
    *(letter_code + 0) = strtok(current_line, ",");
    *(letter_code + 1) = strtok(NULL, ",");
    *(morse_table + index) = letter_code;
  }
  return morse_table;
}

char** extract_file_information(char* file_name, int lines, int line_size)
{
  char** file_lines = malloc(sizeof(*file_lines) * lines);
  FILE* file_pointer = fopen(file_name, "r");
  char current_line[line_size];
  for(int index = 0; index < lines; index = index + 1)
  {
    if(!fgets(current_line, line_size, file_pointer)) break;
    int current_length = strlen(current_line);
    file_lines[index] = strncpy( malloc( line_size ), current_line, current_length - 1);
  }
  return file_lines;
}
