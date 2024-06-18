#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "conta.h"

typedef int bool;
#define true 1;
#define false 0;

#define LIM 100

Transacao extrato[LIM];

ContaCorrente ContasCorrente[LIM];
ContaPoupanca ContasPoupanca[LIM];

Funcionario ContasFuncionario[LIM];
Funcionario ADM;

int savingsAccAmount = 0;
int checkingsAccAmount = 0;
int workerAccAmount = 0;

//MENU PRINCIPAL
void mainMenu();
int getMainMenuInput();
void processMainMenuInput(int input);

//MENU FUNCIONARIO
void menuFuncionario();
int getFuncionarioMenuInput();
void processFuncionarioMenuInput(int input);

void createAccount();
void deleteAccount();
void viewAccounts();
void changeAccounts();
void cadastrarWorker();
void gerarRelatorio();

//MENU CLIENTE
void menuCliente();
int getClientMenuInput();
void processClientMenuInput(int input, Conta account);


void showBalance(Conta account);
void processDeposit(Conta account);
void processWithdrawal(Conta account);
void showStatement(Conta account);
void showLimit(Conta account);
void clientMenuEndOpt();


//TELA DE FECHAMENTO
void closingScreen();
void setFullScreen();
void EESecret();