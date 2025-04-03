#include <cstdio>

class Celula
{
    friend class Pilha;

public:
    void escrever (const char *sep = ", "); // esse sep é pra separar os dados entre os prints, sendo por padrão ", "
    Celula(int chave);
    Celula();

private:
    int chave;
    Celula *prox;
};

void Celula::escrever (const char *sep){
    printf("%d%s", this->chave , sep);
};

Celula::Celula(int chave){
    this->chave = chave;
    this->prox = nullptr; //Null pointer (uma nova semantica de um null que é ponteiro)
};

class Pilha{
    public:
        void empilhar(int chave);
        int desempilhar (void);
        void escrever ();
        bool vazia(void);
        Pilha (); //construtor
        ~Pilha (); //destrutor (limpa o objeto antes de ser destruido)

    private:
        Celula *topo;
        };
void Pilha::empilhar (int chave){
    Celula *c = new Celula(chave); // como se fosse um Malloc

    c->prox = topo->prox;
    topo->prox = c;
};

int Pilha::desempilhar(void){
    int chave;
    Celula *p;

    p = topo->prox;

    topo->prox = p->prox;
    //... nao terminei de digitar
    }
    Pilha::Pilha() // construtor
    {
        topo = new Celula();
    }

    Pilha::~Pilha(){
        while(!vazia())
            desempilhar();
        delete topo;
    }

    bool Pilha::vazia(){
        
    }


// Celula c1(2); --> cria um objeto da classe celula chamado c1, e o construtor vai lá e coloca o valor 2 em "chave"
// c1 --> [2]chave e [.]prox->null (um agrupamento )
//c1.escreve("--"); --> vai ter um ponteiro que aponta pra "--" (uma literal de prog2)
// agora o ponteiro this é um ponteiro que sempre aponta para o objeto que eu estou dentro, o objeto é como se fosse
// um agrupamento de dados(registro de C) que existe dentro de uma classe, ele tem todas as variaveis e metodos da classe

//entao, this->chave é a mesma coisa que eu pegar o valor de chave dentro do objeto c1 (caso eu esteja mechendo nele)
