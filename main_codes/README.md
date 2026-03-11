# Conversor de Imagem para Arte ASCII

Este é o meu primeiro projeto real de programação, e pra isso, eu decidi fazer um conversor escrito em **C** que transforma imagens comuns (JPG, PNG, etc.) em representações de texto (ASCII Art).

## 📌 - OBJETIVO:
O Projeto visa colocar em prática conceitos fundamentais de Ciência da Computação:
- Manipulação de ficheiros e buffers de memória
- Processamento de matrizes de pixels
- Uso de Bibliotecas em C (stb_image.h)
- Aritmética de cores e conversão para escala de cinza

## 🛠 - TECNOLOGIAS E FERRAMENTAS:
- **Linguagem:** C
- **Biblioteca de Imagem:** [stb_image.h](https://github.com/nothings/stb) (single-header library)
- **Controle de Versão:** Git e GitHub
- **Compilador:** gcc

## 📋 - COMO FUNCIONA:
1. **Carregamento:** A imagem é carregada na memória como um array de bytes (RGB).
2. **Escala de Cinza:** Cada pixel é convertido para um valor de luminosidade.
3. **MapeamentoL** O valor do brilho (0-255) é mapeado para um caractere ASCII (ex: '@' para escuro e '-' para claro).
4. **Output:** A arte final é exibido no terminal ou guardada num ficheiro '.txt'.

## ⚙ - COMO EXECUTAR

Para compilar o projeto, use o comando:
`gcc main.c -o conversor -lm`

Para executar o programa (Exemplo):
`./conversor minha_imagem.jpg`

## 🧱 - PROGRESSO:
- [x] Configuração do ambiente e Git
- [x] Integração da biblioteca `stb_image.h`
- [ ] Implementação da leitura de pixels
- [ ] Lógica de Conversão para tons de Cinza
- [ ] Mapeamento de caracteres ASCII