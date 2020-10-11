/*--------------------------------------
	Project : SciStaEBD
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-02 @ 04:27 PM
--------------------------------------*/

#ifndef __SOLVERBASE__
	#define __SOLVERBASE__
	
	#include<cmath>
	#include<Eigen/Core>
	#include<functional>
	#include<string>
	#include<iostream>
	#include <stdexcept>
	#include <chrono>
	#include "Util/StringCollection.hpp"
	
	namespace SciStaEBD{
		namespace Solve{
			using namespace Eigen3;
			
			enum SOLVE_EXIT_FLAG{};
			
			//EXData is for external data.
			class SolverBase{
				protected:
				int opt_direction;
				int max_iter=200;
				int print_level=0;
				int num_vars;
				std::chrono::seconds runing_time;
				
				public:
				
				
				//type can be "max" or "min".
				OptProblem(string direction="min", int nvars){
					if(direction=="min"){
						opt_direction=-1;
					}else if(direction=="max"){
						opt_direction=1;
					}else{
						throw std::invalid_argument("Invalid optimization direction.");
					};
				};
				
				void set_print_level(int l){
					
				};
				auto get_running_time(){
					return runing_time;
				};
				virtual SolveResult solve(){
					if(valid){
						this->opt_begin_msg();
						//Iteration.
						int iter=0;
						
						this->opt_finish_msg();
					};
				};

				virtual void opt_begin_msg(){
					cout<<break_line<<endl
					<<"Number of arguments:"<<endl
					<<"Number of objective function: "<<endl
					<<this->solver_info;
				};
				
				virtual void opt_finish_msg(){
					
					cout<<break_line<<endl;
				};
			};
			
		};
		
	};
#endif