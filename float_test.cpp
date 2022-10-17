// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "save_load_eigen_csv.hpp"
#include "path.hpp"

int main()
{
	// test matrix to be saved
	Eigen::MatrixXf matrix_test(4, 4);

	// define the test matrix
	matrix_test << 1.2, 1.4, 1.6, 1.8,
		1.5, 1.7, 1.9, 1.10,
		0.8, 1.2, -0.1, -0.2,
		1.3, 99, 100, 112;

	// save test matrix
	std::string matrixFile = build_path + std::string("matrix.csv");
	saveData<float>(matrixFile, matrix_test);

	// matrix to be loaded from a file
	Eigen::MatrixXf matrix_test2;

	// load the matrix from the file
	matrix_test2 = openData<float>(matrixFile);

	// print the matrix in console
	std::cout << matrix_test2 << std::endl;

	// test the load function on a matrix defined outside this environment.
	// make sure that the "matrix_outside.csv" file exhists
	/*MatrixXd matrix_test3;

	matrix_test3 = openData("matrix_outside.csv");

	cout <<"\n\n"<< matrix_test3<<"\n\n";

	cout << 10*matrix_test3 << "\n";*/
}
