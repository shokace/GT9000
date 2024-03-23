#include "mainwindow.h"
#include "gt668drv.h"

#include <QApplication>
#include <QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("/GT9000/GT9000/images.jpeg");
    QSplashScreen splash(pixmap);
    splash.setWindowState(Qt::WindowFullScreen);
    splash.show();
    GT668EnumerateBoards(GT_True);
    splash.showMessage("Initializing...", Qt::AlignBottom | Qt::AlignCenter, Qt::white);











    MainWindow w;
    QTimer::singleShot(3000, &splash, [&]() {
        w.setWindowState(Qt::WindowFullScreen);
        w.show();
        splash.close(); // Close the splash screen
    });


    return a.exec();
}
