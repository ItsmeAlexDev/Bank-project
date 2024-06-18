#ifndef WORKER_H
#define WORKER_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int pin;
    char cargo[25];
    char nome[99];
    char cpf[15];
    Data Nascimento;
    char telefone[20];
    char endereco[99];
    char cep[10];
    char local[99];
    char numeroCasa[5];
    char bairro[99];
    char cidade[99];
    char estado[50];
    char senha[10];
    int isAdm;
} Funcionario;

#endif