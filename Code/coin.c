/*
This is a coin dispenser program which dispenses coins equal to the amount you have requested.

amount stores the amount of money to be dispensed as coins
ten_coin stores the number of ten rupee coins to be dispensed
five_coin stores the number of five rupee coins to be dispensed
two_coin stores the number of two rupee coins to be dispensed
one_coin stores the number of one rupee coins to be dispensed

 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

char* trim(char *str)
{
    char *end;
    while(isspace((unsigned char)*str))
        str++;
    if(*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end))
        --end;
    end[1] = '\0';
    return str;
}

char input_char(char *message)
{
    char buf[1024];
    char character='c';
    char *trim_str;
    printf("%s",message);
    do
    {    
        fgets(buf,sizeof(buf),stdin);
        trim_str = trim(buf);
    }while(!strlen(trim_str));
    return trim_str[0];
}

int input_int(char *message)
{
    char buf[1024];
    int number;
    do
    {
        printf("%s",message);
        fgets(buf,sizeof(buf),stdin);
    }while(sscanf(buf,"%d",&number)!=1);
    return number;
}

int required_amount_match(int ten, int five, int two, int one, int amount)
{
    int req_amount = ten * 10 + five * 5 + two * 2 + one * 1;
    if (req_amount > amount)
    {
        printf("Requested dinominations exceeds the total amount, please try again.\n");
        return 1;
    }
    return 0;
}

void display(int a, int ten , int five , int two , int one)
{
    printf("You requested %d Rupees to be dispensed.\n", a);
    printf("You are receiving a total of %d Ten rupee coins.\n", ten);
    printf("You are receiving a total of %d Five rupee coins.\n", five);
    printf("You are receiving a total of %d Two rupee coins.\n", two);
    printf("You are receiving a total of %d One rupee coins.\n", one);
    printf("Thank You \n");
}

int again()
{
    char repeat;
    while(1)
    {
        repeat = input_char("Would you like to go again? Y or N?");
        if (repeat == 'Y' || repeat == 'y')
            return 1;
        else if (repeat == 'N' || repeat == 'n')
            return 0;
        else
            printf("Invalid input. Try again \n");
    }
}


void dispense(int a , int *ten, int *five , int *two , int *one)
{
    int amount_to_dispense;
    amount_to_dispense= a-((*(ten)*10)+(*(five)*5)+(*(two)*2)+(*(one)*1));
    printf("%d is amount\n",amount_to_dispense);
    int extra_ten = amount_to_dispense/10;
    amount_to_dispense -= 10 * extra_ten;
    int extra_five = amount_to_dispense/5;
    amount_to_dispense -= 5 * extra_five;
    int extra_two = amount_to_dispense/2;
    amount_to_dispense -= 2 * extra_two;
    int extra_one = amount_to_dispense/1;
    *ten = *ten + extra_ten;
    *five = *five + extra_five;
    *two = *two + extra_two;
    *one = *one + extra_one;
}


int main()
{
    int amount=0;
    int ten_coin=0;
    int five_coin=0;
    int two_coin=0;
    int one_coin=0;
    int choice = 1, req = 1;
    char yes_no, repeat;
    int valid=1;

    while (choice)
    {

        printf("Welcome to the coin dispenser\n");
        printf("**********\n");
        do
        {
           amount = input_int("Please enter an amount greater than 0 to receive coins. \nIf decimal amount is entered, it will be truncated: \n");
           if(amount <= 0)
           {
                printf("Amount cannot be 0 or less that 0, please enter a valid amount. \n");
                amount = input_int("Please enter amount to receive coins. \nIf decimal amount is entered, it will be truncated: \n");
           }
        }while(amount<=0);

        do
        {
            yes_no = input_char("Do you have any particular change requirement? (Y/N):\n");
            if(yes_no == 'Y' || yes_no == 'y')
            {
                do
                {
                    printf("If any denomination is not a requirement enter a 0.\n");
                    ten_coin = input_int("Please enter minimum number of ten rupee coins you need: ");
                    five_coin = input_int("Please enter minimum number of five rupee coins you need: ");
                    two_coin = input_int("Please enter minimum number of two rupee coins you need: ");
                    one_coin = input_int("Please enter minimum number of one rupee coins you need: ");
                    req = required_amount_match(ten_coin, five_coin, two_coin, one_coin, amount);
                    valid = 0;
                }while(req);
                dispense(amount, &ten_coin, &five_coin, &two_coin, &one_coin);
            }
            else if (yes_no == 'N' || yes_no == 'n')
            {
                ten_coin=0;
                five_coin=0;
                two_coin=0;
                one_coin=0;
                dispense(amount, &ten_coin, &five_coin, &two_coin, &one_coin);
                valid = 0;
            }
            else
            {
                printf("Please enter a valid input.\n");
            }
            
        }while(valid);
            
        display(amount,ten_coin,five_coin,two_coin,one_coin);
        choice = again();  
    }
    return 0;
}

