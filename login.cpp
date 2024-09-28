#include "login.h"
#include "ui_login.h"
#include "calculator.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::onLoginClicked);
}

Login::~Login()
{
    delete ui;
}

void Login::onLoginClicked()
{
    // Логика авторизации. Пример:
    if (ui->usernameField->text() == "admin" && ui->passwordField->text() == "password") {
        Calculator *calculatorWindow = new Calculator();
        calculatorWindow->show();
        this->close();  // Закрываем окно логина
    } else {
        // Ошибка авторизации
    }
}
