
/**
 * @file stack_testing.c
 *
 * @brief Stack testing is done for pushing, popping, stack size and stack free of elements (both strings and integers).
 * 
 * @author Indu Guduru - induguduru@cmail.carleton.ca
 * @author Kiran Ramasamy- kiranramasamy@cmail.carleton.ca
 * @author Tejaswini Tummala- tejaswinitummala@cmail.carleton.ca
 * @author Vinoth Kumar Baskaran - vinothkumarbaskaran@cmail.carleton.ca
 * */
#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
//#include "../src/stack.c"


#define STACKSIZE 150

int main()
{
	Stack strs;
	Stack ints;
	char *str = NULL;
	int *iptr;
	int val = 0;
	int i;

	stackInit(&strs, STACKSIZE);
	stackInit(&ints, STACKSIZE);

	/* To test strings, we are pushing some text into stack and printing*/
	printf("Testing strings strategy:\n");

	str = "This";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char *)stackTop(&strs));
	str = "is";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char *)stackTop(&strs));
	str = "our";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char *)stackTop(&strs));
	str = "calculator";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char *)stackTop(&strs));
	str = "program";
	printf("Pushing \"%s\"\n", str);
	stackPush(&strs, str);
	printf("Top of stack: \"%s\"\n", (char *)stackTop(&strs));

	printf("Stack before stackPop():\n");
	for (i = stackSize(&strs) - 1; i >= 0; i--)
	{
		printf("\"%s\"\n", (char *)(strs.content[i]));
	}

	str = stackPop(&strs);
	printf("stackPop() returned \"%s\"\n", str);
	printf("Remainder of stack:\n");
	while (stackSize(&strs))
	{
		str = (char *)stackPop(&strs);
		printf("\"%s\"\n", str);
	}

	/* Test ints */
	printf("\n\nTest ints:\n");

	for (i = 1; i <= 4; i++)
	{
		int *add = (int *)malloc(sizeof(int));
		if (add == NULL)
		{
			printf("Cannot allocate memory, poping stack\n");
			goto error_pop;
		}
		*add = i;
		printf("Pushing %d\n", *add);
		stackPush(&ints, add);
		printf("Top of stack: %d\n", *(int *)stackTop(&ints));
	}

	printf("Stack before stackPop():\n");
	for (i = stackSize(&ints) - 1; i >= 0; i--)
	{
		printf("%d\n", *((int *)(ints.content[i])));
	}

	iptr = (int*)stackPop(&ints);
	printf("stackPop() returned %d\n", *iptr);
	free(iptr);
	printf("Remainder of stack:\n");
error_pop:
	while(stackSize(&ints))
	{
		int *rem = (int*)stackPop(&ints);
		val = (rem != NULL ? *rem : -1);
		printf("%d\n", val);
		free(rem);
	}

	stackFree(&ints);
	getchar();
	return 0;
}