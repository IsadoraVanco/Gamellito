#ifndef VIDEOGRAPHICSVIEW_H
#define VIDEOGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QResizeEvent>

class VideoGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit VideoGraphicsView(QGraphicsVideoItem* videoItem, QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QGraphicsVideoItem* m_videoItem;
};

#endif // VIDEOGRAPHICSVIEW_H
