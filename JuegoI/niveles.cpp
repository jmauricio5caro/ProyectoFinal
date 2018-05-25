#include "niveles.h"
#include "ui_niveles.h"

int ex=0;


niveles::niveles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::niveles)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1000,500);

    ui->graphicsView->setScene(scene);

    timer= new QTimer();
    Tscene = new QTimer();
    Taux = new QTimer();
    Td = new QTimer();
    Ta = new QTimer();

    connect(Tscene,SIGNAL(timeout()),this,SLOT(upScene()));
    connect(timer,SIGNAL(timeout()),this,SLOT(nivel1()));
    connect(Taux,SIGNAL(timeout()),this,SLOT(Sumaux()));
    connect(Td,SIGNAL(timeout()),this,SLOT(CalCantidadD()));
    connect(Ta,SIGNAL(timeout()),this,SLOT(CalCantidadA()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel2()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel3()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel4()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel5()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel6()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel7()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel8()));
//    connect(timer,SIGNAL(timeout()),this,SLOT(nivel9()));

    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer->start(3);
    Tscene->start(16);
    Taux->start(5);

    flagDir = 1;
    flagDirAnt = 1;
}

niveles::~niveles()
{
    delete ui;
}
void niveles::upScene()
{
    qDebug() << jugador->getPx();

    if(jugador->getPx() > 100) {
       x = jugador->getPx()-jugador->getCwidth()-10;
    } else {
       x = scene->sceneRect().x();
       cont = 0;
    }

    if(jugador->getPy() < 365) {
       y = jugador->getPy()+jugador->getCheigh()-250;
    } else {
       y = scene->sceneRect().y();
    }


    scene->setSceneRect(x+cont,y,scene->width(),scene->height());

}

float niveles::CalCantidadD()
{

    if(cont<0)
        cont+=0.5;
    if(cont==0){
       // Td->stop();
    }
    return cont;
}
float niveles::CalCantidadA()
{
    if(cont>-400)
    cont-=0.5;
    if(cont==-400){
      //  Ta->stop();
    }
    return cont;
}

bool niveles::Sumaux()
{
    if(flagDir == flagDirAnt)
    {
       m = false;
    }
    else
    {
       m =  true;
        flagDirAnt = flagDir;
    }
    return m;
}



void niveles::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W)
    {
       flag = true;

       if(jugador->getPy()==500-jugador->getCheigh()){
           jugador->setVy(-80);
       }

       for(int i =0;i<cosas.length();++i)
       {
           if(jugador->collidesWithItem(cosas.at(i)))
           {

                       jugador->setVy(-123);
           }
       }

    }
    if(ev->key()==Qt::Key_S)
    {  
        flag = true;
        jugador->setVy(80);
    }

    if(ev->key()==Qt::Key_D)
    {
        Ta->stop();
        flagDir = 1;
        if(Sumaux())
        {
            if(cont>249)
            cont =0;
            Td->start(1);
        }
        jugador->setVx(100);
    }

    if(ev->key()==Qt::Key_A)
    {
        Td->stop();
        flagDir = 0;
        if(Sumaux())
        {
            if(cont<-249)
            cont =0;
            Ta->start(1);
        }
        jugador->setVx(-100);
    }
}

void niveles::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_D||ev->key()==Qt::Key_A)
    {
        jugador->setVx(0);

    }
    if(ev->key()==Qt::Key_S)
    {
        flag = false;

    }
    if(ev->key()==Qt::Key_W)
    {
        flag = false;
    }

}

void niveles::nivel1()
{
    if(flag2)
    {
        cosas.append(new objetos(600,200,60,10,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(320,300,100,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(440,300,30,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(600,50,100,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(700,50,50,80,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(800,50,80,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(70,450,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(180,400,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(250,350,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1100,450,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1200,50,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1300,0,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1400,-50,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1500,475,500,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1600,-100,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1700,-150,50,20,0,0));
        scene->addItem(cosas.last());
        cosas.append(new objetos(1500,-200,50,20,0,0));
        scene->addItem(cosas.last());




        jugador = new player(0,500,50,70);
        scene->addItem(jugador);
        QPen mypen(Qt::yellow);
        scene->addRect(0,0,1000,500,mypen);
        flag2 = false;
    }
        for(int i =0;i<cosas.length();++i)
        {
          h = cosas.at(i)->getPy()-cosas.at(i)->getCheigh()-(jugador->getPy()+jugador->getCheigh());
          if(cosas.at(i)->collidesWithItem(jugador))
          {
              choque = true;
              if(h>=-1.50){
                  if(!flag)
                  {
                          jugador->detectarpiso(jugador,cosas.at(i));

                  }
               }

          }


        }
        if(!choque)
          jugador->setAy(g);

        choque = false;

    jugador->mover();

}

void niveles::nivel2()
{
    scene->setBackgroundBrush(Qt::magenta);
}

void niveles::nivel3()
{
    scene->setBackgroundBrush(Qt::green);
}

void niveles::nivel4()
{
    scene->setBackgroundBrush(Qt::yellow);
}

void niveles::nivel5()
{
    scene->setBackgroundBrush(Qt::blue);
}

void niveles::nivel6()
{
    scene->setBackgroundBrush(Qt::red);
}

void niveles::nivel7()
{
    scene->setBackgroundBrush(Qt::gray);
}

void niveles::nivel8()
{
    scene->setBackgroundBrush(Qt::darkCyan);
}

void niveles::nivel9()
{
    scene->setBackgroundBrush(Qt::darkYellow);
}



