#include "player.h"

float player::getVx() const
{
    return vx;
}

void player::setVx(float value)
{
    vx = value;
}

float player::getVy() const
{
    return vy;
}

void player::setVy(float value)
{
    vy = value;
}

float player::getCwidth() const
{
    return Cwidth;
}

void player::setCwidth(float value)
{
    Cwidth = value;
}

float player::getCheigh() const
{
    return Cheigh;
}

void player::setCheigh(float value)
{
    Cheigh = value;
}

float player::getPy() const
{
    return py;
}

void player::setPy(float value)
{
    py = value;
}

float player::getPx() const
{
    return px;
}

void player::setPx(float value)
{
    px = value;
}

float player::getAx() const
{
    return ax;
}

void player::setAx(float value)
{
    ax = value;
}

float player::getAy() const
{
    return ay;
}

void player::setAy(float value)
{
    ay = value;
}

float player::getWidth() const
{
    return width;
}

void player::setWidth(float value)
{
    width = value;
}

float player::getHeigh() const
{
    return heigh;
}

void player::setHeigh(float value)
{
    heigh = value;
}

player::player(float _x, float _y, float _width, float _heigh)
{

    vx = 0;
    vy = 0;
    ax = 0;
    ay = g;

    imagen = QPixmap(":/imagenes/cuadrado.jpg");
    width = _width;
    heigh = _heigh;

    Cwidth = width/2.0;
    Cheigh = heigh/2.0;

    px = _x; py = _y;
    this->setPos(px,py);
}

QRectF player::boundingRect() const
{
    return QRectF(-Cwidth,-Cheigh,width,heigh);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(boundingRect(),imagen,imagen.rect());

}

void player::aceleracion()
{
    ax = 0;
    ay = g;
}

void player::posicion()
{
    px = px + vx*dt + (ax*pow(dt,2))/2;
    py = py + vy*dt + (ay*pow(dt,2))/2;

    if(py >=500-Cheigh)
    {
        py = 500-Cheigh;
    }

    if(py<=-1000-Cheigh)
    {
        py = -1000-Cheigh;
    }

    if(px<=0+Cwidth)
    {
        px = Cwidth;
    }
   // this->setPos(px,py);
}

void player::velocidad()
{
    vx = vx + ax*dt;
    vy = vy + ay*dt;
}

void player::colision()
{
      if(px-(Cwidth/1.0)<=0.0)
        {
            vx = -e*vx;
            if(px-(Cwidth/1.0)<0.0)
            {
                px = (Cwidth/1.0)+1;
            }
        }
        if(px+(Cwidth/1.0)>=1000.0)
        {
            vx = -e*vx;
            if(px+(Cwidth/1.0)>1000.0)
            {
                px = 999-Cwidth/2;
            }
        }
        if(py+(Cheigh/1.0)>=500.0)
        {
            vy = -e*vy;
            if(py+(Cheigh/1.0)>500.0)
            {
                py = 499-Cheigh/1.0;
            }

        }
        if(py-(Cheigh/1.0)<=0.0)
        {
            vy = -e*vy;
            if(py-(Cheigh/1.0)<0.0)
            {
                py = Cheigh/1.0;
            }
        }

       // this->setPos(px,py);

}

void player::mover()
{
    //colision();
    //aceleracion();
    velocidad();
    posicion();
    this->setPos(px,py);
}

void player::detectarpiso(player *p, objetos *o)
{
    k = (o->getPy()-o->getCheigh())-(p->getPy()+p->getCheigh());
    if(-1.50<=k && k<1.5)
    {       p->setPos(p->getPx(),o->getPy()-o->getCheigh());
            p->setAy(0);
            p->setVy(0);
    }
}


