#include "addshoweditdialog.h"
#include "ui_adddialog.h"
#include <QPixmap>
#include "contactssingleton.h"
#include "QMenu"
#include "QMessageBox"

AddShowEditDialog::AddShowEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{

}

AddShowEditDialog::~AddShowEditDialog()
{
    delete ui;
}

void AddShowEditDialog::setMode(const Modes mode){
    _mode = mode;
}

void AddShowEditDialog::setContact( Contact * contact ){
    _contact = contact;
}

void AddShowEditDialog::init() {
    ui->setupUi(this);
    QPixmap pix(":/images/res/contact-icon");
    int w = ui->picLabel->width();
    int h = ui->picLabel->height();
    ui->picLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->addPhoneBtn->setEnabled(false);
    ui->finalWarning->setVisible(false);
    ui->phoneWarningLabel->setText(INVALID_NUMBER_MESS);
    ui->nameWarningLabel->setVisible(false);
    ui->phoneWarningLabel->setVisible(false);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    switch (_mode) {
    case ADD:
               break;
    case EDIT:
               ui->nameLine->setText(_contact->name());
               ui->surnameLine->setText(_contact->surname());
               for(int i = 0; i < _contact->phoneNumbers().size(); i++){
               ui->listWidget->addItem(_contact->phoneNumbers()[i]);
                }
               break;

    case SHOW:
               ui->nameLine->setText(_contact->name());
               ui->surnameLine->setText(_contact->surname());
               for(int i = 0; i < _contact->phoneNumbers().size(); i++){
               ui->listWidget->addItem(_contact->phoneNumbers()[i]);
               }
               ui->nameLine->setEnabled(false);
               ui->surnameLine->setEnabled(false);
               ui->listWidget->setEnabled(false);
               ui->phoneLine->setVisible(false);
               ui->phoneWarningLabel->setVisible(false);
               ui->nameWarningLabel->setVisible(false);
               ui->addPhoneBtn->setVisible(false);
               ui->finalWarning->setVisible(false);
               ui->cancelBtn->setVisible(false);

               break;
    }
}

void AddShowEditDialog::on_phoneLine_textEdited(const QString &arg1)
{
     ui->phoneWarningLabel->setVisible(!isValidPhoneNumber(arg1));
     ui->addPhoneBtn->setEnabled(isValidPhoneNumber(arg1));
}

void AddShowEditDialog::on_addPhoneBtn_clicked()
{
    ui->listWidget->addItem(ui->phoneLine->text());
    ui->phoneLine->clear();
    ui->phoneWarningLabel->setVisible(true);
    ui->addPhoneBtn->setEnabled(false);
}

void nameSpacesChecking(QString name,QString surname, QLabel* nameWarningLabel, Contact *contact = nullptr ) {
    QString fullname = surname + " " + name;
    if (name.size() == 0 && surname.size() == 0){
        nameWarningLabel->setVisible(true);
        nameWarningLabel->setText(EMPTY_MESS);
    }
    else if(name.size() == 0){
        nameWarningLabel->setVisible(true);
        nameWarningLabel->setText(EMPTY_NAME_MESS);
    }
    else if(surname.size() == 0){
        nameWarningLabel->setVisible(true);
        nameWarningLabel->setText(EMPTY_SURNAME_MESS);
    }

    else if ((ContactsSingleton::getInstance())->contains(fullname) && !(contact!=nullptr && !QString::compare(contact->fullname(), fullname, Qt::CaseInsensitive))) {
        nameWarningLabel->setVisible(true);
        nameWarningLabel->setText(EXIST_CONTACT_MESS);
    }

    else nameWarningLabel->setVisible(false);
}

void AddShowEditDialog::on_nameLine_textEdited(const QString &arg1)
{
    switch(_mode){
    case ADD:
        nameSpacesChecking(arg1, ui->surnameLine->text(), ui->nameWarningLabel );
        break;
    case EDIT:
        nameSpacesChecking(arg1, ui->surnameLine->text(), ui->nameWarningLabel, _contact);
        break;
    }
}

void AddShowEditDialog::on_surnameLine_textEdited(const QString &arg1)
{

    switch(_mode){
    case ADD:
       nameSpacesChecking(ui->nameLine->text(), arg1 , ui->nameWarningLabel );
        break;
    case EDIT:
        nameSpacesChecking(ui->nameLine->text(), arg1 , ui->nameWarningLabel, _contact);
        break;
    }
}

void AddShowEditDialog::on_cancelBtn_clicked()
{
    close();
}

void AddShowEditDialog::on_okBtn_clicked()
{
    switch(_mode) {
    case ADD:
    if(!ui->nameWarningLabel->isVisible() && ui->listWidget->count() != 0) {
        QVector<QString> s;
        for(int i = 0; i < ui->listWidget->count(); ++i)
        {
            QListWidgetItem* item = ui->listWidget->item(i);
            s.push_back(item->text());
        }
        Contact *contact = new Contact(ui->nameLine->text(), ui->surnameLine->text(), s);
        (ContactsSingleton::getInstance())->add(*contact);
        close();
    }

    else {
        ui->finalWarning->setVisible(true);
    }
        break;

    case SHOW:
        close();
        break;

    case EDIT:
         if(!ui->nameWarningLabel->isVisible() && ui->listWidget->count() != 0) {
        QVector<QString> s;
        for(int i = 0; i < ui->listWidget->count(); ++i)
        {
            QListWidgetItem* item = ui->listWidget->item(i);
            s.push_back(item->text());
        }
        _contact->name() = ui->nameLine->text();
        _contact->surname() = ui->surnameLine->text();
        _contact->phoneNumbers() = s;
        close();
         }
         else {
             ui->finalWarning->setVisible(true);
         }
        break;
    }

}

void AddShowEditDialog::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
       QMenu * menu = new QMenu(this);
       QAction * remove = new QAction("remove", this);
       connect(remove, SIGNAL(triggered()), this, SLOT(slotRemoveItem()));
       menu->addAction(remove);
       menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
}

void AddShowEditDialog::slotRemoveItem()
{
    int row = ui->listWidget->selectionModel()->currentIndex().row();
    ui->listWidget->takeItem(row);
}

