
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char * nombre;
    char * apellidos;
    int edad;
    char * telefono;
}Paciente;

typedef struct{
    int estatus;
}Cama;

typedef struct{
    char * nombre;
    int num_camas;
    int camas_oc;
    Paciente * pacientes;
    Cama * ca;
}Hospital;

void agregarPaciente(Paciente * p,Hospital * h, char * nombre, char * apellido, char * telefono, int edad);
void altaPaciente(Paciente * p,Hospital * h);
void masCamas(Hospital * h);
void imprimeHospital(Hospital * a);

void masCamas(Hospital * h){
    Cama * c = h->ca;
    Paciente * p = h->pacientes;
    int  num = h->num_camas;
    h->num_camas = h->num_camas + 5;
    if(realloc(c, num*sizeof(Cama))&&realloc(p, num*sizeof(Cama))){
        printf("Realocado");
    }
    else
        printf("No se pudo expandir el arreglo");
    //p = (Paciente *) realloc(p, h->num_camas * sizeof(Paciente));
    
}
void agregarPaciente(Paciente * p, Hospital * h, char * nombre, char * apellido, char * telefono, int edad){

    p->nombre = nombre;
    p->apellidos = apellido;
    p->telefono = telefono;
    p->edad = edad;
    
    int indice = h->camas_oc;
    for (int i=0; i< h->camas_oc; i++) {
        if((h->pacientes+i) == NULL)
            indice = i;
    }
    //printf("Indice: %d\n",indice);
    
    if (h->camas_oc == h->num_camas){
        printf("No hay camas disponibles se agregan 5 mas!, Camas actuales: %d\n",h->num_camas);
        masCamas(h);
        printf("Camas disponibles: %d\n",h->num_camas);
    }
    *(h->pacientes+indice) = *p;
    h->camas_oc++;
    h->ca = malloc(100*sizeof(Cama));
    (*(h->ca+indice)).estatus = 1;
    
}
void altaPaciente(Paciente * p,Hospital * h){
    Cama * a;
    Paciente *p2;
    for (int i = 0; i < h->camas_oc; i++) {
        if ((h->pacientes+i) == p)
        {
            printf("El paciente esta en el indice %d \n",i);
            p2 = (h->pacientes+i);
            p2 = NULL;
            a = &h->ca[i];
            a->estatus = 0;
            //a->paciente = NULL;
            h->camas_oc--;
        }
    }
}
void imprimeHospital(Hospital * a){
    printf("Hospital %s\n",a->nombre);
    printf("Camas Disponibles: %d\n",a->num_camas-a->camas_oc);
    printf("...........................................\n");
    printf("Pacientes:\n");
    for (int i=0; i< a->camas_oc; i++) {
        printf("%s,%s alojado en la cama numero %d\n",(a->pacientes+i)->nombre,(a->pacientes+i)->apellidos,i);
    }
    

}
int main(int argc, const char * argv[]) {
    
    Hospital * h = (Hospital *)malloc(50*sizeof(Hospital));
    Cama * camasEnHospital;
    //camasEnHospital = h->camas;
    //Inicializando
    h->num_camas = 5;
    h->camas_oc = 0;
    h->nombre = "ABC";
    //Alocando memoria
    camasEnHospital = malloc((h->num_camas)*sizeof(Cama));
    //h->camas = realloc(h->camas, (h->num_camas)*sizeof(Cama));
   
    h->pacientes = (Paciente *)malloc((h->num_camas)*sizeof(Paciente));
    
    //Pacientes
    Paciente * p = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p1 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p2 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p3 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p4 = (Paciente *)malloc(sizeof(Paciente));
    /*Paciente * p5 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p6 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p7 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p8 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p9 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p10 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p11 = (Paciente *)malloc(sizeof(Paciente));
    Paciente * p12 = (Paciente *)malloc(sizeof(Paciente));*/
    
   

    
   
    agregarPaciente(p, h, "Steve1", "Jobs", "551515112", 50);
    agregarPaciente(p1, h, "Steve2", "Jobs", "551515112", 50);
    agregarPaciente(p2, h, "Steve3", "Jobs", "551515112", 50);
    agregarPaciente(p3, h, "Steve4", "Jobs", "551515112", 50);
    agregarPaciente(p4, h, "Steve5", "Jobs", "551515112", 50);
    //agregarPaciente(p5, h, "Steve6", "Jobs", "551515112", 50);
    //agregarPaciente(p6, h, "Steve7", "Jobs", "551515112", 50);
    altaPaciente(p3,h);
    //agregarPaciente(p3, h, "Steve4", "Jobs", "551515112", 50);
    //altaPaciente(p4, h);
    
    
    
    
    for (int i=0;i < h->camas_oc; i++){
        //if ((h->ca+i)->estatus != 0) {
            printf("Cama [%d]: %s, Estatus: %d \n",i,(h->pacientes+i)->nombre,(h->ca+i)->estatus);
        //}
    }
 
    free(p);
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(h);
    return 0;
}