#include "blobwindow.h"
#include "ui_blobwindow.h"

BlobWindow::BlobWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BlobWindow)
{
    ui->setupUi(this);
}

BlobWindow::~BlobWindow()
{
    delete ui;
}
