#include "pwdnote.h"

PwdNote::PwdNote(QObject *parent)
    : QObject{parent}
{

}

PwdNote::PwdNote(const QString &content, QObject *parent)
{

}

QVariantMap PwdNote::getData() const
{
    return mData;
}

void PwdNote::setData(const QJsonObject &content)
{
    //size_t keyCursor = 0;
    for(auto it = content.begin(); it != content.end(); it++){
        const QString &key = it.key();
        const QJsonValue &value = it.value();
        mData[key] = value.toVariant();
        //keyCursor++;
    }
    qDebug();
}
