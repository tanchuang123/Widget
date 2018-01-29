#include "ttkmarqueewindow.h"
#include "ui_ttkmarqueewindow.h"
#include <QtDebug>
#include <QColorDialog>
TTKMarqueeWindow::TTKMarqueeWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKMarqueeWindow)
{
    ui->setupUi(this);

    ui->widget->setText("adbnsaklbdjafkcbnasklfbcaklsdbfjaskfbcsbvjsdjdvbldbcajsk");
    ctrlFrame = new QFrame;
    contentFrame=new QFrame;
    qDebug()<<ui->widget->sizeHint();
    connect(ui->toolButton, SIGNAL(pressed()), this, SLOT(selectColor()));
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(sl_base()));
}

TTKMarqueeWindow::~TTKMarqueeWindow()
{
    delete ui;
}

void TTKMarqueeWindow::selectColor()//选择颜色
{
    QColorDialog dialog;
    if (dialog.exec()) {
        QColor color = dialog.selectedColor();
        QString senderName = sender()->objectName();
        if ("toolButton" == senderName) {
           ui->widget->setAutoFillBackground(true);//必须有这条语句
           ui->widget->setPalette(QPalette(color));

//           QPalette pal =lineEdit->QPalette();
//           pal->setColor(QPalette::Text,QColor(255,0,0);
//           ui->widget->setPalette(QPalette::Text,color);
//            QPalette palette;
//            palette.setColor(QPalette::Background, QColor(192,253,123,100)); // 最后一项为透明度

//            ui->widget->setPalette(palette);
//            this->setBackgroundColor(color);
//            ui->backgroundColorLineEdit->setText(color.name(QColor::HexRgb));
        }
    }
//    setupForm();
    update();
}
void TTKMarqueeWindow::setBackgroundColor(const QColor &color)
{
//    Q_D(TTKMarqueeWidget);

    this->backgroundColor = color;

    if (this->useThemeColors == true) {
        this->useThemeColors = false;
    }
    update();
}
//void TTKMarqueeWindow::sl_base()
//{
//    QStringList colorNameList = QColor::colorNames();
//    QColor m_color = QColor(colorNameList[ui->comboBox->currentIndex()]);
//    QPalette p = ui->frame->palette();
//    p.setColor(QPalette::Base,m_color);
//    ui->frame->setPalette(p);
//}
