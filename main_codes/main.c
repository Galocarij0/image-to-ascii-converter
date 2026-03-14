#define STB_IMAGE_IMPLEMENTATION
#include "lib\stb_image.h"

#include <stdio.h>

int main(int argc, char* argv[]){


    if (argc < 2){
        printf("Uso correto %s nome_da_imagem.png \n", argv[0]);
        return 1;
    }

    int pLargura, pAltura, pQuant_canais;

    unsigned char *dadosImagem = stbi_load(argv[1], &pLargura, &pAltura, &pQuant_canais, 3);
    if (dadosImagem == NULL){
        printf("NAO SEI O QUE TA ROLANDO MAS NAO TA CARREGANDO A TUA IMAGEM NAO BROTHER \n");
        return 1;
    } 

    for (int linhaAtual = 0; linhaAtual < pAltura; linhaAtual += 5){ 
        for ( int colunaAtual = 0; colunaAtual < pLargura; colunaAtual += 4){
            
            int index= (linhaAtual * pLargura + colunaAtual) * 3;
            
            float luminosidade = ((0.02126 * dadosImagem[index]) + (0.7152 * dadosImagem[index + 1]) + (0.0722 * dadosImagem[index + 2]));
            
            char *caracteres = " :-=+*#%@";

            float mapaLuminosidade = ((luminosidade / 255.0 ) * 9);
            
            int mapaLuminosidadeInt = mapaLuminosidade;

            printf ("%c %c", caracteres[mapaLuminosidadeInt], caracteres[mapaLuminosidadeInt]);

        }
        printf("\n");  
    }

    stbi_image_free(dadosImagem);
    return 0;
}