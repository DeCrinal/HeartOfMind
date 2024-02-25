#ifndef PWDNOTE_H
#define PWDNOTE_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariantMap>

class PwdNote : public QObject
{
    Q_OBJECT
    const QHash<int, QString> DATA_KEYS{
        {0, "URL"},
        {1, "Password"},
        {2, "Username"},
        {3, "Description"},
        {4, "Category"},
    };

    QVariantMap mData;
    /*QString mEmail;
    QString mPwd;
    QString mDescription;
    QString mURL;*/
    //QString mRefToOtherNote;

    QString mSHA256;

public:
    explicit PwdNote(QObject *parent = nullptr);
    explicit PwdNote(const QString &content, QObject *parent = nullptr);
    QVariantMap getData() const;
    void setData(const QJsonObject &content);

signals:

};

#endif // PWDNOTE_H
