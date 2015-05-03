#ifndef BLOBWINDOW_H
#define BLOBWINDOW_H

#include <QMainWindow>

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
};

#endif // BLOBWINDOW_H
