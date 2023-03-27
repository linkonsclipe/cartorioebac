#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings



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
	
	FILE *file; //FILE é uma função pronta do sistema , parte do codigo onde cria o arquivo no Banco de Dados
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
		printf("Não foi possivel localizar o CPF.\n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	int opcao=0;//definindo as váriaveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
		printf("\t	************************\n");
		printf("\t	*   Cartório da EBAC   *\n");
		printf("\t	************************\n");
		printf("________________________________________________________\n");
		printf("|Escolha a opção desejada:				|\n");
		printf("|							|\n");
		printf("|\t1 - Registrar nomes:				|\n");
		printf("|\t2 - Consultar nomes:				|\n");
		printf("|\t3 - Excluir nomes:				|\n");
		printf("|\t4 - Sair do Programa				|\n");
		printf("|_______________________________________________________|\n");
		printf("Opção:");
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
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
			printf("Opção inválida\n");
			system("pause");
			break;
			
		}
	
	}
}


//printf("\n\n\n\n\nEste software foi desenvolvido por Linkon Douglas Sclipe");
