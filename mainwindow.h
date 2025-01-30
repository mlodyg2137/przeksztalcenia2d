#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_translationX_valueChanged(int value);

    void on_reset_btn_clicked();

    void on_translationY_valueChanged(int value);

    void on_rotation_valueChanged(int value);

    void on_scalingX_valueChanged(int value);

    void on_scalingY_valueChanged(int value);

    void on_shearingX_valueChanged(int value);

    void on_shearingY_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
