#include <stdio.h>
#include <math.h>

double areaTriangulo(double x1, double y1, double x2, double y2, double x3, double y3){
	double area=0.5f*(x1*y2+y1*x3+x2*y3-y1*x2-x1*y3-y2*x3);
	return area;
}

double areaPoligono(int vertices,double x1,double y1,double x2,double y2){
	double x3,y3;
	scanf("%lf %lf",&x3,&y3);
	printf("%f :%f :%f :%f :%f :%f\n\n",x1,y1,x2,y2,x3,y3);
	if (vertices==3){
		return areaTriangulo(x1,y1,x2,y2,x3,y3);
	}
		return areaPoligono(vertices-1,x1,y1,x3,y3)+areaTriangulo(x1,y1,x2,y2,x3,y3);
}

int main(){

	double x1,x2,y1,y2;
	int numeroVertices=1;
	double poligono;

	while (numeroVertices!=0){
		scanf("%d",&numeroVertices);
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		poligono=(areaPoligono(numeroVertices,x1,y1,x2,y2));
		printf("%f\n",poligono);
}
return 0;
}

/*p1 vira o último ponto*/
