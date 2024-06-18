#include "procedure.h"

int funcionarioOperacoes(int input)
    {            
        if (input < 1 || input > 7) 
            {
                return 8;
            }

        fflush(stdin);
        
        switch(input)
            {
                case 1:
                    createAccount();
                    break;
                case 2:
                    deleteAccount();
                    break;
                case 3:
                    viewAccounts();
                    break;
                case 4:
                    changeAccounts();
                    break;
                case 5:
                    cadastrarWorker();
                    break;
                case 6:
                    gerarRelatorio();
                    break;
                case 7:
                    system("cls");
                    return 7;
            }
        fflush(stdin);
        return 0;
        
    }

void createAccount()
    {   
        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/ca");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/ca");
                    }
            
                while (!(input >= 1 && input <= 3))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 3).");
                        input = getWorkerInput("wm/ca");
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            createSavingAccount();
                            break;

                        case 2:
                            system("cls");
                            createCheckingAccount();
                            break;
                    }

                if (input != 3) input = 0;

            } while(input != 3);
    }

void deleteAccount()
    {
        
        char input[10];
        printf("Digite a senha de ADM: ");
        scanf("%s", input);

        if (strcmp(input, getADM().senha) != 0) 
            {
                printf("Senha de administrador incorreta!");
                fflush(stdin);
                while(getchar() != '\n');
                return;
            }

        int accountDelete;
        printf("Digite o numero da conta a ser deletada: ");
        scanf("%d", &accountDelete);

        loadAccounts();

        for (int i = 0; i < LIM; i++)
            {
                if (ContasPoupanca[i].pin == accountDelete)
                    {
                        for(int j = i; j <= savingsAccAmount; j++)
                            ContasPoupanca[j] = ContasPoupanca[j + 1];
                        savingsAccAmount--;
                        saveChanges();
                        printf("Conta deletada com sucesso!\n");
                        fflush(stdin);
                        while(getchar() != '\n');
                        return;
                    }
                if (ContasCorrente[i].pin == accountDelete)
                    {
                        for(int j = i; j <= checkingsAccAmount; j++)
                            ContasCorrente[j] = ContasCorrente[j + 1];
                        checkingsAccAmount--;
                        saveChanges();
                        printf("Conta deletada com sucesso!\n");
                        fflush(stdin);
                        while(getchar() != '\n');
                        return;
                    }
            }
        printf("Nenhuma conta foi encontrada com esse numero :(\n");
        fflush(stdin);
        while(getchar() != '\n');
    }

void viewAccounts()
    {
        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/va");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/va");
                    }
            
                while (!(input >= 1 && input <= 4))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 4).");
                        input = getWorkerInput("wm/va");
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            viewAccount();
                            break;

                        case 2:
                            system("cls");
                            viewWorker();
                            break;

                        case 3:
                            system("cls");
                            viewClient();
                            break;
                    }

                if (input != 4) input = 0;

            } while(input != 4);

    }

void changeAccounts()
    {
        system("cls");
        printTxtFile("wm", "logo");
        int input = getWorkerInput("wm/aa");

        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getWorkerInput("wm/aa");
                    }
            
                while (!(input >= 1 && input <= 4))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 4).");
                        input = getWorkerInput("wm/aa");
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            changeAccount();
                            break;

                        case 2:
                            system("cls");
                            changeWorker();
                            break;

                        case 3:
                            system("cls");
                            changeClient();
                            break;
                    }

                if (input != 4) input = 0;

            } while(input != 4);
    }

void cadastrarWorker()
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
        system("cls");
        
        Data newDate = {
            .dia = 0,
            .mes = 0,
            .ano = 0
            };
        Funcionario newWorker = {  
            .pin = 0,
            .cargo = "N/A",
            .nome = "N/A",
            .cpf = "N/A",
            .Nascimento = newDate,
            .telefone = "N/A",
            .endereco = "N/A",
            .cep = "N/A",
            .local = "N/A",
            .numeroCasa = "N/A",
            .bairro = "N/A",
            .cidade = "N/A",
            .estado = "N/A",
            .senha = "N/A",
            .isAdm = 0
        };

        int input;

        do 
            {
                int input = getWorkerInput("wm/cw");
                
                if (input == 0) break;

                if (input < 0 || input > 14)
                    {
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (0 - 14).");
                        continue;
                    }
                    
                switch(input)
                    {
                        case 1:
                            printf("Digite o pin do funcionario: \n");
                            scanf("%d", &newWorker.pin);

                            break;
                        case 2:
                            fflush(stdin);
                            printf("Digite o cargo do funcionario: \n");
                            scanf("%[^\n]", newWorker.cargo);

                            break;
                        case 3:
                            fflush(stdin);
                            printf("Digite o nome do funcionario: \n");
                            scanf("%[^\n]", newWorker.nome);
                            
                            break;
                        case 4:
                            fflush(stdin);
                            printf("Digite o CPF do funcionario: \n");
                            scanf("%[^\n]", newWorker.cpf);

                            break;
                        case 5:
                            printf("Digite a data de nascimento do funcionario (dd mm aaaa): \n");
                            scanf("%d %d %d", &newWorker.Nascimento);

                            break;
                        case 6:
                            fflush(stdin);
                            printf("Digite o telefone do funcionario: \n");
                            scanf("%[^\n]", newWorker.telefone);

                            break;
                        case 7:
                            fflush(stdin);
                            printf("Digite o endereco do funcionario: \n");
                            scanf("%[^\n]", newWorker.endereco);

                            break;
                        case 8:
                            fflush(stdin);
                            printf("Digite o CEP do funcionario: \n");
                            scanf("%[^\n]", newWorker.cep);

                            break;
                        case 9:
                            fflush(stdin);
                            printf("Digite o local do funcionario: \n");
                            scanf("%[^\n]", newWorker.local);

                            break;
                        case 10:
                            fflush(stdin);
                            printf("Digite o numero da casa do funcionario: \n");
                            scanf("%[^\n]", newWorker.numeroCasa);

                            break;
                        case 11:
                            fflush(stdin);
                            printf("Digite o bairro do funcionario: \n");
                            scanf("%[^\n]", newWorker.bairro);

                            break;
                        case 12:
                            fflush(stdin);
                            printf("Digite a cidade do funcionario: \n");
                            scanf("%[^\n]", newWorker.cidade);

                            break;
                        case 13:
                            fflush(stdin);
                            printf("Digite o estado do funcionario: \n");
                            scanf("%[^\n]", newWorker.estado);

                            break;
                        case 14:
                            fflush(stdin);
                            printf("Digite a senha do funcionario: \n");
                            scanf("%[^\n]", newWorker.senha);

                            break;

                        case 0:
                            break;
                    }

                system("cls");
            }
        while(input != 0);

        for (int i = 0; i < 100; i++)
            {   
                if (ContasFuncionario[i].pin == newWorker.pin)
                    {
                        printf("a funcionario nao pode ser cadastrado, ja que o pin ja estava em uso, tente novamente");
                        return;
                    }
                if (ContasFuncionario[i].pin == 0)
                    {
                        ContasFuncionario[i] = newWorker;
                        break;
                    }
            }

        saveWorkers();
    }

void gerarRelatorio()
    {
        Funcionario account = funcionarioLogin();

        if (account.pin == -1)
            {
                printf("Usuario ou senha invalido\n");
                fflush(stdin);
                while (getchar() != '\n');
                return;
            }

        FILE *file_rela = fopen("./src/sys/rela.txt", "r");
        FILE *file = fopen("./src/sys/relatorio.csv","w");

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

        for (int i = 0; i < i_transac; i++)
            {
                fprintf(file, "Conta: %d;%s: %d\n",
                (extrato[i].account),
                ((extrato[i].type == 'D') ? ("Deposito") : ("Saque")),
                extrato[i].amount);
            }

        system("start excel ./src/sys/relatorio.csv");

        fclose(file);
        fclose(file_rela);
    }