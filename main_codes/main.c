#define STB_IMAGE_IMPLEMENTATION
#include "lib\stb_image.h"

#include <stdio.h>

int main(){
    
    // Declaração das variáveis da imagem
    int pLargura, pAltura, pQuant_canais;
    unsigned char *data = stbi_load("shower_baby.png", &pLargura, &pAltura, &pQuant_canais, 3); // Fixação dos valores

    
    // Printa os valores que acl função stbi_load() econtrou acima
    printf("%d %d %d \n",pLargura, pAltura, pQuant_canais);


    
    extern void stbi_image_free(void *retval_from_stbi_load); // limpa a imagem pra evitar memory leak
    return 0;
}