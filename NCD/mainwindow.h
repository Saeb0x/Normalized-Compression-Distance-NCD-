#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <unordered_map>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::vector<int> Encoding(std::string mString);
    void Decoding(std::vector<int> OutputCodes);
    float NCD(std::string mString1, std::string mString2);
    ~MainWindow();

private slots:
    void on_actionCreator_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
