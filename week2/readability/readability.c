#include <cs50.h>
#include <ctype.h>
#include <math.h> // აუცილებელია round-ისთვის
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    float l = 0, s = 0, w = 1; // float უმჯობესია სიზუსტისთვის

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
        else if (text[i] == ' ')
        {
            w++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
    }

    // index-ის გამოთვლა ციკლის გარეთ
    int index = (int) round(0.0588 * (l / w * 100) - 0.296 * (s / w * 100) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
