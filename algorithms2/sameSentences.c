#include <stdio.h>
int main()
{
    char phrase1[50];
    char phrase2[50];

    fgets(phrase1, 50, stdin);
    fgets(phrase2, 50, stdin);
    int isDifferent = 0;
    int i = 0;
    while (!phrase1[i] == '\0')
    {

        if (phrase1[i] >= 97 && phrase1[i] <= 122)
        {
            phrase1[i] = phrase1[i] - 32;
        }
        if (phrase2[i] >= 97 && phrase2[i] <= 122)
        {
            phrase2[i] = phrase2[i] - 32;
        }

        if (phrase1[i] != phrase2[i])
        {
            isDifferent = 1;
        }

        i++;
    }
    
    
    
    if (isDifferent == 1)
    {
        printf("As frases sao diferentes");
    }
    else
    {
        printf("As frases sao iguais");
    }
    return 1;
}