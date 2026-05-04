#include<stdio.h>

int main(int argc,char** argv){

//declare variables for the triangle
	float al = 0; // for length of side a
	float bl = 0; // for length of side b
	float cl = 0; // for length of side c

	float Aa = 0; // for angle a
	float Ba = 0;
	float Ca = 0;

// get the values from the user
	printf("enter length of side a");
	scanf("%G",&al);
	printf("enter angle of a in degrees");
	scanf("%G",&Aa);
	printf("enter length of side b");
	scanf("%G",&bl);
	printf("enter angle of b in degrees");
	scanf("%G",&Ba);
	printf("enter length of side c");
	scanf("%G",&cl);
	printf("enter angle of c in degrees");
	scanf("%G",&Ca);

	printf("all data entered");
	return  0;
}
