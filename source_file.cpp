// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Eigen/Dense>
#include<fstream>
#include<vector>

using namespace std;
using namespace Eigen;


void saveData(string fileName, MatrixXd  matrix)
{
	//https://eigen.tuxfamily.org/dox/structEigen_1_1IOFormat.html
	const static IOFormat CSVFormat(FullPrecision, DontAlignCols, ", ", "\n");

	ofstream file(fileName);
	if (file.is_open())
	{
		file << matrix.format(CSVFormat);
		file.close();
	}
}



MatrixXd openData(string fileToOpen)
{

	// the inspiration for creating this function was drawn from here (I did NOT copy and paste the code)
	// https://stackoverflow.com/questions/34247057/how-to-read-csv-file-and-assign-to-eigen-matrix
	
	// the input is the file: "fileToOpen.csv":
	// a,b,c
	// d,e,f
	// This function converts input file data into the Eigen matrix format



	// the matrix entries are stored in this variable row-wise. For example if we have the matrix:
	// M=[a b c 
	//	  d e f]
	// the entries are stored as matrixEntries=[a,b,c,d,e,f], that is the variable "matrixEntries" is a row vector
	// later on, this vector is mapped into the Eigen matrix format
	vector<double> matrixEntries;

	// in this object we store the data from the matrix
	ifstream matrixDataFile(fileToOpen);

	// this variable is used to store the row of the matrix that contains commas 
	string matrixRowString;

	// this variable is used to store the matrix entry;
	string matrixEntry;

	// this variable is used to track the number of rows
	int matrixRowNumber = 0;


	while (getline(matrixDataFile, matrixRowString)) // here we read a row by row of matrixDataFile and store every line into the string variable matrixRowString
	{
		stringstream matrixRowStringStream(matrixRowString); //convert matrixRowString that is a string to a stream variable.

		while (getline(matrixRowStringStream, matrixEntry, ',')) // here we read pieces of the stream matrixRowStringStream until every comma, and store the resulting character into the matrixEntry
		{
			matrixEntries.push_back(stod(matrixEntry));   //here we convert the string to double and fill in the row vector storing all the matrix entries
		}
		matrixRowNumber++; //update the column numbers
	}

	// here we convet the vector variable into the matrix and return the resulting object, 
	// note that matrixEntries.data() is the pointer to the first memory location at which the entries of the vector matrixEntries are stored;
	return Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(matrixEntries.data(), matrixRowNumber, matrixEntries.size() / matrixRowNumber);

}




int main()
{
	// test matrix to be saved
	MatrixXd matrix_test(4, 4);
	
	// define the test matrix
	matrix_test << 1.2, 1.4, 1.6, 1.8,
		1.5, 1.7, 1.9, 1.10,
		0.8, 1.2, -0.1, -0.2,
		1.3, 99, 100, 112;

	// save test matrix
	saveData("matrix.csv", matrix_test);

	// matrix to be loaded from a file
	MatrixXd matrix_test2;

	// load the matrix from the file
	matrix_test2 = openData("matrix.csv");
	
	// print the matrix in console
	cout << matrix_test2;
	
	// test the load function on a matrix defined outside this environment.
	// make sure that the "matrix_outside.csv" file exhists
	/*MatrixXd matrix_test3;
	
	matrix_test3 = openData("matrix_outside.csv");

	cout <<"\n\n"<< matrix_test3<<"\n\n";

	cout << 10*matrix_test3 << "\n";*/
}
