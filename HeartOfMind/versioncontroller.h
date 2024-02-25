#ifndef VERSIONCONTROLLER_H
#define VERSIONCONTROLLER_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QVector>

class VersionControl {
private:
    QString mFilePath;
    QStringList mVersions;

public:
    VersionControl(const QString &filePath);

    void setAnotherFilePath(const QString &filePath);
    bool saveVersion(const QString &content);
    bool loadVersion(int version, QString &content);
    int getCurrentVersion() const;
    QStringList getVersionsList() const;

private:

    bool saveVersionToFile(const QString &content, int version);
    bool loadVersionFromFile(int version, QString &content);
};

#endif // VERSIONCONTROLLER_H
