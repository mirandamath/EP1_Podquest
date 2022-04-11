# **EP 1 - PODQUEST**
Estrutura de Dados - 3° Semestre - EP 1

## 1. **PODQUEST MVP**

  * Quero poder inserir um novo podcast na minha playlist, para depois poder verificar quais são os episódios de podcasts que tenho

  * Quando inserir meu episódio, quero poder colocar algumas palavras-chave, pra poder buscar depois através delas

  * Quero poder remover um episodio de podcast, caso eu não queira mais ouvi-lo

  * Quero poder começar a tocar minha playlist e saber qual podcast esta sendo reproduzido no momento, para poder verificar se quero ouvir aquele ou se passo para o próximo 

  * Quero poder escolher a opção “shuffle” que, ao passar para o próximo podcast, escolhe um episódio aleatório da minha playlist para tocá-lo

  * Quero saber quais são e quantos são os podcasts (se tiver mais de um episódio do mesmo podcast, quero saber só o nome deste podcast) que possuo na minha playlist, para poder contar para os meus amigos

## 2. **Especificações**

  * Um episodio de podcast terá as seguintes informações:
  
      * Nome do Podcast, com no máximo 64 caracteres
      
      * PodcastId, um número inteiro que identifica aquele podcast
      
      * Nome do Episódio, com no máximo 64 caracteres
      
      * Um número inteiro que representará qual é o episódio 
      
      * Uma lista com palavras-chave do episódio, cada palavra tendo no máximo 64 caracteres

## 3. **Comandos**

  * ### Adicionar: 
    * Pede as informações do episódio e o insere no final da playlist.

  * ### Remover:
    * Remove um episódio da playlist, recebendo o ID do podcast e número do episódio.

  * ### Tocar:
    * Inicia a playlist pelo primeiro episodio da lista e exibe na tela "Comecando a tocar: Episodio: {Episodio X}, do podcast {Podcast Y}"
    * Caso a playlist ja tenha sido iniciada, exibe o episódio atual "Estou no episodio {Episodio X}, do podcast {Podcast Y}"

  * ### Proximo:
    * Também serve para iniciar a playlist, caso não tenha sido iniciada ainda.
    * Caso a opção shuffle esteja habilitada, sorteia um episódio aleatório e troca para o episódio sorteado.
    * Caso a opção shuffle esteja desabilitada, passa para o próximo episódio da lista.

  * ### Shuffle:
    * Serve para habilitar e desabilitar a opção shuffle.