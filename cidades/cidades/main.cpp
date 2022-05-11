#include<stdio.h>
#include<math.h>

int main(){
    FILE *arquivo = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    int N = 9152;
    double cidLa[N];
    double cidLg[N];

    double *dist;
    dist = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i*N + j] = 0.;
        }
    }
    

    int k=0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            dist[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
        }
    }
}
