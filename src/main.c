#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "include/basic_header.h"

bool isValid(char* s);

int main(int argument_count, char** argument_vector) {
  int error = 0;
  /* (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  (void) temp();
 *//*   stack* basic_stack = initStack(1);
  error += printStack(basic_stack);
  basic_stack = pushStack(basic_stack, 2);
  error += printStack(basic_stack);
  basic_stack = popStack(basic_stack);
  error += printStack(basic_stack);
  basic_stack = popStack(basic_stack);
  error += printStack(basic_stack);
  error += deleteStack(basic_stack);
 */
  bool test_string[11];
  test_string[0] = isValid("()");
  test_string[1] = isValid("))");
  test_string[2] = isValid("])");
  test_string[3] = isValid("})");
  test_string[4] = isValid("()(");
  test_string[5] = isValid("(){");
  test_string[6] = isValid("()[");
  test_string[7] = isValid("()[]{}");
  test_string[8] = isValid("(()[]{}");
  test_string[9] = isValid("()[]{}");
  test_string[10] = isValid("()[]{}");

  for(uint index = 0; index < 11; index++) {
    (void) printf("%d: Is valid? %d\n", index, test_string[index]);
  }
  return error;
}

bool isValid(char* s) {
  enum parans {
    ROUND = 0,
    SQUARE = 1,
    CURLY = 2
  };
  bool is_valid = true;\
  (void) printf("\n\n%s] %s) %d- is_valid = true: %d\n\n", __FILE__, __FUNCTION__, __LINE__, is_valid);    
  /*
    Cases:
      1) size of s < 2 => false
      2) size of s mod 2 != 0 => false
      2) s[0] != '(' NOR '[' NOR '{' => false
      3) s[last] != ')' NOR ']' NOR '}' => false
      4) parsing fails => false
      5) parsing passes => true
  */
  uint size_of_s = 0;
  char* count_ptr = s;
  while('\0' != *count_ptr) {
    size_of_s++;
    count_ptr++;
  }
  if(2 > size_of_s) { 
    (void) printf("%s] %s) %d- failed 2 > size_of_s: %d\n", __FILE__, __FUNCTION__, __LINE__, size_of_s);
    return false; }
  if(0 != (size_of_s % 2)) { 
    (void) printf("%s] %s) %d- failed size_of_s mod 2: %d\n", __FILE__, __FUNCTION__, __LINE__, size_of_s);
    return false; }
  if( (')' == s[0]) + (']' == s[0]) + ('}' == s[0]) != 0) {
    (void) printf("%s] %s) %d- s[0]: %c\n", __FILE__, __FUNCTION__, __LINE__, s[0]);
    (void) printf("%s] %s) %d- failed starting with end parans: %d\n", __FILE__, __FUNCTION__, __LINE__,  (')' != s[1]) + (']' != s[1]) + ('}' != s[1]));
    return false; }
  if( ('(' == s[size_of_s]) + ('[' == s[size_of_s]) + ('{' == s[size_of_s]) != 0) {
    (void) printf("%s] %s) %d- ending s[size_of_s]: %c\n", __FILE__, __FUNCTION__, __LINE__, s[size_of_s]);
    (void) printf("%s] %s) %d- failed ending with start parans: %d\n", __FILE__, __FUNCTION__, __LINE__, ('(' != s[size_of_s]) + ('[' != s[size_of_s]) + ('{' != s[size_of_s]) );
    return false; }

  int token = -1;
  stack* parans_stack = initStack(token);
  for(uint index = 0; index < size_of_s; index++) {
    switch(s[index]) {
      case '(' : {
        token = ROUND;
        parans_stack = pushStack(parans_stack, token);
        break;
      };
      case ')' : {
        token = ROUND;
        if(ROUND != parans_stack->top->element) { return false; 
        } else {
          parans_stack = popStack(parans_stack);
        }
        break;
      };
      case '[' : {
        token = SQUARE;
        parans_stack = pushStack(parans_stack, token);
        break;
      };
      case ']' : {
        token = SQUARE;
        if(SQUARE != parans_stack->top->element) { return false; 
        } else {
          parans_stack = popStack(parans_stack);
        };
        break;
      };
      case '{' : {
        token = CURLY;
        parans_stack = pushStack(parans_stack, token);
        break;
      };
      case '}' : {
        token = CURLY;
        if(CURLY != parans_stack->top->element) { return false; 
        } else {
          parans_stack = popStack(parans_stack);
        }
        break;
      };
      default : {
        break;
      }
    }
  }
  if(-1 != parans_stack->top->element) { return false; }
  int error = deleteStack(parans_stack);

  return is_valid;
}
