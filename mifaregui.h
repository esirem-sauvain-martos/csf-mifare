#ifndef MIFAREGUI_H
#define MIFAREGUI_H

#include <QMainWindow>
#include <mifareengine.h>

namespace Ui {
class MifareGUI;
}

class MifareGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MifareGUI(QWidget *parent = nullptr);
    ~MifareGUI();

private:
    Ui::MifareGUI *ui;
    MifareEngine *mifare_engine;

    void refresh_ui_data();
    void log(QString entry);

private slots:
    void on_refreshButton_clicked();
    void on_enrolButton_clicked();
    void on_writeButton_clicked();
    void on_incrementButton_clicked();
    void on_decrementButton_clicked();
    void on_formatButton_clicked();
};

#endif // MIFAREGUI_H
