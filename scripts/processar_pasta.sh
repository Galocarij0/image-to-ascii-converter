#!/bin/bash

mkdir -p resultados
mkdir -p bin

gcc src/main.c -lm -o bin/IMG_to_ASCII.exe

for imagem in imagens_entrada/*.png; do
    nome_da_imagem=$(basename "$imagem" .png)
    echo "🔁 Convertendo $nome_da_imagem..."

    ./bin/IMG_to_ASCII.exe "$imagem" > "resultados/${nome_da_imagem}.txt"
done

echo "✅ Tudo pronto ! Verifique a pasta de 'resultados' para encontrar a sua arte ASCII !."
