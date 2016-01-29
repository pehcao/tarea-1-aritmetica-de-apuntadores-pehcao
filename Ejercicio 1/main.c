
#include <stdio.h>
#include <stdlib.h>
#define NUM_MAX_TRIPULANTES 10
#define NUM_BARCOS 10
#define NUM_PROP 5
typedef struct{
    char * nombre;
    char * apellido;
    char * edad;
    char * rol;
    int asignado;
}Tripulante;

typedef struct{
    char * propietarios[NUM_PROP];
    char * nombre;
    char * eslora;
    char * manga;
    int num_tripulantes;
    int num_tripulantes_A_bordo;
    int num_propietarios;
    Tripulante * tripulacion[NUM_MAX_TRIPULANTES];
}Barco;
typedef struct{
    Barco * barcos[NUM_BARCOS];
    int num_barcos_actual;
}Puerto;
void imprimeTripulantes(Barco *);
void imprimePropietarios (Barco * ship){
    for (int i=0; i < ship->num_propietarios; i++) {
        printf("--%s\n",*(ship->propietarios+i));
    }
}
void imprimeBarco(Barco * ship){
    
    printf("-------------Barco %s----------------------------------\n",ship->nombre);
    printf("Nombre: %s      Manga: %s\nTripulantes a bordo: %d      Eslora: %s\n",ship->nombre,ship->manga,ship->num_tripulantes_A_bordo,ship->eslora);
    printf("Propietarios: \n");
    imprimePropietarios(ship);
    imprimeTripulantes(ship);
    printf(".......................................................\n");
    
}

void imprimeTripulantes(Barco * ship){
    printf("Tripulantes\n");
    printf("|--------------------------------------------------|\n");
    printf("| ID | Nombre       | Apellido     | Edad | Rol    |\n");
    printf("|--------------------------------------------------|\n");
    for (int i=0; i < ship->num_tripulantes_A_bordo; i++ ){
        if (*(ship->tripulacion+i)!=NULL)
        printf("|%d : | %s | %s | %s | %s |\n",i,ship->tripulacion[i]->nombre,ship->tripulacion[i]->apellido,ship->tripulacion[i]->edad,ship->tripulacion[i]->rol);
    }
}
void agregaApuerto(Barco * ship,Puerto * puerto){
    if (puerto->num_barcos_actual <= NUM_BARCOS){
      
            *(puerto->barcos+puerto->num_barcos_actual) = ship;
            puerto->num_barcos_actual++;
    }
    else
        printf("El puerto esta lleno");
    
    
}
void agregaPropietario (Barco * ship,char * prop){
    *(ship->propietarios + ship->num_propietarios) = prop;
    ship->num_propietarios++;
}
void imprimePuerto(Puerto * p){
    printf("Puerto\n");
    printf("------------------");
    printf("Barcos:\n");
    for (int i=0; i< p->num_barcos_actual; i++) {
        imprimeBarco(*(p->barcos+i));
    }
    
}
void agregaTripulante(Tripulante * a, Barco * b, char * nombre, char * apellido, char * edad, char* rol){
    a->asignado = 0;
    if( b->num_tripulantes_A_bordo <= b->num_tripulantes  &&  a->asignado != 1 )
    {
        
        a->nombre = nombre;
        a->apellido = apellido;
        a->edad = edad;
        a->rol = rol;
        a->asignado = 1;
        
        *(b->tripulacion + b->num_tripulantes_A_bordo) = a;
        b->num_tripulantes_A_bordo++;
    }
    else
    {
        printf("El barco %s está lleno\n",b->nombre);
        imprimeBarco(b);
    }
}
void eliminaTripulante(Tripulante * a, Barco * b){
    for (int i=0; i < b->num_tripulantes_A_bordo; i++)
    {
        if (*(b->tripulacion+i) == a ){
            printf("Se elimina el tripulante: %s %s\n",b->tripulacion[i]->nombre,b->tripulacion[i]->apellido);
            *(b->tripulacion+i) = NULL;
            b->num_tripulantes_A_bordo--;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Puerto * puerto1 = (Puerto *)malloc(sizeof(Puerto));
    Puerto * puerto2 = (Puerto *)malloc(sizeof(Puerto));

    Barco * barco1 = (Barco *)malloc(sizeof(Barco));
    Barco * barco2 = (Barco *)malloc(sizeof(Barco));
    Barco * barco3 = (Barco *)malloc(sizeof(Barco));
    
    barco1->num_propietarios = 0;
    barco2->num_propietarios = 0;
    barco3->num_propietarios = 0;


    barco1->num_tripulantes = 10;
    barco1->nombre = "Voyager 123";
    barco1->eslora = "Eslora 1";
    barco1->manga = "Manga";
    agregaPropietario(barco1, "Bill Gates");
    agregaPropietario(barco1, "Steve Jobs");
    //*(barco1->propietarios) = "Bill Gates";
    //*(barco1->propietarios+1) = "Steve Jobs";
    
    barco2->num_tripulantes = 1;
    barco2->nombre = "Queen Mary 2";
    barco2->eslora = "Eslora 2";
    barco2->manga = "Manga2";
    agregaPropietario(barco2, "Bob Esponja");
    agregaPropietario(barco2, "Patricio");
    //*(barco2->propietarios) = "Bob Esponja";
    //*(barco2->propietarios+1) = "Patricio";
    
    barco3->num_tripulantes = 2;
    barco3->nombre = "Titanic";
    barco3->eslora = "Eslora 3";
    barco3->manga = "Manga3";
    agregaPropietario(barco3, "Spock");
    agregaPropietario(barco3, "Darth Vader");
    agregaPropietario(barco3, "Abraham");
    //*(barco3->propietarios) = "Spock";
    //*(barco3->propietarios+1) = "Darth Vader";
    
    puerto1->num_barcos_actual = 0;
    puerto2->num_barcos_actual = 0;

    
    barco1->num_tripulantes_A_bordo = 0;
    barco2->num_tripulantes_A_bordo = 0;
    barco3->num_tripulantes_A_bordo = 0;
    
    Tripulante * t1 = (Tripulante *)malloc(sizeof(Tripulante));//Haloja 10 tripulantes
    Tripulante * t2 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t3 = (Tripulante *)malloc(sizeof(Tripulante));//Haloja 10 tripulantes
    Tripulante * t4 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t5 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t6 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t7 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t8 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t9 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t10 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t11 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t12 = (Tripulante *)malloc(sizeof(Tripulante));
    Tripulante * t13 = (Tripulante *)malloc(sizeof(Tripulante));


    agregaTripulante(t1, barco1, "Tripulante 1", "Tripulante 1", "10", "Capitan");
    agregaTripulante(t2, barco1, "Tripulante 2", "Tripulante 2", "11", "FCapitan");
    agregaTripulante(t3, barco1, "Tripulante 3", "Tripulante 3", "12", "Cubierta");
    agregaTripulante(t4, barco1, "Tripulante 4", "Tripulante 4", "13", "Mesero");
    agregaTripulante(t5, barco1, "Tripulante 5", "Tripulante 5", "14", "Mesero");
    agregaTripulante(t6, barco1, "Tripulante 6", "Tripulante 6", "15", "Mesero");
    agregaTripulante(t7, barco1, "Tripulante 7", "Tripulante 7", "16", "Mesero");
    agregaTripulante(t8, barco1, "Tripulante 8", "Tripulante 8", "17", "Mesero");
    agregaTripulante(t9, barco1, "Tripulante 9", "Tripulante 9", "18", "Mesero");
    agregaTripulante(t10, barco1, "Tripulante 10", "Tripulante 10", "19", "Cocinero");
    agregaTripulante(t11, barco2, "Tripulante 11", "Tripulante 11", "20", "Cocinero");
    agregaTripulante(t12, barco3, "Tripulante 12", "Tripulante 12", "21", "Cocinero");
    agregaTripulante(t13, barco3, "Tripulante 13", "Tripulante 13", "22", "Cocinero");

    
    imprimeBarco(barco1);
    imprimeBarco(barco2);
    imprimeBarco(barco3);
    
    eliminaTripulante(t8,barco1);
    agregaTripulante(t8, barco1, "Tripulante 8", "Tripulante 8", "17", "Mesero");
    imprimeBarco(barco1);
    printf("*******************\n");
    
    agregaApuerto(barco1, puerto1);
    agregaApuerto(barco2, puerto1);
    imprimePuerto(puerto1);
    
    agregaApuerto(barco3, puerto2);
    imprimePuerto(puerto2);
    

    free(puerto1);
    free(puerto2);

    
    free(barco1);
    free(barco2);
    free(barco3);
    
    free(t1);
    free(t2);
    free(t3);
    free(t4);
    free(t5);
    free(t6);
    free(t7);
    free(t8);
    free(t9);
    free(t10);
    free(t11);
    free(t12);
    free(t13);
    
    return 0;
}