#include <stdio.h>  // Biblioteca de comunica��o com o usuario
#include <stdlib.h> // Biblioteca aloca��o de espa�o de memoria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca responsavel por cuidar das string


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respinsavel por copiar os valores das string
	
	FILE *file; // cria um arquivo no banco de dado
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n.");
		system ("pause");
	}
}

int main()
{
		int opcao=0; //definindo as variaveis
		int x=1;
	
		for(x=1;x=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definir a Linguagem
		
			printf ("*** Cart�rio Da EBAC *** \n\n"); // Inicio do Menu
			printf ("Escolha a op��o desejada do menu: \n\n");
			printf ("\t 1 - Registrar Nomes \n");
			printf ("\t 2 - Consultar Nomes \n");
			printf ("\t 3 - Deletar Nomes \n\n");
			printf ("\t 4 - Sair do sistema \n\n");
			printf("Op��o: "); //Fim do Menu
		
		scanf("%d", &opcao);
		
		system("cls" ); // Apagar o texto
		
		switch(opcao)
		{
			
			case 1:
				registro();
			break;
		
			case 2:
				consultar();
			break;
		
			case 3:
				deletar();
			break;
			
			case 4:
				printf("obrigado por usar o sistema \n");
				return 0;
			default:
			
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
			
			break;
		}	
	}
}
