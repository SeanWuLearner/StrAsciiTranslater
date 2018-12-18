#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_edit_str_textChanged();

    void on_edit_ascii_textChanged();

private:
    Ui::MainWindow *ui;
};


class StringUtil
{
public:
    static void strToAscii(const QString str, QString &astr, bool isJoinSpace);
    static void asciiToStr(const QString astr, QString &str);
};

#endif // MAINWINDOW_H
