//
//  main.c
//  PBR
//
//  Created by brandon kehl on 7/23/15.
//  Copyright (c) 2015 bignerdranch. All rights reserved.
//

#include <stdio.h>
#include <math.h>
void metersToFeetAndInches(double meters,unsigned int *ftPtr, double *inPtr){
    
    // This function assumes meters is non-negative
    
    // Convert the number of meters into a floating-point number of feet
    double rawFeet = meters * 3.281; // Turns supplied number of Meters(3.0) to feet
    
    // Calculate inches
    double feet= modf(rawFeet,&rawFeet); //Splits inches and feet apart after meter to feet calculation
    double inches = feet * 12.0; //Multiplys feet by 12 to make into inches
    
    
    printf("Storing %f to the address %p\n"  ,rawFeet, &rawFeet); //Store just feet WITHOUT inches to an address
    *ftPtr = rawFeet; // Lets us be able to call address later on

    // Stores inches at address
    printf("Storing %.2f to the address %p\n", inches, &inches);
    *inPtr = inches;
    
}
int main(int argc, const char * argv[]){
    double meters = 3.0;//Supplied number of meters for use in calculation
    unsigned int feet;
    double inches;
    metersToFeetAndInches(meters, &feet, &inches);
    printf("%.1f meters is equal to %d feet and %.1f inches.", meters,feet,inches); //Calls and prints
    return 0;
}
