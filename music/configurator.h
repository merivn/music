#ifndef CONFIGURATOR
#define CONFIGURATOR
#include <iostream>
#include <string>
#include <QDebug>
#include <fstream>

using namespace std;

class Configurator {
public:

    Configurator (void);

    void load (
        string const& cfgFile //< [in] 配置文件路径
    );
    static string& trim (string& str);
    static vector<string> split (string const& str, string const& delim,int limit = 0);
    int m_volume;  //音量大小
};

//本地配置文件读取相关，暂时只设置了音量

#endif //


