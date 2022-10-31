
struct Rational {

        int num;
        int den;

};
typedef struct Rational Rational;


Rational* new_Rational( int num, int den );

Rational* add_rational( Rational* r1, Rational* r2 );

Rational* mult_rational( Rational* r1, Rational* r2 );

Rational* div_rational( Rational* r1, Rational* r2 );

int compare_rational( Rational* r1, Rational* r2 );

void free_rational( Rational* r );
