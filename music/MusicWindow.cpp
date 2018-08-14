#include "MusicWindow.h"
#include "ui_MusicWindow.h"



MusicWindow *MusicWindow::s_pMainWnd=NULL;

MusicWindow*MusicWindow::InitInstance()
{
    if(!s_pMainWnd)
        s_pMainWnd=new MusicWindow;
    return s_pMainWnd;
}


MusicWindow::MusicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);

    init_var();  //初始化变量

    init_windowui(); //界面初始化

    init_musicplay(); //音乐播放初始化

    initNetwork();  //网络初始化

    set_connetfunc(); //设置槽函数的连接;

    init_database();

    traverse("/mp3"); // 遍历./mp3文件夹下所有歌曲文件并加载到列表

}


//重写鼠标事件１
void MusicWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
//重写鼠标事件２
void MusicWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
//重写鼠标事件３
void MusicWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
//暂未使用
void MusicWindow::mouseDoubleClickEvent(QMouseEvent *e){
    if(lyrict_rect.contains(e->pos()))   {

    }
}
//最小化槽函数
void MusicWindow::on_minButton_clicked()
{
    if( windowState() != Qt::WindowMinimized ){
        setWindowState( Qt::WindowMinimized );
    }
}
//最大化槽函数
void MusicWindow::on_maxButton_clicked()
{
    if(m_maxnor){

        ui->maxButton->setIcon(QIcon(":/img/maxm.png"));
        setWindowState( Qt::WindowMaximized );
    }
    else{

        ui->maxButton->setIcon(QIcon(":/img/max.png"));
        setWindowState( Qt::WindowNoState );
    }
    m_maxnor = ! m_maxnor;
}
//关闭槽函数
void MusicWindow::on_closeButton_clicked()
{
    musicPlayer->stop();
    close();
}
//　加载qss文件函数２
void MusicWindow::setStyle(const QString &style) {
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

//　播放暂停槽函数
void MusicWindow::on_playmusicButton_clicked()
{

    m_musicplay = ! m_musicplay;
    if(!m_musicplay){
        musicPlayer->pause();
        ui->playmusicButton->setIcon(QIcon(":/img/playmusic.png"));

    }
    else{
        musicPlayer->play();
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }

}
//　上一曲槽函数
void MusicWindow::on_premusicButton_clicked()
{

    music_change = true;
    if(!m_musicplay){
        m_musicplay = !m_musicplay;
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }
    if (q_MediaPlaylist == playlist){

        listWidget->setCurrentRow(playlist->previousIndex());

        playlist->setCurrentIndex(playlist->previousIndex());
    }
    else{
        searchWidget->setCurrentRow(searchlist->previousIndex());
        searchlist->setCurrentIndex(searchlist->previousIndex());
    }
    updateText();
    showlrc();
    to_play2();
}
//　下一曲槽函数
void MusicWindow::on_nextmusicButton_clicked()
{
    music_change = true;
    if(!m_musicplay){
        m_musicplay = !m_musicplay;
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }

    if (q_MediaPlaylist == playlist){

        listWidget->setCurrentRow(playlist->nextIndex());
        qDebug() << playlist->nextIndex() <<playlist->mediaCount();
        playlist->setCurrentIndex(playlist->nextIndex());

    }
    else{

        searchWidget->setCurrentRow(searchlist->nextIndex());
        searchlist->next();
        searchlist->setCurrentIndex(searchlist->nextIndex());
    }
    updateText();
    showlrc();
    to_play2();
}
//遍历指定路径下的ｍｐ３文件
int MusicWindow::traverse(const QString& path){
    QString  tmppath = QCoreApplication::applicationDirPath() + path;
    QDir dir(tmppath);
    if (!dir.exists()) {
        qDebug() << "dir error!";
        qDebug() <<  QCoreApplication::applicationDirPath();
        return -1;
    }

    QStringList list_tmp = dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    QStringList list = dir.entryList(QDir::Files);
    for(int i=0;i<list.size();i++){
        QString str4 = QCoreApplication::applicationDirPath();
//        int first = str4.lastIndexOf ("/");
//        QString fileName2 = str4.mid (0, first+1);
        QString str2 = str4 /*+ DEbug*/ + "/mp3/" +list.at(i);
//        qDebug()<< str2;
        playlist->addMedia(QUrl::fromLocalFile(str2));
        QString fileName=str2.split("/").last();
        fileName=fileName.split(".").first();
//        listWidget->addItem(str2);
        listWidget->addItem(fileName);
    }
    if(list_tmp.size()<1){
        return -1;
    }
    for(int i=0;i<list_tmp.size();i++){
        traverse(tmppath + "/" +list_tmp.at(i));
    }
}

//加载本地音乐槽函数
void MusicWindow::on_locmusicButton_clicked()
{

    pages->setCurrentIndex(0);
    QString initialName=QCoreApplication::applicationDirPath()+"/mp3";
    QStringList pathList=QFileDialog::getOpenFileNames(this, tr("选择文件"),\
                                                       initialName, tr("*.mp3","*wmv"));
    for(int i=0; i<pathList.size(); ++i)
    {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        if(!path.isEmpty())
        {
            qDebug() <<path;
            playlist->addMedia(QUrl::fromLocalFile(path));
            QString fileName=path.split("\\").last();
            fileName=fileName.split(".").first();
            listWidget->addItem(fileName);
        }
    }

}
//音量处理槽函数
void MusicWindow::on_volumeButton_clicked()
{
    volume_silence = ! volume_silence;
    if(!volume_silence){
        musicPlayer->setVolume(cur_music_volume);
        ui->volumeSlider->setValue(cur_music_volume);
        ui->volumeButton->setIcon(QIcon(":/img/volume.png"));

    }
    else{
        cur_music_volume =musicPlayer->volume();
        musicPlayer->setVolume(0);
        ui->volumeSlider->setValue(0);
        ui->volumeButton->setIcon(QIcon(":/img/silence.png"));
    }
}
//播放模式处理槽函数
void MusicWindow::on_playmodeButton_clicked()
{

    //    QMediaPlaylist::CurrentItemInLoop	1	单曲循环
    //    QMediaPlaylist::Sequential	2	顺序播放
    //    QMediaPlaylist::Loop	3	列表循环
    //    QMediaPlaylist::Random	4	随机播放
    if(m_playmode == QMediaPlaylist::Loop){
        m_playmode = QMediaPlaylist::Random;
        ui->playmodeButton->setIcon(QIcon(":/img/randomplay.png"));
    }
    else if(m_playmode ==QMediaPlaylist::Random){
        m_playmode = QMediaPlaylist::CurrentItemInLoop;
        ui->playmodeButton->setIcon(QIcon(":/img/circulateplay.png"));
    }
    else if(m_playmode ==QMediaPlaylist::CurrentItemInLoop){
        m_playmode = QMediaPlaylist::Loop;
         ui->playmodeButton->setIcon(QIcon(":/img/listplay.png"));
    }
    if (q_MediaPlaylist == playlist){
        playlist->setPlaybackMode(m_playmode);
    }
    else{
        searchlist->setPlaybackMode(m_playmode);
    }
}
//槽函数：实时更新显示时间
void MusicWindow::updatePosition(qint64 position)
{

    if (position == 0){
        music_end = false;
    }
    else if (music_change &&position > 0 && position < 200 ){
        l_dur = musicPlayer->duration();
        music_change = false;
    }
    if(position != 0&&position == musicPlayer->duration()&& music_end ==false ){
        //   qDebug()<< "下一曲";
        music_end = true;
        int currentrow = q_ListWidget->currentRow();
        if(++currentrow>q_ListWidget->count()){
            currentrow = q_ListWidget->count();
        }
        q_ListWidget->setCurrentRow(currentrow);
        music_change = true;
        updateText();
        showlrc();
        to_play2();
    }
    if (position> 60000&&list_hide){
        if(ui->listwidget->isVisible()){
            ui->listwidget->hide();
        }
    }
    ui->playtimeSlider->setValue(position);
    ui->palytimelabel->setText(Time(position));
    ui->palytimetotallabel->setText(Time(musicPlayer->duration()));
}
//　转换　ms　为字符串格式的时间（xx:xx）
QString MusicWindow::Time(qint64 time)
{
    int sec=time/1000;
    int min=sec/60;
    sec-=min*60;
    return
            QStringLiteral("%1:%2")
            .arg(min, 2, 10, QLatin1Char('0'))
            .arg(sec, 2, 10, QLatin1Char('0'));
}
//　　槽函数：实时更新音乐播放进度条
void MusicWindow::updateDuration(qint64 duration)
{
    ui->playtimeSlider->setRange(0,duration);
    ui->playtimeSlider->setEnabled(duration>0);
    ui->playtimeSlider->setPageStep(duration/10);
}
//　槽函数：　显示当前播放歌曲的歌名
void  MusicWindow::updateText()
{
    QString Text;
    QString tempauthor;
    if (q_ListWidget == searchWidget){

        tempauthor = searchWidget->currentItem()->text();
    }
    else if(q_ListWidget == listWidget){
        tempauthor = listWidget->currentItem()->text();
    }
    else if(q_ListWidget == collect_widget){
         tempauthor = collect_widget->currentItem()->text();
    }
    Text =tempauthor.section('-', 0, 0).trimmed()+ " - "+ \
            tempauthor.section('-', 1, 1).trimmed();

    ui->lyriclabel->setText(Text);
}
//　槽函数：　播放列表双击切换歌曲
void  MusicWindow::listDoubleClicked(){
    //
    pages->setCurrentIndex(PAGE_LRC);
    music_change = true;

    if (q_MediaPlaylist == searchlist){
        q_MediaPlaylist = playlist;
        musicPlayer->setPlaylist(playlist);
    }
    if (q_ListWidget == searchWidget){
        q_ListWidget = listWidget;
    }
    updateText();

    if(!m_musicplay){
        m_musicplay = !m_musicplay;
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }
    q_MediaPlaylist->setCurrentIndex(listWidget->currentIndex().row());
    musicPlayer->play();
   // qDebug()<<  m_musicplay;
    showlrc();
    to_play2(); //切换到mylrc界面，并更改背景图片
}
//　槽函数：　播放列表双击切换歌曲
void  MusicWindow::listDoubleClicked2(){

    music_change = true;
    if (q_MediaPlaylist == playlist){
        q_MediaPlaylist = searchlist;
        musicPlayer->setPlaylist(searchlist);
    }
    if (q_ListWidget == listWidget){
        q_ListWidget = searchWidget;
    }
    updateText();
    pages->setCurrentIndex(PAGE_LRC);


    if(!m_musicplay){
        m_musicplay = !m_musicplay;
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }

    int cur_item = searchWidget->currentIndex().row();
    s_strHash = lrc_Hash.at(cur_item);
   // qDebug() << "hash" << s_strHash;
    search.requestSongurl(s_strHash);


    showlrc();
    to_play2(); //切换到mylrc界面，并更改背景图片

}
void MusicWindow::collectDoubleClicked(){
    music_change = true;
    if (q_MediaPlaylist != collectlist){
        q_MediaPlaylist = collectlist;
        musicPlayer->setPlaylist(collectlist);
    }
    if (q_ListWidget != collect_widget){
        q_ListWidget = collect_widget;
    }
    updateText();
    pages->setCurrentIndex(PAGE_LRC);
    if(!m_musicplay){
        m_musicplay = !m_musicplay;
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }

    int cur_item = collect_widget->currentIndex().row();
 //   qDebug()  <<  collectlist->mediaCount();
//      qDebug() <<cur_item;
//    QString strHash = col_hash.at(cur_item);
   // qDebug() << "hash" << s_strHash;
//    search.requestSongurl(strHash);
      collectlist->setCurrentIndex(cur_item);
      musicPlayer->play();



    showlrc();
    to_play2(); //切换到mylrc界面，并更改背景图片


}

void MusicWindow::listclicked2(QListWidgetItem* curitem){
//    qDebug() << curitem;

}
//根据关键字搜索歌词并显示
void MusicWindow::showlrc(){

    QString tempauthor;
    QString strdur;
    int cur_item;
    int dur;
    QString strhash;
    if (q_MediaPlaylist == searchlist){
        tempauthor = searchWidget->currentItem()->text();
        cur_item = searchWidget->currentIndex().row();
        s_strHash = lrc_Hash.at(cur_item);
        s_dur = tempauthor.section('-',2, 2).trimmed();
        QTime time= QTime::fromString(s_dur,"mm:ss");
        dur=time.minute()*60*1000+time.second()*1000;

    }
    else if(q_MediaPlaylist == playlist){
        tempauthor = listWidget->currentItem()->text();
        cur_item = listWidget->currentIndex().row();
    }
    else if(q_MediaPlaylist == collectlist){
        tempauthor = collect_widget->currentItem()->text();
        cur_item = collect_widget->currentIndex().row();

        strhash = col_hash.at(cur_item);
        strdur = col_dur.at(cur_item);
        QTime time= QTime::fromString(strdur,"mm:ss");
        dur=time.minute()*60*1000+time.second()*1000;
    }

    QString strTemp = "lrc/" +tempauthor.section('-', 0, 0).trimmed()\
            +" - "+ tempauthor.section('-', 1, 1).trimmed() +".krc";
    s_musicname =tempauthor.section('-', 1, 1).trimmed();
    s_templocal=strTemp;

    QFileInfo fileInfo(strTemp);
    if(fileInfo.isFile())//歌词存在
    {
        QFile file(strTemp);
        if(!file.open(QIODevice::ReadOnly))
            return;
        QByteArray byt=file.readAll();
        lyrict->analyzeLrcContent(byt,strTemp);
        file.close();
    }
    else{
        if (q_MediaPlaylist == searchlist){
            search.requestlrc(s_musicname,dur,s_templocal,s_strHash);
        }
        else if (q_MediaPlaylist == playlist){
            search.requestlrc(s_musicname,l_dur,s_templocal);
        }
        else if(q_MediaPlaylist == collectlist){
            search.requestlrc(s_musicname, dur , s_templocal, strhash);
        }
    }

}
//　初始化函数：　ui的初始化
void  MusicWindow::init_windowui(void){

    searcht = new searchmusic();
    listt = new listmusic();
    collectt = new collectwidget();
    listt->hide();
    lyrict = new LyricWidget();
    lyrict->setAutoFillBackground(true);//


    QPalette palette = lyrict->palette();
    palette.setBrush(QPalette::Window,\
                      QBrush(QPixmap("au_bg_pic/0.jpg").scaled(this->size(),\
                       Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    lyrict->setPalette(palette);

    pages = new QStackedWidget(ui->contentwidget);
    pages->addWidget(listt); //本地音乐页面
    pages->addWidget(searcht); //搜索页面
    pages->addWidget(lyrict); // 歌词页面
    pages->addWidget(collectt);
    QVBoxLayout *mainpLayout = new QVBoxLayout();
    mainpLayout->addWidget(pages);
    mainpLayout->setSpacing(0);
    mainpLayout->setContentsMargins(0, 0, 0, 0);
    ui->contentwidget->setLayout(mainpLayout);

    lyrict->setOriginalStatus();


    ui->listScrollBar->setHidden(true); //隐藏列表滚动条
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉window主窗口标题栏
    // this->setGeometry(QRect(950, 55, 350, 250));//可设置窗口显示的方位与大小
    //设置应用图标
    this->setWindowIcon(QIcon(":/img/mobileipod.png"));
    //设置音量图片
    if(!volume_silence){
        ui->volumeButton->setIcon(QIcon(":/img/volume.png"));
    }
    else{
        ui->volumeButton->setIcon(QIcon(":/img/silence.png"));
    }
    ui->playmodeButton->setIcon(QIcon(":/img/listplay.png"));
    ui->winlrcButton->setIcon(QIcon(":/img/lrc.png"));
    ui->minButton->setIconSize(QSize(20,20));
    ui->maxButton->setIconSize(QSize(20,20));
    ui->closeButton->setIconSize(QSize(18,18));
    ui->minButton->setIcon(QIcon(":/img/min.png"));
    ui->closeButton->setIcon(QIcon(":/img/close.png"));
    if(m_maxnor){
        ui->maxButton->setIcon(QIcon(":/img/max.png"));
    }
    else{
        ui->maxButton->setIcon(QIcon(":/img/maxm.png"));
    }
    //设置音乐播放器按键图片
    //    ui->playmusicButton->setStyleSheet("QToolButton{border:Opx}");
    //设置音乐播放器按键自动适应图片
    ui->playmusicButton->setIconSize(QSize(40,40));
    ui->premusicButton->setIconSize(QSize(32,32));
    ui->nextmusicButton->setIconSize(QSize(32,32));
    ui->premusicButton->setIcon(QIcon(":/img/premusic.png"));
    ui->nextmusicButton->setIcon(QIcon(":/img/nextmusic.png"));
    if(!m_musicplay){
        ui->playmusicButton->setIcon(QIcon(":/img/playmusic.png"));
    }
    else{
        ui->playmusicButton->setIcon(QIcon(":/img/stopmusic.png"));
    }
    //ui界面布局
    QHBoxLayout* midlayouts = new QHBoxLayout();
    midlayouts->addWidget(ui->listwidget,2);
    midlayouts->addWidget(ui->contentwidget,8);
    ui->midwidget->setLayout(midlayouts);
    midlayouts->setMargin(0);
    //去掉布局中间的缝隙
    midlayouts->setSpacing(0);



    QVBoxLayout* mainLayout2 = new QVBoxLayout();
    mainLayout2->addWidget(ui->titlewidget,1);
    mainLayout2->addWidget(ui->midwidget,8.5);
    mainLayout2->addWidget(ui->bottomwidget,0.5);
    ui->centralWidget->setLayout(mainLayout2);
    //去掉布局外部的间隙
    mainLayout2->setContentsMargins(0,0,0,0);
    //去掉布局中间的缝隙
    mainLayout2->setSpacing(0);

    //歌词列表
    //添加一个搜索图标
    pTrailingAction = new QAction(this);
    pTrailingAction->setIcon(QIcon(":/img/searchr.png"));
    ui->searchEdit->addAction(pTrailingAction, QLineEdit::TrailingPosition);


}

//　初始化函数：　音乐的初始化
void  MusicWindow::init_musicplay(void){
//    test = 0;

    //在listmusic 的ui中添加的QListWidget 并显示无边框
    listWidget = new QListWidget(listt);
    QVBoxLayout *layout = new QVBoxLayout(listt);
    layout->addWidget(listWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    listt->setLayout(layout);
    listWidget->setStyleSheet("border-image: url(:/background/2.jpg); color: rgb(153, 102, 255);");
    //在searchmusic 的ui中添加的QListWidget 并显示无边框
    searchWidget = new myQlistWidget(searcht);
    QVBoxLayout *layout2 = new QVBoxLayout(searcht);
    layout2->addWidget(searchWidget);
    layout2->setSpacing(0);
    layout2->setContentsMargins(0, 0, 0, 0);
    searcht->setLayout(layout2);
    searchWidget->setStyleSheet("border-image: url(:/background/1.jpg); color: rgb(249, 157 ,195);");
    searcht->setStyleSheet(" color: rgb(249, 157 ,195);");
    collectt->setStyleSheet(" color: rgb(100, 101 ,102);");
    //在collectmusic 的ui中添加的QListWidget 并显示无边框
    collect_widget = new mycollectwidget(collectt);
    QVBoxLayout *layout3 = new QVBoxLayout(collectt);
    layout3->addWidget(collect_widget);
    layout3->setSpacing(0);
    layout3->setContentsMargins(0, 0, 0, 0);
    collectt->setLayout(layout3);
//    collect_widget->setStyleSheet("border-image: url(:/background/1.jpg); ");

    collect_widget->setStyleSheet("background: rgb(105, 192 ,253); ");

    connect(searchWidget,SIGNAL(sig_collection()),this,SLOT(slot_collection()));
    connect(collect_widget,SIGNAL(sig_delete_collect()),this,SLOT(slot_delete_collect()));
    //color: red;

    m_playmode = QMediaPlaylist::Loop; //播放模式初始化为顺序播放
    playlist=new QMediaPlaylist(this); //创建QMediaPlaylist对象
    searchlist = new QMediaPlaylist(this);
    collectlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(m_playmode); //设置播放模式
    searchlist->setPlaybackMode(m_playmode);
    collectlist->setPlaybackMode(m_playmode);

    q_MediaPlaylist = playlist;
    q_ListWidget = listWidget;

    musicPlayer = new QMediaPlayer();  //创建QMediaPlayer对象

    musicPlayer->setPlaylist(playlist); //播放列表设置

    //配置文件加载

    Configurator Config;
    Config.load("./bin/music.cfg");
    cur_music_volume = Config.m_volume;
    musicPlayer->setVolume(Config.m_volume);
    ui->volumeSlider->setValue(Config.m_volume);

}
void MusicWindow::initNetwork(){
    QThread *thread=new QThread;
    search.moveToThread(thread);
    thread->start();
    qRegisterMetaType<ItemResult>("ItemResult");
    qRegisterMetaType<SearchStatus>("SearchStatus");


    connect(&search,SIGNAL(dolrcworkfinished(QByteArray,QString)),\
            this,SLOT(slot_lrc(QByteArray,QString)));
    connect(&search,SIGNAL(sig_setBgpix(QStringList,QString)),\
            this,SLOT(slot_setBgPix(QStringList,QString)));
    connect(&search,SIGNAL(sig_seturl(QString)),\
            this,SLOT(slot_seturl(QString)));
    connect(&search,SIGNAL(sig_reqSongStatus(ItemResult,SearchStatus)),\
            this,SLOT(slot_requestSong(ItemResult,SearchStatus)));
    connect(&search,SIGNAL(sig_reqSongStatus2(ItemResult,SearchStatus)),\
            this,SLOT(slot_requestSong2(ItemResult,SearchStatus)));
}
//　槽函数连接设置
void MusicWindow::set_connetfunc(void){

    // 连接搜索图标到槽函数   onSearch(bool)
    connect(pTrailingAction, SIGNAL(triggered(bool)), this, SLOT(onSearch(bool)));

    m_timeline.setCurveShape(QTimeLine::LinearCurve);
    m_timeline.setLoopCount(0);
    connect(&m_timeline,SIGNAL(frameChanged(int)),SLOT(slot_timelineAnimation(int)));

    //音乐相关槽函数



    connect(musicPlayer,&QMediaPlayer::positionChanged,\
            lyrict,&LyricWidget::positionChanged1);
    connect(musicPlayer,&QMediaPlayer::durationChanged,this,&MusicWindow::updateDuration);
        //时间
    connect(musicPlayer,&QMediaPlayer::positionChanged,this,&MusicWindow::updatePosition);
        //时间条
    connect(ui->playtimeSlider,&QSlider::sliderMoved,musicPlayer,&QMediaPlayer::setPosition);
        //音乐条
    connect(ui->volumeSlider,&QSlider::sliderMoved,musicPlayer,&QMediaPlayer::setVolume);
        //本地列表双击
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(listDoubleClicked()));    //双击列表槽函数
        //搜索列表双击
    connect(searchWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(listDoubleClicked2()));    //双击列表槽函数

    connect(collect_widget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(collectDoubleClicked()));

//    connect(searchWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(listclicked2(QListWidgetItem*)));
}

//　初始化函数：初始化变量
void MusicWindow::init_var(void){

    //初始化鼠标移动事件
    last.setX(0);
    last.setY(0);
    m_maxnor = true; //窗口最大化、正常切换
    m_musicplay = false;  //播放、暂停切换
    volume_silence = false;//正常音量、静音切换
    music_change = false;
    list_hide = true;
}
MusicWindow::~MusicWindow() //析构函数
{

    musicPlayer->stop();
    delete ui;
}

void MusicWindow::on_downloadButton_clicked()
{

    switchPage();


}

void MusicWindow::on_TitleButton_clicked()
{
    list_hide = false;
    ui->listwidget->show();
}

void MusicWindow::on_mymusicButton_clicked()
{
    pages->setCurrentIndex(0);
}

void MusicWindow::on_myradioButton_clicked()
{
    lyrict->setAutoFillBackground(true); //
    QPalette palette = lyrict->palette();
    palette.setBrush(QPalette::Window,\
                      QBrush(QPixmap("au_bg_pic/0.jpg").scaled(this->size(),\
                       Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    lyrict->setPalette(palette);

    pages->setCurrentIndex(PAGE_LRC);

}


void MusicWindow::on_foundmusicButton_clicked()
{
    pages->setCurrentIndex(1);
    search.requestSong("");
}
//切换页面
void MusicWindow::switchPage()
{
    int nCount = pages->count();
    int nIndex = pages->currentIndex();

    ++nIndex;
    if (nIndex >= nCount)
        nIndex = 0;
    pages->setCurrentIndex(nIndex);
}

//搜索歌曲
void MusicWindow::onSearch(bool){
    pages->setCurrentIndex(1);

    QString musicnames = ui->searchEdit->text();

    search.requestSonglist(musicnames);


}
void MusicWindow::slot_pagechange(int index){
    if(index == 0){
        musicPlayer->setPlaylist(playlist);
    }
    else if (index == 3){
        musicPlayer->setPlaylist(searchlist);
    }
}
//处理歌曲列表搜索
void MusicWindow::slot_requestSong(const ItemResult &result,SearchStatus status){


    if(SearchStatus::Started==status)
    {
        searchWidget->clear();
        searchlist->clear();
        lrc_Hash.clear();
//        music_Url.clear();
        music_dur.clear();
        music_search_list.clear();
        searchWidget->setStyleSheet("border-image: url(:/background/search.jpg); ");
    }
    else if(SearchStatus::Searching==status)
    {
        QString musicinfor=  result.strSinger + " - " + result.strMusicName + " - " + result.strDur /*+ "-" + result.strHash*/;
        music_search_list.append(musicinfor);
        music_dur.append(result.strDur);
        lrc_Hash.append(result.strHash);
    }
    else if(SearchStatus::Finished==status){
        searchWidget->setStyleSheet("border-image: url(:/background/1.jpg); ");
        searchWidget->addItems(music_search_list);
    }
}
//测试用
void MusicWindow::slot_requestSong2(const ItemResult &result,SearchStatus status){ //测试用

    if(SearchStatus::Started==status)
    {

    }
    else if(SearchStatus::Searching==status)
    {
        QTime time= QTime::fromString(result.strDur,"mm:ss");
        int dur=time.minute()*60*1000+time.second()*1000;
        QString templocal = "lrc/" + result.strSinger+" - "+result.strMusicName +".krc";
        s_musicname =result.strMusicName;
        s_dur = dur;
        s_templocal=templocal;
        s_strHash= result.strHash;
        s_n = 0;

        search.requestlrc(s_musicname,dur,templocal,s_strHash);
    }
}

//回车
void MusicWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
        onSearch(true);
}
void MusicWindow::to_play(){

    QPalette palette = lyrict->palette();

    palette.setBrush(QPalette::Window,\
                      QBrush(QPixmap("au_bg_pic/0.jpg").scaled(this->size(),\
                       Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    lyrict->setPalette(palette);
}

//设置背景图
void MusicWindow::slot_setBgPix(const QStringList& piclist,const QString &strAuthor2)
{
    QString tempauthor;
    if (q_ListWidget == listWidget){
        tempauthor = listWidget->currentItem()->text();
    }
    else if(q_ListWidget ==searchWidget ){
        tempauthor = searchWidget->currentItem()->text();
    }
    else if(q_ListWidget == collect_widget){
        tempauthor = collect_widget->currentItem()->text();
    }
    tempauthor = tempauthor.section('-', 0, 0).trimmed();
    if(tempauthor ==  strAuthor2)
    {
//        qDebug() <<"success";
        QPalette palette = lyrict->palette();
        QFileInfo file(piclist.value(0));
        if(file.exists()==false)
        {
            palette.setBrush(QPalette::Window,\
                              QBrush(QPixmap("au_bg_pic/0.jpg").scaled(this->size(),\
                               Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

        }
        else{
            palette.setBrush(QPalette::Window,\
                              QBrush(QPixmap(piclist.value(0)).scaled(this->size(),\
                               Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

        }
        lyrict->setPalette(palette);

        m_timeline.setFrameRange(0,piclist.count()-1);
        if(piclist.count()!=0)
            m_timeline.setDuration((piclist.count())*10000);
        m_picList=piclist;
        m_timeline.start();
    }
}

void MusicWindow::slot_seturl(const QString &strurl){
    if(iscollect){
         collectlist->addMedia(QUrl(strurl));
         iscollect = false;
         return ;
    }
    else if (q_MediaPlaylist == searchlist){
        searchlist->addMedia(QUrl(strurl));
        searchlist->setCurrentIndex(searchlist->mediaCount()-1);
        musicPlayer->play();
    }

}
//解码并读取歌词
void MusicWindow::slot_lrc(QByteArray lrc, QString strName){
    lyrict->analyzeLrcContent(lrc,strName);

}

void MusicWindow::slot_timelineAnimation(int index)
{
    QFileInfo file(m_picList.value(index));
    QPalette palette = lyrict->palette();
    while(file.exists()==false)
    {
        index++;
    }
    palette.setBrush(QPalette::Window,\
                      QBrush(QPixmap(m_picList.value(index)).scaled(this->size(),\
                       Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    lyrict->setPalette(palette);
}
void MusicWindow::to_play2(){
    QString tempauthor;
    if (q_ListWidget == listWidget){
        tempauthor = listWidget->currentItem()->text();
    }
    else if(q_ListWidget ==searchWidget ){
        tempauthor = searchWidget->currentItem()->text();
    }
    else if(q_ListWidget ==collect_widget ){
        tempauthor = collect_widget->currentItem()->text();
    }
    tempauthor = tempauthor.section('-', 0, 0).trimmed();

    QString tempaupic;
    tempaupic= QString("au_bg_pic/%1/%2.jpg").arg(tempauthor).arg(0);


    QPalette palette = lyrict->palette();

    palette.setBrush(QPalette::Window,\
                      QBrush(QPixmap("au_bg_pic/0.jpg").scaled(this->size(),\
                       Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    lyrict->setPalette(palette);
  //    qDebug() << tempauthor;
    search.requestBgPic(tempauthor);

}
void MusicWindow::on_myenshrineButton_clicked()
{
    pages->setCurrentIndex(1);
}

void MusicWindow::on_videoButton_clicked()
{
//    d.createConnection();  //创建连接
//    d.createTable();
//    d.insert();
//    d.insert();
//    int i = d.tablecount();
 //   d.queryAll();          //已经完成过createTable(), insert(), 现在进行查询
   // d.deleteByname("张杰 - 天下 (2009张杰穿越人海北京演唱会)");
   // d.deleteByname("黑崎子 - 天下");
//    d.queryAll();
//    d.readAll(col_name,col_hash,col_dur);
//    collect_widget->addItems(col_name);
       pages->setCurrentIndex(3);
}

//更新歌词：重新搜索歌词
void MusicWindow::on_friendButton_clicked()
{
    if (!m_musicplay){
        return ;
    }
    QString tempauthor;
    int cur_item;
    int dur;
    QString strTemp = "lrc/" +tempauthor.section('-', 0, 0).trimmed()\
            +" - "+ tempauthor.section('-', 1, 1).trimmed() +".krc";

    s_templocal=strTemp;

    if (q_MediaPlaylist == searchlist){
        tempauthor = searchWidget->currentItem()->text();
        cur_item = searchWidget->currentIndex().row();
        s_strHash = lrc_Hash.at(cur_item);
        s_dur = tempauthor.section('-',2, 2).trimmed();
        QTime time= QTime::fromString(s_dur,"mm:ss");
        dur=time.minute()*60*1000+time.second()*1000;
        s_musicname =tempauthor.section('-', 1, 1).trimmed();
        search.requestlrc(s_musicname,dur,s_templocal,s_strHash);

    }
    else if(q_MediaPlaylist == playlist){
        tempauthor = listWidget->currentItem()->text();
        cur_item = listWidget->currentIndex().row();
        s_musicname =tempauthor.section('-', 1, 1).trimmed();
        search.requestlrc(s_musicname,l_dur,s_templocal);
    }

}

void MusicWindow::on_privateFMButton_clicked()
{
    list_hide = true;
    ui->listwidget->hide();
}
void MusicWindow::slot_collection(){
//     qDebug()<<"slot_collection";
     iscollect = true;
     QString tempauthor;
     int cur_item = searchWidget->currentIndex().row();
     tempauthor = searchWidget->currentItem()->text();

     QString musicname = tempauthor.section('-', 0, 0).trimmed()+ " - "+ \
             tempauthor.section('-', 1, 1).trimmed();
     collect_widget->addItem(musicname);
     QString musicdur = music_dur.at(cur_item);
     QString musichash = lrc_Hash.at(cur_item);

     d.createConnection();  //创建连接
     d.insertm(musicname,musichash,musicdur);

     col_name.append(musicname);
     col_hash.append(musichash);
     col_dur.append(musicdur);
     search.requestSongurl(musichash);

}

void MusicWindow::on_winlrcButton_clicked()
{
//    pages->setCurrentIndex(3);
}
void MusicWindow::init_database(void){
    d.createConnection();  //创建连接
    d.readAll(col_name,col_hash,col_dur);
    collect_widget->addItems(col_name);
    QString tmpurl;
    for(int i = 0; i< col_hash.size();++i)
    {
        iscollect = true;
        tmpurl = col_hash.at(i);
        search.requestSongurl(tmpurl);
    }


}
void MusicWindow::slot_delete_collect(){
    QString tempauthor = collect_widget->currentItem()->text();
    int cur_item = collect_widget->currentIndex().row();
    collect_widget->takeItem(cur_item);
    d.createConnection();
    d.deleteByname(tempauthor);
    //删除音乐播放列表
    collectlist->removeMedia(cur_item);
    //删除stringlist
    col_name.removeAt(cur_item);
    col_hash.removeAt(cur_item);
    col_dur.removeAt(cur_item);



}
