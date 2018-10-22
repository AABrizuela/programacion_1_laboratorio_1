#ifndef PENDRIVE_H_INCLUDED
#define PENDRIVE_H_INCLUDED

typedef struct
{
    int codigo;
    char marca[25];
    int capacidad;
    float precio;
}ePendrive;

/** \brief Permite cargar un pendrive con sus datos correspondientes.
 *
 * \param pen ePendrive* puntero al array de pendrives.
 * \return int devuelve 0 si no cargo, 1 si Ok.
 *
 */
void cargarPendrive(ePendrive* pen);

/** \brief Le paso los datos parametizados
 *
 * \param pen ePendrive* puntero a pendrive
 * \param codigo int campo codigo
 * \param marca[] char campo marca
 * \param cap int campo capacidad
 * \param precio float campo precio
 * \return int devuelve 0 si no cargo, 1 si Ok.
 *
 */
int cargarPendriveParam(ePendrive* pen, int codigo, char marca[], int cap, float precio);

/** \brief Muestra 1 pendrive elegido por codigo
 *
 * \param pen ePendrive* puntero al array de pendrives.
 * \return void
 *
 */
void mostrarPendrive(ePendrive* pen);

#endif // PENDRIVE_H_INCLUDED
