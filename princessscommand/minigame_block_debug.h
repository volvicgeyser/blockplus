#ifndef DEF_MINIGAME_BLOCK_DEBUG_H
#define DEF_MINIGAME_BLOCK_DEBUG_H

#ifdef DEBUGMODE
		#pragma message "DEBUGMODEがONです。DEBUG用の関数を定義します。"
			#define pd(str) \
			char __message[0xff];	\
			sprintf(__message, "print debug: %s  at %d line %s", str, __LINE__, __FILE__);	\
			MessageBox(NULL, __message, TEXT("DEBUG_MESSAGE"), MB_OK);	
#else
		#define pd(str)
#endif

#ifdef DEBUGMODE	
	void pd_scr(const char* str){
	}
#else
		#define pd_scr(str)
#endif



#endif