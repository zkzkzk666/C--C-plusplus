#include "QtWidgetsApplication1.h"
#include<qpushbutton>
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //修改窗口名字
    this->setWindowTitle("zkzk张");
    //设置窗口大小
    //this->resize(800, 600);
    //设置固定大小
    this->setFixedSize(500, 500);
    //创建按钮
    QPushButton* button = new QPushButton("关闭窗口",this);
    //button->show();
    button->resize(100, 100);
    button->move(200, 100);
    connect(button, &QPushButton::clicked, this, &QWidget::close);

}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}
