#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings
    
	int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema.
	
{ //inicio cria��o de vari�veis/string
    char arquivo [40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se as string's
    
    strcpy(arquivo, cpf); //responsavel por criar os valores das strings
    
    FILE *file; //criando o arquivo no banco de dados(pasta)
    file = fopen(arquivo, "w"); //cria o arquivo, w write
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
	
int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
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
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("O usu�rio n�o se encontra no sistema!. \n");
	system("pause");	
	}
}

int main ()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por dar um F5 na pag e deletar 
		
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar os nomes\n\n");
	printf("\t4 - Sair do sistema\n\n"); 
	printf("Op��o: "); //final do menu
	
	
	scanf("%d", &opcao); //armazenando as informa��es
	
	system("cls");
	
	switch(opcao) //inicio da sele��o do menu
	{
		case 1: //cliente registra o nome 
	    registro(); 
		break;
		
		case 2: //cliente consulta o nome
		consultar();
		break;
		
		case 3: //cliente deleta o nome 
	    deletar();
		break;
		
		case 4: //cliente sai do sistema 
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
		
		default: 
		printf("Est� op��o n�o est� disponivel!\n");
	 	system("pause");
		break;  	
	}
	
	 }
}
