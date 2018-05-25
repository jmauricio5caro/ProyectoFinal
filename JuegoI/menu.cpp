#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_nivel1_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel1();
    this->close();
}

void menu::on_nivel2_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel2();
    this->close();
}

void menu::on_nivel3_clicked()
{

    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel3();
    this->close();
}

void menu::on_nivel4_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel4();
    this->close();
}

void menu::on_nivel5_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel5();
    this->close();
}

void menu::on_nivel6_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel6();
    this->close();
}

void menu::on_nivel7_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel7();
    this->close();
}

void menu::on_nivel8_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel8();
    this->close();
}

void menu::on_nivel9_clicked()
{
    escenarios = new niveles();
    escenarios->show();
    escenarios->nivel9();
    this->close();
}
