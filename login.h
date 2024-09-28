#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

class QLineEdit;
class QLabel;
class QPushButton;

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void onLoginClicked();  // Слот для обработки нажатия кнопки

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QLabel *errorLabel;
    QPushButton *loginButton;
};

#endif // LOGIN_H
