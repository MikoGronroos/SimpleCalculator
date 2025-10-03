#include <stdio.h>
#include "tree.h"
#include "calculate.h"

int main(){
  char input[256];
  scanf("%255s", input);
  node* newNode = getFirstNode(input);
  int number = calculate(newNode);
  //printf("%f, %f, %f, %f, %f", newNode->backNode->nodeValue, newNode->backNode->leftNode->nodeValue, newNode->backNode->rightNode->nodeValue, newNode->backNode->rightNode->leftNode->nodeValue, newNode->backNode->rightNode->leftNode->leftNode->nodeValue);
  printf("\n%d\n", number);
  return 0;  
}
