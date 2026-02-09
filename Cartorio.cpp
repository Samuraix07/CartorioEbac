#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função resposavel por cadastra os usuários no sistema
{
    //inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
	FILE *file; //cria o arquivo
    file= fopen(arquivo, "w"); // cria o arquivo eo "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Coletando as infomações do usuário
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,nome); //salvar o valor da variável
    fclose(file); //fechar oarquivo
    
	file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fechar o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando asz informações do usuário
    scanf("%s", sobrenome); //%s refere-se a string 
    
    file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,sobrenome); //salva o valor da variável
    fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fechar o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
    scanf("%s",cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file,cargo); //salva o valor da variável
    fclose(file); //fechar o arquivo
    
	file = fopen(arquivo, "a"); //criar o arquivo
    fprintf(file, ","); //salva o valor da variável
    fclose(file); //fechar o arquivo
    
    system("pause");
    
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
     
     //inicio criação de variáveis/string
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: "); //Coletando imformações do usuário
    scanf("%s",cpf); //%s refere-se a string
    
    FILE *file;
    file = fopen(cpf,"r"); //criar o arquivo
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
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
    char cpf[40]; //inicio da criação da variavel
    
    printf("Digite o CPF do usúario a ser deletado: "); //coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a string
    
	remove(cpf); //Deletando usúariio existente 
	
	FILE *file; //Consultar a biblioteca
	file = fopen(cpf, "r");
	
	if(file == NULL)  // Caso não encontre o usúario no systema
	{
		printf("O usúario não se encontra no sistema!.\n");
		system("pause");
	}
	
	else
	{
	    remove(cpf); //Agora você pode remover o arquivo
		printf("Usúario deletado com sucesso!Obrigado!.\n");
		system("pause");
		
	}
}
int main()
{
    int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
       printf("### Cartório da EBAC ###\n\n"); //inicio do menu
       printf("Escolha a opção desejada do menu:\n\n");
       printf("\t1 - registrar nomes\n");
       printf("\t2 - Consltar nomes\n");
       printf("\t3 - Deletar nomes\n\n");
       printf("\t4 - Sair do sistema\n\n");
       printf("opção: "); //fim do menu
    
       scanf("%d", &opcao); //armazenando a escolha do usuário
     
	   system("cls"); //resposavel por limpa a tela
	   
	    switch(opcao) //inicio da seleção do menu
	   {
	   	  case 1:
	   	  registro(); //chamada de funções
		  break;
		  
		  case 2:
		  consulta();
		  break;
		  
		  case 3:
		  deletar();
		  break;
		  
		  case 4:
		  	printf("Obrigado por ultilizar nosso sistema!\n");
		  	return 0;
		    break;
		  
		  default:
		   printf("essa opcao não esta disponivel!\n");
		   system("pause");
		   break;	
	   } //fim da seleção
    }
}
