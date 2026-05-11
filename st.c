#include<stdio.h>
#include<math.h>

float to_radian(float degrees) {
    return degrees * M_PI / 180.0;
}

float to_degree(float radians) {
    return radians * 180.0 / M_PI;
}

void print_solved(float al, float bl, float cl, float Aa, float Ba, float Ca) {
    printf("the triangle is fully solved\n");
    printf("angle a %g side a: %g\n", Aa,al);
    printf("angle b %g side b: %g\n", Ba,bl);
    printf("angle c %g side c: %g\n", Ca,cl);
}
float law_of_sine_angle(float al,float aa,float bl){
// al is length of side a
// aa is the angle oppisite of side a 
// bl is the the length of side b
    float ar = to_radian(aa);
    float sr = sin(ar)/aa;
    return asin(sr*bl);
}
float law_of_sine_side(float al,float aa,float ba){
// al is length of side a
// aa is the angle oppisite of side a 
// ba is the the angle of side b
    float ar = to_radian(aa);
    float br = to_radian(ba);
    return (al*sin(br))/sin(ar);
}   

float law_of_cosine_side(float al, float bl, float angle) {
// al is length of side a
// bl is the length of side b
// angle is the angle between sides a and b
    float ar = to_radian(angle);
    return sqrt(al*al + bl*bl - 2*al*bl*cos(ar));//length of side c
}

float law_of_cosine_angle(float al, float bl, float cl) {
//solves for c
    float c2 = cl*cl;
    float sqrs = al*al+bl*bl;
    float tba  =0-(2*al*bl);
    float cc = (c2-sqrs) / tba;  //cosine of angle c
    return acos(cc);// the angle in radians
}

void solve_sss(float al,float bl, float cl){
    float aa = law_of_cosine_angle(al,bl,cl);
    float ba = law_of_sine_angle(al,aa,bl);
    float ca = law_of_sine_angle(al,aa,al);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),to_degree(ca));
}

void solve_ssa(float al,float bl, float ca){
    //solve side side angle
    float cl = law_of_cosine_side(al,bl,ca);
    float aa = law_of_sine_angle(cl,ca,al);
    float ba = law_of_sine_angle(cl,ca,bl);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),ca);
}

void solve_sas(float al,float aa,float bl){
    float ba = law_of_sine_angle(al,aa,bl);
    float bda = to_degree(ba);
    float ca = 180 -(bda+aa); // ca in degrees
    float cl = law_of_sine_side(al,aa,ca);
    print_solved(al,bl,cl,to_degree(aa),to_degree(ba),ca);
}
int main(int argc,char** argv) {

//declare variables for the triangle
    float al = 0; // for length of side a
    float bl = 0; // for length of side b
    float cl = 0; // for length of side c

    float Aa = 0; // for angle a
    float Ba = 0;
    float Ca = 0;

// get the values from the user
    int angles = 0;
    int sides = 0;
    printf("enter values for the triangle use zero if you don't know the value\n");
    printf("enter length of side a: ");
    scanf("%G",&al);
    if(al != 0.0) {
        sides++;
    }
    printf("enter angle of a in degrees: ");
    scanf("%G",&Aa);
    if(Aa != 0.0) {
        angles++;
    }
    printf("enter length of side b: ");
    scanf("%G",&bl);
    if(bl != 0.0) {
        sides++;
    }
    printf("enter angle of b in degrees: ");
    scanf("%G",&Ba);
    if(Ba != 0.0) {
        angles++;
    }
    printf("enter length of side c: ");
    scanf("%G",&cl);
    if(cl != 0.0) {
        sides++;
    }
    printf("enter angle of c in degrees: ");
    scanf("%G",&Ca);
    if(Ca != 0.0) {
        angles++;
    }

    printf("all data entered\n");
    if(angles+sides<3){
        printf("not enough data to solve the triangle\n");
        printf("you need at least 3 values to solve the triangle\n");
    }
    if(sides<1){
        printf("you need at least 1 side to solve the triangle\n");
    }
    if(angles==3 && sides==3){
        printf("the triangle is fully solved\n");
        print_solved(al, bl, cl, Aa, Ba, Ca);
    }
    return  0;
}
