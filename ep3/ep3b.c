/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 3B                                                 ***
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

// Funcao: valor_absoluto
// Entrada: um numero real.
// Saida: o modulo do numero.
// Descricao: calcula o valor absoluto de um numero real.

double valor_absoluto(double x)
{
  if (x >= 0)
    return x;
  else
    return -x;
}

// Funcao: erro_relativo
// Entrada: dois numeros reais.
// Saida: o erro relativo entre os dois.
// Descricao: calcula o erro relativo entre dois numeros reais.

double erro_relativo(double x, double y)
{
  if (y == 0)
    return 1;
  else
    return valor_absoluto((x - y) / y);
}

// Funcao: raiz_quadrada
// Entrada: a base x e a margem de erro epsilon.
// Saida: o resultado da raiz quadrada de x.
// Descricao: calcula a raiz quadrada de um numero real pelo metode de Newton.

double raiz_quadrada(double x, double epsilon)
{
  double r_n  = x,
         r_n1 = 0.5 * (x + 1);

  while (erro_relativo(r_n1,r_n) >= epsilon)     // Repete ate encontrar a
  {                                              // precisao desejada
    r_n  = r_n1;
    r_n1 = 0.5 * (r_n + x / r_n);
  }
  return r_n1;
}

// Funcao: f
// Entrada: a taxa de juros, o valor do bem, o numero de prestacoes e o valor
//          da prestacao.
// Saida: o valor de f(j).
// Descricao: calcula o valor da funcao f para um dado j.

double f(double j, double vbem, int n, double prestacao)
{
  double S;

  if (j == 0)
    S = n;
  else
    S = (1 - potencia(1 / (1 + j),n)) / (1 - 1 / (1 + j));
  return S - vbem / prestacao;
}

// Funcao: juros
// Entrada: o valor do bem, o numero de prestacoes, o valor da prestacao e a
//          margem de erro.
// Saida: a taxa de juros.
// Descricao: calcula a taxa de juros sobre um bem pelo metodo de Muller.

double juros(double vbem, int n, double prestacao, double epsilon)
{
  double x_n2, x_n1, x_n, f_n2, f_n1, f_n, h_n1, h_n, q_n, A, B, C, q_linha,
         q_2_linhas, q_n_prox, x_n_prox, erro;

  x_n2 = 0;
  x_n1 = 0.3 * prestacao / (vbem - prestacao);
  x_n  = prestacao / (vbem - prestacao);
  if (f(x_n2,vbem,n,prestacao) == 0)        // Achou uma raiz
    return x_n2;
  else
    if (f(x_n1,vbem,n,prestacao) == 0)      // Achou uma raiz
      return x_n1;
    else
      if (f(x_n,vbem,n,prestacao) == 0)     // Achou uma raiz
        return x_n;
      else                 // Procura uma nova aproximacao
      {
        do      // Repete ate a precisao ser aceitavel ou achar uma raiz
        {
          f_n2 = f(x_n2,vbem,n,prestacao);
          f_n1 = f(x_n1,vbem,n,prestacao);
          f_n  = f(x_n,vbem,n,prestacao);
          h_n1 = x_n1 - x_n2;
          h_n  = x_n - x_n1;
          q_n  = h_n / h_n1;
          A    = q_n * f_n - q_n * (1 + q_n) * f_n1 + q_n * q_n * f_n2;
          B    = (2 * q_n + 1) * f_n - (1 + q_n) * (1 + q_n) * f_n1 - q_n *
                 q_n * f_n2;
          C    = (1 + q_n) * f_n;
          q_linha    = -2 * C / (B + raiz_quadrada(B * B - 4 * A * C,epsilon));
          q_2_linhas = -2 * C / (B - raiz_quadrada(B * B - 4 * A * C,epsilon));
          if (valor_absoluto(q_linha) < valor_absoluto(q_2_linhas))
            q_n_prox = q_linha;
          else
            q_n_prox = q_2_linhas;
          x_n_prox = x_n + h_n * q_n_prox;
          erro     = erro_relativo(x_n,x_n_prox);
          x_n2     = x_n1;
          x_n1     = x_n;
          x_n      = x_n_prox;
          printf("j=%.20g  erro=%.20g\n",x_n_prox,erro);
        } while (erro >= epsilon && f(x_n_prox,vbem,n,prestacao) != 0);
        return x_n_prox;
      }
}

// Funcao: main
// Descricao: calcula a taxa de juros de um bem.

void main(void)
{
  int nprest;
  double vbem = 1,
         prestacao,
         epsilon;

  printf("Digite respectivamente os valores de\n");
  while (vbem >= 0)
  {
    printf("Valor NPrest Prestacao ErroRelativo\n");
    scanf("%lf",&vbem);
    if (vbem > 0)
    {
      scanf("%d",&nprest);
      if (nprest >= 1)
      {
        scanf("%lf",&prestacao);
        if (prestacao > 0)
        {
          scanf("%lf",&epsilon);
          if (epsilon > 0)
            printf("Juros = %.20g\n",juros(vbem,nprest,prestacao,epsilon));
          else
            printf("\n");
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
