#include "bankingoper.h"

int checkFreePosition(tAccount accounts[MAXACCOUNTS]) {
	int i = 0, aux;

	for (i = 0; i < MAXACCOUNTS; i++) {
		if (accounts[i].activeAccount != ACTIVEACCOUNT) {
			aux = 1;
			break;
		}
	}
	
	if (aux)
		return TRUE;
	return FALSE;
}

void showData (tAccount account) {
    printf("\nRazao Social: %s", account.socialName);
    printf("\nCPF: %s", account.cpf);
    printf("\nSaldo disponivel: %d", account.balance);
}

int freePosition (tAccount accounts[MAXACCOUNTS]) {
	int i = 0, pos = 0;

	for (i = 0; i < MAXACCOUNTS; i++) {
		if (accounts[i].activeAccount != ACTIVEACCOUNT) {
			return pos;
			break;
		}
	}
}

int generateAccNumber () {
	srand(time(NULL));
	return rand() % 100000;
}

void registerUser (tAccount accounts[MAXACCOUNTS]) {
	int i = 0;
	
	if (freePosition(accounts) == TRUE) {
		i = freePosition(accounts);

		printf("\nRazao Social: ");
		fgets(accounts[i].socialName, 80, stdin);
		cleanBuffer();

		printf("\nData de Nascimento: ");
		fgets(accounts[i].dateBirth, 12, stdin);
		cleanBuffer();

		printf("\nCPF: ");
		fgets(accounts[i].cpf, 15, stdin);
		cleanBuffer();

		printf("\ntelefhone: ");
		fgets(accounts[i].telefhone, 10, stdin);
		cleanBuffer();

		printf("\nEmail: ");
		fgets(accounts[i].email, 50, stdin);
		cleanBuffer();

		printf("\nEndereço: ");
		fgets(accounts[i].andress, 80, stdin);
		cleanBuffer();

		accounts[i].balance = 0;
		accounts[i].activeAccount = ACTIVEACCOUNT;
		accounts[i].accountNumber = generateAccNumber();
		printf("\nCadastro realizado com sucesso");
	} else {
		printf("\nO BANCO ATINGIU A CAPACIDADE MAXIMA DE CLIENTES");
		printf("\nNAO EH POSSIVEL REALIZAR UM NOVO CADASTRO\n");
	}
}

int searchAccount (tAccount accounts[MAXACCOUNTS]) {
	int i, number, pos = FALSE;

	printf("\nNumero da conta: ");
	scanf("%d", &number);
	cleanBuffer();

	for (i = 0; i <MAXACCOUNTS; i++) {
		if (number == accounts[i].accountNumber) {
			pos = i;
			break;
		}
	}
		
	return pos;
}

void deposit (tAccount accounts) {
	int value;

	printf("\n\nvalor do deposito: ");
	while (1) {
		scanf("%d", &value);
		cleanBuffer();

		if (value < 0) {
			printf("\nPor favor, digite um value valido ou digite 0 para cancelar: ");
		} else break;
	}

	if (value == 0) {
		printf("\nOperacao cancelada\n");
	} else {
		accounts.balance += value;
		printf("\nDeposito realizado com sucesso\n");
	}
}

int checkWithdrawal (tAccount accounts, int value) {
	if (value > accounts.balance) {
		return FALSE;
	} else return TRUE;
}

void withdraw (tAccount accounts) {
	int value;
	
	printf("\n\nvalor do saque: ");
	while (1) {
		scanf("%d", &value);
		cleanBuffer();
		
		if (checkWithdrawal(accounts, value) == TRUE || value == 0) {
			break;
		} else {
			printf("\nSaldo Insuficiente");
			printf("\nDigite um value menor ou igual ao balance disponivel ou digite 0 para cancelar a operacao: ");
		}
	}

	if (value == 0) {
		printf("\nOperacao cancelada\n");
	} else {
		accounts.balance -= value;
		printf("\nSaque realizado com sucesso\n");
	}
}

void closeAccount (tAccount accounts) {
	int opcao;

	printf("\nTem certeza que deseja encerrar a conta? O processo eh irreversivel.\n");
	printf("\n\n1 para confirmar\n\n0 para cancelar\n");
	printf("\nopcao: ");
	intFoceOption(0, 1);

	if (opcao == 1) {
		accounts.activeAccount = ACCOUNTCLOSED;
		accounts.dateBirth[0] = '\0';
		accounts.cpf[0] = '\0';
		accounts.email[0] = '\0';
		accounts.andress[0] = '\0';
		accounts.socialName[0] = '\0';
		accounts.telefhone[0] = '\0';
		accounts.balance = 0;
		printf("\nConta encerrada\n");
	} else if (opcao == 0) {
		printf("\nOperacao Cancelada\n");
	}
}

void initializeBank (tAccount accounts[MAXACCOUNTS]) {
	int option, pos, aux;
	tLogin users[CAPACITY];
	//system("clear||cls");

	aux = initializeLogin(users);

	if (aux == TRUE) {
		while (1) {
			printf("\n\t\tMENU PRINCIPAL\n");
			printf("1 - Abertura de conta\n");
			printf("2 - Deposito\n");
			printf("3 - Saque\n");
			printf("4 - Extrato da conta\n");
			printf("5 - Encerramento de conta\n");
			printf("6 - Encerrar secao\n\n");

			printf("Opcao escolhida: ");
			while (1) {
				scanf("%d", &option);
				cleanBuffer();

				if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6) {
					break;
				}

				printf("\nPor favor, digite um opcao valida: ");
			}
			system("clear||cls");

			if (option == 1) {
				//abertura de conta
				registerUser(accounts);
				continue;
			} else if (option == 2) {
				//deposito
				while (1) {
					pos = searchAccount(accounts);

					if (pos != FALSE) {
						showData(accounts[pos]);
						deposit(accounts[pos]);
						break;
					} else {
						printf("\nConta nao encontrada\n");
						printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
						option = intFoceOption(0, 1);

						if (option == 0) {
							printf("\nOperacao cancelada\n");
							break;
						}
						system("clear||cls");
					}
				}
				continue;
			} else if (option == 3) {
				//saque
				while (1) {
					pos = searchAccount(accounts);

					if (pos != FALSE) {
						showData(accounts[pos]);
						withdraw(accounts[pos]);
						break;
					} else {
						printf("\nConta nao encontrada\n");
						printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
						option = intFoceOption(0, 1);

						if (option == 0) {
							printf("\nOperacao cancelada\n");
							break;
						}
						system("clear||cls");
					}
				}
				continue;
			} else if (option == 4) {
				//extrato
				while (1) {
					pos = searchAccount(accounts);

					if (pos != FALSE) {
						showData(accounts[pos]);
						break;
					} else {
						printf("\nConta nao encontrada\n");
						printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
						option = intFoceOption(0, 1);

						if (option == 0) {
							printf("\nOperacao cancelada\n");
							break;
						}
						system("clear||cls");
					}
				}
				continue;
			} else if (option == 5) {
				//encerramento de conta
				while (1) {
					pos = searchAccount(accounts);

					if (pos != FALSE) {
						closeAccount(accounts[pos]);
						break;
					} else {
						printf("\nConta nao encontrada\n");
						printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
						option = intFoceOption(0, 1);

						if (option == 0) {
							printf("\nOperacao cancelada\n");
							break;
						}
						system("clear||cls");
					}
				}
				continue;
			} else break;
			system("clear||cls");
		}
	}
}