#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pad.h"
#include "paciente.h"
#include "historico.h"
#include "lesao.h"
#include "data.h"
#include "constantes.h"

struct Pad {
    tPaciente **pacientes;
    tLesao **lesoes;
    tHistorico **historico_medico;

    int num_pacientes, num_lesoes, num_historicos, total_consultas;
    int pacientes_alocados, lesoes_alocadas, historicos_alocados;
};

void cria_diretorios (const char* nome_pasta) {
    int status;
    /*
        - CRIA O DIRETORIO USANDO O COMANDO SHELL 'MKDIR'
        - USANDO SYSTEM NAO PRECISA CHAMAR A BIBLIOTECA DA FUNCAO MKDIR 
    */

    //SAIDA PRINCIPAL
    char comando[100];
    snprintf(comando, sizeof(comando), "mkdir %s", nome_pasta);
    status = system(comando);
    if (status != 0) printf("A PASTA PRINCIPAL JA EXISTE");

    //LOGS
    snprintf(comando, sizeof(comando), "mkdir %s/logs", nome_pasta);
    status = system(comando);
    if (status != 0) printf("A PASTA DE LOGS JA EXISTE");

    //BUSCAS
    snprintf(comando, sizeof(comando), "mkdir %s/buscas", nome_pasta);
    status = system(comando);
    if (status != 0) printf("A PASTA DE BUSCAS JA EXISTE");

    //RELATORIO
    snprintf(comando, sizeof(comando), "mkdir %s/relatorio", nome_pasta);
    status = system(comando);
    if (status != 0) printf("A PASTA DO RELATORIO JA EXISTE");
}

tPad *inicializa_pad () {
    tPad *p = (tPad *) malloc(sizeof(tPad));

    if (p == NULL) {
        printf("FALTA MEMORIA PARA INICIALIZAR A PAD\n");
        exit(1);
    }
    p->pacientes_alocados = 0;
    p->lesoes_alocadas = 0;
    p->historicos_alocados = 0;

    p->num_pacientes = 0;
    p->num_lesoes = 0;
    p->num_historicos = 0;
    p->total_consultas= 0;

    p->pacientes = NULL;
    p->lesoes = NULL;
    p->historico_medico = NULL;
    return p;
}

void cadastrar_paciente (tPad *p) {
    int cartao_repetido = FALSO;
    char cartao_sus[TAM_CARTAO_SUS], nome_paciente[101];

    printf("NOME: ");
    scanf("\n%101[^\n]", nome_paciente);

    printf("\nCARTAO SUS: ");
    scanf("\n%s", cartao_sus);

    for (int i = 0; i < p->num_pacientes; i++) {
        if (verifica_cartao_sus_paciente(p->pacientes[i], cartao_sus) == VERDADEIRO) {
            cartao_repetido = VERDADEIRO;
            break;
        }
    }

    if (cartao_repetido == FALSO) {
        tPaciente *paciente = aloca_paciente();
        le_paciente(paciente, nome_paciente, cartao_sus);

        p->pacientes_alocados++;
        p->pacientes = (tPaciente **) realloc(p->pacientes, p->pacientes_alocados * sizeof(tPaciente *));
        if (p->pacientes == NULL) {
            printf("FALTA MEMORIA PARA CADASTRAR UM NOVO PACIENTE\n");
            exit(1);
        }

        p->pacientes[p->num_pacientes] = paciente;
        p->num_pacientes++;
       
    } else {
        printf("NAO FOI POSSIVEL CONCLUIR O CADASTRO, POIS O CARTAO SUS JA ESTA NA BASE DE DADOS");
    }
}

void realizar_consulta (tPad *p, const char * caminho) {
    int verificador = FALSO, pos = FALSO;
    char cartao[TAM_CARTAO_SUS];
    printf("CARTAO SUS: ");
    scanf("\n%s", cartao);

    for (int i = 0; i < p->num_pacientes; i++) {
        if (verifica_cartao_sus_paciente(p->pacientes[i], cartao) == VERDADEIRO) {
            verificador = i;
            break;
        }
    }

    if (verificador != FALSO) {
        for (int i = 0; i < p->num_historicos; i++) {
            if (verifica_cartao_sus_historico(p->historico_medico[i], cartao) == VERDADEIRO) {
                pos = i;
                break;
            }
        }

        if (pos != FALSO) {
            p->historicos_alocados--;
            p->num_historicos--;
            free_historico(p->historico_medico[pos]);
        }
        p->historicos_alocados++;
        p->historico_medico = (tHistorico **) realloc(p->historico_medico, p->historicos_alocados * sizeof(tHistorico *));
        if (p->historico_medico == NULL) {
            printf("FALTA MEMORIA PARA ALOCAR UM HISTORICO MEDICO\n");
            exit(1);
        }
        
        tHistorico *h = inicializa_historico();
        le_hisotorico(h, cartao);
        p->historico_medico[p->num_historicos] = h;
        p->num_historicos++;

        p->total_consultas++;

        char caminhoCompleto[100];
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/logs/log_%d", caminho, p->total_consultas);
 
        FILE *file = fopen(caminhoCompleto, "w");
        fprintf(file, "%s\n", cartao);

        while(1) {
            char diagnostico[100], id[100];
            printf("\nDIAGNOSTICO: ");
            scanf("\n%100[^\n]", diagnostico);

            if (strcmp(diagnostico, "E") == 0 || strcmp(diagnostico, "e") == 0) {
                //p->total_consultas++;
                atribui_consulta(p->pacientes[verificador]);
                fclose(file);
                break;
            }

            p->lesoes_alocadas++;
            p->lesoes = (tLesao **) realloc(p->lesoes, p->lesoes_alocadas * sizeof(tLesao *));
            if (p->lesoes == NULL) {
                printf("FALTA MEMORIA PARA ALOCAR UMA NOVA LESAO\n");
                exit(1);
            }
            tLesao *lesao = aloca_lesao();

            /*
                SABER QUANTAS LESOES O PACIENTE POSSUI PARA ATRIBUIR O PROXIMO ID
                CONT COMEÇA A PARTIR DO 1, POIS O PRIMEIRO ID SERA 1
            */
            int cont_lesoes_paciente = ID_INICIAL;
            for (int i = 0; i < p->num_lesoes; i++) {
                if (verifica_cartao_sus_lesao(p->lesoes[i], cartao) == VERDADEIRO)
                    cont_lesoes_paciente++;
            }

            snprintf(id, sizeof(id), "L%d", cont_lesoes_paciente);
            cadastra_lesao(lesao, cartao, id, diagnostico);
            imprime_log(lesao, file);
            p->lesoes[p->num_lesoes] = lesao;
            p->num_lesoes++;
        }
    } else {
        printf("O PACIENTE PRECISA SER CADASTRADO\n");
    }
}

void buscar_paciente (tPad *p, const char * caminho) {
    int pos = FALSO;
    char cartao[TAM_CARTAO_SUS];
    scanf("\n%s", cartao);

    for (int i = 0; i < p->num_pacientes; i++) {
        if (verifica_cartao_sus_paciente(p->pacientes[i], cartao) == VERDADEIRO) {
            pos = i;
            break;
        } 
    }
    if (pos != FALSO) {
        char caminhoCompleto[100];
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/buscas/busca_%s", caminho, cartao);

        FILE *file = fopen(caminhoCompleto, "w");
        imprime_paciente_arq_busca(p->pacientes[pos], file);

        for (int i = 0; i < p->num_historicos; i++) {
            if ((verifica_cartao_sus_historico(p->historico_medico[i], cartao) == VERDADEIRO) && (verifica_consulta(p->pacientes[i]) == VERDADEIRO)) {
                imprime_historico_arq_busca(p->historico_medico[i], file);
                break;
            }
        }
        
        int num_lesoes = 0, num_cirurgias = 0, num_crioterapias = 0;
        if (verifica_consulta(p->pacientes[pos]) == VERDADEIRO) {
            fprintf(file, "\nLESOES:\n");
            for (int i = 0; i < p->num_lesoes; i++) {
                if (verifica_cartao_sus_lesao(p->lesoes[i], cartao) == VERDADEIRO) {
                    num_lesoes++;
                    if (num_lesoes > 0){
                        if (verifica_cirurgia(p->lesoes[i]) == VERDADEIRO) 
                            num_cirurgias++;
                        else if (verifica_crioterapia(p->lesoes[i]) == VERDADEIRO) 
                            num_crioterapias++;                    
                    }             
                }
            }
            
            fprintf(file, "TOTAL: %d\n", num_lesoes);
            fprintf(file, "ENVIADA PARA CIRURGIA: %d\n", num_cirurgias);
            fprintf(file, "ENVIADA PARA CRIOTERAPIA: %d\n", num_crioterapias);
            
            fprintf(file, "\nDESCRICAO DAS LESOES:\n");
            for (int i = 0; i < p->num_lesoes; i++) {
                if (verifica_cartao_sus_lesao(p->lesoes[i], cartao) == VERDADEIRO) 
                    imprime_lesao_arq_busca(p->lesoes[i], file);                
            }
            
        }
        fclose(file);
        
    } else {
        printf("CARTAO SUS NAO ENCONTRADO NA BASE DE DADOS\n");
    }
}

/*

    -MONTANDO O RELATORIO

*/

float calcula_porcentagem (int parte, int total) {
    if (total == 0)
        return 0;
    return (float)(parte * 100) / total;
}

float media_idade (tPad *p) {
    float media = 0;

    for (int i = 0; i < p->num_pacientes; i++) {
        media += retorna_idade(p->pacientes[i]);
    }
    media /= p->num_pacientes;
    return media;
}

float desvio_padrao_idade (tPad *p, float media) {
    float soma_quadrados = 0;

    for (int i = 0; i < p->num_pacientes; i++) {
        soma_quadrados += pow (retorna_idade(p->pacientes[i]) - media, 2);
    }
    return sqrt(soma_quadrados / p->num_pacientes);
}

float tamanho_medio_lesoes (tPad *p) {
    float media = 0;

    for (int i = 0; i < p->num_lesoes; i++) {
        media += retorna_tamanho_lesao(p->lesoes[i]);
    }
    media = media / p->num_lesoes;
    return media;
}

float desvio_padrao_tamanho (tPad *p, float media) {
    float soma_quadrados = 0, desvio_padrao;

    for (int i = 0; i < p->num_lesoes; i++) {
        soma_quadrados += pow(retorna_tamanho_lesao(p->lesoes[i]) - media, 2);
    }

    desvio_padrao = sqrt(soma_quadrados / p->num_lesoes);
    return desvio_padrao;
}

void imprime_diagnostico_ordenado (tPad *p, FILE *file) {
    int tipos_diagnosticos[NUM_DIAGNOSTICOS_POSSIVEIS][2];
    //O PRIMEIRO INDICE EH O ID DO DIAGNOSTICO E O SEGUNDO A QUANTIDADE

    //ATRIBUINDO OS ID E ZERANDO A QUANTIDADE
    for (int i = 0; i < NUM_DIAGNOSTICOS_POSSIVEIS; i++) {
        if (i == CARC_BASOCELULAR) {
            tipos_diagnosticos[i][0] = CARC_BASOCELULAR;
            tipos_diagnosticos[i][1] = 0;
        } else if (i == CARC_ESPINOCELULAR) {
            tipos_diagnosticos[i][0] = CARC_ESPINOCELULAR;
            tipos_diagnosticos[i][1] = 0;
        } else if (i == MELANOMA) {
            tipos_diagnosticos[i][0] = MELANOMA;
            tipos_diagnosticos[i][1] = 0;
        } else if (i == CER_ACTINICA) {
            tipos_diagnosticos[i][0] = CER_ACTINICA;
            tipos_diagnosticos[i][1] = 0;
        } else if (i == CER_SEBORREICA) {
            tipos_diagnosticos[i][0] = CER_SEBORREICA;
            tipos_diagnosticos[i][1] = 0;
        } else {
            tipos_diagnosticos[i][0] = NEVO;
            tipos_diagnosticos[i][1] = 0;
        }
    }

    //CONTABILIZANDO
    for (int i = 0; i < p->num_lesoes; i++) {
        if (identifica_lesao(p->lesoes[i]) == CARC_BASOCELULAR)
           tipos_diagnosticos[CARC_BASOCELULAR][1] += 1;
        else if (identifica_lesao(p->lesoes[i]) == CARC_ESPINOCELULAR)
            tipos_diagnosticos[CARC_ESPINOCELULAR][1] += 1;
        else if (identifica_lesao(p->lesoes[i]) == MELANOMA)
            tipos_diagnosticos[MELANOMA][1] += 1;
        else if (identifica_lesao(p->lesoes[i]) == CER_ACTINICA)
            tipos_diagnosticos[CER_ACTINICA][1] += 1;
        else if (identifica_lesao(p->lesoes[i]) == CER_SEBORREICA)
            tipos_diagnosticos[CER_SEBORREICA][1] += 1;
        else
            tipos_diagnosticos[NEVO][1] += 1;
    }


    //ORDENAR A MATRIZ DE ACORDO COM A QUANTIDADE DO SEGUNDO INDICE
    for (int i = 0; i < NUM_DIAGNOSTICOS_POSSIVEIS - 1; i++) {
        for (int j = 0; j < NUM_DIAGNOSTICOS_POSSIVEIS- i - 1; j++) {
            if (tipos_diagnosticos[j][1] < tipos_diagnosticos[j + 1][1]) {
                // Trocar as linhas da matriz
                int tempCodigo = tipos_diagnosticos[j][0];
                int tempQuantidade = tipos_diagnosticos[j][1];
                tipos_diagnosticos[j][0] = tipos_diagnosticos[j + 1][0];
                tipos_diagnosticos[j][1] = tipos_diagnosticos[j + 1][1];
                tipos_diagnosticos[j + 1][0] = tempCodigo;
                tipos_diagnosticos[j + 1][1] = tempQuantidade;
            }
        }
    }


    //IMPRIMIR SOMENTE O QUE FOR MAIOR QUE ZERO
    for (int i = 0; i < NUM_DIAGNOSTICOS_POSSIVEIS; i++) {
        float porcentagem = calcula_porcentagem(tipos_diagnosticos[i][1], p->num_lesoes);

        if (tipos_diagnosticos[i][0] == CARC_BASOCELULAR) 
            fprintf(file, "- CARCINOMA BASOCELULAR: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);
        else if (tipos_diagnosticos[i][0] == CARC_ESPINOCELULAR) 
            fprintf(file, "- CARCINOMA ESPINOCELULAR: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);
        else if (tipos_diagnosticos[i][0] == MELANOMA) 
            fprintf(file, "- MELANOMA: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);
        else if (tipos_diagnosticos[i][0] == CER_ACTINICA) 
            fprintf(file, "- CERATOSE ACTINICA: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);
        else if (tipos_diagnosticos[i][0] == CER_SEBORREICA) 
            fprintf(file, "- CERATOSE SEBORREICA: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);            
        else if (tipos_diagnosticos[i][0] == NEVO)
            fprintf(file, "- NEVO: %d (%.2f%%)\n", tipos_diagnosticos[i][1], porcentagem);

    }
}

void relatorio_final (tPad *p, const char * caminho) {
    char caminhoCompleto[100];
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/relatorio/relatorio_final", caminho);

    FILE *file = fopen(caminhoCompleto, "w");

    int cont_atendidos = 0;
    for (int i = 0; i < p->num_pacientes; i++) {
        if (verifica_consulta(p->pacientes[i]) == VERDADEIRO)
            cont_atendidos++;
    }
    fprintf(file, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", cont_atendidos);

    //MEDIA DE IDADE
    float media_de_idade = 0;
    int dp_idade = 0;

    if (p->num_pacientes > 0) {
        media_de_idade = media_idade(p);
        dp_idade = (int)desvio_padrao_idade(p, media_de_idade);
    }
    fprintf(file, "IDADE MEDIA: %d +- %d ANOS\n", (int)media_de_idade, dp_idade);

    //CALCULANDO A QUANTIDADE DE CADA GENERO
    int genero_fem = 0, genero_mas = 0, genero_out = 0;
    for (int i = 0; i < p->num_pacientes; i++) {
        int g = identifica_genero(p->pacientes[i]);
        
        if (g == GENERO_FEMININO) 
            genero_fem++;
        else if (g == GENERO_MASCULINO) 
            genero_mas++;
        else 
            genero_out++;
        
    }    
    fprintf(file, "DISTRIBUICAO POR GENERO:\n");
    fprintf(file, "- FEMININO: %.2f%%\n", calcula_porcentagem(genero_fem, p->num_pacientes));
    fprintf(file, "- MASCULINO: %.2f%%\n", calcula_porcentagem(genero_mas, p->num_pacientes));
    fprintf(file, "- OUTROS: %.2f%%\n", calcula_porcentagem(genero_out, p->num_pacientes));


    //CALCULANDO TAMANHO MEDIO DAS LESOES E QUANTIDADE DE CIRURGIAS E CRIOTERAPIAS
    int total_cirurgias = 0, total_crioterapias = 0, media_tamanho = 0, dp_tamanho = 0;
    float porcentagem_cirurgias = 0, porcentagem_crioterapias = 0;
    if (p->num_lesoes > 0) {
        media_tamanho = tamanho_medio_lesoes(p);

        for (int i = 0; i < p->num_lesoes; i++) {
            if (verifica_cirurgia(p->lesoes[i]) == VERDADEIRO) 
                total_cirurgias++;
            else if (verifica_crioterapia(p->lesoes[i]) == VERDADEIRO) 
                total_crioterapias++;
        }
            
        dp_tamanho = (int)desvio_padrao_tamanho(p, media_tamanho);
        porcentagem_cirurgias = calcula_porcentagem(total_cirurgias, p->num_lesoes);
        porcentagem_crioterapias = calcula_porcentagem(total_crioterapias, p->num_lesoes);
    }

    fprintf(file, "TAMANHO MEDIO DAS LESOES: %d +- %d MM\n", media_tamanho, dp_tamanho);
    fprintf(file, "NUMERO TOTAL DE LESOES: %d\n", p->num_lesoes);
    fprintf(file, "NUMERO TOTAL DE CIRURGIAS: %d (%.2f%%)\n", total_cirurgias, porcentagem_cirurgias);
    fprintf(file, "NUMERO TOTAL DE CRIOTERAPIA: %d (%.2f%%)\n", total_crioterapias, porcentagem_crioterapias);

    fprintf(file, "DISTRIBUICAO POR DIAGNOSTICO:\n");
    imprime_diagnostico_ordenado(p, file);

    fclose(file);
}

void free_pad (tPad *p) {
    for (int i = 0; i < p->num_pacientes; i++)
        free_paciente(p->pacientes[i]);
    
    for (int i = 0; i < p->num_lesoes; i++)
        free_lesao(p->lesoes[i]);
    
    for (int i = 0; i < p->num_historicos; i++)
        free_historico(p->historico_medico[i]);
    
    free(p->pacientes);
    free(p->lesoes);
    free(p->historico_medico);
    free(p);
}