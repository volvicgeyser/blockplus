// iterator_test.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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

