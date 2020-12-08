/******************************************************************************
 ***                                                                       ***
 *** Rodrigo Mendes Leme                            3151151                ***
 *** Exercicio-Programa 4B                                                 ***
 *** Professor: Jose Augusto                                               ***
 *** Turma: 11                                                             ***
 ***                                                                       ***
******************************************************************************/
#include <stdio.h>

#define MAX_PROTEINA 3000
#define MAX_DNA 10000
#define TAM_NOME 100

// Funcao: complemento
// Entrada: uma base.
// Saida: o complemento dessa base.
// Descricao: devolve o complemento de uma base de DNA.

char complemento(char base)
{
  char compl_base;

  switch(base)
  {
    case 'a': compl_base = 't';
              break;
    case 'c': compl_base = 'g';
              break;
    case 'g': compl_base = 'c';
              break;
    case 't': compl_base = 'a';
              break;
  }
  return compl_base;
}

// Funcao: complemento_reverso
// Entrada: o numero de bases no DNA e o vetor de DNA.
// Saida: o complemento reverso do vetor de DNA.
// Descricao: calcula o complemento reverso de uma sequencia genetica.

void complemento_reverso(int n, char dna[], char crdna[])
{
  int indice;

  for (indice = 0; indice <= n - 1; indice++)
    crdna[indice] = complemento(dna[n - indice - 1]);
  crdna[n] = '\0';
}

// Funcao: leia_seq_genetica
// Entrada: o arquivo de saida.
// Saida: o comprimento da sequencia genetica e o vetor de DNA.
// Descricao: le o nome de um arquivo e, caso exista, le seus caracteres a ar-
//            mazena-os no vetor de DNA, caso os mesmos sejam validos.

int leia_seq_genetica(FILE *arqsaida, char dna[])
{
  FILE *arqentrada;
  char nome[TAM_NOME];
  int n = 0;

  printf("Digite o nome do arquivo com a sequencia genetica: ");
  scanf("%s",nome);
  fprintf(arqsaida,"Digite o nome do arquivo com a sequencia genetica: %s\n",
          nome);

  if ((arqentrada = fopen(nome,"r")) == NULL)    // Se o arquivo nao existe
    fprintf(arqsaida,"Arquivo %s nao existe\n",nome);
  else
  {
    while (!feof(arqentrada))   // Enquanto o fim do arquivo nao for encontrado
    {
      fscanf(arqentrada,"%c",&dna[n]);      // Le um caracter do arquivo

      // Verificacao se o caracter lido e da sequencia genetica
      if (!feof(arqentrada) && (dna[n] == 'a' || dna[n] == 't' ||
                                dna[n] == 'g' || dna[n] == 'c'))
        n++;
    }
    fclose(arqentrada);
    if (n == 0)
      fprintf(arqsaida,
              "Nenhuma sequencia valida foi encontrada no arquivo %s\n",nome);
  }
  return n;
}

// Funcao: leia_proteina
// Entrada: o arquivo de saida.
// Saida: o comprimento da sequencia proteica e o vetor de proteina.
// Descricao: le o nome de um arquivo e, caso exista, le seus caracteres a ar-
//            mazena-os no vetor de proteina, caso os mesmos sejam validos.

void leia_proteina(FILE *arqsaida, int *n, char proteina[])
{
  FILE *arqentrada;
  char nome[TAM_NOME];
  int qtas_prot = 0;

  printf("Digite o nome do arquivo com a sequencia proteica: ");
  scanf("%s",nome);
  fprintf(arqsaida,"Digite o nome do arquivo com a sequencia proteica: %s\n",
          nome);

  if ((arqentrada = fopen(nome,"r")) == NULL)    // Se o arquivo nao existe
    fprintf(arqsaida,"Arquivo %s nao existe\n",nome);
  else
  {
    while (!feof(arqentrada))   // Enquanto o fim do arquivo nao for encontrado
    {
      fscanf(arqentrada,"%c",&proteina[qtas_prot]);        // Le um caracter
                                                           //do arquivo
      // Verificacao se o caracter lido e da sequencia proteica
      if (!feof(arqentrada) && (proteina[qtas_prot] >= 'A' &&
          proteina[qtas_prot] <= 'Z' && proteina[qtas_prot] != 'B' &&
          proteina[qtas_prot] != 'J' && proteina[qtas_prot] != 'O' &&
          proteina[qtas_prot] != 'U' && proteina[qtas_prot] != 'X'))
        qtas_prot++;
    }
    fclose(arqentrada);
    if (qtas_prot == 0)
      fprintf(arqsaida,
              "Nenhuma sequencia valida foi encontrada no arquivo %s\n",nome);
  }
  *n = qtas_prot;
}

// Funcao: iguais
// Entrada: duas cadeias de caracteres e o tamanho das mesmas.
// Saida: 1 se os primeiros "tamanho" caracteres de seq1 forem iguais aos pri-
//        meiros "tamanho" caracteres de seq2; 0 caso contrario.
// Descricao: compara caracter a caracter duas cadeias de caracteres ate encon-
//            trar uma diferenca ou as duas cadeias terminarem.

int iguais(int tamanho, char seq1[], char seq2[])
{
  int indice = 0;

  while (seq1[indice] == seq2[indice] && indice <= tamanho - 1)
    indice++;
  if (indice == tamanho)      // As sequencias sao iguais
    return 1;
  else                        // As sequencias sao diferentes
    return 0;
}

// Funcao: codigo_aminoacido
// Entrada: um codon.
// Saida: um aminoacido.
// Descricao: compara as diversas combinacoes possiveis de codons de forma a
//            encontrar o aminoacido correspondente.

char codigo_aminoacido(char codon[])
{
  if (iguais(3,"gct",codon) || iguais(3,"gcc",codon) ||
      iguais(3,"gca",codon) || iguais(3,"gcg",codon))
    return ('A');
  if (iguais(3,"tgt",codon) || iguais(3,"tgc",codon))
    return('C');
  if (iguais(3,"gat",codon) || iguais(3,"gac",codon))
    return('D');
  if (iguais(3,"gaa",codon) || iguais(3,"gag",codon))
    return('E');
  if (iguais(3,"ttt",codon) || iguais(3,"ttc",codon))
    return('F');
  if (iguais(3,"ggt",codon) || iguais(3,"ggc",codon) ||
      iguais(3,"gga",codon) || iguais(3,"ggg",codon))
    return('G');
  if (iguais(3,"cat",codon) || iguais(3,"cac",codon))
    return('H');
  if (iguais(3,"att",codon) || iguais(3,"atc",codon) || iguais(3,"ata",codon))
    return('I');
  if (iguais(3,"aaa",codon) || iguais(3,"aag",codon))
    return('K');
  if (iguais(3,"tta",codon) || iguais(3,"ttg",codon) ||
      iguais(3,"ctt",codon) || iguais(3,"ctc",codon) ||
      iguais(3,"cta",codon) || iguais(3,"ctg",codon))
    return('L');
  if (iguais(3,"atg",codon))
    return('M');
  if (iguais(3,"aat",codon) || iguais(3,"aac",codon))
    return('N');
  if (iguais(3,"cct",codon) || iguais(3,"ccc",codon) ||
      iguais(3,"cca",codon) || iguais(3,"ccg",codon))
    return('P');
  if (iguais(3,"caa",codon) || iguais(3,"cag",codon))
    return('Q');
  if (iguais(3,"cgt",codon) || iguais(3,"cgc",codon) ||
      iguais(3,"cga",codon) || iguais(3,"cgg",codon) ||
      iguais(3,"aga",codon) || iguais(3,"agg",codon))
    return('R');
  if (iguais(3,"tct",codon) || iguais(3,"tcc",codon) ||
      iguais(3,"tca",codon) || iguais(3,"tcg",codon) ||
      iguais(3,"agt",codon) || iguais(3,"agc",codon))
    return('S');
  if (iguais(3,"act",codon) || iguais(3,"acc",codon) ||
      iguais(3,"aca",codon) || iguais(3,"acg",codon))
    return('T');
  if (iguais(3,"gtt",codon) || iguais(3,"gtc",codon) ||
      iguais(3,"gta",codon) || iguais(3,"gtg",codon))
    return('V');
  if (iguais(3,"tgg",codon))
    return('W');
  if (iguais(3,"tat",codon) || iguais(3,"tac",codon))
    return('Y');
  if (iguais(3,"taa",codon) || iguais(3,"tag",codon) || iguais(3,"tga",codon))
    return('Z');
  return('\0');
}

// Funcao: testa_sequencia
// Entrada: uma sequencia genetica, seu tamanho, uma sequencia proteica, seu
//          tamanho, o nome da sequencia e o arquivo de saida.
// Descricao: varre uma sequencia genetica em busca de uma dada sequencia pro-
//            teica, comparando os codons da primeira com as proteinas da se-
//            gunda, jogando o resultado num arquivo.

void testa_sequencia(char sequencia[], int qtos_dna, char seq_proteica[],
                     int qtas_prot, char nome_sequencia[], FILE *arqsaida)
{
  int indice1,
      indice2,
      indice3;
  char codon[4];

  for (indice1 = 0; indice1 <= qtos_dna - 3 * qtas_prot; indice1++)    // Testa
  {                                                  // toda a sequencia de DNA
    indice2  = 0;
    codon[0] = sequencia[3 * indice2 + indice1];
    codon[1] = sequencia[3 * indice2 + indice1 + 1];
    codon[2] = sequencia[3 * indice2 + indice1 + 2];
    codon[3] = '\0';
    while (indice2 <= qtas_prot - 1 && seq_proteica[indice2] ==
           codigo_aminoacido(codon))     // Executa enquanto as duas sequencias
    {                    // forem iguais, comparando-as aminoacido a aminoacido
      indice2++;
      codon[0] = sequencia[3 * indice2 + indice1];
      codon[1] = sequencia[3 * indice2 + indice1 + 1];
      codon[2] = sequencia[3 * indice2 + indice1 + 2];
    }
    if (indice2 == qtas_prot)     // Achou uma sequencia valida
    {
      fprintf(arqsaida,
              "Encontrada uma ocorrencia comecando no caractere %d %s\n",
              indice1 + 1,nome_sequencia);
      fprintf(arqsaida,"A sequencia e' a seguinte: ");
      for (indice3 = indice1; indice3 <= 3 * qtas_prot + indice1; indice3++)
        fprintf(arqsaida,"%c",sequencia[indice3]);
      fprintf(arqsaida,"\n                           ");
      for (indice3 = 0; indice3 <= qtas_prot - 1; indice3++)
        fprintf(arqsaida,"%c  ",seq_proteica[indice3]);
      fprintf(arqsaida,"\n");
    }
  }
}

// Funcao: main
// Descricao: abre varios arquivos de DNA e de proteinas, testando as sequen-
//            cias geneticas, em busca das proteinas, ate encontrar um arquivo
//            invalido.

void main(void)
{
  FILE *arqsaida;
  char seq_dna[MAX_DNA],
       compl_rev[MAX_DNA],
       seq_proteica[MAX_PROTEINA],
       nome_saida[TAM_NOME];
  int qtos_dna,
      qtas_prot;

  printf("Digite o nome do arquivo a ser gerado: ");
  scanf("%s",nome_saida);
  arqsaida = fopen(nome_saida,"w");
  do
  {
    leia_proteina(arqsaida,&qtas_prot,seq_proteica);
    if (qtas_prot > 0)        // Arquivo da proteina existe e contem um sequencia
    {
      seq_proteica[qtas_prot] = '\0';
      fprintf(arqsaida,"Sequencia de proteina: %s\n",seq_proteica);
      qtos_dna = leia_seq_genetica(arqsaida,seq_dna);
      if (qtos_dna > 0)       // Arquivo de DNA existe e contem uma sequencia
      {
        seq_dna[qtos_dna] = '\0';
        complemento_reverso(qtos_dna,seq_dna,compl_rev);
        fprintf(arqsaida,"Sequencia genetica:   %s\n",seq_dna);
        fprintf(arqsaida,"Complemento reverso:  %s\n",compl_rev);
        testa_sequencia(seq_dna,qtos_dna,seq_proteica,qtas_prot,
                        "da sequencia genetica",arqsaida);
        testa_sequencia(compl_rev,qtos_dna,seq_proteica,qtas_prot,
                        "do complemento reverso",arqsaida);
      }
      fprintf(arqsaida,"************************************************************************\n");
    }
  }
  while (qtas_prot != 0);     // Executa ate o arquivo de proteina ser invalido
  fclose(arqsaida);
}
