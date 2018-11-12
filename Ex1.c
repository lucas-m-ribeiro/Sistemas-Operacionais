#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define number_of_threads 10

void*print_hello_word(void*tid){
	
	/* função para imprimir o identificador do thread*/
	
	printf("hello world Greetings from thread %d\n", tid);
	pthread_exit(NULL);
}

/*função principal*/
int main(int argc, char *agrv[]){
	
	/*O programa ira criar 10 threads e sai*/
	
	pthreads_t threads[number of threads];
	int status, i;
	
	/* Laço de repetição enquanto o contador for menor que number_of_threads ele ira imprimir e mostrar */
	for(i = 0; i < number_of_threads;i++){
		printf("main here creating thread %d\n",i);
		status = pthread_creat(&threads[i], NULL, print_hello_word, (void*)i);
		
		/*caso seja diferente de 0 ira informar o erro da criação do thread*/
		if(status != 0){
			printf("ops, phterad_creatd returned error code %d\n", status);
			exit(-1);
		}
	}
	/*saida do programa*/
	exit(NULL);	
}