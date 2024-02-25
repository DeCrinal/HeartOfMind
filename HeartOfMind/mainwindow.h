#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Core;
class AuthDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum MainWindowState : int{
        UnAthorizedApp = 0,
        AthorizedApp = 1
    } mCurrentState {UnAthorizedApp};

    //! Pointer to core.
    Core *mCorePtr {nullptr};
    AuthDialog *mAuthDialog {nullptr};

public:
    MainWindow(QWidget *parent = nullptr);
    void setCore(Core *core);
    ~MainWindow();

public slots:
    void authorizeHandler();
    void coreStateChangedHandler();

signals:
    void authorizeChanged(const QString &name, const QString &pwd);

private:
    Ui::MainWindow *ui;

private slots:
    void authDialogHandler(const QString &name, const QString &pwd);
};
#endif // MAINWINDOW_H
