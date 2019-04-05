#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
DÚVIDA #1: chamo a função "conta_notas" dentro da função recebe_notas?
Ou eu devo ter um novo vetor chamado APR na main?
*/

void recebe_notas(double *APR, int N){

    for (int i = 0; i < N; i++){
        if ((*(APR+i)) >= 6.0){
            *(APR+i) = 1;
        } else {
            *(APR+i) = 0;
        }
    }
}

void conta_notas(double *APR, int N, int *qnt_aprov, int *qnt_repov){

    for (int i = 0; i < N; i++){
        if (*(APR+i) == 1) {
            *qnt_aprov = *qnt_aprov + 1;
        } else {
            *qnt_repov = *qnt_repov + 1;
        }
    }


}

int percent_aprov(int qnt_aprov, int qnt_reprov, double *p_aprov, double *p_reprov){
    *p_aprov = qnt_aprov * (qnt_aprov + qnt_reprov);
    *p_reprov = qnt_reprov * (qnt_aprov + qnt_reprov);
    if (*p_aprov > *p_reprov) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    double NOTAS[MAX];
    int qnt_aprov = 0, qnt_reprov = 0, maioria;
    double p_aprov, p_reprov;

  for (int i = 0; i < MAX; i++){
    scanf("%lf", &NOTAS[i]);
  }

    recebe_notas(NOTAS, MAX);

    conta_notas(NOTAS, MAX, &qnt_aprov, &qnt_reprov);

    maioria = percent_aprov(qnt_aprov, qnt_reprov, &p_aprov, &p_reprov);

    printf(" - Quantidade de aprovados: %d\n", qnt_aprov);
    printf(" - Quantidade de reprovados: %d\n", qnt_reprov);
    printf(" - Percentual de aprovados: %.1lf%%\n", p_aprov);
    printf(" - Percentual de reprovados: %.1lf%%\n", p_reprov);
    if (maioria == 1) {
        printf(" - A maioria foi APROVADA\n");
    } else {
        printf(" - A maioria foi REPROVADA\n");
    }
  return 0;
}
