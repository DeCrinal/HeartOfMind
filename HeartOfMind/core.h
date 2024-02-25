#ifndef CORE_H
#define CORE_H
#include <QObject>
#include <QApplication>
#include "mainwindow.h"

#define DEBUG

class PwdManager;
enum CoreState : uint {
    UnAthorized = 0,
    Athorized = 1,
    Prohibited = 2
};

class Core : public QObject
{
    Q_OBJECT
    QApplication *mApplication {nullptr};

    uint8_t mMaxNumberAttempts {3};
    uint8_t mNumberLogAttempts {0};

    MainWindow *mMainWindow {nullptr};
    CoreState mCurrentState {UnAthorized};

public:
    Core();
    ~Core();
    int start();
    uint getCurrentState() const;
#ifdef DEBUG
    void testNewFunc();
#endif

private:
    bool isCorrectHash(const QString &name, const QString &pwd);
    void authorize();
    void updateWithState();

private slots:
    void checkSignIn(const QString &name, const QString &pwd);

signals:
    void needAuthorize();
    void stateChanged();
};

#endif // CORE_H
