# Projeto Gamellito (carinhosamente "HC")

A ideia do projeto é construir um reprodutor de vídeos, que ao final de cada execução, exiba um questionário para reforçar o aprendizado. 

Esse projeto têm como objetivo auxiliar as crianças que possuem condição de diabete, para que entendam e aprendam sobre a doença e como podem cuidar de sua saúde. 

De uma forma mais técnica, o projeto envolve não só código, mas também desafios de hardware, já que a máquina que será utilizada terá poucos recursos de execução. Mais precisamente: um processador Celeron D331 que possui um núcleo de 2.66GHz dos anos 2000 com barramento de 533MHz, 3GB de memória DDR2, com a possibilidade no máximo 1GB de expansão. Carinhosamente, a chamarei de "Dino" para ficar mais fácil.

Pessoalmente, será um grande desafio, já que estou no início da programação, e conciliar o projeto com a grade da faculdade não será nada fácil.

## 1. Ferramentas

### 1.1. Linguagem e biblioteca
Para esta difícil tarefa, irei utilizar a linguagem **C++** e a biblioteca **Qt5** (no momento existe a 6, mas utiliza-lá ocasionaria outros problemas). A IDE utilizada será o **QtCreator**, que é responsável por compilar o código, nele também é muito mais fácil criar as interfaces gráficas.

### 1.2. Virtualização

Como utilizo Windows no dia-a-dia, preciso de uma ferramenta para virtualizar o sistema Linux para compilar o código e testá-lo. Para isso, utilizarei o **VM Virtual Box**.

Cogitei utilizar Docker, mas creio que seria muito para a máquina Dino, além de não ser muito viável para o usuário replicar o programa em outra máquina.

### Ainda para se pensar...
Algumas novidades que podem ajudar (ainda para pesquisar e testar):

* Embedar uma linguagem para uma atividade específica
* IDE para modificar as Interfaces utilizando Drag and Drop
* Utilizar CSV para armazenar os dados selecionados pelo usuário

## 2. Hardware

Por enquanto, a máquina foi desbloqueada para utilizar de sistemas operacionais. Procuro por sistemas Linux que são leves o suficientes para a máquina Dino.

Sistemas testados até o momento (na máquina Dino):
- **Linux Mint XFCE versão Vera (64 bits)** => O sistema é pesado para a máquina. Vídeos em HD rodam até bem, mas em fullHD não tem um bom desempenho.
- **Lubuntu 22.04 (64bits)** => Sistema leve, rodou tranquilamente os testes e vídeos.
- **Q4OS (64bits)** => Sistema leve, rodou tranquilamente os testes e vídeos.

Testar outros Linux mais leves. OBS: Pode ser que haja incompatiblidade de bibliotecas 
- Bodhi Linux
- Xubuntu
- Puppy Linux
- AntiX
- outros...

* Formatar o HD utilizando software