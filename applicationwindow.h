#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class ApplicationWindow;
}

class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ApplicationWindow(QWidget *parent = 0);
    ~ApplicationWindow();

private:
    Ui::ApplicationWindow *ui;
};

#endif // APPLICATIONWINDOW_H
