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
int judge_cycle(void), main_cycle(int), main_extract(array<int, 55>), sex(int),group_cycle(void); //定义判断循环，定义主要的循环,定义获得随机数的函数
int class_number = 55;
void output(int), output_fuction_third(vector<int>);                //定义输出姓名的函数
array<int, 55> member = {};
int main()
{
    main_cycle(judge_cycle());  //使用主循环和默认设置
    return 0;
}

int judge_cycle()
{
    int Auto_setting, keep_run = 1, repeat;
    while (keep_run == 1)
    {
        cout << "选择程序运行用途：" << endl << "1、重复抽签" << endl << "2、不重复抽签" << endl << "3、排座位" << endl << endl;
        cin >> Auto_setting;
        cout << endl;
        if (Auto_setting == 1 || Auto_setting == 2 || Auto_setting == 3 || Auto_setting == 4)
        {
            repeat = main_cycle(Auto_setting);
            if (repeat == 0)
                continue;
            break;
        }
        else
        {
            cout << "别TM输入些什么乱七八糟的东西" << endl << endl;
            continue;
        }
    }
    return Auto_setting;
}

int main_cycle(int Auto_setting) //定义默认设置、循环获取抽取人数的次数
{
    int times = 0, random_number, times2 = 0, rise1 = 0, rise2 = 0, judge_continue = 0;
    member.fill(-1);
    while (Auto_setting == 1) //选择循环
    {
        srand((int)time(0));
        member.fill(-1); //初始化member数组，防止出现无限循环 
        rise1 = 0;
        cout << "请输入需要抽出多少个人......(数字介于0和56中间)（如果需要重新选择功能，请输入0）" << endl;
        cin >> times;    //输入循环获取抽取人数的次数
        cout << endl;
        if (times == 0)
            break;
        if (times >= 1 && times <= class_number)  //循环抽取
        {
            for (times = times; times >= 1; times--) //由于输入的次数为1-55，对应循环次数也应当为从一到抽取次数
            {
                member[rise1] = main_extract(member);  //由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                random_number = member[rise1];   //令获得的第n个随机数与数组中第n个数相等
                rise1++;                        //由于递增的数从0开始，必须使它从1开始才能被当为序号，所以放在判断的前面
                if (rise1 >= 1 && rise1 <= 9) //判断数字大小从而达到美观的目的
                    cout << rise1 << ".  "; //多加个空格
                else
                    cout << rise1 << ". ";
                output(random_number);  //输出人名
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
    while (Auto_setting == 2) //选择循环
    {
        srand((int)time(0));
        cout << "请输入需要抽出多少个人......(数字介于0和56中间)（如果需要重新选择功能，请输入0）" << endl;
        cin >> times;    //输入循环获取抽取人数的次数
        cout << endl;
        if (times == 0)
            break;
        if (times >= 1 && times <= class_number)  //循环抽取
        {
            times2 = times + rise2;
            if (times2 >= class_number + 1)  //判断抽取次数于之前抽取总数之和范围小于等于56
            {
                cout << "总抽取人数大于或等于" << class_number + 1 << "人，是否重置抽取池？重置请按1，退出请输入任意字符。" << endl;
                cin >> judge_continue;
                cout << endl;
                if (judge_continue == 1)
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
                member[rise1] = main_extract(member);  //由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                random_number = member[rise1];   //令获得的随机数与数组中第n个数相等
                rise1++;                       //由于递增的数从0开始，必须使它从1开始才能被当为序号，所以放在判断的前面
                if (rise1 >= 1 && rise1 <= 9) //判断数字大小从而达到美观的目的
                    cout << rise1 << ".  "; //多加个空格
                else
                    cout << rise1 << ". ";
                output(random_number);  //输出人名
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
    if (Auto_setting == 3) //选择循环
    {
        group_cycle();
    }
    return times;  //修改功能
}

int group_cycle(void)
{
    srand((int)time(0));
    struct group_struct { int number; int male;; vector<int> sex; }
    group[3] = { {7,4,{-1,-1,-1,-1,-2,-2,-2}},{7,3,{-1,-1,-1,-2,-2,-2,-2}},{6,3,{-1,-1,-1,-2,-2,-2}} };
    vector<int> whole_group;
    int group1 = 0, group2 = 0, member_sex, judge, group_struct, rise1 = 0, times, times2 , rise2;
    const int keep_run = 1;
    do
        group1 = rand() % 8 + 1, group2 = rand() % 8 + 1;  //获得的特殊组的随机数范围为1-8
    while (group1 == group2);  //当两个组的组号相等时，重新获取
    for (times = 1; times <= 8; times++)
    {
        cout << endl << "第" << times << "组" << endl << endl;
        if (times == group2)
            group_struct = 2;
        else if (times == group1)
            group_struct = 1;
        else
            group_struct = 0;
        whole_group.clear();
        whole_group.resize(group[group_struct].number);
        for (times2 = 1; times2 <= group[group_struct].number; times2++)
        {
            while (keep_run == 1)
            {
                judge = 1;
                member[rise1] = main_extract(member);//由于数组的编号从0开始，也就应该令获得的第n个随机数与数组中第n个数相等，因此递增的数（即表示第n次抽取）从0开始
                member_sex = sex(member[rise1] - 1); //获得成员对应的性别(member_sex的范围为-2到-1)
                for (rise2 = 0; rise2 <= group[group_struct].number - 1; rise2++)
                {
                    if (group[group_struct].sex[rise2] == member_sex)
                    {
                        group[group_struct].sex[rise2] = member[rise1] - 1;
                        whole_group[static_cast<std::vector<int, std::allocator<int>>::size_type>(times2) - 1] = member[rise1] - 1;
                        break;
                    }
                    if (rise2 == group[group_struct].number - 1 && group[group_struct].sex[rise2] != member_sex)
                        judge = 0;
                }
                if (judge == 0)
                    continue;
                break;
            }
            rise1++;
        }
        output_fuction_third(whole_group);
        group[0].sex = { -1,-1,-1,-1,-2,-2,-2 };
        cout << endl;
    }
    cout << endl << endl;
    times = 0;
    return 0;
}

int main_extract(array<int, 55> member) //定义获得随机数的函数
{
    int keep_run = 1, random_number, judge, rise1;
    while (keep_run == 1)  //keep_run的用处仅仅是为了令循环的条件能够满足
    {
        judge = 1;  //每次重新获取随机数时重新设置judge的值，防止出现死循环
        random_number = rand() % 55 + 1; //令随机数的范围从0-54 增加到 1-55
        for (rise1 = 0; rise1 <= 55; rise1++) //遍历数组中所有的数字，从而确保一定没有重复值
        {
            if (member[rise1] == random_number)  //判断产生随机数的值是否与之前产生的是否重复
            {
                judge = 0;
                break;
            }
        }
        if (judge == 0)  //如果值相等，重新获取随机数
            continue;
        else
            break;  //退出两个循环，从而令不会重复return 随机数的值
        break;
    }
    return random_number; //返回有随机数的值
}

void output(int random_number)
{
    cout << members[static_cast<std::array<std::string, 55Ui64>::size_type>(random_number) - 1] << endl;
}


void output_fuction_third(vector<int> member)
{
    for (int rise = 0; rise < member.size(); rise++)
    {
        if (rise % 2 == 0)
            cout << members[member[rise]] << " ";
        else
            cout << members[member[rise]] << endl;
    }
}

int sex(int number)
{
    array<int, 55> sex{ -1,-2,-1,-1,-2,-2,-1,-2,-1,-1,-2,-1,-2,-2,-2,-1,-2,-1,-2,-1,-1,-1,-1,-2,-1,-2,-1,-1,-1,-2,-2,-1,-1,-2,-2,-2,-1,-2,-1,-1,-1,-2,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-2,-1,-2 };
    return sex[number];
}