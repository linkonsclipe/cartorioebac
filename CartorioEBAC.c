#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings



int registro()
{
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; //FILE � uma fun��o pronta do sistema , parte do codigo onde cria o arquivo no Banco de Dados
	file = fopen(arquivo, "w"); //cria e salva o arquivo na pasta do programa
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a"); //cria e salva o arquivo na pasta do programa
	fprintf(file,nome); // salva o valor da variavel
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a"); //cria e salva o arquivo na pasta do programa
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a"); //cria e salva o arquivo na pasta do programa
	fprintf(file,cargo); // salva o valor da variavel
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o CPF.\n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O Usuario nao se encontra no sistema.\n");
		system("pause");
		
	}
	
}



int main()
{
	int opcao=0;//definindo as v�riaveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
		printf("\t	************************\n");
		printf("\t	*   Cart�rio da EBAC   *\n");
		printf("\t	************************\n");
		printf("________________________________________________________\n");
		printf("|Escolha a op��o desejada:				|\n");
		printf("|							|\n");
		printf("|\t1 - Registrar nomes:				|\n");
		printf("|\t2 - Consultar nomes:				|\n");
		printf("|\t3 - Excluir nomes:				|\n");
		printf("|\t4 - Sair do Programa				|\n");
		printf("|_______________________________________________________|\n");
		printf("Op��o:");
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpa a tela (win/lin/mac)
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por Utilizar o programa!\n");
			return 0;
			break;
							
			default:
			printf("Op��o inv�lida\n");
			system("pause");
			break;
			
		}
	
	}
}


//printf("\n\n\n\n\nEste software foi desenvolvido por Linkon Douglas Sclipe");
