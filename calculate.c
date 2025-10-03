#include "tree.h"
#include <stdio.h>

int calc(node* first, node* second, node* third){
  int value = 0;
  if(first->nodeToken == Addition){
    value = second->nodeValue + third->nodeValue;
  }
  if(first->nodeToken == Substraction){
    value = second->nodeValue - third->nodeValue;
  }
  return value;
}

int calculate(node* firstNode){
  node* currentNode = firstNode;
  token currentToken = currentNode->nodeToken;
  while(true){
    //printf("%d, %f\n", currentNode->nodeToken, currentNode->nodeValue);
    //printf("%f\n", currentNode->nodeValue);
    if(currentNode->leftNode == NULL && currentNode->rightNode == NULL){
      if(currentNode->backNode == NULL){
        printf("All is null\n");
        break;
      }
      printf("CurrentNode\n");
      currentNode = currentNode->backNode;
    }
    if(currentNode->leftNode != NULL && currentNode->rightNode != NULL){
      printf("Hei1\n");
      if(currentNode->leftNode->nodeToken == Value && currentNode->rightNode->nodeToken == Value){
        printf("Hei2\n");
        currentNode->nodeValue = calc(currentNode, currentNode->leftNode, currentNode->rightNode);
        currentNode->nodeToken = Value;
        currentNode->leftNode = NULL;
        currentNode->rightNode = NULL;
      }
    }
  }
  return currentNode->nodeValue;
}
