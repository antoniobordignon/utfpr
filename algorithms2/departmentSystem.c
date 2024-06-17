#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Cria��o de struct referente a um departamento*/
typedef struct Departamento{
	int id;
	char nome[50];
} DEPARTAMENTO;

/*Cria��o de struct referente a um funcion�rio*/
typedef struct Funcionario{
	int id;
	char nome[50];
	float salario;
	int cod_depart;
} FUNCIONARIO;

/*
Fun��o respons�vel por cadastrar um departamento: Inicialmente � aberto o arquivo bin�rio de grava��o e leitura
(departamentos.txt) onde os dados s�o adicionados no final do arquivo caso ele exista, caso contr�rio, o arquivo
� criado. Na sequ�ncia, � feito a leitura da quantidade de departamentos a serem cadastrados, onde em cada ciclo
do la�o de repeti��o � feito a leitura dos dados do departamento e cadastrado o mesmo no arquivo.
*/
void cadastrar_departamento(){
	int qtde, i;
	FILE *arq = fopen("departamentos.txt", "a+b");
	DEPARTAMENTO depart;

	printf("\nQuantos departamentos deseja cadastrar? ")	;
	scanf("%d", &qtde);
	
	for(i = 0; i < qtde; i++){
		printf("\nID: ");
		scanf("%d", &depart.id);
		printf("Nome: ");
		fflush(stdin);
		gets(depart.nome);
		fwrite(&depart, sizeof(DEPARTAMENTO), 1, arq);
	}
	fclose(arq);
}

/*
Fun��o respons�vel por cadastrar um funcion�rio: Inicialmente � aberto o arquivo bin�rio de grava��o e leitura
(funcionarios.txt) onde os dados s�o adicionados no final do arquivo caso ele exista, caso contr�rio, o arquivo
� criado. Na sequ�ncia, � feito a leitura da quantidade de funcion�rios a serem cadastrados, onde em cada ciclo
do la�o de repeti��o � feito a leitura dos dados do funcion�rio e cadastrado o mesmo no arquivo. Ao realizar a
leitura do departamento do funcion�rio, possui uma valida��o que percorre o arquivo de departamentos para verificar
se o departamento existe.
*/
void cadastrar_funcionario(){
	int qtde, i, aux;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;
	
	printf("\nQuantos funcion�rios deseja cadastrar? ");
	scanf("%d", &qtde);
	
	for(i = 0; i < qtde; i++){
		aux = 0;
		printf("\nID: ");
		scanf("%d", &func.id);
		printf("Nome: ");
		fflush(stdin);
		gets(func.nome);
		printf("Sal�rio: ");
		scanf("%f", &func.salario);
		
		while(aux == 0){
			printf("ID departamento: ");
			scanf("%d", &func.cod_depart);
			
			rewind(arq_depart);
			while(fread(&depart, sizeof(DEPARTAMENTO), 1, arq_depart) != 0){
				if(depart.id == func.cod_depart){
					aux = 1;
					break;
				}
			}
			if(aux == 0){
				printf("Departamento n�o cadastrado!\n");
			}
		}
		fwrite(&func, sizeof(FUNCIONARIO), 1, arq_func);
	}
	fclose(arq_func);
	fclose(arq_depart);
}

/*
Fun��o respons�vel por listar todos os departamentos cadastrados: Inicialmente ao abrir o arquivo, o cursor � direcionado
ao in�cio do arquivo, na sequ�ncia � realizado a impress�o dos dados de cada departamento. Caso n�o possua nenhum departamento
cadastrado � exibido uma mensagem ao usu�rio.
*/
void listar_departamentos(){
	int aux = 0;
	FILE *arq = fopen("departamentos.txt", "a+b");
	DEPARTAMENTO depart;
	
	printf("\nDepartamentos:\n");
	
	rewind(arq);
	while(fread(&depart, sizeof(DEPARTAMENTO), 1, arq) != 0){
		aux = 1;
		printf("%d - %s\n", depart.id, depart.nome);
	}
	
	if(aux == 0){
		printf("N�o possui nenhum departamento cadastrado!\n");
	}
	
	fclose(arq);
}

/*
Fun��o respons�vel por listar todos os funcion�rios de um departamento: Inicialmente ao abrir o arquivo, � feito a
leitura de qual departamento ser� listado os seus funcion�rios, na sequ�ncia o cursor � direcionado ao in�cio do arquivo,
onde a cada ciclo do la�o de repeti��o � verificado no arquivo de funcion�rios o id do departamento de cada funcion�rio
e comparado com o id do departamento informado pelo usu�rio, e quando verdadeiro � impresso os dados dos funcion�rios.
Caso o departamento n�o possua nenhum funcion�rio � exibido uma mensagem ao usu�rio.
*/
void listar_funcionario_departamento(){
	int id_depart, aux_depart = 0, aux_func = 0;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;
	
	while(aux_depart == 0){
		printf("\nDeseja visualizar os funcion�rios de qual departamento? ");
		scanf("%d", &id_depart);
		rewind(arq_depart);
		while(fread(&depart, sizeof(DEPARTAMENTO), 1, arq_depart) != 0){
			if(depart.id == id_depart){
				aux_depart = 1;
				break;
			}
		}
	
		if(aux_depart == 0){
			printf("Departamento n�o cadastrado!\n");
		}
	}
	
	rewind(arq_func);
	while(fread(&func, sizeof(FUNCIONARIO), 1, arq_func) != 0){
		if(func.cod_depart == id_depart){
			aux_func = 1;
			printf("%d - %s - R$ %.2f\n", func.id, func.nome, func.salario);
		}
	}
	
	if(aux_func == 0){
		printf("Departamento sem funcion�rio!\n");
	}
	
	fclose(arq_func);
	fclose(arq_depart);
}


/*
Fun��o respons�vel por buscar funcion�rio pelo id: o primeiro passo � abrir o arquivo, ent�o � solicitado o id ao usu�rio e armazenado,
em seguida a leitura do arquivo � voltado ao in�cio para o ponteiro ir ao inicio do arquivo. Posteriormente � checado se h� dados,
ent�o se o id passado pelo usu�rio � correspondente a algum funcion�rio este sendo � retornado o mesmo, n�o havendo id igual
armazenado ser� exibido uma mensagem de aviso ao usu�rio.
*/
void buscar_funcionario_id(){
	int id_fun, aux = 0;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;

	printf("\nDeseja visualizar qual funcion�rio? ");
	scanf("%d", &id_fun);
	
	rewind(arq_func);
	while(fread(&func, sizeof(FUNCIONARIO), 1, arq_func) != 0){
		if(func.id == id_fun){
			aux = 1;
			rewind(arq_depart);
			
			while(fread(&depart, sizeof(DEPARTAMENTO), 1, arq_depart) != 0){
				if(depart.id == func.cod_depart){
					break;
				}
			}
			printf("%d - %s - R$ %.2f - %s\n", func.id, func.nome, func.salario, depart.nome);
		}
	}
	
	if(aux == 0){
		printf("Funcion�rio n�o existe.\n");
	}
	
	fclose(arq_func);
	fclose(arq_depart);
}

/*
Fun��o respons�vel por excluir funcion�rio pelo id: o primeiro passo � abrir o arquivo de funcion�rios e abrir o arquivo temp,
ent�o � solicitado o id ao usu�rio e armazenado. Posteriormente � checado se h� dados, ent�o se o id passado pelo usu�rio n�o �
correspondente a algum funcion�rio n�o sendo � escrito no arquivo temp. Caso tenha o id digitado pelo usu�rio o arquivo
funcion�rios ser� deletado o arquivo temp ser� renomeado para funcion�rios e ent�o informado ao usu�rio que o funcion�rio
correspondente foi removido, caso contr�rio o arquivo temp ser� deletado e exibido uma mensagem avisando que n�o tinha usu�rio
com aquele id.  
*/

void remover_funcionario() {
    int id_fun, aux = 0;
    FILE *arq = fopen("funcionarios.txt", "rb");
    FILE *temp_arq = fopen("temp.txt", "wb");
    FUNCIONARIO func;

    printf("\nDeseja remover qual funcion�rio? ");
    scanf("%d", &id_fun);

    while (fread(&func, sizeof(FUNCIONARIO), 1, arq) != 0) {
        if (func.id != id_fun) {
            fwrite(&func, sizeof(FUNCIONARIO), 1, temp_arq);
        } else {
            aux = 1;
        }
    }

    fclose(arq);
    fclose(temp_arq);

    if (aux == 1) {
        remove("funcionarios.txt");
        rename("temp.txt", "funcionarios.txt");
        printf("Funcion�rio %d removido com sucesso.\n", id_fun);
    } else {
        remove("temp.txt");
        printf("Funcion�rio n�o existe.\n");
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao_menu;
	
	while(1){
		
		printf("\n1 - Cadastrar departamento\n");
		printf("2 - Cadastrar funcion�rio\n");
		printf("3 - Listar departamentos\n");
		printf("4 - Listar funcion�rios de um departamento\n");
		printf("5 - Buscar funcion�rio por ID\n");
		printf("6 - Remover funcion�rio\n");
		printf("0 - Sair\n");
		
		printf("\nOp��o: ");
		scanf("%d", &opcao_menu);
		
		switch(opcao_menu){
			case 1:
				cadastrar_departamento();
				break;
			case 2:
				cadastrar_funcionario();
				break;
			case 3:
				listar_departamentos();
				break;
			case 4:
				listar_funcionario_departamento();
				break;
			case 5:
				buscar_funcionario_id();
				break;
			case 6:
				remover_funcionario();
				break;
			case 0:
				exit(1);
		}
	}
}
