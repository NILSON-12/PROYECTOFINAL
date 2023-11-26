#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtextedit.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionINSERTAR_triggered();

    void on_actionGUARDAR_triggered();

    void on_actionIMPRIMIR_triggered();

    void on_actionPEGAR_triggered();

    void on_actionCORTAR_triggered();

    void on_actionNUEVO_triggered();

    void on_actionCOPIAR_triggered();

    void on_actionDESHACER_triggered();

    void on_actionREHACER_triggered();

    void on_actionFUENTES_triggered();

    void on_actionCOLOR_triggered();

    void on_actionCENTRAR_triggered();

    void on_actionDERECHA_triggered();

    void on_actionIZQUIERDA_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
