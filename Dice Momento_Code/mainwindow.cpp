#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    rg.setMinMax(1,6);
    model.setStringList(rolls);
    ui->listView->setModel(&model);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(getMemento(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(){
   count ++;
   QList<int> nums = rg.getRandomNumber(6);

   rolls.append(stringRollNums(nums));
   model.setStringList(rolls);
   ct.addAMemento(rg.createMemento());
   setPics(nums);
}

void MainWindow::getMemento(QModelIndex index){
    QString data = (model.data(index,0)).toString();
    rg.setMemento(ct.getAMemento(modelToindex(data)-1));
    setPics(rg.getRandomNumber(6));
}

void MainWindow::setPics(QList<int> nums){    
    QList<QPixmap> pixmaps;
    foreach(int i, nums){
        QString fName (":/images/");        
        fName.append(QString::number(i,10));
        fName.append(".png");
        QPixmap pixmap(fName);
        pixmaps.append(pixmap);
    }
     ui->label_2->setPixmap(pixmaps[0]);
     ui->label_3->setPixmap(pixmaps[1]);
     ui->label_4->setPixmap(pixmaps[2]);
     ui->label_5->setPixmap(pixmaps[3]);
     ui->label_6->setPixmap(pixmaps[4]);
     ui->label_7->setPixmap(pixmaps[5]);
}

QString MainWindow::stringRollNums(QList<int> nums)const {
    QStringList numstrings;
    foreach(int n, nums){
        numstrings.append(QString::number(n,10));
    }
    return QString("%1 : %2").arg(count).arg(numstrings.join(","));
}

int MainWindow::modelToindex(QString s) const{
    QStringList tempList = s.split(":");
    QString tempS = tempList[0].trimmed();
    return tempS.toInt();
}
