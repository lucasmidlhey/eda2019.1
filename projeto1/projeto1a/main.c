#include <stdio.h>
void fneuronio(float *, float *, float, int, int *);
int main(int argc, char const *argv[]) {
  float entrada[10], peso[10], limiar;
  int cont= 10, x, *r, neuronio ;
  r = &neuronio;
  printf("\nDigite as Entradas: " );
  for (x =0; x<cont; x++){
    scanf("%f", &entrada[x]);
  }
  printf("\nDigite os Pesos: ");
  for (x=0; x<cont; x++){
    scanf("%f", &peso[x]);
  }
  printf("\nDigite o limiar: " );
  scanf("%f", &limiar);
  fneuronio(entrada, peso, limiar, cont, r);
  if (*r==1)
    printf("\n\nNeuronio Ativado!");
  else
    printf("\n\nNeuronio inibido!");

  return 0;
}
void fneuronio(float *e, float *p, float l, int cont, int *r){
    float somap=0;
    int x;
    for(x = 0; x<cont; x++){
      somap += *(e + x) * *(p + x);
    }

    if (somap>l)
      *r = 1;
    else
      *r = 0;
}
