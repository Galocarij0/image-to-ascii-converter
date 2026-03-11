#define STB_IMAGE_IMPLEMENTATION
#include "lib\stb_image.h"

#include <stdio.h>

int main(){
    
    // Declaração das variáveis da imagem
    int largura, altura, quant_canais;
    char* imagem_load = stbi_load("shower_baby.png", &largura, &altura, &quant_canais, 0); // Fixação dos valores

    // Printa os valores que acl função stbi_load() econtrou acima
    printf("Largura: %d pixels, Altura: %d pixels, Canais: %d\n", largura, altura, quant_canais);

    stbi_image_free(stbi_load);
    return 0;
}