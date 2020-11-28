#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stack[100][100];
int top = 0;

void clear()
{
	for (int i = 0; i < 100; i++)
		stack[i][0] = '\0';

}

int empty()
{
	return top <= 0;
}

void pop()
{
	if (top > 0)
		top--;
}

void push(char* val)
{
	if (top < 100)
	{
		strcpy(stack[top],val);
		top++;

	}
}

char* tos()
{
	char* buff = (char*)malloc(sizeof(char) * 100);
	strcpy(buff, stack[top - 1]);
	

	return buff;
}