#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* conv(int resp, int opcao) {
    if (resp == 0) {
        char* binario = (char*)malloc(2 * sizeof(char));
        if (binario == NULL) {
            printf("Erro ao alocar memória!\n");
            return NULL;
        }
        binario[0] = '0';
        binario[1] = '\0';
        return binario;
    }

    int tamanho = (int)(log2(resp)) + 1;
    char* binario = (char*)malloc((tamanho + 1) * sizeof(char));
    int cont = 0;
    int resto;

    if (binario == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    while (resp > 0) {
        resto = resp % opcao;
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

    return binario;
}

void convHex(int num) {
    int hex[32];
    int cont = 0;

    while (num > 0) {
        hex[cont] = num % 16;
        num = num / 16;
        cont++;
    }
    for (int inversor = cont - 1; inversor >= 0; inversor--) {
        if (hex[inversor] < 10) {
            printf("%d", hex[inversor]);
        } else {
            printf("%c", hex[inversor] + 55);
        }
    }
}

void convBCD(int n) {
    int temp = n;
    int tam = 0;
    while(temp != 0) {
        temp /= 10;
        tam++;
    }

    int bcd[tam];
    temp = n;

    for(int i = tam - 1; i >= 0; i--) {
        int digit = temp % 10;
        bcd[i] = digit;
        temp /= 10;
    }

    for(int i = 0; i < tam; i++) {
        switch(bcd[i]) {
            case 0: printf("0000 "); break;
            case 1: printf("0001 "); break;
            case 2: printf("0010 "); break;
            case 3: printf("0011 "); break;
            case 4: printf("0100 "); break;
            case 5: printf("0101 "); break;
            case 6: printf("0110 "); break;
            case 7: printf("0111 "); break;
            case 8: printf("1000 "); break;
            case 9: printf("1001 "); break;
        }
    }
    printf("\n");
}

void convComp2(int n){
  for (int i = 15; i >= 0; i--) {
      printf("%d", (n >> i) & 1);
  }
}

void binariotonotacao(int sinal,const char *binario, char *notacao, int *expoente) {
    int comprimento = strlen(binario);
    int i, posicaoPonto = 0;
    int primeiroDigito = 0;

    for (i = 0; i < comprimento; i++) {
        if (binario[i] == '1') {
            primeiroDigito = i;
            break;
        }
    }

    if (primeiroDigito == comprimento) {
        strcpy(notacao, "0.0 * 2^0");
        *expoente = 0;
        return;
    }

    posicaoPonto = comprimento - primeiroDigito - 1;
    *expoente = posicaoPonto;

    char mantissa[24];
    int indicemantissa = 0;

    for (i = primeiroDigito + 1; i < comprimento && indicemantissa < 23; i++) {
        mantissa[indicemantissa++] = binario[i];
    }

    while (indicemantissa < 23) {
        mantissa[indicemantissa++] = '0';
    }

    mantissa[23] = '\0';
    
    printf("\nBit de sinal: %d\n", sinal);
    printf("Expoente: %d\n", posicaoPonto);
    printf("Expoente com viés: %s\n", conv(posicaoPonto+127,2));
    printf("Mantissa: %s\n", mantissa);
    
}

int main(){
printf("Maria Fernanda Suruagy Ordonho - 3A (Última atualização = 30/08/2024-14:49)\n1.a(28/08-11:55)\n1.b(28/08-12:07)\n1.c(28/08-14:25)\n1.d(28/08-14:31)\n2(28/08-14:49)\n3(30/08-15:45)\n");

  printf("\n\n----CALCULADORA DE CONVERSÃO----\n\nEscolha uma opção:\n(1)Base 10 --> Base 2\n(2)Base 10 --> base 8\n(3)Base 10 --> base 16\n(4)Base 10 --> Código BCD\n(5)Base 10 --> Complemento a 2\n(6)Decimal --> Float e Double\n\n");

  int opt, n;
  printf("Opção:");
  scanf("%d",&opt);

  if(opt==1){
    printf("Digite um número: ");
    scanf("%d",&n);
    char* resultado = conv(n,2);
      if(resultado!=NULL){
    printf("%d em base2 = %s",n,resultado);
      }
    free(resultado);
  }

  else if(opt==2){
    printf("Digite um número: ");
    scanf("%d",&n);
      char* resultado = conv(n,8);
      printf("%d em base2 = %s",n,resultado);
        free(resultado);
  }
  else if(opt==3){
   printf("Digite um número: ");
        scanf("%d",&n);
        printf("%d em base16 = ",n);
        convHex(n);
  }

  else if(opt==4){
      printf("Digite um número: ");
      scanf("%d",&n);
      printf("%d em BCD = ",n);
      convBCD(n);
  }

  else if(opt==5){
      printf("Digite um número: ");
        scanf("%d",&n);
        printf("%d em complemento a 2 = ",n);
        convComp2(n);
  }
  else if(opt==6){
      char notacao[50];
      int expoente;
      printf("Digite um número: ");
      scanf("%d",&n);

      if(n<0){
          
          char *binario = conv(n*-1,2);
          binariotonotacao(1,binario, notacao, &expoente);
          
      } else {
          
      char *binario = conv(n,2);
      binariotonotacao(0,binario, notacao, &expoente);
      
      }

  } else {
      printf("Opção inválida!");
  }
  return 0;


}
