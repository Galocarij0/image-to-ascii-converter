#!/bin/bash

SRC="src/main.c"
BIN="bin/IMG_to_ASCII.exe"
IMG_PADRAO="imagens_entrada/rice_shower_baby.png"

echo " -- INICIANDO AUTOMAÇÃO 🚀 -- "

if [ ! -d "bin" ]; then
    echo "📂 pasta 'bin' não encontrada, criando...."
    mkdir bin
fi

echo " -- COMPILANDO $SRC 🛠 --"

gcc $SRC -lm -o $BIN

if [ $? -eq 0 ]; then
    echo "✅ Compilação finalizada com êxito !"
    echo "🖼 Criando Arte ASCII..."
    echo "----------------------------------------------------------------------"

    ./$BIN "$IMG_PADRAO"
else 
    echo " ❌ Erro Fatal: Não foi possível compilar o programa"
    exit 1
fi 
echo "----------------------------------------------------------------------"
echo "🏁 Processo encerrado !"