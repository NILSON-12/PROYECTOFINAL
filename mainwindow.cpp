#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QFile>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QTextEdit>

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


void MainWindow::on_actionINSERTAR_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombrearch;
    nombrearch=QFileDialog::getOpenFileName(this, "INSERTÁ ALGO");
    arch.setFileName(nombrearch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen())
    {

        QMessageBox::critical(this, "ERROR PAI",  arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->textEdit->setPlainText(io.readAll());
    arch.close();

}


void MainWindow::on_actionGUARDAR_triggered()
{
    QFile arch;
    QString nombrearch;
    nombrearch=QFileDialog::getSaveFileName(this, "GUARDE, BIEN PUEDA","", "Archivos de texto(*.html *.docx);;Todos los archivos()" );
    arch.setFileName(nombrearch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this, "ERROR MANÍ",  arch.errorString());
            return;
    }
    QTextStream io(&arch);
    io << ui->textEdit->toHtml(); 

    arch.close();
}


void MainWindow::on_actionIMPRIMIR_triggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);

    if (dialog.exec() == QDialog::Accepted) {

    }


}


void MainWindow::on_actionPEGAR_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCORTAR_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionNUEVO_triggered()
{

}


void MainWindow::on_actionCOPIAR_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionDESHACER_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionREHACER_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionFUENTES_triggered()
{
    
    QTextCharFormat formatoActual = ui->textEdit->textCursor().charFormat();

    
    bool siono;
    QFont fuenteNueva = QFontDialog::getFont(&siono, formatoActual.font(), this);

    if (siono)
    {      
        formatoActual.setFont(fuenteNueva);

        ui->textEdit->textCursor().mergeCharFormat(formatoActual);
    }
}


void MainWindow::on_actionCOLOR_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if (color.isValid())
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextCharFormat charFormat = cursor.charFormat();
        charFormat.setForeground(color);
        cursor.setCharFormat(charFormat);
    }
}


void MainWindow::on_actionCENTRAR_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_actionDERECHA_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);

}



void MainWindow::on_actionIZQUIERDA_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

