#include <stdio.h>

int main(){

    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j,aux;
    int entrada, tempo_chegada[20];
    int waiting_time = 0, turnaround = 0;

    printf("Simulador de escalonamento de processos\n\n");
    printf("Entre com 1 para executar FCFS!\n");
    printf("Entre com 2 para executar SJF!\n");
    printf("Entre com 3 para executar SRTF!\n");
    printf("Entre com 4 para executar Round Robin!\n");

    printf("\n\nEntre com a opcao que deseja: ");
    scanf("%d", &entrada);

    do{
        switch(entrada){

            case 1:{
                printf("\nEntre com o numero de processos: ");
                scanf("%d", &n);            //numero de processos

                printf("\nEntre com o numero de burst:\n");
                for(i = 0; i < n; i++){
                    printf("P[%d]: ",i+1);          //numero de burst
                    scanf("%d", &bt[i]);
                }

                //calculando tempo de espera
                wt[0] = 0;
                for(i=1;i<n;i++){
                    wt[i]=0;           // tempo de espera enquanto i for menor que n o tempo deespera
                for(j=0;j<i;j++)        // é igual a soma do burst
                    wt[i]+= bt[j];
                    }

                printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

                //calculo do tempo de entrega
                for(i=0;i<n;i++){
                    tat[i]=bt[i]+wt[i];   //Tat igual ao burst mais tempo de espera
                    avwt+=wt[i];           //AVAT é a soma com tempo de espera
                    avtat+=tat[i];         // AVAT é a soma com TAT
                    printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
                    }

                    avwt/=i;
                    avtat/=i;
                    printf("\n\n\nAverage Waiting Time: %d\n",avwt);
                    printf("\nAverage Turnaround Time: %d\n\n",avtat);
                    break;
            }

            case 2:{
                printf("\nEntre com o numero de processos: ");
                scanf("%d", &n);       //entrada com o numero de processos

                printf("\nEntre com o numero de burst:\n");
                for(i = 0; i < n; i++){
                    printf("P[%d]: ",i+1);      // entrada com o numero de burst
                    scanf("%d", &bt[i]);
                }
                    // shortest job first
                for(i = 0; i < n; i++){
                    for(j = i; j < n; j++){
                        if(bt[i] > bt[j]){      // ordena os processos de acordo com o burst
                            aux = bt[i];
                            bt[i] = bt[j];
                            bt[j] = aux;
                            }
                        }
                    }

                //calculando tempo de espera
                wt[0] = 0;
                for(i=1;i<n;i++){           //Tat igual ao burst mais tempo de espera
                    wt[i]=0;                   //AVAT é a soma com tempo de espera
                    for(j=0;j<i;j++){       // AVAT é a soma com TAT
                    wt[i]+= bt[j];
                    }
                }
                printf("\nProcess\tWaiting Time\tTurnaround Time");

                 //calculo do tempo de entrega
                for(i=0;i<n;i++){
                    tat[i]=bt[i]+wt[i];
                    avwt+=wt[i];
                    avtat+=tat[i];
                    printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
                }

                 avwt/=i;
                    avtat/=i;
                    printf("\n\n\nAverage Waiting Time: %d\n",avwt);
                     printf("\nAverage Turnaround Time: %d\n\n",avtat);
                    break;
            }

            case 3:{
                 int at[10],bt[10],rt[10],endTime,i,smallest,processGantt[100];
                 int remain=0,n,time,sum_wait=0,sum_turnaround=0;

                 printf("\nEntre com o numero de processos: ");
                 scanf("%d",&n);        // entada dos processos
                 for(i=0;i<n;i++){
                     printf("\nEntre com o tempo de chegada do processo %d: ",i+1);
                     scanf("%d",&at[i]);        // entrada com o tempo de chegada dos processos
                 printf("\nEntre com o burst do processo %d: ",i+1);
                 scanf("%d",&bt[i]);            //entrada com o burst do processo
                 rt[i]=bt[i];
            }
                printf("\nProcess\t|Waiting Time|\tTurnaround Time");
                rt[9]=9999;

                for(time=0;remain!=n;time++){
                    smallest=9;
                for(i=0;i<n;i++){
                    if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0){
                        processGantt[time]=i;
                        smallest=i;
                }
        }
                rt[smallest]--;
                if(rt[smallest]==0){
                    remain++;
                    endTime=time+1;
                    printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);
                    sum_wait+=endTime-bt[smallest]-at[smallest];
                    sum_turnaround+=endTime-at[smallest];
                }
        }           printf("\n\nAverage waiting time = %.2f\n",sum_wait*1.0/n);
                    printf("\nAverage Turnaround time = %.2f\n\n",sum_turnaround*1.0/5);
                    for(i=0;i<=time;i++){
                        printf("%d->P%d \n",i,processGantt[i]+1);
                        break;
                    }
                }

                case 4:{
                int count,j,n,time,remain,flag=0,time_quantum;
                int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

                printf("\nEntre com o total de processos: ");
                scanf("%d",&n);
                remain=n;
                for(count=0;count<n;count++){
                    printf("\nEntre com o tempo de chegada do processo %d: ",count+1);
                scanf("%d",&at[count]);
                printf("\nEntre com o tamanho do burst do processo %d: ",count+1);
                scanf("%d",&bt[count]);
                rt[count]=bt[count];
            }
                printf("\nEntre com o quantum: ");
                scanf("%d",&time_quantum);
                printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
                for(time=0,count=0;remain!=0;){
                    if(rt[count]<=time_quantum && rt[count]>0){
                            time+=rt[count];
                            rt[count]=0;
                            flag=1;
                }
                    else if(rt[count]>0){
                        rt[count]-=time_quantum;
                        time+=time_quantum;
                }
                if(rt[count]==0 && flag==1){
                    remain--;
                    printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
                    wait_time+=time-at[count]-bt[count];
                    turnaround_time+=time-at[count];
                    flag=0;
        }
                    if(count==n-1)
                        count=0;
                    else if(at[count+1]<=time)
                        count++;
                    else
                        count=0;
            }
                    printf("\nAverage Waiting Time= %.2f\n",wait_time*1.0/n);
                    printf("\nAvg Turnaround Time = %.2f\n",turnaround_time*1.0/n);
                    break;
                }
        }
    }while(entrada != 0);
}

