#include "menu_client.c"

void mainMenu()
    {
        printf("Seja bem vindo(a) ao malvader bank: \n");
        
        printTxtFile("mm", "logo");

        processMainMenuInput(getMainMenuInput());

        return;
    }
int getMainMenuInput()
    {   
        int input;
        bool validInput = false;
        
        while (!validInput)
            {
                printTxtFile("mm", "options");
                if (scanf("%d", &input) == 1)
                    {
                        return input;
                    }
                else
                    {
                        while (getchar() != '\n');
                        system("cls");
                        printTxtFile("mm", "logo");
                        printf("Houve um erro processando o input. Por Favor, tente novamente.");
                    }
            }

        return input;
    }
void processMainMenuInput(int input)
    {
        do
            {
                if (input == 0)
                    {   
                        system("cls");
                        printTxtFile("mm", "logo");
                        input = getMainMenuInput();
                    }
            
                while (!(input >= 1 && input <= 3))
                    {
                        system("cls");
                        printTxtFile("mm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 3).");
                        input = getMainMenuInput();
                    }

                switch (input)
                    {
                        case 1:
                            system("cls");
                            menuFuncionario();
                            break;

                        case 2:
                            system("cls");
                            menuCliente();
                            break;

                        case 3:
                            fflush(stdin);
                            system("cls");
                            closingScreen();
                            break;

                    }
                input = 0;
            }
        while(input != 3);
    }

void menuFuncionario()
    {

        Funcionario account = funcionarioLogin();

        if (account.pin == -1)
            {
                printf("Usuario ou senha invalido\n");
                fflush(stdin);
                while (getchar() != '\n');
                return;
            }

        printTxtFile("wm", "logo");

        processFuncionarioMenuInput(getFuncionarioMenuInput());
        
        return;
    }
int getFuncionarioMenuInput()
    {
        int input;
        bool validInput = false;
        
        while (!validInput)
            {
                printTxtFile("wm", "options");
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
void processFuncionarioMenuInput(int input)
    {
        do
            {
                fflush(stdin);

                if (input == 0)
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        input = getFuncionarioMenuInput();
                    }

                while (!(input >= 1 && input <= 7))
                    {
                        system("cls");
                        printTxtFile("wm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 7).");
                        input = getFuncionarioMenuInput();
                    }

                input = funcionarioOperacoes(input);
            }
        while (input != 7);
    }

void menuCliente()
    {
        Conta account = clientLogin();

        if (account.pin == -1)
            {
                printf("Usuario ou senha invalido\n");
                fflush(stdin);
                while (getchar() != '\n');
                return;
            }

        printTxtFile("cm", "logo");

        processClientMenuInput(getClientMenuInput(), account);
        
        return;
    }
int getClientMenuInput()
    {
        int input;
        bool validInput = false;
        
        while (!validInput)
            {
                printTxtFile("cm", "options");
                if (scanf("%d", &input) == 1)
                    {
                        return input;
                    }
                else
                    {
                        while (getchar() != '\n');
                        system("cls");
                        printTxtFile("cm", "logo");
                        printf("Houve um erro processando o input. Por Favor, tente novamente.");
                    }
            }

        

        return input;
    }
void processClientMenuInput(int input, Conta account)
    {
        do
            {
                fflush(stdin);

                if (input == 0)
                    {
                        system("cls");
                        printTxtFile("cm", "logo");
                        input = getClientMenuInput();
                    }

                while (!(input >= 1 && input <= 6))
                    {
                        system("cls");
                        printTxtFile("cm", "logo");
                        printf("A escolha de menu foi invalida. Por favor, insira uma opcao valida (1 - 6).");
                        input = getClientMenuInput();
                    }

                input = clienteOperacoes(input, account);
            }
        while (input != 6);
    }

void closingScreen()
    {
        setFullscreen();
        printTxtFile("cs", "screen");
        fflush(stdin);
        char eeinput[20];
        scanf("%20[^\n]",eeinput);
        EESecret(eeinput);
        exit(1);
    }
void EESecret(char input[])
    {
        if(strcmp(input, "maytheforce") == 0)   system("START https://youtu.be/gYbW1F_c9eM");
        if(strcmp(input, "hellothere") == 0)    system("START https://youtu.be/d0oknb6fX04?t=5");
        if(strcmp(input, "father") == 0)        system("START https://youtu.be/_lOT2p_FCvA?t=65");
    }