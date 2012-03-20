#ifndef DEF_MINIGAME_BLOCK_STRUCT_H
#define DEF_MINIGAME_BLOCK_STRUCT_H
#include<vector>
#include<boost/unordered_map.hpp>
#include"minigame_block_fpscounter.h"
#include"minigame_block_point.h"
#include"minigame_block_interval_visible_obj.h"

//�\����
//boost�̃n�b�V���֐��ɂ��map
typedef boost::unordered_map<std::string, int> PictureMap;
typedef boost::unordered_map<std::string, Minigame::Block::IntervalVisibleObj> IntervalVisibleObjMap;

namespace Minigame{
	namespace Block{

enum SCREENMODE;
enum GAMEMODE;

//�����s�����b�Z�[�W���̃I�u�W�F�N�g
struct LtdDrawableObj{
	//�����t���[���J�E���g
	int count;
	
	//�����t���[��	
	int limit;

	int type;

	//�\���ʒu
	Point p;
};

typedef std::vector<LtdDrawableObj> LtdDrawableObjs;

typedef struct{
	float angle;
	float speed;
}Polar;

typedef struct {
	PointF p;
	Point size;	
	//Polar pl;
	PointF v;
	
	//�L�����N�^�[�̃^�C�v�i�L�����N�^�[���ƂɎg�������Ⴄ�j
	int type;

	//�L�����N�^�[���������ꂽ�t���[��
	long appearanceFrame;
}CharaObj;

//�X�}�[�g�|�C���^��typedef
typedef std::vector<CharaObj> CharaObjs;
typedef boost::shared_ptr<CharaObj> CharaObj_Ptr;
typedef std::vector<CharaObj_Ptr> CharaObj_Ptrs;
typedef std::vector<CharaObj_Ptrs> AllCharaObj_Ptrs;

//Game�̎��ԂɊւ������ێ�����N���X
class GameTime{
public:
	//FPS���擾����
	double getFPS();

	//�Q�[�����N�����Ă���̃g�[�^�����Ԃ��擾����
	int getTotalMinutes();
private:
};

//�Q�[���̃X�e�[�W����ێ�����\����
struct StageInfo{
	//���݂̃X�e�[�W
	int currentStage;

	//���݂̃X�e�[�W�Ŕj��\�ȃu���b�N�̐�
	int breakableBlockN;

	//�ߋ��ɁA�ŏ��̃X�e�[�W����J�n���A�ǂ��܂ł̃X�e�[�W�܂ł�������
	int completedStage;

	//���[�h���ꂽ�X�e�[�W���
	StagesVec default_stagesVec;
};

//�o�[�A�u���b�N�A�A�C�e���A�{�[���Ȃǂ��L�����N�^�[�I�u�W�F�N�g��ێ�����\����
struct CharaInfo{
	CharaObjs balls;
	CharaObjs blocks;
	CharaObjs bars;
	CharaObjs items;

	//�K���X��
	CharaObjs glass_bits;

	//�u���b�N��
	CharaObjs block_bits;

	//���e�u���b�N�����яo���j��
	CharaObjs bomb_bits;
	CharaObjs freeze_bits;
};

typedef struct{
	//�S�Ẳ摜�f�[�^��ێ�����A�z�z��
	PictureMap graphicData;

	//�������茻�ꂽ�肷�郁�b�Z�[�W���̃I�u�W�F�N�g
	IntervalVisibleObjMap intervalVisibleObjs;
	
	//FPS�Ɋւ�����
	FPSCounter fpsCounter;

	//�X�e�[�W�̏��
	StageInfo stageInfo;
	
	//�S�ẴL�����N�^�[���
	CharaInfo charaInfo;

	//�u���b�N�����̃Q�[���̗���
	SCREENMODE sm;

	//�^�C�g����ʂőI�ׂ�Q�[�����[�h
	GAMEMODE gm;

	//�����t�����b�Z�[�W�\���I�u�W�F�N�g
	LtdDrawableObjs ltdDrawableObjs;

	//�X�e�[�W�̃X�R�A
	int score;

	//�g�[�^���X�R�A
	long totalFrameCount;

	//�`�������W���[�h�͉��x�����A�ł���̕s�v�H�@�d�l���ł܂莟��
	//int challenge_chance;
}Gamedata;
	}
}
#endif
