/*
 * Lab 3 Functions.hpp
 *
 *  Created on: 2020. 3. 5.
 *      Author: Donggyu Park
 */

#ifndef SRC_LAB3_FUNCTIONS_HPP_
#define SRC_LAB3_FUNCTIONS_HPP_

int Minimum(int num1, int num2, int num3){
	int minimum;

	if (num1 < num2){
		minimum = num1;
		if (num1 < num3){
			minimum = num1;
		} else { // num3 <= num1
			minimum = num3;
		}
	} else { // num2 <= num1
		minimum = num2;
		if (num2 < num3){
			minimum = num2;
		} else { // num3 <= num2
			minimum = num3;
		}
	}

	return minimum;
}

int Maximum(int num1, int num2, int num3){
	int maximum;

	if (num1 > num2){
		maximum = num1;
		if (num1 > num3){
			maximum = num1;
		} else { // num3 >= num1
			maximum = num3;
		}
	} else { // num2 >= num1
		maximum = num2;
		if (num2 > num3){
			maximum = num2;
		} else { // num3 >= num2
			maximum = num3;
		}
	}

	return maximum;
}



#endif /* SRC_LAB3_FUNCTIONS_HPP_ */
