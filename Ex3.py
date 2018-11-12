#Cliente TCP
import socket
# Endereco IP do Servidor
SERVER = '169.254.190.37'				
# Porta que o Servidor esta escutando
PORT = 5002
tcp = socket.socket(socket.AF_INET,
socket.SOCK_STREAM)
dest = (SERVER, PORT)
tcp.connect(dest)				
print ('Para sair use CTRL+X\n')		
msg = input()						#Entada da mensagem
while (msg != '\x18'):				
    tcp.send (msg.encode())			#Envia a mensagem e garante que ela chegara por ser TCP 
    msg = input()					#Entra com a mensagem
tcp.close()

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#Servidor TCP
import socket
from threading import Thread			#importa biblioteca Thread

def conexao(con,cli):
    while True:
        msg = con.recv(1024)		#função verifica a mensagem e a imprime, caso cotrario a execução é parada
        if not msg: break
        print (msg)
    print ('Finalizando conexao do cliente', cli)		#se bloqueado a conexão com o cliente é finalizada
    con.close() 

# Endereco IP do Servidor
HOST = ''
# Porta que o Servidor vai escutar
PORT = 5002
cp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
orig = (HOST, PORT)
tcp.bind(orig)
tcp.listen(1)
while True:								#inicia a função da Thread e conecta com o cliente
    con, cliente = tcp.accept()
    print ('Concetado por ', cliente)
    t = Thread(target=conexao, args=(con,cliente,))
    t.start()							#inicia a thread
