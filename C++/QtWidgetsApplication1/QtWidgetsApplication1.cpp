#include "QtWidgetsApplication1.h"
#include<qpushbutton>
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //�޸Ĵ�������
    this->setWindowTitle("zkzk��");
    //���ô��ڴ�С
    //this->resize(800, 600);
    //���ù̶���С
    this->setFixedSize(500, 500);
    //������ť
    QPushButton* button = new QPushButton("�رմ���",this);
    //button->show();
    button->resize(100, 100);
    button->move(200, 100);
    connect(button, &QPushButton::clicked, this, &QWidget::close);

}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}
