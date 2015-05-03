#ifndef BLOBWINDOW_H
#define BLOBWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>

namespace Ui {
class BlobWindow;
}

class BlobWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlobWindow(QWidget *parent = 0);
    ~BlobWindow();

private:
    Ui::BlobWindow *ui;

    QMap<QPair<int,int>, QVector<float>*> _map;

    void    initBlobDatabase();

    QByteArray      blobify(QVector<float> vec);
    QByteArray      blobify(QVector<float>* vec);
    QVector<float>  unBlobify(QByteArray data);

public slots:
    void on_insertBtn_clicked();
    void on_loadBtn_clicked();
};

#endif // BLOBWINDOW_H
