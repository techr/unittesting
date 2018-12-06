/*
 ============================================================================
 Name        : moduletwo.c
 Author      : RP
 ============================================================================
 */

#include <stdio.h>
#include "../inc/moduletwo.h"

int add(int a, int b)
{
	return (a+b);
}

int module_two(int a)
{
	printf("In module_two() \n");
	return add(a, 10);
}
