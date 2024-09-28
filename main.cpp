#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем и показываем окно логина
    Login loginWindow;
    loginWindow.show();

    return a.exec();
}
