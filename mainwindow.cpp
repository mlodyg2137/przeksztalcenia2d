#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reset_btn_clicked()
{
    ui->translationX->setValue(0);
    ui->translationY->setValue(0);
    ui->rotation->setValue(0);
    ui->scalingX->setValue(0);
    ui->scalingY->setValue(0);
    ui->shearingX->setValue(0);
    ui->shearingY->setValue(0);
}

void MainWindow::on_translationX_valueChanged(int value)
{
    // double scaled_value =
    ui->widget->setTranslationX(value);
    ui->widget->updateImage();
}

void MainWindow::on_translationY_valueChanged(int value)
{
    ui->widget->setTranslationY(value);
    ui->widget->updateImage();
}


void MainWindow::on_rotation_valueChanged(int value)
{
    ui->widget->setRotation(value);
    ui->widget->updateImage();
}


void MainWindow::on_scalingX_valueChanged(int value)
{
    ui->widget->setScalingX(value);
    ui->widget->updateImage();
}


void MainWindow::on_scalingY_valueChanged(int value)
{
    ui->widget->setScalingY(value);
    ui->widget->updateImage();
}


void MainWindow::on_shearingX_valueChanged(int value)
{
    ui->widget->setShearingX(value);
    ui->widget->updateImage();
}

void MainWindow::on_shearingY_valueChanged(int value)
{
    ui->widget->setShearingY(value);
    ui->widget->updateImage();
}

