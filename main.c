#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>	
#include <pthread.h>

int shop[5];
pthread_mutex_t lockShop[5];
int stopL;


void* threadClient(void* thread_Cl){
	//завершаем поток
	int *need = (int*)thread_Cl;
    int i, ;
    srand(pthread_self());
    while(*need > 0)
    {
        i = rand() % 5;
        pthread_mutex_lock(&lockShop[i]);
        tmp = shop[i];
        shop[i] = 0;
        pthread_mutex_unlock(&lockShop[i]);
        *need -= tmp;
        printf("customer: %x, shop: %d, %d need: %d\n", (int)pthread_self(), i, tmp, *need);
        sleep(4);
    }
    printf("EXIT\n");
	sleep(3);
	pthread_exit(0);
}
void* threadGruz()
{
	int i;
	i = rand() % 5;
	pthread_mutex_lock(&lockShop[i]);
    shop[i] += 500;
    pthread_mutex_unlock(&lockShop[i]);
	sleep(2);
	pthread_exit(0);
}

int main()
{
	pthread_t pogruzchik, client[3]; /* идентификатор потока */
    //pthread_attr_t attr; /* отрибуты потока */
	//pid_t pid1, pid2, pid3, pid4, pid5;
	//pid_t pogruzchik, client1, client2, client3;
	//FILE *fd;
	//fd=fopen("./txt.txt","r");	

	for(int i=0;i<5;i++)
	{
		shop[i]=9000+500*i;	
	}
	fwrite (&shop, sizeof(int),5, fd);
	printf("Hello :) \n";
	pthread_create(&pogruzchik, NULL, threadGruz, NULL);
	for(int i = 0; i < 3; i++)
    {
        needs[i] = rand() % 2000 + 9000;
        printf("customer %d, need %d\n", i, needs[i]);
        pthread_create(&client[i], NULL, threadGruz, &needs[i])
    }
    pthread_join (client[0], NULL);
    pthread_join (client[1], NULL);
    pthread_join (client[2], NULL);
//fclose(fd);
}
