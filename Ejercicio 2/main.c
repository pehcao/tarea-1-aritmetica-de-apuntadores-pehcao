#include <stdlib.h>
#include <stdio.h>

struct pregunta {
	char * descripcion[20];
	int * respuestas[5];
};

struct encuesta {
	char * nombre[20];
	int edad;
	struct pregunta pregs[10];
	int respuestas[10];
};

struct resultados {
	struct encuesta * encuestas;
};



int * realizarPregunta(struct pregunta preg) {
	int resp;
	printf("\n \n \n %s \n", *preg.descripcion);
	printf("Selecciona una de las siguientes respuestas: \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", *(preg.respuestas + i));
		printf("\n");
	}
	resp = rand() % 5;
	printf("Respuesta:  %d \n", *(preg.respuestas + resp));

	return *(preg.respuestas + resp);
}


struct encuesta aplicarEncuesta(struct encuesta enc) {
	for (int i = 0; i < 10; i++) {
		*(enc.respuestas + i) = realizarPregunta(*(enc.pregs + i));
	}
	return enc;
}



void main() {
		time_t t;
	int opcion = 1;
	char nombre[50];
	int edad = 2;
	srand((unsigned)time(&t));
	struct pregunta p1;
	struct pregunta p2;
	struct pregunta p3;
	struct pregunta p4;
	struct pregunta p5;
	struct pregunta p6;
	struct pregunta p7;
	struct pregunta p8;
	struct pregunta p9;
	struct pregunta p10;
	for (int i = 0; i < 6; i++){
		*(p1.respuestas +i) = rand() % 20;
		*(p2.respuestas +i) = rand() % 20;
		*(p3.respuestas +i) = rand() % 20;
		*(p4.respuestas +i) = rand() % 20;
		*(p5.respuestas +i) = rand() % 20;
		*(p6.respuestas +i) = rand() % 20;
		*(p7.respuestas +i) = rand() % 20;
		*(p8.respuestas +i) = rand() % 20;
		*(p9.respuestas +i) = rand() % 20;
		*(p10.respuestas +i) = rand() % 20;
	}
	*p1.descripcion = "Pregunta 1";
	*p2.descripcion = "Pregunta 2";
	*p3.descripcion =  "Pregunta 3";
	*p4.descripcion = "Pregunta 4";
	*p5.descripcion =  "Pregunta 5";
	*p6.descripcion =  "Pregunta 6";
	*p7.descripcion = "Pregunta 7";
	*p8.descripcion = "Pregunta 8";
	*p9.descripcion =  "Pregunta 9";
	*p10.descripcion =  "Pregunta 10";
	struct encuesta encue;
	*(encue.pregs) = p1;
	*(encue.pregs+1) = p2;
	*(encue.pregs+2) = p3;
	*(encue.pregs+3) = p4;
	*(encue.pregs+4) = p5;
	*(encue.pregs+5) = p6;
	*(encue.pregs+6) = p7;
	*(encue.pregs+7) = p8;
	*(encue.pregs+8) = p9;
	*(encue.pregs+9) = p10;


	struct resultados results = { &encue };


	int aplicadas = 0;
	while (opcion > 0) {
		printf("Elige una opcion:\n 1 - Aplicar encuesta \n 2 - Ver Frecuencia de respuestas \n 0 - Salir \n");
		scanf("%d", &opcion);

		if (opcion == 1) {
			printf("Escribe el nombre del encuestado \n");
			scanf("%s", &nombre);
			printf("Escribe la edad del encuestado \n ");

			scanf("%d", &edad);
			encue = aplicarEncuesta(encue);
			*encue.nombre = nombre;
			encue.edad = edad;
			*(results.encuestas + aplicadas) = encue;
			aplicadas++;
		}else if(opcion == 2){
			if(aplicadas < 1){
				printf("Tienes que aplicar encuestas primero");
			}
		}
	}
}