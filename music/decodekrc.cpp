#include "decodekrc.h"
#include <QString>
#include<QDebug>
#include <stdio.h>
#include <iostream>
using namespace std;
extern int  ZlibGetDecodeLength(uLong  InRawLength)
{
    return  compressBound(InRawLength);
}
extern int  ZlibGetDecodeLength(QByteArray  InRawData)
{
    return  compressBound(InRawData.length());
}

extern long  ZlibUncompress(QByteArray  &OutDecodeData, QByteArray InEncodeData,
                     int * nErrorCode)
{

    Bytef  *DecodeData = NULL; // 解压后的数据缓冲区
    Bytef  *EncodeData_Buffer = NULL;  // 要解压的数据缓冲区, 后面用memcpy放到这
    int     nFuncRet = Z_ERRNO;
    unsigned long  nOutLength = 0;
    nOutLength = ZlibGetDecodeLength(InEncodeData.length());
    nOutLength+=1000000;
    // 为缓冲区申请内存
    DecodeData        =  new Bytef[nOutLength];
    EncodeData_Buffer =  new Bytef[nOutLength];
    if (NULL != DecodeData && NULL != EncodeData_Buffer)
    {

        memcpy(EncodeData_Buffer, InEncodeData.constData(), InEncodeData.size());
        nFuncRet = uncompress(DecodeData, &nOutLength, (Bytef *)EncodeData_Buffer,
                              InEncodeData.length());
    //    qDebug() <<"uncompress:"<<nFuncRet;
        if (Z_OK == nFuncRet)
        {
            OutDecodeData.append((const char *)DecodeData, nOutLength);

        }
        else
        {
            nOutLength = -1;
        }
    }
    else
    {
        nOutLength = -1;
    }
    if (DecodeData)
        delete  DecodeData;
    if (EncodeData_Buffer)
        delete  EncodeData_Buffer;
    if (nErrorCode)
        *nErrorCode = nFuncRet;
    return  nOutLength;
}
extern int  KrcDecode(QByteArray  &KrcData, QByteArray  &LrcData)
{
    int nRet=0;
    QByteArray DecodeData;
    if (!KrcData.isEmpty())
    {
        // 校验开头 4 字符是否为正确
        if (KrcData.left(4) == "krc1")
        {
            KrcData.remove(0, 4);  // 去除文件头标识
            for (int i = 0; i < KrcData.size(); i++)
            {
                DecodeData.append((char)(KrcData[i] ^ Keys[i % 16]));
            }

            ZlibUncompress(LrcData, DecodeData, NULL);

        }
    }
    return nRet;
}
extern void test2(){
    unsigned char strSrc[] = "hello world! aaaaa bbbbb ccccc ddddd 中文测试 yes";
        unsigned char buf[1024] = {0};
        unsigned char strDst[1024] = {0};
        unsigned long srcLen = sizeof(strSrc);
        unsigned long bufLen = sizeof(buf);
        unsigned long dstLen = sizeof(strDst);

//        printf("Src string:%s\nLength:%ld\n", strSrc, srcLen);



        char *strSrc1 = (char *)strSrc;

        QString ttset = QString(QLatin1String(strSrc1));

          qDebug() <<"TEST2"<< ttset;
        /* 压缩 */
   int mm=  compress(buf, &bufLen, strSrc, srcLen);
//        printf("After Compressed Length:%ld\n", bufLen);
 qDebug() <<"mm"<<mm<<bufLen;
        /* 解压缩 */
      int nn=  uncompress(strDst, &dstLen, buf, bufLen);
//        printf("After UnCompressed Length:%ld\n",dstLen);
 qDebug() <<"nn"<<nn<<bufLen;
//        printf("UnCompressed String:%s\n",strDst);
        // cout <<strDst;

 char *strSrc2 = (char *)strDst;

 QString ttset2 = QString(QLatin1String(strSrc2));

   qDebug() <<"TEST2"<< ttset2;

}



