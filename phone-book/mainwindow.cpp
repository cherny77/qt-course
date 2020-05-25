#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addshoweditdialog.h"
#include "contactssingleton.h"
#include "vector"
#include "string"
#include "QString"
#include "QMessageBox"
#include "Utils.h"
#include <iostream>


void fillList(QListWidget *listWidget, QVector<Contact> *contacts) {
    listWidget->clear();
    for (int i = 0; i < contacts->size(); i++)
   {
    listWidget->addItem((*contacts)[i].fullname());
   }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->deleteBtn->setEnabled(false);
    ui->editBtn->setEnabled(false);
    Contacts *contacts = (ContactsSingleton::getInstance());
    ui->listWidget->addItem(QString());
    fillList(ui->listWidget, &contacts->contacts());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_deleteBtn_clicked()
{

    Contacts *contacts = (ContactsSingleton::getInstance());
    contacts->remove(*(contacts->findContactbyFullname(ui->listWidget->currentItem()->text())));
    QListWidgetItem *it = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete it;
    ui->deleteBtn->setEnabled(false);
    ui->editBtn->setEnabled(false);

}



void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->deleteBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

    fillList(ui->listWidget, ((ContactsSingleton::getInstance())->filterContacts(arg1)));
}

void MainWindow::on_addBtn_clicked()
{
        AddShowEditDialog addDialog;
        addDialog.setMode(Modes::ADD);
        addDialog.init();
        addDialog.setModal(true);
        addDialog.exec();
        fillList(ui->listWidget, &((ContactsSingleton::getInstance())->contacts()));
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    AddShowEditDialog showDialog;
    showDialog.setMode(Modes::SHOW);
    showDialog.setContact((ContactsSingleton::getInstance())->findContactbyFullname(item->text()));
    showDialog.init();
    showDialog.setModal(true);
    showDialog.exec();

}

void MainWindow::on_editBtn_clicked()
{
    AddShowEditDialog editDialog;
    editDialog.setMode(Modes::EDIT);
    editDialog.setContact((ContactsSingleton::getInstance())
                              ->findContactbyFullname(ui->listWidget->currentItem()->text()));
    editDialog.init();
    editDialog.setModal(true);
    editDialog.exec();
     fillList(ui->listWidget, &((ContactsSingleton::getInstance())->contacts()));
}
