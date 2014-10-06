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
    /* if scanf is unable to decode one integer from the user input, we need to show an error message and as her to re-enter */
    while ( 1 != scanf("%d", &i) ) {
        printf("That is not a valid choice, please re-enter: ");
        /* It seems that if user did not enter a valid integer, scanf keeps getting the same input in its next attempt.
         * So I need to scan that input line and throw it away if I want to give the user another chance to give us
         * an integer. */
        char a[1000];
        scanf("%s", a);
    }
    return i;
}


int waitForEnterKey()
{
    printf("\n\nPress enter key to continue .... ");
    char a[1000];
    
    /* We use fgets instead of scanf because scanf does not move forwards if we hit only enter, whereas fgets does. */
    fgets(a, 1000, stdin);

    /* Looks like the we need two fgets here instead of one. Possibly has to do with us using scanf for getting previous
     * inputs. As far as I can tell, the previous scanf scanned a double. Then scanf threw the \n at the end of that string 
     * back onto the input buffer in which all of users key-strokes wait until we get them out using scanf/fgets etc.
     * The is not a problem for two scanf's called one after the other because scanf's ignore \n, \t space etc. But
     * of course we cannot use scanf because it does not move forward when user only hits the enter key. */
    fgets(a, 1000, stdin);

    return 0;
}


void desplayMenuOptions ()
{
    printf("\nWelcome to Pallavi Vichare's Handy Calculator\n\n");
    printf("\t1. Addition\n");
    printf("\t2. Subtraction\n");
    printf("\t3. Multiplication\n");
    printf("\t4. Division\n");
    printf("\t5. Exit\n\n");
    
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

