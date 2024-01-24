#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0, optipo, cont;
char ftcomida[150], ftcomidaM[150];

typedef struct {
	char comida[150];
	double quantidade;
	char tipo[10];
    int tip;
	double valor;	
} Registro;

Registro registro[145];

//FUNCAO PARA TORNAR A STRING EM MAIUSCULO
void maiusculo (char s1[], char s2[]) {
    int s = 0;
    while (s1[s] != '\0') {
        s2[s] = toupper(s1[s]);
        s++;
    }
    s2[s] = '\0';
}

// FUNCAO PARA CADASTRAR UM PEDIDO
void pedido () {

    // Limpar o buffer do teclado antes da leitura
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("\n--------REGISTRO DE PEDIDO--------\n");

    printf("\nInforme o prato desejado:\n");
	scanf("%[^\n]", registro[i].comida);

    printf("Informe a quantidade desejada:\n");
	scanf("%lf", &registro[i].quantidade);

    printf("Informe o tipo:\n");
    printf("(1) Unidade\n");
    printf("(2) Porcao\n");
    printf("(3) kg\n");
    scanf("%d", &optipo);
	switch (optipo){
        case 1:
            registro[i].tip = 1;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

        case 2:
            registro[i].tip = 2;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

        case 3:
            registro[i].tip = 3;
            strcpy(registro[i].tipo, "kg");
            break;

        default:
            printf("Opcao invalida");
            break;
    }
    
    printf("Informe o valor do prato:\n");
	scanf("%lf", &registro[i].valor);

    printf("\n--------PEDIDO REGISTRADO--------\n");
	i++;
};

//FUNCAO PARA LISTAR OS PEDIDOS
void listar () {
    for (cont = 0; cont < i; cont++) {
        printf("\n--------PEDIDO %d--------\n", cont+1);
        printf("%s\n", registro[cont].comida);
        printf("%.1lf %s\n", registro[cont].quantidade, registro[cont].tipo);
        printf("Valor: R$%.2lf\n", registro[cont].valor);
        }
    printf("\n--------FIM DOS PEDIDOS--------\n");
}

//FUNCAO PARA FILTRAR OS PEDIDOS POR NOMES
void filtrarNomes () {
    char convert[150];
    // Limpar o buffer do teclado antes da leitura
    int o, c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Informe o prato:");
    scanf("%[^\n]", &ftcomida);
    maiusculo(ftcomida, ftcomidaM);
    for (o = 0; o<i; o++) {
        maiusculo(registro[o].comida, convert);
        int result = strcmp(convert, ftcomidaM);
        if (result == 0) {
            printf("\n--------PEDIDO %d--------\n", o+1);
            printf("%s\n", registro[o].comida);
            printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
            printf("Valor: R$%.2lf\n", registro[o].valor);
        }
    }
}

//FUNCAO PARA FILTRAR OS PEDIDOS POR TIPO
void filtrarTipo() {
    int o, opt;
    printf("Informe o tipo que deseja filtrar:\n");
    printf("(1) Unidade(s)\n");
    printf("(2) Porcao(oes)\n");
    printf("(3) kg\n");
    scanf("%d", &opt);

    switch (opt) {
        case 1:
            for (o = 0; o < i; o++) {
                if (registro[o].tip==1) {
                    printf("\n--------PEDIDO %d--------\n", o + 1);
                    printf("%s\n", registro[o].comida);
                    printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
                    printf("Valor: R$%.2lf\n", registro[o].valor);
                }
            }
            break;
        case 2:
            for (o = 0; o < i; o++) {     
                if (registro[o].tip==2) {
                    printf("\n--------PEDIDO %d--------\n", o + 1);
                    printf("%s\n", registro[o].comida);
                    printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
                    printf("Valor: R$%.2lf\n", registro[o].valor);
                }
            }
            break;
        case 3:
            for (o = 0; o < i; o++) {
                if (registro[o].tip==3) {
                    printf("\n--------PEDIDO %d--------\n", o + 1);
                    printf("%s\n", registro[o].comida);
                    printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
                    printf("Valor: R$%.2lf\n", registro[o].valor);
                }
            }
            break;
        default:
            printf("Opcao invalida!\n");
    }
};


int main() {
	
	int op, opf;
	
	printf("*****************************\n");
	printf("BOTEQUIN DO CARECA\n");
	printf("*****************************\n");
    while (op!=4) {
	    printf("\nInforme a operacao que deseja realizar:\n");
	    printf("(1) Registrar pedido\n");
	    printf("(2) Listar pedidos\n");
        printf("(3) Filtrar prato\n");
        printf("(4) Sair\n");
	    scanf("%d", &op);
        switch(op) {
	   
	    	case 1:
	    		pedido ();
                break;

		    case 2:
			    listar();
                break;

            case 3:
                printf("Deseja filtar por nome ou tipo?\n");
                printf("(1) Nome\n");
                printf("(2) Tipo\n");
                scanf("%d", &opf);
                if (opf == 1){
                    filtrarNomes();
                    break;
                }

                if (opf ==2){
                    filtrarTipo();
                    break;
                }

                else {
                    printf("Opcao invalida!");
                    break;
                }
            
            case 4:
                printf("\n--------PROGRAMA ENCERRADO--------\n");
	    		return 0;
            
	    	default:
		        printf("Opcao errada!\n");
    		    break; 
	    };
    };
	
	return 0;
}