#ifndef SHOWEDITDIALOG_H
#define SHOWEDITDIALOG_H

#include <QDialog>
#include "Utils.h"
#include "contact.h"

namespace Ui {
class ShowEditDialog;
}

class ShowEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowEditDialog(QWidget *parent = nullptr);
    void setContact(Contact * const contact);
    void setMode(const Modes mode);
    void init();
    ~ShowEditDialog();

private slots:
    void on_okBtn_clicked();

private:
    Modes _mode;
    Contact *_contact;
    Ui::ShowEditDialog *ui;
};

#endif // SHOWEDITDIALOG_H
