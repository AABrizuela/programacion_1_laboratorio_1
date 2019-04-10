#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValidStringLetras(char* mensaje);
int isValidNumber(char* str);
int getNumber(char* msg, char* msgError, int* minimo, int* maximo, int* reintentos, int* resultado);
int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);

int main()
{
    /*char nombre[7]={'X','O','X','X','\0'};
    char nombre2[7]="HOLA";

    //NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO nombre = "Juan";

    strncpy(nombre,nombre2,sizeof(nombre));
    printf("\n%s",nombre);
    fgets(nombre,sizeof(nombre),stdin);
    //NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  scanf("%s",nombre);
    printf("\n%s",nombre);
    strlen()
    strcmp()*/

    char nombre[7];
    char buffer[7];
    int status = 1;
    //int i = 0;


    printf("Ingrese nombre: ");
    fgets(buffer, sizeof(buffer), stdin);
    fflush(stdin);

    /*while(buffer[i] != '\0'){*/

    printf("antes: %d\n", status);
    status = getValidStringLetras(buffer);
    printf("despues: %d\n", status);

    while(status != 0){

        printf("El nombre solo debe contener letras. Reingrese: ");
        fgets(buffer, sizeof(buffer), stdin);
        printf("antes: %d\n", status);
        status = getValidStringLetras(buffer);
        printf("despues: %d\n", status);
        fflush(stdin);

    }
        /*if((buffer[i] != ' ') && (buffer[i] > 'a' && buffer[i] < 'z') || (buffer[i] > 'A' && buffer[i] < 'Z')){
            printf("validando\n");
            status = 0;
        }else{
               printf("El nombre solo debe contener letras. Reingrese: ");
               fgets(buffer, sizeof(buffer), stdin);
               fflush(stdin);
        }*/
        /*i++;
    }*/

    if(status == 0){
        strcpy(nombre, buffer);
        printf("El nombre ingresado es: %s", nombre);
    }/*else{
        printf("El nombre solo debe contener letras.");
    }*/

    //printf("El nombre ingresado es: %s", nombre);

    return 0;
}

int getValidStringLetras(char* mensaje){

    int i = 0;
    int valido = 1;
    int len = strlen(mensaje);
    printf("tamaño: %d" ,len);

    //while(mensaje[i] != '\0' && mensaje[i] != '\n')
    for(; i < len-1; i++){

        if((mensaje[i] != ' ') && ((mensaje[i] > 'a' && mensaje[i] < 'z') || (mensaje[i] > 'A' && mensaje[i] < 'Z'))){
            printf("validando %d\n", i);
            valido = 0;
        }else{
            printf("mensaje: %s\n", mensaje);
            valido = 1;
            break;
        }

    }

    return valido;

}

int isValidNumber(char* str){

    return 1;

}

int getNumber(char* msg, char* msgError, int minimo, int maximo, int reintentos, int resultado){

    return 1;

}

int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado){

    return 1;

}
