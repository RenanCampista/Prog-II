#include <stdio.h> 
#include "pessoas.h"
#include "vector.h" 
 
int main(){ 
    Vector *v = vector_create(); 
 
    Empreiteiro *empreiteiro = empreiteiro_criar("Jose Clodoaldo", 15, 9, 1994, 
"132.456.789-00", 5000); 
    Professor *professor = professor_criar("Cleberson Souza", 20, 3, 2001, 
"111.111.111-11", DOUTORADO); 
    TecAdm *tec = tec_adm_criar("Jonas Silva", 7, 9, 1867, "987.654.321-00"); 
 
    vector_add(v, empreiteiro, EMPREITEIRO); 
    vector_add(v, professor, PROFESSOR); 
    vector_add(v, tec, TECADM); 
 
    vector_print(v); 
 
    vector_destroy(v); 

    return 0;
}