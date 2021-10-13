#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <cmath>
using namespace std;

pthread_mutex_t m;

void* func(void *);

int main()
{
    setlocale(LC_ALL, "rus");
        pthread_t id[16];
        pthread_mutex_init(&m, NULL);
        int t = 0;
    int a[16] = {19191, 201, 333, 43, 555, 60, 777, 888, 900, 1010, 1111, 1222, 13333, 144, 15, 16};
    for (int i = 0; i < 16; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 16; i++)
    {
        pthread_create(&id[i], NULL, func, (void*)&a[i]);
    }
        for (int i = 0; i < 16; i++)
    {
                pthread_join (id[i], NULL);
                if (a[i] == 1){
                        t++;
                }
        }
    cout << "Quantity: " << t << endl;
    pthread_mutex_destroy(&m);
    return (0);
}
void * func(void *arg){
    pthread_mutex_lock (&m);
    int j=0;
        cout << *((int*)arg) << endl;
        int n = *((int*)arg);
    long long req = sqrt(n);
        for(long long i=2;i<=req;i++)
                if(n%i==0){
                        *((int*)arg) = 0;
                        cout << "Chislo ne prostoe!" << endl;
                        pthread_mutex_unlock(&m);
                        return arg;
                }
                *((int*)arg) = 1;
                cout << "Chislo prostoe!" << endl;
                pthread_mutex_unlock(&m);
                return arg;

}