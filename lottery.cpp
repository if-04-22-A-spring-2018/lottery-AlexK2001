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

bool init_lottery(char *csv_file, char csv_separator)
{
  FILE* fd = fopen(csv_file, "r");
      seperator = csv_separator;
      drew = false;
      file_name = csv_file;
      if(fd != 0)
      {
        fclose(fd);
        return true;
      }
      return false;

}
bool get_tip(int tip_number, int tip[TIP_SIZE])
{
  FILE* file = fopen(file_name, "r");
    char input[MAX_LINE_LEN];
    int count = 0;
    if(tip_number < 0 || file == 0){
        fclose(file);
        return false;
    }
    char* tip_array = fgets(input, MAX_LINE_LEN, file);

    while(tip_array != 0 && count < tip_number)
    {
        tip_array = fgets(input, MAX_LINE_LEN, file);
        count++;
        if (tip_array != input) {
            fclose(file);
            return false;
        }
    }
    int position = 0;
    while(input[position] != seperator && position < UUID_LEN){
        position++;
    }

    int insert_on_possition = 0;
    int tens = 0;
    while(insert_on_possition < 6){
        position++;
        if(input[position] <= '9' && input[position] >= '0'){
            tens = tens * 10 + (input[position] - '0');
        }
        else{
            tip[insert_on_possition] = tens;
            tens = 0;
            insert_on_possition++;
        }
    }
    fclose(file);
    return true;
}

bool set_drawing(int drawing_numbers[TIP_SIZE]){
    drew = true;
    numbers_array = drawing_numbers;
    return false;
}

int get_tip_result(int tip_number){
    if(!drew)
    {
      return -1;
    }

    int array[6];
    if(!get_tip(tip_number, array))
    {
      return -2;
    }

    int count = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(array[i] == numbers_array[j])
            {
              count++;
            }
        }
    }
    return count;
}

int get_right_tips_count(int tip){
    if(drew && tip >= 0 && tip <= TIP_SIZE)
    {
      int to_check_tip = 0;
      int count = 0;
      int correct_tip_count = 0;
      do{
          correct_tip_count = get_tip_result(to_check_tip);
          if(correct_tip_count == tip)
          {
            count++;
          }
          to_check_tip++;
      }while (correct_tip_count != -2 && correct_tip_count != -1);
      return count;
    }
    return -1;
}
