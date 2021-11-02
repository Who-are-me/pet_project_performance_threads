#include <ctime>
#include <QString>
#include <iostream>


#define PI 3.1415926535


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CalculatorIntegrals.hpp"


MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditResult->setReadOnly(true);
    ui->lineEditTime->setReadOnly(true);
}


MainWindow::~MainWindow () {
    delete ui;
}


void MainWindow::setIntegral (const std::function<f64 (f64, f64)> integral) {
    this->m_integral = integral;
}


void MainWindow::on_btnCalculate_released () {
    CalculatorIntegrals ci;

    if (ui->lineEditCountThreads->text().toShort() >= 0 && ui->lineEditCountSteps->text().toULongLong() >= 0) {
        ci.setCountThreads(ui->lineEditCountThreads->text().toShort());

        clock_t start = clock();
        ci.calculator(0, PI/2, ui->lineEditCountSteps->text().toULongLong(), m_integral);
        clock_t end = clock();

        std::cout << "Time:\t" << ((double)(end - start) / CLOCKS_PER_SEC) << std::endl;
        std::cout << "Result:\t" << ci.getResult() << std::endl;

        ui->lineEditTime->setText( QString::number((double)(end - start) / CLOCKS_PER_SEC) );
        ui->lineEditResult->setText( QString::number(ci.getResult()) );
    }
    else {
        ui->lineEditTime->setText( "Error" );
        ui->lineEditResult->setText( "Error" );
    }
}






















