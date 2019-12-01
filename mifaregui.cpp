#include <QDebug>
#include <QString>

#include "mifaregui.h"
#include "ui_mifaregui.h"
#include "mifareenginestatus.h"

MifareGUI::MifareGUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::MifareGUI)
{
    ui->setupUi(this);
    mifare_engine = new MifareEngine();
}

MifareGUI::~MifareGUI()
{
    delete ui;
    delete mifare_engine;
}

void MifareGUI::refresh_ui_data()
{
    qDebug() << "Reading....";
    QString lastname = "Nom : ";
    QString firstname = "Prénom : ";
    QString cpt = "";

    bool lastname_read_success = mifare_engine->get_lastname(lastname);
    bool firstname_read_success = mifare_engine->get_firstname(firstname);
    bool cpt_read_success = mifare_engine->read_cpt(cpt);

    if(lastname_read_success)
        ui->LastnameLabel->setText(lastname);
    if(firstname_read_success)
        ui->FirstnameLabel->setText(firstname);
    if(cpt_read_success)
        ui->IncrementValueLabel->setText(cpt);
}

void MifareGUI::on_refreshButton_clicked()
{
    MifareGUI::refresh_ui_data();
}

void MifareGUI::on_connectButton_clicked()
{
    log("Connection...");
    mifare_engine->init();
    if(mifare_engine->get_mifare_engine_status() == MIFARE_ENG_CONNECTED_READY)
        log("Connected !");
    else
        log("Connection failed");
}

void MifareGUI::on_enrolButton_clicked()
{
    log("Enroling...");
    mifare_engine->enrol();
    if(mifare_engine->get_mifare_engine_status() == MIFARE_ENG_CONNECTED_READY)
        log("Enroled !");
    else
        log("Enroling failed");
}

void MifareGUI::on_writeButton_clicked()
{
    log("Writing data on the card");
    mifare_engine->set_firstname(ui->firstnameEdit->text());
    mifare_engine->set_lastname(ui->lastnameEdit->text());

    MifareGUI::refresh_ui_data();
}

void MifareGUI::on_incrementButton_clicked()
{
    log("Incrementing counter");
    mifare_engine->increment_cpt();

    MifareGUI::refresh_ui_data();
}

void MifareGUI::on_decrementButton_clicked()
{
    log("Decrementing counter");
    mifare_engine->decrement_cpt();

    MifareGUI::refresh_ui_data();
}

void MifareGUI::on_formatButton_clicked()
{
    log("Formating card");
    mifare_engine->format();
}

void MifareGUI::log(QString entry)
{
    ui->logTextEdit->append(entry);
}
