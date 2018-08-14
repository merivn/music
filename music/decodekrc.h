#ifndef DECODEKRC_H
#define DECODEKRC_H

#include <QByteArray>
#include "zlib/zlib.h"

#pragma comment (lib,"zlib/zlib.h")

const static int Keys[16] =  {64, 71, 97, 119, 94, 50, 116, 71, 81, 54, 49, 45, 206, 210,110, 105};
//zlib解压相关函数
extern int  ZlibGetDecodeLength(uLong  InRawLength);
extern int  ZlibGetDecodeLength(QByteArray  InRawData);

extern long  ZlibUncompress(QByteArray  &OutDecodeData, QByteArray InEncodeData,
                     int   * nErrorCode = NULL);

extern int  KrcDecode(QByteArray  &KrcData, QByteArray  &LrcData); //LRC解码

extern void test2(); //测试解压库的函数


#endif
