/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/

#include "lottery.h"
#include <stdio.h>
#include <stdlib.h>

#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)

char seperator;
const char* file_name;
bool  drew = false;
int* numbers_array;

bool init_lottery(const char *csv_file, char csv_separator)
{
  FILE* fd = fopen(csv_file, "r");
  file_name = csv_file;
  seperator = csv_separator;
  drew = false;
  if (fd == NULL) {
    return false;
  }
  fclose(fd);
  return true;

}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
  FILE* file = fopen(file_name, "r");
  char input[MAX_LINE_LEN] = {0};

  if (tip_number <= 0 || file == NULL ) {
    fclose(file);
    return false;
  }

  char* output = fgets(input, MAX_LINE_LEN, file);
  int count = 0;
  //int fseek(file,tip_number,SEEK_CUR);
  fclose(file);
  return false;
}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  drew = true;
  numbers_array = drawing_numbers;
  return false;
}

int get_tip_result(int tip_number){

}

int get_right_tips_count(int right_digits_count){

}
