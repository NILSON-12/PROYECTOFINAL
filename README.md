# PROYECTOFINAL
Editor de texto en Qt Creator tipo Word




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

Esta función abre un cuadro de diálogo para que el usuario seleccione un archivo, lee su contenido y lo coloca en un widget de texto (textEdit) en la interfaz de usuario.



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

Esta función permite al usuario seleccionar o especificar un nombre y ubicación para guardar un archivo, y luego escribe el contenido del widget de texto (textEdit) en formato HTML en ese archivo.



void MainWindow::on_actionIMPRIMIR_triggered()
{
  
    QPrinter printer;
    QPrintDialog dialog(&printer, this);

    if (dialog.exec() == QDialog::Accepted) {

    }


}

Esta función permite al usuario abrir el menú de impresión, para imprimir su archivo.



void MainWindow::on_actionPEGAR_triggered()
{

    ui->textEdit->paste();
}


void MainWindow::on_actionCORTAR_triggered()
{

    ui->textEdit->cut();
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

Funciones rápidas en las que permiten al usuario copiar,pegar,cortar,deshacer y rehacer lo escrito en el textEdit.






