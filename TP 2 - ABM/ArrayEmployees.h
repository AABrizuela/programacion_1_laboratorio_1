#ifndef ArrayEmployees_h_included
#define ArrayEmployees_h_included
#define EMPLOYEES 1000
#define LENGTH 51
#define SECTORS 10

typedef struct
{
    int id;
    char name[LENGTH];
    char lastName[LENGTH];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

typedef struct
{
	int id;
	char description[20];
	int isEmpty;
}eSector;


int getFreeSpot(eEmployee employeeList[], int len);

/** \brief To indicate that all position in the array are empty,
 *  			this function put the flag (isEmpty) in TRUE in all
 * 			position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void initEmployees( eEmployee employeeList[], int len);
void addEmployee(eEmployee employeeList[], int len);
void menu();
void subMenu(eEmployee employeeList[], int len);
void sortByAlphaAndSector(eEmployee employeeList[], int len);
void removeEmployee(eEmployee employeeList[], int len);
void printEmployee(eEmployee employee, int len);
void printEmployees(eEmployee employeeList[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee employeeList[], int len,int id);

#endif // ArrayEmployees_h_included
