#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pqListaLigada.h"

void remove_newline_ch(char* line)
{
    int new_line = strlen(line) - 1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

void getRemocao(Playlist pl) {
    Episodio episodio;

    printf("Qual o id no podcast que deseja remover ?\n");
    scanf("%d", &episodio.podcastId);
    printf("Qual o numero do episodio que deseja remover ?\n");
    scanf("%d", &episodio.numEpisodio);

    pqRemover(pl, episodio);
}

void getNewEpisodio(Playlist pl) {
    Episodio episodio;

    printf("Nome do podcast: ");
    fgets(episodio.nomePodcast, 64, stdin);
    remove_newline_ch(episodio.nomePodcast);

    printf("Nome do episodio: ");
    fgets(episodio.nomeEpisodio, 64, stdin);
    remove_newline_ch(episodio.nomeEpisodio);

    printf("ID do podcast: ");
    scanf("%d", &episodio.podcastId);

    printf("Numero do episodio: ");
    scanf("%d", &episodio.numEpisodio);

    pqInsereNoFinal(pl, episodio);
}

int main(void) {
    Playlist pl = pqNovaPlaylist();
    int option = 0;
    bool running = true, shuffle = false;



    while (running) {
        printf("\n1) Adicionar episodio\n2) Exibir nome dos podcasts\n3) Exibir Tudo\n4) Remover\n5) Tocar\n6) Proximo\n7) shuffle\n0) Sair\n");
        scanf("%d", &option);
        getchar();
        switch (option) {
        case 0:
            running = false;
            break;
        case 1:
            getNewEpisodio(pl);
            break;
        case 2:
            pqExibirNomes(pl);
            break;
        case 3:
            pqExibirTudo(pl);
            break;
        case 4:
            getRemocao(pl);
            break;

        case 5:
            pqTocar(pl);
            break;
        case 6:
            pqProximoEpisodio(pl, shuffle);
            break;
        case 7:
            if (shuffle) {
                printf("Desligando o shuffle!");
                shuffle = false;
            }
            else {
                printf("Ligando o shuffle!");
                shuffle = true;
            }
        }
    }

    return 0;
}