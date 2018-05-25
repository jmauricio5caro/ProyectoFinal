#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>

class objetos : public QObject, public QGraphicsItem
{
    float px, py;
    float width, heigh;
    float vx, vy;
    float Cwidth, Cheigh;

    QPixmap imagen;


    Q_OBJECT
public:
    objetos(float _x, float _y, float _width, float _heigh, float _vx, float _vy);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);


    // get methods
    float getCwidth() const;
    float getCheigh() const;
    float getWidth() const;
    float getHeigh() const;
    float getPx() const;
    float getPy() const;
    float getVx() const;
    float getVy() const;

    //set methods
    void setCwidth(float value);
    void setCheigh(float value);
    void setWidth(float value);
    void setHeigh(float value);
    void setPx(float value);
    void setPy(float value);
    void setVx(float value);
    void setVy(float value);



signals:

public slots:
};

#endif // OBJETOS_H
