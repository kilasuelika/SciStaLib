/*--------------------------------------
	Project : SciStaEBD
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-08 @ 07:45 PM
--------------------------------------*/
#ifndef __SOLVECOMMON__
	#define __SOLVECOMMON__
	
	
	namespace SciStaEBD{
		namespace Solve{
			#include "../Util/EigenHelper.hpp"
			#include "../Util/FunctionCollection.hpp"
			#include<string>
			#include<utility>
			#include<cmath>
			#include<iostream>
			#include<tuple>
			#include<set>
			#include<vector>
			#include<algorithm>
			using namespace std;
			using namespace Eigen;
			//
			struct SolveOption{
				//Tollerance for x, gradient, hessian matrix. 
				//We compute norms of gradient and hessian change.
				double xtol=1e-6, gtol=1e-6, htol=1e-6;
				int maxiter=1000;
				//disp level. 0:none.
				//1: only final result.
				//2: x and function value of each iteration + x and function value change 
				//+ gradient change norm +level 1.
				int disp=2;
				
				//"least square", "norm";
				string mode;
				
			};
			
			SolveOption DefaultSolveOption;
			
			//
			struct SolveResult{
				double dx_n, dy_n, dgrad_n, dhes_n;
				VectorXd x, dx, y, dy, grad, dgrad;				
				MatrixXd hes, dhes;
			};
			
			template<typename ProbType, typename ParmType=VectorXd>
			ParmType ApproxGrad(ProbType, ParmType x){
				
			};
			
			template<typename ProbType, typename MatType=MatrixXd>
			MatType ApproxGrad(ProbType, ParmType x){
				
			};
			
		};
	};
#endif