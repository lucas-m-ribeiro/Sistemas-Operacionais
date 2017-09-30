package Processo;

import java.io.IOException;

/* O programa mostrou os resulados esperados abrindo como exemplo a calculadora do windows */

public class Process {

/* para criar um processo em java é nescessario importar a biblioteca import java.io.IOException; */

	public static void main(String[] args) {
		try{
			/* "Runtime.getRuntime().exec("calc.exe");" este comando é para executar um segundo processo dando
			origem ao processo filho, como esta no exemplo ira executar a calculadora do windows */
			Runtime.getRuntime().exec("calc.exe");
		
		}catch (IOException e){
			
			/* caso a execução nao seja concluida com sucesso, o comando "e.printStackTrace();" ira mostrar uma
			mensagem de erro para o usuario*/
			e.printStackTrace();
		}
		
		/*Depois o processo terminado, ira imprimir a mensagem "filho completo" */
		System.out.println("Filho Completo");
	}
}
