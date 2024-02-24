#include "authdialog.h"
#include "ui_authdialog.h"
#include <QTimer>

AuthDialog::AuthDialog(const QString &userAuthName, const QString &titleText,
                       const QString &labelText, const QPixmap &icon, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    Q_UNUSED(labelText)
    Q_UNUSED(userAuthName)
    Q_UNUSED(icon)
    ui->setupUi(this);

    setWindowTitle(titleText);

    connect(ui->enterPBtn, &QPushButton::clicked,  this, &AuthDialog::acceptedHandler);

}

QString AuthDialog::getName() const
{
    return ui->userLineEdit->text();
}

QString AuthDialog::getPwd() const
{
    return ui->pwdLineEdit->text();
}

void AuthDialog::acceptedHandler()
{
    const QString name = ui->userLineEdit->text();
    const QString pwd = ui->pwdLineEdit->text();
    emit needAproveSignIn(name, pwd);
    qApp->processEvents();
}
