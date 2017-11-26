#include "applicationwindow.h"
#include "ui_applicationwindow.h"
#include <QLabel>

ApplicationWindow::ApplicationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApplicationWindow)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(this);
    label->setText("Adam \nAndrzej");
}

ApplicationWindow::~ApplicationWindow()
{
    delete ui;
}
