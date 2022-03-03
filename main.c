#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int numero_max, numero_min, array[10], ripetizioni_bool; //Il numero massimo da generare; Il numero minimo da generare;  L'array dove inserire i numeri casiali; Un booleano per controllare le ripetiozioni
    char ripetizioni; //Ripetizioni si o no

    //Chiede i valori
    printf("Inserire qual'e' il numero massimo da generare ");
    scanf("%d", &numero_max);
    printf("Inserire qual'e' il numero mininmo da generare ");
    scanf("%d", &numero_min);
    numero_max++;

    //Controllo se i numeri sono invertiti
    if(numero_max < numero_min){
        printf("Hai scritto il numero piu' grande e il piu' piccolo al contrario \n(L'ordine verra sistemato automaticamente) \n");
        numero_max = numero_max + numero_min;
        numero_min = numero_max - numero_min;
        numero_max = numero_max - numero_min;
    }

    printf("Inserire se [s]i vuole ripetizioni [n]o ");
    scanf(" %c", &ripetizioni);

    //Controllo se e' possibile non avere ripetizioni
    if(((numero_max - numero_min) < 10) && ripetizioni == 'n'){
        printf("Il numero e' troppo piccolo per non avere ripetizioni");
        return 0;
    }

    //Generazioni di numeri senza ripetizioni
    if(ripetizioni == 'n'){
        ripetizioni_bool = 0;
        while(ripetizioni_bool == 0){
            for(int i = 0; i < 10; i++){
                array[i] = (rand() % (numero_max + (numero_min * -1))) + numero_min;
                //Controllo delle ripetioni e generazioni di numeri casuiali di sustituzione
                for(int n = 0; n < i; n++){
                    if (array[i] == array[n]){
                        ripetizioni_bool = 1;
                        array[i] = (rand() % (numero_max + (numero_min * -1))) + numero_min;
                    }

                //Controllo finale per essere sicuri non ci siano doppioni
                for(int i = 0; i < 10; i++){
                    for(int n = 0; i < 10; n++){
                        if (array[i] == array[n]){
                            ripetizioni_bool = 1;
                            break;
                        } else {
                            ripetizioni_bool = 0;
                        }
                    }
                }
            }
        }
    }

    //Generazioni di numeri con possibili ripetiozioni
    } else if (ripetizioni == 's'){
        for(int i = 0; i < 10; i++){
            array[i] = (rand() % (numero_max + (numero_min * -1))) + numero_min;
        }
    }


    //Stampa dei numeri
    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
}
