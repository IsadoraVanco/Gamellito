#include <QMessageBox>

#include "senha.h"
#include "arquivos.h"


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Senha::Senha(QWidget *parent): QDialog(parent){}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Senha::~Senha(){}

// *** AUTENTICAÇÃO  *********************************************************

bool Senha::ehSenhaValida(QString senha){
    return senha.length() >= tamanhoMinSenha;
}

bool Senha::compararSenha(QString input){
    return senhaArquivo == input;
}

bool Senha::autenticarSenha(){
    // A senha do arquivo estará necessariamente carregada em "senhaArquivo"!

    // Configura a caixa de diálogo para a senha
    QInputDialog *dialogSenha = criarCaixaDialogoSenha("Autenticação", "Digite a senha para acessar as configurações:");
    dialogSenha->exec();

    QString input = dialogSenha->textValue();

    bool senhaVerificada = compararSenha(input);

    // Senha não digitada ou botão "cancelar"
    if(input != "" && !senhaVerificada){
        QMessageBox::about(this, "Senha incorreta", "A senha digitada está incorreta. Caso tenha perdido a senha, consulte o manual do programa ou entre em contato com o suporte.");
    }

    return senhaVerificada;
}

// *** ALTERAÇÃO *********************************************************

QInputDialog *Senha::criarCaixaDialogoSenha(QString titulo, QString texto){
    QInputDialog *dialogSenha = new QInputDialog();

    dialogSenha->setTextEchoMode(QLineEdit::Password);
    dialogSenha->setWindowTitle(titulo);
    dialogSenha->setLabelText(texto);

    dialogSenha->setStyleSheet("QDialogButtonBox{ background-color: #FF7439; color: white; border: none}" "QLineEdit{background-color: #D9D9D9; border: #D9D9D9 10px; border-radius: 5px; color: black;}" "QInputDialog{background-color: white; color: black; font-size: 14px;}" );

    return dialogSenha;
}

QString Senha::definirSenha(QString texto){

    // Configura a caixa de diálogo para a senha
    QInputDialog *dialogSenha = criarCaixaDialogoSenha("Definição de senha", texto);
    dialogSenha->exec();

    QString input = dialogSenha->textValue();

    while(!ehSenhaValida(input)){
        dialogSenha->setLabelText(QString("Senha muito curta! Utilize no mínimo %1 caracteres quaisquer").arg(tamanhoMinSenha));
        dialogSenha->exec();
        input = dialogSenha->textValue();

        if(ehSenhaValida(input)){
            break;
        }
    }

    QMessageBox::about(this, "Senha cadastrada", "Sua senha foi cadastrada com sucesso! Não a esqueça e não conte para ninguém :)");

    // Atualiza a nova senha
    senhaArquivo = input;
    return input;
}

void Senha::alterarSenha(){
    // Configura a caixa de diálogo para a senha
    QInputDialog *dialogSenha = criarCaixaDialogoSenha("Alterar senha", "Digite sua nova senha:");
    dialogSenha->exec();

    QString novaSenha = dialogSenha->textValue();

    if(ehSenhaValida(novaSenha)){
        // Salva a senha no arquivo
        senhaArquivo = novaSenha;
        Arquivos::alterarSenha(novaSenha);

        qDebug() << "[Senha][INFO] Senha alterada:" << senhaArquivo;

        QMessageBox::about(this, "Senha cadastrada", "Sua nova senha foi cadastrada com sucesso!");
    }else if(novaSenha != ""){
        QMessageBox::about(this, "Senha muito curta", QString("Senha muito curta! Utilize no mínimo %1 caracteres quaisquer").arg(tamanhoMinSenha));
    }
}

void Senha::carregarSenha(){
    // Carrega a senha do arquivo
    senhaArquivo = Arquivos::carregarSenha();

    qDebug() << "[Senha][INFO] Senha atual:" << senhaArquivo;

    // Caso a senha tenha sido alterada, ou houve algum erro ao carregar
    if(!ehSenhaValida(senhaArquivo)){
        definirSenha("Ops! Parece que sua senha não está definida. Por favor, defina uma nova senha: ");
        // Salva a senha no arquivo
        Arquivos::alterarSenha(senhaArquivo);
    }
}
