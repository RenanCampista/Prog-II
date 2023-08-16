#include <stdio.h> 
#include "vector.h" 
 
int main(){ 
    Vector *v = vector_create(); 
    int qntdNumeros; 
 
    scanf("%d", &qntdNumeros); 
 
    for(int i = 0; i < qntdNumeros; i++){ 
        vector_add(v, &i); 
        vector_print(v); 
    } 
 
    vector_remove(v, qntdNumeros - 1); 
    vector_print(v); 
 
    vector_destroy(v); 

    return 0;

}