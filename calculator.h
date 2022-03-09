#include <stdio.h>
#include <math.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>

typedef void math_function(int argc, char * argv[]);

struct array
{
   char * name;
   math_function * operation;
};

int check_hex(char * check);
int pick(struct array * menu, int argc, char * argv[]);
void display_menu(struct array * menu);
void print_backwards(char * word);

void addition(int argc, char * argv[]); 
void subtraction(int argc, char * argv[]);
void multiplication(int argc, char * argv[]);
void division(int argc, char * argv[]);
void modulo(int argc, char * argv[]);
void rev(int argc, char * argv[]);
void exit_prog(int argc, char * argv[]);