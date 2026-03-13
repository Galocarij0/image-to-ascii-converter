#define STB_IMAGE_IMPLEMENTATION
#include "lib\stb_image.h"

#include <stdio.h>

int main(){
    
    // Declaração das variáveis da imagem
    int pLargura, pAltura, pQuant_canais;
    unsigned char *data = stbi_load("shower_baby.png", &pLargura, &pAltura, &pQuant_canais, 3); // Fixação dos valores


    // Printa os valores que acl função stbi_load() econtrou acima
    printf("%d %d %d \n",pLargura, pAltura, pQuant_canais);

    for (int i = 0; i < pAltura; i++){
        for ( int j = 0; j < pLargura; j++){
            
            // logica de mapeamento de array 1d (data) para array 2d (index)
            int index= (i * pLargura + j) * 3;
            
            // trasnforma os valores rgb anteriores em um unico valor de luminosidade
            float luminosidade = ((0.02126 * data[index]) + (0.7152 * data[index + 1]) + (0.0722 * data[index + 2]));
            
            char *caracteres = "@%#*+=-:. ";

            // Coloca o "nivel" de luminosidade entre 0.00 e 9.00 (para os 9 caracteres que iremos usar)
            float indiceAscii = ((luminosidade / 255.0 ) * 9);
            
            // Transforma o indiceAscii de float para int (pra poder ser um index dos caracteres)
            int castedIndiceAscii = indiceAscii;

            printf ("%c", caracteres[castedIndiceAscii]);

            // printf("%c", caracteres[indiceAscii]);
        }
        printf("%\n");
    }

    stbi_image_free(data); // limpa a imagem pra evitar memory leak
    return 0;
}