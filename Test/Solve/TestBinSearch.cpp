/*--------------------------------------
	Project : SciStaLib
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-07 @ 02:12 PM
--------------------------------------*/

#include "../../SciStaLib/Solve/BinSearch.hpp"

double fun(double x, void* data){
	return std::pow(x,2)-9.25;
};
	
int main(){
	SciStaLib::Solve::BinSearch<double, void>(fun,0,10);
};