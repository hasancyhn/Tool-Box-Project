#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    initilaze();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::itemDoubleClicked(QListWidgetItem *item)
{
    QString url= item->data(Qt::ItemDataRole::UserRole).toString();
    QDesktopServices::openUrl(QUrl(url));
}

void Dialog::initilaze()
{
    //toolbox icinde sayfa varsa once silinsin
    while(ui->toolBox->count() > 0){
        ui->toolBox->removeItem(0);
    }
    //sayfaları ekliyoruz
    addCategory("Egitim");
    addCategory("Sosyal Medya");
    addCategory("Arama motorlari");
    addEgitim();
    addSosyal();
    addArama();
}

void Dialog::addCategory(QString name)
{
    QListWidget *list=new QListWidget(this);
    ui->toolBox->addItem(list,QIcon(":/resim/images/new.png"),name);
    connect(list, &QListWidget::itemDoubleClicked, this, &Dialog::itemDoubleClicked);
}

void Dialog::addLink(QListWidget *list, QString name, QString url)
{
    QListWidgetItem *itm=new QListWidgetItem(QIcon(":/resim/images/selectall.png"),name);
    itm->setData(Qt::ItemDataRole::UserRole,url);
    list->addItem(itm);
}

void Dialog::addEgitim()
{
    QListWidget *list=qobject_cast<QListWidget*>(ui->toolBox->widget(0));
    if(!list){
        qWarning() << "Egitim ile ilgili bir liste bulunamadi";
        return;
    }
    addLink(list,"Necmettin Erbakan Universitesi","https://www.erbakan.edu.tr");
}

void Dialog::addSosyal()
{

}

void Dialog::addArama()
{

}
