# Projeto Gamellito (carinhosamente "HC")

A ideia do projeto é construir um reprodutor de vídeos, que ao final de cada execução, exiba um questionário para reforçar o aprendizado. 

Esse projeto têm como objetivo auxiliar as crianças que possuem diabete, para que entendam e aprendam sobre a condição e como podem cuidar de sua saúde. 

De uma forma mais técnica, o projeto envolve não só código, mas também desafios de hardware, já que a máquina que será utilizada terá poucos recursos de execução. Mais precisamente: um processador Celeron D331 que possui um núcleo físico de 2.66GHz dos anos 2000 com barramento de 533MHz, 3GB de memória DDR2, com a possibilidade de no máximo 1GB de expansão. Carinhosamente, a chamarei de "Dino" para ficar mais fácil.

Pessoalmente, será um grande desafio, já que estou no início da programação, e conciliar o projeto com a grade da faculdade não será nada fácil.

## 1. Ferramentas

### 1.1. Linguagem e biblioteca
Para esta difícil tarefa, irei utilizar a linguagem **C++** e a biblioteca [**Qt5 (versão 5.15)**](https://doc.qt.io/qt-5/modules-cpp.html) (no momento existe a 6, mas utiliza-lá ocasionaria outros problemas). A IDE utilizada será o **QtCreator**, que é responsável por compilar o código, além disso, nele é muito mais fácil criar as interfaces gráficas, já que possui o sistema Drag and Drop.

#### Referências
Para consultas futuras, aqui estão as documentações de cada classe utilizada:

* [**QMultimedia**](https://doc.qt.io/qt-5/qtmultimedia-index.html)
* [**QWidget**](https://doc.qt.io/qt-5/qwidget.html)
* [**QVideoWidget**](https://doc.qt.io/qt-5/qvideowidget.html)
* [**QGraphicsVideoItem**](https://doc.qt.io/qt-5/qgraphicsvideoitem.html)

#### Bibliotecas para a reprodução de vídeo
Existem várias bibliotecas para a reprodução de vídeo em Qt. Abaixo, algumas testadas e seus resultados:

* [**QVideo**](): Não foi possível alterar a dimensão do reprodutor;
* [**QVideoWidget**](): Altera a dimensão do vídeo, porém, abrindo outra janela.
* [**QGraphicsVideoItem**](): É possível alterar a dimensão do vídeo, e colocá-lo em um widget, sem a necessidade de abrir outra janela para reproduzir o vídeo. Apesar desses benefícios, o vídeo reproduz travando um pouco (quase impercipitível).

Outras classes possíveis (mas que não foram testadas):

* [**Qtav**](https://github.com/wang-bin/QtAV/tree/master);
* [**QVideoFrame**](https://doc.qt.io/qt-5/qvideoframe.html);
* [**QVideoSink**](https://doc.qt.io/qt-6/qvideosink.html) (Qt6);
* [**VLC Qt**](https://github.com/vlc-qt/vlc-qt);

### 1.2. Virtualização
Como utilizo Windows no dia-a-dia, preciso de uma ferramenta para virtualizar o sistema Linux para compilar o código e testá-lo. Para isso, utilizarei o **VM Virtual Box** e nele virtualizo o **Linux Mint XFCE versão 21.2 (Victoria) (64bits)**. Utilizando 2 GB de RAM da máquina hospedeira e 1 núcleo de 1.80GHz do AMD Ryzen 7 5700U with Radeon Graphics.

Cogitei utilizar Docker, mas creio que seria muito para a máquina Dino, além de não ser muito viável para o usuário replicar o programa em outra máquina (creio eu).

### 1.3 Papelada

Assim como uma casa, um software também precisa de uma planta que foi planejada para poder ser estruturado de forma segura. E para fazer algumas partes do processo, utilizei:

- **Protipagem de telas**: [Figma](https://www.figma.com);
- **Diagrama de caso de uso**: [Lucidchart](https://lucid.app/);

## 2. Software
Estrutura do armazenamento do software na máquina:

```
projeto{
    assets{
        somAmbiente.wav
        ...
    }

    backups{
        paciente{
            videos.mp4
            ...
        }
        profissional{
            videos.mp4
            ...
        }
        responsavel{
            videos.mp4
            ...
        }
    }
    
    configuracoes{
        sequenciaPaciente.json
        sequenciaProfissional.json
        sequenciaResponsavel.json

        respostasPaciente.json
        respostasProfissional.json
        respostasResponsavel.json
    }

    .executavel
    config.json
}
```

Onde `projeto` é a pasta da aplicação do Gamellito, e dentro dela contém todos os arquivos necessários para o funcionamento da aplicação. 

A pasta `assets` contém sons, ícones e fotos da aplicação. 

`backups` trata-se da pasta que armazena os vídeos que foram salvos para as sequências. Dentro desta pasta, possui uma pasta separada para cada perfil.

`configuracoes` é a pasta que armazena os arquivos .json de cada perfil, incluindo a sequência de cada perfil e as respostas coletadas em perguntas.

`.executavel` é o arquivo executável do programa.

`config.json` é o arquivo de configurações gerais, que armazena algumas informações do programa, como: Número de reproduções das sequências, número de vezes que o programa foi aberto, a última vez que o programa foi aberto, a senha do administrador e a última vez que um relatório foi gerado.

### Assets

* Sons públicos:
    - [Som ambiente do menu](https://pixabay.com/pt/sound-effects/funny-and-comical-melody-glide-synth-bass-and-trumpet-21398/)

* Ícones/imagens públicas:
    
    Menu:
    - [Iniciar do Menu](https://br.freepik.com/icone/jogar-circulo_10435870#fromView=image_search_similar&page=1&position=10&uuid=40e7a8b3-175f-43da-9d45-47ff17ad6399)
    - [Configurações](https://br.freepik.com/icone/chave-inglesa_11270131)
    - [Informações](https://br.freepik.com/icone/informacoes_3916699#fromView=search&page=1&position=7&uuid=736630dc-7ab3-4b4b-842a-2bb19c458c58)

    Geral:
    - [Home](https://www.freepik.com/icon/home_1946436#fromView=search&page=1&position=1&uuid=df718193-70a8-4e6c-bbb2-cfdbf124f5f0)
    - [Voltar](https://www.freepik.com/icon/back_9126101#fromView=search&page=1&position=65&uuid=bf37574f-28a7-48f9-829d-081313cd83f3)
    - [Próximo](https://www.freepik.com/icon/right-arrow_9125994#fromView=resource_detail&position=44)
    - [Lixeira](https://br.freepik.com/icone/lixo_3917378#fromView=search&page=1&position=0&uuid=f109c5d2-09ce-4fec-a0f1-a15a1aac6a9a)
    - [Seta](https://br.freepik.com/icone/caret-up_3916917#fromView=search&page=1&position=2&uuid=ac09fa06-c342-4946-8d95-d4c28a6a72ef)
    - [Sair](https://br.freepik.com/icone/relogio-seis_7602707)
    
    Reprodutor:
    - [Com som](freepik.com/icon/volume_727269#fromView=search&page=1&position=2&uuid=a5f213c1-6501-4e0d-9c22-7edddaeb7029)
    - [Sem som](https://www.freepik.com/icon/mute_727240#fromView=search&page=1&position=3&uuid=a5f213c1-6501-4e0d-9c22-7edddaeb7029)

### Sequências
As sequências dos perfis são representadas por arquivos .json, e dentro deles, estão estruturados objetos Json para representar um item. Os itens são representados da seguinte maneira:

* Para o `vídeo`: 
```
{
    "id": numero;
    "tipo":"video";
    "caminho":"caminho/do/video"
}
```

* Para a `pergunta`: 
```
{
    "id": numero;
    "tipo":"pergunta";
    "pergunta":"texto";
    "opcao1":"texto";
    "opcao2":"texto";
    "opcao3":"texto";
    "opcao4":"texto";
    "correta":0-4;
}
```

## 3. Hardware
Por enquanto, a máquina foi desbloqueada para utilizar sistemas operacionais. Procuro por sistemas Linux que são leves o suficientes para a máquina Dino.

Sistemas testados até o momento (na máquina Dino):
- **Linux Mint XFCE versão Vera (64 bits)** => O sistema é pesado para a máquina. Vídeos em HD rodam até bem, mas em fullHD não tem um bom desempenho.
- **Lubuntu 22.04 (64bits)** => Sistema leve, rodou tranquilamente os testes e vídeos. A inicialização é um pouco lenta, mas geralmente utiliza menos CPU que o Q4OS.
- **Q4OS (64bits)** => Sistema leve, rodou tranquilamente os testes e vídeos. Utiliza menos memória RAM que o Lubuntu.

Testar outros Linux mais leves. OBS: Pode ser que haja incompatiblidade de bibliotecas 
- Bodhi Linux
- Xubuntu
- Puppy Linux
- AntiX
- outros...

## 4. Testes
Irei guardar cada teste para caso precise testar em um novo sistema operacional, e assim eu posso comparar cada resultado. Por enquanto, temos:

1. **Roadmap** -> Um exemplo simples de tela inicial, com redimensionamento e botões que levam a novas janelas. Tamanho mínimo da tela: 960x540.
2. **PaginasDinamicas** -> Apesar do nome, é um exemplo simples de aplicação que possui elementos estáticos, sem responsividade, mas que navega entre widgets dentro de uma StackedWidgets, sem a necessidade de criar uma nova janela para alterar o conteúdo.
3. **Menus** -> Um esboço de como imagino a aplicação (com exceção do reprodutor de vídeo), ainda sem as telas dinâmicamente alocadas. Este exemplo possui a navegação entre as telas (em StackedWidgets) e som ambiente no menu. A aplicação é ajustada conforme o tamanho do monitor e sem a barra de título da janela. Tamanho mínimo da tela: 800x600 (SVGA).
4. **ReprodutorMenu** -> Essa versão é um leve aprimoramento do "Menus". Armazena uma sequência de vídeos escolhidos em um arquivo JSON e reproduz um vídeo (fixo) após clicado o botão "iniciar". Foram testados vídeos em FullHD e HD. 