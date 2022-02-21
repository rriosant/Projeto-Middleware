# Projeto-Middleware
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *pont_arq; //chamada pelo SO - cria variável ponteiro para o arquivo
  char c;

//abrindo o arquivo com tipo de abertura r (somente leitura - read)    
  pont_arq = fopen("arquivo1.txt","r"); //chamada pelo SO 

  if (pont_arq == NULL)
  {
    printf("Erro ao tentar abrir o arquivo!");
    exit(1);
  }
  printf("Lendo e exibindo os dados do arquivo \n\n");
 

  do
  {  
      //faz a leitura dos caracteres no arquivo apontado por pont_arq
      c = fgetc(pont_arq);//chamada pelo SO
      
      //exibe o caracter lido na tela
      printf("%c" , c);  
            
  }while (c != EOF);//enquanto não for final de arquivo 
  
        fclose(pont_arq);//fechando o arquivo //chamada pelo SO
  system("pause");//pausa na tela, somente para Windows
  return(0);
}
