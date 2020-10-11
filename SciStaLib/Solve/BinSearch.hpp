/*--------------------------------------
	Project : SciStaLib
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-07 @ 02:12 PM
--------------------------------------*/

#ifndef __BINSEARCH__
	#define __BINSEARCH__
	#include "Common.hpp"
	
	namespace SciStaLib{
		namespace Solve{
			using namespace std;
			
			//The second value of pair store if res is valid.
			template<typename S=double, typename EXData=void>
			pair<S,bool> BinSearch(function<S(S,EXData*)> fun ,S low, S high,
				EXData* data=nullptr, S tol=1e-7, int maxiter=100){
				
				S fl=fun(low,data), fh=fun(high,data);
				pair<S,bool> res;
				if(abs(fl)<tol){
					res.first=low;
					res.second=true;
					return res;
				};
				if(abs(fh)<tol){
					res.second=high;
					res.second=true;
					return res;
				};
				if(copysign(1,fl)*copysign(1,fh)>0){
					cerr<<"Function value at lower and higher bounds have the same sign. Exit."<<endl;
					res.second=false;
					return res;
				};
				
				S mid=(low+high)/2;
				S fm=fun(mid,data);
				int iter=1;
				
				while(abs(fm)>tol){
					fl=fun(low,data), fh=fun(high,data);
					if((copysign(1,fl)*copysign(1,fm)>0) && 
						(copysign(1,fm)*copysign(1,fh)>0)){
						cerr<<"Possible multiple solution in giving area. Exit"<<endl;
						break;
					};
					if(copysign(1,fl)*copysign(1,fm)<0){
						high=mid;
					}else if(copysign(1,fm)*copysign(1,fh)<0){
						low=mid;
					};
					mid=(low+high)/2;
					fm=fun(mid,data);
					
					++iter;
					if(iter>maxiter){
						cout<<"Maximum iteration reached."<<endl;
					};
				};
				
				if(abs(fm)>tol){
					cerr<<"Final solution doesn't satisfy target."<<endl;
					res.second=false;
					return res;
				};
				
				res.first=mid;
				res.second=true;
				cout<<"Solution: "<<mid<<endl;
				cout<<"Function value: "<<fm<<endl;
				return res;
			};
			
		};
	};
	
#endif