#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6
int flag = 0;

void print_number(int x)
{
  flag++;
  printf("%10d", x);
  if(flag != COLUMNS)
  {
    printf("\t");
    return;
  }
  flag = 0;
  printf("\n");
}

void print_siecs(int max)
{
  _Bool notPrime[max - 1];
  for(int i = 2; i <= sqrt((double)max); i++)
  {
    if(notPrime[i - 2] == 0)
    {
        int y = i;
        int j = 2;
        while(y < max)
        {
          y = i * j;
          notPrime[y - 2] = 1;
          j++;
        }
    }
  }
  for(int i = 0; i <= sizeof(notPrime) - 1; i++)
  {
    if(notPrime[i] == 0)
    {
      print_number(i + 2);
    }
  }
}

int main(int argc, char *argv[]){
  int flag = 0;
  if(argc == 2)
    print_siecs(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
