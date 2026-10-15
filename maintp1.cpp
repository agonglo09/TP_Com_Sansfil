#include "maintp1.h"
#include "ui_maintp1.h"

Maintp1::Maintp1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Maintp1)
{
    ui->setupUi(this);
}

Maintp1::~Maintp1()
{
    delete ui;
}
