#include "login.h"


int adminOperation () {
    char name[6], password[10];
    
    while (1) {
        printf("\nUSUARIO: ");
        fgets(name, 6, stdin);
        cleanBuffer();
        
        if (strcmp(name, "0") == 0) {
            printf("\nOperacao cancelada\n");
            return FALSE;
            break;
        }

        printf("\nSENHA: ");
        passwordImput(password);

        if ((strcmp(name, "ADMIN") == 0) && strcmp(password, "!!!") == 0) {
            return TRUE;
            break;
        }
        printf("\nNome do usuario ou senha invalido(s). Tente novamente ou digite 0 para cancelar a operacao\n");
    }
    
}

int searchUser (char name[20], tLogin users[CAPACITY]) {
    /*ESTA FUNCAO IRA RETORNAR A POSICAO NA STRUCT EM QUE O USUARIO SE ENCONTRA
    CASO NAO ENCONTRE NINGUEM SERA RETORNADO "FALSO"*/
    int aux = FALSE, i, pos;

    for (i = 0; i < CAPACITY; i++) {
        if (strcmp(name, users[i].userName) == 0) {
            aux = TRUE;
            pos = i;
            break;
        }
    }

    return aux;
}
 
int freePositionLo (tLogin users[CAPACITY]) {
    int i, aux = FALSE, pos;

    for (i = 0; i < CAPACITY; i++) {
        if (users[i].activeUser != ENABLE) {
            aux = ENABLE;
            pos = i;
            break;
        }
    }
    return pos;
}

int usernameAvaibility (char name[20], tLogin users[CAPACITY]) {
    int i, aux = TRUE;

    for (i = 0; i < CAPACITY; i++) {
        if (strcmp(name, users[i].userName) == 0) {
            aux = FALSE;
            break;
        }

    }
    
    return aux;
}

void registerUserLo (tLogin users[CAPACITY], int pos) {
    char repeatPass[10], name[20];

    printf("\nDe um nome para seu usuario: ");

    //REGISTRAR UM NOME QUE NAO SEJA REPETIDO name[20], tLogin users[CAPACITY]);
    while (1) {
        fgets(name, 20, stdin);
        cleanBuffer();
        if (usernameAvaibility(name, users) == TRUE) {
            strcpy(users[pos].userName, name);
            break;
        }
        printf("\nEste nome ja esta em uso. Por favor, digite outro: ");
    }

    //REGISTRAR UMA SENHA
    printf("\nRegistre sua senha (MAX 10 digitos): ");
    while (1) {
        passwordImput(users[pos].password);

        printf("\nRepita a senha: ");
        passwordImput(repeatPass);

        if (strcmp(users[pos].password, repeatPass) == 0) {
            printf("\nSenha registrada com sucesso!\n");
            break;
        }
        printf("\nAs senhas nao iguais, tente novamente: ");
    }

    users[pos].activeUser = ENABLE;
    printf("\nUsuario registrado\n");

   

}

void retireUser (tLogin users[CAPACITY]) {
    int pos, option;
    char name[20], password[10];
    
    if (adminOperation(users) == TRUE) {
        while (1) {
            printf("Nome do usuario: ");
            fgets(name, 20, stdin);
            cleanBuffer();

            pos = searchUser(name, users);
            if (pos != FALSE) {
                printf("\nTem certeza que deseja excluir o usuario? A operacao e irreversilvel\n");
                printf("0 - Cancela\n");
                printf("1 - Confirma\n");

                while (1) {
                    scanf("%d", &option);
                    if (option == 1 || option == 0) 
                        break;
                
                    printf("\nOpcao invalida, tente novamente: \n");
                }
            
                if (option == 1) {
                    users[pos].activeUser = DISABLE;
                    users[pos].password[0] = '\0';
                    users[pos].userName[0] = '\0';

                    printf("\nUsuario excluido com sucesso!\n");
                    break;
                } else if (option == 0) {
                    printf("\nOperacao cancelada\n");
                }
            } else if (strcmp(name, "0") == 0) {
                printf("\nOperacao de exclusao de usuario cancelada\n");
                break;
            } else {
                printf("\nUsuario nao encontrado. Tente novamente ou digite 0 para cancelar a operacao: ");
            }           
        }

    } else 
        printf("\nOperacao de retirar usuario cancelada\n");
}

void passwordRecovey (tLogin users[CAPACITY]) {
    char name[20], repeatPass[10];
    int pos;

    if (adminOperation(users) == TRUE) {
        printf("\nDigite o nome do usuario que deseja recuperar/alterar a senha: ");
        
        while (1) {
            fgets(name, 20, stdin);
            cleanBuffer();
            pos = searchUser(name, users);

            if (strcmp(name, "0") == 0) {
                printf("\nOperacao de recuperacao de senha cancelada\n");
                break;
            }

            if (pos != FALSE) {
                printf("\nRegistre sua nova senha (MAX 10 digitos): ");
                while (1) {
                    passwordImput(users[pos].password);

                    printf("\nRepita a senha: ");
                    passwordImput(repeatPass);

                    if (strcmp(users[pos].password, repeatPass) == 0) {
                        printf("\nSenha registrada com sucesso!\n");
                        break;
                    }
                    printf("\nAs senhas nao iguais, tente novamente: ");
                }
                break;  
            }
            printf("\nUsuario nao encontrado tente novamente ou digite 0 para cancelara operacao: ");
            
        }
    } else 
        printf("\nOperacao de recuperacao de senha cancelada\n");

}

int initializeLogion (tLogin users[CAPACITY]) {
    int option, pos;
    char name[20], password[10];

    while (1) {
        printf("1 - Realizar login\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Remover usuario\n");
        printf("4 - Recuperacao de senha\n");
        printf("5 - Encerrar secao\n");
        
        printf("Opcao escolhida: ");

        while (1) {
            scanf("%d", &option);
            cleanBuffer();

            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5) {
                break;
            }
            printf("\nPor favor, digite um opcao valida: ");
        }
        system("clear||cls");

        if (option == 1) {
            while (1) {
                printf("\nUsuario: ");
                fgets(name, 20, stdin);
                cleanBuffer();
                pos = searchUser(name, users);

                printf("\nSenha: ");
                passwordImput(password);

                if (pos != FALSE && strcmp(users[pos].password, password) == 0) {
                    break;
                    system("clear||cls");
                }
                printf("\nNome e/ou senha incorreto(s)\n");
            }  
            return TRUE;
            break;
        } else if (option == 2) {
            if (adminOperation() == TRUE) {
                pos = freePositionLo(users);
                if (pos != FALSE) {
                    registerUserLo(users, pos);
                } else {
                    printf("Capacidade maxima de usuarios registrados atingida\n");
                    break;
                }
            } else break;
            continue;
        } else if (option == 3 ) {
            retireUser(users);
            continue;
        } else if (option == 4) {
            passwordRecovey(users);
            continue;
        } else {
            return FALSE;
            break;
        }
    }
}