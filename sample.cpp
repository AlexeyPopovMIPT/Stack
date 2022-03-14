#include <stdio.h>

#include "Stack.h"

int main() {
	Stack* stk = NULL;
	NewStack(stk, short int);
	short int v = 9328, u = 0;
	
	StackPush(stk, &v);
	printf("Pushed %hd\n\n", v);

	v = 21;
	StackPush(stk, &v);
	printf("Pushed %hd\n\n", v);
	
	StackPeek(stk, &u);
	printf("On peek: %hd\n\n", u);

	printf("There\'s %d elements in the stack\n\n", GetStackSize(stk));

	StackPop(stk, &u);
	printf("Popped %hd\n\n", u);

	StackPeek(stk, &u);
	printf("On peek: %hd\n\n", u);

	printf("StackPop returned %d while ", StackPop(stk, &u));
	printf("popping %hd\n\n", u);

	printf("StackPop returned %d while popping from empty buffer\n\n", StackPop(stk, &u));

	printf("Pushing many elements\n");
	for (int i = 0; i < 10000; i++) {
		StackPush(stk, &i);
	}

	printf("There\'s %d elements in the stack\n\n", GetStackSize(stk));

	printf("Popping many elements\n");
	for (int i = 0; i < 9998; i++) {
		StackPop(stk, &u);
	}
	printf("There\'s %d elements in the stack\n\n", GetStackSize(stk));

	StackPeek(stk, &u);
	printf("On peek: %hd\n\n", u);

	StackDistruct(&stk);
	return 0;
}
