#!/bin/bash

# Utilize "chmod +x install_libs_qt.sh" 
# Ou configure com mouse e menu de opções
# Para que este arquivo seja reconhecido como executável
echo -e "### INICIANDO INSTALACAO DO GAMELLITO ###"
echo -e "\n"
echo -e "Este instalador utiliza comandos para sistemas linux"
echo -e "baseados em Debian, caso esteja utilizando outra distribuicao"
echo -e "o instalador nao ira funcionar."
echo -e "Observacoes:"
echo -e "1. O programa sera instalado na pasta do usuario."
echo -e "2. Verifique se os arquivos .sh estao disponiveis:"
echo -e "- iniciar_gamellito.sh"
echo -e "- gamellito.sh"
echo -e "- install_libs_qt.sh"
echo -e "3. Verifique se ha conexao com a internet"
echo -e "\n"

continuar=0

while [ $continuar == 0 ]; do
    read -p "Podemos continuar? [sim/nao] " yn
    case $yn in
        [Ss][Ii][Mm] ) continuar=1; break;;
        [Nn][Aa][Oo] ) exit;;
    esac
done

# 1. Copiando arquivos do programa para o sistema

PASTA_ORIGEM="Gamellito"
DIR_ATUAL="$(cd "$(dirname "$0")" && pwd)"

# Caminho completo da pasta de origem
CAMINHO_ORIGEM="$DIR_ATUAL/$PASTA_ORIGEM"

# Caminho de destino na pasta do usuário
PASTA_USUARIO="$HOME"

if [ ! -d "$CAMINHO_ORIGEM" ]; then
    echo "A pasta $PASTA_ORIGEM nao foi encontrada!"
    exit 1
fi

# Copia a pasta para o destino (pasta do usuário)
echo "Copiando $CAMINHO_ORIGEM para $PASTA_USUARIO..."
cp -r "$CAMINHO_ORIGEM" "$PASTA_USUARIO"

# Verifica se a cópia foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "### ARQUIVOS COPIADOS COM SUCESSO ###"
else
    echo "### FALHA AO COPIAR ARQUIVOS ###"
fi

sudo chmod +x $PASTA_USUARIO/$PASTA_ORIGEM/Gamellito

# 2. Copiando os arquivos executaveis

ARQUIVO_INICIALIZADOR="iniciar_gamellito.sh"
ATALHO_EXECUTAVEL="gamellito.sh"

if [ ! -f "$ATALHO_EXECUTAVEL" ]; then
    echo "O arquivo '$ATALHO_EXECUTAVEL' nao foi encontrado!"
    exit 1
fi

if [ ! -f "$ARQUIVO_INICIALIZADOR" ]; then
    echo "O arquivo '$ARQUIVO_INICIALIZADOR' nao foi encontrado!"
    exit 1
fi

# Copia os arquivos
echo "Copiando executaveis..."
cp -r "$ARQUIVO_INICIALIZADOR" "$PASTA_USUARIO"
sudo chmod +x $PASTA_USUARIO/$ARQUIVO_INICIALIZADOR

if [ -d $PASTA_USUARIO/Área\ de\ trabalho ]; then
    cp -r "$ATALHO_EXECUTAVEL" $PASTA_USUARIO/Área\ de\ trabalho
    sudo chmod +x $PASTA_USUARIO/Área\ de\ trabalho/$ATALHO_EXECUTAVEL
else
    cp -r "$ATALHO_EXECUTAVEL" "$PASTA_USUARIO/Desktop"
    sudo chmod +x $PASTA_USUARIO/Desktop/$ATALHO_EXECUTAVEL
fi

# 3. Criando arquivo de inicialização

# Cria o arquivo de serviço para systemd
SERVICE_FILE="$HOME/.config/systemd/user/gamellito.service"
mkdir -p "$(dirname "$SERVICE_FILE")"

echo "### Criando arquivo de serviço em $SERVICE_FILE ###"

cat > "$SERVICE_FILE" << EOL
[Unit]
Description=Inicia o Gamellito
After=graphical-session.target

[Service]
ExecStart=$PASTA_USUARIO/$ARQUIVO_INICIALIZADOR
Environment=DISPLAY=:0
Restart=on-failure

[Install]
WantedBy=default.target
EOL

# Habilita o serviço para iniciar na sessão do usuário
echo "### Habilitando o serviço ###"
systemctl --user enable gamellito.service

# Inicia o serviço para testar
systemctl --user start gamellito.service

# Confirmação final da configuração
echo "### CONFIGURACAO CONCLUIDA! O PROGRAMA SERA INICIADO AO LIGAR O SISTEMA ###"

# 4. Instalando bibliotecas do Qt

sudo chmod +x install_libs_qt.sh
./install_libs_qt.sh