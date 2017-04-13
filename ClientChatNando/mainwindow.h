#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    bool writeData(QByteArray data);

signals:
    void dataRecived(QByteArray);

private slots:
    void on_pushButton_clicked();
    void conessione();
    void onClickButtoSend();
    void readyReadd();
    void addDalServer(QByteArray a);

private:
    Ui::MainWindow *ui;
    QTcpSocket *s;
    QByteArray intToArray(qint32 sorce);
    QHash<QTcpSocket*, QByteArray*> buffers;
    QHash<QTcpSocket*, qint32*> sizes;
};

#endif // MAINWINDOW_H
