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

int required_amount_match(int a, int b, int c, int d, int e)
{
    int req_amount = a * 10 + b * 5 + c * 2 + d * 1;
    if (req_amount > e)
    {
        printf("Requested dinominations exceeds the total amount, please try again.\n");
        return 1;
    }
    else
    {
        return 0;
    }
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

int Again()
{
    char repeat;
    printf("Would you like to go again? Y or N?(Case Sensitive)");
    scanf("%s", &repeat);
    if (repeat == 'Y')
        return 1;
    else if (repeat == 'N')
        return 0;
    else
    {
        printf("Invalid input, press 'Y' to continue and 'N' to exit.\n");
        return Again();
    }
}


int dispense(int a , int ten, int five , int two , int one)
{
    int amount_to_dispense;
    amount_to_dispense= a-((ten*10)+(five*5)+(two*2)+(one*1));
    ten=ten+(amount_to_dispense/10);
    amount_to_dispense= a-((ten*10)+(five*5)+(two*2)+(one*1));
    five=five+(amount_to_dispense/5);
    amount_to_dispense= a-((ten*10)+(five*5)+(two*2)+(one*1));
    two=two+(amount_to_dispense/2);
    amount_to_dispense= a-((ten*10)+(five*5)+(two*2)+(one*1));
    one=one+(amount_to_dispense/1);
    
}


int main()
{
    int amount;
    int ten_coin;
    int five_coin;
    int two_coin;
    int one_coin;
    int y, n, choice = 1, req = 1;
    char yes_no, repeat;

    while (choice)
    {

        printf("Welcome to the coin dispenser \n");
    AMT:
        printf("Please enter amount to receive coins. \nIf decimal amount is entered, it will be truncated: \n");
        scanf("%d", &amount);
        if (amount <= 0)
        {
            printf("Amount cannot be 0 or less that 0, please enter a valid amount. \n");
            goto AMT;
        }

    YES_OR_NO:
        printf("Do you have any particular change requirement? (Y/N): \n");
        scanf("%s", &yes_no);

        while (req)
        {
            if (yes_no == 'Y')
            {
                printf("If any denomination is not a requirement enter 0.\n");
                printf("Please enter minimum number of ten rupee coins you need: ");
                scanf("%d", &ten_coin);
                printf("Please enter minimum number of five rupee coins you need: ");
                scanf("%d", &five_coin);
                printf("Please enter minimum number of two rupee coins you need: ");
                scanf("%d", &two_coin);
                printf("Please enter minimum number of one rupee coins you need: ");
                scanf("%d", &one_coin);
                req = required_amount_match(ten_coin, five_coin, two_coin, one_coin, amount);
            }
            else if (yes_no == 'N')
            {
            }

            else
            {
                printf("Please enter a valid input.\n");
                goto YES_OR_NO; //Please remove goto statement
            }

            
            display(amount,ten_coin,five_coin,two_coin,one_coin);
            choice = Again();
            
        }
        
    }

    return 0;
}

