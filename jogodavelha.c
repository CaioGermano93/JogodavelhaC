#include "funcoes.h"

int main(){
    
	t_jogador p1;
	t_jogador p2;
	
	system("cls");
    
    switch (menu ()){
    case 1:
		{
		int op;

		printf("Jogador 1 digite seu nome: ");
		scanf("%s", &p1.jogador1);
		system("cls"); 
		
		printf("Jogador 2 digite seu nome: ");
		scanf("%s", &p2.jogador2);
		system("cls"); 

		do{
			inicializarMatriz();
			jogar(p1, p2);
			printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
			scanf("%d", &op);
			system("cls");
			
			
		}while(op == 1);
		
		if (op == 2)
			{
				main();
			}
			
		}
		break;
    case 2:
        system("cls");
        verRanking();
        break;
    case 3:
        system("cls");
        credits();
        break;
    default: 
        printf("IEEEEE...");
        break;
    }
	
    return 0;
}