/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 1C                                                 ***
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
      cont_PT        = 0,     // Numero de posicoes que o prof. deve
                              // percorrer ate inserir "*"
      num_vezes,
      kk,
      NN = 0;                 // Soma do numero de numeros gerados

  printf("Digite o valor maximo que pode ser gerado: ");
  scanf("%d",&n_max);
  printf("Digite um valor para a semente de numeros aleatorios: ");
  scanf("%d",&semente);
  printf("Digite o numero de vezes que o programa sera executado: ");
  scanf("%d",&num_vezes);
  printf("\n");
  srand(semente);

  for (kk = 0; kk < num_vezes; kk++)
  {
    qual_AB = onde_mais = 2;
    qual_PT = onde_asterisco = 1;
    cont_AB = cont_PT = qtos_num = 0;
    while (qual_PT != qual_AB || onde_mais != onde_asterisco)  // So para quan-
    {                                                          // do a mesma
      x = 1 + (rand() / ((double) RAND_MAX + 1)) * n_max;   // carta e marcada
      cont_AB++;                                            // pelo prof. e
      cont_PT++;                                            // pelo aluno
      qtos_num++;
      if (cont_PT == onde_asterisco)    // Andou o no. de posicoes que preci-
      {                                 // sava andar; pega o proximo no.
        qual_PT += x;
        cont_PT = 0;
        onde_asterisco = x;
      }
      if (cont_AB == onde_mais)         // Andou o no. de posicoes que preci-
      {                                 // sava andar; pega o proximo no.
        qual_AB += x;
        cont_AB = 0;
        onde_mais = x;
      }
    }
    printf("Numero de numeros gerados: %d\n",qtos_num);
    NN += qtos_num;
  }
  printf("Numero medio de numeros gerados = %d/%d = %d\n",NN,num_vezes,
          NN / num_vezes);
}
