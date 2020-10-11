/*--------------------------------------
	Project : SciStaLib
	Author  : Zhou Yao
	E-Mail  : semeegozy@gmail.com
	Time    : 2020-02-07 @ 02:12 PM
--------------------------------------*/

#ifndef __FUNCTIONCOLLECTION__
	#define __FUNCTIONCOLLECTION__
	
	#include<vector>
	#include<set>
	namespace SciStaLib{
		
		using namespace std;
		//Find indices of all occurences of a value in a vector like container.
		template<typename V, typename S>
		vector<int> which(const V& v, const S& val) {
			vector<int> res;
			for (int i = 0; i < v.size(); ++i) {
				if (v[i] == val) {
					res.push_back(i);
				};
			};
			return res;
		};
		
		//Convert a set to vector.
		template<typename T>
		vector<T> set2vec(const set<T>& s) {
			vector<T> res;
			for (auto& ele : s) {
				res.push_back(ele);
			};
			return res;
		};
		
		//Print value in a STL container.
		template<typename T>
		void print_stl(const T& v){
			for(auto& ele: v){
				cout<< ele<<endl;
			};
		};
	};
#endif