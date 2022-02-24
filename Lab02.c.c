#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fptr1, *fptr2; //chamada pelo SO - cria variável ponteiro para o arquivo
	char ch, fname1[20], fname2[20];

	printf("\n\n Copie o arquivo com outro nome :\n");
	printf("----------------------------------\n");

	printf(" Entre com o nome do arquivo  : ");
	scanf("%s",fname1);

	fptr1=fopen(fname1, "r");
	if(fptr1==NULL)
	{
		printf(" Arquivo não encontrado ou erro ao abrir.!!");
		exit(1);
	}
	printf(" Entre com o novo nome do arquivo : ");
	scanf("%s",fname2);
	fptr2=fopen(fname2, "w"); //chamada pelo SO - abrindo o arquivo com tipo de abertura r (escrita - write)
	if(fptr2==NULL)
	{
		printf(" Arquivo não encontrado ou erro ao abrir.!!");
		fclose(fptr1); //chamada pelo SO - fechando o arquivo fptr1 //chamada pelo SO
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fptr1); //chamada pelo SO - faz a leitura dos caracter no arquivo apontado por fptr1 //chamada pelo SO
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fptr2);
		}
	}
	printf(" Arquivo %s  copiado com sucesso no arquivo %s. \n\n",fname1,fname2);
	fclose(fptr1);//chamada pelo SO - fechando o arquivo fptr1 //chamada pelo SO
	fclose(fptr2);//chamada pelo SO - fechando o arquivo fptr2 //chamada pelo SO
	getchar();
}
