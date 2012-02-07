#pragma once

#if defined(NDEBUG)
#define BUG_DISABLE_BUGBEARD 
#endif

#ifndef NDEBUG
	#ifdef DEBUGMODE
		#define BUG_DISABLE_BUGBEARD		
	#endif
#endif

#define BUG_EVIL_CONTRACT
#include "bug.h"

#if defined(BUG_LOAD_BUGBEARD)
const bugbeard::bug_string bug_log_filename()
{
    using namespace bugbeard;
    const bug_clock stamp = bug_clock();
#if defined(__MWERKS__)
#error
#endif
    return
        bug_dir("buglog")
        +bug_dir("%4.4d", stamp.year)
        +bug_dir("%2.2d", stamp.mon)
        +bug_dir("%2.2d", stamp.mday)
        +"bulklog.log";
}
#endif

BUG_define_logger(new bugbeard::bug_tsv_logger(new bugbeard::bug_file_writer(bug_log_filename())));

#define BUG_STATEMENT_HACK
#include "bug.h"

void MyBugInit(){
	    //  [BUG]固定メッセージをログ出力
    BUG_puts("Hello, Bugbeard!");
    
    //  [BUG]コンパイル情報のログ出力
    BUG_exec(bugbeard::bug_compile_info(BUG_LOG));

	    //  [BUG]Windowsバージョン情報のログ出力
    BUG_exec(bugbeard::bug_windows_version_info(BUG_LOG));
    
    //  [BUG]Windowsシステム情報のログ出力
    BUG_exec(bugbeard::bug_windows_system_info(BUG_LOG));
    
#if 0x0500 <= WINVER
    //  各種モジュールバージョン情報のログ出力
    BUG_exec(bugbeard::bug_enum_module_version_info(BUG_LOG));
#endif
    
#if 0x0500 <= WINVER
    //  各種モジュールハッシュ値のログ出力
    BUG_exec(bugbeard::bug_enum_module_hash(BUG_LOG));
#endif
    
#if 0x0500 <= WINVER
    //  [BUG]メモリ情報のログ出力
    BUG_exec(bugbeard::bug_memory_info(BUG_LOG));
#endif

    //  [BUG]ドライブ情報のログ出力
    BUG_exec(bugbeard::bug_enum_drive_info(BUG_LOG));

#if 0x0500 <= WINVER
    //  [BUG]モニター情報のログ出力
    BUG_exec(bugbeard::bug_enum_monitor_info(BUG_LOG));
    //  [BUG]ディスプレイ情報のログ出力
    BUG_exec(bugbeard::bug_enum_display_info(BUG_LOG));
#endif

    //  [BUG](全ての)環境変数情報のログ出力
    BUG_exec(bugbeard::bug_enum_env(BUG_LOG));
}