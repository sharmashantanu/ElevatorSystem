#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;

class Elevator
{
    public:
    int status;
    int curpos;
    int nop;
    int source;
    int sourceb;
    int destb;
    int dest;
    int temp;
    float diff;

    Elevator()
    {
        status=curpos=source=dest=sourceb=destb=0;
        temp=-1;
        diff=0;
    }
}L[4];

int main()
{
    int gd=DETECT,gm,i,j,k,src,x,y,p,des,s,d,r,flag,b[100],C[100],N[100],t[100],visit[100];
    float arr[100],min=0,minin=0,ar[100];
    char ch,str1[10];

    initwindow(900,700);

    // GUI

    rectangle(150,30,450,600);
    rectangle(150,600,225,638);
    outtextxy(168,612,"LIFT 1");
    setfillstyle(SOLID_FILL,RED);
    floodfill(200,620,WHITE);
    rectangle(225,600,300,638);
    outtextxy(243,612,"LIFT 2");
    //setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(250,620,WHITE);
    rectangle(300,600,375,638);
    outtextxy(318,612,"LIFT 3");
    //setfillstyle(SOLID_FILL,GREEN);
    floodfill(350,620,WHITE);
    rectangle(375,600,450,638);
    outtextxy(393,612,"LIFT 4");
    //setfillstyle(SOLID_FILL,BLUE);
    floodfill(400,620,WHITE);

    for(i=1;i<=15;i++)
    {
        line(150,30+(570/15)*i,450,30+(570/15)*i);
        sprintf(str1,"%d",15-i);
        outtextxy(70,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,"FLOOR");
        outtextxy(125,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,str1);
        if(i==15)
            outtextxy(30,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,"GROUND FLOOR");

        // UP - DOWN Buttons

        circle(480,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,13);
        outtextxy(475,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-8,"U");
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(490,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,WHITE);
        circle(520,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,13);
        outtextxy(515,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-8,"D");
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(530,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,WHITE);
    }

    //Selecting Floors inside the Lift.

    rectangle(640,300,840,420);
    line(680,300,680,420);
    line(720,300,720,420);
    line(760,300,760,420);
    line(800,300,800,420);
    line(840,300,840,420);
    line(640,340,840,340);
    line(640,380,840,380);
    outtextxy(690,270,"SELECT FLOOR");
    outtextxy(655,313,"G");
    outtextxy(695,313,"1");
    outtextxy(735,313,"2");
    outtextxy(775,313,"3");
    outtextxy(815,313,"4");
    outtextxy(655,353,"5");
    outtextxy(695,353,"6");
    outtextxy(735,353,"7");
    outtextxy(775,353,"8");
    outtextxy(815,353,"9");
    outtextxy(653,393,"10");
    outtextxy(693,393,"11");
    outtextxy(733,393,"12");
    outtextxy(773,393,"13");
    outtextxy(813,393,"14");

    while (!ismouseclick(WM_LBUTTONDOWN))
    {
    }
    getmouseclick(WM_LBUTTONDOWN, x, y);
    for(i=1;i<=15;i++)
    {
        if(x<493 && x>467 && y<((30+(570/15)*i)+(30+(570/15)*(i-1)))/2+13 && y>((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-13)
        {
            s=15-i;
            break;
        }
        if(x<533 && x>507 && y<((30+(570/15)*i)+(30+(570/15)*(i-1)))/2+13 && y>((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-13)
        {
            s=15-i;
            break;
        }
    }
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
    }
    getmouseclick(WM_LBUTTONDOWN, x, y);
    for(i=300;i<420;i+=40)
    {
        for(j=640;j<840;j+=40)
        {
            if(x>j && x<j+40 && y>i && y<i+40)
            {
                d=(j-640)/40+(i-300)/8;
                break;
            }
        }
    }
    cout<<endl<<s<<endl<<d;

    if(d>s)
        flag=1;
    else
        flag=0;
    L[0].source=s;
    L[0].curpos=s;
    L[0].dest=d;
    L[0].status=1;
    L[0].temp=flag;

    while(true)
    {
        //if()
        //Sleep(2000);
        cleardevice();

        rectangle(150,30,450,600);

        for(i=1;i<=15;i++)
        {
            line(150,30+(570/15)*i,450,30+(570/15)*i);
            sprintf(str1,"%d",15-i);
            outtextxy(70,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,"FLOOR");
            outtextxy(125,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,str1);
            if(i==15)
                outtextxy(30,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-5,"GROUND FLOOR");

            // UP - DOWN Buttons

            circle(480,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,13);
            outtextxy(475,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-8,"U");
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(490,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,WHITE);
            circle(520,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2,13);
            outtextxy(515,((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-8,"D");
        }

        circle(650,200,10);
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if(x<660 && x>640 && y<210 && y>190){
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        for(i=1;i<=15;i++)
        {
            if(x<493 && x>467 && y<((30+(570/15)*i)+(30+(570/15)*(i-1)))/2+13 && y>((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-13)
            {
                s=15-i;
                break;
            }
            else if(x<533 && x>507 && y<((30+(570/15)*i)+(30+(570/15)*(i-1)))/2+13 && y>((30+(570/15)*i)+(30+(570/15)*(i-1)))/2-13)
            {
                s=15-i;
                break;
            }
        }

        rectangle(640,300,840,420);
        line(680,300,680,420);
        line(720,300,720,420);
        line(760,300,760,420);
        line(800,300,800,420);
        line(840,300,840,420);
        line(640,340,840,340);
        line(640,380,840,380);
        outtextxy(690,270,"SELECT FLOOR");
        outtextxy(655,313,"G");
        outtextxy(695,313,"1");
        outtextxy(735,313,"2");
        outtextxy(775,313,"3");
        outtextxy(815,313,"4");
        outtextxy(655,353,"5");
        outtextxy(695,353,"6");
        outtextxy(735,353,"7");
        outtextxy(775,353,"8");
        outtextxy(815,353,"9");
        outtextxy(653,393,"10");
        outtextxy(693,393,"11");
        outtextxy(733,393,"12");
        outtextxy(773,393,"13");
        outtextxy(813,393,"14");

        while (!ismouseclick(WM_LBUTTONDOWN))
        {
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        for(i=300;i<420;i+=40)
        {
            for(j=640;j<840;j+=40)
            {
                if(x>j && x<j+40 && y>i && y<i+40)
                {
                    d=(j-640)/40+(i-300)/8;
                    break;
                }
            }
        }

        if(d>s)
            flag=1;
        else
            flag=0;
        for(i=0;i<4;i++)
        {
            if(L[i].dest>L[i].curpos)
            {
                L[i].temp=1;
                L[i].status=1;
            }
            else if(L[i].dest<L[i].curpos)
            {
                L[i].temp=0;
                L[i].status=1;
            }
        }

        int x=0;
        if(s>=L[0].curpos && s<=L[0].dest && flag==L[0].temp)
        {
            if(d>L[0].dest && flag==1||d<L[0].dest && flag==0)
            {
                L[0].dest=d;
                x=1;
            }
        }
        else if(s>=L[1].curpos && s<=L[1].dest && flag==L[1].temp && x==0)
        {
            if(d>L[1].dest && flag==1||d<L[1].dest && flag==0)
            {
                L[1].dest=d;
                x=1;
            }
        }
        else if(s>=L[2].curpos && s<=L[2].dest && flag==L[2].temp && x==0)
        {
            if(d>L[2].dest && flag==1||d<L[2].dest && flag==0)
            {
                L[2].dest=d;
                x=1;
            }
        }
        else if(s>=L[3].curpos && s<=L[3].dest && flag==L[3].temp && x==0)
        {
            if(d>L[3].dest && flag==1||d<L[3].dest && flag==0 )
            {
                L[3].dest=d;
                x=1;
            }
        }
        else if(x==0)
        {
            cout<<"P";
            for(i=0;i<4;i++)
            {
                if(L[i].status==1)
               {
                    if(L[i].temp==0)
                    {
                        if(s<=L[i].dest)
                        {
                            L[i].diff=s-L[i].curpos;
                        }
                        else
                        {
                            L[i].diff=(float) ((L[i].curpos-L[i].dest) + (L[i].dest-s)*1.5);
                        }
                    }
                    else if(L[i].temp==1)
                    {
                        if(s>=L[i].dest)
                        {
                            L[i].diff=(s-L[i].curpos)*1.5;
                        }
                        else
                        {
                            L[i].diff=(float) ((L[i].curpos-L[i].dest)*1.5 + L[i].dest-s);
                        }
                    }
                }
                else if(L[i].status==0)
                {
                    if(s<=L[i].curpos)
                        L[i].diff=s-L[i].curpos;
                    else
                        L[i].diff=(float) ((L[i].curpos-s)*1.5);
                }
            }
            for(i=0;i<4;i++)
            {
                arr[i]=abs(L[i].diff);
                ar[i]=arr[i];
            }
            min=arr[0];
            for(int i=1;i<4;i++)
            {
                if(min>arr[i])
                {
                    min=arr[i];
                    minin=i;
                }
            }
            sort(arr,arr+4);
            for(int i=0;i<4;i++)
            {
                visit[i]=0;
            }
            for(int i=0;i<4;i++)
            {
                for(int j1=0;j1<4;j1++)
                {
                    if(arr[i]==ar[j1] && visit[j1]==0)
                    {
                        visit[j1]=1;
                        t[i]=j1;
                        break;
                    }
                }
            }
            int c=0,j=0;
            for(int i=0;i<4;i++)
            {
                if(min==arr[i])
                {
                    c++;
                    b[j]=i;
                    j++;
                }
            }
            for(int i=0;i<4;i++)
            {
                cout<<arr[i]<<endl;
                cout<<t[i]<<endl;
            }
            int v=0,o=0;
            if(c==1)
            {
                cout<<"q";
                for(i=0;i<4;i++)
                {
                    o=t[i];
                    if(L[o].sourceb==0 && L[o].destb==0)
                    {
                        if(L[o].status==1)
                        {
                            L[o].sourceb=s;
		            		L[o].destb=d;
                        }
                        else if(L[o].status==0)
                        {
                            L[o].source=s;
		            		L[o].dest=d;
		            		L[o].status=1;
		            		L[o].curpos=s;
		            		L[o].temp=flag;
                        }
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<j;i++)
                {
                    int q=b[i];
                    if(L[q].temp==flag && L[q].sourceb==0 && L[q].destb==0)
                    {
                        if(L[q].status==1)
                        {
                            L[q].sourceb=s;
		            		L[q].destb=d;
                        }
                        else if(L[q].status==0)
                        {
                            L[q].source=s;
		            		L[q].dest=d;
		            		L[q].status=1;
		            		L[q].curpos=s;
		            		L[q].temp=flag;
                        }
                        v=1;
                        break;
                    }
                }
                if(v==0)
                {
                    for(int i=0;i<j;i++)
                    {
                        int q=b[i];
                        if( L[q].sourceb==0 && L[q].destb==0)
                        {
                            if(L[q].status==1)
                            {
                                L[q].sourceb=s;
                                L[q].destb=d;
                            }
                            else if(L[q].status==0)
                            {
                                L[q].source=s;
                                L[q].dest=d;
                                L[q].status=1;
                                L[q].curpos=s;
                                L[q].temp=flag;
                            }
                            break;
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++)
        {
            if(L[i].status==1)
            {
                if(L[i].temp==1)
                {
                    if(L[i].curpos<=L[i].dest)
                    {
                        rectangle(150+i*75,600-(L[i].curpos+1)*38,225+i*75,600-(L[i].curpos)*38);
                        //cout<<"Hello";
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(200+i*75,620-(L[i].curpos+1)*38,WHITE);
                        outtextxy(168+i*75,610-(L[i].curpos+1)*38,"LIFT ");
                        L[i].curpos++;
                        cout<<endl<<L[i].curpos<<i<<endl;
                    }
                }
                else if(L[i].temp==0)
                {
                    if(L[i].curpos>=L[i].dest)
                    {
                        rectangle(150+i*75,600-(L[i].curpos+1)*38,225+i*75,600-(L[i].curpos)*38);
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(200+i*75,620-(L[i].curpos+1)*38,WHITE);
                        outtextxy(168+i*75,610-(L[i].curpos+1)*38,"LIFT ");
                        L[i].curpos--;
                        cout<<endl<<L[i].curpos<<i<<endl;
                    }
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            if(L[i].temp==1)
            {
            if(L[i].curpos==L[i].dest+1)
            {
                L[i].status=0;
                L[i].source=L[i].sourceb;
                L[i].dest=L[i].destb;
                L[i].curpos=L[i].sourceb;
                L[i].temp=-1;
                L[i].sourceb=0;
                L[i].destb=0;
            }
            }
            else if(L[i].temp==0)
            {
                if(L[i].curpos==L[i].dest-1)
                {
                L[i].status=0;
                L[i].source=L[i].sourceb;
                L[i].dest=L[i].destb;
                L[i].curpos=L[i].sourceb;
                L[i].temp=-1;
                L[i].sourceb=0;
                L[i].destb=0;
                }

            }
    }
        }
    else
    {
        for(i=0;i<4;i++)
        {
            if(L[i].status==1)
            {
                if(L[i].temp==1)
                {
                    if(L[i].curpos<=L[i].dest)
                    {
                        rectangle(150+i*75,600-(L[i].curpos+1)*38,225+i*75,600-(L[i].curpos)*38);
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(200+i*75,620-(L[i].curpos+1)*38,WHITE);
                        outtextxy(168+i*75,610-(L[i].curpos+1)*38,"LIFT ");
                        L[i].curpos++;
                        cout<<endl<<L[i].curpos<<i<<endl;
                    }
                }
                else if(L[i].temp==0)
                {
                    if(L[i].curpos>=L[i].dest)
                    {
                        rectangle(150+i*75,600-(L[i].curpos+1)*38,225+i*75,600-(L[i].curpos)*38);
                        setfillstyle(SOLID_FILL,RED);
                        floodfill(200+i*75,620-(L[i].curpos+1)*38,WHITE);
                        outtextxy(168+i*75,610-(L[i].curpos+1)*38,"LIFT ");
                        L[i].curpos--;
                        cout<<endl<<L[i].curpos<<endl;
                    }
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            if(L[i].temp==1)
            {
            if(L[i].curpos==L[i].dest+1)
            {
                L[i].status=0;
                L[i].source=L[i].sourceb;
                L[i].dest=L[i].destb;
                L[i].curpos=L[i].sourceb;
                L[i].temp=-1;
                L[i].sourceb=0;
                L[i].destb=0;
            }
            }
            else if(L[i].temp==0)
            {
                if(L[i].curpos==L[i].dest-1)
                {
                L[i].status=0;
                L[i].source=L[i].sourceb;
                L[i].dest=L[i].destb;
                L[i].curpos=L[i].sourceb;
                L[i].temp=-1;
                L[i].sourceb=0;
                L[i].destb=0;
            }
            }
        }
    }
    Sleep(2000);
    }

    getch();
    closegraph();
    return 0;
}
