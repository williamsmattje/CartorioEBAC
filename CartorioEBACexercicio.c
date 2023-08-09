#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings
    
	int registro() //Função responsável por cadastrar os usuários no sistema.
	
{ //inicio criação de variáveis/string
    char arquivo [40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
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
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("O usuário não se encontra no sistema!. \n");
	system("pause");	
	}
}

int main ()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por dar um F5 na pag e deletar 
		
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar os nomes\n");
	printf("\t3 - Deletar os nomes\n\n");
	printf("\t4 - Sair do sistema\n\n"); 
	printf("Opção: "); //final do menu
	
	
	scanf("%d", &opcao); //armazenando as informações
	
	system("cls");
	
	switch(opcao) //inicio da seleção do menu
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
		printf("Está opção não está disponivel!\n");
	 	system("pause");
		break;  	
	}
	
	 }
}
