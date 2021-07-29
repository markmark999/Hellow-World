#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QAbstractNativeEventFilter>
#include<windows.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    atom=GlobalAddAtom("a");
    BOOL a=RegisterHotKey((HWND)winId(),atom,MOD_ALT,VK_F8);
    if(a)
        qApp->installNativeEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    BOOL b=UnregisterHotKey((HWND)winId(),atom);
    GlobalDeleteAtom(atom);
}

bool MainWindow::nativeEventFilter(const QByteArray &eventType, void *msg, long *)
{
    if(eventType=="windows_generic_MSG")
    {
        MSG *pmsg=reinterpret_cast<MSG*>(msg);
        if((WM_HOTKEY==pmsg->message)&&((UINT)LOWORD(pmsg->lParam)==MOD_ALT)&&((UINT)HIWORD(pmsg->lParam)==VK_F8)){
            if(this->isHidden())
                this->show();
            else
                this->hide();
            return true;
        }
        return false;
    }
    return false;
}
