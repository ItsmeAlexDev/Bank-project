#ifndef CONTA_H
#define CONTA_H

#include "worker.h"

typedef struct {
    int pin;
    char senha[20];
    int isSavings;
} Conta;

typedef struct {
    int account;
    char type;
    int amount;
} Transacao;

typedef struct {
    char agency[25];
    int pin;
    char clientName[99];
    char clientCPF[11];
    Data clientNascimento;
    char clientPhoneNumber[9];
    char clientEndereco[99];
    char clientCEP[8];
    char clientLocal[99];
    char clientHouseNumber[5];
    char clientBairro[99];
    char clientCity[99];
    char clientState[99];
    char senha[20];
    double saldo;
} ContaPoupanca;

typedef struct {
    char agency[25];
    int pin;
    double limite;
    Data vencimento;
    char clientName[99];
    char clientCPF[11];
    Data clientNascimento;
    char clientPhoneNumber[9];
    char clientEndereco[99];
    char clientCEP[8];
    char clientLocal[99];
    char clientHouseNumber[5];
    char clientBairro[99];
    char clientCity[99];
    char clientState[99];
    char senha[20];
    double saldo;
} ContaCorrente;

#endif