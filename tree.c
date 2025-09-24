#include "tree.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

node* getFirstNode(char input[]){
  node* firstNode = NULL;
  node* currentNode = NULL;
  char* character = &input[0];
  int i = 0;
  while(*character != '\0'){ 
    node *newNode = allocateNode();
    int numberIndex = 1;

    if(isdigit(*character)){
      float newNumber = atof(character);
      //printf("xd %f, %c\n", newNumber, *character);
      newNode->nodeValue = newNumber;
      numberIndex = sizeOfNumber(character);
    }else if(*character == '-'){
      newNode->nodeToken = Substraction;
    }else if(*character == '+'){
      newNode->nodeToken = Addition; 
    }

    i = i + numberIndex;
    character = &input[i];
    if(currentNode != NULL){
      currentNode->backNode = newNode;
    }
    currentNode = newNode;
    if(firstNode == NULL){
      firstNode = newNode;
    }
  }
  return firstNode;
}

int sizeOfNumber(char number[]){
  char* character = &number[0];
  int newNumber = 0;
  while(*character != '\0'){
    if(!isdigit(*character)){
      return newNumber;
    }
    newNumber++;
    character = &number[newNumber];
  }
  return newNumber;
}

node* allocateNode(){
  node *newNode;
  newNode = malloc(sizeof(node));
  newNode->nodeValue = 0.0;
  newNode->nodeToken = Value;
  newNode->leftNode = NULL;
  newNode->rightNode = NULL;
  newNode->backNode = NULL;
  return newNode;
}
