#ifndef NIVELES_H
#define NIVELES_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <math.h>
#include <iostream>
#include "player.h"
#include "objetos.h"


using namespace std ;


namespace Ui {
class niveles;
}

class niveles : public QWidget
{
    Q_OBJECT

public:
    explicit niveles(QWidget *parent = 0);
    ~niveles();

public slots:
    void nivel1();
    void nivel2();
    void nivel3();
    void nivel4();
    void nivel5();
    void nivel6();
    void nivel7();
    void nivel8();
    void nivel9();
    void upScene();
    float CalCantidadD();
    float CalCantidadA();
    bool Sumaux();


private:
    int flagDir,flagDirAnt;
    Ui::niveles *ui;
    QGraphicsScene *scene;
    player *jugador;
    QList<objetos*>cosas;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    QTimer *timer,*Tscene,*Taux,*Td,*Ta;

    bool flag2 = true;
    bool flag = true;
    bool choque = false;
    bool m;

    float h,k;
    float x,y;
    float cont =0;







};

#endif // NIVELES_H
