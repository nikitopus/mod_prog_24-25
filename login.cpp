#include "login.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "calculator.h"

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    // Создаем виджеты динамическиbbb
    QLabel *usernameLabel = new QLabel("Username:");
    QLabel *passwordLabel = new QLabel("Password:");
    usernameField = new QLineEdit;
    passwordField = new QLineEdit;
    passwordField->setEchoMode(QLineEdit::Password);  // Маскируем ввод пароля
    errorLabel = new QLabel;
    loginButton = new QPushButton("Login");

    // Настраиваем макет формы
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(usernameLabel, usernameField);
    formLayout->addRow(passwordLabel, passwordField);

    // Макет для кнопки входа
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(loginButton);

    // Основной макет
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(errorLabel);
    mainLayout->addLayout(buttonLayout);

    // Применяем макет к окну
    setLayout(mainLayout);

    // Связываем кнопку с обработчиком
    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginClicked);
}

Login::~Login()
{
    // Здесь не нужно удалять объекты вручную, так как Qt сделает это автоматически
}

void Login::onLoginClicked()
{
    // Простая проверка авторизации
    if (usernameField->text() == "admin" && passwordField->text() == "password") {
        Calculator *calculatorWindow = new Calculator();
        calculatorWindow->show();
        this->close();  // Закрываем окно логина
    } else {
        // Показ сообщения об ошибке
        errorLabel->setText("Неверный логин или пароль!");
    }
}
