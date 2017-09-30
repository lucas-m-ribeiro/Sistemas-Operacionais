#include <stdio.h>
#include <windows.h>

/* Os resultados obtidos foram concluidos com sucesso, o codigo executou a a aplicação abrindo o navegador
internet exporer */


int main(void){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

	/* Inicia a alocação de memoria */
    ZeroMemory(&si, sizeof (si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

	/* inicia a criação do processo filho para executar o seundo programa. */
    if(!CreateProcess(NULL, "C:\\Program Files\\Internet Explorer\\iexplore.exe", NULL,NULL,FALSE, 0, NULL,NULL, &si,&pi)){
        fprintf(stderr, "Create Process Failed"); 
        return -1;
	/* caso o processo falhe ira imprimir a mensagem "Created Process Failed" */
}

/* O processo pai ira esperar o Processo filho terminar de rodar
assim que terminar ira imprimir a mensagem "Child complete" */
WaitForSingleObject(pi.hProcess,INFINITE);
printf("child complete.");

//* por fim ele ira fechar os processos em aberto */
CloseHandle(pi.hProcess);
CloseHandle(pi.hThread);
}


