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
    AuthDialog authDialog("Heart of mind",
                          QObject::tr("Вход в программу"),
                          QObject::tr("Heart of mind\nВведите имя пользователя и пароль"),
                          QPixmap(":/images/"));
    connect(&authDialog, &AuthDialog::needAproveSignIn, this, &MainWindow::authDialogHandler);
    authDialog.exec();
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
}

void MainWindow::authDialogHandler(const QString &name, const QString &pwd)
{
    emit authorizeChanged(name, pwd);
}

