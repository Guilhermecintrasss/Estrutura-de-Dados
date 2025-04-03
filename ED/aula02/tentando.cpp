#include <cstdio>

class Celula;
class TabelaDispersao;

class Celula
{
  friend TabelaDispersao;

public:
  Celula(int chave, Celula *prox = nullptr) : chave(chave), prox(prox) { }

private:
  int chave;
  Celula *prox;
};

class TabelaDispersao
{
public:
  TabelaDispersao(int tamanho);
  ~TabelaDispersao();
  void insere(int x);
  bool busca(int x);
  bool remover(int x);
  double fator_carga();
  int elementos(); // devolve a quantidade de elementos
  void escreve();

private:
  int h(int x);
  int m;
  Celula **tabela;
};

int main(void)
{
    TabelaDispersao tabela(10);
    tabela.insere(5);
    tabela.insere(4);
    tabela.insere(3);
    tabela.remover(3);

    printf("%d",tabela.elementos());

  return 0;
}

TabelaDispersao::TabelaDispersao(int tamanho) :
  m(tamanho)
{
  tabela = new Celula*[tamanho];
  for (int i = 0; i < tamanho; i++)
    tabela[i] = nullptr;
}

TabelaDispersao::~TabelaDispersao()
{
  // FAZER: varrer cada lista deletando as células
  for(int i = 0; i < m; i++){
    Celula *p = tabela[i];

    while(p != nullptr){
        Celula *lixo = p;
        p = p->prox;
        delete lixo;
    }
  }
  delete[] tabela;
}

void TabelaDispersao::insere(int x)
{
  Celula *nova = new Celula(x, tabela[h(x)]);
  tabela[h(x)] = nova;
}

bool TabelaDispersao::busca(int x)
{
  // FAZER: varrer a lista em tabela[h(x)], devolvendo true se encontrar x e false c.c.
  Celula *p = tabela[h(x)];
  bool resultado = false;
  while(p != nullptr){
    if(p->chave == x){
      p = nullptr;
      return true;
    }
    p = p->prox;
  }
  return false;

}

bool TabelaDispersao::remover(int x)
{
  // FAZER: varrer a lista em tabela[h(x)], removendo a célula com x se encontrar e devolvendo true, ou devolvendo false se não encontrar
  Celula *p = tabela[h(x)];
  Celula *ant = nullptr;
  while(p != nullptr && p->chave != x){
      ant = p;
      p = p->prox;
    }
    if(p!= nullptr && p->chave == x){
      if(ant == nullptr)
        tabela[h(x)] = p->prox;
      else
        ant->prox = p->prox;
      delete p;
      return true;
      }else{
      return false;
    }
}

double TabelaDispersao::fator_carga()
{
  return elementos() / (double) m;
}

int TabelaDispersao::elementos()
{
  // FAZER: varrer cada lista contando e devolver
    int c = 0;
    for(int i = 0; i < m; i++){
    Celula *p = tabela[i];
    while(p != nullptr){
        c++;
        p = p->prox;
    }
  }
  return c;
}

int TabelaDispersao::h(int x)
{
  return x % m;
}
