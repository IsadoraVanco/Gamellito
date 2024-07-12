#ifndef SENHA_H
#define SENHA_H

#include <QDialog>
#include <QInputDialog>

namespace Ui {
class Senha;
}

class Senha : public QDialog
{
    Q_OBJECT

public:

    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    explicit Senha(QWidget *parent = nullptr);

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~Senha();

    // *** AUTENTICAÇÃO  *********************************************************

    /**
     * @brief ehSenhaValida
     * @param senha
     * @return
     */
    bool ehSenhaValida(QString senha);

    /**
     * @brief compararSenha
     * @param input
     * @return
     */
    bool compararSenha(QString input);

    /**
     * @brief autenticarSenha
     * @return
     */
    bool autenticarSenha();

    // *** ALTERAÇÃO *********************************************************

    /**
     * @brief criarCaixaDialogoSenha
     * @param titulo
     * @param texto
     * @return
     */
    QInputDialog *criarCaixaDialogoSenha(QString titulo, QString texto);

    /**
     * @brief definirSenha
     * @param textoInicio
     * @param verificarTamanho
     * @return
     */
    QString definirSenha(QString texto);

    /**
     * @brief alterarSenha
     */
    void alterarSenha();

    /**
     * @brief carregarSenha
     */
    void carregarSenha();

private:
    /* ************************************************************
     * CONSTANTES E ATRIBUTOS
     *************************************************************/

    int tamanhoMinSenha = 4;
    QString senhaArquivo = "";
};

#endif // SENHA_H
