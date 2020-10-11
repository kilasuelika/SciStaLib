/*--------------------------------------
	Project : SciStaEBD
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-02 @ 05:29 PM
--------------------------------------*/
#ifndef __EIGENHELPER__
	#define __EIGENHELPER__
	#include<Eigen/Core>
	#include "../Util/FunctionCollection.hpp"
	
namespace SciStaEBD{
	using namespace Eigen;
	
	typedef Array<bool,Dynamic,1> ArrayXb;
	
	//Indexing a matrix by set of integers. dim=0 for rows, dim=1 for columns.
	template<typename SV, typename IDXT>
	SV slice_by_set(SV mat, IDXT is, int dim=0){
		int m=mat.rows(), n=mat.cols(), sz=is.size();
		SV res;
		if(dim==0){
			res=SV(sz,n);
		}else{
			res=SV(m,sz);
		};
		
		int i=0;
		for(auto &ele: is){
			if(dim==0){
				res.row(i)=mat.row(ele);
			}else{
				res.col(i)=mat.col(ele);
			};
			++i;
		};
		
		return res;
		
	};
	
};

#endif