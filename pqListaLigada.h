#ifndef PQ_LISTA_LIGADA_H
#define PQ_LISTA_LIGADA_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <time.h>

    typedef struct podcast {
        char nomePodcast[64];
        int podcastId;
    } Podcast;

    typedef struct episodio {
        Podcast podcast;
        char nomeEpisodio[64];
        int numEpisodio;
    } Episodio;

    typedef struct no {
        Episodio episodio;
        struct no* proximo;
        struct no* anterior;
    } No;

    typedef No* Celula;

    typedef struct playlist {
        Celula inicio;
        Celula fim;
        Celula atual;
    } Pl;

    typedef Pl* Playlist;

Celula pqNovaCelula(Episodio ep) {
    Celula novaCelula = (Celula)malloc(sizeof(No));

    novaCelula->proximo = NULL;
    novaCelula->anterior = NULL;
    novaCelula->episodio = ep;
    return novaCelula;
}

Playlist pqNovaPlaylist() {
    Playlist novaPlaylist = malloc(sizeof(struct playlist));

    novaPlaylist->inicio = NULL;
    novaPlaylist->fim = NULL;
    novaPlaylist->atual = NULL;
    return novaPlaylist;
}

void pqInsereNoFinal(Playlist pl, Episodio ep) {
    Celula novoEpisodio = pqNovaCelula(ep);
    if (pl->inicio == NULL) {
        pl->inicio = novoEpisodio;
        pl->fim = novoEpisodio;
        return;
    }
    novoEpisodio->anterior = pl->fim;
    pl->fim->proximo = novoEpisodio;
    pl->fim = novoEpisodio;
}

void pqExibirNomes(Playlist pl) {
    if (pl->inicio == NULL) {
        printf("A playlist esta vazia.");
        return;
    }
    
    for(Celula aux = pl->inicio; aux != NULL; aux = aux->proximo){
        printf("\n%s\n", aux->episodio.podcast.nomePodcast);
        printf("-----------------------");
    }
}

void pqExibirTudo(Playlist pl) {
    if (pl->inicio == NULL) {
        printf("A playlist esta vazia.");
        return;
    }
    Celula aux = pl->inicio;
    for (;aux != NULL; aux = aux->proximo) {
        printf("Nome do Podcast: %s\n", aux->episodio.podcast.nomePodcast);
        printf("Nome do episodio: %s\n", aux->episodio.nomeEpisodio);
        printf("Numero do episodio: %d\n", aux->episodio.numEpisodio);
        printf("ID do Podcast: %d\n", aux->episodio.podcast.podcastId);
    }
}

Celula pqBusca(Playlist pl, Episodio alvo) {
    for (Celula aux = pl->inicio; aux != NULL; aux = aux->proximo) {
        if (aux->episodio.numEpisodio == alvo.numEpisodio && aux->episodio.podcast.podcastId == alvo.podcast.podcastId) {
            return aux;
        }
    }
    return NULL;
}

void pqRemoveFim(Playlist pl) {
    if (pl->fim != NULL) {
        Celula fimRemovido = pl->fim;

        pl->fim = pl->fim->anterior;

        pl->fim->proximo = NULL;

        free(fimRemovido);
    }
}

void pqRemoveInicio(Playlist pl) {
    if (pl->inicio != NULL) {
        Celula inicioRemovido = pl->inicio;

        //Caso seja o unico na playlist.
        if (pl->inicio->proximo == NULL) {
            pl->inicio = NULL;
            free(inicioRemovido);
            return;
        }

        pl->inicio = pl->inicio->proximo;

        pl->inicio->anterior = NULL;

        free(inicioRemovido);
    }
}

void pqRemover(Playlist pl, Episodio alvo) {
    Celula alvoBuscado = pqBusca(pl, alvo);

    if (alvoBuscado != NULL) {
        if (alvoBuscado == pl->inicio) {
            printf("Episodio %d do podcast %s removido !", alvoBuscado->episodio.numEpisodio, alvoBuscado->episodio.podcast.nomePodcast);
            pqRemoveInicio(pl);
            return;
        }
        else if (alvoBuscado == pl->fim) {
            printf("Episodio %d do podcast %s removido !", alvoBuscado->episodio.numEpisodio, alvoBuscado->episodio.podcast.nomePodcast);
            pqRemoveFim(pl);
            return;
        }
        else {
            printf("Episodio %d do podcast %s removido !", alvoBuscado->episodio.numEpisodio, alvoBuscado->episodio.podcast.nomePodcast);
            alvoBuscado->proximo->anterior = alvoBuscado->anterior;

            alvoBuscado->anterior->proximo = alvoBuscado->proximo;

            return;
        }
    }

    printf("Nao foi possivel remover esse episodio.\n");
}

void pqTocar(Playlist pl) {
    if (pl->inicio != NULL) {
        if (pl->atual == NULL) {
            pl->atual = pl->inicio;
            printf("Comecando a tocar:\n Episodio: %s, do podcast %s\n", pl->atual->episodio.nomeEpisodio, pl->atual->episodio.podcast.nomePodcast);
            return;
        }
        printf("Estou no episodio %s, do podcast %s\n", pl->atual->episodio.nomeEpisodio, pl->atual->episodio.podcast.nomePodcast);
    }
    else {
        printf("Playlist vazia.");
    }
}

void pqProximoEpisodio(Playlist pl, bool shuffle) {
    if (pl->inicio != NULL) {
        if (pl->atual == NULL) {
            pqTocar(pl);
        }
        else if (shuffle) {
            srand(time(NULL));
            int count = 0;
            for (Celula aux = pl->inicio; aux != NULL; aux = aux->proximo) {
                count++;
            }
            
            int numRand = rand() % count + 1;
            while (pl->atual->episodio.podcast.podcastId == numRand && pl->inicio != pl->fim) {
                numRand = rand() % count + 1;
            }
            for (Celula aux = pl->inicio; aux != NULL; aux = aux->proximo) {
                if (aux->episodio.podcast.podcastId == numRand) {
                    pl->atual = aux;
                }
            }
            pqTocar(pl);
        }
        else {
            if (pl->atual == pl->fim) {
                printf("A playlist acabou, voltando para o inicio.\n");
                pl->atual = pl->inicio;
                pqTocar(pl);
                return;
            }
            pl->atual = pl->atual->proximo;
            pqTocar(pl);
            return;
        }
    }
    else {
        printf("Playlist vazia.");
    }
}
#endif