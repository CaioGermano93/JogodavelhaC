#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];

typedef struct jogador{

     char jogador1[50], jogador2[50];
     char ganhador[50];
}t_jogador;

int menu(){

    int opcao = 0;
    system("cls");
    printf("|Jogar - 1:\n");
    printf("|Ver Ranking - 2:\n");
    printf("|Ver Creditos - 3:\n");
    printf("|Sair - 4:\n");
    scanf("%d", &opcao);
     system("cls");
    return opcao;
   
}

void back(int voltar){
    if(voltar == 5)
        main();
    while(voltar != 5){
        printf("digite 5 para ir ao menu\n");
        scanf("%d", &voltar);
        if (voltar == 5)
        {
            main();
        }
    }
}

void credits(){
    int retornar;
    printf("Caio, Philipe, Joao, Lucas");
    printf("\n Aperte 5 para voltar: ");
    scanf("%d", &retornar);
    back(retornar);

}

void verRanking(){
     system("cls");
    int c, retornar;
    FILE *file;
    file = fopen("ranking.txt", "r");
    printf("\n");
    printf("=====RANKING=====\n");

    if (file) {
        while ((c = getc(file)) != EOF){
            putchar(c);
        }

    fclose(file);
    }
    
    printf("\n Aperte 5 para voltar: ");
    scanf("%d", &retornar);
    back(retornar);
   
   
}

void inicializarMatriz(){
    int i,j;
    for(i = 0; i<3; i++){
        for(j = 0; j < 3; j++){
            jogo[i][j]= 'a';
        }
    }
}

int eValido(char letra){
    if(letra == 'x' || letra == 'o')
        return 1;
    else
        return 0;
}

int coordenadaEhValida(int x, int y){
    if(x >= 0 && x < 3){
        if(y >= 0 && y < 3){
           system("cls");
            return 1;           
        }
           
    }
    system("cls");
    printf(" Coordenada inexistente! Selecione uma coordenada diponivel! \n");
    return 0;
   
}

int posicaoVazia(int x, int y){
    if(jogo[x][y] != 'x' && jogo[x][y] != 'o')
        return 1;
    system("cls");
    printf(" Casa ocupada, nao jogue no mesma coordenada! \n");
    return 0;
     
}

int ganhouLinhas(){
  int i , j, igual = 1;
  for(i = 0;i < 3;i++){
   for(j = 0;j < 2;j++){
    if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
        igual++;
}
 if(igual==3)
    return 1;
 igual=1;
}
return 0;
}

int ganhouColunas(){
 int i,j,igual=1;
  for(i=0;i<3;i++){
    for(j=0;j<2;j++){
     if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
         igual++;
}

   if(igual==3)
   return 1;
   igual=1;
}
return 0;
}

int ganhoudiagPrincipal(){
 int i,igual=1;
 for(i=0;i<2;i++){
if (eValido(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1])
igual++;
}
 if(igual == 3)
   return 1;
   else
   return 0;
}

int ganhoudiagSecundaria(){
 int i,igual=1;
 for(i=0;i<2;i++){
if (eValido(jogo[i][3-i-1 ]) && jogo[i][3-i-1] == jogo[i+1][3-i-2])
igual++;
}
 if(igual == 3)
   return 1;
   else
   return 0;
}

void Imprimir(){
    int l, c;


    printf("\t    0  1  2\n\n");

    for(l = 0; l < 3; l++){
        printf("\t%d", l);
        for(c = 0; c < 3; c++){

            if(eValido(jogo[l][c])){
                if(c < 2)

                printf(" %c |", jogo[l][c]);
            else
                printf(" %c ", jogo[l][c]);
            }
            else{
                if(c < 2)
                     printf("   | ");
                else
                    printf("   ");

            }

        }
        if(l < 2)

        printf("\n\t  ----------\n ");

	}
}

void gravarNome(char ganhador[50]){
    FILE *f;
    f = fopen("ranking.txt", "a+");
    if (f == NULL){
        printf("erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    int res = fputs(ganhador, f);
    fputc('\n', f);
    if(res == EOF){
        printf("erro na gravação\n");
        fclose(f);
    }

}

void jogar(t_jogador p1, t_jogador p2){
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

  do {
      do{
        Imprimir();
        printf("\n\n Digite a coordenada que deseja jogar: ");
        scanf("%d%d", &x, &y);
        valida = coordenadaEhValida(x, y);
        if(valida == 1)
          valida += posicaoVazia(x, y);
      }while(valida != 2);
      if(ordem == 1)
        jogo[x][y] = 'x';
      else
        jogo[x][y] = 'o';
      jogadas++;
      ordem++;
      if(ordem == 3)
          ordem = 1;
      system("cls");
     
      ganhou += ganhouLinhas();
      ganhou += ganhouColunas();
      ganhou += ganhoudiagPrincipal();
      ganhou += ganhoudiagSecundaria();
    

    }while(ganhou == 0 && jogadas < 9);
    if(ganhou != 0){
        if(ordem - 1 == 1){
            printf("\nParabens. Voce venceu %s\n", p1.jogador1 );
            gravarNome(p1.jogador1);
    }else{
            printf("\nParabens. Voce venceu %s\n", p2.jogador2);
            gravarNome(p2.jogador2); 
    }
     }else{ 
    
      printf("\nQue feio. Ninguem venceu!\n\n");
    }
   
 }
