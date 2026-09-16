#include <stdio.h>
#include <stdlib.h>

void print_vector(int *vet, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) printf("%d", vet[i]);
        else printf("%d, ", vet[i]);
    }
    printf(" }\n");
}

void swap(int *vet, int i, int j) {
    int tmp = vet[i];
    vet[i] = vet[j];
    vet[j] = tmp;
}

void selectionsort(int *vet, int size) {
    for (int i = 0; i < size - 1; i++) {
        int menor_indice = i;

        for (int j = i + 1; j < size; j++) {
            if (vet[menor_indice] > vet[j])
                menor_indice = j;
        }

        swap(vet, i, menor_indice);
    }
}

int main(void) {
    int size;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int *vet = (int *) malloc(size * sizeof(int));

    printf("\nInsira os elementos do vetor\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &vet[i]);

    selectionsort(vet, size);

    printf("\nVetor ordenado: ");
    print_vector(vet, size);

    free(vet);

    return 0;
}
