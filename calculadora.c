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


int main(){
printf("Maria Fernanda Suruagy Ordonho - 3A (Última atualização = 28/08/2024 - 12:07)\n1.a(11:55)\n1.b(12:07)\n1.c(Não feito)\n1.d(Não feito)\n2(Não feito)\n3(Não feito)\n");
  
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
   
  }
    
  else if(opt==4){
    
  }
  else if(opt==5){
    
  }
  else if(opt==6){
    
  }
  return 0;

  
}
