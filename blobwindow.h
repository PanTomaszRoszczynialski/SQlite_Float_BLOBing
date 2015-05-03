#ifndef BLOBWINDOW_H
#define BLOBWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

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

    void    initBlobDatabase();

public slots:
    void on_insertBtn_clicked();
    void on_loadBtn_clicked();
};

#endif // BLOBWINDOW_H
