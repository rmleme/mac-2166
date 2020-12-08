/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 2A                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/

#include <stdio.h>

void main(void)
{
  int num1,
      num2,
      posicao = 1;

  printf("Digite um numero: ");
  scanf("%d",&num1);
  printf("Digite outro numero: ");
  scanf("%d",&num2);
  printf("\nDiferenca notada em: ");
  while (num1 != num2 && num1 != 0)
  {
    if (num1 % 10 != num2 % 10)     // O digito menos signifacativo de cada
      printf("%d ",posicao);        // numero e igual
    num1 /= 10;
    num2 /= 10;
    posicao++;
  }
  printf("\n");
}
