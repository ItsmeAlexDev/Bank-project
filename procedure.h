#include "lib.h"

char* concat(const char *a, const char *b)
    {
        size_t length = strlen(a) + strlen(b) + 1;

        char *result = (char*)malloc(length);

        strcpy(result, a);
        strcat(result, b);

        return result;
    }

void printTxtFile(const char *foldername, const char *filename)
    {   
        foldername = concat("./src/", foldername);
        foldername = concat(foldername, "/");
        filename = concat(filename, ".txt");
        FILE *file;
        char ch;
        file = fopen(concat(foldername, concat("/", filename)), "r");
        while ((ch = fgetc(file)) != EOF) printf("%c", ch);
        fclose(file);
    }

void setFullscreen()
    {
        ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    }

void loadAccounts()
    {
        FILE *file_s = fopen("./src/sys/cp.txt", "r");
        FILE *file_c = fopen("./src/sys/cc.txt", "r");
        
        int i_poup = 0;
        while(fscanf(file_s, "agencia: %s\npin: %d\nnome do cliente: %[^\n]\nCPF do cliente: %[^\n]\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %[^\n]\nendereco do cliente: %[^\n]\nCEP: %[^\n]\nlocal: %[^\n]\nnumero da casa: %[^\n]\nbairro: %[^\n]\ncidade: %[^\n]\nestado: %[^\n]\nsenha: %[^\n]\nsaldo: %d\n\n",
                ContasPoupanca[i_poup].agency,
                &ContasPoupanca[i_poup].pin,
                ContasPoupanca[i_poup].clientName,
                ContasPoupanca[i_poup].clientCPF,
                &ContasPoupanca[i_poup].clientNascimento.dia,
                &ContasPoupanca[i_poup].clientNascimento.mes,
                &ContasPoupanca[i_poup].clientNascimento.ano,
                ContasPoupanca[i_poup].clientPhoneNumber,
                ContasPoupanca[i_poup].clientEndereco,
                ContasPoupanca[i_poup].clientCEP,
                ContasPoupanca[i_poup].clientLocal,
                ContasPoupanca[i_poup].clientHouseNumber,
                ContasPoupanca[i_poup].clientBairro,
                ContasPoupanca[i_poup].clientCity,
                ContasPoupanca[i_poup].clientState,
                ContasPoupanca[i_poup].senha,
                &ContasPoupanca[i_poup].saldo) == 16) i_poup++;
        savingsAccAmount = i_poup;

        int i_corr = 0;
        while(fscanf(file_c, "agencia: %[^\n]\npin %d\nlimite: %d\ndata do vencimento: %d/%d/%d\nnome do cliente: %[^\n]\nCPF do cliente: %[^\n]\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %[^\n]\nendereco do cliente: %[^\n]\nCEP: %[^\n]\nlocal: %[^\n]\nnumero da casa: %[^\n]\nbairro: %[^\n]\ncidade: %[^\n]\nestado: %[^\n]\nsenha: %[^\n]\nsaldo: %d\n\n",
                ContasCorrente[i_corr].agency,
                &ContasCorrente[i_corr].pin,
                &ContasCorrente[i_corr].limite,
                &ContasCorrente[i_corr].vencimento.dia,
                &ContasCorrente[i_corr].vencimento.mes,
                &ContasCorrente[i_corr].vencimento.ano,
                ContasCorrente[i_corr].clientName,
                ContasCorrente[i_corr].clientCPF,
                &ContasCorrente[i_corr].clientNascimento.dia,
                &ContasCorrente[i_corr].clientNascimento.mes,
                &ContasCorrente[i_corr].clientNascimento.ano,
                ContasCorrente[i_corr].clientPhoneNumber,
                ContasCorrente[i_corr].clientEndereco,
                ContasCorrente[i_corr].clientCEP,
                ContasCorrente[i_corr].clientLocal,
                ContasCorrente[i_corr].clientHouseNumber,
                ContasCorrente[i_corr].clientBairro,
                ContasCorrente[i_corr].clientCity,
                ContasCorrente[i_corr].clientState,
                ContasCorrente[i_corr].senha,
                &ContasCorrente[i_corr].saldo) == 21) i_corr++;
        checkingsAccAmount = i_corr;

        fclose(file_s);
        fclose(file_c);
    }

void saveChanges()
    {
        FILE *file_s = fopen("./src/sys/cp.txt", "w");
        FILE *file_c = fopen("./src/sys/cc.txt", "w");


        for (int i = 0; i <= savingsAccAmount; i++)
            {   
                fprintf(file_s, "agencia: %s\npin: %d\nnome do cliente: %s\nCPF do cliente: %s\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %s\nendereco do cliente: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\nsenha: %s\nsaldo: %d\n\n",
                ContasPoupanca[i].agency,
                ContasPoupanca[i].pin,
                ContasPoupanca[i].clientName,
                ContasPoupanca[i].clientCPF,
                ContasPoupanca[i].clientNascimento.dia,
                ContasPoupanca[i].clientNascimento.mes,
                ContasPoupanca[i].clientNascimento.ano,
                ContasPoupanca[i].clientPhoneNumber,
                ContasPoupanca[i].clientEndereco,
                ContasPoupanca[i].clientCEP,
                ContasPoupanca[i].clientLocal,
                ContasPoupanca[i].clientHouseNumber,
                ContasPoupanca[i].clientBairro,
                ContasPoupanca[i].clientCity,
                ContasPoupanca[i].clientState,
                ContasPoupanca[i].senha,
                ContasPoupanca[i].saldo);
            }

        for(int i = 0; i < checkingsAccAmount; i++)
            {
                fprintf(file_c, "agencia: %s\npin %d\nlimite: %d\ndata do vencimento: %d/%d/%d\nnome do cliente: %s\nCPF do cliente: %s\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %s\nendereco do cliente: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\nsenha: %s\nsaldo: %d\n\n",
                ContasCorrente[i].agency,
                ContasCorrente[i].pin,
                ContasCorrente[i].limite,
                ContasCorrente[i].vencimento.dia,
                ContasCorrente[i].vencimento.mes,
                ContasCorrente[i].vencimento.ano,
                ContasCorrente[i].clientName,
                ContasCorrente[i].clientCPF,
                ContasCorrente[i].clientNascimento.dia,
                ContasCorrente[i].clientNascimento.mes,
                ContasCorrente[i].clientNascimento.ano,
                ContasCorrente[i].clientPhoneNumber,
                ContasCorrente[i].clientEndereco,
                ContasCorrente[i].clientCEP,
                ContasCorrente[i].clientLocal,
                ContasCorrente[i].clientHouseNumber,
                ContasCorrente[i].clientBairro,
                ContasCorrente[i].clientCity,
                ContasCorrente[i].clientState,
                ContasCorrente[i].senha,
                ContasCorrente[i].saldo);
            }

        fclose(file_s);
        fclose(file_c);
    }

void saveWorkers()
    {
        FILE *workers = fopen("./src/sys/wc.txt", "w");
        
        for (int i = 0; i < 100; i++)
            {
                if (ContasFuncionario[i].pin == 0) continue;
                fprintf(workers, "pin: %d\ncargo: %s\nnome: %s\nCPF: %s\nnascimento: %d/%d/%d\ntelefone: %s\nendereco: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\nsenha: %s\n\n",
                            ContasFuncionario[i].pin,
                            ContasFuncionario[i].cargo,
                            ContasFuncionario[i].nome,
                            ContasFuncionario[i].cpf,
                            ContasFuncionario[i].Nascimento.dia,
                            ContasFuncionario[i].Nascimento.mes,
                            ContasFuncionario[i].Nascimento.ano,
                            ContasFuncionario[i].telefone,
                            ContasFuncionario[i].endereco,
                            ContasFuncionario[i].cep,
                            ContasFuncionario[i].local,
                            ContasFuncionario[i].numeroCasa,
                            ContasFuncionario[i].bairro,
                            ContasFuncionario[i].cidade,
                            ContasFuncionario[i].estado,
                            ContasFuncionario[i].senha);
            }
        
        fclose(workers);
    }    

Conta clientLogin() 
    {
        loadAccounts();
        
        Conta loginAccount;
        printf("Insira o pin da sua conta: ");
        scanf("%d", &loginAccount.pin);
        printf("\nInsira a senha da sua conta: ");
        scanf("%s", &loginAccount.senha);
        system("cls");

        for (int i = 0; i < LIM; i++)
                if(loginAccount.pin == ContasPoupanca[i].pin && (strcmp(loginAccount.senha, ContasPoupanca[i].senha) == 0))
                    {   
                        loginAccount.isSavings = 1;
                        return loginAccount;
                    }

        for (int i = 0; i < LIM; i++)
                if(loginAccount.pin == ContasCorrente[i].pin && (strcmp(loginAccount.senha, ContasCorrente[i].senha) == 0))
                    {
                        return loginAccount;
                    }

        loginAccount.pin = -1;

        return loginAccount;
    }

int findSavingAccount(Conta account)
    {
        for (int i = 0; i < LIM; i++)
            if(account.pin == ContasPoupanca[i].pin)
                return i;
    }

int findCheckingAccount(Conta account)
    {
        for (int i = 0; i < LIM; i++)
            if(account.pin == ContasCorrente[i].pin)
                return i;
    }

bool isSavings(Conta account)
    {
        return (account.isSavings == 1);
    }

void loadInternalInfo()
    {
        FILE *adm =     fopen("./src/sys/adminfo.txt", "r");
        FILE *workers = fopen("./src/sys/wc.txt", "r");
        
        int i = 0;
        while(fscanf(workers, "pin: %d\ncargo: %[^\n]\nnome: %[^\n]\nCPF: %[^\n]\nnascimento: %d/%d/%d\ntelefone: %[^\n]\nendereco: %[^\n]\nCEP: %[^\n]\nlocal: %[^\n]\nnumero da casa: %[^\n]\nbairro: %[^\n]\ncidade: %[^\n]\nestado: %[^\n]\nsenha: %[^\n]\n\n",
              &ContasFuncionario[i].pin,
              ContasFuncionario[i].cargo,
              ContasFuncionario[i].nome,
              ContasFuncionario[i].cpf,
              &ContasFuncionario[i].Nascimento.dia,
              &ContasFuncionario[i].Nascimento.mes,
              &ContasFuncionario[i].Nascimento.ano,
              ContasFuncionario[i].telefone,
              ContasFuncionario[i].endereco,
              ContasFuncionario[i].cep,
              ContasFuncionario[i].local,
              ContasFuncionario[i].numeroCasa,
              ContasFuncionario[i].bairro,
              ContasFuncionario[i].cidade,
              ContasFuncionario[i].estado,
              ContasFuncionario[i].senha) == 16)
              {
                ContasFuncionario[i].isAdm = 0;
                i++;
              }
        workerAccAmount = i;

        while(fscanf(adm, "pin: %d\nsenha: %s",
              &ADM.pin,
              &ADM.senha) == 2)
            {
                ADM.isAdm = 1;
            }

        fclose(adm);
        fclose(workers);
    }

Funcionario getADM()
    {
        loadInternalInfo();
        return ADM;
    }

Funcionario funcionarioLogin() 
    {
        loadInternalInfo();
        
        Funcionario loginAccount;
        printf("Insira o seu pin: ");
        scanf("%d", &loginAccount.pin);
        printf("\nInsira a sua senha: ");
        scanf("%s", &loginAccount.senha);
        system("cls");

        if(loginAccount.pin == ADM.pin &&
        (strcmp(loginAccount.senha, ADM.senha) == 0))
            {
                return loginAccount;
            }

        for (int i = 0; i < LIM; i++)
                if(loginAccount.pin == ContasFuncionario[i].pin &&
                (strcmp(loginAccount.senha, ContasFuncionario[i].senha) == 0))
                    {   
                        return loginAccount;
                    }

        loginAccount.pin = -1;
        return loginAccount;
    }

int getWorkerInput(const char *filepath)
    {
        int input;
        bool validInput = false;
        
        while (!validInput)
            {
                printTxtFile(filepath, "options");
                if (scanf("%d", &input) == 1)
                    {
                        return input;
                    }
                else
                    {
                        while (getchar() != '\n');
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("Houve um erro processando o input. Por Favor, tente novamente.");
                    }
            }

        return input;
    }

void putSavingAccountArray(ContaPoupanca account)
    {
        if (account.pin == -1) return;
        loadAccounts();
        for(int i = 0; i < 100;i++)
            if(account.pin == ContasPoupanca[i].pin)
                {
                    printf("a conta nao pode ser criada, ja que o pin ja estava em uso, tente novamente");
                    return;
                }
        savingsAccAmount++;
        ContasPoupanca[savingsAccAmount] = account;
        saveChanges();
    }

void createSavingAccount()
    {
        Data newDate = {
            .dia = 0,
            .mes = 0,
            .ano = 0
            };
        ContaPoupanca newAccount = {
            .agency = "N/A",
            .pin = -1,
            .clientName = "N/A",
            .clientCPF = "N/A",
            .clientNascimento = newDate,
            .clientPhoneNumber = "N/A",
            .clientEndereco = "N/A",
            .clientCEP = "N/A",
            .clientLocal = "N/A",
            .clientHouseNumber = "N/A",
            .clientBairro = "N/A",
            .clientCity = "N/A",
            .clientState = "N/A",
            .senha = "N/A",
            .saldo = 0
        };

        int input;

        do 
            {
                int input = getWorkerInput("wm/ca/cp");
                
                if (input == 0) break;

                if (input < 0 || input > 14)
                    {
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (0 - 14).");
                        continue;
                    }
                    
                switch(input)
                    {
                        case 1:
                            printf("Digite a agencia da conta: \n");
                            scanf("%s", newAccount.agency);

                            break;
                        case 2:
                            printf("Digite o numero da conta: \n");
                            scanf("%d", &newAccount.pin);

                            break;
                        case 3:
                            printf("Digite o nome do Cliente: \n");
                            scanf("%s", newAccount.clientName);
                            
                            break;
                        case 4:
                            printf("Digite o CPF do cliente: \n");
                            scanf("%s", newAccount.clientCPF);
                            
                            break;
                        case 5:
                            printf("Digite a data de nascimento do cliente: (dd mm aaaa)");
                            scanf("%d %d %d",
                            &newAccount.clientNascimento.dia,
                            &newAccount.clientNascimento.mes,
                            &newAccount.clientNascimento.ano);
                            
                            break;
                        case 6:
                            printf("Digite o telefone de contato: ");
                            scanf("%s", newAccount.clientPhoneNumber);

                            break;
                        case 7:
                            printf("Digite o endereco: ");
                            scanf("%s", newAccount.clientEndereco);
                            
                            break;
                        case 8:
                            printf("Digite o CEP: ");
                            scanf("%s", newAccount.clientCEP);

                            break;
                        case 9:
                            printf("Digite o Local: ");
                            scanf("%s", newAccount.clientLocal);

                            break;
                        case 10:
                            printf("Digite o numero da casa: ");
                            scanf("%s", newAccount.clientHouseNumber);

                            break;
                        case 11:
                            printf("Digite o Bairro: ");
                            scanf("%s", newAccount.clientBairro);

                            break;
                        case 12:
                            printf("Digite a cidade: ");
                            scanf("%s", newAccount.clientCity);

                            break;
                        case 13:
                            printf("Digite o estado: ");
                            scanf("%s", newAccount.clientState);

                            break;
                        case 14:
                            printf("Digite o senha: ");
                            scanf("%s", &newAccount.senha);

                            break;

                        case 0:
                            break;
                    }

                system("cls");
            }
        while(input != 0);

        putSavingAccountArray(newAccount);
    }

void putCheckingAccountArray(ContaCorrente account)
    {
        if (account.pin == -1) return;
        loadAccounts();
        for(int i = 0; i < 100;i++)
            if(account.pin == ContasCorrente[i].pin)
                {
                    printf("a conta nao pode ser criada, ja que o pin ja estava em uso, tente novamente");
                    return;
                }
        checkingsAccAmount++;
        ContasCorrente[checkingsAccAmount] = account;
        saveChanges();
    }

void createCheckingAccount()
    {
        Data newDate = {
            .dia = 0,
            .mes = 0,
            .ano = 0
        };

        ContaCorrente newAccount = {
            .agency = "N/A",
            .pin = -1,
            .limite = 0,
            .vencimento = newDate,
            .clientName = "N/A",
            .clientCPF = "N/A",
            .clientNascimento = newDate,
            .clientPhoneNumber = "N/A",
            .clientEndereco = "N/A",
            .clientCEP = "N/A",
            .clientLocal = "N/A",
            .clientHouseNumber = "N/A",
            .clientBairro = "N/A",
            .clientCity = "N/A",
            .clientState = "N/A",
            .senha = 0,
            .saldo = 0
        };

        int input;

        do 
            {
                int input = getWorkerInput("wm/ca/cc");
                
                if (input == 0) break;

                if (input < 0 || input > 16)
                    {
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (0 - 16).");
                        continue;
                    }
                    
                switch(input)
                    {
                        case 1:
                            printf("Digite a agencia da conta: \n");
                            scanf("%s", newAccount.agency);

                            break;
                        case 2:
                            printf("Digite o numero da conta");
                            scanf("%d", &newAccount.pin);

                            break;
                        case 3:
                            printf("Digite o limite da conta");
                            scanf("%d", &newAccount.limite);

                            break;
                        case 4:
                            printf("Digite a data de vencimento: (dd mm aaaa)");
                            scanf("%d %d %d",
                            &newAccount.vencimento.dia,
                            &newAccount.vencimento.mes,
                            &newAccount.vencimento.ano);

                            break;
                        case 5:
                            printf("Digite o nome do cliente: ");
                            scanf("%s", newAccount.clientName);

                            break;
                        case 6:
                            printf("Digite o CPF do cliente: ");
                            scanf("%s", newAccount.clientCPF);
                        
                            break;
                        case 7:
                            printf("Digite a data de nascimento do cliente: (dd mm aaaa)");
                            scanf("%d %d %d",
                            &newAccount.clientNascimento.dia,
                            &newAccount.clientNascimento.mes,
                            &newAccount.clientNascimento.ano);

                            break;
                        case 8:
                            printf("Digite o numero do cliente");
                            scanf("%s", newAccount.clientPhoneNumber);
                            break;
                        case 9:
                            printf("Digite o endereco: ");
                            scanf("%s", newAccount.clientEndereco);
                            
                            break;
                        case 10:
                            printf("Digite o CEP: ");
                            scanf("%s", newAccount.clientCEP);

                            break;
                        case 11:
                            printf("Digite o Local: ");
                            scanf("%s", newAccount.clientLocal);

                            break;
                        case 12:
                            printf("Digite o numero da casa: ");
                            scanf("%s", newAccount.clientHouseNumber);

                            break;
                        case 13:
                            printf("Digite o Bairro: ");
                            scanf("%s", newAccount.clientBairro);

                            break;
                        case 14:
                            printf("Digite a cidade: ");
                            scanf("%s", newAccount.clientCity);

                            break;
                        case 15:
                            printf("Digite o estado: ");
                            scanf("%s", newAccount.clientState);

                            break;
                        case 16:
                            printf("Digite o senha: ");
                            scanf("%s", newAccount.senha);

                            break;


                        case 0:
                            break;
                    }

                system("cls");
            }
        while(input != 0);

        fflush(stdin);
        while(getchar() != '\n');

        putCheckingAccountArray(newAccount);

        return;
    }

void viewAccount()
    {
        loadAccounts();
        
        int input;
        printf("Digite o número da conta para consulta: ");
        scanf("%d", &input);

        for(int i = 0; i <= savingsAccAmount; i++)
            {
                if (input == ContasPoupanca[i].pin)
                    {
                        printf("Conta POUPANCA encontrada!\n");
                        printf("\n\nagencia: %s\npin: %d\nnome do cliente: %s\nsenha: %s\nsaldo: %d\n\n",
                        ContasPoupanca[i].agency, 
                        ContasPoupanca[i].pin,
                        ContasPoupanca[i].clientName,
                        ContasPoupanca[i].senha,
                        ContasPoupanca[i].saldo);

                        fflush(stdin);
                        while(getchar() != '\n');
                        return;
                    }
            }

        for(int i = 0; i <= checkingsAccAmount; i++)
        {
            if (input == ContasCorrente[i].pin)
                {
                    printf("Conta CORRENTE encontrada!\n");
                    printf("agencia: %s\npin %d\nlimite: %d\ndata do vencimento: %d/%d/%d\nnome do cliente: %s\nsenha: %s\nsaldo: %d\n\n",
                    ContasCorrente[i].agency,
                    ContasCorrente[i].pin,
                    ContasCorrente[i].limite,
                    ContasCorrente[i].vencimento.dia,
                    ContasCorrente[i].vencimento.mes,
                    ContasCorrente[i].vencimento.ano,
                    ContasCorrente[i].clientName,
                    ContasCorrente[i].senha,
                    ContasCorrente[i].saldo);

                    fflush(stdin);
                    while(getchar() != '\n');
                    return;
                }
        }

        printf("Nenhuma conta com esse numero foi encontrada!");
        fflush(stdin);
        while(getchar() != '\n');
    }

void viewWorker()
    {
        loadInternalInfo();
        
        int input;
        printf("Digite o número da conta para consulta: ");
        scanf("%d", &input);

        for(int i = 0; i <= 100; i++)
            {
                if (input == ContasFuncionario[i].pin)
                    {
                        printf("Funcionario encontrado!\n");
                        printf("pin: %d\ncargo: %s\nnome: %s\nCPF: %s\nnascimento: %d/%d/%d\ntelefone: %s\nendereco: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\nsenha: %s\n\n",
                        ContasFuncionario[i].pin,
                        ContasFuncionario[i].cargo,
                        ContasFuncionario[i].nome,
                        ContasFuncionario[i].cpf,
                        ContasFuncionario[i].Nascimento.dia,
                        ContasFuncionario[i].Nascimento.mes,
                        ContasFuncionario[i].Nascimento.ano,
                        ContasFuncionario[i].telefone,
                        ContasFuncionario[i].endereco,
                        ContasFuncionario[i].cep,
                        ContasFuncionario[i].local,
                        ContasFuncionario[i].numeroCasa,
                        ContasFuncionario[i].bairro,
                        ContasFuncionario[i].cidade,
                        ContasFuncionario[i].estado,
                        ContasFuncionario[i].senha);

                        fflush(stdin);
                        while(getchar() != '\n');
                        return;
                    }
            }

        printf("Nenhum funcionario com esse codigo foi encontrado!");
        fflush(stdin);
        while(getchar() != '\n');
    }

void viewClient()
    {
        loadAccounts();
        
        int input;
        printf("Digite o número da conta para consulta: ");
        scanf("%d", &input);

        for(int i = 0; i <= savingsAccAmount; i++)
            {
                if (input == ContasPoupanca[i].pin)
                    {
                        printf("Cliente encontrado!\n");
                        printf("\n\npin: %d\nnome do cliente: %s\nCPF do cliente: %s\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %s\nendereco do cliente: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\n\n",
                        ContasPoupanca[i].pin,
                        ContasPoupanca[i].clientName,
                        ContasPoupanca[i].clientCPF,
                        ContasPoupanca[i].clientNascimento.dia,
                        ContasPoupanca[i].clientNascimento.mes,
                        ContasPoupanca[i].clientNascimento.ano,
                        ContasPoupanca[i].clientPhoneNumber,
                        ContasPoupanca[i].clientEndereco,
                        ContasPoupanca[i].clientCEP,
                        ContasPoupanca[i].clientLocal,
                        ContasPoupanca[i].clientHouseNumber,
                        ContasPoupanca[i].clientBairro,
                        ContasPoupanca[i].clientCity,
                        ContasPoupanca[i].clientState);

                        fflush(stdin);
                        while(getchar() != '\n');
                        return;
                    }
            }

        for(int i = 0; i <= checkingsAccAmount; i++)
        {
            if (input == ContasCorrente[i].pin)
                {
                    printf("Cliente encontrado!\n");
                    printf("\n\npin %d\nnome do cliente: %s\nCPF do cliente: %s\ndata de nascimento do cliente: %d/%d/%d\ntelefone: %s\nendereco do cliente: %s\nCEP: %s\nlocal: %s\nnumero da casa: %s\nbairro: %s\ncidade: %s\nestado: %s\n\n",
                    ContasCorrente[i].pin,
                    ContasCorrente[i].clientName,
                    ContasCorrente[i].clientCPF,
                    ContasCorrente[i].clientNascimento.dia,
                    ContasCorrente[i].clientNascimento.mes,
                    ContasCorrente[i].clientNascimento.ano,
                    ContasCorrente[i].clientPhoneNumber,
                    ContasCorrente[i].clientEndereco,
                    ContasCorrente[i].clientCEP,
                    ContasCorrente[i].clientLocal,
                    ContasCorrente[i].clientHouseNumber,
                    ContasCorrente[i].clientBairro,
                    ContasCorrente[i].clientCity,
                    ContasCorrente[i].clientState);

                    fflush(stdin);
                    while(getchar() != '\n');
                    return;
                }
        }

        printf("Nenhuma conta com esse numero foi encontrada!");
        fflush(stdin);
        while(getchar() != '\n');
    }

void alterarTipoPTC(int i)
    { 
        strcpy(ContasCorrente[checkingsAccAmount].agency, ContasPoupanca[i].agency);
        ContasCorrente[checkingsAccAmount].pin = ContasPoupanca[i].pin;
        ContasCorrente[checkingsAccAmount].limite = 0;
        ContasCorrente[checkingsAccAmount].vencimento.dia = 0;
        ContasCorrente[checkingsAccAmount].vencimento.mes = 0;
        ContasCorrente[checkingsAccAmount].vencimento.ano = 0;
        strcpy(ContasCorrente[checkingsAccAmount].clientName, ContasPoupanca[i].clientName);
        strcpy(ContasCorrente[checkingsAccAmount].clientCPF, ContasPoupanca[i].clientCPF);
        ContasCorrente[checkingsAccAmount].clientNascimento = ContasPoupanca[i].clientNascimento;
        strcpy(ContasCorrente[checkingsAccAmount].clientPhoneNumber, ContasPoupanca[i].clientPhoneNumber);
        strcpy(ContasCorrente[checkingsAccAmount].clientEndereco, ContasPoupanca[i].clientEndereco);
        strcpy(ContasCorrente[checkingsAccAmount].clientCEP, ContasPoupanca[i].clientCEP);
        strcpy(ContasCorrente[checkingsAccAmount].clientLocal, ContasPoupanca[i].clientLocal);
        strcpy(ContasCorrente[checkingsAccAmount].clientHouseNumber, ContasPoupanca[i].clientHouseNumber);
        strcpy(ContasCorrente[checkingsAccAmount].clientBairro, ContasPoupanca[i].clientBairro);
        strcpy(ContasCorrente[checkingsAccAmount].clientCity, ContasPoupanca[i].clientCity);
        strcpy(ContasCorrente[checkingsAccAmount].clientState, ContasPoupanca[i].clientState);
        strcpy(ContasCorrente[checkingsAccAmount].senha, ContasPoupanca[i].senha);
        ContasCorrente[checkingsAccAmount].saldo = ContasPoupanca[i].saldo;

        saveChanges();
    }

void alterarTipoCTP(int i)
    {
        strcpy(ContasPoupanca[savingsAccAmount].agency, ContasCorrente[i].agency);
        ContasPoupanca[savingsAccAmount].pin = ContasCorrente[i].pin;
        strcpy(ContasPoupanca[savingsAccAmount].clientName, ContasCorrente[i].clientName);
        strcpy(ContasPoupanca[savingsAccAmount].clientCPF, ContasCorrente[i].clientCPF);
        ContasPoupanca[savingsAccAmount].clientNascimento = ContasCorrente[i].clientNascimento;
        strcpy(ContasPoupanca[savingsAccAmount].clientPhoneNumber, ContasCorrente[i].clientPhoneNumber);
        strcpy(ContasPoupanca[savingsAccAmount].clientEndereco, ContasCorrente[i].clientEndereco);
        strcpy(ContasPoupanca[savingsAccAmount].clientCEP, ContasCorrente[i].clientCEP);
        strcpy(ContasPoupanca[savingsAccAmount].clientLocal, ContasCorrente[i].clientLocal);
        strcpy(ContasPoupanca[savingsAccAmount].clientHouseNumber, ContasCorrente[i].clientHouseNumber);
        strcpy(ContasPoupanca[savingsAccAmount].clientBairro, ContasCorrente[i].clientBairro);
        strcpy(ContasPoupanca[savingsAccAmount].clientCity, ContasCorrente[i].clientCity);
        strcpy(ContasPoupanca[savingsAccAmount].clientState, ContasCorrente[i].clientState);
        strcpy(ContasPoupanca[savingsAccAmount].senha, ContasCorrente[i].senha);
        ContasPoupanca[savingsAccAmount].saldo = ContasCorrente[i].saldo;

        saveChanges();
    }

void changeAccountType(Conta account)
    {
        if(isSavings(account))
            {   
                alterarTipoPTC(findSavingAccount(account));
                for(int i = findSavingAccount(account); i < LIM; i++) ContasPoupanca[i] = ContasPoupanca[i + 1];
                savingsAccAmount--;
                saveChanges();

                printf("Mudanca de tipo de conta feito com sucesso!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }
        else
            {
                alterarTipoCTP(findCheckingAccount(account));
                for(int i = findCheckingAccount(account); i < LIM; i++) ContasCorrente[i] = ContasCorrente[i + 1];
                checkingsAccAmount--;
                saveChanges();

                printf("Mudanca de tipo de conta feito com sucesso!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }
    }

void changeAccount()
    {   
        loadInternalInfo();
        loadAccounts();
        
        char passinput[20];
        printf("Digite a senha de administrador: ");
        scanf("%s", passinput);

        if (strcmp(ADM.senha, passinput) != 0)
            {
                printf("Senha incorreta!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        Conta acc;
        int foundAccount = 0;
        printf("\n\nDigite o numero da conta que vai ser alterada: ");
        scanf("%d", &acc.pin);

        for(int i = 0; i <= savingsAccAmount; i++)
            {
                if (ContasPoupanca[i].pin == acc.pin)
                    {
                        acc.isSavings = 1;
                        foundAccount++;
                    }
            }

        for(int i = 0; i <= checkingsAccAmount; i++)
            {
                if (ContasCorrente[i].pin == acc.pin)
                    {
                        acc.isSavings = 0;
                        foundAccount++;
                    }
            }

        if (foundAccount == 0)
            {
                printf("Uma conta nao pode ser encontrada com o numero inserido!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/aa/acc");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/aa/acc");
                    }
            
                while (!(input >= 1 && input <= 4))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 4).");
                        input = getWorkerInput("wm/aa/acc");
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            changeAccountType(acc);
                            return;

                        case 2:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Contas poupanca nao possuem limite ou vencimento");
                                }
                            else
                                {
                                    printf("Digite o novo limite: ");
                                    scanf("%d", &ContasCorrente[findCheckingAccount(acc)].limite);
                                    saveChanges();


                                    printf("Novo limite registrado!");
                                    fflush(stdin);
                                    while(getchar() != '\n');
                                }
                            return;

                        case 3:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Contas poupanca nao possuem limite ou vencimento");
                                }
                            else
                                {
                                    printf("Digite a nova data para o vencimento (dd mm aaaa): ");
                                    double newLimite;
                                    scanf("%d %d %d",
                                    &ContasCorrente[findCheckingAccount(acc)].vencimento.dia,
                                    &ContasCorrente[findCheckingAccount(acc)].vencimento.mes,
                                    &ContasCorrente[findCheckingAccount(acc)].vencimento.ano);
                                    saveChanges();


                                    printf("Novo vencimento registrado!");
                                    fflush(stdin);
                                    while(getchar() != '\n');
                                }
                            return;
                    }

                if (input != 4) input = 0;

            } while(input != 4);
    }

void changeWorker()
    {
        loadInternalInfo();
        loadAccounts();
        
        char passinput[20];
        printf("Digite a senha de administrador: ");
        scanf("%s", passinput);

        if (strcmp(ADM.senha, passinput) != 0)
            {
                printf("Senha incorreta!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        int worker;
        int acc;
        int foundAccount = 0;
        printf("\n\nDigite o numero do funcionario que vai ser alterado: ");
        scanf("%d", &acc);

        for (int i = 0; i < 100; i++)
            {
                if(ContasFuncionario[i].pin == acc)
                    {
                        worker = i;
                        foundAccount++;
                    }
            }

        if (foundAccount == 0)
            {
                printf("Um funcionario nao pode ser encontrada com o numero inserido!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/aa/wor");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/aa/acc");
                    }
            
                while (!(input >= 1 && input <= 4))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 4).");
                        input = getWorkerInput("wm/aa/acc");
                    }

                switch (input)
                    {
                        case 1:
                            fflush(stdin);
                            printf("Digite o novo pin para o funcionario: ");
                            scanf("%d", &ContasFuncionario[worker].pin);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;
                        case 2:
                            fflush(stdin);
                            printf("Digite o novo cargo para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].cargo);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 3:
                            fflush(stdin);
                            printf("Digite o novo telefone para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].telefone);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 4:
                            fflush(stdin);
                            printf("Digite o novo local para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].local);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 5:
                            fflush(stdin);
                            printf("Digite o novo numero da casa para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].numeroCasa);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 6:
                            fflush(stdin);
                            printf("Digite o novo CEP para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].cep);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 7:
                            fflush(stdin);
                            printf("Digite o novo bairro para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].bairro);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 8:
                            fflush(stdin);
                            printf("Digite a nova cidade para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].cidade);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                        case 9:
                            fflush(stdin);
                            printf("Digite o novo estado para o funcionario: ");
                            scanf("%[^\n]", ContasFuncionario[worker].estado);
                            saveWorkers();

                            printf("Alteracao realizada com sucesso!");
                            fflush(stdin);
                            while(getchar() != '\n');
                            return;

                    }

                if (input != 10) input = 0;

            } while(input != 10);
    }

void changeClient()
    {
        loadInternalInfo();
        loadAccounts();
        
        char passinput[20];
        printf("Digite a senha de administrador: ");
        scanf("%s", passinput);

        if (strcmp(ADM.senha, passinput) != 0)
            {
                printf("Senha incorreta!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        Conta acc;
        int foundAccount = 0;
        printf("\n\nDigite o numero da conta que vai ser alterada: ");
        scanf("%d", &acc.pin);

        for(int i = 0; i <= savingsAccAmount; i++)
            {
                if (ContasPoupanca[i].pin == acc.pin)
                    {
                        acc.isSavings = 1;
                        foundAccount++;
                    }
            }

        for(int i = 0; i <= checkingsAccAmount; i++)
            {
                if (ContasCorrente[i].pin == acc.pin)
                    {
                        acc.isSavings = 0;
                        foundAccount++;
                    }
            }

        if (foundAccount == 0)
            {
                printf("Uma conta nao pode ser encontrada com o numero inserido!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/aa/cli");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/aa/cli");
                    }
            
                while (!(input >= 1 && input <= 8))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 4).");
                        input = getWorkerInput("wm/aa/cli");
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo telefone");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientPhoneNumber);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo telefone");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientPhoneNumber);
                                    saveChanges();
                                }

                            printf("Novo telefone registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 2:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo local");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientLocal);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo local");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientLocal);
                                    saveChanges();
                                }

                            printf("Novo local registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 3:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo numero da casa");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientHouseNumber);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo numero da casa");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientHouseNumber);
                                    saveChanges();
                                }

                            printf("Novo numero da casa registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 4:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo CEP");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientCEP);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo CEP");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientCEP);
                                    saveChanges();
                                }

                            printf("Novo CEP registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 5:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo bairro");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientBairro);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo bairro");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientBairro);
                                    saveChanges();
                                }

                            printf("Novo bairro registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 6:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira a nova cidade");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientCity);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira a nova cidade: ");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientCity);
                                    saveChanges();
                                }

                            printf("Nova cidade registrada!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                        case 7:
                            system("cls");
                            if(isSavings(acc))
                                {
                                    printf("Insira o novo estado");
                                    scanf("%s", ContasPoupanca[findSavingAccount(acc)].clientState);
                                    saveChanges();
                                }
                            else
                                {
                                    printf("Insira o novo estado");
                                    scanf("%s", ContasCorrente[findCheckingAccount(acc)].clientState);
                                    saveChanges();
                                }

                            printf("Novo estado registrado!");
                            fflush(stdin);
                            while(getchar() != '\n');

                            return;

                    }

                if (input != 8) input = 0;

            } while(input != 8);
        
    }