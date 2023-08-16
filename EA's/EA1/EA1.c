#include "clinica.h"

int main() {
    char opcao;
    tPaciente pacientes[MAXPACIENTES];

    while(opcao != 'F') {
        scanf("%c", &opcao);

        if (opcao == 'P') {
            cadastraPaciente(pacientes);
        } else if (opcao == 'L') {
            cadastraLesao(pacientes);
        } 
    }

    dadosGerais(pacientes);
    imprimePacientes(pacientes);

    return 0;
}