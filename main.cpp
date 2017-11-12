// int_fract.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;


double binaryToDecimal(string binary, int len)
{
	// Fetch the radix point
	size_t point = binary.find('.');

	// Update point if not found
	if (point == string::npos)
		point = len;

	double intDecimal = 0, fracDecimal = 0, twos = 1;

	// Convert integral part of binary to decimal
	// equivalent
	for (int i = point - 1; i >= 0; --i)
	{
		// Subtract '0' to convert character
		// into integer
		intDecimal += (binary[i] - '0') * twos;
		twos *= 2;
	}

	// Convert fractional part of binary to
	// decimal equivalent
	twos = 2;
	for (int i = point + 1; i < len; ++i)
	{
		fracDecimal += (binary[i] - '0') / twos;
		twos *= 2.0;
	}

	// Add both integral and fractional part
	return intDecimal + fracDecimal;
}

// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}


// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char *res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;

	// Extract floating part
	float fpart = n - (float)ipart;

	// convert integer part to string
	int i = intToStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0)
	{
		res[i] = '.';  // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);

		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

int main()
{
	int  integral, binaryInt = 0, i = 1;
	float  binaryFract = 0, k = 0.1f, fractional, temp1, f;
	double binaryTotal;
	int  num, binary_val, decimal_val = 0, base = 1, rem;

	printf("***** Convert float to binary *******\n");
	printf("\nEnter float value : ");
	scanf_s("%f", &f);

	//Separating the integral value from the floating point variable
	integral = (int)f;

	//Separating the fractional value from the variable
	fractional = f - (int)f;
	integral = integral & 0xFF;  ///for masking
	//Loop for converting decimal to binary
	while (integral>0)
	{
		binaryInt = binaryInt + integral % 2 * i;
		i = i * 10;
		integral = integral / 2;
	}

	//Loop for converting Fractional value to binary
	while (k>0.000000001)
	{
		temp1 = fractional * 2;
		binaryFract = binaryFract + ((int)temp1)*k;
		///float ii = ()
		fractional = temp1 - (int)temp1;
		k = k / 10;
	}

	//Combining both the integral and fractional binary value.
	binaryTotal = binaryInt ;
	printf(" \nbinary int equivalent = %0.8lf\n", binaryTotal);
	printf("binary fraction equivalent =%0.8lf\n\n", binaryFract);

	binary_val = binaryInt;
	 num= binary_val;
	while (num > 0)
	{
		rem = num % 10;
		decimal_val = decimal_val + rem * base;
		num = num / 10;
		base = base * 2;
	}
	char res[20]; 
	ftoa(binaryFract, res, 8);
	float fraction_part_value = binaryToDecimal(res, 8);



	printf("Its decimal equivalent is = %d \n", decimal_val);
	printf("Its fractional equivalent is = %f\n", fraction_part_value);

	double answer = decimal_val + fraction_part_value;


	printf("\nANSWER = %f\n", answer);

	_getch();
}
