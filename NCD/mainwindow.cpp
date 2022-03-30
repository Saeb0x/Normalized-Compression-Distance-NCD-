#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Normalized Compression Distance (NCD)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
// LZW compression method
std::vector<int> MainWindow::Encoding(std::string mString)
{
    std::unordered_map<std::string, int> table; // Key - Value container (dictionary)
        for (int i = 0; i < 256; i++)
        {
            std::string ch = "";
            ch += char(i);
            table[ch] = i; // ASCII table - 256 unique symbols
        }

        std::string p = "", c = "";

        p += mString[0]; // first character of string mString
        int code = 256;
        std::vector<int> output_code;

        // LZW
        for (int i = 0; i < mString.length(); i++)
        {
            if (i != mString.length() - 1)
            {
                c += mString[i + 1];
            }

            if (table.find(p + c) != table.end())
            {
                p = p + c;
            }
            else
            {
                output_code.push_back(table[p]);
                table[p + c] = code;
                code++;
                p = c;
            }

            c = "";
        }

        output_code.push_back(table[p]);
        return output_code;
}

// for decoding the encoded codes (compressed text) by LZW compression method
void MainWindow::Decoding(std::vector<int> OutputCodes)
{
    std::unordered_map<int, std::string> table;
        for (int i = 0; i <= 255; i++)
        {
            std::string ch = "";
            ch += char(i);
            table[i] = ch;
        }
        int old = OutputCodes[0], n;
        std::string s = table[old];
        std::string c = "";
        c += s[0];
        int count = 256;
        for (int i = 0; i < OutputCodes.size() - 1; i++)
        {
            n = OutputCodes[i + 1];
            if (table.find(n) == table.end())
            {
                s = table[old];
                s = s + c;
            }
            else
            {
                s = table[n];
            }
            c = "";
            c += s[0];
            table[count] = table[old] + c;
            count++;
            old = n;
        }
}

// Normalized Compression Distance
float MainWindow::NCD(std::string mString1, std::string mString2)
{
        std::string mString3 = mString1 + mString2;
        // Determine C(xy)-min{C(x),C(y)}
        long max_C;
        if (Encoding(mString1).size() > Encoding(mString2).size())
        {
            max_C = Encoding(mString3).size() - Encoding(mString2).size();
        }
        else
        {
            max_C = Encoding(mString3).size() - Encoding(mString1).size();
        }

        // Determine max{C(x), C(y)}
        long max_Cx_Cy;
        if (Encoding(mString1).size() > Encoding(mString2).size())
        {
            max_Cx_Cy = Encoding(mString1).size();
        }
        else
        {
            max_Cx_Cy = Encoding(mString2).size();
        }

        // NCD =  C(xy)-min{C(x),C(y)} / max{C(x), C(y)}
        float NCD = (float)max_C / (float)max_Cx_Cy;
        return NCD;
}

void MainWindow::on_actionCreator_triggered()
{
    QMessageBox::information(this, "Creator", "This program is developed by Saeb K. H. Naser");
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textBrowser->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser_2->setText("Suppose we have two string sequences X and Y, and the concatenated sequence XY, The similarity between these two strings is to be computed with the use of Normalized Compression Distance (NCD) where the LZW text compression method is used.NCD value ranges from 0 to 1. NCD(X, Y) = 0, indicate the string X and Y are similar.");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString string1 = ui->textEdit->toPlainText();
    QString string2 = ui->textEdit_2->toPlainText();
    QString NCDValues;
    NCDValues.setNum(NCD(string1.toStdString(), string2.toStdString()));
    ui->textBrowser->setText(NCDValues);
}

