#include "configurator.h"
Configurator::Configurator (void) :m_volume(10){}
void Configurator::load (
    string const& cfgFile // [输入] 配置文件路径
    ) {
    ifstream ifs (cfgFile.c_str ());
    if (! ifs)
       qDebug() << "read"<<  cfgFile.c_str () << "error";
    string line;
    for (int lineNo = 0; getline (ifs, line); ++lineNo) {
        trim (line);
        if (line[0] == '#' || line[0] == '\0')
            continue;
       vector<string> strv = split (line, "=", 1);
        if (strv.size () == 2) {
            // 若键为"MUSIC_VOLUME"
            if (! strcasecmp (strv[0].c_str (), "MUSIC_VOLUME"))
                m_volume = atoi (strv[1].c_str ());
            else
                qDebug() << "no MUSIC_VOLUME";
        }
        else
             qDebug() << "no MUSIC_VOLUME2";
    }
    ifs.close ();
}

string& Configurator::trim (string& str) {
    string::size_type first = str.find_first_not_of (" \t\r\n"),
        last = str.find_last_not_of (" \t\r\n");
    if (first == string::npos || last == string::npos)
        str.clear ();
    else
        str = str.substr (first, last - first + 1);
    return str;
}

vector<string> Configurator::split ( string const& str,string const& delim, int limit ) {
    vector<string> strv;
    char temp[str.size () + 1];
    strcpy (temp, str.c_str ());
    for (char* token = strtok (temp, delim.c_str ());
        token; token = strtok (NULL, delim.c_str ())) {
        string part = token;
        strv.push_back (trim (part));
        if (! --limit && (token += strlen (token)) - temp <
            (int)str.size ()) {
            strv.push_back (trim (part = ++token));
            break;
        }
    }
    return strv;
}
