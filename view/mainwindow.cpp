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
    ui->gl_visual->Parse();
    ui->gl_visual->update();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_double_spin_box_scale_valueChanged(double arg1)
{
    ui->gl_visual->Scale(arg1);
}

