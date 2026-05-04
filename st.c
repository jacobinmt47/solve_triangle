#include<stdio.h>

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
    printf("enter values for the triangle use zero if you don't know the value")
    printf("enter length of side a");
    scanf("%G",&al);
    if(al != 0) {
        sides++;
    }
    printf("enter angle of a in degrees");
    scanf("%G",&Aa);
    if(Aa != 0) {
        angles++;
    }
    printf("enter length of side b");
    scanf("%G",&bl);
    if(bl != 0) {
        sides++;
    }
    printf("enter angle of b in degrees");
    scanf("%G",&Ba);
    if(Ba != 0) {
        angles++;
    }
    printf("enter length of side c");
    scanf("%G",&cl);
    if(cl != 0) {
        sides++;
    }
    printf("enter angle of c in degrees");
    scanf("%G",&Ca);
    if(Ca != 0) {
        angles++;
    }

    printf("all data entered");
    if(angles+side<3){
        printf("not enough data to solve the triangle");
        printf("you need at least 3 values to solve the triangle");
    }
    if(sides<1){
        printf("you need at least 1 side to solve the triangle");
    }
    return  0;
}
