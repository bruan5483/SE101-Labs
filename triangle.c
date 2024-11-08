/*******************************************************************************/
/*                                                                             */
/* Program: Triangle                                                           */
/* Input:  Exactly 6 floating point numbers, interpreted as three Cartestian   */
/*         points.                                                             */
/* Output: The area of the triangle formed by the input points is printed on   */
/*         stdout.                                                             */
/*                                                                             */
/* Author: PASW; 17 July 2018                                                  */
/*                                                                             */
/* Change history                                                              */
/* 17 July 2018; PASW: Initial version                                         */
/* 28 Sept 2018; PASW: Added slope output, comments, broke into functions      */
/* 17 Aug 2023; PASW: reduced tojust triangle area; changed to C               */
/*                                                                             */

#include <stdio.h>                    /* printf */
#include <math.h>                     /* sqrt   */
#include <stdlib.h>                   /* atof   */
#include <ctype.h>                    /* isdigit */
#include <stdbool.h>                  /* bool   */

#define EXPECTED_ARG_COUNT 7          /* 6 plus the program name */

/*******************************************************************************/
/*                                                                             */
/* outputMessage()                                                             */
/*                                                                             */

void outputMessage(const float x1, const float y1,
                   const float x2, const float y2,
                   const float x3, const float y3,
                   const float area) {

  // Limit the number of decimal places in area to 3 to avoid rounding error with floating point numbers
  // i.e. area of (3,0), (0,1), (2,4) is 5.500 rather than 5.499999
  printf("The area of the triangle formed by points (%.3f,%.3f), (%.3f,%.3f), and (%.3f,%.3f) is: %.3f\n",
	 x1, y1,
	 x2, y2,
	 x3, y3,
	 area);

  return;
}

/*******************************************************************************/
/*                                                                             */
/* distance()                                                                  */
/* Inputs:                                                                     */
/* (x1,y1), (x2,y2): unvalidated Cartesian coordinates                         */
/* Output:                                                                     */

// The distance between said coordinates.
//

float distance(const float x1, const float y1,
               const float x2, const float y2) {
  return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

/*******************************************************************************/
/*                                                                             */
/* triangleArea()                                                              */
/* Inputs:                                                                     */
/* s1, s2, s3: lengths of the three sides                                      */
/* Output:                                                                     */
/* The area of the triangles.                                                  */
/*                                                                             */

float triangleArea(const float s1, const float s2, const float s3) {
  float s = 0.5*(s1+s2+s3);
  float area = sqrt(s*(s-s1)*(s-s2)*(s-s3));
  return area;
}

// Function to check if a string is a valid integer or floating point number
int isValidNumber(const char* str) {
    int hasDecimalPoint = 0;
    int hasDigits = 0;

    // Check for negative sign at the start of a number
    if (*str == '-') {
        str++;
    }

    // Check each character in the string
    while (*str) {
        if (*str == '.') {
            if (hasDecimalPoint) {
                // Multiple decimal points are invalid
                return 0;
            }
            hasDecimalPoint = 1;
        } else if (!isdigit(*str)) {
            // If it's not a digit, it's invalid
            return 0;
        } else {
            hasDigits = 1;
        }
        str++;
    }

    // Ensure there was at least one digit
    return hasDigits;
}

// Function to check if the three points are the same
bool samePoint(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
    if ((x1-x2<0.001 && x2-x1<0.001) && (x2-x3<0.001 && x3-x2<0.001) && (x1-x3<0.001 && x3-x1<0.001) && (y1-y2<0.001 && y2-y1<0.001) && (y2-y3<0.001 && y3-y2<0.001) && (y1-y3<0.001 && y3-y1<0.001)) {
        printf("The three points form a single point\n");
        return true;
    }
    return false;
}

// Function to check if the three points form a line
bool formLine(const float x1, const float y1, const float x2, const float y2, float area) {
  // if the area of the triangle is 0, the points form a line or a point, but we check for a point before the function call in main
    if (area == 0) {
        printf("The three points form a line\n");
        if (x1-x2<0.001 && x2-x1<0.001) printf("The slope of the line is: undefined\n");
        else printf("The slope of the line is: %.3f\n", (y2-y1)/(x2-x1));
        return true;
    }
    return false;
}

/*******************************************************************************/
/*                                                                             */
/* main()                                                                      */
/*                                                                             */

int main(const int argc, const char* const argv[]) {

  // Check if the number of arguments passed is correct
  if (argc != EXPECTED_ARG_COUNT) {
    printf("Expected %d inputs; received %d\n", 6, argc - 1);
    return 0;
  }

  // Check that each argument is a valid integer or floating point number
    for (int i = 1; i <= 6; i++) {
        if (!isValidNumber(argv[i])) {
            printf("Argument %d is not a valid integer or float\n", i);
            return 0;
        }
    }


  /* Cartesian coordinates */
  
  float x1;
  float y1;
  float x2;
  float y2;
  float x3;
  float y3;
 
  /* Process inputs */
  // Changed from atoi to atof to allow for floating point numbers
  x1 = atof(argv[1]);
  y1 = atof(argv[2]);
  x2 = atof(argv[3]);
  y2 = atof(argv[4]);
  x3 = atof(argv[5]);
  y3 = atof(argv[6]);

  /* Compute lengths s1, s2, and s3 */
  float s12 = distance(x1,y1,x2,y2);
  float s23 = distance(x2,y2,x3,y3);
  float s13 = distance(x1,y1,x3,y3);

  // Check if the three points are the same
  if (samePoint(x1, y1, x2, y2, x3, y3)) return 0;

  /* Compute area per problem description */
  float area = triangleArea(s12, s23, s13);

  // Check if the three points form a line
  if (formLine(x1, y1, x2, y2, area)) return 0;

  /* Output area */
  outputMessage(x1,y1,x2,y2,x3,y3,area);

  return 0;
}
