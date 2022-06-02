/*Teste T2
Victor Cardozo Garcia 32068883
Carla Pollastrini 32085877
Projeto de sistema operacionais */

#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>







typedef struct {
  int dinheiro;
  pthread_mutex_t lock;
} Banco;
static Banco the_bank;

struct bank{
  /*Isso usa um recurso que não discutimos até agora, que são variáveis globais. Como C, Rust permite a declaração de globais com a palavra-chave static. Infelizmente, as variáveis globais quebram o modelo de propriedade e, portanto, usá-las não é seguro (consulte Acessando ou modificando uma variável estática mutável para obter mais informações). Podemos resolver isso movendo nosso global para a função main.*/

};
/*Podemos corrigir nosso bug anterior condensando dois bloqueios em um e agrupando adequadamente as duas funções.*/
void depositar(int n) {
  int cur_cash = the_bank.dinheiro;
  the_bank.dinheiro = cur_cash  += n;
  if (the_bank.dinheiro >= n) {
  the_bank.dinheiro -= n;
    pthread_mutex_lock(&the_bank.lock);
  the_bank.dinheiro += n;
  pthread_mutex_unlock(&the_bank.lock);
}
}

void retirar_o(int n) {
  pthread_mutex_lock(&the_bank.lock);
  if (the_bank.dinheiro >= n) {
    the_bank.dinheiro -= n;
  }
  pthread_mutex_unlock(&the_bank.lock);
}


/*3 pessoas diferentes x, y e z
nesse quadro, a pessoas x, deposita uma quantia, e outras duas pessoas y e z retiram simultaneamente a quantia desejada no caso a quantia dividido por dois, como se fossemos pensar em uma herança*/
void* cliente(void* args) {
  for (int i = 0; i < 1; ++i) {
    depositar(125);//FATOR WH1
  }
  //FATOR QUE RETIRAR PELA TIRA PELA METADE DA CONTA SIMULTANEAMENTE O MESMO FATOR
  for (int i = 0; i < 1; ++i) { 
    retirar_o(0);
  }

  return NULL;
}



int main() {
  /*Total de dinheiro que ja tinha na conta!*/
  the_bank.dinheiro =1000;

  // Criar uma thread para 2 clientes
  //Total multiplicado pelo numero de clientes em depositar no fator WH1
  
  int N = 100;
  pthread_t tids[N];
  for (int i = 0; i < N; ++i) {
    pthread_create(&tids[i], NULL, &cliente, NULL);
  }

  // Espere até que cada um esteja pronto.
  for (int i = 0; i < N; ++i) {
    pthread_join(tids[i], NULL);
  }

  printf("Total: %d\n", the_bank.dinheiro);

  return 0;
}