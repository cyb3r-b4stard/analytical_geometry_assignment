/*The Analytical geometry assignment*/
    /*Made by Ivan Lomikovskiy*/
     /*this program takes an equation of a second order surface
     and a plane x + z = beta and computes the type of curve in the intersection*/
#include <stdlib.h>
#include <stdio.h>

void zero_evaluate(double B, double A, double c);
void nonzero_evaluate(double A, double B, double c);
void surface_type(double A, double B, double C, double alpha);

int main() {
	int n;
	double A, B, C, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %lf %lf %lf", &A, &B, &C, &a, &b);
		surface_type(A, B, C, a);
		printf(", ");
		if ((A + C) == 0) {
			zero_evaluate(B, -2*C*b, a - C*b*b);
		} else {
			nonzero_evaluate(A + C, B, a + C*C*b*b/(A + C) - C*b*b);
		}
	}
	return 0;
}

// prints type of intersection curve in case A + C = 0
void zero_evaluate(double B, double A, double c) {
	if ((A == 0 & c*B > 0)) {
		printf("pair of parallel lines\n");
	} else if ((A ==  0 & c == 0) || (B == 0 && A != 0)) {
		printf("single line\n");
	} else if (A != 0 && B != 0) {
		printf("parabola\n");
	} else {
		printf("empty set\n");
	}
}

// prints type of intersection curve in case A + C != 0
void nonzero_evaluate(double A, double B, double c) {
	if ((A > 0 && c > 0 && B > 0) || (A < 0 && B < 0 && c < 0)) {
		printf("ellipse\n");
	} else if (A*B < 0 && c != 0) {
		printf("hyperbola\n");
	} else if (A*B < 0 && c == 0) {
		printf("pair of intersecting lines\n");
	} else if ((B == 0 && c*A > 0) || (A == 0 && c*B > 0)) {
		printf("pair of parallel lines\n");
	} else if (B == 0 && c == 0) {
		printf("single line\n");
	} else if (A*B > 0 && c == 0) {
		printf("single point\n");
	} else {
		printf("empty set\n");
	}
}

// function for printing 2d order surface (Ax^2 + By^2 + Cz^2 = alpha) type
void surface_type(double A, double B, double C, double alpha) {
	if (A > 0 && B > 0 && C > 0 && alpha > 0 || A < 0 && B < 0 && C < 0 && alpha < 0) {
		printf("ellipsoid");
	} else if (A > 0 && B > 0 && C < 0 && alpha > 0 || A < 0 && B < 0 && C > 0 && alpha < 0 || 
				A > 0 && B < 0 && C > 0 && alpha > 0 || A < 0 && B > 0 && C < 0 && alpha < 0 || 
				A < 0 && B > 0 && C > 0 && alpha > 0 || A > 0 && B < 0 && C < 0 && alpha < 0) {
		printf("one-sheet hyperboloid");
	} else if (A > 0 && B > 0 && C < 0 && alpha < 0 || A < 0 && B < 0 && C > 0 && alpha > 0 ||
				A > 0 && B < 0 && C > 0 && alpha < 0 || A < 0 && B > 0 && C < 0 && alpha > 0 || 
				A < 0 && B > 0 && C > 0 && alpha < 0 || A > 0 && B < 0 && C < 0 && alpha > 0) {
		printf("two-sheet hyperboloid");
	} else if (A > 0 && B > 0 && C < 0 && alpha == 0 || A < 0 && B < 0 && C > 0 && alpha == 0 || 
    		A > 0 && B < 0 && C > 0 && alpha == 0 || A < 0 && B > 0 && C < 0 && alpha == 0 || 
    		A < 0 && B > 0 && C > 0 && alpha == 0 || A > 0 && B < 0 && C < 0 && alpha == 0) {
    	printf("cone");
    } else if (A > 0 && B > 0 && C == 0 && alpha > 0 || A < 0 && B < 0 && C == 0 && alpha < 0 || 
    		A > 0 && B == 0 && C > 0 && alpha > 0 || A < 0 && B == 0 && C < 0 && alpha < 0 || 
    		A == 0 && B > 0 && C > 0 && alpha > 0 || A == 0 && B < 0 && C < 0 && alpha < 0) {
    	printf("elliptic cylinder");
    } else if (A > 0 && B < 0 && C == 0 && alpha > 0 || A < 0 && B > 0 && C == 0 && alpha < 0 ||
    		A < 0 && B > 0 && C == 0 && alpha > 0 || A > 0 && B < 0 && C == 0 && alpha < 0 || 
    		A > 0 && B == 0 && C < 0 && alpha > 0 || A < 0 && B == 0 && C > 0 && alpha < 0 || 
    		A < 0 && B == 0 && C > 0 && alpha > 0 || A > 0 && B == 0 && C < 0 && alpha < 0 || 
    		A == 0 && B > 0 && C < 0 && alpha > 0 || A == 0 && B < 0 && C > 0 && alpha < 0 || 
    		A == 0 && B < 0 && C > 0 && alpha > 0 || A == 0 && B > 0 && C < 0 && alpha < 0) {
    	printf("hyperbolic cylinder");
    } else if (A > 0 && B > 0 && C > 0 && alpha == 0 || A < 0 && B < 0 && C < 0 && alpha == 0) {
    	printf("single point");
    } else if (A > 0 && B == 0 && C < 0 && alpha == 0 || A < 0 && B == 0 && C > 0 && alpha == 0 || 
    		A > 0 && B < 0 && C == 0 && alpha == 0 || A < 0 && B > 0 && C == 0 && alpha == 0 || 
    		A == 0 && B > 0 && C < 0 && alpha == 0 || A == 0 && B < 0 && C > 0 && alpha == 0) { 
    	printf("pair of intersecting planes");
	} else if (A > 0 && B == 0 && C == 0 && alpha > 0 || A < 0 && B == 0 && C == 0 && alpha < 0 ||
    		A == 0 && B > 0 && C == 0 && alpha > 0 || A == 0 && B < 0 && C == 0 && alpha < 0 || 
    		A == 0 && B == 0 && C > 0 && alpha > 0 || A == 0 && B == 0 && C < 0 && alpha < 0) {
    	printf("pair of parallel planes");
    } else if (A > 0 && B > 0 && C == 0 && alpha == 0 || A < 0 && B < 0 && C == 0 && alpha == 0 || 
    		A > 0 && B == 0 && C > 0 && alpha == 0 || A < 0 && B == 0 && C < 0 && alpha == 0 || 
    		A == 0 && B > 0 && C > 0 && alpha == 0 || A == 0 && B < 0 && C < 0 && alpha == 0) {
    	printf("single line");
    } else if (A > 0 && B == 0 && C == 0 && alpha == 0 || A < 0 && B == 0 && C == 0 && alpha == 0 ||
    		A == 0 && B > 0 && C == 0 && alpha == 0 || A == 0 && B < 0 && C == 0 && alpha == 0 || 
    		A == 0 && B == 0 && C > 0 && alpha == 0 || A == 0 && B == 0 && C < 0 && alpha == 0) {
    	printf("single plane");
    } else {
    	printf("empty set");
    }
}
