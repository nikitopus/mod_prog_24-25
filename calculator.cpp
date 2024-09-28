#include "calculator.h"
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    currentResult(0.0),
    isNewOperation(true)
{
    // Создаем поле для вывода результата
    resultField = new QLineEdit;
    resultField->setAlignment(Qt::AlignRight);  // Выравниваем текст по правому краю
    resultField->setReadOnly(true);  // Поле только для чтения

    // Создаем кнопки чисел
    for (int i = 0; i < 10; ++i) {
        numberButtons[i] = new QPushButton(QString::number(i));
        connect(numberButtons[i], &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    }

    // Создаем кнопки операций
    buttonAdd = new QPushButton("+");
    buttonSubtract = new QPushButton("-");
    buttonMultiply = new QPushButton("*");
    buttonDivide = new QPushButton("/");
    buttonEqual = new QPushButton("=");
    buttonClear = new QPushButton("C");

    // Подключаем кнопки операций к слотам
    connect(buttonAdd, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(buttonSubtract, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(buttonMultiply, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(buttonDivide, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(buttonEqual, &QPushButton::clicked, this, &Calculator::onEqualButtonClicked);
    connect(buttonClear, &QPushButton::clicked, this, &Calculator::onClearButtonClicked);

    // Макет для кнопок чисел
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(numberButtons[1], 0, 0);
    gridLayout->addWidget(numberButtons[2], 0, 1);
    gridLayout->addWidget(numberButtons[3], 0, 2);
    gridLayout->addWidget(buttonAdd, 0, 3);

    gridLayout->addWidget(numberButtons[4], 1, 0);
    gridLayout->addWidget(numberButtons[5], 1, 1);
    gridLayout->addWidget(numberButtons[6], 1, 2);
    gridLayout->addWidget(buttonSubtract, 1, 3);

    gridLayout->addWidget(numberButtons[7], 2, 0);
    gridLayout->addWidget(numberButtons[8], 2, 1);
    gridLayout->addWidget(numberButtons[9], 2, 2);
    gridLayout->addWidget(buttonMultiply, 2, 3);

    gridLayout->addWidget(buttonClear, 3, 0);
    gridLayout->addWidget(numberButtons[0], 3, 1);
    gridLayout->addWidget(buttonEqual, 3, 2);
    gridLayout->addWidget(buttonDivide, 3, 3);

    // Основной макет
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(resultField);
    mainLayout->addLayout(gridLayout);

    // Устанавливаем макет в центральный виджет окна
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle("Калькулятор");
    resize(300, 400);
}

Calculator::~Calculator()
{
    // Здесь тоже не нужно ничего удалять вручную
}

void Calculator::onNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonText = button->text();
        if (isNewOperation) {
            resultField->setText(buttonText);
            isNewOperation = false;
        } else {
            resultField->setText(resultField->text() + buttonText);
        }
    }
}

void Calculator::onOperationButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        currentResult = resultField->text().toDouble();
        currentOperation = button->text();
        isNewOperation = true;
    }
}

void Calculator::onEqualButtonClicked()
{
    double operand = resultField->text().toDouble();
    if (currentOperation == "+") {
        currentResult += operand;
    } else if (currentOperation == "-") {
        currentResult -= operand;
    } else if (currentOperation == "*") {
        currentResult *= operand;
    } else if (currentOperation == "/") {
        if (operand != 0) {
            currentResult /= operand;
        } else {
            resultField->setText("Ошибка!");
            return;
        }
    }

    resultField->setText(QString::number(currentResult));
    currentOperation.clear();
    isNewOperation = true;
}

void Calculator::onClearButtonClicked()
{
    currentResult = 0.0;
    currentOperation.clear();
    isNewOperation = true;
    resultField->clear();
}
