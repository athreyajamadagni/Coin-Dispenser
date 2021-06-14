#include<stdio.h>
#include<math.h>
#include <string.h>

int main()
{
    int amount;
    char ans; 
    int coin_ten;
    int coin_five;
    int coin_two;
    int coin_one;

    printf("Enter the amount you want the change for: ");
    scanf("%d\n", &amount);

    printf("Any specific requirement? (Y/N) ");
    scanf("%s\n", &ans);  //you've to write that if loop here
    
    printf("How many rupee 10 coins: ");
    scanf("%d\n", &coin_ten);
    printf("How many rupee 5 coins: ");
    scanf("%d\n", &coin_five);
    printf("How many rupee 2 coins: ");
    scanf("%d\n", &coin_two);
    printf("How many rupee 1 coins: ");
    scanf("%d\n", &coin_one);
}