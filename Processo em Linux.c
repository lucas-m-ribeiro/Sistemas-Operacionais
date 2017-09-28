#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* O Programa retornou os resultados esperados, mostrando na tela o PID (Process Identification) ou (identificador de processos) */

int main(void)
{
    int i;
    pid_t pid;

	/* este é o primeito teste para verificar se o fork foi bem sucedido */
   
   if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
	
	/* Em seguida fazemos se pid == 0, sendo o resultado positivo somente no processo filho
	sendo assim o processo pai nao entra nessa condição, apenas o processo filho, 
	E caso esse teste condicional seja falso, é porque o processo em vigor é o pai.*/
	
    if (pid == 0)
    {
        //O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d\n", getpid());
    }
    else
    {
        //O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
    }

	/*É importante colocar algum comando que impeça que nosso programa abra, execute e rapidamente feche, não sendo possível ver os prints. 
	Assim, caso não esteja usando o Code::Blocks, 
	coloque um scanf() no final do programa, para você ver o resultado na tela */
    printf("Esta regiao sera executada por ambos processos\n\n");
    scanf("%d", &i);
    exit(0);
}
