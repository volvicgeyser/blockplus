// iterator_test.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	vector<int> a;
	for(int i = 0; i < 100000; i++){
		a.push_back(i);
	}
	vector<int>::iterator b = a.begin();
	//boost::copy(a, std::ostream_iterator<int>(std::cout, " "));
	return 0;
}

