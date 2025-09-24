#include <stdio.h>
#include "tree.h"
#include "calculate.h"

int main(){
  char input[256];
  scanf("%255s", input);
  //ParseString(input);
  node* newNode = getFirstNode(input);
  int number = calculate(newNode);
  printf("%d\n", number);
  return 0;  
}
