#include "core.h"
#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include "versioncontroller.h"

//test:
#include <QJsonObject>
#include "pwdmanager/pwdnote.h"

Core::Core()
{
    mMainWindow = new MainWindow;
    mMainWindow->setCore(this);
    connect(this, &Core::needAuthorize, mMainWindow, &MainWindow::authorizeHandler);
    connect(mMainWindow, &MainWindow::authorizeChanged, this, &Core::checkSignIn);

}

Core::~Core()
{

}

int Core::start()
{
    const QString ORG_NAME {"MaiRai Software"};
    const QString APP_NAME {"Heart of Mind"};

    emit needAuthorize();

    return 0;
}

uint Core::getCurrentState() const
{
    return mCurrentState;
}

#ifdef DEBUG
void Core::testNewFunc()
{
    QJsonObject jsonObject = {
        {"URL:", "https:\\\\github.com"},
        {"Password", "Not your deal"},
        {"Username", "DeCrinal"}
    };
    PwdNote note;
    note.setData(jsonObject);
}
#endif

bool Core::isCorrectHash(const QString &name, const QString &pwd)
{
    Q_UNUSED(name)
    Q_UNUSED(pwd)
   //заглушка
    return true;
}

void Core::authorize()
{
    emit needAuthorize();

}

void Core::updateWithState()
{
    if(mCurrentState == CoreState::Athorized){
        mMainWindow->show();
        testNewFunc();
    }
    if(mCurrentState == CoreState::Prohibited){
        exit(0);
    }
}

void Core::checkSignIn(const QString &name, const QString &pwd)
{
    mNumberLogAttempts++;
    const bool checkingResult = isCorrectHash(name, pwd);
    const auto oldState = mCurrentState;
    if(mNumberLogAttempts > mMaxNumberAttempts){
        mCurrentState = CoreState::Prohibited;
    }
    else if(checkingResult){
        mCurrentState = CoreState::Athorized;
    }

    if(oldState != mCurrentState){
        emit stateChanged();
        updateWithState();
    }
}
