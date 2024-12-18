#!/bin/bash

source ./scripts/config/colors.sh
source ./scripts/config/messages.sh

TEMP_DIR="./temp"

if [ ! -d "$TEMP_DIR" ]; then
    display_message "${CYAN}" "Criando pasta temporária..."
    mkdir "$TEMP_DIR"
fi

display_message "${GREEN}" "Compilando o código..."

g++ src/main.cpp -o "$TEMP_DIR/calc-plusplus" -std=c++17

if [ $? -eq 0 ]; then
    display_message "${BLUE}" "Compilação bem-sucedida! Executando o projeto...\n"
    display_message "${CYAN}" "Output:"
    "$TEMP_DIR/calc-plusplus"

    display_message "${MAGENTA}" "\nApagando pasta temporária..."
    rm -rf "$TEMP_DIR"
else
    display_message "${RED}" "Erro na compilação!"
    rm -rf "$TEMP_DIR"
fi
