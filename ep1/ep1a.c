/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 1A                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n_max, N, semente, k, x;

  printf("Digite o valor maximo que pode ser gerado: ");
  scanf("%d",&n_max);
  printf("Digite a quantidade de numeros a ser gerada: ");
  scanf("%d",&N);
  printf("Digite um valor para a semente de numeros aleatorios: ");
  scanf("%d",&semente);
  printf("\n");
  srand(semente);

  for (k = 0; k < N; k++)
  {
    x = 1 + (rand() / ((double) RAND_MAX + 1)) * n_max;
    printf("%d ",x);
  }
  printf("\n");
  return 0;
}
