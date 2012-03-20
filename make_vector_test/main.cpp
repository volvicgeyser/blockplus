#include<iostream>
#include<vector>
#include<boost/range/algorithm.hpp>
#include<algorithm>

template <typename T>
void make_vector(std::vector<T>& v, int s){
	for(int i = 0; i < s; i++){
		v.push_back(i);
	}
}

template <typename T>
void make_vector(std::vector<T>& v, int begin, int end){
	const int s = end - begin + 1;
	for(int i = 0; i < s; i++){
		v.push_back(i+begin);
	}
}
int main(){
	std::vector<int> a;
	make_vector<int> (a, 20, 30);
	boost::copy(a, std::ostream_iterator<int>(std::cout, " "));
}