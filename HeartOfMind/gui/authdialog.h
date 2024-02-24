#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>

namespace Ui{
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT


public:
    explicit AuthDialog(const QString &lastUserAuthName,
                            const QString &titleText,
                            const QString &labelText,
                            const QPixmap &icon,
                            QWidget *parent = nullptr);

    QString getName() const;
    QString getPwd() const;

    //void setLockMode();
private:
    Ui::AuthDialog *ui;

private slots:
    void acceptedHandler();

signals:
    void needAproveSignIn(const QString &name, const QString &pwd);

};

#endif //AUTHDIALOG_H
