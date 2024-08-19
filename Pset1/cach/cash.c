#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    int cents = get_cents();

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate how many nickels you should give customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate how many pennies you should give customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum the number of quarters, dimes, nickels, and pennies used
    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }

    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents / 1;
}
