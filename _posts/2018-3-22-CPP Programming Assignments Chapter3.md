---
layout: post
title: "CPP Programming Assignment Chapter3"
description: "my own source codes of Programming Assignment in C Primier Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/22/
---
#CPP Programming Assignment Chapter3

	3.2.c
	#include <stdio.h>
	int main(void)
	{
    	int value;
    	printf("Please input an integer: ");
    	scanf("%d", &value);
    	printf("%d is the ASCII code for %c\n", value, value);
    	return 0;
	}
	
---
	3.3.c
	#include <stdio.h>
	int main(void)
	{
    	printf("\a");
    	printf("Startled by the sudden sound, Sally shouted,\n\"By the Great Pumpkin, what was that!\"");
    	return 0;
	}
	
---
	3.4.c
	#include <stdio.h>
	int main(void)
	{
	    float value;
	    printf("Enter a floating-point value: ");
	    scanf("%f", &value);
	    printf("fixed-point notation: %.6f\n", value);
	    printf("exponential notation: %e\n", value);
	    printf("exponential notation: %.2a\n", value);
	    return 0;
	}
	
---
	3.5.c
	#include <stdio.h>
	int main(void)
	{
	    long value;
	    printf("Enter your age: ");
	    scanf("%ld", &value);
	    value = value * 31560000;
	    printf("the seconds of your age is: %ld\n", value);
	    return 0;
	}
	
---
	3.6.c
	#include <stdio.h>
	int main(void)
	{
	    float mass_mol= 3.0e-23;
	    float mass_qt=950;
	    float quarts;
	    float molecules;
	    printf("Enter the number of quarts of water: ");
	    scanf("%f", &quarts);
	    molecules = quarts * mass_qt / mass_mol;
	    printf("%f quarts of water contain %e molecules.\n", quarts, molecules);
	    return 0;
	}
	
---
	3.7.c
	#include <stdio.h>
	int main(void)
	{
    	float inch_cm= 2.54;
    	float inches;
    	float centimeters;
    	printf("Enter your height in inches: ");
    	scanf("%f", &inches);
    	centimeters = inches * inch_cm;
    	printf("%f inches is equals of %f centimeters.\n", inches, centimeters);
    	return 0;
	}

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.

