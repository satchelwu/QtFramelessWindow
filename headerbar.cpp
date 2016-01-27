#include "headerbar.h"
#include "mainwindow.h"

<<<<<<< HEAD

=======
>>>>>>> remotes/QtDirectUI/master
HeaderBar::HeaderBar(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(HEADER_H);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    CreateWidget();
    CreateLayout();
<<<<<<< HEAD
    //CreateEventFiter();
=======
    CreateEventFiter();
>>>>>>> remotes/QtDirectUI/master
    SetWidgetStyle();
}

HeaderBar::~HeaderBar()
{
}

<<<<<<< HEAD
void HeaderBar::updateMaxIcon(bool max)
{
    if(max)
    {
        if(NULL != ptrBtnMax) ptrBtnMax->setPix("restore.png");
    }
    else
    {
        if(NULL != ptrBtnMax) ptrBtnMax->setPix("max.png");
    }
}
=======
>>>>>>> remotes/QtDirectUI/master

void HeaderBar::CreateWidget() //创建子部件
{

    ptrLabelIcon = new QLabel(this);  //图像标签--logo
    QPixmap objPixmap(":/image/logo.png");
    ptrLabelIcon->setPixmap(objPixmap.scaled(77,30));

<<<<<<< HEAD
    ptrBtnMenu = new PushButton(this);
    ptrBtnMenu->setPix("menu.png");


    ptrBtnMin = new PushButton(this);
    ptrBtnMin->setPix("min.png");


    ptrBtnMax = new PushButton(this);
    ptrBtnMax->setPix("max.png");

    ptrBtnClose = new PushButton(this);
    ptrBtnClose->setPix("close.png");

=======
    QSize iconSize = QSize(30,30);

    ptrBtnMenu = new QToolButton(this);
    QPixmap menupix(":/image/title_bar_menu.png");
    ptrBtnMenu->setIcon(menupix);
    ptrBtnMenu->setIconSize(iconSize);

    ptrBtnMin = new QToolButton(this); //按钮--最小化
    QPixmap minpix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    ptrBtnMin->setIcon(minpix);
    ptrBtnMin->setIconSize(iconSize);

    ptrBtnMax = new QToolButton(this); //按钮--最大化/还原
    QPixmap maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    ptrBtnMax->setIcon(maxPix);
    ptrBtnMax->setIconSize(iconSize);

    ptrBtnClose = new QToolButton(this);  //按钮--关闭
    QPixmap closepix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    ptrBtnClose->setIcon(closepix);
    ptrBtnClose->setIconSize(iconSize);
>>>>>>> remotes/QtDirectUI/master

    const QObjectList &objList = children();   //获得子部件
    for(int nIndex=0; nIndex<objList.count();++nIndex)
    {
        ((QWidget*)(objList.at(nIndex)))->setMouseTracking(true);  //设置子部件的MouseTracking属性
<<<<<<< HEAD
        if(0==qstrcmp(objList.at(nIndex)->metaObject()->className(),"PushButton"))  //如果是QToolButton部件
        {
            connect(((PushButton*)(objList.at(nIndex))),SIGNAL(pressed()),this,SLOT(slot_btnpress()));  //连接pressed信号为slot_btnpress
            connect(((PushButton*)(objList.at(nIndex))),SIGNAL(clicked()),this,SLOT(slot_btnclick())); //连接clicked信号为slot_btnclick
           ((QToolButton*)(objList.at(nIndex)))->setContentsMargins(0,0,0,0);//设置顶部间距
=======
        if(0==qstrcmp(objList.at(nIndex)->metaObject()->className(),"QToolButton"))  //如果是QToolButton部件
        {
            connect(((QToolButton*)(objList.at(nIndex))),SIGNAL(pressed()),this,SLOT(slot_btnpress()));  //连接pressed信号为slot_btnpress
            connect(((QToolButton*)(objList.at(nIndex))),SIGNAL(clicked()),this,SLOT(slot_btnclick())); //连接clicked信号为slot_btnclick
            //((QToolButton*)(objList.at(nIndex)))->setContentsMargins(0,0,0,0);//设置顶部间距
>>>>>>> remotes/QtDirectUI/master
        }
    }
}


void HeaderBar::SetWidgetStyle()  //设置子部件样式(qss)
{   
<<<<<<< HEAD
    setAutoFillBackground(true);
    QPalette pal;
    QPixmap pix(":/image/header.png");
    pal.setBrush(backgroundRole(),QBrush(pix));
    setPalette(pal);
=======
    //setStyleSheet("QLabel{color:#CCCCCC;font-size:12px;font-weight:bold;}QToolButton{border:0px;}"); //设置标签的文本颜色，大小等以及按钮的边框
    //设置左边距
    //m_pLabelTitle->setStyleSheet("margin-left:6px;");
    //设置右边距以及鼠标移上去时的文本颜色
   // m_pLabelVersion->setStyleSheet("QLabel{margin-right:10px;}QLabel:hover{color:#00AA00;}");
>>>>>>> remotes/QtDirectUI/master
}


void HeaderBar::CreateLayout()  //创建设置布局
{ 
    ptrTitleLayout = new QHBoxLayout(this); //水平布局
<<<<<<< HEAD
    ptrTitleLayout->addWidget(ptrLabelIcon, 0, Qt::AlignTop);  //添加部件
    ptrTitleLayout->addStretch();
    ptrTitleLayout->addWidget(ptrBtnMenu, 0, Qt::AlignTop);
    ptrTitleLayout->addWidget(ptrBtnMin, 0, Qt::AlignTop);
    ptrTitleLayout->addWidget(ptrBtnMax, 0, Qt::AlignTop);
    ptrTitleLayout->addWidget(ptrBtnClose, 0, Qt::AlignTop);
    ptrTitleLayout->setContentsMargins(0,0,0,0); //设置Margin
    ptrTitleLayout->setSpacing(0); //设置部件之间的space


    ptrToolLayout = new QHBoxLayout(this);
   /* QWidget *widget = new QWidget(this);
    ptrToolLayout->addWidget(widget);*/
    ptrHeaderLayout =new QVBoxLayout(this);

    ptrHeaderLayout->addLayout(ptrTitleLayout);\
    ptrHeaderLayout->addLayout(ptrToolLayout);
=======
    ptrTitleLayout->addWidget(ptrLabelIcon);  //添加部件
    ptrTitleLayout->addWidget(ptrBtnMenu);
    ptrTitleLayout->addWidget(ptrBtnMin);
    ptrTitleLayout->addWidget(ptrBtnMax);
    ptrTitleLayout->addWidget(ptrBtnClose);
    ptrTitleLayout->setContentsMargins(0,0,0,0); //设置Margin
    ptrTitleLayout->setSpacing(0);
     //设置部件之间的space

    ptrToolLayout = new QHBoxLayout(this);
    ptrHeaderLayout =new QVBoxLayout(this);

    ptrHeaderLayout->addItem(ptrTitleLayout);\
    ptrHeaderLayout->addItem(ptrToolLayout);
>>>>>>> remotes/QtDirectUI/master
    ptrHeaderLayout->setContentsMargins(0,0,0,0); //设置Margin
    ptrHeaderLayout->setSpacing(0);
    setLayout(ptrHeaderLayout);
}


<<<<<<< HEAD


void HeaderBar::slot_btnpress()   //槽函数--slot_btnpress()
=======
void HeaderBar::SetBtnIcon(QToolButton *pBtn,eBtnMoustState state,bool bInit/*=false*/)  //设置按钮不同状态下的图标
{
    QString strImagePath = GetBtnImagePath(pBtn,bInit); //获得图片路径
    QPixmap objPixmap(strImagePath);  //创建QPixmap对象

    int nPixWidth = objPixmap.width(); //得到图像宽和高
    int nPixHeight = objPixmap.height();

    if(state!=eBtnStateNone)//如果状态不是无效值
    {
        /*设置按钮图片
        按钮的图片是连续在一起的，如前1/4部分表示默认状态下的图片部分,接后的1/4部分表示鼠标移到按钮状态下的图片部分
        */
        pBtn->setIcon(objPixmap.copy((nPixWidth/4)*(state-1),0,nPixWidth/4,nPixHeight));
        //设置按钮图片大小
        pBtn->setIconSize(QSize(nPixWidth/4,nPixHeight));
    }
}


//获得图片路径(固定值)
const QString HeaderBar::GetBtnImagePath(QToolButton *pBtn,bool bInit/*=false*/)
{
    QString strImagePath;

    if(ptrBtnMenu==pBtn)
    {
        strImagePath = ":/image/title_bar_menu.png";
    }
    //最小化
    if(ptrBtnMin==pBtn)
    {
        strImagePath = ":/image/sys_button_min.png";
    }
    //最大化/还原按钮，所以包括最大化和还原两张图片
    if(ptrBtnMax==pBtn)
    {
        //如果是初始设置或者主界面的最大化标志不为真(其中MainWindow::Instance()使用单例设计模式)
        if(bInit==true /*|| MainWindow::Instance()->GetMaxWin()==false*/)
        {
            //最大化按钮图片路径
            strImagePath = ":/image/sys_button_max.png";
        }
        else
        {
            //还原按钮图片路径
            strImagePath = ":/image/sys_button_restore.png";
        }
    }
    //关闭按钮
    if(ptrBtnClose==pBtn)
    {
        strImagePath = ":/image/sys_button_close.png";
    }
    return strImagePath;
}


//创建事件过滤器
void HeaderBar::CreateEventFiter()
{
    ptrBtnMenu->installEventFilter(this);
    ptrBtnMin->installEventFilter(this);
    ptrBtnMax->installEventFilter(this);
    ptrBtnClose->installEventFilter(this);
}

//事件过滤
bool HeaderBar::eventFilter(QObject *obj, QEvent *event)
{
    //按钮状态
    eBtnMoustState eState = eBtnStateNone;
    //判断事件类型--QEvent::Enter
    if (event->type() == QEvent::Enter)
    {
        eState = eBtnStateHover;
    }
    //判断事件类型--QEvent::Leave
    if (event->type() == QEvent::Leave)
    {
        eState = eBtnStateDefault;
    }
    //判断事件类型--QEvent::MouseButtonPress
    if (event->type() == QEvent::MouseButtonPress && ((QMouseEvent*)(event))->button()== Qt::LeftButton)
    {
        eState = eBtnStatePress;
    }
    //判断目标
    if(ptrBtnMenu==obj)
    {
        //如果状态有效
        if(eState != eBtnStateNone)
        {
            //根据状态设置按钮图标
            //SetBtnIcon((QToolButton *)obj,eState);
            return false;
        }
    }
    return QWidget::eventFilter(obj,event);
}

//槽函数--slot_btnpress()
void HeaderBar::slot_btnpress()
>>>>>>> remotes/QtDirectUI/master
{
 /*   QToolButton *pBtn = (QToolButton*)(sender());
    if(pBtn==ptrBtnMin)
    {
        emit signal_min();
    }
    if(pBtn==ptrBtnMax)
    {
        emit signal_maxrestore();
    }
    if(pBtn==ptrBtnClose)
    {
        emit signal_close();
    }*/
}


<<<<<<< HEAD

void HeaderBar::slot_btnclick()  //槽函数--slot_btnclick
{
    PushButton *ptrBtn = (PushButton*)(sender());
=======
//槽函数--slot_btnclick
void HeaderBar::slot_btnclick()
{
    QToolButton *ptrBtn = (QToolButton*)(sender());
>>>>>>> remotes/QtDirectUI/master
    if(ptrBtn==ptrBtnMin)
    {
        emit signal_min();
    }
    if(ptrBtn==ptrBtnMax)
    {
        emit signal_maxrestore();
    }
    if(ptrBtn==ptrBtnClose)
    {
        emit signal_close();
    }
}

