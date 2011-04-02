#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "global.h"
#include "list.h"

void close_program();

int main(int argc, char *argv[])
{
  int choice = 0; /* Initial choice is not valid. */
  int read_from_string = false; /* TRUE while string is to be read from */
  int running = true; /* control flag for main loop */
  int error_count = 0; /* Used to prevent runaway loops */
  char buf[buf_size]; /* buf_size is defined in global.h */

  printf("Welcome to Wyatt's Cart Simulation Manager.\n");
  while(true == running)
  {
    printf("\nPlease state your desired action:\n");
    printf("\t1. List Carts in a checkout line.\n");
    printf("\t2. List grocery items in a single cart.\n");
    printf("\t3. View the checkout time for a single cart.\n");
    printf("\t4. View the total checkout time for all carts.\n");
    printf("\t5. Exit the program.\n");

    while(false == read_from_string)
    {
      if(error_count == 3)
      {
        /* Issue a warning; 3 successive invalid choices. If this continues to
           seven, the program will terminate. */
        printf("+----------------------------------------------------------+\n");
        printf("| Warning: You have made 3 invalid selections in a row.    |\n");
        printf("|                                                          |\n");
        printf("| The program will auto-end after seven incorrect choices. |\n");
        printf("+----------------------------------------------------------+\n");
      }
      else if(error_count >= 7)
      {
        /* Triggered after seven successive invalid choices with no
           valid selections in between -- either the user is hostile
           or the program has been broken (probably with some very
           odd input) -- display a warning message and terminate.*/
        printf("+----------------------------------------------------------+\n");
        printf("| Program ending: too many error choices. Goodnight, moon. |\n");
        printf("+----------------------------------------------------------+\n");
        close_program(-1);
        running = false;
        exit(-1);
      }

      memset(buf, 0, buf_size);
      printf("\nEnter your choice here: ");
      fgets(buf, buf_size, stdin);
 
      if(1 != (read_from_string = sscanf(buf, "%d", &choice)))
      {
        printf("That doesn't seem to be a valid choice! Numbers only, please.\n");
        error_count += 1;
      }
    }
    read_from_string = false;
    
    switch (choice)
    {
      case 1:
        printf("Show carts here.\n");
        error_count = 0;
        break;
      case 2:
        printf("Show items for a cart here.\n");
        error_count = 0;
        break;
      case 3:
        printf("See a cart's checkout time (assuming a medium shopper).\n");
        error_count = 0;
        break;
      case 4:
        printf("View the total checkout time.\n");
        error_count = 0;
        break;
      case 5:
        printf("Ending program...\n");
        error_count = 0;
        running = false;
        break;
      default:
        error_count += 1;
        printf("That doesn't seem to be a valid choice! Only the numbers shown are valid.\n");
    }
  }  

  close_program(0);

  return 0;
}

void close_program(int return_value)
{
  if(return_value == 0) printf(" :)\n");
  else if(return_value == 1) printf(" :(\n");

  exit(return_value);
}
