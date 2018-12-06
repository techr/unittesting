/*
 ============================================================================
 Name        : moduleone.c
 Author      : RP
 ============================================================================
 */

#include <stdio.h>
#include "../inc/moduleone.h"
#include "../inc/moduletwo.h"


void module_one(void)
{
	printf("In Module one \n");
}

int module_one_calls_method_in_module_two(int val1)
{
	printf("In module_one_calls_method_in_module_two() \n");
	int valuePlusTen = module_two(val1);
	return valuePlusTen;
}
