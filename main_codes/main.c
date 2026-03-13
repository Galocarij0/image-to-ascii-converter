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
            
            int index= (i * pLargura + j) * 3;
            printf("%d %d %d \n", data[index], data[index + 1], data[index + 2 ]);
        }
        //int indexAltura = (j *pAltura + i) * 3;
        // printf("%d", pAltura);
    }
    


    stbi_image_free(data); // limpa a imagem pra evitar memory leak
    return 0;
}