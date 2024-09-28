#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void onNumberButtonClicked();       // Слот для обработки нажатий на кнопки чисел
    void onOperationButtonClicked();    // Слот для обработки операций
    void onEqualButtonClicked();        // Слот для кнопки равенства
    void onClearButtonClicked();        // Слот для кнопки очистки

private:
    Ui::Calculator *ui;
    double currentResult;       // Переменная для хранения текущего результата
    QString currentOperation;   // Переменная для хранения текущей операции
    bool isNewOperation;        // Переменная для управления состоянием ввода
};

#endif // CALCULATOR_H
