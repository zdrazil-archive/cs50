#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
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
    
    // convert value to cents
    int cents;
    cents = round((money * 100));
    
    // use largest coins possible
    int coins = 0;
    
    // 25 cents   
    while (cents >= 25)
    {       
        cents = (cents - 25);
        coins = coins + 1;        
    }
    
    // 10 cents 
    while (cents >= 10)
    { 
        cents = (cents - 10);
        coins = coins + 1;        
    }
    
    // 5 cents
    while (cents >= 5)
    {
        cents = (cents - 5);
        coins = coins + 1;    
    }
    
    // 1 cents
    while (cents >= 1)
    { 
        cents = (cents - 1);
        coins = coins + 1;    
    }

    printf("%d\n", coins);

}
