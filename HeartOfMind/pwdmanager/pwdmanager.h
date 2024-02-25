#ifndef PWDMANAGER_H
#define PWDMANAGER_H

#include <QObject>

class PwdManager : public QObject
{
    Q_OBJECT
public:
    PwdManager();
    void checkAuth(const QString &userName, const QString &pwd);
    void changeAuthPwd(const QString &pwd);
    void changeAuthUserName();
    void changeStorageDir();
};

#endif // PWDMANAGER_H
