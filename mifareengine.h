#ifndef MIFAREENGINE_H
#define MIFAREENGINE_H

#include "ODALID.h"
#include "mifareenginestatus.h" // Importe les codes de statut de l'application
#include "MfErrNo.h"
#include <QString>

#define DATA_LENGTH 48

class MifareEngine
{
private:
    ReaderName reader;

    unsigned char atq[2];
    unsigned char sak[1];
    unsigned char uid[12];
    unsigned char data[DATA_LENGTH];

    uint16_t uid_len = 12;
    int16_t status;

    int mifare_engine_status;

    // Keys
    unsigned char key_ff[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    unsigned char key_A[6]  = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
    unsigned char key_B[6]  = {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5};
    unsigned char key_C[6]  = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5};
    unsigned char key_D[6]  = {0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5};
    const bool auth_KeyA = true;
    const bool auth_KeyB = false;
    const bool auth_KeyC = true;
    const bool auth_KeyD = false;

    bool read_block(uint8_t block);
    bool write_block_str(QString value, uint8_t block);
    bool write_block_int(uint8_t value, uint8_t block);
    void reset_data();

    void done();
    void close();
    void tag_halt();

public:
    MifareEngine();
    ~MifareEngine();
    void init();
    bool enrol();

    int get_mifare_engine_status();

    bool read_cpt(QString& cpt_value);

    bool get_lastname(QString& lastname);
    bool get_firstname(QString& firstname);

    bool set_lastname(QString lastname);
    bool set_firstname(QString firstname);
    
    bool increment_cpt();
    bool decrement_cpt();
    bool format();
};

#endif // MIFAREENGINE_H
