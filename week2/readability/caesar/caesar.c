#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ფუნქციების პროტოტიპები
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // 1. შემოწმება: უნდა იყოს ზუსტად ერთი არგუმენტი
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. გასაღების გადაქცევა რიცხვად
    int key = atoi(argv[1]);

    // 3. მომხმარებლისგან ტექსტის მიღება
    string plaintext = get_string("plaintext:  ");

    // 4. შიფრაცია და შედეგის დაბეჭდვა
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// ფუნქცია ამოწმებს, შეიცავს თუ არა სტრიქონი მხოლოდ ციფრებს
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// ფუნქცია ახდენს ერთი სიმბოლოს როტაციას (დაშიფვრას)
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // დიდი ასოებისთვის: (c - 'A' + n) % 26 + 'A'
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // პატარა ასოებისთვის: (c - 'a' + n) % 26 + 'a'
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        // თუ სიმბოლო არ არის ასო, დავაბრუნოთ უცვლელად
        return c;
    }

    printf("\n");
}
