#ifndef PWDNOTE_H
#define PWDNOTE_H

#include <QObject>

class PwdNote : public QObject
{
    Q_OBJECT

    QString mEmail;
    QString mPwd;
    QString mDescription;
    QString mURL;
    QString mRefToOtherNote;

    QString mSHA256;

public:
    explicit PwdNote(QObject *parent = nullptr);

signals:

};

#endif // PWDNOTE_H
