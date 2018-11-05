#ifndef ArrayEmployees_h_included
#define ArrayEmployees_h_included
#define LENGTH 51
#define SECTORS 10

typedef struct
{
    char name[LENGTH];
    char lastName[LENGTH];
    float salary;
    int idSector;
    int isEmpty;
    int id;

}eEmployee;

int getFreeSpot(eEmployee employeeList[], int len);
void initEmployees( eEmployee employeeList[], int tam);
void addEmployee(eEmployee employeeList[], int len);
int menu();
void subMenu();

/*int addEmployee(Employee *pList, int len, int id, char name[],char lastName[],float salary,int sector);
int freePosition(Employee *pList, int len);
int newId(Employee *pList, int len);
int printEmployees(Employee *pList, int len);
int validateEmployee();*/

#endif // ArrayEmployees_h_included
