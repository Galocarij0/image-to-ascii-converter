#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>

int main(){
    
    int largura, altura, quant_canais;
    stbi_load("cat-uncanny.jpeg", largura, altura, quant_canais, 0);

    printf("L:%d, A:%d, C:%d", largura, altura, quant_canais);

    return 0;
}