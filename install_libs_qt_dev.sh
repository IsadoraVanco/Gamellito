#!/bin/bash

# Utilize "chmod +x install_libs_qt.sh" 
# Ou configure com mouse e menu de opções
# Para que este arquivo seja reconhecido como executável
echo -e "### INICIANDO INSTALACAO DOS PACOTES QT DEV ###"
echo -e "\n"
echo -e "Verifique se voce possui uma conexao com a internet"
echo -e "antes de prosseguir."
echo -e "Este instalador utiliza comandos para sistemas linux"
echo -e "baseados em Debian, caso esteja utilizando outra distribuicao"
echo -e "o instalador nao ira funcionar."
echo -e "\n"

continuar=0

while [ $continuar == 0 ]; do
    read -p "Podemos continuar? [sim/nao] " yn
    case $yn in
        [Ss][Ii][Mm] ) continuar=1; break;;
        [Nn][Aa][Oo] ) exit;;
    esac
done

# Atualiza a lista de pacotes
sudo apt update

# Instala os pacotes para compilar 
sudo apt install -y cmake build-essential g++

# Instala os pacotes para reconhecimento do codigo qt 
sudo apt install -y qtbase5-dev qtmultimedia5-dev

echo -e "\n"
# Verifica se a instalação foi bem-sucedida
if [ $? == 0 ]; then
    echo -e "### PACOTES INSTALADOS COM SUCESSO! ###"
else
    echo -e "### FALHA NA INSTALACAO DOS PACOTES ###"
fi