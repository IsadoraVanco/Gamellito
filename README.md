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

(Em geral)
* [**QString**](https://doc.qt.io/qt-5/qstring.html)
* [**QWidget**](https://doc.qt.io/qt-5/qwidget.html)
* [**QMessageBox**](https://doc.qt.io/qt-5/qmessagebox.html)
* [**QDebug**](https://doc.qt.io/qt-5/qdebug.html)
* [**QDir**](https://doc.qt.io/qt-5/qdir.html)
* [**QIcon**](https://doc.qt.io/qt-5/qicon.html)

(Em main.cpp)
* [**QApplication**](https://doc.qt.io/qt-5/qapplication.html)

(Em arquivos.h/cpp)
* [**QFileDialog**](https://doc.qt.io/qt-5/qfiledialog.html)
* [**QFileInfo**](https://doc.qt.io/qt-5/qfileinfo.html)
* [**QFile**](https://doc.qt.io/qt-5/qfile.html)
* [**QTextStream**](https://doc.qt.io/qt-5/qtextstream.html)
* [**QDateTime**](https://doc.qt.io/qt-5/qdatetime.html)
* [**QJsonDocument**](https://doc.qt.io/qt-5/qjsondocument.html)
* [**QJsonParseError**](https://doc.qt.io/qt-5/qjsonparseerror.html)
* [**QJsonArray**](https://doc.qt.io/qt-5/qjsonarray.html)
* [**QByteArray**](https://doc.qt.io/qt-5/qbytearray.html)
* [**QJsonObject**](https://doc.qt.io/qt-5/qjsonobject.html)

(Em mainwindow.h/cpp)
* [**QListWidget**](https://doc.qt.io/qt-5/qlistwidget.html)
* [**QListWidgetItem**](https://doc.qt.io/qt-5/qlistwidgetitem.html)
* [**QList**](https://doc.qt.io/qt-5/qlist.html)
* [**QRadioButton**](https://doc.qt.io/qt-5/qradiobutton.html)
* [**QPushButton**](https://doc.qt.io/qt-5/qpushbutton.html)
* [**QTextEdit**](https://doc.qt.io/qt-5/qtextedit.html)
* [**QEvent**](https://doc.qt.io/qt-5/qevent.html)
* [**QTimer**](https://doc.qt.io/qt-5/qtimer.html)
* [**QObject**](https://doc.qt.io/qt-5/qobject.html)
* [**QVBoxLayout**](https://doc.qt.io/qt-5/qvboxlayout.html)

(Em reprodutor.h/cpp)
* [**QMediaPlayer**](https://doc.qt.io/qt-5/qmediaplayer.html)
* [**QAudio**](https://doc.qt.io/qt-5/qaudiooutput.html)
* [**QVideoWidget**](https://doc.qt.io/qt-5/qvideowidget.html)
* [**QMultimedia**](https://doc.qt.io/qt-5/qtmultimedia-index.html)
* [**QGraphicsVideoItem**](https://doc.qt.io/qt-5/qgraphicsvideoitem.html)
* [**QTime**](https://doc.qt.io/qt-5/qtime.html)

(Em senha.h/cpp)
* [**QInputDialog**](https://doc.qt.io/qt-5/qinputdialog.html)

(Em sequencia.h/cpp)
* [**QJsonValue**](https://doc.qt.io/qt-5/qjsonvalue.html)

(Em somambiente.h/cpp)
* [**QSound**](https://doc.qt.io/qt-5/qsound.html)

(Em video.h/cpp)
* [**QVideoWidget**](https://doc.qt.io/qt-5/qvideowidget.html)
* [**QGraphicsVideoItem**](https://doc.qt.io/qt-5/qgraphicsvideoitem.html)
* [**QGraphicsScene**](https://doc.qt.io/qt-5/qgraphicsscene.html)
* [**QMultimedia**](https://doc.qt.io/qt-5/qtmultimedia-index.html)
* [**QMediaPlayer**](https://doc.qt.io/qt-5/qmediaplayer.html)
* [**QMediaPlaylist**](https://doc.qt.io/qt-5/qmediaplaylist.html)
* [**QUrl**](https://doc.qt.io/qt-5/qurl.html)

#### Bibliotecas para a reprodução de vídeo
Existem várias bibliotecas para a reprodução de vídeo em Qt. Abaixo, algumas testadas e seus resultados:

* [**QVideo**](): Não foi possível alterar a dimensão do reprodutor;
* [**QVideoWidget**](https://doc.qt.io/qt-5/qvideowidget.html): Altera a dimensão do vídeo, porém, abrindo outra janela.
* [**QGraphicsVideoItem**](https://doc.qt.io/qt-5/qgraphicsvideoitem.html): É possível alterar a dimensão do vídeo, e colocá-lo em um widget, sem a necessidade de abrir outra janela para reproduzir o vídeo. Apesar desses benefícios, o vídeo reproduz travando um pouco (quase imperceptível).

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

- **Prototipagem de telas**: [Figma](https://www.figma.com);
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
    - [Perfil](https://br.freepik.com/icone/utilizador_3917711)
    - [Perfil com círculo](https://br.freepik.com/icone/usuario-circulo_9821492#fromView=search&page=1&position=48&uuid=3b1aacdf-4a1f-4407-b3a1-7a4417d6fa92)

    Geral:
    - [Página Inicial](https://www.freepik.com/icon/home_1946436#fromView=search&page=1&position=1&uuid=df718193-70a8-4e6c-bbb2-cfdbf124f5f0)
    - [Voltar](https://www.freepik.com/icon/back_9126101#fromView=search&page=1&position=65&uuid=bf37574f-28a7-48f9-829d-081313cd83f3)
    - [Próximo](https://www.freepik.com/icon/right-arrow_9125994#fromView=resource_detail&position=44)
    - [Sair](https://br.freepik.com/icone/relogio-seis_7602707)
    - [Salvar](https://br.freepik.com/icone/caixa-selecao_3917750#fromView=search&page=1&position=3&uuid=b8b8ac32-bd83-475d-9b65-63c5d7f3bb70)
    
    Configurar:
    - [Informações](https://br.freepik.com/icone/informacoes_3916699#fromView=search&page=1&position=7&uuid=736630dc-7ab3-4b4b-842a-2bb19c458c58)
    - [Pergunta](https://br.freepik.com/icone/pergunta-area-transferencia_16542674#fromView=search&page=1&position=18&uuid=01bb0d42-8e24-47a5-b501-52f14a167f5f)
    - [Vídeo](https://br.freepik.com/icone/filme-camera_10435999#fromView=search&page=1&position=23&uuid=bece77bf-d700-4e19-812b-a0a5a07d6ab8)
    - [Seta](https://br.freepik.com/icone/caret-up_3916917#fromView=search&page=1&position=2&uuid=ac09fa06-c342-4946-8d95-d4c28a6a72ef)
    - [Lixeira](https://br.freepik.com/icone/lixo_3917378#fromView=search&page=1&position=0&uuid=f109c5d2-09ce-4fec-a0f1-a15a1aac6a9a)

    Reprodutor:
    - [Com som](freepik.com/icon/volume_727269#fromView=search&page=1&position=2&uuid=a5f213c1-6501-4e0d-9c22-7edddaeb7029)
    - [Sem som](https://www.freepik.com/icon/mute_727240#fromView=search&page=1&position=3&uuid=a5f213c1-6501-4e0d-9c22-7edddaeb7029)
    - [Adiantar](https://br.freepik.com/icone/simbolo-seta-avanco-rapido_27284#fromView=resource_detail&position=59)
    - [Restart](https://br.freepik.com/icone/vire-esquerda_7435121#fromView=search&page=1&position=12&uuid=3ee0056c-0f2b-42b2-bbc0-b4b82166d552)

    Perfil:
    - [Paciente](https://www.freepik.com/icon/child-head_5069208#fromView=search&page=1&position=19&uuid=8a66575b-5afa-40d8-8a66-9fd2ae96faf)
    - [Responsável](https://www.freepik.com/icon/employees-woman-man_14644111#fromView=search&page=1&position=2&uuid=899689b3-c351-4c56-9fc2-7ecf6fde1d39)
    - [Profissional](https://www.freepik.com/icon/user-md_9856423#fromView=search&page=1&position=0&uuid=76dafb05-1ebf-48a2-b2a6-517200676704)

* Fontes:
    - [Alpha Echo](https://www.dafont.com/pt/alpha-echo.font)


* **Estrutura:**
```
/assets
    /botoes
        /configuracoes
        /menu
    /fontes
        /aplicacao
        /configuracoes
        /informacoes
        /iniciar-menu
        /lapis
        /lixeira
        /opcao
        /pagina-inicial
        /perfil
        /pergunta
        /proximo
        /reprodutor
        /sair
        /salvar
        /seta
        /som
        /video
        /voltar
    /icones
    /imagens
    /logos
    /sons
    /videos
```

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

### Como compilar?
Para compilar o código para outra máquina, é necessário ter instalado algumas bibliotecas:
```
qtbase5-dev
cmake
build-essential
```

No **Linux**, é possível instalar via `apt`.

Após instala-las, copie os arquivos de um projeto (.h .cpp ui e cmake) para a sua máquina (não esqueça da pasta de assets). Depois, na pasta do projeto, abra o terminal e utilize o Cmake para criar o Makefile:
```
cmake .
```

Depois disso, um arquivo Makefile será criado, então, é só executá-lo para gerar o executável do programa:
```
make
```

Assim, seu executável está pronto!

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
- Debian
- Zorin OS Lite
- MX Linux
- Peppermint

## 4. Testes
Irei guardar cada teste para caso precise testar em um novo sistema operacional, e assim eu posso comparar cada resultado. Por enquanto, temos:

1. **Roadmap** -> Um exemplo simples de tela inicial, com redimensionamento e botões que levam a novas janelas. Tamanho mínimo da tela: 960x540.
2. **PaginasDinamicas** -> Apesar do nome, é um exemplo simples de aplicação que possui elementos estáticos, sem responsividade, mas que navega entre widgets dentro de uma StackedWidgets, sem a necessidade de criar uma nova janela para alterar o conteúdo.
3. **Menus** -> Um esboço de como imagino a aplicação (com exceção do reprodutor de vídeo), ainda sem as telas dinâmicamente alocadas. Este exemplo possui a navegação entre as telas (em StackedWidgets) e som ambiente no menu. A aplicação é ajustada conforme o tamanho do monitor e sem a barra de título da janela. Tamanho mínimo da tela: 800x600 (SVGA).
4. **ReprodutorMenu** -> Essa versão é um leve aprimoramento do "Menus". Armazena uma sequência de vídeos escolhidos em um arquivo JSON e reproduz um vídeo (fixo) após clicado o botão "iniciar". Foram testados vídeos em FullHD e HD. 
5. **Modulados** -> Versão (quase) final do projeto, com sequências de vídeos e perguntas armazenadas e manipuladas. Troca de perfis já pré definidos.
6. **Gamellito** -> Versão final do projeto com assets corretos e correção de bugs.

## 5. Como replicar

1. Compile o arquivo na máquina desejada
2. Guarde o executável gerado
3. Para replicar em uma máquina semelhante à máquina alvo da compilação, copie o executável e a pasta de Assets dentro de uma pasta chamada "Gamellito" e no mesmo diretório, copie os arquivos executáveis de instalação. Transfira tudo isso para a nova máquina
4. Mude o arquivo install_gamellito.sh para executável e rode no terminal, ele é responsável pela instalação do projeto na máquina, as bibliotecas do Qt e os arquivos de inicialização

## 6. Melhorias futuras

* Adicionar vídeo no menu
* Trocar imagens png por svg
* Adicionar uma confirmação para sair do programa
* Adicionar o ícone da aplicação corretamente. No momento o ícone aparece apenas na notificação
* Adicionar corretamente a fonte do programa
* Separar as telas em classes diferentes e tentar adicionar as páginas na Stack Widgets de forma dinâmica, atribuindo um nome a cada uma delas. Dessa forma, caso uma página seja trocada de lugar na edição, não afete outras partes do código
* Adicionar recurso para recuperação de senha