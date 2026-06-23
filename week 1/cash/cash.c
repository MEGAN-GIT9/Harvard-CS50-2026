#include <cs50.h>
#include <stdio.h>

int quarte1(int c);
int quarte2(int c);
int quarte3(int c);

int main(void)
{

    int change, coins;

    do
    {

        change = get_int("change: ");
    }

    while (change < 1);

    int coin = quarte1(change);
    change = change - (25 * coin);

    int mcoin = quarte2(change);
    change = change - (10 * mcoin);

    int gcoin = quarte3(change);
    change = change - (5 * gcoin);

    coins = coin + mcoin + gcoin + change;

    printf("%i\n", coins);
}

int quarte1(int c)
{

    return c / 25;
}

int quarte2(int c)
{

    return c / 10;
}

int quarte3(int c)
{

    return c / 5;
}