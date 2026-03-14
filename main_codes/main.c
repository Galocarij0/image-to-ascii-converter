#define STB_IMAGE_IMPLEMENTATION
#include "lib\stb_image.h"

#include <stdio.h>

char pegarCaractere(int linhaAtual, int pLargura, int colunaAtual, unsigned char *dados_da_imagem){
    
    int index= (linhaAtual * pLargura + colunaAtual) * 3;
    float luminosidade = ((0.02126 * dados_da_imagem[index]) + (0.7152 * dados_da_imagem[index + 1]) + (0.0722 * dados_da_imagem[index + 2]));
    char *caracteres = " :-=+*#%@";
    int mapaInt = (int)((luminosidade / 255.0 ) * 8);
    return caracteres[mapaInt];
}

int main(int argc, char* argv[]){


    if (argc < 2){
        printf("Uso correto %s nome_da_imagem.png \n", argv[0]);
        return 1;
    }

    FILE *arquivo_para_ler = fopen(argv[1],"r");
    
    if (arquivo_para_ler == NULL){
        printf("Arquivo nao encontrado \nVerifique se o arquivo existe e se eh um formato suportado (JPG, PNG, etc.)\n", arquivo_para_ler);
        return 1;
    }   else {
        fclose(arquivo_para_ler);
    }
    
    int pLargura, pAltura, pQuant_canais;

    unsigned char *dados_da_imagem = stbi_load(argv[1], &pLargura, &pAltura, &pQuant_canais, 3); 

    for (int linhaAtual = 0; linhaAtual < pAltura; linhaAtual += 5){ 
        for ( int colunaAtual = 0; colunaAtual < pLargura; colunaAtual += 4){

            char p = pegarCaractere(linhaAtual, pLargura, colunaAtual, dados_da_imagem);
            printf ("%c%c", p, p);

        }
        printf("\n");  
    }
    stbi_image_free(dados_da_imagem);
    return 0;
}
