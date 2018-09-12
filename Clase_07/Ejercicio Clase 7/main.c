#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 200

int main()
{

    int legajo[CANT], legajoAux, edad[CANT], edadAux, i, j, cantidad, opcion, isEmpty[CANT], isEmptyAux, flag = 0, opcionM;
    char nombre[CANT][31], nombreAux[31], apellido[CANT][31], apellidoAux[31], respuesta;

    for(i = 0; i < CANT; i++)
    {

        isEmpty[i]=1;

    }

    do
    {
        system("cls");

        printf("Bienvenido al ABM!\n\n");
        printf("1.- Alta de datos.\n");
        printf("2.- Baja de datos.\n");
        printf("3.- Listar.\n");
        printf("4.- Ordenar.\n");
        printf("5.- Salir.\n");

        switch(opcion)
        {

            case 1:
                for(i=0; i<CANT; i++)
                {
                    if(isEmpty[i] == 1)
                    {

                        printf("Apellido: ");
                        fgets(apellido[i], sizeof(apellido[i]) - 2, stdin);
                        cantidad = strlen(apellido[i]);
                        apellido[i][cantidad - 1] = '\0';

                        printf("Nombre: ");
                        fgets(nombre[i], sizeof(nombre[i]) - 2, stdin);
                        cantidad = strlen(nombre[i]);
                        nombre[i][cantidad - 1] = '\0';

                        printf("Edad: ");
                        fgets(edad[i], sizeof(edad[i]) - 2, stdin);
                        cantidad = strlen(edad[i]);
                        edad[i][cantidad - 1] = '\0';

                        printf("Legajo: ");
                        fgets(legajo[i], sizeof(legajo[i]) - 2, stdin);
                        cantidad = strlen(legajo[i]);
                        legajo[i][cantidad - 1] = "\0";

                        isEmpty[i] = 0;
                        break;
                    }

                }
                break;

            case 2:
                printf("Legajo: ");
                scanf("%d", &legajoAux);

                flag = 0;

                for(i=0; i<CANT; i++)
                {

                    if(legajoAux == legajo[i] && isEmpty[i] == 0)
                    {

                        isEmpty[i] = 1;
                        flag = 1;

                    }

                }
                if(flag == 0)
                {

                    printf("Dato no encontrado.");

                }
                break;

            case 3:
                printf("Legajo\tApellido\t\tNombre\t\tEdad\n\n");

                for(i=0; i<CANT; i++)
                {
                    if(isEmpty[i] == 0)
                    {

                        printf("%d\t%d\t\t%s\t\t%d\n", legajo[i], apellido[i], nombre[i], edad[i]);

                    }


                }
                break;

            case 4:
                for(i=0; i<CANT-1; i++)
                    {

                        for(j=i+1; j<CANT; i++)
                        {

                            if(strcmp(nombre[i], nombre[j]) > 0)
                            {

                                strcpy(nombreAux, nombre[i]);
                                strcpy(nombre[i], nombre[j]);
                                strcpy(nombre[j], nombreAux);
                                strcpy(apellidoAux, apellido[i]);
                                strcpy(apellido[i], apellido[j]);
                                strcpy(apellido[j], apellidoAux);

                                edadAux = edad[i];
                                edad[i] = edad[j];
                                edad[j] = edadAux;

                                legajoAux = legajo[i];
                                legajo[i] = legajo[j];
                                legajo[j] = legajoAux;

                                isEmptyAux = isEmpty[i];
                                isEmpty[i] = isEmpty[j];
                                isEmpty[j] = isEmptyAux;

                            }else{

                                if(strcmp(apellido[i], apellido[j]) == 0)
                                    {

                                    if(strcmp(nombre[i], nombre[j]) > 0)
                                        {

                                            strcpy(nombreAux, nombre[i]);
                                            strcpy(nombre[i], nombre[j]);
                                            strcpy(nombre[j], nombreAux);

                                            edadAux = edad[i];
                                            edad[i] = edad[j];
                                            edad[j] = edadAux;

                                            legajoAux = legajo[i];
                                            legajo[i] = legajo[j];
                                            legajo[j] = legajoAux;

                                            isEmptyAux = isEmpty[i];
                                            isEmpty[i] = isEmpty[j];
                                            isEmpty[j] = isEmptyAux;


                                        }

                                    }

                            }



                        }

                    }
                break;

            case 5:
                printf("Legajo:");
                scanf("%d", &legajoAux);
                flag = 0;
                for(i=0, i<CANT, i++)
                {

                    if(legajoAux==legajo[i])
                    {

                        printf("%d%s%s%d", legajo[i], apellido[i], nombre[i], edad[i]); //agregar en la baja
                        printf("Desea modificar? S/N");
                        fflush(stdin);
                        scanf("%c", &respuesta);

                        if(respuesta == 'S')
                        {

                            printf("Menu");
                            printf("1.- Apellido.");
                            printf("2.- Nombre.");
                            printf("3.- Edad.");
                            printf("4.- Salir.");
                            printf("Seleccione");
                            scanf("%d", opcionM);

                            switch(opcionM)
                            {

                                case 1:
                                    printf("Apellido: ");
                                    fflush(stdin);
                                    fgets(apellido[i], , ) //rellenar
                                    break;
                                //terminar los casos
                            }

                        }else{

                            printf("No se modificaron los datos.");

                        }

                        printf("Se modificaron los datos con exito.");

                    }

                }
                break;

            case 6:
                printf("Gracias por usar el ABM!");
                break;

        }

        system("pause");

    }while(opcion!=5);

    return 0;

}
