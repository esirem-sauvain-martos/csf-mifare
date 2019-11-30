#include <QDebug>
#include <cstdlib>
#include <ctime>

#include "mifareengine.h"

MifareEngine::MifareEngine()
{
    // Preparation des buffers
    for(int i = 0; i < DATA_LENGTH; i++)
        data[i] = 0x00;
    for(int i = 0; i < 12; i++)
        uid[i] = 0x00;
    for(int i = 0; i < 2; i++)
        atq[i] = 0x00;
    sak[0] = 0x00;

    reader.Type = ReaderCDC;
    reader.device = 0;
    mifare_engine_status = MIFARE_ENG_INIT_READY;

    // Initialisation de la connexion
    init();
    qDebug() << "Init Done";
}

void MifareEngine::init()
{
    status = OpenCOM1(&reader);
    if (status != MI_OK)
    {
        qDebug("Reader not found");
        mifare_engine_status = MIFARE_ENG_NO_READER;
        done();
    }
    else // Lecteur OK
    {
        // Loading keys
        // Key A
        status = Mf_Classic_LoadKey(&reader, auth_KeyA, key_A, 0);
        if (status != MI_OK)
        {
            qDebug() << "Key A load failed";
            mifare_engine_status = MIFARE_ENG_KEY_LOADING_FAIL;
            close();
            return;
        }

        // Key B
        status = Mf_Classic_LoadKey(&reader, auth_KeyB, key_B, 0);
        if (status != MI_OK)
        {
            qDebug() << "Key B load failed";
            mifare_engine_status = MIFARE_ENG_KEY_LOADING_FAIL;
            close();
            return;
        }

        // Key C
        status = Mf_Classic_LoadKey(&reader, auth_KeyC, key_C, 1);
        if (status != MI_OK)
        {
            qDebug() << "Key C load failed";
            mifare_engine_status = MIFARE_ENG_KEY_LOADING_FAIL;
            close();
            return;
        }

        // Key D
        status = Mf_Classic_LoadKey(&reader, auth_KeyD, key_D, 1);
        if (status != MI_OK)
        {
            qDebug() << "Key D load failed";
            mifare_engine_status = MIFARE_ENG_KEY_LOADING_FAIL;
            close();
            return;
        }

        // Alimentation
        RF_Power_Control(&reader, true, 0);
        mifare_engine_status = MIFARE_ENG_POWERED;

        // Detection du tag
        status = ISO14443_3_A_PollCard(&reader, atq, sak, uid, &uid_len);
        if (status != MI_OK)
        {
            qDebug() << "No tag";
            mifare_engine_status = MIFARE_ENG_NO_TAG;
            close();
            return;
        }
        qDebug() << "Tag found: UID = " << uid;
        mifare_engine_status = MIFARE_ENG_READY;

        if ((atq[1] != 0x00) || ((atq[0] != 0x02) && (atq[0] != 0x04) && (atq[0] != 0x18)))
        {
            qDebug() << "This is not a Mifare classic tag";
            mifare_engine_status = MIFARE_ENG_INVALID_MIFARE;
            tag_halt();
        }
        else
        {
            if ((sak[0] & 0x1F) == 0x08)
            {
                qDebug() << "Tag appears to be a Mifare classic 1k";
            }
            else if ((sak[0] & 0x1F) == 0x18)
            {
                qDebug() << "Tag appears to be a Mifare classic 4k";
            }
            mifare_engine_status = MIFARE_ENG_CONNECTED_READY;

            // Ecriture des noms des applications dans les blocs appropiés
            QString application_name = "Identite";
            write_block_str(application_name, 8);
            application_name = "Porte Monnaie";
            write_block_str(application_name, 12);
        }
    }
}

void MifareEngine::tag_halt()
{
    status = ISO14443_3_A_Halt(&reader);
    if (status != MI_OK)
    {
        qDebug() << "Failed to halt the tag";
        mifare_engine_status = MIFARE_ENG_ERROR;
        done();
    }
    else
    {
        mifare_engine_status = MIFARE_ENG_HALT;
    }
}

void MifareEngine::done()
{
    if (status == MI_OK)
        qDebug() << "Done";
    else
        qDebug("%s (%d)", GetErrorMessage(status), status);
}

void MifareEngine::close()
{
    RF_Power_Control(&reader, false, 0);
    CloseCOM1(&reader);
    mifare_engine_status = MIFARE_ENG_DISCONNECTED;
}

void MifareEngine::reset_data()
{
    for(int i = 0; i < DATA_LENGTH; i++)
        data[i] = 0x00;
}

bool MifareEngine::read_block(uint8_t block)
{
    /*
        Permet de lire le bloc de la carte en paramètre
    */

    bool result_status = false;

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        reset_data();

        status = Mf_Classic_Read_Block(&reader, true, block, data, auth_KeyA, 0);
        if(status == MI_OK)
        {
            qDebug("[READ] = %s", data);
            result_status = true;
        }
        else
        {
            qDebug() << "[READ] Fail, status = " << status;
        }
    }
    else
    {
        qDebug() << "[READ] Tag not connected";
    }

    return result_status;
}

bool MifareEngine::write_block_str(QString value, uint8_t block)
{
    /*
        Permet d'ecrire sur le bloc de la carte en paramètre
    */

    bool result_status = false;

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        QByteArray temp_buffer_array = value.toUtf8();
        unsigned char* temp_buffer_char = reinterpret_cast<unsigned char *>(temp_buffer_array.data());
        for(int i = 0; i < value.size(); i++)
        {
            data[i] = *temp_buffer_char;
            temp_buffer_char++;
        }

        status = Mf_Classic_Write_Block(&reader, true, block, data, auth_KeyB, 0);

        if(status == MI_OK)
        {
            qDebug("[WRITE] = %s", data);
            result_status = true;
        }
        else
            qDebug() << "[WRITE] Fail, status = " << status;

        reset_data();
    }
    else
    {
        qDebug() << "[WRITE] Tag not connected";
    }

    return result_status;
}

bool MifareEngine::get_firstname(QString& firstname)
{
    /*
        Retourne le prenom stocké dans la carte
    */

    bool read_success = read_block(9);
    if(read_success)
    {
        int i = 0;
        while(data[i] && i < DATA_LENGTH)
        {
            firstname.append(QChar(data[i++]));
        }
    }

    return read_success;
}

bool MifareEngine::get_lastname(QString& lastname)
{
    /*
        Retourne le nom stocké dans la carte
    */

    bool read_success = read_block(10);
    if(read_success)
    {
        int i = 0;
        while(data[i] && i < DATA_LENGTH)
        {
            lastname.append(QChar(data[i++]));
        }
    }

    return read_success;
}

bool MifareEngine::set_firstname(QString firstname)
{
    /*
        Ecrit le prenom dans la carte
    */

    return write_block_str(firstname, 9);
}

bool MifareEngine::set_lastname(QString lastname)
{
    /*
        Ecrit le nom dans la carte
    */

   return write_block_str(lastname, 10);
}

bool MifareEngine::read_cpt(QString& cpt_value)
{
    /*
        Lit la valeur du compteur
    */

    bool read_success = false;

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        uint32_t val;
        Mf_Classic_Read_Value(&reader, true, 14, &val, auth_KeyD, 1);

        cpt_value = QString::number(val);
        read_success = true;
    }

    return read_success;
}

bool MifareEngine::increment_cpt()
{
    /*
        Incremente le compteur
    */

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        Mf_Classic_Increment_Value(&reader, true, 14, 1, 13, auth_KeyD, 1);
        Mf_Classic_Restore_Value(&reader, true, 13, 14, auth_KeyD, 1);
    }

    return mifare_engine_status == MIFARE_ENG_CONNECTED_READY;
}

bool MifareEngine::decrement_cpt()
{
    /*
        Decremente le compteur
    */

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        Mf_Classic_Decrement_Value(&reader, true, 14, 1, 13, auth_KeyD, 1);
        Mf_Classic_Restore_Value(&reader, true, 13, 14, auth_KeyD, 1);
    }

    return mifare_engine_status == MIFARE_ENG_CONNECTED_READY;
}

bool MifareEngine::format()
{
    /*
        Remet la carte dans son état d'origine
    */

    bool res = false;

    if(mifare_engine_status == MIFARE_ENG_CONNECTED_READY)
    {
        res = true;

        QString blank = "";
        uint8_t index_to_clear[] = {8, 9, 10, 12, 13, 14};
        for(int i = 0; i < 6; i++)
        {
            res = res && write_block_str(blank, index_to_clear[i]);
        }
    }

    return  res;
}

int MifareEngine::get_mifare_engine_status()
{
    return mifare_engine_status;
}
