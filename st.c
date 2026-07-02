
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
    printf("aa as radians %lf",ar);
    double sr = sin(ar)/al;
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
    print_solved(al,bl,cl,aa,bda,ca);
}

void solve_aas_nopair(double Aa, double Ba, double Ca, double side_length) {
    if(Aa == 0.0) {
        //assume side_length is a because there is no pair
        double taa = 180.0-(Ba+Ca);
        double bl = law_of_sine_side(side_length, taa, Ba);
        double cl = law_of_sine_side(side_length, taa, Ca);
        print_solved(side_length, bl, cl, taa, Ba, Ca);
        return;
    }
    if(Ba == 0.0) {
        //assume side_length is b because there is no pair
        double tba = 180.0-(Aa+Ca);
        double al = law_of_sine_side(side_length, tba, Aa);
        double cl = law_of_sine_side(side_length, tba, Ca);
        print_solved(al, side_length, cl, Aa, tba, Ca);
        return;
    }
    if(Ca == 0.0) {
        //assume side_length is c because there is no pair
        double tca = 180.0-(Aa+Ba);
        double al = law_of_sine_side(side_length, tca, Aa);
        double bl = law_of_sine_side(side_length, tca, Ba);
        print_solved(al, bl, side_length, Aa, Ba, tca);
        return;
    }

}

void solve_aas_pair(double a,double b,double side_a) {
    // a and b must be in degress not radians
    //both a and b must be between 0 and 180 degress
    double c = 180 - (a+b);
    double side_b = law_of_sine_side(side_a,a,b);
    double side_c = law_of_sine_side(side_a,a,c);
    print_solved(side_a, side_b, side_c, a, b, c);
}

void work_on_aas(double al,double Aa,double bl, double Ba, double cl,double Ca, int sides, int angles) {
    if(sides>=1 && angles >=2) {
        printf("solve a aas triangle");
        //TODO: create function to solve aas triangle
        // Find angle side pair if they exists

        if (Aa != 0.0 && al != 0.0) {
            printf("Aa is angle pair");
            if(Ba != 0.0) {
                solve_aas_pair(Aa, Ba, al);
                return ;
            }
            if(Ca != 0.0) {
                solve_aas_pair(Aa, Ca, al);
            }
            return ;
        }
        if (Ba != 0.0 && bl != 0.0) {
            printf("Ba is angle pair");
            if( Aa != 0.0) {
                solve_aas_pair(Ba, Aa, bl);
                return ;
            }
            if(Ca != 0.0) {
                solve_aas_pair(Ba, Ca, bl);
            }
            return ;
        }
        if (Ca != 0.0 && cl != 0.0) {
            printf("Ca is angle pair");
            if(Aa != 0.0) {
                solve_aas_pair(Ca, Aa, cl);
                return ;;
            }
            if(Ba != 0.0) {
                solve_aas_pair(Ca, Ba, cl);
            }
            return ;
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
        return ;
    }
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
    //print as a debug the number of sides and angles
    printf("sides: %i angles: %i \n", sides, angles);
    if(angles+sides<3) {
        printf("not enough data to solve the triangle\n");
        printf("you need at least 3 values to solve the triangle\n");
    }
    if(sides<1) {
        printf("you need at least 1 side to solve the triangle\n");
    }
    if(angles==3 && sides==3) {
        printf("all sides entered! \n");
        print_solved(al, bl, cl, Aa, Ba, Ca);
        return 0;
    }
// start processing data here

    if(sides == 3 && angles == 0) {
        solve_sss(al,bl,cl);
        return 0;
    }
    // for debug
    printf(" al: %lf  Aa: %lf \n",al,Aa);
    if(sides>=2 && angles >=1) {
        printf("figure out if its a ssa triangle or a sas triangle \n ");

        if(al>0 && Aa >0) {
            printf("Aa is a side angle pair\n");
            if(bl != 0) {
                solve_sas(al,Aa,bl);
                printf("line: %i \n",__LINE__);
            }
            else {
                solve_sas(al,Aa,cl);
            }
            return 0; // exit so as to not call bl && Ba
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
            }
            else {
                solve_sas(cl,Ca,bl);
            }
            return 0;
        }
        printf("it's a ssa triangle\n");
        int side_count = 0;
        double tsides[2] = { 0,0 };
        double angle = 0.0;
        if(al > 0) {
            tsides[side_count]  = al;
            side_count++;
        }
        if( bl > 0) {
            tsides[side_count] = bl;
            side_count++;
        }
        assert(side_count>0);
        // count cl if bl or al haven't been counted
        if( cl > 0 && side_count<2) {
            tsides[1] = cl;
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
        solve_ssa(tsides[0],tsides[1],angle);
        return 0;

    }
    printf("call work on aas \n");
    work_on_aas(al, Aa, bl, Ba, cl, Ca, sides, angles);
    return  0;
}
