#include <stdio.h>

void moveDisco(int, char, char, char);
int main(){
  int nDisco;
  printf("Digite o numero de discos: ");
  scanf("%d", &nDisco);
  moveDisco(nDisco, 'A', 'C', 'B');
  return 0;
}
void moveDisco(int disco, char inicial, char fim, char auxiliar){
  if (disco == 1){
  printf("Move disco %c para %c\n", inicial, fim);
}else{
    moveDisco(disco-1, inicial, auxiliar, fim);
    printf("Move disco %c para %c\n", inicial, fim);
    moveDisco(disco-1,auxiliar, fim, inicial);
  }
}
