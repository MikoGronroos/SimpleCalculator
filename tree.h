typedef enum token{
  Value,
  LBracket,
  RBracket,
  Multiplication,
  Addition,
  Substraction,
  Division
} token;

typedef struct node{
  token nodeToken;
  float nodeValue;
  struct node *leftNode;
  struct node *rightNode;
  struct node *backNode;
} node;

node* getFirstNode(char input[]);

node* allocateNode();

int sizeOfNumber(char* number);
