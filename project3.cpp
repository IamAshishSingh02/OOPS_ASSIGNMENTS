#include<bits/stdc++.h>
using namespace std;

class publication
{
    private:
    string title;
    float price;

    public:
    void add()
    {
        cout<<"Enter Publication Details\n";
        cout<<"Enter Title of The Publication: ";
        cin.ignore();
        getline(cin,title);
        cout<<"Enter Price of Publication: Rs";
        cin>>price;
    }

    void disp()
    {
        cout<<"\nTitle of Publication is: "<<title;
        cout<<"\nPrice of Publication: "<<price;
    }
};

class book:public publication
{
    private:
    int pg_cnt;

    public:
    void add_bk()
    {
        add();
        cout<<"Enter Page Count: ";
        cin>>pg_cnt;
        if(pg_cnt<=0)
        {
            throw pg_cnt;
        }
    }

    void disp_bk()
    {
        cout<<"\nPage Count is: "<<pg_cnt<<"\n";
    }
};

class tape:public publication
{
    private:
    float py_time;

    public:
    void add_tp()
    {
        add();
        cout<<"Enter Play Time of The Tape in Minutes: ";
        cin>>py_time;
        if(py_time<=0)
        {
            throw py_time;
        }
    }

    void disp_tp()
    {
        cout<<"\nPlay Time of The Tape is: "<<py_time<<" min"<<"\n";
    }
};

int main()
{
    book b[5];
    tape t[5];
    int cs,b_cnt=0,t_cnt=0;

    while(cs!=5)
    {
        cout<<"\nPUBLICATION DATABASE";
        cout<<"\n\nCASE 1: ADD BOOKS";
        cout<<"\nCASE 2: ADD TAPES";
        cout<<"\nCASE 3: DISPLAY BOOKS";
        cout<<"\nCASE 4: DISPLAY TAPES";
        cout<<"\nCASE 5: EXIT CODE";

        cout<<"\n\nEnter Your Choice: ";
        cin>>cs;
        cout<<"\n";

        switch(cs)
        {
            case 1:
            b[b_cnt].add_bk();
            b_cnt++;
            break;

            case 2:
            t[t_cnt].add_tp();
            t_cnt++;
            break;

            case 3:
            cout<<"BOOK PUBLICATION DATABASE\n";
            for(int i=0;i<b_cnt;i++)
            {
                b[i].disp();
                b[i].disp_bk();
            }
            break;

            case 4:
            cout<<"TAPE PUBLICATION DATABASE\n";
            for(int i=0;i<t_cnt;i++)
            {
                t[i].disp();
                t[i].disp_tp();
            }
            break;

            case 5:
            return 0;
        }
    }
}
