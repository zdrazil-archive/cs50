#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
 
    // ask user for amount
    // validate user prompt
    float money;
    do
    {
         printf("How much change is owed?\n");
         money = GetFloat();
    }
    while (money < 0);
    
    //convert value to cents
    int cents;
    cents = round((money * 100));

    
    //use largest coins possible and count their amount
    int coins = 0;
    coins = (cents / 25);
    coins = coins + ((cents % 25) / 10);
    coins = coins + (((cents % 25) % 10) / 5); 
    coins = coins + ((((cents % 25) % 10) % 5) / 1); 

    printf("%d\n", coins);

}
