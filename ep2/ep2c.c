/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 2C                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/

#include <stdio.h>

void main(void)
{
  int destino = 0,
      origem,
      posicao,          // Conta qual digito dos numeros esta sendo examinado
      qtos_dig_igual,
      qtos_dig_troc,
      qtos_dig_ins,
      qtos_dig_rem,
      tot_dig_igual = 0,
      tot_dig_troc  = 0,
      tot_dig_ins   = 0,
      tot_dig_rem   = 0,
      resto_dest,
      resto_orig;

  while (destino >= 0)
  {
    printf("Digite o numero de destino: ");
    scanf("%d",&destino);
    if (destino >= 0)
    {
      posicao = 1;
      qtos_dig_igual = qtos_dig_troc = qtos_dig_ins = qtos_dig_rem = 0;
      printf("Digite o numero de origem: ");
      scanf("%d",&origem);
      printf("\nNumero destino: %d\n",destino);
      printf("Numero origem: %d\n\n",origem);
      while (destino != 0 && origem != 0)    // Faz ate um dos numeros acabar
      {
        resto_dest = destino % 10;
        resto_orig = origem % 10;
        if (resto_dest != resto_orig)     // Os digitos sao diferentes
	{
          printf("Trocar de %d para %d o digito %d\n",resto_orig,resto_dest,
                 posicao);
          qtos_dig_troc++;
        }
        else                   // Os digitos sao iguais
          qtos_dig_igual++;
        destino /= 10;
        origem /= 10;
        posicao++;
      }
      while (destino != 0)    // O numero de origem acabou antes do de destino
      {
        resto_dest = destino % 10;
        printf("Inserir digito %d na posicao %d\n",resto_dest,posicao);
        qtos_dig_ins++;
        destino /= 10;
        posicao++;
      }
      while (origem != 0)    // O numero de destino acabou antes do de origem
      {
        resto_orig = origem % 10;
        printf("Remover digito %d na posicao %d\n",resto_orig,posicao);
        qtos_dig_rem++;
        origem /= 10;
        posicao++;
      }
      printf("\nTotal de digitos iguais: %d\n",qtos_dig_igual);
      printf("Total de digitos trocados: %d\n",qtos_dig_troc);
      printf("Total de digitos inseridos: %d\n",qtos_dig_ins);
      printf("Total de digitos removidos: %d\n",qtos_dig_rem);
      printf("Total de modificacoes: %d\n\n",qtos_dig_troc + qtos_dig_ins +
             qtos_dig_rem);
      tot_dig_igual += qtos_dig_igual;
      tot_dig_troc  += qtos_dig_troc;
      tot_dig_ins   += qtos_dig_ins;
      tot_dig_rem   += qtos_dig_rem;
    }
  }
  printf("\nTotal geral de digitos iguais: %d\n",tot_dig_igual);
  printf("Total geral de digitos trocados: %d\n",tot_dig_troc);
  printf("Total geral de digitos inseridos: %d\n",tot_dig_ins);
  printf("Total geral de digitos removidos: %d\n",tot_dig_rem);
  printf("Total geral de modificacoes: %d\n",tot_dig_troc + tot_dig_ins +
         tot_dig_rem);
}
