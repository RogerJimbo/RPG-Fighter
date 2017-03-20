#include"creatures.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>



void monster_drawings()
{

	for (int i = 1; i < 3; i++)
	{
		printf("|--------|\n");
		printf("|Round  %d|\n", i);
		printf("|--------|\n\n");

		if (i == 1)		//ask to do it with % for odds and even
		{
			printf("\t      ***   \n");
			printf("\t    ******* \n");
			printf("\t   ********* \n");
			printf("\t /\* ### ### *\\ \n");
			printf("\t |   @ / @   |\n");
			printf("\t  \\    ^    /\n");
			printf("\t   \\  ===  /\n");
			printf("\t    \\_____/\n");
			printf("\t     _|_|_\n");
			printf("\t  *$$$$$$$$$*\n");
		}

		if (i == 2)
		{
			printf("\t       _       _        \n");
			printf("\t      (_\\    /_)       \n");
			printf("\t        ))   ((         \n");
			printf("\t      .-'''''''-.        \n");
			printf("\t /^\\/  _.   _.  \\/^\\    \n");
			printf("\t \\(   /__\\ /__\\   )/    \n");
			printf("\t  \\,  \\o_/_\\o_/  ,/     \n");
			printf("\t    \\    (_)    /       \n");
			printf("\t     `-.'==='.-'        \n");
			printf("\t      __) - (__         \n");
			printf("\t     /  `~~~`  \\   \n");
			printf("\t    /  /     \\  \\  \n");
			printf("\t    \\ :       ; /  \n");
			printf("\t     \\|==(*)==|/   \n");
			printf("\t      :       :    \n");
			printf("\t       \\  |  /     \n");
			printf("\t     ___)=|=(___   \n");
			printf("\t    {____/ \\____}  \n");

		}


}