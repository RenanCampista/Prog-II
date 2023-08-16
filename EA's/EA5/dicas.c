
/*void ler_arqv_imagem (tImagem *img, FILE *file) {
    fread (&img->l, sizeof(int), 1, file);
    fread (&img->c, sizeof(int), 1, file);
    //Como tem que passa ponteiro, entao usa & para endenreco de memoria
    //

    fread (&img->tipo, sizeof(int), 1, file);

    img->pixels = (int *) realloc (img->pixels, (img->c * img->l) * sizeof(int));

    fread(img->pixels, sizeof(int), img->c * img->l, file);
}*/

//Leitura
//FILE *file = fopen("img-1-int.bin", "rb");

//Escrita
//FILE *file = fopen("img-1-int.bin", "rw");


//Escreve (salvar) dados
//
/*void salvar_dados_pessoa (tPessoa *p, FILE *file) {
    fwrite(p, sizeof(tPessoa), 1, file);
    
    //struct ponteiro
    //tamanho da struct
    //quantidade
    //file
}*/