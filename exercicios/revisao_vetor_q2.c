#include <stdio.h>

static void print_term(double coefficient, int exponent, int *first_term)
{
    if (coefficient == 0)
        return;

    if (!*first_term)
        printf(coefficient < 0 ? " - " : " + ");
    else if (coefficient < 0)
        printf("-");

    double absolute_coefficient = coefficient < 0 ? -coefficient : coefficient;

    if (exponent == 0 || absolute_coefficient != 1)
        printf("%g", absolute_coefficient);

    if (exponent == 1)
        printf("x");
    else if (exponent > 1)
        printf("x^%d", exponent);

    *first_term = 0;
}

void derivative(const int *polynomial, int degree)
{
    int first_term = 1;

    printf("Derivada: ");
    for (int exponent = degree; exponent >= 1; exponent--)
        print_term(polynomial[exponent] * exponent, exponent - 1, &first_term);

    if (first_term)
        printf("0");
    printf("\n");
}

void integrate(const int* polynomial, int degree)
{
    int first_term = 1;

    printf("Integral: ");
    for (int exponent = degree; exponent >= 0; exponent--)
        print_term((double) polynomial[exponent] / (exponent + 1), exponent + 1,
                   &first_term);

    if (first_term)
        printf("0");
    printf("\n");
}

int main(void)
{
    int g;

    while (scanf("%d", &g) == 1 && g > 0)
    {
        int v[g + 1];

        for (int i = 0; i <= g; i++)
        {
            if (scanf("%d", &v[i]) != 1)
                return 1;
        }

        derivative(v, g);
        integrate(v, g);
    }

    return 0;
}
