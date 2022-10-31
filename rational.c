
#include"rational.h"


#include<stdlib.h>
#include<stdio.h>


// helper functions
int min( int a, int b ) {
        return (a < b) ? a : b;
}

int abs( int a ) {
        return (a < 0) ? -a : a;
}

int gcf( int a, int b ) {
        for (size_t i = min(abs(a), abs(b)); i > 0; i--) {
                if ( a % i == 0 && b % i == 0 ) {
                        return i;
                }
        }

        return abs(a+b); // a or b is zero so return non zero var
}

int lcm( int a, int b ) {
        int f = gcf( a, b );

        return (a/f)*b;
}
// end helper functions



Rational* new_Rational( int num, int den ) {
        Rational* r = (Rational*) malloc( 1 *sizeof(Rational) );

        if (den < 0) {
                r->num = -1*num;
                r->den = -1*den;
        } else {
                r->num = num;
                r->den = den;
        }

        return r;
}

Rational* add_rational( Rational* r1, Rational* r2 ) {
        int m = lcm( r1->den, r2->den );

        int num = (m/r1->den)*r1->num + (m/r2->den)*r2->num;
        int f = gcf( num, m );

        return new_Rational( num/f, m/f );
}

Rational* mult_rational( Rational* r1, Rational* r2 ) {
        int num = r1->num * r2->num;
        int den = r1->den * r2->den;
        int f = gcf( num, den );

        return new_Rational( num/f, den/f );
}

Rational* div_rational( Rational* r1, Rational* r2 ) {

        Rational* tmp = new_Rational( r2->den, r2->num );
        Rational* q = mult_rational( r1, tmp );
        free_rational( tmp );

        return q;
}

int compare_rational( Rational* r1, Rational* r2 ) {

        int m = lcm( r1->den, r2->den );

        return (m/r1->den)*r1->num - (m/r2->den)*r2->num;

}

void free_rational( Rational* r ) {
        free( r );
}
