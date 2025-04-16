#include <cstdio>
#include <climits>
#include <string>
#include <algorithm>

using std::string;

class Heap
{
public:
  Heap();
  Heap(const int n, const int dados[]);
  Heap(const Heap& outro);
  ~Heap();
  Heap& operator=(const Heap& outro); // esta definindo o que o operador = irá fazer
  void escreve_niveis();
  void escreve(const string& prefixo = "", int i = 0);
  void insere(int p);
  int consulta_maxima();
  int extrai_maxima();
  void altera_prioridade(int i, int p);

  
private:
  int *S;         // Vetor que armazena os elementos da heap
  int n;          // Quantidade de posições ocupadas em S
  int capacidade; // Tamanho de S
  static const int TAMANHO_INICIAL = 4; // Tamanho da 1ª alocação de S, um atributo compartilhado por todos os objetos, ele é estatico, nao muda
  
  int pai(int i);
  int esquerdo(int i);
  int direito(int i);
  void troca(int i, int j);
  void desce(int i);
  void sobe(int i);
};


int main(void)
{
  Heap h; // construtor Heap()
  
  for (int i = 1; i <= 10; i++)
    h.insere(i);
  printf("h:\n");
  h.escreve();

  h.extrai_maxima();
  h.altera_prioridade(0, -3);
  printf("h:\n");
  h.escreve();

  int v[] = {1,2,3,4,5};
  
  Heap h2(5, v); // construtor Heap(int n, int dados[])
  h2.insere(15);
  printf("h2:\n");
  h2.escreve();
    
  Heap h3(h2); // construtor de cópia padrão
  h2.insere(30);
  printf("h3:\n");
  h3.escreve();

  Heap h4 = h2; // construtor de cópia padrão
  h2.insere(40);
  printf("h4:\n");
  h4.escreve();
  
  h = h2; // operador de atribuição, sem constructor ou constructor de cópia
  h.insere(100);his->n = capacidade = n;
  printf("h2:\n");
  h2.escreve();
  printf("h:\n");
  h.escreve();

  h = Heap(5, v); // construtor Heap(int n, int dados[]), seguido de atribuição (de cópia, não transferência (move))
  printf("h:\n");
  h.escreve();

  h.extrai_maxima();
  h.altera_prioridade(0, -2);
  printf("h:\n");
  h.escreve();
    
  return 0;
}

Heap::Heap() {
  S(new int[TAMANHO_INICIAL]),
  n(0),
  capacidade(TAMANHO_INICIAL)
}

Heap::Heap(int n, int dados[]) 
{ 
  S = new int[n];
  std::copy(dados,dados+n, S);
  this->n = capacidade = n;

  for (int i = n/2 - 1; i>=0; i--) //ignora as folhas
    desce(i);

}

Heap::Heap(const Heap& outro) :
  Heap(outro.n,outro.S){ // Construtor de copia, copia uma heap em outra e passa o n , e o S
  }

Heap& Heap::operator=(const Heap& outro) {
  n = capacidade = outro.n;
  delete[] S;
  S = new int[capacidade];
  std::copy(outro.S, outro.S+n, S);
  return *this;

}

Heap::~Heap() {
  delete[] S;
}

void Heap::escreve_niveis() {
  int escritos = 0, fim_nivel = 1;

  for(auto const& elemento: S) {
  // Equivalente a for (unsigned i = 0; i < S.size(); i++) { printf("%d ", S[i])};
    printf("%d ", elemento);
    if (++escritos == fim_nivel) {
      putchar('\n');
      fim_nivel *= 2;
      escritos = 0;
    }
  }
  putchar('\n');
  }


void Heap::escreve(const string& prefixo, int i) {
  if (i < (int) S.size()) {
    bool ehEsquerdo = i % 2 != 0;
    bool temIrmao = i < (int) S.size()-1;
    
    printf(prefixo.c_str());
    printf(ehEsquerdo and temIrmao ? "├──" : "└──" );

    printf("%d\n", S[i]);
      
    escreve(prefixo + (ehEsquerdo ? "│   " : "    "), esquerdo(i));
    escreve(prefixo + (ehEsquerdo ? "│   " : "    "), direito(i));
  }
}

int Heap::pai(int i) {
  return (i - 1) / 2;
}

int Heap::esquerdo(int i) {
  return 2 * (i + 1) - 1;
}

int Heap::direito(int i) {
  return 2 * (i + 1);
}

void Heap::troca(int i, int j) {
  int aux = S[i];
  S[i] = S[j];
  S[j] = aux;
}

void Heap::desce(int i) {
  //TODO: implementar
  int e , d , maior;
  e = esquerdo(i);
  d = direito(i);
  if(e < S.size() && S[e] > S[i])
        maior = e;
  else
        maior = i;
  if(d < S.size() && S[d] > S[maior])
        maior = d;
  if(maior != i)
    {
    troca(maior , i);
    desce(i);
    }
}

void Heap::sobe(int i) {
  while (S[pai(i)] < S[i]) {
    troca(i, pai(i));
    i = pai(i);
  }
}

void Heap::insere(int p) {
 if (n == capacidade) {
  capacidade *= 2;
  int *novoS = new int[capacidade];
  std::copy(S,S+n,novoS); //Um ponteiro pro começo que voce quer passar copiando, fim do ponteiro que voce quer passar copiando, e o ponteiro pro começo do vetor que 
  // recebera a copia;
 }
 S[n++] = p;
 sobe(n-1);
 // esse insere basicamente cria uma copia do vetor com 2x o tamanho, e passa todos os dados para ele, quando o tamanho da Heap esta no maximo (o maximo da HEALP é
 // a capacidade, enquanto o n é o tanto de elementos atualmente)
}

int Heap::consulta_maxima() {
  //TODO: implementar
  return S[0];

}

int Heap::extrai_maxima() {
  //TODO: implementar
    int maxima = S[0];
    troca(0,S.size() - 1);
    S.pop_back();
    desce(0);
    return maxima;
}

void Heap::altera_prioridade(int i, int p) {
  int antigo = S[i];
  S[i] = p;
  if(p < antigo)
    desce(i);
  else
    sobe(i);
}