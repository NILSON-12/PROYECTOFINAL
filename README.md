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




