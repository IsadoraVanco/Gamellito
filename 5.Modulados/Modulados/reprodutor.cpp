#include "reprodutor.h"
#include "ui_reprodutor.h"


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Reprodutor::Reprodutor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reprodutor)
{
    ui->setupUi(this);

    // Icones
    ui->pushButton_passarVideo->setIcon(QIcon("assets/icones/reprodutor/proximo/proximo-preto.png"));
    ui->pushButton_voltarVideo->setIcon(QIcon("assets/icones/reprodutor/anterior/anterior-preto.png"));

    // Valores do volume
    ui->horizontalSlider_volume->setMinimum(0);
    ui->horizontalSlider_volume->setMaximum(100);
}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Reprodutor::~Reprodutor()
{
    delete ui;
    delete player;
    delete videoItem;
    delete videoWidget;
    delete scene;
}

/* ************************************************************
 * AUXILIAR
 *************************************************************/

QString Reprodutor::converterTempoEmTexto(qint64 tempo){

    // Tempo está em milissegundos
    qint64 horas = (tempo / 1000) / 3600;
    qint64 minutos = ((tempo / 1000) % 3600) / 60;
    qint64 segundos = (tempo / 1000) % 60;

    QTime tempoCalculado(horas, minutos, segundos);

    QString formato = "";

    if(horas > 0){
        formato = "hh:mm:ss";
    }else{
        formato = "mm:ss";
    }

    return tempoCalculado.toString(formato);
}

/* ************************************************************
 * WIDGETS
 *************************************************************/

void Reprodutor::alterarEstado(QMediaPlayer::MediaStatus status){
    if(status == QMediaPlayer::EndOfMedia){
        pararVideo();
        ui->pushButton_video_tocar->setIcon(QIcon("assets/icones/reprodutor/restart/restart-preto.png"));
    }
}

void Reprodutor::alterarDuracaoMaxima(int64_t duracao){
    // Altera o widget que marca o tempo total do vídeo
    QString tempo = converterTempoEmTexto(duracao);
    ui->label_tempo_final->setText(tempo);

    // Configura o widget de tempo
    int64_t duracaoMaxima = duracao / periodoTempo;
    ui->horizontalSlider_tempo->setMinimum(0);
    ui->horizontalSlider_tempo->setMaximum(duracaoMaxima);

    // Volta para o inicio quando acabar
    ui->horizontalSlider_tempo->setRange(0, duracaoMaxima);

    qDebug() << "[Reprodutor][INFO] Duração máxima alterada:" << tempo;
}

void Reprodutor::alterarWidgetTempo(int64_t valor){
    // Altera o widget que marca o tempo atual do vídeo em texto
    QString tempo = converterTempoEmTexto(valor);
    ui->label_tempo_atual->setText(tempo);

    // Altera o widget que mostra o tempo no slider
    ui->horizontalSlider_tempo->setValue(valor / periodoTempo);
}

/* ************************************************************
 * REPRODUÇÃO DO VÍDEO
 *************************************************************/

void Reprodutor::alterarTempoVideo(int posicao){
    player->setPosition(posicao * periodoTempo);
}

void Reprodutor::tocarVideo(){
    ui->pushButton_video_tocar->setIcon(QIcon("assets/icones/reprodutor/pause/pause-preto.png"));

    player->play();
    videoParado = false;

    qDebug() << "[Reprodutor][INFO] Video tocando";
}

void Reprodutor::pararVideo(){
    ui->pushButton_video_tocar->setIcon(QIcon("assets/icones/reprodutor/play/play-preto.png"));

    player->pause();
    videoParado = true;

    qDebug() << "[Reprodutor][INFO] Video parado";
}

void Reprodutor::configurarVideo(QString caminhoVideo){

    // Obtem o caminho absoluto do arquivo
    QString caminhoAbsoluto = QFileInfo(caminhoVideo).absoluteFilePath();
    QUrl url = QUrl::fromLocalFile(caminhoAbsoluto);

    player = new QMediaPlayer;
    player->setMedia(url);

    // Saída de vídeo do player
    videoItem = new QGraphicsVideoItem;
    player->setVideoOutput(videoItem);

    scene = new QGraphicsScene;
    scene->addItem(videoItem);
    ui->graficosVideo->setScene(scene);

    // Atualiza o tamanho do vídeo
    videoItem->setSize(ui->graficosVideo->size());
    ui->graficosVideo->viewport()->update();

    // Configura o som
    ui->horizontalSlider_volume->setValue(50);
    alterarVolume(50);

    // Conexões
    connect(player, &QMediaPlayer::durationChanged, this, &Reprodutor::alterarDuracaoMaxima);
    connect(player, &QMediaPlayer::positionChanged, this, &Reprodutor::alterarWidgetTempo);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Reprodutor::alterarEstado);
    connect(ui->horizontalSlider_volume, &QSlider::valueChanged, this, &Reprodutor::alterarVolume);
    connect(ui->horizontalSlider_tempo, &QSlider::sliderMoved, this, &Reprodutor::alterarTempoVideo);

    qDebug() << "[Reprodutor][INFO] Configuração pronta para" << caminhoVideo;
}

/* ************************************************************
 * SOM DO VÍDEO
 *************************************************************/

void Reprodutor::mutarSom(){
    ui->pushButton_volume->setIcon(QIcon("assets/icones/som/sem-som-preto.png"));

    somMutado = true;
    player->setMuted(somMutado);

    qDebug() << "[Reprodutor][INFO] Som mutado";
}

void Reprodutor::reproduzirSom(){
    ui->pushButton_volume->setIcon(QIcon("assets/icones/som/com-som-preto.png"));

    somMutado = false;
    player->setMuted(somMutado);

    qDebug() << "[Reprodutor][INFO] Som tocando";
}

void Reprodutor::alterarVolume(int valor){
    if(valor <= 0){
        mutarSom();
    }else{
        if(somMutado){
            reproduzirSom();
        }

        player->setVolume(valor);
    }
}

/* ************************************************************
 * AÇÕES
 *************************************************************/

// ***** VIDEO **************************************************

void Reprodutor::on_pushButton_video_tocar_clicked()
{
    if(videoParado){
        tocarVideo();
    }else{
        pararVideo();
    }
}

void Reprodutor::on_pushButton_voltarVideo_clicked()
{
    int posicao = ui->horizontalSlider_tempo->value() - (tempoAcao / periodoTempo);
    alterarTempoVideo(posicao);
}

void Reprodutor::on_pushButton_passarVideo_clicked()
{
    int posicao = ui->horizontalSlider_tempo->value() + (tempoAcao / periodoTempo);
    alterarTempoVideo(posicao);
}

// ***** SOM **************************************************

void Reprodutor::on_pushButton_volume_clicked()
{
    if(somMutado){
        if(ui->horizontalSlider_volume->value() <= 0){
            ui->horizontalSlider_volume->setValue(30);
        }

        reproduzirSom();
    }else{
        mutarSom();
    }
}
