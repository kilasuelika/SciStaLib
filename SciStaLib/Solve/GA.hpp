/*--------------------------------------
	Project : SciStaEBD
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-02 @ 04:27 PM
--------------------------------------*/

#ifndef __SOLVEAGENTOPTIMIZATIONBASE__
#define __SOLVEAGENTOPTIMIZATIONBASE__
#include "AgentOptimizationBase.hpp"

namespace SciStaEBD {
	namespace Solve {

		class GA : public AgentOptimizationBase {

			GA(string direction, int nvars): AgentBasedSolverBase(direction, nvars)  {
				
			};

			template<typename FT = function<double(VextorXd)>>
			pair<VectorXd, GA_FLAG> solve(FT fun) {
				try_init_population();
				return solve(fun, population);
			};

			template<typename FT = function<double(VextorXd)>, typename T = VectorXd>
			pair<VectorXd, GA_FLAG>  solve(FT fun, T& x0) {
				try_init_population();
				population[0] = x0;
				auto res = solve(fun, population);
				x0 = res.first;
				return res;
			};

			template<typename FT = function<double(VextorXd)>, typename T =vector< VectorXd>>
			pair<VectorXd, GA_FLAG>  solve(FT fun, T& x0) {
				
			};
		};
	};
};