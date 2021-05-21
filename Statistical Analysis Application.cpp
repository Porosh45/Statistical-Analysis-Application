#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void display_print()
{
    printf("                                             Enter The desired button to continue\n");
    printf(" 1. Arithmetic Mean            2. Harmonic Mean             3. Geometric Mean      \n");
    printf(" 4. Median                        5. Mode      \n");
    printf(" 6. Mean Deviation(Mean)    7. Mean Deviation(Mode)    8. Mean Deviation(Median)      \n");
    printf(" 9. Variance                     10. Standard Deviation  \n");
    printf(" 0. Exit \n");
}
void welcome()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    setfillstyle(XHATCH_FILL, RED);
    outtextxy(150,10,"Welcome");
    outtextxy(220,50,"To");
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    setfillstyle(XHATCH_FILL, BLUE);
    outtextxy(10,100,"Statistics Analysis Application");
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(20,200,"Press any key to Continue");
    getch();
    closegraph();
}
void graph_output(float res, string s)
{
//    system("CLS");
//    cout<<"The value of "<<s<<" is "<<res<<endl;
//    system("PAUSE");
//    system("CLS");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    char arr[100] ;
    cout<<s<<endl;
    for(int i = 0; i<s.size(); i++)
        arr[i] = s[i];
    for(int i = 0; i<s.size(); i++)
        cout<<arr[i];
    arr[s.size()]='\0';
    outtextxy(100,10,arr);
    sprintf(arr," %f ",res);
    outtextxy(130,40,arr);

    getch();
    //closegraph();

}
void graph_set(int a,float x, float y, float z)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    if(a==1)
        outtextxy(275,0,"Mean Median Mode");
    if(a==2)
        outtextxy(275,0,"Mean Deviation ");
    if(a==3)
        outtextxy(275,0,"Mean Comparison ");
    setlinestyle(SOLID_LINE,0,2);
    /* Draw X and Y Axis */
    line(90,410,90,50);
    line(90,410,590,410);
    line(85,60,90,50);
    line(95,60,90,50);
    line(585,405,590,410);
    line(585,415,590,410);

    outtextxy(65,60,"Y");
    outtextxy(570,420,"X");
    outtextxy(70,415,"O");
    /* Draw bars on screen */
    setfillstyle(XHATCH_FILL, RED);

    bar(150,410 - (x*10),200,410);
    setfillstyle(XHATCH_FILL, BLUE);
    bar(250,410 - (y*10),300,410);
    setfillstyle(XHATCH_FILL, GREEN);
    bar(350,410 -(z*10),400,410);
//   bar(375,170,425,410);
//   bar(450,135,500,410);

//  getch();
    system("PAUSE");
    //closegraph();
}
class cal
{
public :
    float Me,Mo,Med;
    float Mem,Mom,Medm;
    float AMe,GMe,HMe;
    float st_dev,var;
};
int Mode(int a[],int n)
{
    int x=0,res = 0;
    map<int, int >mp;
    for(int i = 0; i<n; i++)
    {
        mp[a[i]]++;
    }
    if(mp.size()==n)
        return 0;
    else
    {
        map<int, int > :: iterator it = mp.begin();
        for(; it!=mp.end(); it++)
        {
            if(x<it->second)
            {
                x=it->second;
                res = it->first;
            }
        }
        return res;
    }
}
double geo_mean(int a[],int n)
{
    double x=1;
    for(int i = 0; i<n; i++)
        x=x*a[i];
    return pow(x,(double)(1.0/n));
}
float median(int a[],int n)
{
    if(n%2)
        return (a[(n+1)/2]);
    else
        return (float)((a[n/2]+a[(n+1)/2])/2);
}
float har_mean(int a[],int n)
{
    float x=0;
    for(int i = 0; i<n; i++)
        x+=(1.0/a[i]);
    return ( ((float)n/x));
}
float Mean_deviation(int a[], float Me, int n)
{
    int x = 0;
    for(int i = 0; i<n; i++)
    {
        x += abs(Me - a[i]);
    }
    return (float)(x/n);
}
float variance(int a[],float Me,int n)
{
    float x = 0;
    for(int i = 0; i<n; i++)
    {
        float b = abs(Me - a[i]);
        x+=b*b;
    }
    return (float)(x/n);
}
cal name;
int graph_display_command()
{
    char c;

    printf("                                    Do you want to check Graphical Comparison\n");
    printf("                        If 'YES' Press 'Y' or Press 'N' \n");
    cin>>c;
    if(c=='Y' || c =='y')
    {
        int x;
        printf("                Graph of Mean Median and Mode Press 1\n");
        printf("    Graph of Mean Deviation from Mean Median and Mode Press 2\n");
        printf("Graph of Arithmetic Mean Geometric Mean and Harmonic Mean Press 3\n");
        printf("                                   To Exit Press 0\n");
        cin>>x;
        return x;
    }
    else
        return 0;
}
int display_input()
{
    int n;
    printf("Enter the total number of data set: ");
    scanf("%d",&n);
    printf("Enter the values of data set :");
    return n;
}
vector<string>file_name;
bool file_find(string s)
{
    for(int i = 0;i<file_name.size();i++)
    {
        if(file_name[i]==s)
            return true;
    }
return false;
}
int check = -1;
string s;
void file_display()
{
    printf("1. Open a Existing file\n");
    printf("2. Create a new file\n");
    printf("Enter your choice\n");
    int n;
    scanf("%d",&n);
    system("CLS");
    ifstream fin("files");
    int c = 0;


    //system("PAUSE");
    string a;
    while(fin>>a)
    {
        file_name.push_back(a);
    }
    cout<<"Name of the files "<<endl<<endl;
    for(int i = 0;i<file_name.size();i++)
        cout<<i+1<<". "<<file_name[i]<<endl;
    cout<<endl;
    printf("Enter the name of the file: ");
    cin>>s;
    cout<<endl;
    if(n==1)
    {
        if(file_find(s))
            {
               check = 0;
            }
        else
            {
                printf("There is no such file\n");
                check = 1;
            }
    }
    else
        check = 1;

    if(check!=0)
    {
     printf("Creating a new file\n");
     file_name.push_back(s);
    }
    ofstream fout("files");
     //cout<<"Desired Email after file calling "<<s<<endl;
    for(int i = 0;i<file_name.size();i++)
        fout<<file_name[i]<<" ";
    //cout<<"Desired Email "<<s<<endl;
     system("PAUSE");
 //   return s;
    //system("PAUSE");
}
int welcome_check = 0;
int main()
{

    if(welcome_check ==0)
    {
        welcome();
        welcome_check = 1;
    }
    int c = 0;
    while(1)
    {
        if(c==0)
        {
            c=1;
            system("CLS");
            file_display();
            cout<<s<<endl;
            system("CLS");
            int n;
            int f[100000];
            long long sum = 0;
            if(check==0)
            {
            ifstream Fin(s);
            int k;
            Fin>>k;
            if(k == 1)
            {
            Fin>>n;
            cout<<"The Total Number of Elements "<<n<<endl;
            cout<<"The Data Values are ";
            for(int i = 0; i<n; i++)
            {
             //   scanf("%d",&f[i]);
                Fin>>f[i];
                sum +=f[i];
                printf("%d ",f[i]);
            }
            check = -1;
            cout<<endl;
            system("PAUSE");
            }
            else
                check=1;
            }
            if(check == 1)
            {
            ofstream Fout(s);
            cout<<"file input "<<endl;
            n = display_input();
            Fout<<1<<endl;
            Fout<<n<<endl;
            for(int i = 0; i<n; i++)
            {
                scanf("%d",&f[i]);
                Fout<<f[i]<<endl;
                sum +=f[i];
            }
            }
            sort(f,f+n);
            name.AMe = ((float)(sum)/n);
            //  cout<<"After calculation 1"<<endl;
            name.Mo = Mode(f,n);
            //cout<<"After calculation 2"<<endl;
            name.Med = median(f,n);
            //cout<<"After calculation 3"<<endl;
            name.GMe = geo_mean(f,n);
            //cout<<"After calculation 4"<<endl;
            name.HMe = har_mean(f,n);
            //cout<<"After calculation 5"<<endl;
            name.Mem = Mean_deviation(f,name.AMe,n);
            //cout<<"After calculation 6"<<endl;
            name.Mom = Mean_deviation(f,name.Mo,n);
            //cout<<"After calculation 7"<<endl;
            name.Medm = Mean_deviation(f,name.Med,n);
            //cout<<"After calculation 8"<<endl;
            name.var = variance(f,name.AMe,n);
            //cout<<"After calculation 9"<<endl;
            name.st_dev = sqrt(name.var);
            //cout<<"After calculation 10"<<endl;
        }
        system("CLS");
        int x;
        display_print();
        scanf("%d",&x);
        system("PAUSE");
        if(x==0)
            break;
        else
        {
            switch(x)
            {
            case 1:
                graph_output(name.AMe,"Arithmetic Mean");
                break;
            case 2:
                graph_output(name.HMe,"Harmonic Mean");
                break;
            case 3:
                graph_output(name.GMe,"Geometric Mean");
                break;
            case 4:
                graph_output(name.Med,"Median");
            case 5:
                graph_output(name.Mo,"Mode");
                break;
            case 6:
                graph_output(name.Mem,"Mean Deviation(Mean)");
                break;
            case 7:
                graph_output(name.Mom,"Mean Deviation(Mode)");
                break;
            case 8:
                graph_output(name.Medm,"Mean Deviation(Median)");
                break;
            case 9:
                graph_output(name.var,"Variance");
                break;
            case 10:
                graph_output(name.st_dev,"Standard Deviation");
                break;
            default:
                printf("You have enter the wrong number ");
                break;
            }
        }
        system("CLS");
    }
    while(1)
    {
        system("CLS");
        int a = graph_display_command();
        if(a==1)
            graph_set(a,name.AMe,name.Med,name.Mo);
        else if(a==3)
            graph_set(a,name.AMe,name.GMe,name.HMe);
        else if(a==2)
            graph_set(a,name.Mem,name.Mom,name.Medm);
        else
            break;
    }
    system("CLS");
    int x;
    cout<<"              Do wish to continue?"<<endl<<endl;
    cout<<"              Press 1 to continue"<<endl;
    cout<<"              Press 0 to exit "<<endl;
    cout<<"              Enter your choice: ";
    cin>>x;
    if(x)
        main();

    return 0;
}
//Porosh's Statistics Analysis software code
