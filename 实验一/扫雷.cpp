CMy2_1View::CMy2_1View()
{
    // TODO: add construction code here
    //flag = 1;             //模式标志
    for(int ii=0;ii<16;ii++)
        m_Bitmap[ii].LoadBitmap(IDB_BITMAP14+ii);
    for(int jj = 0;jj < 4;jj++)
        m_anniu[jj].LoadBitmap(IDB_ANNIU1+jj);
    second = 0;           //计时
    s_start = 0;          //1时开始计时
    m_RowCount = 10;      //行数
    m_ColCount = 10;      //列数
    leinum = 10;
    leftnum = leinum;     //剩余雷数
    over = 0;             //over = 1时停止
    int aa = 0;
     //初始化0
    for(int i=0;i < m_RowCount;i++)
    {
        for(int j = 0;j < m_ColCount;j++)
        {
            lei[i][j].shumu = 0;
            lei[i][j].weitu = 0;
        }
    }
     
    CTime time = GetCurrentTime(); //获取当前时间
    int s;                  
    s = time.GetSecond();         //获取秒数
 /***********标雷************/
    do
    {
/*************以当前秒数为产生随机算法**********/
        int k = (rand()*s) % m_RowCount;
        int l = (rand()*s) % m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    //给方格赋值，计算雷数
    for(int a=0;a<m_RowCount;a++)
        for(int b=0;b<m_ColCount;b++)
            if(lei[a][b].shumu == 0)
            {
                for(int c=a-1;c<a+2;c++)
                    for(int d=b-1;d<b+2;d++)
                        if(c>=0 && c<m_RowCount && d>=0 && d<m_ColCount)
                            if(lei[c][d].shumu == -1)  //发现雷
                                lei[a][b].shumu++;      //数目+1
            }
}
 
CMy2_1View::~CMy2_1View()
{
     
}
 
BOOL CMy2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs
 
    return CView::PreCreateWindow(cs);
}
 
/////////////////////////////////////////////////////////////////////////////
// CMy2_1View drawing
 
void CMy2_1View::OnDraw(CDC* pDC)
{
    CMy2_1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // TODO: add draw code for native data here
/***********************背景颜色(+)*******************************/
    //画背景
    CBrush mybrush1;
    int c1 = 192, c2 = 192, c3 = 192;
    switch(flag)
    {
    case 0:    
        c1 = 192, c2 = 192, c3 = 192;break;
    case 1:
        c1 = 200, c2 = 100, c3 = 100;break;
    case 2:
        c1 = 100, c2 = 100, c3 = 200;break;
    case 3:
        c1 = 100, c2 = 200, c3 = 100;break;
    }
    mybrush1.CreateSolidBrush(RGB(c1,c2,c3));
    CRect myrect1(0,0,1200,800);
    pDC->FillRect(myrect1,&mybrush1);
    //画框
    /*************显示秒数和雷数的窗口*********************/
    CBrush mybrush;
    mybrush.CreateSolidBrush(RGB(0,0,0));
    CRect myrect(20,10,70,40);
    pDC->FillRect(myrect,&mybrush);
 
    CRect myrect2(325,10,375,40);
    pDC->FillRect(myrect2,&mybrush);
 
    CPen mypen;
    CPen*myoldPen;
    mypen.CreatePen(PS_SOLID,2,RGB(255,255,255));
    myoldPen = pDC -> SelectObject(&mypen);
//画黑框的白线
    pDC->MoveTo(20,40);
    pDC->LineTo(70,40);
    pDC->LineTo(70,10);
    pDC->MoveTo(325,40);
    pDC->LineTo(375,40);
    pDC->LineTo(375,10);
//画雷区边线
    for(int i = 0;i < m_RowCount;i++)
        for(int j = 0;j < m_ColCount;j++)
        {
            pDC -> MoveTo(10+i*15, 50+j*15+14);
            pDC -> LineTo(10+i*15, 50+j*15);
            pDC -> LineTo(10+i*15+14, 50+j*15);
        }
    pDC -> SelectObject(myoldPen);
 
    CPen mypen2;
    CPen*myoldPen2;
    mypen2.CreatePen(PS_SOLID,1,RGB(0,0,0));
    myoldPen2 = pDC->SelectObject(&mypen2);
    for(int ii=0;ii<m_RowCount;ii++)
        for(int jj=0;jj<m_ColCount;jj++)
        {
            pDC -> MoveTo(10+ii*15, 50+jj*15+14);
            pDC -> LineTo(10+ii*15+14, 50+jj*15+14);
            pDC -> LineTo(10+ii*15+14, 50+jj*15);
        }
    pDC -> SelectObject(myoldPen2);
 
         CDC Dc;
     if(Dc.CreateCompatibleDC(pDC)==FALSE)
          AfxMessageBox("Can't create DC");    //按钮风格
/*******************显示按钮***************/
     Dc.SelectObject(m_anniu[0]);
     pDC -> BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);
      
/********************显示位图*****************/
 /*
     判断显示什么位图
     weitu=1已按下的数字区
     weitu=2显示旗
     weitu=3显示问号
*/
     for(int a=0;a<m_RowCount;a++)
         for(int b=0;b<m_ColCount;b++)
            {
                if(lei[a][b].weitu == 1)                    //数字类
                {
                    Dc.SelectObject(m_Bitmap[lei[a][b].shumu]);
                    pDC->BitBlt(a*15+10,b*15+50,160,160,&Dc,0,0,SRCCOPY);
                }
                if(lei[a][b].weitu == 2)                   //插旗
                {
                    Dc.SelectObject(m_Bitmap[9]); 
                    pDC->BitBlt(a*15+10,b*15+50,160,160,&Dc,0,0,SRCCOPY);
                }
                if(lei[a][b].weitu == 3)                   //问号
                {
                    Dc.SelectObject(m_Bitmap[10]);
                    pDC->BitBlt(a*15+10,b*15+50,160,160,&Dc,0,0,SRCCOPY);
                }
                //结束
                if(over == 1 && lei[a][b].shumu == -1)
                {
                    Dc.SelectObject(m_Bitmap[11]);
                    pDC->BitBlt(a*15+10,b*15+50,160,160,&Dc,0,0,SRCCOPY);
                    Dc.SelectObject(m_anniu[3]);
                    pDC->BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);
                }
                 
            }
/**********************************显示黑框里的数字******************************/
    int nOldDC=pDC->SaveDC();
    pDC->SetTextColor(RGB(255,0,0));
    pDC->SetBkColor(RGB(0,0,0));
    CFont font;                                 
    if(0==font.CreatePointFont(160,"Comic Sans MS"))
    {
        AfxMessageBox("Can't Create Font");
    }
    pDC->SelectObject(&font);
    CString str; 
    if(leftnum<10)
        str.Format("00%d",leftnum);
    else
        str.Format("0%d",leftnum);                 
    pDC->TextOut(25,10,str);
    if(second<10)
        str.Format("00%d",second);
    else if(second<100)
            str.Format("0%d" ,second);
        else
            str.Format("%d" ,second);
    pDC->TextOut(330,10,str);
    pDC->RestoreDC(nOldDC);
            //////////////////////////////////////////////
}
 
/////////////////////////////////////////////////////////////////////////////
// CMy2_1View printing
 
BOOL CMy2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}
 
void CMy2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}
 
void CMy2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}
 
/////////////////////////////////////////////////////////////////////////////
// CMy2_1View diagnostics
 
#ifdef _DEBUG
void CMy2_1View::AssertValid() const
{
    CView::AssertValid();
}
 
void CMy2_1View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}
 
CMy2_1Doc* CMy2_1View::GetDocument() // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2_1Doc)));
    return (CMy2_1Doc*)m_pDocument;
}
#endif //_DEBUG
 
/////////////////////////////////////////////////////////////////////////////
// CMy2_1View message handlers
 
void CMy2_1View::OnTimer(UINT nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
     
    if(over == 1)         //结束，返回
        return;
     
    leizero();              //显示个数为0的方格
     
    if(s_start > 0)       //计时
        s_start++;
    if(s_start == 20)
    {
        s_start = 1;
        second++;  
        //重画时间
        CRect rect3;
        rect3.left = 325;
        rect3.right = 375;
        rect3.top = 10;
        rect3.bottom = 40;
        InvalidateRect(&rect3);
    }
    CView::OnTimer(nIDEvent);
}
 
void CMy2_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    /*************弹出对话框**************/
     
    CString strOutput1; //生成用于输出的格式化的字符
    strOutput1.Format("YOU WIN!");
     
 
    CString strOutput2;
    strOutput2.Format("YOU LOSE!");
    /****************************************/
 
  /***********获取指针pdc*************/
     CDC *pDC=GetDC();
     CDC Dc;
     if(Dc.CreateCompatibleDC(pDC) == FALSE)
          AfxMessageBox("Can't create DC");       //按钮风格   
    /*************显示按下按钮*************/
     if(point.x>180 && point.x<210 && point.y>10 && point.y<40)
     {
        Dc.SelectObject(m_anniu[3]);
        pDC->BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);    
     }
    if((point.x >= 10) && (point.x <= 385) && (point.y >= 50) && (point.y <= 290))
    {          
        if(over == 1)
            return;
 
         
        Dc.SelectObject(m_anniu[1]);              //显示按钮(ANNIU1)
        pDC->BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);
        /*
        各参数意义：
        目标区域左上角点的x坐标
        目标区域左上角点的y坐标
        目标区域的宽度
        目标区域的高度
        源贴图区域DC的指针
        源贴图区域x坐标
        源贴图区域y坐标
        像素直接拷贝模式
        */
     
        s_start = 1;               //开始计时
        int a = (point.x - 10) / 15;
        int b = (point.y - 50) / 15;
        if(lei[a][b].weitu == 0 || lei[a][b].weitu == 3)
        {
            if(lei[a][b].shumu == -1)
            {
                over = 1;
                KillTimer(1);              
                Invalidate();
                MessageBox(strOutput2);           //弹出YOU LOSE
            }
            else if (leftnum == 0)
            {
                over = 1;
                KillTimer(1);              
                Invalidate();
                MessageBox(strOutput1);    
            }
            else
            {
                lei[a][b].weitu = 1;
                CRect rect;
                rect.left = a * 15 + 10;
                rect.right = a * 15 + 25;
                rect.top = b * 15 + 50;
                rect.bottom = b * 15 + 65;
                InvalidateRect(&rect);
            }  
        }
         
    }
 
    CView::OnLButtonDown(nFlags, point);
}
 
void CMy2_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
 
    //结束，返回
    if(over == 1)
        return;
    if((point.x >= 10) && (point.x <= 385) && (point.y >= 50) && (point.y <= 290))
    {      
        int a = (point.x - 10) / 15;
        int b = (point.y - 50) / 15;
 
        if(lei[a][b].weitu == 0 || lei[a][b].weitu == 3)      //无显示或问号 
        {
            lei[a][b].weitu = 2;                              //按右键插旗          
            leftnum--;                                        //雷数-1
         
        }
        else
            if(lei[a][b].weitu == 2)                          //雷旗
            {
                lei[a][b].weitu = 3;                          //按右键显示问号
                leftnum++;                                    //雷数+1
            }
       /**********重画剩下雷数*********/
        CRect rect2;
        rect2.left = 20;
        rect2.right = 70;
        rect2.top = 10;
        rect2.bottom = 40;
        InvalidateRect(&rect2);        
        /**********重画打击格子*************/
        CRect rect;
        rect.left = a * 15 + 10;
        rect.right = a * 15 + 25;
        rect.top = b * 15 + 50;
        rect.bottom = b * 15 + 65;
        InvalidateRect(&rect);     
    }
    CView::OnRButtonDown(nFlags, point);
}
 
  
int CMy2_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;
     
    // TODO: Add your specialized creation code here
//  SetTimer(1,50,NULL);
    return 0;
}
 
/***********************扫描，如果是已经被按下且雷数为0，显示它周围的格子数，并重画******************/
void CMy2_1View::leizero()
{
    for(int i = 0;i < m_RowCount;i++)
        for(int j = 0;j < m_ColCount;j++)
            if(lei[i][j].shumu == 0 && lei[i][j].weitu ==  1)   //位图显示为数字类型
            {
                for(int n = i - 1;n < i + 2;n++)
                    for(int m = j - 1;m < j + 2;m++)
                        if(n >= 0 && n < 25 && m >= 0 && m < m_ColCount)
                            if(lei[n][m].shumu != -1 && lei[n][m].weitu == 0)
                            {
                                lei[n][m].weitu = 1;
                                CRect rect;
                                rect.left = n * 15 + 10;
                                rect.right = n * 15 + 25;
                                rect.top = m * 15 + 50;
                                rect.bottom = m * 15 + 65;
                                InvalidateRect(&rect);     
                            }
            }
}
 
/**********************重新开始函数(+)*****************************/
//原理与构造函数一样，默认的模式初始化为简单模式
void CMy2_1View::OnStart()
{
    //flag = 1;
    SetTimer(1,50,NULL);
    // TODO: Add your command handler code here
    m_RowCount = 10;                  //行数
    m_ColCount = 10;                  //列数
    leinum = 10;
    leftnum = leinum;                 //剩余雷数
    second = 0;                       //计时
    s_start = 0;                      //1时开始计时
    leftnum = leinum;                 //剩余雷数
    over = 0;                       //over = 1时停止
    int aa = 0;
    //初始化0
    for(int i = 0;i < m_RowCount;i++)
    {
        for(int j = 0;j < m_ColCount;j++)
        {
            lei[i][j].shumu = 0;
            lei[i][j].weitu = 0;
        }
    }
    /*********************设置10个雷************************/
    do
    {
        int k = rand() % m_RowCount;
        int l = rand() % m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    /***********************给方格赋值***********************/
    for(int a = 0;a < m_RowCount;a++)
        for(int b = 0;b < m_ColCount;b++)
            if(lei[a][b].shumu == 0)
            {
                for(int c = a - 1;c < a + 2;c++)
                    for(int d = b - 1;d < b + 2;d++)
                        if(c >= 0 && c < m_RowCount && d >= 0 && d < m_ColCount)
                            if(lei[c][d].shumu == -1)
                                lei[a][b].shumu++;     
            }
    Invalidate();
}
 
void CMy2_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    CDC *pDC = GetDC();
    CDC Dc;
    if(Dc.CreateCompatibleDC(pDC) == FALSE)
      AfxMessageBox("Can't create DC");
    //显示按钮
    Dc.SelectObject(m_anniu[0]);
    pDC -> BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);
     
    if(over == 1)
    {
        // KillTimer(1);  //时间停止
        Dc.SelectObject(m_anniu[2]);
        pDC -> BitBlt(180,10,160,160,&Dc,0,0,SRCCOPY);
    }  
 
    if(point.x>180 && point.x<210 && point.y>10 && point.y<40)
        OnStart();
 
    CView::OnLButtonUp(nFlags, point);
}
 
/****************简单模式(+)**********************/
void CMy2_1View::OnEasy()
{
    //flag = 1;          //简单模式标志
    SetTimer(1,50,NULL);
    // TODO: Add your command handler code here
    m_RowCount = 10;        //行数
    m_ColCount = 10;        //列数
    leinum = 10;            //初始化雷数
    leftnum = leinum;       //剩余雷数
    second=0;               //计时
    s_start = 0;            //1时开始计时
    leftnum = leinum;       //剩余雷数
    over = 0;               //over=1时停止
    int aa = 0;
    for(int i = 0;i < m_RowCount;i++) //初始化0
    {
        for(int j = 0;j < m_ColCount;j++)
        {
            lei[i][j].shumu = 0;
            lei[i][j].weitu = 0;
        }
    }
    //设置10个雷
    do
    {
        int k = rand()%m_RowCount;
        int l = rand()%m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    /****************给方格赋值*************/
    for(int a = 0;a < m_RowCount;a++)
        for(int b = 0;b < m_ColCount;b++)
            if(lei[a][b].shumu == 0)
            {
                for(int c = a-1;c < a + 2;c++)
                    for(int d = b - 1;d < b + 2;d++)
                        if(c >= 0 && c < m_RowCount && d >= 0 && d < m_ColCount)
                            if(lei[c][d].shumu == -1)
                                lei[a][b].shumu++;     
            }
    Invalidate();
 
     
}
 
/***************困难模式(+)********************/
void CMy2_1View::OnDifficult()
{
    //flag = 3;                      //困难模式标志
    SetTimer(1,50,NULL);
    // TODO: Add your command handler code here
    m_RowCount = 25;                //行数
    m_ColCount = 16;                //列数
    leinum = 100;
    leftnum = leinum;               //剩余雷数
    second = 0;                       //计时
    s_start = 0;                    //1时开始计时
    leftnum = leinum;               //剩余雷数
    over = 0;                      //over = 1时停止
    int aa = 0;
 
    for(int i = 0;i < m_RowCount;i++)    //初始化0
    {
        for(int j = 0;j < m_ColCount;j++)
        {
            lei[i][j].shumu=0;
            lei[i][j].weitu=0;
        }
    }
/********************设置100个雷*********************/
    do
    {
    /*****以行和列为参数产生随机数*****/
        int k = rand() % m_RowCount;
        int l = rand() % m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    /****************给方格赋值*************/
    for(int a = 0;a < m_RowCount;a++)
        for(int b = 0; b < m_ColCount;b++)
            if(lei[a][b].shumu == 0)
            {
                for(int c = a-1;c < a+2;c++)
                    for(int d = b - 1;d < b + 2;d++)
                        if(c >= 0 && c < m_RowCount && d >= 0 && d < m_ColCount)
                            if(lei[c][d].shumu == -1)
                                lei[a][b].shumu++;     
            }
    Invalidate();
 
     
}
 
/**************中等模式(+)******************/
void CMy2_1View::OnMiddle()
{
    //flag = 2; //中等模式标志
    SetTimer(1,50,NULL);
    // TODO: Add your command handler code here
    m_RowCount = 20;             //行数
    m_ColCount = 12;             //列数
    leinum = 40;                 //初始化雷数
    leftnum = leinum;            //剩余雷数
    second = 0;                  //计时
    s_start = 0;                 //1时开始计时
    leftnum = leinum;            //剩余雷数
    over = 0;                    //over = 1时停止
    int aa = 0;
     
    for(int i = 0;i < m_RowCount;i++)            //初始化0
    {
        for(int j = 0;j < m_ColCount;j++)
        {
            lei[i][j].shumu = 0;
            lei[i][j].weitu = 0;
        }
    }
 /********************设置40个雷*********************/
    do
    {
        /*****以行和列为参数产生随机数*****/
        int k = rand() % m_RowCount;
        int l = rand() % m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    /****************给方格赋值*************/
    for(int a = 0;a < m_RowCount;a++)
        for(int b = 0;b < m_ColCount;b++)
            if(lei[a][b].shumu == 0)
            {
                for(int c=a-1;c<a+2;c++)
                    for(int d=b-1;d<b+2;d++)
                        if(c>=0 && c<m_RowCount && d>=0 && d<m_ColCount)
                            if(lei[c][d].shumu == -1)
                                lei[a][b].shumu++;     
            }
    Invalidate();             //更新试图   
}
 
/********************简介函数(+)******************/
void CMy2_1View::OnIntroduction()
{
    // TODO: Add your command handler code here
    CString strOutput;  //生成用于输出的格式化的字符
    strOutput.Format("Welcome to mine clearance game created by ChenTao!");
    MessageBox(strOutput); //弹出提示信息框
}
 
 
/***************自定义开始游戏(+)*******************/
void CMy2_1View::DStrat()
{
    SetTimer(1,50,NULL);
    // TODO: Add your command handler code here
    leftnum = leinum;                 //剩余雷数
    second = 0;                       //计时
    s_start = 0;                      //1时开始计时
    leftnum = leinum;                 //剩余雷数
    over = 0;                       //over = 1时停止
    int aa = 0;
    //初始化0
    for(int i=0;i<m_RowCount;i++)
    {
        for(int j = 0;j<m_ColCount;j++)
        {
            lei[i][j].shumu = 0;
            lei[i][j].weitu = 0;
        }
    }
/*********************设置雷************************/
    do
    {
        int k = rand() % m_RowCount;
        int l = rand() % m_ColCount;
        if(lei[k][l].shumu != -1)
        {
            lei[k][l].shumu = -1;
            aa++;
        }
      
    }while(aa != leinum);  
    /***********************给方格赋值***********************/
    for(int a=0;a<m_RowCount;a++)
        for(int b=0;b<m_ColCount;b++)
            if(lei[a][b].shumu==0)
            {
                for(int c=a-1;c<a+2;c++)
                    for(int d=b-1;d<b+2;d++)
                        if(c>=0 && c<m_RowCount && d>=0 && d<m_ColCount)
                            if(lei[c][d].shumu == -1)
                                lei[a][b].shumu++;     
            }
//  Invalidate();
 
}
 
/***************自定义雷数的函数(+)*********************/
void CMy2_1View::OnEditNum()
{
    // TODO: Add your command handler code here
    SDefine dlg;
    dlg.m_num = 10;
    if(dlg.DoModal() == IDOK)
    {
        leinum = dlg.m_num;
        if(10 <= leinum && leinum <= 20)
        {
            m_RowCount = 10;        //行数   
            m_ColCount = 10;        //列数
        }
        if(20 < leinum && leinum <= 30)
        {
            m_RowCount = 15;        //行数   
            m_ColCount = 12;        //列数
        }
        if(30 < leinum && leinum <= 50)
        {
            m_RowCount = 20;        //行数   
            m_ColCount = 12;        //列数
        }
        if(50 < leinum && leinum <= 80)
        {
            m_RowCount = 24;        //行数   
            m_ColCount = 15;        //列数
        }
        if(80 < leinum && leinum <= 100)
        {
            m_RowCount = 25;        //行数   
            m_ColCount = 16;        //列数
        }
        DStrat();      
        Invalidate();
    }  
}
 
/********选择模式(+)************/
void CMy2_1View::ChooseModel()
{
     AfxMessageBox("确认开始游戏？");
    if(Vchoice == 1)
        OnEasy();
    if(Vchoice == 2)
        OnMiddle();
    if(Vchoice == 3)
        OnDifficult();
}
 
/*************弹出选择模式对话框(+)****************/
void CMy2_1View::OnJumpModel()
{
    // TODO: Add your command handler code here
    CChoose dlg;
    dlg.choice = 1;
    if(dlg.DoModal() == IDOK)
    {
        Vchoice = dlg.choice;
        ChooseModel();
    }
    Invalidate();
}
 
 
/**************背景颜色(+)*******************/
void CMy2_1View::OnLeiBackground()
{
    // TODO: Add your command handler code here
    CLeiBackground dlg;
    dlg.color = 0;
    if(dlg.DoModal()==IDOK)
    {
        flag = dlg.color;  
    }
     
}
