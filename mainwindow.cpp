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
    io << ui->textEdit->toHtml(); // Asegúrate de que 'textEdit' es un QTextEdit

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
    // Obtener el formato actual del cursor de texto
    QTextCharFormat formatoActual = ui->textEdit->textCursor().charFormat();

    // Mostrar el diálogo de selección de fuente y actualizar el formato actual
    bool siono;
    QFont fuenteNueva = QFontDialog::getFont(&siono, formatoActual.font(), this);

    if (siono)
    {
        // Establecer la fuente en el formato actual
        formatoActual.setFont(fuenteNueva);

        // Aplicar el formato actual al texto seleccionado (o al cursor)
        ui->textEdit->textCursor().mergeCharFormat(formatoActual);
    }
    // No es necesario un "else" ya que si el usuario cancela, no realizas cambios.
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

