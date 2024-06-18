#include "menu_worker.c"

int clienteOperacoes(int input, Conta loggedAccount)
    {            
        if (input < 1 || input > 6) 
            {
                return 7;
            }

        fflush(stdin);
        
        switch(input)
            {
                case 1:
                    showBalance(loggedAccount);
                    clientMenuEndOpt();
                    break;
                case 2:
                    processDeposit(loggedAccount);
                    clientMenuEndOpt();
                    break;
                case 3:
                    processWithdrawal(loggedAccount);
                    clientMenuEndOpt();
                    break;
                case 4:
                    showStatement(loggedAccount);
                    clientMenuEndOpt();
                    break;
                case 5:
                    showLimit(loggedAccount);
                    clientMenuEndOpt();
                    break;
                case 6:
                    system("cls");
                    return 6;
            }
        fflush(stdin);
        return 0;
        
    }

void showBalance(Conta account)
    {
        if (isSavings(account))  printf("O saldo da conta eh de: %d\n", ContasPoupanca[findSavingAccount(account)].saldo);
        if (!isSavings(account)) printf("O saldo da conta eh de: %d\n", ContasCorrente[findCheckingAccount(account)].saldo);
    }

void processDeposit(Conta account)
    {
        FILE *rela = fopen("./src/sys/rela.txt", "a");

        double deposit;
        printf("Insira a quantidade a se depositar: ");
        scanf("%d", &deposit);

        if (deposit < 0)
            {
                printf("O valor do deposito nao pode ser negativo");

                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        if (isSavings(account))  ContasPoupanca[findSavingAccount(account)].saldo += deposit;
        if (!isSavings(account)) ContasCorrente[findCheckingAccount(account)].saldo += deposit;

        fprintf(rela, "%d - D - %d\n", account.pin, deposit);

        fclose(rela);
        saveChanges();
    }

void processWithdrawal(Conta account)
    {        

        char *senha;
        if (isSavings(account))  senha = ContasPoupanca[findSavingAccount(account)].senha;
        if (!isSavings(account)) senha = ContasCorrente[findCheckingAccount(account)].senha;

        double saldo;
        if (isSavings(account))  saldo = ContasPoupanca[findSavingAccount(account)].saldo;
        if (!isSavings(account)) saldo = ContasCorrente[findCheckingAccount(account)].saldo;

        char input[20];
        printf("Confirme sua senha para executar o saque: ");
        scanf("%s", &input);

        if (strcmp(input, senha) != 0)
            {
                printf("Uhh, a senha nao estava correta!\n\n");
                return;
            }

        double withdrawal;
        printf("Insira a quantidade a se sacar: ");
        scanf("%d", &withdrawal);

        if (withdrawal < 0)
            {
                printf("O valor do saque nao pode ser negativo");

                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        if (withdrawal > saldo)
            {
                printf("O valor do saque tem que ser menor que o saldo da conta");

                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        if (isSavings(account))  ContasPoupanca[findSavingAccount(account)].saldo -= withdrawal;
        if (!isSavings(account)) ContasCorrente[findCheckingAccount(account)].saldo -= withdrawal;

        FILE *rela = fopen("./src/sys/rela.txt", "a");
        fprintf(rela, "%d - S - %d\n", account.pin, withdrawal);

        fclose(rela);
        
        saveChanges();
    }

void showStatement(Conta account)
    {
        FILE *file_rela = fopen("./src/sys/rela.txt", "r");
        FILE *file = fopen("./src/sys/extrato.csv","w");

        int i_transac = 0;
        while(fscanf(file_rela, "%d - %c - %d\n",
            &extrato[i_transac].account, 
            &extrato[i_transac].type,
            &extrato[i_transac].amount) == 3)
            {
                i_transac++;
            }

        if (i_transac == 0)
            {
                printf("Nao existem transacoes registradas no sistema!\n\n");
                fclose(file_rela);
                return;
            }

        int accTransacs = 0;
        for (int i = 0; i < i_transac; i++)
            {
                if (account.pin != extrato[i].account) continue;
                fprintf(file, "Conta: %d;%s: %d\n",
                (extrato[i].account),
                ((extrato[i].type == 'D') ? ("Deposito") : ("Saque")), extrato[i].amount);
                accTransacs++;
            }

        if (accTransacs > 0)
            {
                system("start excel ./src/sys/extrato.csv");
            }
        else
            {
                printf("Parece que nao tem transacoes registradas sobre essa conta");
            }

        fclose(file);
        fclose(file_rela);
    }

void showLimit(Conta account)
    {
        if(isSavings(account))
            {
                printf("uhh, contas poupanca nao possuem um limite.\n");
                return;
            }

        printf("O limite da sua conta eh de: %d\n",ContasCorrente[findCheckingAccount(account)].limite);
    }

void clientMenuEndOpt()
    {
        printf("Operacao finalizada!\nPressione Enter para continuar.");
        fflush(stdin);
        while(getchar() != '\n');
        system("cls");
    }