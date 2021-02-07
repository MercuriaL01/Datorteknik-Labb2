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
  _Bool *notPrime;
  notPrime = (_Bool* ) malloc((max - 2) * sizeof(_Bool*));
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
  for(int i = 0; i <= max - 2; i++)
  {
    if(notPrime[i] == 0)
    {
      print_number(i + 2);
    }
  }
  free(notPrime);
}

int main(int argc, char *argv[]){
  int flag = 0;
  if(argc == 2)
    print_siecs(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
