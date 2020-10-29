#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "randomnumbercaretaker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void buttonClicked();
    void getMemento(QModelIndex index);

private:
    Ui::MainWindow *ui;
    int count;
    RandomNumberCaretaker ct;
    RandomNumberGenerator rg;
    QStringList rolls;
    QStringListModel model;
    void setPics(QList<int> num);
    QString stringRollNums(QList<int> nums) const;
    int modelToindex(QString s)const;

};

#endif // MAINWINDOW_H
