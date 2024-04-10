#include "videographicsview.h"

VideoGraphicsView::VideoGraphicsView(QGraphicsVideoItem* videoItem, QWidget* parent)
    : QGraphicsView(parent), m_videoItem(videoItem) {}

void VideoGraphicsView::resizeEvent(QResizeEvent* event)
{
    if (m_videoItem) {
        m_videoItem->setSize(event->size());
    }
    QGraphicsView::resizeEvent(event);
}
