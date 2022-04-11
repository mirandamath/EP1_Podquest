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
    scanf("%d", &episodio.podcast.podcastId);
    printf("Qual o numero do episodio que deseja remover ?\n");
    scanf("%d", &episodio.numEpisodio);

    pqRemover(pl, episodio);
}

void getNewEpisodio(Playlist pl) {
    Episodio episodio;

    printf("Nome do episodio: ");
    fgets(episodio.nomeEpisodio, 64, stdin);
    remove_newline_ch(episodio.nomeEpisodio);

    printf("Numero do episodio: ");
    scanf("%d", &episodio.numEpisodio);

    pqInsereNoFinal(pl, episodio);
}


void getOptionAdicionar(Playlist pl) {
    int opcao = 0;
    bool selecao = true;
    Podcast podcast;

    printf("Voce deseja adicionar o que ?\n1) Podcast\n2) Episodio");
    while(selecao){
        switch(opcao){
        case 1:
            
            printf("Nome do podcast: ");
            fgets(podcast.nomePodcast, 64, stdin);
            remove_newline_ch(podcast.nomePodcast);

            printf("ID do podcast: ");
            scanf("%d", &podcast.podcastId);
            break;
        case 2:
            printf("Em qual podcast voce gostaria de adicionar um episodio:\n");
            pqExibirNomes(pl);
            getNewEpisodio(pl);
            break;
        default:
            selecao = false;
            break;
        }
    }
}

int main(void) {
    Playlist pl = pqNovaPlaylist();
    int option = 0;
    bool running = true, shuffle = false;



    while (running) {
        printf("\n1) Adicionar\n2) Remover\n3) Tocar\n4) Proximo\n5) Shuffle\n6) Exibir nome dos podcasts\n7) Exibir Tudo\n0) Sair\n");
        scanf("%d", &option);
        getchar();
        switch (option) {
        case 0:
            running = false;
            break;
        case 1:
            getOptionAdicionar(pl);
            break;
        case 2:
            getRemocao(pl);
            break;
        case 3:
            pqTocar(pl);
            break;
        case 4:
            pqProximoEpisodio(pl, shuffle);
            break;
        case 5:
            if (shuffle) {
                printf("Desligando o shuffle!");
                shuffle = false;
            }
            else {
                printf("Ligando o shuffle!");
                shuffle = true;
            }
            break;
        case 6:
            pqExibirNomes(pl);
            break;
        case 7:
            pqExibirTudo(pl);
            break;
        }
    }

    return 0;
}