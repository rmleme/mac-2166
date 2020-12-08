/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 1B                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  int n_max,
      semente,
      x,
      qual_AB        = 2,     // Posicao do aluno na sequencia
      qual_PT        = 1,     // Posicao do prof. na sequencia
      onde_mais      = 2,     // Posicao da sequencia onde insere "+"
      onde_asterisco = 1,     // Posicao da sequencia onde insere "*"
      qtos_num       = 0,     // Total de numeros gerado na sequencia
      cont_AB        = 0,     // Numero de posicoes que o aluno deve
                              // percorrer ate inserir "+"
      cont_PT        = 0;     // Numero de posicoes que o prof. deve
                              // percorrer ate inserir "*"

  printf("Digite o valor maximo que pode ser gerado: ");
  scanf("%d",&n_max);
  printf("Digite um valor para a semente de numeros aleatorios: ");
  scanf("%d",&semente);
  printf("\n");
  srand(semente);

  while (qual_PT != qual_AB || onde_mais != onde_asterisco)    // So para quan-
  {                                                            // do a mesma
    x = 1 + (rand() / ((double) RAND_MAX + 1)) * n_max;    // carta e marcada
    printf("%d",x);                                        // pelo prof. e pelo
    cont_AB++;                                             // aluno
    cont_PT++;
    qtos_num++;
    if (cont_PT == onde_asterisco)    // Marca com "*" a posicao atual do
    {                                 // prof. Teoria
      printf("*");
      qual_PT += x;
      cont_PT = 0;
      onde_asterisco = x;
    }
    if (cont_AB == onde_mais)         // Marca com "+" a posicao atual do
      {                               // aluno brilhante
      printf("+");
      qual_AB += x;
      cont_AB  = 0;
      onde_mais = x;
    }
    printf(" ");
  }
  printf("\nNumero de numeros gerados: %d\n",qtos_num);
}
