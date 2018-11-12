#Estrita Alternância
from threading import Thread
import time

global turn						#variavel global turn 

def regiaoCritica():			#definição do delay da seção critica de cada função
    time.sleep(1)

def processamentoA(times, delay):
    global turn						#variavel global tunr que da a vez para o processamentoB entrar na região critica
    for x in range(times):
        print ("Secao de Entrada A - ",x+1)        
        while (turn != 0):				#quando a variavel turn for diferente de 0 o programa ira entrar na seção critica
            continue
        print ("Regiao Critica A")        
        regiaoCritica()					#região critica do programa onde é executado
        print ("Secao de Saida A")
        turn = 1						#a variavel turn = 1 da a vez para o prodessamento B executar sua regiao critica saindo assim da seção critica
        print ("Regiao nao critica A\n")
        time.sleep(delay)    			#tempo limite para entrar em sua seção critica novamente 

def processamentoB(times, delay):
    global turn							# variavel turn que da a vez para o processamentoA entrar na região critica
    for x in range(times):
        print ("Secao de Entrada B - ",x+1)
        while (turn != 1):				# quando o valor de turn for igual a 1 ele vai entrar na seção critica
            continue
        print ("Regiao Critica B")      
        regiaoCritica()					#Regiao critica do programa onde é executado.
        print ("Secao de Saida B")
        turn = 0						# variavel turn = 0 que da a vez para o processamentoA executar a região critica
        print ("Regiao nao critica B\n")
        time.sleep(delay)				#tempo limite para entrar em sua regiao critica novamente


print ("Exemplo de Estrita Aternancia")
execTimes = 10		#numero de repetição da execução do programa
turn = 0

#no processamento você pode passar quantas vezes que a exec e
#qual o tempo de delay para simular o efeito comboi
tA = Thread(target=processamentoA, args=(execTimes,1,))
tA.start()
tB = Thread(target=processamentoB, args=(execTimes,5,))
tB.start()