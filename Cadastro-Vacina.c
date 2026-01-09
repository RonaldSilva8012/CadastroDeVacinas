#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>


struct Usuario{
	char nome [50];
	char cpf [14];
	char vacina [25];
    char data [11];
    int nLote;
};

struct Usuario cadastrarUsusario(){
	
	struct Usuario vacina;
	printf("Informe o nome do usuario\n");
	fflush (stdin);
	gets(vacina.nome);
	printf("Digite o CPF\n");
	fflush (stdin);
	gets(vacina.cpf);
	printf("Digite a Vacina\n");
	fflush (stdin);
	gets(vacina.vacina);
	printf("Digite a data da aplicação\n");
	fflush (stdin);
	gets(vacina.data);
	printf("Digite o número do lote\n");
	fflush(stdin);
	scanf("%d", &vacina.nLote);
	
	return vacina;
}
void listarUsuarios(struct Usuario usuarios[999], int qtdUsuario){
	int i, codigo;
	for(i = 0; i < qtdUsuario; i++){
			printf("===============================\n");
			printf("Codigo %d\n", i+1);
			printf("Nome: %s\n", usuarios[i].nome);
			printf("CPF: %s\n", usuarios[i].cpf);
			printf("Vacina: %s\n", usuarios[i].vacina);
			printf("Data: %s\n", usuarios[i].data);
			printf("Número do lote: %d\n", usuarios[i].nLote);
	}
}

void buscarcpf(struct Usuario usuarios[999], int qtdUsuario){
	char buscar [20];
	int acha,i,cpfEncontrado;
	printf("Digite o CPF que deseja buscar:\n");
	scanf("%s", &buscar);
	for(i = 0; i < qtdUsuario; i++){
	if(strcmp(buscar, usuarios[i].cpf ) == 0)
		{
		acha++;
		printf("===============================\n");
		printf("Nome: %s\n", usuarios[i].nome);
		printf("CPF: %s\n", usuarios[i].cpf);
		printf("Vacina: %s\n", usuarios[i].vacina);
		printf("Data: %s\n", usuarios[i].data);
		printf("Número do lote: %d\n", usuarios[i].nLote);
		}
	}
	if (strcmp(buscar,usuarios[i].cpf)== 1)
		{ 
		printf("CPF não encontrado\n");
		}
	}

void main() {
	int opcao = 0;
	int contUsuario = 0;
	struct Usuario cadUsuario[999];
	do {
		setlocale(LC_ALL,"portuguese");
		printf("Digite uma opção\n 1 - Cadastrar Vacina\n 2 - Listar Aplicações\n 3 - Consultar por CPF\n 4 -Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1: {
				cadUsuario[contUsuario] = cadastrarUsusario();
				contUsuario ++;
				break;
			}
			case 2: {
				listarUsuarios(cadUsuario, contUsuario);
				break;
			}
			case 3: {
				buscarcpf (cadUsuario, contUsuario );
				break;
			        }
			case 4: {
				printf("Finalizando o Programa\n");
				break;
			}
			default: {
				printf("Opção Invalida\n");
				break;
			}
		} 
	} while(opcao != 4);	
}
