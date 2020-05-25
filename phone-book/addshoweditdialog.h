#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "Utils.h"
#include "contact.h"
#include "QListWidget"

namespace Ui {
class AddDialog;
}

class AddShowEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddShowEditDialog(QWidget *parent = nullptr);
    void setContact(Contact * contact);
    void setMode(const Modes mode);
    void init();
    ~AddShowEditDialog();

private slots:
    void slotRemoveItem();

    void on_phoneLine_textEdited(const QString &arg1);

    void on_addPhoneBtn_clicked();

    void on_nameLine_textEdited(const QString &arg1);

    void on_surnameLine_textEdited(const QString &arg1);

    void on_cancelBtn_clicked();

    void on_okBtn_clicked();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);



private:
    Modes _mode;
    Contact *_contact;
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
