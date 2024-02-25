#include "versioncontroller.h"

VersionControl::VersionControl(const QString &filePath) :
    mFilePath(filePath)
{

}

void VersionControl::setAnotherFilePath(const QString &filePath)
{
    mFilePath = filePath;
}

bool VersionControl::saveVersion(const QString &content)
{
    int version = mVersions.size() + 1;
    return saveVersionToFile(content, version);
}

bool VersionControl::loadVersion(int version, QString &content)
{
    if (version < 1 || version > mVersions.size()){
        return false;
    }
    return loadVersionFromFile(version, content);
}

int VersionControl::getCurrentVersion() const
{
    return mVersions.size();
}

QStringList VersionControl::getVersionsList() const
{
    return mVersions;
}

bool VersionControl::saveVersionToFile(const QString &content, int version)
{
    QFile file(mFilePath + ".v" + QString::number(version));
    if (!file.open(QFile::WriteOnly)){
        return false;
    }

    QTextStream out(&file);
    out << content;

    file.close();

    mVersions.append(QDateTime::currentDateTime().toString());
    return true;
}

bool VersionControl::loadVersionFromFile(int version, QString &content)
{
    QFile file(mFilePath + ".v" + QString::number(version));
    if (!file.open(QFile::ReadOnly)){
        return false;
    }

    QTextStream in(&file);
    content = in.readAll();

    file.close();

    return true;
}
