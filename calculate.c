#include "tree.h"
#include <stdio.h>

int calculate(node* firstNode){
  int numbers[12];
  numbers[0] = 0;
  node* currentNode = firstNode;
  token currentToken = Value;
  while(currentNode != NULL){
    printf("%d, %f\n", currentNode->nodeToken, currentNode->nodeValue);
    if(currentNode->nodeToken == 0){
      numbers[1] = currentNode->nodeValue;
      if(currentToken == 0){
        numbers[0] = currentNode->nodeValue;
      }
    }

    if(currentToken == 4){
      currentToken = Value;
      numbers[0] = numbers[0] + numbers[1];

    }
    if(currentToken == 5){
      currentToken = Value;
      numbers[0] = numbers[0] - numbers[1];
    }


    if(currentNode->nodeToken == 4){
      currentToken = Addition;
    }
    if(currentNode->nodeToken == 5){
      currentToken = Substraction;
    }
    currentNode = currentNode->backNode;

  }
  return numbers[0];
}
