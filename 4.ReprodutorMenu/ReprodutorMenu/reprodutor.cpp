#include "reprodutor.h"

Reprodutor::Reprodutor()
{
    // Crie um QGraphicsVideoItem
    videoItem = new QGraphicsVideoItem;

    // Defina o QGraphicsVideoItem como a saída de vídeo do player
    player->setVideoOutput(videoItem);

    // Crie um QGraphicsScene e adicione o QGraphicsVideoItem a ele
    scene = new QGraphicsScene;
    scene->addItem(videoItem);

    // Defina a QGraphicsScene para o seu QGraphicsView
    //ui->graficosVideo->setScene(scene);

    // Defina o tamanho do QGraphicsVideoItem para o tamanho do QGraphicsView
    //videoItem->setSize(ui->graficosVideo->size());

    videoItem->setSize(QSizeF(480, 360)); // Substitua por seu tamanho desejado

    // Defina o modo de proporção
    //videoItem->setAspectRatioMode(Qt::KeepAspectRatio); // Mantém a proporção do vídeo
}

