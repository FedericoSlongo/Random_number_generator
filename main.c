#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int numero_max, numero_min, array[10], ripetizioni_bool; //Il numero massimo da generare; Il numero minimo da generare;  L'array dove inserire i numeri casiali; Un booleano per controllare le ripetiozioni
    char ripetizioni; //Ripetizioni si o no

    //Chiede i valori
    printf("Insert the max value you want to generate ");
    scanf("%d", &numero_max);
    printf("Insert the min value you want to generate ");
    scanf("%d", &numero_min);
    numero_max++;

    //Controllo se i numeri sono invertiti
    if(numero_max < numero_min){
        printf("You wrote the max value in the min value (and viceversa) \n(They will be automatically swapped) \n");
        numero_max = numero_max + numero_min;
        numero_min = numero_max - numero_min;
        numero_max = numero_max - numero_min;
    }

    printf("Insert if you want repetion (s) or not (n) ");
    scanf(" %c", &ripetizioni);

    //Controllo se e' possibile non avere ripetizioni
    if(((numero_max - numero_min) < 10) && ripetizioni == 'n'){
        printf("The range is to small to not have repetion");
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
