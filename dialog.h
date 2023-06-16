#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QUrl>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDesktopServices>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Dialog *ui;
    void initilaze();
    void addCategory(QString name);
    void addLink(QListWidget *list, QString name, QString url);
    void addEgitim();
    void addSosyal();
    void addArama();
};
#endif // DIALOG_H
