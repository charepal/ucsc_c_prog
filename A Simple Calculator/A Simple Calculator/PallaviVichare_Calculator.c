//
//  PallaviVichare_Calculator.c
//  A Simple Calculator
//
//  Created by Pallavi Vichare on 10/5/14.
//  Copyright (c) 2014 Pallavi Vichare. All rights reserved.
//


#include <stdio.h>

void desplayMenuOptions ();
int getInput ();
float Add (float, float);
float Subtraction (float, float);
float Multiplication (float, float);
float Division (float, float);
void Exit ();
int ErrorMessage ();
int waitForEnterKey();
void performOperation(int i);
int getMenuOption();

int main ()
{
    printf("Welcome to Pallavi Vichare's Handy Calculator\n\n");
    
    while (1) {
        desplayMenuOptions ();
        int i = getMenuOption();
        performOperation(i);
        waitForEnterKey();
    }
    return 0;
}


int getMenuOption()
{
    int i;
    scanf("%d", &i);
    return i;
}


int waitForEnterKey()
{
    printf(" Press enter key to continue ....\n\r");
    return 0;
}


void desplayMenuOptions ()
{
    printf(" 1. Addition\n");
    printf(" 2. Subtraction\n");
    printf(" 3. Multiplication\n");
    printf(" 4. Division\n");
    printf(" 5. Exit\n\n");
    
    printf(" What would you like to do? ");
    
}


void performOperation(int i)
{
    /*
     * Handle the error cases
     */
    if (i == 5) {
        Exit ();
    }
    
    if ( (i < 1) || (i > 5) ) {
        int i = ErrorMessage ();
    }
    
    
    /*
     * Handle the valid cases
     */
    float num1, num2 ;
    switch (i) {
        case 1:
        printf("\nPlease enter two numbers for Addition, separated by a space: ");
        break;
        
        case 2:
        printf("\nPlease enter two numbers for Subtraction, separated by a space: ");
        break;
        
        case 3:
        printf("\nPlease enter two numbers for Multiplication, separated by a space: ");
        break;
        
        case 4:
        printf("\nPlease enter two numbers for Division, separated by a space: ");
        break;
        
        default:
        /* Should not get here */
        break;
    }
    
    scanf("%f %f", &num1, &num2);
    
    switch (i) {
        case 1:
        Add ( num1, num2);
        break;
        
        case 2:
        Subtraction ( num1, num2);
        break;
        
        case 3:
        Multiplication ( num1, num2);
        break;
        
        case 4:
        Division ( num1, num2);
        break;
        
        default:
        // should not get here
        break;
    }
}


float Add (float a, float b)
{
    printf("\nResult of Adding %.2f and %.2f is %.2f.", a, b, a + b);
    
    return a + b;
}


float Subtraction (float a, float b)
{
    printf("\nResult of Subtracting %.2f and %.2f is %.2f.",a, b, a - b);
    
    return a - b;
}


float Multiplication (float a, float b)
{
    printf("\nResult of Multiplication %.2f and %.2f is %.2f.", a, b, a * b);
    
    return a * b;
}


float Division (float a, float b)
{
    while (b == 0) {
        printf("\nThis is- divide by zero error, which is invalid.\n" );
        printf("\nPlease re-enter your numbers,seperated by a space: ");
        
        scanf("%f %f", &a, &b);
    }
    
    printf("\nResult of Division %.2f and %.2f is %.2f.",a , b, a / b);
    
    return a / b;
}


void Exit ()
{
    printf("\nThank you for using Pallavi Vichare's Handy Calculator\n\n");
}


int ErrorMessage ()
{
    int i;
    printf("\nThat is not a valid choice, please re-enter: ");
    scanf("%d", &i);
    return i;
}

