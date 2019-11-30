#ifndef MIFAREENGINESTATUS_H
#define MIFAREENGINESTATUS_H

// Code de statuts
#define MIFARE_ENG_DISCONNECTED    0
#define MIFARE_ENG_INIT_READY      1
#define MIFARE_ENG_POWERED         2
#define MIFARE_ENG_VALID_MIFARE    3
#define MIFARE_ENG_READY           4
#define MIFARE_ENG_CONNECTED_READY 5
#define MIFARE_ENG_HALT            6

// Code d'erreurs
#define MIFARE_ENG_NO_READER        -1
#define MIFARE_ENG_NO_TAG           -2
#define MIFARE_ENG_KEY_LOADING_FAIL -3
#define MIFARE_ENG_INVALID_MIFARE   -4
#define MIFARE_ENG_ERROR            -10

#endif // MIFAREENGINESTATUS_H
