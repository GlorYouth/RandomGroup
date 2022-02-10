#include <iostream>
#include<ctime>
#include <cstdlib>
#include<array>
#include<vector>
using namespace std;
const int ClassNumber = 55, GroupTotal = 8, KeepRunning = 1;
int HiddenSetting = 1;
struct ParameterStruct { int AutoSetting; int Times; int Rise; int TotalTimes; };
int JudgeCycle(void), MainExtract(array<int, ClassNumber>*),
    GetSex(int), DefineMember(vector<int>, int); //定义判断循环，定义主要的循环,定义获得随机数的函数
bool MainCycle(int), InputTimes(ParameterStruct*, array<int, ClassNumber>*), DefineTimes(ParameterStruct*, array<int, ClassNumber>*),
     DefineJudge(int), DefineNumber(int, array<int, ClassNumber>*), Requirement(vector<int>*);
void Output(int, int, array<int, ClassNumber>*), GroupOutput(vector<int>*), GroupCycle(vector<int>*),
     HiddenMode(void), function2(void), function1(int), MemberOutput(int, int);
vector<int> Demo;
int main()
{
    while (MainCycle(JudgeCycle()));
}  //使用主循环和默认设置

int JudgeCycle()
{
    int AutoSetting = 1;
    do 
    {
        cout << "选择程序运行用途：" << endl << "1、重复抽签" << endl << "2、不重复抽签" << endl << "3、排座位" << endl << endl;
        cin >>  AutoSetting;
        cout << endl;
    } while (DefineJudge(AutoSetting));
    return AutoSetting;
}

bool DefineJudge(int AutoSetting)
{
    if (AutoSetting == 1 || AutoSetting == 2 || AutoSetting == 3 || AutoSetting == 114514 )
        return false;
    cout << "别TM输入些什么乱七八糟的东西" << endl << endl;
    return true;
}

bool MainCycle(int AutoSetting) //定义默认设置、循环获取抽取人数的次数
{
    srand(time(nullptr));
    switch (AutoSetting)
    {
    case 1:function1(AutoSetting);
        break;
    case 2:function1(AutoSetting);
        break;
    case 3:function2();
        break;
    default:HiddenMode();
        break;
    }
    return true;  //修改功能
}

void function1(int AutoSetting)
{
    array<int, ClassNumber>* Member = new array<int, ClassNumber>{};
    ParameterStruct* Parameter = new ParameterStruct{ AutoSetting ,0,0,0 };
    while (InputTimes(Parameter, Member))
    {
        for (int times = Parameter->Times; times >= 1; times--) //由于输入的次数为1-55，对应循环次数也应当为从一到抽取次数
        {
            Member->at(Parameter->Rise) = MainExtract(Member);
            //由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
            Parameter->Rise++;                        //令递增的数从0开始
        }
        Parameter->TotalTimes = Parameter->TotalTimes + Parameter->Times;
        Output(Parameter->Times, Parameter->TotalTimes, Member);  //输出人名
        cout << endl;
    }
    delete Parameter,Member;
    Parameter = nullptr, Member = nullptr;
}

bool InputTimes(ParameterStruct* Parameter , array<int, ClassNumber>* Member) //这里使用指针的原因是要修改Parameter的值
{
    do
    {
        cout << "请输入需要抽出多少个人......(数字介于0和56中间)（如果需要重新选择功能，请输入0）" << endl;
        cin >> Parameter->Times;    //输入循环获取抽取人数的次数
        cout << endl;
    } while (DefineTimes(Parameter, Member));
    if (Parameter->AutoSetting == 1) //Parameter本身是一个指针
    {
        Parameter->TotalTimes = 0;
        Parameter->Rise = 0;
        Member->fill(0);
    }
    if (Parameter->Times == 0)
        return false;
    return true;
}

bool DefineTimes(ParameterStruct* Parameter, array<int, ClassNumber>* Member)
{
    if (Parameter->Times >= 0 && Parameter->Times <= ClassNumber)
    {
        if (Parameter->AutoSetting == 2 && Parameter->TotalTimes + Parameter->Times > 55)
        {
            cout << "总抽取人数大于" << ClassNumber << "人，是否重置抽取池？重置请按1，重新选择功能请输入任意字符。" << endl;
            int JudgeContinue;
            cin >> JudgeContinue;
            cout << endl;
            if (JudgeContinue == 1)
            {
                Parameter->TotalTimes = 0;
                Parameter->Rise = 0;
                Member->fill(0);
                return true;
            }
            else
            {
                Member->fill(0);
                Parameter->Times = 0;
                return false;
            }
        }
        return false;
    }
    return true;
}

void Output(int times, int TotalTimes, array<int, ClassNumber>* Member)
{
    vector<int>* OutputVector = new vector<int>(Member->cbegin() + TotalTimes - times, Member->cbegin() + TotalTimes);
    int rise1 = TotalTimes - times + 1;
    for (int InsideMember : *OutputVector)
    {
        if (rise1 >= 1 && rise1 <= 9) //判断数字大小从而达到美观的目的
            cout << rise1 << ".  "; //多加个空格
        else
            cout << rise1 << ". ";
        MemberOutput(InsideMember, 1);
        rise1++;
    }
    delete OutputVector;
    OutputVector = nullptr;
}

void function2()
{
    vector<int>* WholeClass = new vector<int>[GroupTotal];
    //注意WholeClass本身是vector数组的地址，这意味着仅仅这个数组是指针并且这个数组的类型是vector<int>
    do
        GroupCycle(WholeClass);
    while (Requirement(WholeClass));
    GroupOutput(WholeClass);
    Demo = *WholeClass;
    delete [] WholeClass;
    WholeClass = nullptr;
}

void GroupCycle(vector<int>* WholeClass)
{
    vector<int>* Group = new vector<int>[3] { {-1, -1, -1, -1, -2, -2, -2}, {-1,-1,-1,-2,-2,-2,-2}, {-1,-1,-1,-2,-2,-2} };
    array<int, ClassNumber>* Member = new array<int, ClassNumber>{};
    int group1 = 0, group2 = 0, MemberSex = 0, GroupStruct, rise = 0;
    do
        group1 = rand() % 8, group2 = rand() % 8;  //获得的特殊组的随机数范围为0-7
    while (group1 == group2);  //当两个组的组号相等时，重新获取
    for (int times = 0; times < GroupTotal ; times++)
    {
        if (times == group2)  //switch无法使用，因为两者都是变量
            GroupStruct = 2;
        else if (times == group1)
            GroupStruct = 1;
        else
            GroupStruct = 0;
        WholeClass[times].clear();
        WholeClass[times].resize(Group[GroupStruct].size());
        for (int &InsideMember: WholeClass[times]) //"&"的作用是令WholeClass[times]的值可以修改
        {
            do
            {
                Member->at(rise) = MainExtract(Member);//由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                MemberSex = GetSex(Member->at(rise) - 1); //获得成员对应的性别(MemberSex的范围为-2到-1)
            } while (DefineMember(Group[GroupStruct], MemberSex) == -1);
            Group[GroupStruct][DefineMember(Group[GroupStruct], MemberSex)] = Member->at(rise);
            InsideMember = Member->at(rise);
            rise++;
        }
        Group[0] = { -1,-1,-1,-1,-2,-2,-2 }; //重新设置默认组的配置
    }
    delete [] Group;
    delete Member;
    Member = nullptr,Group = nullptr;
}

int DefineMember(vector<int> TheGroup,int MemberSex)
{
    for (int rise1 = 0; rise1 < TheGroup.size(); rise1++)
    {
        if (TheGroup[rise1] == MemberSex)
            return rise1;
        if (rise1 == TheGroup.size() - 1 && TheGroup[rise1] != MemberSex)
            return -1;
    }
    return -2;       //没啥用，仅仅是为了让编译器不警告
}

bool Requirement(vector<int>* WholeClass)
{
    if (HiddenSetting == 0) //如果隐藏设置被关闭，则不经过筛选
        return false;
    if (Demo == *WholeClass)
        return true;
    for (int rise1 = 0; rise1 < GroupTotal; rise1++) 
        //遍历这个数组中所有的vector (因为*WholeClass == WholeClass[0]，所以不能直接for(vector <int> Group : WholeClass) )
    {
        int judge1 = 0, judge2 = 0;
        for (int InsideMember: WholeClass[rise1]) //遍历所有vector里的数字
        {
            if (InsideMember == 36)
                judge1 = 1;
            if (InsideMember == 28)
                judge2 = 1;
        }
        if (judge1 == 1 && judge2 == 1) //两个人在同一个组内
            return true;
    }
    return false; //筛选满足条件的结果
}

int MainExtract(array<int, ClassNumber>* Member) //定义获得随机数的函数
{
    int RandomNumber = -1;
    do
        RandomNumber = rand() % ClassNumber + 1; //随机数的范围1-55
    while (DefineNumber(RandomNumber,Member));
    return RandomNumber; //返回有随机数的值
}

bool DefineNumber(int RandomNumber, array<int, ClassNumber>* Member)
{
    for (int rise = 0;rise < Member->size();rise++) //遍历数组中所有的数字，从而确保一定没有重复值
        if (Member->at(rise) == RandomNumber)  //判断产生随机数的值是否与之前产生的是否重复
            return true;
    return false;
}

void GroupOutput(vector<int>* WholeClass)
{
    for (int rise1 = 0; rise1 < GroupTotal; rise1++)
    {
        int rise2 = 0;
        cout << endl << "第" << rise1 + 1 << "组" << endl << endl;
        for (int InsideMember: WholeClass[rise1])
        {
            MemberOutput(InsideMember, rise2);
            rise2++;
        }
        cout << endl;
    }
    cout << endl << endl;
}

int GetSex(int Number)
{
    const array<int, 55> Sex{ -1,-2,-1,-1,-2,-2,-1,-2,-1,-1,-2,-1,-2,-2,-2,-1,-2,-1,-2,-1,-1,-1,-1,-2,-1,-2,-1,-1,-1,-2,-2,-1,-1,-2,-2,-2,-1,-2,-1,-1,-1,-2,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-2,-1,-2 };
    return Sex[Number];
}

void MemberOutput(int Number ,int Choose)
{
    Number = Number - 1;
    const array<string, 55> Members{ "陈俊东","陈婉林","陈勇佳","丁晨洋","冯飞雯","冯泳钰","关楚睿","关淇允","何隽烨","洪勇坤","黄嘉慧","黄书伟","黄杏婷",
        "黄咏诗","江晓君","劳伟臻","李佳霖","李若霖","李早","梁艺臻","梁宇恒","廖淞竣","林均泽","刘津蕊","刘炫辰","刘阳","陆才耀","陆嘉铭",
        "伦宇杭","罗月霞","欧阳珏尧","潘亚颢","邱国勐","沈慧婕","苏树琪","汤蝶韵","唐鸿杰","汪思莉","韦绍煌","吴东燃","吴烨进","伍绮静",
        "谢浩翔","徐家栋","徐一钦","姚蕾","叶心怡","易雯清","张睿钧","张伟坤","钟培燃","周政轩","朱洁兰","麦艺洋","吴心妍" };
    if (Choose % 2 == 0)
        cout << Members[Number] << " ";
    else
        cout << Members[Number] << endl;
}

void HiddenMode(void)
{
    cout << "您已进入隐藏设置" << endl << "按“0”关闭隐藏设置,按“1”开启隐藏设置" << endl << endl;
    do
    {
        cin >> HiddenSetting;
        cout << endl;
    } while (HiddenSetting != 0 && HiddenSetting != 1);
    cout << endl;
}
