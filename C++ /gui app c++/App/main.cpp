#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QTimer::singleShot(1000, &a, &QCoreApplication::quit);

    QTextStream input(stdin);
    qInfo() << "Enter Your Name : ";
    QString fullName = input.readLine();
    qInfo() << "Hello : " << fullName;


    return a.exec();
}
