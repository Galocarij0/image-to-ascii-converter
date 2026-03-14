#!/bin/bash
shopt -s extglob 

VERDE='\033[0;32m'
AZUL='\033[0;34m'
NOCOLOR='\033[0;0m'

clear
echo -e "${AZUL}=====================================================${NOCOLOR}"
echo -e "${AZUL}   🚀   TRANSFORMANDO IMAGEM EM ARTE ASCII    🚀    ${NOCOLOR}"
echo -e "${AZUL}=====================================================${NOCOLOR}"

mkdir -p resultados
mkdir -p bin

gcc src/main.c -lm -o bin/IMG_to_ASCII.exe || { echo "❌ Erro Fatal: Houve uma falha na compilação :("; exit 1;}

for imagem in imagens_entrada/*.@(png|jpg|jpeg); do
    [ -e "$imagem" ] || continue
    if [ -f "$imagem" ]; then
        nome_da_imagem=$(basename "$imagem" .${imagem##*.})
        nome_da_imagem="${nome_da_imagem%.*}"
        echo -e "🔁 Convertendo ${VERDE}$nome_da_imagem${NOCOLOR}..."

        ./bin/IMG_to_ASCII.exe "$imagem" > "resultados/${nome_da_imagem}.txt"
    fi
done

echo -e "\n${VERDE}✅ Tudo pronto ! Verifique a pasta de 'resultados' para encontrar a sua arte ASCII !${NOCOLOR}."
