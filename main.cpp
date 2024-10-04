#include <Majorwindow.h>
#include <QApplication>
#include <QDir>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // 设置图标
    QApplication::setWindowIcon(QIcon(":/images/resources/icon/thumbnail.png"));
    // 设置应用名称
    QApplication::setApplicationDisplayName("desktop-pet");
    QApplication::setApplicationName("desktop-pet");
    QApplication::setApplicationVersion("v1.0.0");

    MajorWindow major_window;
    major_window.show();

    return QApplication::exec();
}
