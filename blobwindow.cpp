#include "blobwindow.h"
#include "ui_blobwindow.h"
#include <QDebug>

BlobWindow::BlobWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BlobWindow)
{
    ui->setupUi(this);
    initBlobDatabase();
}

BlobWindow::~BlobWindow()
{
    delete ui;
}

void BlobWindow::initBlobDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myBLOB.sqlite");

    if (! db.open()) {
        qDebug() << db.lastError().text() << __func__;
        return;
    }

    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS Blobs "
               "(ID         integer primary key, "
               "Name        varchar(255), "
               "floatsVec   BLOB)");
}

QByteArray BlobWindow::blobify(QVector<float> vec)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << vec;

    return data;
}

QByteArray BlobWindow::blobify(QVector<float> *vec)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << *vec;

    return data;
}

QVector<float> BlobWindow::unBlobify(QByteArray data)
{
    QVector<float> vec;
    QDataStream stream(data);
    stream >> vec;

    return vec;
}

void BlobWindow::on_insertBtn_clicked()
{
    QString name = ui->insertNameEdt->text();
    QVector<float> *vec = new QVector<float>;

    float tmp;
    for (int i = 0; i < 5; ++i) {
        tmp = 20.f/(rand()%1024);
        vec->append(tmp);
    }
    qDebug() << *vec << __func__;
    QByteArray data = blobify(vec);


    QSqlQuery query;
    query.prepare("INSERT INTO Blobs ("
                  "Name, floatsVec) VALUES ("
                  ":Name, :floatsVec)");
    query.bindValue(":Name",name);
    query.bindValue(":floatsVec",data);
    query.exec();
    qDebug() << data.toHex() << vec <<__func__;
}

void BlobWindow::on_loadBtn_clicked()
{
    QString name = ui->loadNameEdt->text();
    QSqlQuery query;
    QString qry_string = "SELECT floatsVec FROM Blobs WHERE Name='%1'";
    query.exec(qry_string.arg(name));
    query.first();
    QByteArray data = query.value("floatsVec").toByteArray();
    qDebug() << data.toHex() << __func__;
    QVector<float> vec = unBlobify(data);

    qDebug() << vec << __func__;
}
