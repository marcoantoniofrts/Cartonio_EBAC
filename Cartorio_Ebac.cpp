#include <stdio.h> //biblioteca de comunica��o com o usu�rio

#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria

#include <locale.h> //biblioteca de aloca��o de texto por regi�o

#include <string.h> // biblioteca responsavel por cuidas das strings


int registro() //func��o responsavel por cadastrar os usuarios no sistema

{

	//inicio cria��o de variaveis/strings

	char arquivo[40];

	char cpf[40];

	char nome[40];

	char sobrenome[40];

	char cargo[40];

	//final cria��o de variaveis/strings


	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario

	scanf("%s", cpf); //%s refere-se as strings


	strcpy(arquivo, cpf); //resposavel por copiar os valores das strings


	FILE *file; //cria o arquivo no banco de dados

	file = fopen(arquivo,"w"); //cria o arquivo e o w significa escrever

	fprintf(file,cpf); //salvo valor da variavel

	fclose(file); //fecha o arquivo


	file = fopen(arquivo,"a");

	fprintf(file,",");

	fclose(file);


	printf("Digite o nome a ser cadastrado: ");

	scanf("%s", nome);


	file = fopen(arquivo, "a");

	fprintf(file, nome);

	fclose(file);

	file = fopen(arquivo, "a");

	fprintf(file,",");

	fclose(file);


	printf("Digite o sobrenome a ser cadastrado: ");

	scanf("%s", sobrenome);


	file = fopen(arquivo,"a");

	fprintf(file,sobrenome);
	
	fclose(file);

	file = fopen(arquivo,"a");

	fprintf(file,",");

	fclose(file);


	printf("Digite o cargo a ser cadastrado: ");

	scanf("%s", cargo);


	file = fopen(arquivo,"a");

	fprintf(file,cargo);

	fclose(file);


	system("pause");


}

int consulta()

{

	setlocale(LC_ALL, "Portuguese"); //sempre colocar essa op��o para que o programa possa identificar assentua��es


	char cpf[40];

	char conteudo[200];


	printf("Digite o CPF a ser consultado: ");

	scanf("%s",cpf);


	FILE *file;

	file = fopen(cpf,"r");


	if(file == NULL);

{

printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");

}


while(fgets(conteudo, 200, file) != NULL);

{

	printf("\nEssas s�o as informa��es do usuario: ");

	printf("%s", conteudo);

	printf("\n\n");

}

	system("pause");

}

int deletar()

{

	char cpf[40];


	printf("Digite o CPF do usuario a ser deletado: ");

	scanf("%s", cpf);


	remove(cpf);


	FILE *file;

	file = fopen(cpf,"r");


if(file == NULL);

{

	printf("O usuario n�o se encontra no sistema!.\n");

	system("pause");

	}


}

int main()

{

int opcao=0; //definindo as variaveis

int laco=1;

char senhadigitada[10]="a";

int comparacao;


	printf("### Cart�rio da EBAC ###\n\n");

	printf("Login de administrador!\n\nDigite a sua senha: ");

	scanf("%s",senhadigitada);


	comparacao = strcmp(senhadigitada, "admin");


if(comparacao == 0)

{

	system("cls");

	for(laco=1;laco=1;)

	{


		system("cls");


		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem


		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		
		printf("Escolha a op��o desejada do menu:\n\n");
		
		printf("\t1 - Registrar nomes\n");
		
		printf("\t2 - Consultar nomes\n");
		
		printf("\t3 - Deletar nome\n");
		
		printf("\t4 - Sair do sistema\n\n");
		
		printf("Op��o: "); //fim do menu
		
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		
		system("cls"); //� o responsavel por limpar a tela


		switch(opcao) //inicio da sele��o do menu
		
		{
		
			case 1:
			
			registro(); //chamada de fun��es
			
			break;
			
			
			case 2:
			
			consulta();
			
			break;
			
			
			case 3:
			
			deletar();
			
			break;
			
			
			case 4:
			
			printf("Obrigado por utilizar o sistema!\n");
			
			return 0;
			
			break;
			
			
			
			default:
			
			printf("Essa op��o n�o esta disponivel!\n");
			
			system("pause");
			
			break;
		
		}//fim da sele��o

	}

}


else

printf("Senha incorreta!");


}
