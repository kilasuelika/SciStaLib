/** @author Zhou Yao


*/
#ifndef _EIGEN_HELPER_RAND_
#define _EIGEN_HELPER_RAND_
#include<random>

namespace eigen_helper {

	std::random_device SciStaLib_rd;

	template<typename Mat, typename D>
	void rand_dist(Mat& m, D& dist) {
		for (int i = 0; i < m.rows(); ++i) {
			for (int j = 0; j < m.cols(); ++j) {
				m.coeffRef(i, j) = dist(SciStaLib_rd);
			};
		};
	};
	template<typename Mat, typename S = double>
	void randn(Mat& m, S mu = 0, S var = 1) {
		typedef typename Mat::Scalar ElemType;

		std::normal_distribution<ElemType> dist{ mu,var };
		rand_dist(m, dist);	
	};

	template<typename Mat, typename S = double>
	void randu(Mat& m, S lb = 0, S ub = 1) {
		typedef typename Mat::Scalar ElemType;
		std::uniform_real_distribution<ElemType> dist{ lb,ub };

		rand_dist(m, dist);
	};
};
#endif