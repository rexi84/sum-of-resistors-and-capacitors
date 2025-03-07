#include <iostream>
#include<conio.h>

int main()
{
    int moznost1;
    int moznost2;
    int pocet = 0;
    float input;
    int moznost3 = 0;
    float soucet = 0;

input1:
    printf("Pro scitani rezistoru napiste 1, pro scitani kondenzatoru napiste 2: ");
    scanf_s("%d", &moznost1);
    if (moznost1 == 1 || moznost1 == 2)
    {
    input2:
        printf("Pro seriove scitani napiste 1, pro paralerni scitani napiste 2: ");
        scanf_s("%d", &moznost2);
        if (!(moznost2 == 1 || moznost2 == 2))
        {
            system("cls");
            puts("Neplatna hodnota!");
            goto input2;
        }
    }
    else
    {
        system("cls");
        puts("Neplatna hodnota!");
        goto input1;
    }

    if ((moznost1 == 1 && moznost2 == 1) || (moznost1 == 2 && moznost2 == 2))
        moznost3 = 1;

pocet_IN:
    printf("Zadejte pocet soucastek: ");
    scanf_s("%d", &pocet);
    if (pocet <= 0)
    {
        system("cls");
        puts("Neplatna hodnota!");
        goto pocet_IN;
    }

    float* hodnoty = new float[pocet];

    for (int i = 0; i < pocet; i++)
    {
        printf("Zadejte hodnotu %d. soucastky: ", i + 1);
        scanf_s("%f", &input);
        hodnoty[i] = input;
    }

    switch (moznost3) {
    case 0:
        for (int i = 0; i < pocet; i++)
            soucet = soucet + pow(hodnoty[i], -1);
        soucet = pow(soucet, -1);
        break;
    case 1:
        for (int i = 0; i < pocet; i++)
            soucet = soucet + hodnoty[i];
        break;
    }

    printf("Celkova hodnota souctu je: %f \n", soucet);
    _getch();
}