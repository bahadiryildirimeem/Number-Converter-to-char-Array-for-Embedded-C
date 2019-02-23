#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "numberconverter.h"
/*
   Author: Bahadir YILDIRIM
   
   I need your advice about this mini library, so this is my e-mail:
   bahadiryildirim15@gmail.com
   
*/
/*This function turns value in char type. */
/*value parameter is number value will turn char type */
/* *ptr parameter is adress of number value */
/*size parameter is number of converted char array's size*/
char* number2char(float value, char *ptr, uint8_t size)
{
    char turned[20], data[20];
    char *converted = &data[20];
    float decimals, decimalsMultiplying;
    uint8_t i = 0, noInteger = 0, pointLimit = 3;
    uint32_t step = 0, valDividing;
    valDividing = value;
    decimals = value - valDividing;

    while(valDividing != 0)
    {
        valDividing /= 10;
        step++;
    }
    valDividing = value;
    for(i = step; i != 0; i--)
    {
        number2character(valDividing % 10, &turned[i-1]);
        valDividing /= 10;
    }
    /*Checking, is value integer */
    if(decimals != 0)
    {
    	noInteger = 1;
    }

    if(noInteger == 1)
    {
    turned[step] = '.';
    decimalsMultiplying = decimals;
    for(i = 0; pointLimit != 0; i++)
        {
        	decimalsMultiplying *= 10;
        	valDividing = decimalsMultiplying;
        	step++;
        	number2character(valDividing % 10, &turned[step]);
        	pointLimit--;
        }
    for(i; i<size; i++)
    {
    	step++;
    	turned[step] = '0';
    }
    }
    else
    {
    	turned[step] = '\0';
    }

    converted = turned;
    for(i = 0; i < size; i++)
    {
    	*ptr = converted[i];
    	ptr++;

    }
    return "OK\n";

}
char* number2character(int value, char *ptr)
{
    char numberChar;
    switch(value)
    {
        case 1:
        numberChar = '1';
        break;
        case 2:
        numberChar = '2';
        break;
        case 3:
        numberChar = '3';
        break;
        case 4:
        numberChar = '4';
        break;
        case 5:
        numberChar = '5';
        break;
        case 6:
        numberChar = '6';
        break;
        case 7:
        numberChar = '7';
        break;
        case 8:
        numberChar = '8';
        break;
        case 9:
        numberChar = '9';
        break;
        case 0:
        numberChar = '0';
        break;
        default:
        numberChar = '\0';
        break;
    }
    *ptr = numberChar;
    return "OK\n";
}
