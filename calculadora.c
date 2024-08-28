#include <stdio.h>
#include <string.h>
#include <math.h>

int conv(int resp, int opcao) {
    int tamanho = (int)(log2(resp)) + 1;
    int resto, array[tamanho];
    int cont = 0;
    int numero = 0;

    while(resp > 0) {
        resto = resp % opcao;
        array[cont] = resto;
        resp /= opcao;
        cont++;
    }

    for(int i = cont - 1; i >= 0; i--) {
        numero = numero * 10 + array[i];
    }

    return numero;
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



int main(){
printf("Maria Fernanda Suruagy Ordonho - 3A (Última atualização = 28/08/2024 - 14:49)\n1.a(11:55)\n1.b(12:07)\n1.c(14:25)\n1.d(14:31)\n2(14:49)\n3(Não feito)\n");
  
  printf("\n\n----CALCULADORA DE CONVERSÃO----\n\nEscolha uma opção:\n(1)Base 10 --> Base 2\n(2)Base 10 --> base 8\n(3)Base 10 --> base 16\n(4)Base 10 --> Código BCD\n(5)Base 10 --> Complemento a 2\n(6)Decimal --> Float e Double\n\n");

  int opt, n;
  printf("Opção:");
  scanf("%d",&opt);

  if(opt==1){
    printf("Digite um número: ");
    scanf("%d",&n);
    printf("%d em base2 = %d",n,conv(n, 2));
  }

  else if(opt==2){
    printf("Digite um número: ");
    scanf("%d",&n);
    printf("%d em base8 = %d",n,conv(n, 8));
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
    
  }
  return 0;

  
}
