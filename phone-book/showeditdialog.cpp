#include "showeditdialog.h"
#include "ui_showeditdialog.h"


ShowEditDialog::ShowEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowEditDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/images/res/contact-icon");
    int w = ui->picLabel->width();
    int h = ui->picLabel->height();
    ui->picLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void ShowEditDialog::setMode(const Modes mode){
    _mode = mode;
}

void ShowEditDialog::setContact( Contact * const contact ){
    _contact = contact;
}

void ShowEditDialog::init() {
    ui->nameLine->setText(_contact->name());
    ui->surnameLine->setText(_contact->surname());
    for(int i = 0; i < _contact->phoneNumbers().size(); i++){
        ui->listWidget->addItem(_contact->phoneNumbers()[i]);
    }
    switch (_mode) {
    case EDIT: ui->nameLine->setEnabled(true);
               ui->surnameLine->setEnabled(true);
               ui->listWidget->setEnabled(true);
               break;
    case SHOW: ui->nameLine->setEnabled(false);
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


ShowEditDialog::~ShowEditDialog()
{
    delete ui;
}

void ShowEditDialog::on_okBtn_clicked()
{

}
