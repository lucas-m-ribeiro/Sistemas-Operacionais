class Producer implements Runnable{
	private Channel mbox;
	
	public Producer (Channel mbox){		/*declaração da variavel */
		this.mbox = mbox;
	}
	
	public void run(){
		Date message;
		
		while(true){
			/*suspendido por algum tempo*/
			SleepUtilites.nap();
			
			/*produz a menssagem e entra no buffer */
			message = new Date();
			
			syste.out.println("Producer producer" +message);	/*imprime a mensagem */
			mbox.send(message);
			
		}
	}
}


class Consumer implements Runnable{
	private Channel mbox;
	
	public Consumer (channel mbox){
	}
		this.mbox = mbox;
		
		public void run(){
			Date message;
			
			while(true){
				
				/*suspendido por um tempo*/
				SleepUtilites.nap();
				
				/*consome a mensagem do buffer */
				message = (Date) mbox.recive();
				
				/* enquanto nao estiver vazio a variavel mensagem ele ira imprimir e mostrar na tela */
				if(message != null)
					system.out. println("Consumer consumed " + message);
			}
		}
	}
	
	public class Factory{
		public Factory(){
			
			/*cria primeiro a mensagem do buffer */
			
			Channel mailbox = new MessageQueue();
			
			/*crie os segmentos do produtor e do consumidor 
			e passe cada tópico uma referência para o objeto de email */
			
			Thread producerThread = new Thread (new Producer(mailbox));
			Thread consumerThread = new Thread(new Consumer(mailbox));
			
			/*inicia a thread*/
			producerThread.start();
			consumer.Thread.star();
		}
		public  static void main(String args[]){
			Factory server = new Factory();
		}
	}
	