# **EP 1 - PODQUEST**

Matheus Miranda

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

# **Exemplos**
![image](https://user-images.githubusercontent.com/75645010/162817124-16514912-00c2-4a12-9831-6a010a8a2644.png)
  - Como Adicionar um episodio novo:
    - Selecione Adicionar(1) no menu.
    - Digite as infos do seu episodio:
  ![image](https://user-images.githubusercontent.com/75645010/162817751-30ca8dd0-e36e-4d06-99a0-be6783e1b6fb.png)

  - Como remover um episodio:
    - Selecione Remover(2) no menu.
    - Digite as infos do episodio que deseja remover:
  ![image](https://user-images.githubusercontent.com/75645010/162818059-f7bc3d7a-f6f7-41a2-b0a6-4aefc8c4b2f4.png)
  
  