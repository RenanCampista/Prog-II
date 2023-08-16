#include "paciente.h"

int main() {
    tPaciente *paciente = NULL;
    char opcao;
    int totalPacientes = 0;

    while (1) {
        scanf(" %c ", &opcao);

        if (opcao == 'P') {
            totalPacientes++;
            paciente = cadastraPaciente(paciente, totalPacientes);
        } else if (opcao == 'L') {
            cadastraLesao(paciente, totalPacientes);
        } else {
            printf("TOTAL PACIENTES: %d\n", totalPacientes);
            printf("MEDIA IDADE (ANOS): %d\n", calculaMediaIdade(paciente, totalPacientes));
            printf("TOTAL LESOES: %d\n", totalLesoes(paciente, totalPacientes));
            printf("TOTAL CIRURGIAS: %d\n", contabilizaCirurgias(paciente, totalPacientes));
            printf("LISTA DE PACIENTES:\n");
            imprimeRelatorio(paciente, totalPacientes);

            liberaMemoria(paciente, totalPacientes);
            break;
        }
    }

    return 0;
}