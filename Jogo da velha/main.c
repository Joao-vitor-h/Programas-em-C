#include <stdio.h>
#include <stdlib.h>

void jogador1(int *vencedor, char *vitoria, char j1);
void jogador2(int *vencedor, char *vitoria, char j2);

void main(){
	
	char pos[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char x = {'X'}, o = {'O'}, escolha, j1, j2, vitoria;
	int cont = 0, posicao, vencedor = 0;
	
	do{
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("\n	--- JOGO DA VELHA ---	\n");
		printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("\n	      |         |      \n");
		printf("	   %c  |    %c    |  %c\n", pos[0], pos[1], pos[2]);
		printf("	      |         |      \n");
		printf("	------------------------\n");
		printf("	      |         |      \n");
		printf("	   %c  |    %c    |  %c\n", pos[3], pos[4], pos[5]);
		printf("	      |         |      \n");
		printf("	------------------------\n");		
		printf("	      |         |      \n");
		printf("	   %c  |    %c    |  %c\n", pos[6], pos[7], pos[8]);
		printf("	      |         |      \n");
//		VERIFICAÇÃO DO JOGADOR 01
//		verifica a primeira linha
		if(pos[0] == j1 && pos[1] == j1 && pos[2] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifica a segunda linha
		else if(pos[3] == j1 && pos[4] == j1 && pos[5] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifica a terceira linha
		else if(pos[6] == j1 && pos[7] == j1 && pos[8] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifica a primeira coluna
		else if(pos[0] == j1 && pos[3] == j1 && pos[6] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifica a segunda coluna
		else if(pos[1] == j1 && pos[4] == j1 && pos[7] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verfica a terceira coluna
		else if(pos[2] == j1 && pos[5] == j1 && pos[8] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifica a digonal esquerda
		else if(pos[0] == j1 && pos[4] == j1 && pos[8] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		verifca a diagonal direita
		else if(pos[2] == j1 && pos[4] == j1 && pos[6] == j1){
			jogador1(&vencedor, &vitoria, j1);
			break;
		}
//		VERIFICAÇÃO DO JOGADOR 02
//		verifica a primeira linha
		else if(pos[0] == j2 && pos[1] == j2 && pos[2] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a segunda linha 
		else if(pos[3] == j2 && pos[4] == j2 && pos[5] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a terceira linha
		else if(pos[6] == j2 && pos[7] == j2 && pos[8] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a primeira coluna
		else if(pos[0] == j2 && pos[3] == j2 && pos[6] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a segunda coluna
		else if(pos[1] == j2 && pos[4] == j2 && pos[7] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a terceira coluna
		else if(pos[2] == j2 && pos[5] == j2 && pos[8] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a diagonal esquerda
		else if(pos[0] == j2 && pos[4] == j2 && pos[8] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		verifica a diagonal direita
		else if(pos[2] == j2 && pos[4] == j2 && pos[6] == j2){
			jogador2(&vencedor, &vitoria, j2);
			break;
		}
//		Aqui o jogador 1 escolhe se quer o "x" ou a "o" e, logicamente, o jogador 2
//		fica com o que sobrar.
		if(cont == 0){
			int i = 0;
			while(i != 1){
				printf("\nVoce quer o \"X\" ou a \"O\"? ");
				fflush(stdin);
				scanf("%c", &escolha);
				if(escolha == x || escolha == 'x'){
					j1 = x;
					j2 = o;
					i = 1;
				}
				else if(escolha == o || escolha == 'o'){
					j1 = o;
					j2 = x;
					i = 1;
				}
				else{
					printf("\n	Opcao INVALIDA. Digite novamente!	\n");
				}
			}
		}
//		Nessa parte é feita a jogada junto com a verificação se a posição está ocupada.
		if(cont != 9){
//			Jogador 1
			if(cont % 2 == 0){
				int j = 0;
				while(j != 1){
					printf("\n	--- JOGADOR 1 ---	\n");
					printf("\nDigite em qual posicao voce deseja jogar %c: ", j1);
					scanf("%d", &posicao);
					posicao--;
					if(pos[posicao] == j1 || pos[posicao] == j2)
						printf("\n	--- Ops! Poscicao ja ocupada. Jogue Novamente!\n");
					else
						j = 1;
				}
				pos[posicao] = j1;
			}
//			Jogador 2
			else{
				int j = 0;
				while(j != 1){
					printf("\n	--- JOGADOR 2 ---	\n");
					printf("\nDigite em qual posicao voce deseja jogar %c: ", j2);
					scanf("%d", &posicao);
					posicao--;
					if(pos[posicao] == j1 || pos[posicao] == j2)
						printf("\n	--- Ops! Poscicao ja ocupada. Jogue Novamente! ---\n");
					else
						j = 1;
				}
				pos[posicao] = j2;
			}
		}
//		Nessa linha a tela é limpa.
		cont != 9 ? system("cls") : printf("\n");
		cont++;
	} while(cont != 10);
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	if(vencedor != 0)
		printf("\nO vencedor eh o jogador %d (%c)!", vencedor, vitoria);
	else
		printf("\nO jogo EMPATOU!\n");
}

void jogador1(int *vencedor, char *vitoria, char j1){
	*vencedor = 1;
	*vitoria = j1;
}

void jogador2(int *vencedor, char *vitoria, char j2){
	*vencedor = 2;
	*vitoria = j2;
}
