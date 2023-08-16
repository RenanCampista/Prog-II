#include <stdio.h> 
#include "vector.h" 
 
int main(){ 
    Vector *v = vector_create(); 
 
    int qntdNumeros; 
 
    scanf("%d", &qntdNumeros); 
 
    for(int i = 0; i < qntdNumeros; i++){ 
        vector_add(v, &i, 0); 
        vector_print(v); 
    } 
 
    char c = 'c'; 
    double d = 3.0; 
    float f = 4.5; 
  
    vector_add(v, &c, CHAR); 
    vector_add(v, &d, DOUBLE); 
    vector_add(v, &f, FLOAT);

    vector_print(v); 
    vector_remove(v, qntdNumeros + 2); 
    vector_print(v); 
 
    vector_destroy(v); 

    return 0;
}