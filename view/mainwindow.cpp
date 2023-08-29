#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->render_button, &QPushButton::clicked, this, &MainWindow::StartRendering);
}


void MainWindow::StartRendering()
{
    ui->widget->Parse();
    ui->widget->update();
}


MainWindow::~MainWindow()
{
    delete ui;
}
