#include"NewLib.h"

#include <math.h>

struct complejo Sumacpx(struct complejo c1,struct complejo c2)
{
   struct complejo aux;
   aux.x=(c1.x+c2.x);
   aux.y=(c1.y+c2.y);
   return aux;
}

struct complejo restacpx(struct complejo c1,struct complejo c2)
{
    struct complejo aux;
    aux.x=(c1.x-c2.x);
    aux.y=(c1.y-c2.y);
    return aux;
}

struct complejo MultCpx(struct complejo c1,struct complejo c2)
{
    struct complejo aux;
    aux.x=((c1.x*c2.x)+((c1.y*c2.y)*(-1)));
    aux.y=(c1.x*c2.y+c1.y*c2.x);
    return aux;
}

struct complejo DivCpx (struct complejo c1,struct complejo c2)
{
  struct complejo  aux;
  float divaux=(ModCpx(c1)/ModCpx(c2));  //parte numerica
  float newang=(angulo(c1)-angulo(c2));  //angulo
  aux.x = divaux * cos(newang);          // Nuevo X
  aux.y = divaux * sin(newang);          // Nuevo Y
   /* struct complejo aux;
    r=c1.x*c2.x;
    r2=c1.y*(-1*c2.y);
    i1=c1.x*(-1*c2.y);
    i2=c1.y*c2.x;

    x=r1-r2;
    y=i1+i2;


    a=pow((c1.x)2);
    b=pow((c1.y)2);
    d=a+b;
    struct complex c
    c.x=(x)/d;
    c.y=(y)/d;*/

    return (aux); // retorno la estructura con componentes de la division. 
}


float ModCpx(struct complejo c1)
{
    return (sqrt(pow(c1.x,2)+pow(c1.y,2)));
}

float ArgCpx(struct complejo c1)
{
   return (atan(c1.y/c1.x));
}

//--------------------------------------------------------------------------------------------------------------//
void Rte(struct complejo C1) //ver por que no copila
{
     float Mod = ModCpx(C1);
     float Ang = angulo(C1);
     C1.x = ( Mod * cos( Ang + 90 ) );
     C1.y = ( Mod * sin( Ang + 90 ) );
}

float angulo (struct complejo complejo)
{
    int aux;
    aux = cuadrante (complejo);

    switch(aux)
	{
	case 1:
		return (atan(complejo.y/complejo.x));
		break;
	case 2:
		return ((atan(complejo.x/complejo.y)*(-1))+90);
		break;
	case 3:
		return ((complejo.y/complejo.x)+180);
		break;
	case 4:
		return(atan(complejo.x/complejo.y)*(-1)+270);
		break;
	default:
		break;
	}
}

int cuadrante(struct complejo C1)
{
   if(C1.x>0)
   {
      if(C1.y>0)//primer cuadrante
      {
        return 1;
      }
      else// cuarto cuadrante
      {
        return 4;
      }
   }
   else
   {
      if(C1.y>0)//segundo cuadrante
      {
        return 2;
      }
      else  //tercer cuadrante
      {
        return 3;
      }
   }
}
