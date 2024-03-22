#pragma once

struct complejo
{
    float x;//real
    float y;//Imaginaria
};
//

struct complejo Sumacpx(struct complejo c1,struct complejo c2);
struct complejo restacpx(struct complejo c1,struct complejo c2);
struct complejo MultCpx(struct complejo c1,struct complejo c2);
struct complejo DivCpx (struct complejo c1,struct complejo c2);
float ModCpx(struct complejo c1);
float ArgCpx(struct complejo c1);
//void Rte(struct complejo *complejo);
float angulo (struct complejo complejo);
int cuadrante(struct  complejo C1);


//Suma 
//resta
//multiplicacion
//division
//conjugado.

