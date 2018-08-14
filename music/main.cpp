#include "MusicWindow.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //字体设置
    int nIndex = QFontDatabase::addApplicationFont("./font/FZZJ-DHSWLJW.TTF");

    if (nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0)
        {
            QFont fontThis(strList.at(0));
            //设置字体大小
//            fontThis.setPointSize(9);
            a.setFont(fontThis);
        }
    }

    MusicWindow::setStyle(":/style/style.qss");
    MusicWindow w;
    w.show();
    return a.exec();
}
