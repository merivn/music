/// @file StrKit.h
/// @brief 声明#StrKit类
/// @author 闵卫
/// @date 2015年11月20日
/// @version 1.0.0.1

#ifndef _STRKIT_H
#define _STRKIT_H
#include <QString>
#include <string.h>
/// @brief 字符串工具包
class StrKit {
public:

    static string strcat (
		char const* str1, ///< [in] 字符串1
		char const* str2, ///< [in] 字符串2
		...               ///< [in] 字符串n
	);

	static string& trim (
		string& str ///< [in,out] 待修剪字符串
	);
	static vector<string> split (
		string const& str,      ///< [in] 待拆分字符串
		string const& delim,    ///< [in] 分隔符字符串
		int           limit = 0 ///< [in] 拆分次数限制
	);
};

#endif // _STRKIT_H
