#include"minigame_block_func.h"
#include"minigame_block_debug.h"
#include"minigame_block_enum.h"
namespace Minigame{
	namespace Block{

void LoadGraphic(string name, string filename, PictureMap &graphicData)
{
	const char* str = filename.c_str();
	int graphicHandle = LoadGraph(str);
	
	//画像ファイルの有無をチェック
	if(PathFileExists(str) == FALSE){
		pd(str);
	}
	if(graphicHandle == -1){
		stringstream ss;
		ss << CANT_OPEN_GRAPHIC_FILE_STR << TEXT(". ") << str;
		pd(ss.str().c_str());
	}
	graphicData[name] = graphicHandle;
}


void LoadNumberingGraphics(PictureMap &graphicData, string name, string folderpath,string filename_without_ext, string fileExt, int numberingIndex){
	int i = numberingIndex;
	stringstream numbering_name;
	stringstream fullpath_filename;
	numbering_name << name << i;
	fullpath_filename << folderpath << TEXT(numbering_name.str())<< fileExt;
	while(PathFileExists(fullpath_filename.str().c_str()) != FALSE){
		LoadGraphic(numbering_name.str(), fullpath_filename.str(), graphicData);
		i++;

		numbering_name.str("");
		fullpath_filename.str("");

		numbering_name << name << i;
		fullpath_filename << folderpath << TEXT(numbering_name.str()) << fileExt;
	}
}
void LoadNumberingGraphics(PictureMap &graphicData, string name, string folderpath,string filename_without_ext, string fileExt){
	LoadNumberingGraphics(graphicData, name, folderpath, filename_without_ext, fileExt, 0);
}

void LoadBlockGraphics(PictureMap &graphicsData){
	LoadNumberingGraphics(graphicsData, BLOCK_STR, MEDIA_PATH_STR, BLOCK_STR, PNG_STR, 0);
}
void LoadBallGraphics(PictureMap &graphicData){
	LoadNumberingGraphics(graphicData, BALL_STR, MEDIA_PATH_STR, BALL_STR, PNG_STR);
}

void Init(Gamedata &gameData)
{
	PictureMap& g = gameData.graphicData;
	StagesVec& stages = gameData.stageInfo.default_stagesVec;
	LoadBallGraphics(g);
	stringstream titlepath;

	string title_name = TITLE_STR;
	titlepath<< MEDIA_PATH_STR << title_name << PNG_STR;
	
	//タイトル画像の読み込み
	LoadGraphic(title_name, titlepath.str().c_str(), g);

	//press enter key画像の読み込み
	string press_enter_key_name = PRESS_ENTER_KEY_STR;
	stringstream press_enter_key_path;
	press_enter_key_path << MEDIA_PATH_STR <<  PRESS_ENTER_KEY_STR <<  PNG_STR;
	LoadGraphic(press_enter_key_name, press_enter_key_path.str(), g);

	
	//rankingmode
	string ranking_name = RANKINGMODE_STR;
	stringstream ranking_path;
	ranking_path << MEDIA_PATH_STR << ranking_name << PNG_STR;
	LoadGraphic(ranking_name, ranking_path.str(), g);
	
	//retrymode
	string retrymode_name = RETRYMODE_STR;
	stringstream retrymode_path;
	retrymode_path << MEDIA_PATH_STR << retrymode_name << PNG_STR;
	LoadGraphic(retrymode_name, retrymode_path.str(), g);

	//drop画像の読み込み
	string drop_name = DROP_STR;
	stringstream drop_path;
	drop_path << MEDIA_PATH_STR << drop_name << PNG_STR;
	LoadGraphic(drop_name, drop_path.str(), g);

	//ready画像の読み込み
	string ready_name = "ready";
	stringstream ready_path;
	ready_path << MEDIA_PATH_STR << ready_name << PNG_STR;
	LoadGraphic(ready_name, ready_path.str(), g);

	//score画像の読み込み
	string score_name = "score";
	stringstream score_path;
	score_path << MEDIA_PATH_STR << score_name << PNG_STR;
	LoadGraphic(score_name, score_path.str(), g);

	//bombbit画像の読み込み
	string fire_name = "bombbit";
	stringstream fire_path;
	fire_path << MEDIA_PATH_STR << fire_name << PNG_STR;
	LoadGraphic(fire_name, fire_path.str(), g);

	//blockbit画像の読み込み
	string block_bit_name = "blockbit";
	stringstream block_bit_path;
	block_bit_path << MEDIA_PATH_STR << block_bit_name << PNG_STR;
	LoadGraphic(block_bit_name, block_bit_path.str(), g);

	//plus画像の読み込み
	string plus_name = PLUS_STR;
	stringstream plus_path;
	plus_path << MEDIA_PATH_STR << plus_name << PNG_STR;
	LoadGraphic(plus_name, plus_path.str(), g);

	//タイトル画像の読み込み
	string version_name = VERSION_STR;
	stringstream version_path;
	version_path << MEDIA_PATH_STR << VERSION_STR << PNG_STR;
	LoadGraphic(version_name, version_path.str(), g);

	//stage clear
	string stage_clear_name = STAGE_CLEAR_STR;
	stringstream stage_clear_path;
	stage_clear_path << MEDIA_PATH_STR << STAGE_CLEAR_STR << PNG_STR;
	LoadGraphic(stage_clear_name, stage_clear_path.str(), g);

	//explosion
	string explosion_name = EXPLOSION_STR;
	stringstream explosion_path;
	explosion_path << MEDIA_PATH_STR << EXPLOSION_STR << PNG_STR;
	LoadGraphic(explosion_name, explosion_path.str(), g);

	//ステージに使うブロック画像の読み込み
	LoadBlockGraphics(g);

	//ボール画像の読み込み
	LoadBallGraphics(g);

	//ステージデータの読み込み
	LoadAllStage(stages, DAT_PATH_STR);
	InitGameData(gameData);

	//点滅オブジェクトを初期化
	IntervalVisibleObj title_logo;
	title_logo.SetInterval(PRESS_ENTER_KEY_INTERVAL );
	gameData.intervalVisibleObjs["title_logo"] = title_logo;

	IntervalVisibleObj ready_logo;
	ready_logo.SetInterval(READY_INTERVAL);
	gameData.intervalVisibleObjs["ready_logo"] = ready_logo;

	IntervalVisibleObj stage_clear_logo;
	stage_clear_logo.SetInterval(STAGE_CLEAR_INTERVAL);
	gameData.intervalVisibleObjs["stage_clear_logo"] = stage_clear_logo;

	IntervalVisibleObj drop_logo;
	drop_logo.SetInterval(DROP_INTERVAL);
	gameData.intervalVisibleObjs["drop_logo"] = drop_logo;

	gameData.sm = TITLE;

	//タイトル画面用にブロックのCharaObj情報を初期化
	InitBlocks(gameData);

	//ランダムボール生成
	InitCharaInfo(gameData);
}

void InitBar(Gamedata& gameData){
	CharaObjs& bars = gameData.charaInfo.bars;
	bars.clear();
	CharaObj c;
	c.p.y(static_cast<float>(BAR_Y));
	c.size.x(BAR_SIZE_X);
	c.size.y(BAR_SIZE_Y);
	c.v.x(0);
	c.v.y(0);
	bars.push_back(c);
}
//ステージ開始前に実行する 読み込んだステージデータのブロック情報をCharaObjsに反映する
void InitBlocks(Gamedata &gamedata){
	StageVec& s = gamedata.stageInfo.default_stagesVec[gamedata.stageInfo.currentStage];
	CharaObjs& blocks = gamedata.charaInfo.blocks;
	blocks.clear();
	gamedata.stageInfo.breakableBlockN = 0;
	for(int i = 0; i < static_cast<int>(s.size()); i++){
		vector<char> vc = s[i];
		for(int j = 0; j < static_cast<int>(vc.size()); j++){
			if(vc[j] != NOTHING){
				CharaObj c;
				c.p.x(static_cast<float>(i * BLOCK_SIZE));
				c.p.y(static_cast<float>(j * BLOCK_SIZE));

				//ブロックのサイズはWidthとHeightがすべて一緒なので設定しない。
				//ブロックは移動しないのでspeedとangleも設定しない。

				c.type = vc[j];

				//壊せるブロックだったら壊せるブロックに1加える
				if(c.type != UNBREAKABLE){
					gamedata.stageInfo.breakableBlockN++;
				}
				blocks.push_back(c);
			}
		}
	}
}


void InitCharaInfo(Gamedata &gamedata){
	CharaObjs& balls = gamedata.charaInfo.balls;
	gamedata.charaInfo.bomb_bits.resize(1000);
	gamedata.charaInfo.block_bits.resize(1000);
	for(int i = 0; i < TITLE_BALLS_N; i++){
		CharaObj c;
		Polar pl;
		c.p.x(static_cast<float>(GetRand(SCREEN_SIZE_WIDTH)));
		c.p.y(static_cast<float>(GetRand(SCREEN_SIZE_HEIGHT)));
		c.size.x(BLOCK_SIZE);
		c.size.y(BLOCK_SIZE);
		pl.angle = static_cast<float>(GetRand(MAX_DEG));
		pl.speed = static_cast<float>(BALL_MIN_SPEED + GetRand(BALL_MAX_SPEED - BALL_MIN_SPEED));
		//c.pl.angle = static_cast<float>(GetRand(MAX_DEG));
		//c.pl.speed = static_cast<float>(BALL_MIN_SPEED + GetRand(BALL_MAX_SPEED - BALL_MIN_SPEED));
		if(pl.speed == 0){
			pd("zero speed!");
		}
		ConvertPolarToCartesian(c.v, pl);
		balls.push_back(c);
	}
}

void InitGameData(Gamedata &gameData){
	gameData.score = 0;
	//gameData.pek_logo_visible = true;
	//gameData.pek_logo_count = 0;
	gameData.stageInfo.currentStage = 0;
	gameData.sm = INIT;
	
	//ミニゲームが起動してからの総フレーム数
	gameData.totalFrameCount = 0;
}

}
}
