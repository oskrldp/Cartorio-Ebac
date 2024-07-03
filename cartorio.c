#include<stdio.h>//biblioteca de comunica��o com o usuario
#include<stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include<locale.h>//biblioteca de aloca��es de texto por regi�o
#include<string.h>//biblioteca de stirng

int registrar(){//fun��o responsavel por cadastrar usuarios

	setlocale(LC_ALL,"Portuguese");//definindo a linguagem 
//inicio de cria��o de variaveis string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	
	printf("Por favor insire o cpf a ser cadastrado: ");//coletando informa��o de usuario
	scanf("%s", cpf);//para salvar string
	
	strcpy(arquivo, cpf);//responsavel por copiar valores da string
	
	FILE* file;//cria arquivo
	file = fopen(arquivo, "w");//cria arquivo
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a");//atualizar a informa��o do arquivo
	fprintf(file,"| |nome: ");//separar cpf do nome
	fclose(file);//fechar arquivo
	
	printf("Digite o primeiro nome: ");//informar ao usuario qual nome quer cadastrar
	scanf("%s", nome);//salvar string inserida
	file = fopen(arquivo, "a");//atualizar a informa��o do arquivo
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//atualizar a informa��o do arquivo
	fprintf(file,"| |sobrenome: ");//separar nome do sobrenome
	fclose(file);//fecha arquivo
	
	printf("Digite o primeiro sobrenome: ");//informar ao usuario qual sobrnome quer cadastrar
	scanf("%s", sobrenome);//salvar string inserida
	file = fopen(arquivo, "a");//atualizar a informa��o do arquivo
	fprintf(file, sobrenome);//salva o valor da variavel
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//atualizar a informa��o do arquivo
	fprintf(file,"| |cargo: ");//separar sobrenome do cargo
	fclose(file);//fecha arquivo
	
	printf("Digite o cargo do usuario cadastrado: ");//informar ao usuario qual cargo quer cadastrar
	scanf("%s",cargo);//salvar string inserida
	file = fopen(arquivo, "a");//atualizar a informa��o do arquivo
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha arquivo
	
	system("pause");//pausar a aba 
}

int consultar(){//fun��o responsavel consultar ususarios
	
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem 
	//inserindo variaveis tipo string
	char cpf[40];
	char conteudo[200];
	
	printf("Porfavor insira o CPF para consultar: ");//mostrando pro ususario qual usuario ele quer consultar
	scanf("%s", cpf);//salvar string inserida
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//l� o arquivo
	
	if (file == NULL){//fun��o caso o cpf n�o esteja localizado
		printf("CPF nao localizado\n\n");//mostrando pro usuario que o cpf n�o foi localizado
	}
	
	while (fgets(conteudo, 200, file) != NULL){//enquanto a informa��o inserida esteja no file continuar a fun��o while, enquanto n�o, continuar pra fun��o if NULL
		printf("\n Informa��es encontradas com sucesso\n\n");//informando ao usuario que o usuario foi consulrado 
		printf(" |cpf: ");//identificando cpf , so pra ficar bonitinho
		printf("%s", conteudo);//mostrar a string conteudo
		printf("\n\n");
	}

system("pause");//pausar a aba
	
}
int deletar(){//fun��o para deletar o usuarios cadastrados
	
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem 
	
	char cpf[40];//insereindo variavel tipo string
	printf("Digite o CPF que deseja remover: ");//informando pro usuario informar o cpf
	scanf("%s", cpf);//salvar string
	
	remove(cpf);//fun��o para remover o cpf
	
	FILE *file;//criar arquivo
	file=fopen(cpf,"r");//ler o arquivo
	
	if(file == NULL){//fun��o para caso nao tenha nenum cpf a deletar 
		printf("O usuario n�o se encontra mais no sistema\n");//mostrando pro cliente que o usuario foi deletado
		system("pause");//pausar a aba
	}
}
int main(){//func�ao principal
	//definindo variaveis
	int opcao = 0;
	int laco = 1;
	for(laco = 1;laco = 1;)
	{
		system("cls");//limpa  a tela 
		
		setlocale(LC_ALL,"Portuguese");//definindo a linguagem 
	
		printf("###CART�RIO DA EBAC###\n\n");//inicio do menu
		printf("Escloha a op��o a desejar:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d",&opcao);//armazenando escolha do usuario
	
		system("cls");//limpa a tela
		
		switch(opcao)//mostrando o resultado selecionado
		{
			case 1://chamada de fun��es
				registrar();
			break;
				
			case 2:
				consultar();			
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Esta op��o n�o est� disponivel\n");
				system("pause");
			break;			
		}//final da sele��o 
	}
}

