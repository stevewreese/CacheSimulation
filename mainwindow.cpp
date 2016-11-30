#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    full.Pass();
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *setdes = new QTableWidgetItem;
            int thing = full.returnTable(i, j);
            QString item = QString::number(thing);
            setdes->setText(item);
            ui->tableWidget->setItem(i, j, setdes);

        }
    }
    QString calc = QString::number(full.calculate());
    ui->textEdit->setText(calc);
}

void MainWindow::on_pushButton_2_clicked()
{
    map.cache();
    map.calculate();
}

void MainWindow::on_pushButton_3_clicked()
{
    set.cache();
}
