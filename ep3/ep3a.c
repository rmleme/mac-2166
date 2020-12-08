/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 3A                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/

#include <stdio.h>

// Funcao: potencia
// Entrada: a base x e o expoente n.
// Saida: o resultado de x elevado a n.
// Descricao: exponencia um numero real.

double potencia(double x, int n)
{
  double produto = 1;
  int indice;

  for (indice = 1; indice <= n; indice++)
    produto *= x;
  return produto;
}

// Funcao: main
// Descricao: calcula o valor das prestacoes de um bem.

void main(void)
{
  int nprest;
  double vbem = 1,
         j,
         soma,
         prestacao;

  printf("Digite respectivamente os valores de\n");
  while (vbem >= 0)
  {
    printf("Valor NPrest Juros\n");
    scanf("%lf",&vbem);
    if (vbem > 0)
    {
      scanf("%d",&nprest);
      if (nprest >= 1)
      {
        scanf("%lf",&j);
        if (j >= 0)
	{
          if (j == 0)
            soma = nprest;
          else
            soma = (1 - potencia(1 / (1 + j),nprest)) / (1 - 1 / (1 + j));
          prestacao = vbem / soma;
          printf("Prestacao = %.20g\n",prestacao);
        }
        else
          printf("\n");
      }
      else
        printf("\n");
    }
    else
      if (vbem == 0)
        printf("\n");
      else
        printf("Acabou!\n");
  }
}
