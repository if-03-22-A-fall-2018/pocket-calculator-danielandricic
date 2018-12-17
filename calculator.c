#include "calculator.h"
#include <stdio.h>
#include <float.h>

int main()
{
  int option = 0;
  double result = 0;
  printf("Calculator\n==========\n");

  do
  {
    printoption();
    result = getinputandcalculate(&option);
    if(option != -1)
    {
      printf("\nDas Ergebnis beträgt %.1f.\n", result);
    }
  }while(option != -1);
  return 0;
}

void printoption()
{
  printf("\nChoose one of the following operations:\n");
  printf("Add (1)\nSubtract (2)\nMultiply (3)\nDivide (4)\nStop program (-1)\n");
  printf("Enter your choice: ");
}

double getinputandcalculate(int *option)
{
  double firstnumber = 0;
  double secondnumber = 0;

  scanf("%d", option);

  while(*option == 0 || *option < -1 || *option > 4)
  {
    printf("\nOption not allowed, please try again.\n");
    scanf("%d", option);
  }

  if(*option == -1)
  {
    return 0;
  }

  printf("\nBitte geben Sie die erste Zahl ein: ");
  scanf("%lf", &firstnumber);
  checkfornumber(&firstnumber);

  printf("\nBitte geben Sie die zweite Zahl ein: ");
  scanf("%lf", &secondnumber);

  if(*option != 4)
  {
    checkfornumber(&secondnumber);
  }

  switch(*option)
  {
    case 1:
      return Add(firstnumber, secondnumber);
    break;
    case 2:
      return Subtract(firstnumber, secondnumber);
    break;
    case 3:
      return Multiply(firstnumber, secondnumber);
    break;
    case 4:
      while(secondnumber == 0)
      {
        printf("Dividieren durch 0 ist verboten!\n Zeite Zahl neu eingeben: ");
        scanf("%lf", &secondnumber);
      }
      return Divide(firstnumber, secondnumber);
    break;
    default:
      return 0;
    break;
  }
}

double Add(double firstnumber, double secondnumber){
  return firstnumber + secondnumber;
}

double Subtract(double firstnumber, double secondnumber)
{
  return firstnumber - secondnumber;
}

double Multiply(double firstnumber, double secondnumber)
{
  return firstnumber * secondnumber;
}

double Divide(double firstnumber, double secondnumber)
{
  return firstnumber / secondnumber;
}

void checkfornumber(double *number)
{
  while(1){
    if(*number > DBL_MAX)
    {
      printf("\nNumber overflow!\n Enter a new number: ");
      scanf("%lf", number);
    }
    else if(*number < DBL_MIN)
    {
      printf("\nNumber underflow!\n Enter a new number: ");
      scanf("%lf", number);
    }
    else
    {
      return;
    }
  }
}
