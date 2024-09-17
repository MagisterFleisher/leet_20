#ifndef BAISC_HEADER_H_
#define BAISC_HEADER_H_

#include <stdint.h>
#include "basic_header.c"

typedef struct stack stack;
typedef struct stack_item stack_item;

stack* initStack(char element);
stack_item* initStackItem(char element);
stack* pushStack(stack* current_stack, char element);
stack* popStack(stack* current_stack);
stack* emptyStack(stack* current_stack);
int_least16_t deleteStack(stack* current_stack);
int_least16_t printStack(stack* current_stack); 

void temp(void);

#endif
