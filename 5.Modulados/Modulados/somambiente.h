#ifndef SOMAMBIENTE_H
#define SOMAMBIENTE_H

// Tratamento de String
#include <QString>

// Para o som ambiente
#include <QtMultimedia/QSound>

// Para manipular diretorios
#include <QFile>
#include <QDir>

// Para debugar
#include <QDebug>

class SomAmbiente
{
public:

    /* ************************************************************
     * CONSTRTUTOR
     *************************************************************/

    SomAmbiente();

    /* ************************************************************
     * CONFIGURAÇÕES
     *************************************************************/

    /**
     * @brief Configura o arquivo que será reproduzido
     * @param nomeArquivo O nome do arquivo
     * @return true caso tenha sido concluído com sucesso, false para caso contrário
     */
    bool configurar(QString nomeArquivo);

    /**
     * @brief Liga o som
     */
    void ligar();

    /**
     * @brief Desliga o som
     */
    void desligar();

    /**
     * @brief Verifica se o som está mutado
     * @return True caso esteja mutado, false para caso conrário
     */
    bool estaMutado();

private:
    QSound *som;
    bool mutado = false;
};

#endif // SOMAMBIENTE_H
