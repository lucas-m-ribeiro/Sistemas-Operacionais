#Solucao Peterson
from threading import Thread	
import time

global turn, i, j, flag				#definição das variaveis globais compartilhadas

def regiaoCritica():				#Definição do delay da regiao critica de cada funçao
    time.sleep(1)

def processamentoA(times, delay):
    global turn, i, j, flag						#deinição das variaveis compartilhadas
    for x in range(times):
        print ("Secao de Entrada A - ",x+1)  
        flag[i] = True								# a variavel flag indica se o processo esta pronto para entrar na seção critica 
        turn = j								# a variavel turn indica de quem é a vez de entrar na seção critica
        while (flag[j] and turn == j):			# enquanto a vriavel turn e flag nao estiverem com a mesma variavel pronta nao entrara na seção critica.
            continue							
        print ("Regiao Critica A")
        regiaoCritica()							#Entrada na seção critica para exceutar o programa
        print ("Secao de Saida A")
        flag[i] = False							# variavel flag verifica se i esta pronto para entrar na seção critica
        print ("Regiao nao critica A\n")
        time.sleep(delay)    					#tempo limite para entrar em sua seção critica novamente

def processamentoB(times, delay):				
    global turn, i, j, flag						#declaração das variaveis compartilhadas
    for x in range(times):
        print ("Secao de Entrada B - ",x+1)		
        flag[j] = True							#variavel flag que indica se o processo esta pronto para a entrada na seção critica
        turn = i        						#variavel turn indica de quem é a vez de entrar na seção critica
        while (flag[i] and turn == i):			#enquanto flag e turn nao estiverem com a mesma variavel pronta nao entrara na seção critica
            continue		
        print ("Regiao Critica B")        
        regiaoCritica()							# entrada na seção critica para executar o programa
        print ("Secao de Saida B")
        flag[j] = False							#verifica se j esta pronto para entrar na seção critica
        print ("Regiao nao critica B\n")
        time.sleep(delay)						#tempo limite para a entrada da seção critica novamente


print ("Exemplo de Solucao de Peterson")
execTimes = 5		# numero de repetiçao da execução do programa
turn = 0			
i = 0
j = 1
flag = []
flag.append(False)
flag.append(False)

#no processamento você pode passar quantas vezes que a exec e
#qual o tempo de delay para simular o efeito comboi
tA = Thread(target=processamentoA, args=(execTimes,1,))
tA.start()
tB = Thread(target=processamentoB, args=(execTimes,5,))
tB.start()