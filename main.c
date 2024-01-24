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
    double preco;
	double valor;
    int mesa;
    int delivery;	
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
    int c, op2, p1, p2;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("\n--------REGISTRO DE PEDIDO--------\n");

    printf("\nMesa ou Delivery?\n");
    printf("(1) Mesa\n");
    printf("(2) Delivery\n");
    scanf("%d", &op2);
    
    switch (op2) {
        case 1:
        do {
            printf("\nInforme o numero da mesa:");
            scanf("%d", &registro[i].mesa);

            if (registro[i].mesa > 20) {
                printf("Opcao invalida! O numero da mesa deve ser igual ou menor que 20.\n");
            }
        } while (registro[i].mesa > 20);
        break;

        case 2:
        printf("Informe o numero do delivery:");
        scanf("%d", &registro[i].delivery);
        registro[i].delivery += 100;
        break;


        default:
        printf("Opcao invalida!\n");
        break;
    }

    printf("\nInforme o prato desejado:\n");
    printf("(1) Petiscos\n");
    printf("(2) Sanduiches\n");
    printf("(3) Pratos Principais\n");
    printf("(4) Bebidas\n");
    printf("(5) Sobremesas\n");
    scanf("%d", &p1);

    switch (p1) {
        case 1:
        printf("\n(1) Bolinho de Bacalhau (6 unidades)\n");
        printf("(2) Pastel de Carne Seca com Queijo (porcao com 8 unidades)\n");
        printf("(3) Calabresa Acebolada\n");
        printf("(4) Frango a Passarinho\n");
        printf("(5) Sarapatel\n");
        printf("(6) Linguica de Dumont\n");
        printf("(7) Buchada de Bode (porcao individual)\n");
        printf("(8) Cabeca de Macaco (porcao para compartilhar)\n");
        scanf("%d", &p2);        
        switch (p2) {
            case 1:
            strcpy(registro[i].comida, "Bolinho de Bacalhau");
            registro[i].preco = 18.90;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 2:
            strcpy(registro[i].comida, "Pastel de Carne Seca com Queijo");
            registro[i].preco = 15.50;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 3:
            strcpy(registro[i].comida, "Calabresa Acebolada");
            registro[i].preco = 16.80;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 4:
            strcpy(registro[i].comida, "Frango a Passarinho");
            registro[i].preco = 20.50;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 5:
            strcpy(registro[i].comida, "Sarapatel");
            registro[i].preco = 26.90;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 6:
            strcpy(registro[i].comida, "Linguica de Dumont");
            registro[i].preco = 24.50;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 7:
            strcpy(registro[i].comida, "Buchada de Bode");
            registro[i].preco = 29.90;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            case 8:
            strcpy(registro[i].comida, "Cabeca de Macaco");
            registro[i].preco = 35.90;
            strcpy(registro[i].tipo, "porcao(oes)");
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

        case 2:
        printf("\n(1) Sanduiche de Pernil\n");
        printf("(2) X-Bacon\n");
        printf("(3) Misto Quente de Linguica\n");
        scanf("%d", &p2);
        switch (p2) {
            case 1:
            strcpy(registro[i].comida, "Sanduiche de Pernil");
            registro[i].preco = 22.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 2:
            strcpy(registro[i].comida, "X-Bacon");
            registro[i].preco = 25.50;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 3:
            strcpy(registro[i].comida, "Misto Quente de Linguica");
            registro[i].preco = 18.50;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

        case 3:
        printf("\n(1) Feijoada Completa (porcao individual)\n");
        printf("(2) Strogonoff de Carne\n");
        printf("(3) Espaguete a Carbonara\n");
        scanf("%d", &p2);
        switch (p2) {
            case 1:
            strcpy(registro[i].comida, "Feijoada Completa");
            registro[i].preco = 32.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 2:
            strcpy(registro[i].comida, "Strogonoff de Carne");
            registro[i].preco = 28.50;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 3:
            strcpy(registro[i].comida, "Espaguete a Carbonara");
            registro[i].preco = 24.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

        case 4:
        printf("\n(1) Caipirinha Tradicional\n");
        printf("(2) Chopp Artesanal (300ml)\n");
        printf("(3) Coquetel de Frutas com Alcool\n");
        scanf("%d", &p2);
        switch (p2) {
            case 1:
            strcpy(registro[i].comida, "Caipirinha Tradicional");
            registro[i].preco = 14.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 2:
            strcpy(registro[i].comida, "Chopp Artesanal (300ml)");
            registro[i].preco = 8.50;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 3:
            strcpy(registro[i].comida, "Coquetel de Frutas com Alcool");
            registro[i].preco = 16.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

        case 5:
        printf("\n(1) Petit Gateau de Chocolate\n");
        printf("(2) Pudim de Leite Condensado\n");
        printf("(3) Mousse de Maracuja\n");
        scanf("%d", &p2);
        switch (p2) {
            case 1:
            strcpy(registro[i].comida, "Petit Gateau de Chocolate");
            registro[i].preco = 14.50;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 2:
            strcpy(registro[i].comida, "Pudim de Leite Condensado");
            registro[i].preco = 10.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            case 3:
            strcpy(registro[i].comida, "Mousse de Maracuja");
            registro[i].preco = 12.90;
            strcpy(registro[i].tipo, "unidade(s)");
            break;

            default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

        default:
        printf("Opcao invalida!\n");
        break;

    }

    printf("\nInforme a quantidade desejada:\n");
	scanf("%lf", &registro[i].quantidade);

    registro[i].valor = registro[i].preco * registro[i].quantidade;

    printf("\n--------PEDIDO REGISTRADO--------\n");
	i++;
};

//FUNCAO PARA LISTAR OS PEDIDOS
void listar () {
    for (cont = 0; cont < i; cont++) {
        printf("\n--------PEDIDO %d--------\n", cont+1);
        printf("Mesa: %d\n", registro[cont].mesa);
        printf("%s\n", registro[cont].comida);
        printf("Preco: %.2lf\n",registro[cont].preco);
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
            printf("Mesa: %d\n", registro[o].mesa);
            printf("%s\n", registro[o].comida);
            printf("Preco: %.2lf\n",registro[o].preco);
            printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
            printf("Valor: R$%.2lf\n", registro[o].valor);
        }
    }
}

//FUNCAO PARA FILTRAR OS PEDIDOS POR MESA
void filtrarMesa() {
    int o, opmesa;
    int list = 1;
    int comPedido = 0;
    printf("Informe a mesa:\n");
    scanf("%d", &opmesa);
    printf("\n------------PEDIDOS DA MESA %d------------\n", opmesa);

    for (o = 0; o < i; o++) {
        if (registro[o].mesa == opmesa) {
            comPedido = 1;
            printf("\n--------PEDIDO %d--------\n", list);
            printf("%s\n", registro[o].comida);
            printf("Preco: %.2lf\n",registro[o].preco);
            printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
            printf("Valor: R$%.2lf\n", registro[o].valor);
            list++;
        }
    }
    
    if (comPedido == 0) {
    printf("\nMESA SEM PEDIDOS\n");
    }
    printf("\n-----------------------------------------\n");
};

//FUNCAO PARA FECHAR CONTA
void fecharConta() {
    int o, opmesa;
    int list = 1;
    int comPedido = 0;
    double total = 0;
    printf("\nInforme a mesa:");
    scanf("%d", &opmesa);
    printf("\n------------PEDIDOS DA MESA %d------------\n", opmesa);

    for (o = 0; o < i; o++) {
        if (registro[o].mesa == opmesa) {
            comPedido = 1;
            printf("\n--------PEDIDO %d--------\n", list);
            printf("%s\n", registro[o].comida);
            printf("Preco: %.2lf\n",registro[o].preco);
            printf("%.1lf %s\n", registro[o].quantidade, registro[o].tipo);
            printf("Valor: R$%.2lf\n", registro[o].valor);
            total += registro[o].valor;
            list++;
        }
    }
    
    if (comPedido == 0) {
    printf("MESA SEM PEDIDOS");
    }
    printf("\n-----------------------------------------\n", opmesa);
    printf("\nTOTAL: R$%.2lf\n", total);
    printf("\n-----------------------------------------\n", opmesa);
};



int main() {
	
	int op;
	
	printf("*****************************\n");
	printf("SABORES EXOTICOS\n");
	printf("*****************************\n");
    while (op!=4) {
	    printf("\nInforme a operacao que deseja realizar:\n");
	    printf("(1) Registrar pedido\n");
	    printf("(2) Listar pedidos\n");
        printf("(3) Listar pedidos por mesa\n");
        printf("(4) Filtrar prato\n");
        printf("(5) Fechar conta\n");
        printf("(6) Sair\n");
	    scanf("%d", &op);
        switch(op) {
	   
	    	case 1:
	    		pedido ();
                break;

		    case 2:
			    listar();
                break;

            case 3:
                filtrarMesa();
                break;
                
            
            case 4:
                filtrarNomes();
                break;

            case 5:
                fecharConta();
                break;

            case 6:
                printf("\n--------PROGRAMA ENCERRADO--------\n");
	    		return 0;
            
	    	default:
		        printf("Opcao errada!\n");
    		    break; 
	    };
    };
	
	
	return 0;
}