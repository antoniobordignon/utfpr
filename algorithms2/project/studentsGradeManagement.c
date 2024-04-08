#include <stdio.h>

void boasVindas() {
  printf("Ola, seja bem vindo ao Gerenciador de Notas de Alunos!\n\n");
}

void Configuracao() {
  printf("Para iniciar, por favor nos informe quantos alunos serao adicionados.\n");
  int quantidadeAlunos;
  scanf("%d", &quantidadeAlunos);

}

int main(){
  boasVindas();
  Configuracao();
}
