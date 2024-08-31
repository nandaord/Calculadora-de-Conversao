/*Maria Fernanda Suruagy Ordonho - 3A 
(Última atualização = 30/08-23:35)
1.a(30/08-18:11)
1.b(30/08-18:42)
1.c(30/08-20:46)
1.d(30/08-21:46)
2(30/08-22:00)
3(30/08-23:35)
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* conv(int resp, int opcao) {

    if (resp == 0) {
        char *binario = (char*)malloc(3 * sizeof(char));
        if (binario == NULL) {
            printf("Erro ao alocar memória!\n");
            return NULL;
        }
        strcpy(binario, "0");
        printf("\nResultado final da parte inteira: 0\n");
        return binario;
    }

    int tamanho = (int)(log2(resp)) + 1;
    char* binario = (char*)malloc((tamanho + 1) * sizeof(char));
    int cont = 0;
    int resto;

    while (resp > 0) {
        resto = resp % opcao;
        printf("%d %% %d = (%d)\n", resp, opcao, resto);
        binario[cont] = resto + '0';
        resp /= opcao;
        cont++;
    }

    binario[cont] = '\0';

    for (int i = 0; i < cont / 2; i++) {
        char temp = binario[i];
        binario[i] = binario[cont - 1 - i];
        binario[cont - 1 - i] = temp;
    }

    printf("\nResultado final da parte inteira: %s\n\n", binario);
    return binario;
}

char* convDecimal(double decimal, int n) {

    char* resultado = (char*)malloc(64 * sizeof(char));
    if (resultado == NULL) { 
        printf("Erro ao alocar memória.\n");
        return NULL;
    } else {

    int i = 1;
    resultado[0] = '.';
    while (decimal > 0 && i < 63) {
        decimal *= n;
        int bit = (int)decimal;
        resultado[i++] = bit + '0';
        decimal -= bit;
        printf("%.6f (%d)\n", decimal, bit);
    }

    resultado[i] = '\0';
    printf("\nResultado final da parte decimal: %s\n", resultado);
    return resultado;
}
}

void intToHex(int num, char* hexStr) {
    const char hexDigits[] = "0123456789ABCDEF";
    int i = 0;
    int j;
    char temp[20]; 

    if (num == 0) {
        hexStr[i++] = '0';
    } else {
        while (num > 0) {
            temp[i++] = hexDigits[num % 16];
            num /= 16;
        }

        for (j = 0; j < i; j++) {
            hexStr[j] = temp[i - j - 1];
        }
        hexStr[i] = '\0';
    }
}

void decimalToHex(double decimal, char* hexStr) {
    const char hexDigits[] = "0123456789ABCDEF";
    int i = 0;

    hexStr[i++] = '.';
    while (decimal > 0.0 && i < 20) {  
        decimal *= 16.0;
        int intPart = (int)decimal;
        hexStr[i++] = hexDigits[intPart];
        decimal -= intPart;
    }
    hexStr[i] = '\0';
}

void doubleToHex(double value, char* hexStr) {
    int intPart = (int)value;
    double decimalPart = value - intPart;
    char intHex[20] = {0};
    char decHex[20] = {0};

    intToHex(intPart, intHex);
    decimalToHex(decimalPart, decHex);

    sprintf(hexStr, "%s%s", intHex, decHex);
}

void convBCD(char *string) {

    int tam = strlen(string);
    for(int i=0; i<tam; i++){
       switch (string[i]){
           case '0': printf("0000 "); break;
           case '1': printf("0001 "); break;
           case '2': printf("0010 "); break;
           case '3': printf("0011 "); break;
           case '4': printf("0100 "); break;
           case '5': printf("0101 "); break;
           case '6': printf("0110 "); break;
           case '7': printf("0111 "); break;
           case '8': printf("1000 "); break;
           case '9': printf("1001 "); break; 
           case '.': printf(". ");break;
       } 
    }
}

void convComp2(int n){
    printf("Convertendo para binário com complemento a 2...\n");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void binariotonotacao(int sinal, const char *binario, char *notacao, int *expoente) {
    
    int comprimento = strlen(binario);
    int i, posicaoPonto = 0;
    int primeiroDigito = 0;
    int posicaovirgula = 0;

    for (i = 0; i < comprimento; i++) {
        if (binario[i] == '1') {
            primeiroDigito = i;
            break;
        }
    }

    for (int i=0; i<comprimento;i++){
        if(binario[i]=='.'){
            posicaovirgula = i;
            break;
        }
    }

    if (primeiroDigito == comprimento) {
        strcpy(notacao, "0.0 * 2^0");
        *expoente = 0;
        return;
    }

    posicaoPonto = posicaovirgula - primeiroDigito - 1;
    *expoente = posicaoPonto;

    char mantissa[24];
    int indicemantissa = 0;

    for (i = primeiroDigito + 1; i < comprimento && indicemantissa < 23; i++) {
        if(mantissa[indicemantissa]=='.'){

        }
        mantissa[indicemantissa++] = binario[i];
    }

    while (indicemantissa < 23) {
        mantissa[indicemantissa++] = '0';
    }

    mantissa[23] = '\0';

    printf("\nBit de sinal: (%d)\n", sinal);
    printf("Expoente: (%d)\n\n", posicaoPonto);
    printf("Expoente com viés: (%s)\n", conv(posicaoPonto + 127, 2));
    printf("Mantissa: (%s)\n", mantissa);
}

int main() {
    printf("----CALCULADORA DE CONVERSÃO----\n\nEscolha uma opção:\n(1) Base 10 --> Base 2\n(2) Base 10 --> Base 8\n(3) Base 10 --> Base 16\n(4) Base 10 --> Código BCD\n(5) Base 10 --> Complemento a 2\n(6) Decimal --> Float e Double\n\n");

    int opt;
    double n;
    printf("Opção: ");
    scanf("%d", &opt);

    if(opt == 1) {
        printf("Digite um número: ");
        scanf("%lf", &n);
        printf("\n");

        if (n<0){
            printf("Entrada apenas de números positivos!");
        } 
        else if (n==0){
            printf("\n0 em base 2 (binário) = 0");
        }
        else {
        int parteinteira = (int)n;
        double partedecimal = n-parteinteira;

        char* resultadointeiro = conv(parteinteira, 2);

        char* resultadodecimal = convDecimal(partedecimal,2);
        if(resultadointeiro != NULL) {
            printf("\n%lf em base 2 (binário) = %s%s\n", n, resultadointeiro, resultadodecimal);
        }
        free(resultadointeiro);
        free(resultadodecimal);

    }}
        if(opt == 2) {
            printf("Digite um número: ");
            scanf("%lf", &n);
            printf("\n");

            if (n<0){
                printf("Entrada apenas de números positivos!");
            } 
            else if (n==0){
                printf("\n0 em base 8 (octal) = 0");
            }
            else {
            int parteinteira = (int)n;
            double partedecimal = n-parteinteira;

            char* resultadointeiro = conv(parteinteira, 8);

            char* resultadodecimal = convDecimal(partedecimal,8);
            if(resultadointeiro != NULL) {
                printf("\n%lf em base 2 (octal) = %s%s\n", n, resultadointeiro, resultadodecimal);
            }
            free(resultadointeiro);
            free(resultadodecimal);

        }

    } else if(opt == 3) {

            printf("Digite um número: ");
                scanf("%lf", &n);
            printf("\n");

                if (n<0){
                    printf("Entrada apenas de números positivos!");
                } 
                else if (n==0){
                    printf("\n0 em base 16 (hexadecimal) = 0");
                }
                else {
                char hexStr[50];

                doubleToHex(n, hexStr);

                printf("%lf em base 16 (hexadecimal) = %s\n",n,hexStr);

            }

    } else if(opt == 4) {

            char string[30];
            printf("Digite um número: ");
                scanf("%29s", string);
            printf("\n");

                if (n<0){
                    printf("Entrada apenas de números positivos!");
                } 
                else if (n==0){
                    printf("\n0 em base 16 (hexadecimal) = 0");
                }
                else {

                convBCD(string);   
                }

        } else if(opt == 5) {

        printf("Digite um número: ");
        scanf("%lf", &n);
        if(n > 0) {
            printf("Entrada apenas de números negativos!\n");
        } else {
            convComp2(n);
        }

    } else if(opt == 6) {

            printf("Digite um número: ");
            scanf("%lf", &n);
            printf("\n");

            char notacao[50];
            int expoente;
            int parteinteira = (int)n;
            double partedecimal = n - parteinteira;

            int sinal = (n < 0) ? 1 : 0;

            if (sinal) {
                parteinteira = -parteinteira;
                partedecimal = -partedecimal;
            }

            char* resultadointeiro = conv(parteinteira, 2);
            char* resultadodecimal = convDecimal(partedecimal, 2);

            strcat(resultadointeiro, resultadodecimal);

            binariotonotacao(sinal, resultadointeiro, notacao, &expoente);

            free(resultadointeiro);
            free(resultadodecimal);

    }
    return 0;
}
