#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QAbstractNativeEventFilter>
#include <QMainWindow>
#include<windows.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual bool nativeEventFilter(const QByteArray &eventType, void *msg, long *) Q_DECL_OVERRIDE;

private:
    Ui::MainWindow *ui;
     ATOM atom;
};

#endif // MAINWINDOW_H
