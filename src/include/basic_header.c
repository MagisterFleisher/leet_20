#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct stack stack;
typedef struct stack_item stack_item;

stack* initStack(char element);
stack_item* initStackItem(char element);
stack* pushStack(stack* current_stack, char element);
stack* popStack(stack* current_stack);
stack* emptyStack(stack* current_stack);
void deleteStack(stack* current_stack);
int_least16_t printStack(stack* current_stack); 

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}
typedef struct stack { 
  stack_item* top;
  uint_least16_t stack_size;
} stack;

typedef struct stack_item {
  stack_item* bottom;
  int element;
} stack_item;

stack* initStack(char element) {
  stack* current_stack = (stack*) malloc(sizeof(stack));
  current_stack->top = initStackItem(element);
  current_stack->stack_size = 1;
  return current_stack; 
}

stack_item* initStackItem(char element) {
  stack_item* current_stack_item = (stack_item*) malloc(sizeof(stack_item));
  current_stack_item->element = element;
  current_stack_item->bottom = NULL;
  return current_stack_item;
}

stack* pushStack(stack* current_stack, char element) {
  stack_item* new_item = initStackItem(element);
  new_item->bottom = current_stack->top;
  current_stack->top = new_item;
  current_stack->stack_size++;
  return current_stack;
}

stack* popStack(stack* current_stack) {
  switch(current_stack->stack_size) {
    case 0: {
      break;
    };
    case 1: {
      stack_item* current_top = current_stack->top;
      (void) free(current_top);
      current_stack->top = NULL;
      current_stack->stack_size = 0;
      break;
    };
    default : {
      stack_item* current_top = current_stack->top;
      current_stack->top = current_top->bottom;
      (void) free(current_top);
      current_stack->stack_size--;
    }
  }
  return current_stack;
}

stack* emptyStack(stack* current_stack) {
  switch(current_stack->stack_size) {
    case 0: {
      return current_stack;
      break;
    };
    case 1: {
      current_stack = popStack(current_stack);
      return current_stack;
      break;
    }
    default: {
      break;
    }
  }
  while(NULL != current_stack->top) {
    current_stack = popStack(current_stack);
  }
  return current_stack;
}

void deleteStack(stack* current_stack) {
  current_stack = emptyStack(current_stack);
  free(current_stack);
  return;
}

int_least16_t printStack(stack* current_stack) {
  switch(current_stack->stack_size) {
    case 0: {
      break;
    };
    case 1: {
      (void) printf("%s] %s) %d- stack:\n %d\n", __FILE__, __func__, __LINE__, current_stack->top->element);
      break;
    };
    default: {
      (void) printf("%s] %s) %d- stack:\n", __FILE__, __func__, __LINE__);
      stack_item* current_stack_item = current_stack->top;
      while(NULL != current_stack_item) {
        (void) printf(" %d | ", current_stack_item->element);
        if(NULL == current_stack_item->bottom) {
          current_stack_item = NULL;
        } else {
          current_stack_item = current_stack_item->bottom;
        }
      }
      (void) printf("\n");
      break;
    }
  }
  return 0;
}