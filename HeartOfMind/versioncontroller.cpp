#include "versioncontroller.h"

VersionControl::VersionControl(const QString& filePath) :
    m_filePath(filePath)
{

}

bool VersionControl::saveVersion(const QString& content)
{
    int version = m_versions.size() + 1;
    return saveVersionToFile(content, version);
}

bool VersionControl::loadVersion(int version, QString& content)
{
    if (version < 1 || version > m_versions.size()) {
        return false;
    }
    return loadVersionFromFile(version, content);
}

int VersionControl::getCurrentVersion() const
{
    return m_versions.size();
}

QStringList VersionControl::getVersionsList() const
{
    return m_versions;
}

bool VersionControl::saveVersionToFile(const QString& content, int version)
{
    QFile file(m_filePath + ".v" + QString::number(version));
    if (!file.open(QFile::WriteOnly)) {
        return false;
    }

    QTextStream out(&file);
    out << content;

    file.close();

    m_versions.append(QDateTime::currentDateTime().toString());
    return true;
}

bool VersionControl::loadVersionFromFile(int version, QString& content)
{
    QFile file(m_filePath + ".v" + QString::number(version));
    if (!file.open(QFile::ReadOnly)) {
        return false;
    }

    QTextStream in(&file);
    content = in.readAll();

    file.close();

    return true;
}
