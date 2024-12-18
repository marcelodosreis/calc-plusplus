#!/bin/bash

source ./scripts/config/colors.sh
source ./scripts/config/messages.sh

if [ -d "build" ]; then
    display_message "${CYAN}" "Removendo diretório 'build' existente..."
    rm -rf build
    display_message "${CYAN}" "Diretório 'build' removido com sucesso!"
fi

display_message "${CYAN}" "Criando diretório 'build'..."
mkdir build
display_message "${CYAN}" "Diretório 'build' criado com sucesso!"

cd build

display_message "${BLUE}" "Executando cmake para configurar..."
cmake ..

display_message "${GREEN}" "Compilando com make..."
make

display_message "${YELLOW}" "Executando testes..."
ctest --verbose --output-on-failure

display_message "${MAGENTA}" "Processo concluído!"
cd ..
