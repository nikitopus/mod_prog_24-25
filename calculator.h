#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

class QPushButton;
class QLineEdit;

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
    QLineEdit *resultField;       // Поле вывода результата
    QPushButton *numberButtons[10];   // Кнопки цифр
    QPushButton *buttonAdd;
    QPushButton *buttonSubtract;
    QPushButton *buttonMultiply;
    QPushButton *buttonDivide;
    QPushButton *buttonEqual;
    QPushButton *buttonClear;

    double currentResult;        // Текущий результат
    QString currentOperation;    // Текущая операция
    bool isNewOperation;         // Состояние ввода
};

#endif // CALCULATOR_H
