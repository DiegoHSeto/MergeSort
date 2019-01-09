#include <stdlib.h>

void merge(int *v, int inicio, int meio, int fim)
{
    int f = 0;
    int f2 = 0;
    int i, k , j;

    int v1 = inicio;
    int v2 = meio + 1;

    int tam = (fim-inicio) + 1;

    int *aux = (int*)malloc(tam * sizeof(int));


    for(i = 0; i < tam; i++)
    {
        if(!f && !f2)
        {
            if(v[v1]<v[v2])
            {
                aux[i] = v[v1++];
            }
            else
            {
                aux[i] = v[v2++];
            }

            if(v1>meio)
            {
                f = 1;
            }
            if(v2>fim)
            {
                f2 = 1;
            }
        }
        else
        {
            if(!f)
            {
                aux[i] = v[v1++];
            }
            else
            {
                aux[i] = v[v2++];
            }
        }
    }

    for(j = 0, k = inicio; j < tam; j++, k++)
    {
        v[k] = aux[j];
    }


}


void mergesort(int *v, int inicio, int fim)
{
    int meio;

    if(inicio<fim)
    {
        meio = (int)((inicio+fim)/2);

        mergesort(v, inicio, meio);
        mergesort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }

}



main(int argc, char **argv)
{
    int vet[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    mergesort(vet, 0, 19);

    for(int i = 0; i<20; i++)
    {
        printf("%d ", vet[i]);
    }
}
