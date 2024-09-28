#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator),
    currentResult(0.0),
    isNewOperation(true)
{
    ui->setupUi(this);

    // Подключаем кнопки к слотам
    connect(ui->button0, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button1, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button2, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button3, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button4, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button5, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button6, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button7, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button8, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);
    connect(ui->button9, &QPushButton::clicked, this, &Calculator::onNumberButtonClicked);

    connect(ui->buttonAdd, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(ui->buttonSubtract, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(ui->buttonMultiply, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(ui->buttonDivide, &QPushButton::clicked, this, &Calculator::onOperationButtonClicked);
    connect(ui->buttonEqual, &QPushButton::clicked, this, &Calculator::onEqualButtonClicked);
    connect(ui->buttonClear, &QPushButton::clicked, this, &Calculator::onClearButtonClicked);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::onNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonText = button->text();
        if (isNewOperation) {
            ui->resultField->setText(buttonText);
            isNewOperation = false;
        } else {
            ui->resultField->setText(ui->resultField->text() + buttonText);
        }
    }
}

void Calculator::onOperationButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        currentResult = ui->resultField->text().toDouble();
        currentOperation = button->text();
        isNewOperation = true;
    }
}

void Calculator::onEqualButtonClicked()
{
    double operand = ui->resultField->text().toDouble();
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
            ui->resultField->setText("Ошибка!");
            return;
        }
    }

    ui->resultField->setText(QString::number(currentResult));
    currentOperation.clear();
    isNewOperation = true;
}

void Calculator::onClearButtonClicked()
{
    currentResult = 0.0;
    currentOperation.clear();
    isNewOperation = true;
    ui->resultField->clear();
}
