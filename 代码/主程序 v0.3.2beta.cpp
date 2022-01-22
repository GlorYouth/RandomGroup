#include <iostream>
#include<ctime>
#include <cstdlib>
#include<array>
#include<vector>
using namespace std;
const array<string, 55> members{ "陈俊东","陈婉林","陈勇佳","丁晨洋","冯飞雯","冯泳钰","关楚睿","关淇允","何隽烨","洪勇坤","黄嘉慧","黄书伟","黄杏婷",
        "黄咏诗","江晓君","劳伟臻","李佳霖","李若霖","李早","梁艺臻","梁宇恒","廖淞竣","林均泽","刘津蕊","刘炫辰","刘阳","陆才耀","陆嘉铭",
        "伦宇杭","罗月霞","欧阳珏尧","潘亚颢","邱国勐","沈慧婕","苏树琪","汤蝶韵","唐鸿杰","汪思莉","韦绍煌","吴东燃","吴烨进","伍绮静",
        "谢浩翔","徐家栋","徐一钦","姚蕾","叶心怡","易雯清","张睿钧","张伟坤","钟培燃","周政轩","朱洁兰","麦艺洋","吴心妍" };
struct ClassStruct { vector<int> group; } AllGroup[8] = {};
struct GroupStruct { int number; vector<int> sex; };
int JudgeCycle(void),DefineJudge(int), MainCycle(int), MainExtract(array<int, 55>),
    GetSex(int), Requirement(void),DefineNumber(int), DefineMember(GroupStruct, int); //定义判断循环，定义主要的循环,定义获得随机数的函数
const int ClassNumber = 55, GroupTotal = 8;
int HiddenSetting = 0;
void output(int,int), GroupOutput(void), GroupCycle(void), HiddenMode(void);                //定义输出姓名的函数
array<int, ClassNumber> member = {};
int main()
{
    while (MainCycle(JudgeCycle()) == 0);  //使用主循环和默认设置
    return 0;
}

int JudgeCycle()
{
    int AutoSetting = 0, KeepRunning = 1;
    do 
    {
        cout << "选择程序运行用途：" << endl << "1、重复抽签" << endl << "2、不重复抽签" << endl << "3、排座位" << endl << endl;
        cin >> AutoSetting;
        cout << endl;
    } while (DefineJudge(AutoSetting) == 0);
    return AutoSetting;
}

int DefineJudge(int AutoSetting)
{
    if (AutoSetting == 1 || AutoSetting == 2 || AutoSetting == 3 || AutoSetting == 114514)
        return 1;
    cout << "别TM输入些什么乱七八糟的东西" << endl << endl;
    return 0;
}

int MainCycle(int AutoSetting) //定义默认设置、循环获取抽取人数的次数
{
    int times = 0, RandomNumber, times2 = 0, rise1 = 0, rise2 = 0, JudgeContinue = 0;
    member.fill(-1);
    while (AutoSetting == 1) //选择循环
    {
        srand((int)time(0));
        member.fill(-1); //初始化member数组，防止出现无限循环 
        rise1 = 0;
        cout << "请输入需要抽出多少个人......(数字介于0和56中间)（如果需要重新选择功能，请输入0）" << endl;
        cin >> times;    //输入循环获取抽取人数的次数
        cout << endl;
        if (times == 0)
            break;
        if (times >= 1 && times <= ClassNumber)  //循环抽取
        {
            for (times = times; times >= 1; times--) //由于输入的次数为1-55，对应循环次数也应当为从一到抽取次数
            {
                member[rise1] = MainExtract(member);  //由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                RandomNumber = member[rise1];   //令获得的第n个随机数与数组中第n个数相等
                rise1++;                        //由于递增的数从0开始，必须使它从1开始才能被当为序号，所以放在判断的前面
                output(RandomNumber,rise1);  //输出人名
            }
        }
        else
        {
            cout << "别TM输入些什么乱七八糟的东西" << endl << endl;
            continue;  //如果输入错误，重新循环程序
        }
        cout << endl;
        continue;  //自动重复运行程序以达到方便的目的
    }
    while (AutoSetting == 2) //选择循环
    {
        srand((int)time(0));
        cout << "请输入需要抽出多少个人......(数字介于0和56中间)（如果需要重新选择功能，请输入0）" << endl;
        cin >> times;    //输入循环获取抽取人数的次数
        cout << endl;
        if (times == 0)
            break;
        if (times >= 1 && times <= ClassNumber)  //循环抽取
        {
            times2 = times + rise2;
            if (times2 >= ClassNumber + 1)  //判断抽取次数于之前抽取总数之和范围小于等于56
            {
                cout << "总抽取人数大于或等于" << ClassNumber + 1 << "人，是否重置抽取池？重置请按1，退出请输入任意字符。" << endl;
                cin >> JudgeContinue;
                cout << endl;
                if (JudgeContinue == 1)
                {
                    times2 = 0, rise2 = 0;
                    member.fill(-1); //初始化member数组，防止出现无限循环 
                    rise1 = 0;
                    continue;
                }
                else
                    break;
            }
            for (times = times; times >= 1; times--) //由于输入的次数为1-55，对应循环次数也应当为从一到抽取次数
            {
                member[rise1] = MainExtract(member);  //由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                RandomNumber = member[rise1];   //令获得的随机数与数组中第n个数相等
                rise1++;                       //由于递增的数从0开始，必须使它从1开始才能被当为序号，所以放在判断的前面
                output(RandomNumber,rise1);  //输出人名
            }
        }
        else
        {
            cout << "别TM输入些什么乱七八糟的东西" << endl << endl;
            continue;  //如果输入错误，重新循环程序
        }
        cout << endl;
        rise2 = rise1 + 1; //由于increasing_number的范围为0-54，必须要+1才能令之后的判断成立
        continue;  //自动重复运行程序以达到方便的目的
    }
    if (AutoSetting == 3) //选择循环
    {
        do
            GroupCycle();
        while (Requirement() == 1);
        GroupOutput();
        ClassStruct AllGroup[8] = {};
    }
    if (AutoSetting == 114514)
        HiddenMode();
    return times;  //修改功能
}

void GroupCycle(void)
{
    srand((int)time(0));
    GroupStruct group[3] { {7,{-1,-1,-1,-1,-2,-2,-2}},{7,{-1,-1,-1,-2,-2,-2,-2}},{6,{-1,-1,-1,-2,-2,-2}} };
    vector<int> WholeGroup;
    member.fill(-1); //初始化member数组，防止出现无限循环 
    int group1 = 0, group2 = 0, MemberSex = 0, GroupStruct, rise1 = 0, times, times2;
    const int KeepRunning = 1;
    do
        group1 = rand() % 8, group2 = rand() % 8;  //获得的特殊组的随机数范围为0-7
    while (group1 == group2);  //当两个组的组号相等时，重新获取
    for (times = 0; times < GroupTotal ; times++)
    {
        if (times == group2)
            GroupStruct = 2;
        else if (times == group1)
            GroupStruct = 1;
        else
            GroupStruct = 0;
        WholeGroup.clear();
        WholeGroup.resize(group[GroupStruct].number);
        for (times2 = 0; times2 < group[GroupStruct].number; times2++)
        {
            do
            {
                member[rise1] = MainExtract(member);//由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                MemberSex = GetSex(member[rise1]); //获得成员对应的性别(MemberSex的范围为-2到-1)
            } while (DefineMember(group[GroupStruct], MemberSex) == -1);
            group[GroupStruct].sex[DefineMember(group[GroupStruct], MemberSex)] = member[rise1];
            WholeGroup[times2] = member[rise1];
            rise1++;
        }
        AllGroup[times].group = WholeGroup;
        group[0].sex = { -1,-1,-1,-1,-2,-2,-2 };
    }
}

int DefineMember(GroupStruct TheGroup,int MemberSex)
{
    for (int rise1 = 0; rise1 < TheGroup.number; rise1++)
    {
        if (TheGroup.sex[rise1] == MemberSex)
            return rise1;
        if (rise1 == TheGroup.number - 1 && TheGroup.sex[rise1] != MemberSex)
            return -1;
    }
    return -2;
}

int Requirement(void)
{
    if (HiddenSetting == 0) //如果隐藏设置被关闭，则不经过筛选
        return 0;
    for (int rise1 = 0,judge1, judge2; rise1 < GroupTotal; rise1++)
    {
        judge1 = 0, judge2 = 0;
        for (int rise2 = 0; rise2 < AllGroup[rise2].group.size(); rise2++)
        {
            if (AllGroup[rise1].group[rise2] == 36)
                judge1 = 1;
            if (AllGroup[rise1].group[rise2] == 28)
                judge2 = 1;
        }
        if (judge1 == 1 && judge2 == 1) //两个人在同一个组内
            return 1;
    }
    return 0; //筛选满足条件的结果
}

int MainExtract(array<int, ClassNumber> member) //定义获得随机数的函数
{
    int KeepRunning = 1, RandomNumber = -1;
    do
        RandomNumber = rand() % ClassNumber; //随机数的范围0-54
    while (DefineNumber(RandomNumber) == 1);
    return RandomNumber; //返回有随机数的值
}

int DefineNumber(int RandomNumber)
{
    for (int rise1 = 0; rise1 < ClassNumber; rise1++) //遍历数组中所有的数字，从而确保一定没有重复值
        if (member[rise1] == RandomNumber)  //判断产生随机数的值是否与之前产生的是否重复
            return 1;
    return 0;
}

void output(int RandomNumber,int rise)
{
    if (rise >= 1 && rise <= 9) //判断数字大小从而达到美观的目的
        cout << rise << ".  "; //多加个空格
    else
        cout << rise << ". ";
    cout << members[RandomNumber] << endl;
}

void GroupOutput(void)
{
    for (int rise1 = 0; rise1 < GroupTotal; rise1++)
    {
        cout << endl << "第" << rise1 + 1 << "组" << endl << endl;
        for (int rise2 = 0; rise2 < AllGroup[rise1].group.size(); rise2++)
        {
            if (rise2 % 2 == 0)
                cout << members[AllGroup[rise1].group[rise2]] << " ";
            else
                cout << members[AllGroup[rise1].group[rise2]] << endl;
        }
        cout << endl;
    }
    cout << endl << endl;
}

int GetSex(int number)
{
    array<int, 55> sex{ -1,-2,-1,-1,-2,-2,-1,-2,-1,-1,-2,-1,-2,-2,-2,-1,-2,-1,-2,-1,-1,-1,-1,-2,-1,-2,-1,-1,-1,-2,-2,-1,-1,-2,-2,-2,-1,-2,-1,-1,-1,-2,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-2,-1,-2 };
    return sex[number];
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