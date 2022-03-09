//Melissa Nguyen
//CS201
//A4
//5-31-2021

#include "a4.h"

int main(int argc, char * argv[])
{
   if(argc > 15 || argc == 1) //checks to see if right amount of input
   {
      printf("Invalid argument amount\n");
      exit(EXIT_FAILURE);
   }

   int choice = 0;
   //initialize the menu with the name and the function
   struct array menu[] = {
      {"exit", exit_prog},
      {"addition", addition},
      {"subtraction", subtraction},
      {"multiplication", multiplication},
      {"division", division},
      {"modulo", modulo},
      {"reverse input", rev}
   };
   //menu system
   do
   {
      printf("------------------------------\n\n");
      display_menu(menu);
      choice = pick(menu, argc, argv);

   }while(choice > 0 && choice < 7);

   exit(EXIT_SUCCESS);
}

//checks to see if one of the input is a hex and if it is, returns a 1. If I
//had more time, I would have changed this to another way
int check_hex(char * check)
{
   int length = strlen(check);
   for(int i = 0; i < length; ++i)
   {
      if(check[i] == 'x')
         return 1;
   }
   return 0;
}

//takes input from the user and uses it to decide what function to use
int pick(struct array * menu, int argc, char * argv[])
{
   int choice = -1;
   int hold = 0;

   printf("\nEnter 0-6 here: ");
   hold = scanf("%d", &choice);

   if(hold == 0 || choice == -1)
   {
      printf("\n\nSomething went wrong ABORT\n\n");
      exit(EXIT_FAILURE);
   }

   while(choice < 0 || choice >= 7)
   {
      printf("\nInvalid selection try again.\n");
      printf("\nEnter 0-6 here: ");
      hold = scanf("%d", &choice);
   }

   if(choice >= 0 || choice < 7)
   {
      printf("\n");
      menu[choice].operation(argc, argv);
   }

   return choice;
}

//displays the menu
void display_menu(struct array * menu)
{
   int i = 0;

   for(i = 0; i < 7; ++i)
   {
      printf("%d. %s\n", i, menu[i].name);
   }
}

//the rest is all of the math function
void addition(int argc, char * argv[])
{
   int sum = 0;
   int i = 1;
   int hex = -1;
   int hold = 0;
   int flag = 0;

   for(i = 1; i < argc; ++i)
   {
      hex = check_hex(argv[i]);
      if(hex != 0)
      {
         flag = sscanf(argv[i], "%x", &hold);
         if(flag == 1)
            sum += hold;
      }
      else
         sum += atoi(argv[i]);
   }
   printf("\nSum is: %d\n\n", sum);

}


void subtraction(int argc, char * argv[])
{
   int sum = 0;
   int i = 1;
   int hex = -1;
   int hold = 0;
   int flag = 0;
   for(i = 1; i < argc; ++i)
   {
      hex = check_hex(argv[i]);
      if(hex != 0)
      {
         flag = sscanf(argv[i], "%x", &hold);
         if(i == 1)
            sum += hold;
         else
         {
            if(flag == 1)
               sum -= hold;
         }
      }
      else
      {
         if(i == 1)
            sum += atoi(argv[i]);
         else
            sum -= atoi(argv[i]);

      }
   }
   printf("\nSubtraction is: %d\n\n", sum);
}


void multiplication(int argc, char * argv[])
{
   int i = 1;
   int hex = -1;
   int total = 0;
   int flag = 0;
   int hold = 0;
   for(i; i < argc; ++i)
   {
      hex = check_hex(argv[i]);
      if(hex != 0)
      {
         flag = sscanf(argv[i], "%x", &hold);
         if(i == 1)
            total = hold;
         else
            if(flag == 1)
               total *= hold;
      }
      else
      {
         if(i == 1)
            total = atoi(argv[i]);
         else
            total *= atoi(argv[i]);
      }
   }

   printf("\nMultiplied together is: %d\n\n", total);
}


void division(int argc, char * argv[])
{
   int i = 1;
   int hex = -1;
   float total = 0;
   int flag = 0;
   int hold = 0;
   for(i; i < argc; ++i)
   {
      hex = check_hex(argv[i]);
      if(hex != 0)
      {
         flag = sscanf(argv[i], "%x", &hold);
         if(i == 1)
            total = hold;
         else
            if(flag == 1)
               total /= hold;
      }
      else
      {
         if(i == 1)
            total = atoi(argv[i]);
         else
            total /= atoi(argv[i]);
      }
   }

   printf("\nDivided together is: %f\n\n", total);
}


void modulo(int argc, char * argv[])
{
   int i = 1;
   int hex = -1;
   int total = 0;
   int flag = 0;
   int hold = 0;
   hold = atoi(argv[2]);
   if(hold == 0)
   {
      printf("\nMod together is: 0 \n\n");
      return;
   }
   for(i; i < argc; ++i)
   {
      hex = check_hex(argv[i]);
      if(hex != 0)
      {
         flag = sscanf(argv[i], "%x", &hold);
         if(i == 1)
            total = hold;
         else
            if(flag == 1)
               total %= hold;
      }
      else
      {
         if(i == 1)
            total = atoi(argv[i]);
         else
            total %= atoi(argv[i]);
      }
   }

   printf("\nMod together is: %d\n\n", total);

}


void rev(int argc, char * argv[])
{
   int i = argc;
   for(i; i > 1; --i)
   {
      print_backwards(argv[i-1]);
      printf(" ");
   } 
   printf("\n\n");
}


void print_backwards(char * word)
{
   int length = strlen(word);
   int k = length;
   for(k; k >= 0; --k)
   {
      printf("%c", word[k]);
   }
}


void exit_prog(int argc, char * argv[])
{
   printf("\nThank you. Goodbye.\n\n");
   exit(EXIT_SUCCESS);
}