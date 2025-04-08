#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


int main()
{
	std::ifstream infile("data.txt");
	std::ofstream outfile("result.txt");
	if (infile.fail() || outfile.fail())
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	double S;
	int n;
	double F;;
	char tmp;
	
	infile >> tmp >> tmp >> S;
	infile >> tmp >> tmp >> n;	
	
	std::string tmp2;
	infile >> tmp2;
	
	std::vector<double> w(n), r(n);
	
	for (int i = 0; i < n; i++) 
	{
		double a,b;
        infile >> w[i] >> tmp >> r[i]; 
		
	}
	infile.close();
	
	double Return = 0.0;
	for(unsigned int i = 0; i<n ;i++)
	{
		Return += w[i]*r[i];
	}
	
	double V = (1+Return)*S;
	
	//output screen
	
	std::cout << "S = "<< std::fixed << std::setprecision(2) << S << ", n = "<< n << std::endl;
	std::cout <<"w = [ ";
	for(unsigned int i = 0; i<n; i++) {
		std::cout << std::fixed << std::setprecision(2) << w[i]<< " ";
	}
	std::cout << "]" << std::endl;
	
	std::cout <<"r = [ ";
	for(unsigned int i = 0; i<n; i++) {
		std::cout << std::fixed << std::setprecision(2) << r[i]<< " ";
	}
	std::cout << "]" << std::endl;
	
	std::cout << "Rate of return of the portfolio: "<< std::fixed << std::setprecision(4)<< Return << std::endl;
	
	std::cout <<"V: " << std::fixed << std::setprecision(2) << V << std::endl;
	
	//output result.txt
	
	outfile <<"S = "<< std::fixed << std::setprecision(2) << S << ", n = "<< n << std::endl;
	outfile <<"w = [ ";
	for(unsigned int i = 0; i<n; i++) {
		outfile << std::fixed << std::setprecision(2) << w[i]<< " ";
	}
	outfile << "]" << std::endl;
	
	outfile <<"r = [ ";
	for(unsigned int i = 0; i<n; i++) {
		outfile << std::fixed << std::setprecision(2) << r[i]<< " ";
	}
	outfile << "]" << std::endl;
	
	outfile << "Rate of return of the portfolio: "<< std::fixed << std::setprecision(4)<< Return << std::endl;
	
	outfile <<"V: " << std::fixed << std::setprecision(2) << V << std::endl;
	
	
	return 0;
}
