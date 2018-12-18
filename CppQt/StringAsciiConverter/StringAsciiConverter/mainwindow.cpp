#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_edit_str_textChanged()
{
    if(ui->radioBtn_ToAscii->isChecked())
    {
        QString instr = ui->edit_str->toPlainText();
        QString outstr;
        StringUtil::strToAscii(instr, outstr, ui->checkBox_joinSpace->isChecked());
        ui->edit_ascii->setText(outstr);
    }
}

/////////////////////////////////////////////////
void StringUtil::strToAscii(const QString str, QString &astr, bool isJoinSpace)
{
   if(str.isEmpty())
   {
       astr = "";
       return;
   }

   QStringList sl;
   for(QString::ConstIterator ch = str.begin(); ch != str.end(); ch++){
       sl << QString::number( (*ch).unicode(), 16);
   }

   if(isJoinSpace == true)
       astr = sl.join(" ");
   else
       astr = sl.join("");
   astr = astr.toUpper();
}

void StringUtil::asciiToStr(const QString astr, QString &str)
{
   QString instr = astr;
   if(instr.isEmpty())
   {
       str = "";
       return;
   }

   instr.remove(QChar(' '), Qt::CaseInsensitive);
   str = QByteArray::fromHex(instr.toLocal8Bit());
}



void MainWindow::on_edit_ascii_textChanged()
{
    if(ui->radioBtn_ToStr->isChecked())
    {
        QString instr = ui->edit_ascii->toPlainText();
        QString outstr;
        StringUtil::asciiToStr(instr, outstr);
        ui->edit_str->setText(outstr);
    }
}
