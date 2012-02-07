#include "minigame_block_load_stage.h"
#include"minigame_block_debug.h"
//#include"mybug.h"
namespace Minigame{
	namespace Block{


void LoadAllStage(StagesVec &buf, string folderpath){
	int stageNumber= 0;
	//MyBugInit();
	//ステージの数だけ拡張する
	buf.resize(STAGE_N);

	for(int i = 0; i < STAGE_N; i++){
		buf[i].resize(STAGE_MAX_X);
		for(int j = 0; j < STAGE_MAX_X; j++){
			StageVec& v = buf[i];
			v[j].resize(STAGE_MAX_Y);
		}
	}
	string fp = folderpath;
	stringstream ss;
	ss << folderpath << MAP_STR <<	stageNumber <<	MP_STR;
	while(PathFileExists(ss.str().c_str()) != FALSE){
		ifstream ifs;
		ifs.open(ss.str().c_str(), ios::in);
		int j = 0;
		while(!ifs.eof()){
			char line[STAGE_MAX_X];
			ifs.getline(line, sizeof(line));

			int s = static_cast<int>(strlen(line));
			for(int i = 0; i < s; i++){
					char c = line[i];
					if('0' < c && c < '9') {
						buf[stageNumber][i][j] = line[i] - '0';
					}
					else{
						pd("マップデータに無効な値が入っています");
					}
			}
			j++;
		}
		
		ss.str("");
		ifs.close();
		stageNumber++;
		ss << folderpath << MAP_STR << stageNumber << MP_STR;
	}
}
	}}