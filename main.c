#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char nombres[5][20];
    float m1[5], m2[5], m3[5];

    int opc, opc1, contE=0;

    float promE = 0;
    float promM[3]={0};
    char MatSimp[3][20] = {"Mat","Len","Prog"};
    float maxminM[3][2];
    float max = 0, min = 10;
    char aprep[3][10];

    do{

        printf("Seleccione una opcion:\n");
        printf("1.Crear estudiante (incluye ingreso de calificaciones)\n");
        printf("2.Mostrar promedios (por asignatura y por estudiante)\n");
        printf("3.Mostrar calificaciones mas altas y mas bajas\n");
        printf("4.Mostrar estudiantes aprobados/reprobados\n");
        printf("5.Salir\n");
        printf(">> ");

        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Ingrese los datos del estudiante:\n");
            printf("Nombre: ");
            scanf("%s",&nombres[contE]);
            printf("Matematicas: ");
            scanf("%f",&m1[contE]);
            printf("Lenguaje: ");
            scanf("%f",&m2[contE]);
            printf("Programacion: ");
            scanf("%f",&m3[contE]);
            contE++;
            break;
        case 2:
            printf("#\t\tNombre\t\tMat\t\tLen\t\tProg\t\tPromE\n");
            for (int i = 0; i < contE; i++)
            {
                promE = (m1[i] + m2[i] + m3[i])/3;
                promM[0]+=m1[i];
                promM[1]+=m2[i];
                promM[2]+=m3[i];
                printf("%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i,nombres[i],m1[i],m2[i],m3[i],promE);
            }
            promM[0]/=contE;
            promM[1]/=contE;
            promM[2]/=contE;
            printf("\tPromedioM\t\t%.2f\t\t%.2f\t\t%.2f\n",promM[0],promM[1],promM[2]);
            break;
        case 3:

            for (int i = 0; i < contE; i++)
            {
                if (m1[i]<=min){
                    min = m1[i];
                }
                if (m1[i]>max){
                    max = m1[i];
                }
            }
            maxminM[0][0]=max;
            maxminM[0][1]=min;

            max=0;
            min=10;

            for (int i = 0; i < contE; i++)
            {
                if (m2[i]<=min){
                    min = m2[i];
                }
                if (m2[i]>max){
                    max = m2[i];
                }
            }
            maxminM[1][0]=max;
            maxminM[1][1]=min;

            max=0;
            min=10;
            for (int i = 0; i < contE; i++)
            {
                if (m3[i]<=min){
                    min = m3[i];
                }
                if (m3[i]>max){
                    max = m3[i];
                }
            }
            maxminM[2][0]=max;
            maxminM[2][1]=min;

            printf("mats\t\tMax\t\tMin\n");

            for (int i = 0; i < 3; i++)
            {
                printf("%s\t\t%.2f\t\t%.2f\n",MatSimp[i],maxminM[i][0],maxminM[i][1]);
            }
            break;
        case 4:

            printf("#\t\tNombre\t\tMatematicas\t\tLenguaje\t\tProgramacion\n");
            for (int i = 0; i < contE; i++)
            {
                if (m1[i]>=6){
                    strcpy(aprep[0],"Aprobado");
                }else{
                    strcpy(aprep[0],"Reprobado");
                }
                if (m2[i]>=6){
                    strcpy(aprep[1],"Aprobado");
                }else{
                    strcpy(aprep[1],"Reprobado");
                }
                if (m3[i]>=6){
                    strcpy(aprep[2],"Aprobado");
                }else{
                    strcpy(aprep[2],"Reprobado");
                }
                
                printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",i,nombres[i],aprep[0],aprep[1],aprep[2]);
            }
            
            break;
            case 5:
                return 0;
        default:
            printf("No existe la opcion\n");
            break;
        }

        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d",&opc1);
    }while(opc1==1);





    return 0;
}