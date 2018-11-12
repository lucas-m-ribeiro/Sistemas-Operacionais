#Semáfaro
from threading import Thread,Semaphore
import time

s = Semaphore()
def regiaoCritica():					#deinição de delay da seção Critica de cada função
    time.sleep(1)

def processamentoA(times, delay):
    for x in range(times):
        print ("Secao de Entrada A - ",x+1)        
        s.acquire()						#inicia a seçao de entrada do programa
        print ("Regiao Critica A")        
        regiaoCritica()					#região critica do programa onde é executado
        print ("Secao de Saida A")
        s.release()						# s.release() é a regiao de saida do programa depois de executar a seção critica
        print ("Regiao nao critica A\n")
        time.sleep(delay)    			# tempo limite para a entrada em sua região critica novamente

def processamentoB(times, delay):
    for x in range(times):				
        print ("Secao de Entrada B - ",x+1)
        s.acquire()						# entrada do programa
        print ("Regiao Critica B")        
        regiaoCritica()					#região critica do programa onde é executado
        print ("Secao de Saida B")
        s.release()						#região de saida do programa apos excutar a região critica
        print ("Regiao nao critica B\n")
        time.sleep(delay)				#tempo limite pra entrar na regiao critica novamente


print ("Exemplo de Semafaro")
execTimes = 5	#repetição de execução do programa

#no processamento você pode passar quantas vezes que a exec e
#qual o tempo de delay para simular o efeito comboi
tA = Thread(target=processamentoA, args=(execTimes,1,))
tA.start()
tB = Thread(target=processamentoB, args=(execTimes,5,))
tB.start()