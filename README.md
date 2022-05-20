Exercício 1B - Sistemas Operacionais

1) Foram realizadas 4 chamadas ao SO;
2) Foram realizadas 6 chamadas ao SO;

Exercício 2 - Sistemas Operacionais

1) As mensagens não estarão ordenadas pelo valor de i já que se mantivérmos os valores grande de N rodando, os valores perdem o tempo além da sua ordenação que se torna confusa e fora de ordem;
2) Se atualizarmos o código de acordo com as mudanças no caso de printf para sys.stdout, com a 
biblioteca certa o resultado final não muda. Apenas ficará mais lenta porém em milésimos;


- Projeto de Software

#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <threads.h>
#include <pthread.h>

typedef struct {
  int dinheiro;
  /*pthread_mutex_t deposit_lock;
  pthread_mutex_t retirar_lock;*/
  pthread_mutex_t lock;
} BANCO;

static BANCO BANQUINHO;
void depositar(int n) {
  BANQUINHO.dinheiro += n;
}

void deposito(int n) {
  pthread_mutex_lock(&BANQUINHO.lock);
  BANQUINHO.dinheiro += n;
  pthread_mutex_unlock(&BANQUINHO.lock);
}
void RETIRAR(int n) {
  if (BANQUINHO.dinheiro >= n) {
    pthread_mutex_lock(&BANQUINHO.lock);
    BANQUINHO.dinheiro -= n;
    pthread_mutex_unlock(&BANQUINHO.lock);
  }
}
/Colocar aqui numero de clientes/
void* Cliente(void* args) {
  for (int i = 0; i < 100; ++i) {
    depositar(2);
  }

  for (int i = 0; i < 100; ++i) {
    RETIRAR(2);
  }

  return NULL;

}



int main() {
  BANQUINHO.dinheiro = 0;

 // Cria uma thread para 2 clientes.
  int N = 2;
  pthread_t tids[N];
  for (int i = 0; i < N; ++i) {
    pthread_create(&tids[i], NULL, &Cliente, NULL);
  }

  // Espera até que cada um esteja pronto.
  for (int i = 0; i < N; ++i) {
    pthread_join(tids[i], NULL);
  }

  printf("Total:R$ %d reais\n", BANQUINHO.dinheiro);

  return 0;
}
