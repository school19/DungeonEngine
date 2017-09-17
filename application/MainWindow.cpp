#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(std::move(std::make_unique<Ui::MainWindow>()))
{
    ui->setupUi(this);
    connect(ui->actionNew, SIGNAL(triggered), this, SLOT(createNew));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createNew()
{

}