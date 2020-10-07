#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


class User{
private:
    unsigned int age;
    QString name;
    static int total_count;
public:
    explicit User(QString name, int age=18){
        if(age>=18)
        {
            this->age=age;
        }
        else
        {
            this->age=18;
        }
        this->name=name;
        total_count++;
    }

    QString getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    static unsigned long getTotalCount(){
        return users.size();
    }

    static std::vector<User> users;

    void deleteUserByIndex(unsigned int indexOfDeletedUser) {
        if (indexOfDeletedUser > users.size()) {
            qDebug() << "Index of this user is more that our database can contain.";
            break;
        }
        else {
            users.erase(users.begin() + indexOfDeletedUser);
        }
    }

    void addUser(User newfag) {
        users.push_back(newfag);
    }

    void deleteUserByName(QString deletedName) {
        for (unsigned long i = 0; i < users.size(); i++) {
            if (users[i].getName() == deletedName) {
                users.erase(users.begin() + i);
                qDebug() << "Deleted successfully.";
            }
            else {
                qDebug() << "User had already been deleted - or just doesn't exist.";
            }
        }
    }

};

int User::total_count = 0;
std::vector<User> User::users;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    // ui->nameLineEdit->setText("Aufar");
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello "+ student.getName() + "!");
    // qDebug() << "Name:" << student.getName();
    // qDebug() << "Age:" << student.getAge();
    qDebug() << msg.exec();
    qDebug() << User::getTotalCount();
    User::users.push_back(student);
    //qDebug() << "Last student age:" << User::users_.end()->getAge();
    //qDebug() << "Last student name:" << User::users_.end()->getName();
    qDebug() << "Total count:" << User::users.size();
    qDebug() << "First student name ([0]):" << User::users[0].getName();
    qDebug() << "First student name (at):" << User::users.at(0).getName();
    qDebug() << "------------------------";
}
