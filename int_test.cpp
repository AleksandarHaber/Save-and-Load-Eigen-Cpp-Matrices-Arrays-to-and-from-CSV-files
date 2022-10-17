// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "save_load_eigen_csv.hpp"

int main()
{
	// test matrix to be saved
	Eigen::MatrixXi matrix_test(4, 4);

	// define the test matrix
	matrix_test << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;

	// save test matrix
	saveData<int>("matrix.csv", matrix_test);

	// matrix to be loaded from a file
	Eigen::MatrixXi matrix_test2;

	// load the matrix from the file
	matrix_test2 = openData<int>("matrix.csv");

	// print the matrix in console
	std::cout << matrix_test2 << std::endl;

	// test the load function on a matrix defined outside this environment.
	// make sure that the "matrix_outside.csv" file exhists
	/*MatrixXd matrix_test3;

	matrix_test3 = openData("matrix_outside.csv");

	cout <<"\n\n"<< matrix_test3<<"\n\n";

	cout << 10*matrix_test3 << "\n";*/
}
