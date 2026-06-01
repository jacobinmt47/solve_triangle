
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <assert.h>


double to_radian(double degrees) {
    return degrees * M_PI / 180.0;
}

double to_degree(double radians) {
    return radians * 180.0 / M_PI;
}

void print_solved(double al, double bl, double cl, double Aa, double Ba, double Ca) {
    printf("the triangle is fully solved\n");
    printf("angle a %lf side a: %lf\n", Aa,al);
    printf("angle b %lf side b: %lf\n", Ba,bl);
    printf("angle c %lf side c: %lf\n", Ca,cl);
}
double law_of_sine_angle(double al,double aa,double bl) {
// calculate the angle using the law of sine return in radians
// al is length of side a
// aa is the angle oppisite of side a
// bl is the the length of side b
    double ar = to_radian(aa);
    double sr = sin(ar)/aa;
    return asin(sr*bl);
}
double law_of_sine_side(double al,double aa,double ba) {
// al is length of side a
// aa is the angle oppisite of side a
// ba is the the angle of side b
    double ar = to_radian(aa);
    double br = to_radian(ba);
    return (al*sin(br))/sin(ar);
}

double law_of_cosine_side(double al, double bl, double angle) {
// al is length of side a
// bl is the length of side b
// angle is the angle between sides a and b
    double ar = to_radian(angle);
    return sqrt(al*al + bl*bl - 2*al*bl*cos(ar));//length of side c
}

double law_of_cosine_angle(double al, double bl, double cl) {
//solves for c
    double c2 = cl*cl;
    double sqrs = al*al+bl*bl;
    double tba  =0-(2*al*bl);
    double cc = (c2-sqrs) / tba;  //cosine of angle c
    return acos(cc);// the angle in radians
}

void solve_sss(double al,double bl, double cl) {
    double aa = law_of_cosine_angle(al,bl,cl);
    double ba = law_of_sine_angle(al,aa,bl);
    double ca = law_of_sine_angle(al,aa,al);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),to_degree(ca));
}

void solve_ssa(double al,double bl, double ca) {
    //solve side side angle
    double cl = law_of_cosine_side(al,bl,ca);
    double aa = law_of_sine_angle(cl,ca,al);
    double ba = law_of_sine_angle(cl,ca,bl);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),ca);
}

void solve_sas(double al,double aa,double bl) {
    double ba = law_of_sine_angle(al,aa,bl);
    double bda = to_degree(ba); // law of sine returns in radians
    double ca = 180 -(bda+aa); // ca in degrees
    double cl = law_of_sine_side(al,aa,ca);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),ca);
}

void solve_aas_nopair(double Aa, double Ba, double Ca, double side_length) {

}
int main(int argc,char** argv) {

//declare variables for the triangle
    double al = 0; // for length of side a
    double bl = 0; // for length of side b
    double cl = 0; // for length of side c

    double Aa = 0; // for angle a
    double Ba = 0;
    double Ca = 0;

// get the values from the user
    int angles = 0;
    int sides = 0;

    printf("enter values for the triangle use zero if you don't know the value\n");
    printf("enter length of side a: ");
    scanf("%lf",&al);
    if(al != 0.0) {
        sides++;
    }
    printf("enter angle of a in degrees: ");
    scanf("%lf",&Aa);
    if(Aa != 0.0) {
        angles++;
    }
    printf("enter length of side b: ");
    scanf("%lf",&bl);
    if(bl != 0.0) {
        sides++;
    }
    printf("enter angle of b in degrees: ");
    scanf("%lf",&Ba);
    if(Ba != 0.0) {
        angles++;
    }
    printf("enter length of side c: ");
    scanf("%lf",&cl);
    if(cl != 0.0) {
        sides++;
    }
    printf("enter angle of c in degrees: ");
    scanf("%lf",&Ca);
    if(Ca != 0.0) {
        angles++;
    }

    printf("all data entered\n");
    if(angles+sides<3) {
        printf("not enough data to solve the triangle\n");
        printf("you need at least 3 values to solve the triangle\n");
    }
    if(sides<1) {
        printf("you need at least 1 side to solve the triangle\n");
    }
    if(angles==3 && sides==3) {
        printf("the triangle is fully solved\n");
        print_solved(al, bl, cl, Aa, Ba, Ca);
        return 0;
    }
// start processing data here

    if(sides == 3 && angles == 0) {
        solve_sss(al,bl,cl);
        return 0;
    }
    if(sides>=2 && angles >=1) {
        printf("figure out if its a ssa triangle or a sas triangle \n ");
        if(al>0 && Aa >0) {
            printf("Aa is a side angle pair\n");
            if(bl != 0) {
                solve_sas(al,Aa,bl);
            }
            else {
                solve_sas(al,Aa,cl);
            }
            return 0;
        }
        if(bl>0 && Ba >0) {
            printf("Ba is the side angle pair\n");
            if(al !=0) {
                solve_sas(bl,Ba,al);
            }
            else {
                solve_sas(bl,Ba,cl);
            }
            return 0;
        }
        if(cl>0 &&  Ca >0) {
            printf("Ca us the side angle pair\n");
            if(al != 0) {
                solve_sas(cl,Ca,al);
                else {
                    solve_sas(cl,Ca,bl);
                }
                return 0;
            }
            printf("it's a ssa triangle\n");
            int side_count = 0;
            double sides[2] = { 0,0 };
            double angle = 0.0;
            if(al > 0) {
                sides[side_count]  = al;
                side_count++;
            }
            if( bl > 0) {
                sides[side_count] = bl;
                side_count++;
            }
            assert(side_count>0);
            // count cl if bl or al haven't been counted
            if( cl > 0 && side_count<2) {
                sides[1] = cl;
            }
            if(Aa > 0 ) {
                angle = Aa;
            }
            if(Ba > 0 ) {
                angle = Ba;
            }
            if(Ca > 0 ) {
                angle = Ca;
            }
            assert(angle != 0.0);
            solve_ssa(sides[0],sides[1],angle);
            return 0;


        }
        if(sides>=1 && angles >=2) {
            printf("solve a aas triangle");
            int angle_count = 0;
            double angles[2] = {0, 0};
            double side_length = 0.0;
            if(Aa != 0.0) {
                angles[angle_count] = Aa;
                angle_count++;
            }

            if(Ba != 0.0) {
                angles[angle_count] = Ba;
                angle_count++;
            }
            if(angle_count<2 && Ca != 0.0) {
                angles[1] = Ca;
            }

            //TODO: create function to solve aas triangle
            // Find angle side pair if they exists

            if (Aa != 0.0 && al != 0.0) {
                printf("Aa is angle pair");
                //TODO solve aas
                return 0;
            }
            if (Ba != 0.0 && bl != 0.0) {
                printf("Ba is angle pair");
                //TODO solve for Ba aas
                return 0;
            }
            if (Ca != 0.0 && cl != 0.0) {
                printf("Ba is angle pair");
                //TODO solve for Ca aas
                return 0;
            }
            if (al != 0.0) {
                solve_aas_nopair(Aa, Ba, Ca, al);
            }
            if (bl != 0.0) {
                solve_aas_nopair(Aa, Ba, Ca, bl);
            }
            if (cl != 0.0) {
                solve_aas_nopair(Aa, Ba, Ca, cl);
            }
            return 0;
        }

        return  0;
    }
