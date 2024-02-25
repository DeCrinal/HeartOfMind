#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gui/authdialog.h"

#include "core.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mAuthDialog = new AuthDialog("Heart of mind",
                                 QObject::tr("Вход в программу"),
                                 QObject::tr("Heart of mind\nВведите имя пользователя и пароль"),
                                 QPixmap(":/images/"));
    connect(mAuthDialog, &AuthDialog::needAproveSignIn, this, &MainWindow::authDialogHandler);
}

void MainWindow::setCore(Core *core)
{
    mCorePtr = core;
    setWindowTitle("Heart of mind");
    connect(core, &Core::stateChanged, this, &MainWindow::coreStateChangedHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::authorizeHandler()
{
    mAuthDialog->exec();
}

void MainWindow::coreStateChangedHandler()
{
    const auto coreCurrState = mCorePtr->getCurrentState();
    if(mCurrentState == MainWindowState::UnAthorizedApp){
        if(coreCurrState == CoreState::Prohibited){
            QMessageBox::information(this, "Information", "Fuck off FBI!");
        }
    }
    else if(mCurrentState == MainWindowState::AthorizedApp){

    }
    mAuthDialog->close();
}

void MainWindow::authDialogHandler(const QString &name, const QString &pwd)
{
    emit authorizeChanged(name, pwd);
}

