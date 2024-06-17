#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Criação de struct referente a um departamento*/
typedef struct Departamento{
	int id;
	char nome[50];
} DEPARTAMENTO;

/*Criação de struct referente a um funcionário*/
typedef struct Funcionario{
	int id;
	char nome[50];
	float salario;
	int cod_depart;
} FUNCIONARIO;

/*
Função responsável por cadastrar um departamento: Inicialmente é aberto o arquivo binário de gravação e leitura
(departamentos.txt) onde os dados são adicionados no final do arquivo caso ele exista, caso contrário, o arquivo
é criado. Na sequência, é feito a leitura da quantidade de departamentos a serem cadastrados, onde em cada ciclo
do laço de repetição é feito a leitura dos dados do departamento e cadastrado o mesmo no arquivo.
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
Função responsável por cadastrar um funcionário: Inicialmente é aberto o arquivo binário de gravação e leitura
(funcionarios.txt) onde os dados são adicionados no final do arquivo caso ele exista, caso contrário, o arquivo
é criado. Na sequência, é feito a leitura da quantidade de funcionários a serem cadastrados, onde em cada ciclo
do laço de repetição é feito a leitura dos dados do funcionário e cadastrado o mesmo no arquivo. Ao realizar a
leitura do departamento do funcionário, possui uma validação que percorre o arquivo de departamentos para verificar
se o departamento existe.
*/
void cadastrar_funcionario(){
	int qtde, i, aux;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;
	
	printf("\nQuantos funcionários deseja cadastrar? ");
	scanf("%d", &qtde);
	
	for(i = 0; i < qtde; i++){
		aux = 0;
		printf("\nID: ");
		scanf("%d", &func.id);
		printf("Nome: ");
		fflush(stdin);
		gets(func.nome);
		printf("Salário: ");
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
				printf("Departamento não cadastrado!\n");
			}
		}
		fwrite(&func, sizeof(FUNCIONARIO), 1, arq_func);
	}
	fclose(arq_func);
	fclose(arq_depart);
}

/*
Função responsável por listar todos os departamentos cadastrados: Inicialmente ao abrir o arquivo, o cursor é direcionado
ao início do arquivo, na sequência é realizado a impressão dos dados de cada departamento. Caso não possua nenhum departamento
cadastrado é exibido uma mensagem ao usuário.
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
		printf("Não possui nenhum departamento cadastrado!\n");
	}
	
	fclose(arq);
}

/*
Função responsável por listar todos os funcionários de um departamento: Inicialmente ao abrir o arquivo, é feito a
leitura de qual departamento será listado os seus funcionários, na sequência o cursor é direcionado ao início do arquivo,
onde a cada ciclo do laço de repetição é verificado no arquivo de funcionários o id do departamento de cada funcionário
e comparado com o id do departamento informado pelo usuário, e quando verdadeiro é impresso os dados dos funcionários.
Caso o departamento não possua nenhum funcionário é exibido uma mensagem ao usuário.
*/
void listar_funcionario_departamento(){
	int id_depart, aux_depart = 0, aux_func = 0;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;
	
	while(aux_depart == 0){
		printf("\nDeseja visualizar os funcionários de qual departamento? ");
		scanf("%d", &id_depart);
		rewind(arq_depart);
		while(fread(&depart, sizeof(DEPARTAMENTO), 1, arq_depart) != 0){
			if(depart.id == id_depart){
				aux_depart = 1;
				break;
			}
		}
	
		if(aux_depart == 0){
			printf("Departamento não cadastrado!\n");
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
		printf("Departamento sem funcionário!\n");
	}
	
	fclose(arq_func);
	fclose(arq_depart);
}


/*
Função responsável por buscar funcionário pelo id: o primeiro passo é abrir o arquivo, então é solicitado o id ao usuário e armazenado,
em seguida a leitura do arquivo é voltado ao início para o ponteiro ir ao inicio do arquivo. Posteriormente é checado se há dados,
então se o id passado pelo usuário é correspondente a algum funcionário este sendo é retornado o mesmo, não havendo id igual
armazenado será exibido uma mensagem de aviso ao usuário.
*/
void buscar_funcionario_id(){
	int id_fun, aux = 0;
	FILE *arq_func = fopen("funcionarios.txt", "a+b");
	FILE *arq_depart = fopen("departamentos.txt", "a+b");
	FUNCIONARIO func;
	DEPARTAMENTO depart;

	printf("\nDeseja visualizar qual funcionário? ");
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
		printf("Funcionário não existe.\n");
	}
	
	fclose(arq_func);
	fclose(arq_depart);
}

/*
Função responsável por excluir funcionário pelo id: o primeiro passo é abrir o arquivo de funcionários e abrir o arquivo temp,
então é solicitado o id ao usuário e armazenado. Posteriormente é checado se há dados, então se o id passado pelo usuário não é
correspondente a algum funcionário não sendo é escrito no arquivo temp. Caso tenha o id digitado pelo usuário o arquivo
funcionários será deletado o arquivo temp será renomeado para funcionários e então informado ao usuário que o funcionário
correspondente foi removido, caso contrário o arquivo temp será deletado e exibido uma mensagem avisando que não tinha usuário
com aquele id.  
*/

void remover_funcionario() {
    int id_fun, aux = 0;
    FILE *arq = fopen("funcionarios.txt", "rb");
    FILE *temp_arq = fopen("temp.txt", "wb");
    FUNCIONARIO func;

    printf("\nDeseja remover qual funcionário? ");
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
        printf("Funcionário %d removido com sucesso.\n", id_fun);
    } else {
        remove("temp.txt");
        printf("Funcionário não existe.\n");
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao_menu;
	
	while(1){
		
		printf("\n1 - Cadastrar departamento\n");
		printf("2 - Cadastrar funcionário\n");
		printf("3 - Listar departamentos\n");
		printf("4 - Listar funcionários de um departamento\n");
		printf("5 - Buscar funcionário por ID\n");
		printf("6 - Remover funcionário\n");
		printf("0 - Sair\n");
		
		printf("\nOpção: ");
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
