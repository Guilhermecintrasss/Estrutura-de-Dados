#include <cstdio>

class Celula;
class TabelaDispersao;

class Celula
{
  friend TabelaDispersao; // permite que a tabela dispersão acesse metodos e atributos privados da classe celula
  
public:
  Celula(int chave, Celula *prox = nullptr) : chave(chave), prox(prox) { } // chave(chave) --> nome do atributo (o que recebe), se eu quisesse eu poderia colocar (chave+2)
  // Esses construtores dps do :, vao colocar os dados nos atributos privados da classe, eles nao necessariamente precisam ter o mesmo nome;   
  // tenho que revisar isso
private:
  int chave;
  Celula *prox;
};

class TabelaDispersao
{
public:
  TabelaDispersao(int tamanho); // construtor
  ~TabelaDispersao(); // destrutor, para a remoção na alocação dinamica, nao ficar flutuando na momoria
  void insere(int x);
  bool busca(int x);
  bool remove(int x); // devolve um true or false se deu pra remover algum existente
  double fator_carga(); //  n / m, conteudo da aula teorica
  int elementos(); // devolve a quantidade de elementos ( o 'n' )
  void escreve();
  
private:
  int h(int x); // função de hash, que recebe um x, e devolve um valor
  int m;
  Celula **tabela; // esse ponteiro de ponteiro, vai apontar para um ponteiro da lista de ponteiros, que vai apontar para a lista encadeada
};

int main(void)
{


  return 0;
}

TabelaDispersao::TabelaDispersao(int tamanho) : //da classe TabelaDispersão, a função TabelaDispersão recebe tamanho
  m(tamanho) //inicializa o valor m com o tamanho, que esta dentro da classe e vai existir fora da função (m = tamanho)
{
  tabela = new Celula*[tamanho]; // cria um vetor de ponteiros que aponta pra celula de de 'tamanho' ponteiros (por ser criado por new, ele nao some quando sai da função)
  // tabela tambem foi delcarado na classe, entao ele tambem nao vai sumir quando sair da função
  for (int i = 0; i < tamanho; i++) // faz todos os ponteiros do vetor apontarem pra nulo
    tabela[i] = nullptr;
}

TabelaDispersao::~TabelaDispersao()
{
  // FAZER: varrer cada lista deletando as células (falta deletar a lista inteira que o ponteiro de ponteiro aponta)
  delete[] tabela; // apaga a tabela inteira
}

void TabelaDispersao::insere(int x)
{
  Celula *nova = new Celula(x, tabela[h(x)]); // cria um ponteiro nova que aponta para uma celula passando x como o valor que vai estar, e com o objetivo de inserir na lista encadeada
  // o ponteiro prox dele vai apontar para o primeiro elemento da lista, que é justamentente o elemento que o ponteiro na posição tabela[h(x)] aponta,
  // assim o ponteiro prox vai dessa celula vai apontar para o primeiro elemento da lista
  tabela[h(x)] = nova; // e aqui, alteramos o que o ponteiro apontava antes, já que antes ele apontava para o primeiro elemento, e o primeiro mudou, agora ele aponta pra
  // nova celula, que é o que nova aponta.
}

bool TabelaDispersao::busca(int x)
{
  // FAZER: varrer a lista em tabela[h(x)], devolvendo true se encontrar x e false c.c.
  return true;
}

bool TabelaDispersao::remove(int x)
{
  // FAZER: varrer a lista em tabela[h(x)], removendo a célula com x se encontrar e devolvendo true, ou devolvendo false se não encontrar
  return true;
}

double TabelaDispersao::fator_carga()
{
  return elementos() / (double) m;
}

int TabelaDispersao::elementos()
{
  // FAZER: varrer cada lista contando e devolver
  return 0;
}

int TabelaDispersao::h(int x)
{
  return x % m;
}