
#ifndef TEST_PROGRAM_H
#define TEST_PROGRAM_H

char*** generate_morse_table(int, int);

char* convert_character_morse(char***, int, char);

char convert_morse_character(char***, int, char*);

char** convert_string_morse(char***, int, char*, int);

char** extract_file_information(char*, int, int);

char* convert_morse_string(char***, int, char**, int);

char** extract_morse_string(char*[], int);

void output_morse_string(char**, int);

#endif
