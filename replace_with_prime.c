/* Documentation 
Name          : Anusree Mohan
Date          : 25-11-24
Title         : To replace the elements of a 2D array with 5th prime number starting from the corresponding array element
input	      : 1 2 3
		4 5 7
output	      : 11 11 13
	        17 17 19

		eg: arr[0][1] = 2
		starting from 2, 5th prime number 11 ( 2,3,5,7,11,13,17,19...)
 */

#include <stdio.h>

// check if the number is prime or not
int is_prime(int num) {
	int flag = 0;
	for(int i = 2; i*i <= num; i++) {
		if( num % i == 0 ) {
			flag = 1;
			break;
		}
	}
	if( flag == 1 )
		return 0;
	else
		return 1;
}

// function to replace with prime
void replace_array_element(int row, int col, int (*arr)[col])
{
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			int count = 0;
			int num = arr[i][j];
			if( num <= 1 )
				num = 2;
			while(1) {
				// check if it is prime
				if( is_prime(num) == 1 ) {
					count++;	// increment count
				}

				if(count == 5) {
					arr[i][j] = num;
					break;
				}
				num++;
			}
		}
	}
}

int main()
{
	int arr[2][3] = {{1,2,3},{4,5,7}};

	// function call
	replace_array_element(2,3,arr);

	// to print result 2D array
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


