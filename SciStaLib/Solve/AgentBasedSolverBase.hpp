/*--------------------------------------
	Project : SciStaEBD
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-02 @ 04:27 PM
--------------------------------------*/

#ifndef __SOLVEAGENTOPTIMIZATIONBASE__
#define __SOLVEAGENTOPTIMIZATIONBASE__
#include "SolverBase.hpp"
#include "../Eigen-Helper/Eigen-Helper.hpp"

namespace SciStaEBD {
	namespace Solve {

		class AgentBasedSolverBase : public SolverBase {
		protected:
			int population_size = 500;
			std::vector<VectorXd> population;
			int max_stall = 30;
			vector<double> init_lb, init_ub;
			double sinit_lb=-10, sinit_ub=10;
			bool population_initialized = false;
			
			void try_init_population() {
				if (!population_initialized) {
					init_population();
				};
			};
		public:
			AgentBasedSolverBase(string direction, int nvars) :SolverBase(direction, nvars){
				
			};

			void set_population_size(int pop) {
				population_size = pop;
			};

			std::vector<VectorXd>& get_population() {
				return population;
			};
			
			void set_init_bounds(double slb, double sub) {
				sinit_lb = slb;
				sinit_ub = sub;
			};
			void set_init_bounds(const vector<double>& lb, const vector<double>& ub) {
				init_lb = lb;
				init_ub = ub;
			};
			
			void init_population() {	

				if (population.size() == 0) {
					population.resize(population_size);
				};

				if (init_lb.size() == 0) {
					for (auto& ele : population) {
						ele.resize(num_vars);
						randu(ele, sinit_lb, sinit_ub);
					};

				}
				else {

					for (int i = 0; i < num_vars; ++i) {
						std::uniform_real_distribution<double> dist(init_lb[i], init_ub[i]);
							for (int j = 0; j < population_size; ++j) {
								population[j].coeffRef(i) = dist(SciStaLib_rd);
							};
					};
				};
			};

			void set_max_stall(int ms) {
				max_stall = ms;
			};


		};
	};
};

#endif
