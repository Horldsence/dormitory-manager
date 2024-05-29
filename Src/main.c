#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int sign = 0;// 区分用户标识符， 1： 系统管理员，  2：普通用户
char ACCOUNT[N]; // 用于保存普通用户登录后的账号
//定义住宿信息链表的头指针为全局变量。
p_node_dormitory headDormitory;
//定义 3 个指针数组，分别按照关键字学号、姓名和宿舍号顺序存储住宿信息的结点地址。
dormitory *arrayDormID[MAX_SIZE], *arrayStudentID[MAX_SIZE], *arrayName[MAX_SIZE];
int countRecord;

int main(void)
{
    int n;
    USER user[M]; //定义结构体数组保存用户信息
    Register_system(); // 登录注册功能  系统管理员登录后sign = 1， 普通用户登录后 sign = 2，
    Load(user, &n); // 把用户信息加载到内存中
    readFile("userInfoList.txt"); //
    if(sign == 1) // 进入系统管理员菜单
    {
        int select;
        FILE *fp;
        while(1)
        {
            Menu_admist();
            printf("请输入菜单选项：\n");
            scanf("%d", &select);
            switch(select)
            {
                case 1: // 批量创建用户
                    creatAccount(user, &n);break;
                case 2: // 批量删除用户
                    removeAccount(user, &n);break;
                case 3: //修改账号密码
                    editAccount(user, &n);break;
                case 4: //重置账号密码
                    PrAllAccount(user, &n);break;
                case 5://显示全部住宿信息 排序
                    view(); break;
                case 6://添加一条住宿信息 查 增
                    add(); break;
                case 7://修改一条住宿信息
                    edit(); break;
                case 8://删除一条住宿信息
                    delete(); break;
                case 9://根据姓名查找
                    find(1); break;
                case 10://根据学号查找
                    find(2); break;
                case 11://根据住宿号查找
                    find(3); break;
                case 0:
                    printf("成功退出系统，期待你的下次使用O(∩_ ∩)O, 祝你生活愉快！\n");
                    writeDataToFile("studentData.txt");
                    exit(0);
                default:
                    printf("\n输入错误！无该菜单，输入任意键返回 *系统管理员功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    break;
            }
        }

    }
    if(sign == 2) // 进入系统普通用户菜单
    {
        int select;
        FILE *fp;
        while(1)
        {
            Menu_user();
            printf("请输入菜单选项：\n");
            scanf("%d", &select);
            switch(select)
            {
                case 1:
                    editAccount(user, &n); //修改账号密码
                    break;
                case 2:
                    find(1); break;
                case 3:
                    find(2); break;
                case 4:
                    find(3); break;
                case 0:
                    printf("成功退出系统，期待你的下次使用O(∩_ ∩)O, 祝你生活愉快！\n");
                    writeDataToFile("studentData.txt");
                    exit(0);
                default:
                    printf("\n输入错误！无该菜单，输入任意键返回 *系统普通用户功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    break;
            }
        }
    }
}

//用户登录注册菜单函数
void Register_system()
{
    int select;
    Menu1();
    scanf("%d", &select);
    switch(select)
    {
    case 0:  //退出系统
        printf("\n成功退出系统！期待你的下次使用O(∩_ ∩)O ，祝你生活愉快！\n");
        exit(0);
    case 1: //登录账户
        User_enter();
        return;
    case 2://注册账号
        User_reg();
        return;
    default: //重新输入选项
        printf("\n输入错误，输入任意键返回 *系统用户登录注册界面* ...\n");
        scanf("%*c%*c");
        system("clear");
        Register_system();
        return;
    }
}

//系统用户登录注册界面
void Menu1()
{
    system("clear");
    printf("===============================================\n");
    printf("                                            \n");
    printf("            欢 迎 使 用 宿 舍 系 统             \n");
    printf("      该界面为：*系统用户登录注册界面*            \n");
    printf("     1: 登录  2：新用户注册  0: 退出系统         \n");
    printf("                                             \n");
    printf("===============================================\n");
    printf("请输入菜单项：\n");
}

//系统用户登录函数
void User_enter()
{
    int select;
    char Accont[N], Password[N];
    char Accont1[N], Password1[N], ID1[N], People_name1[N];
    FILE *fp;
    if((fp = fopen("userInfoList.txt", "a")) == NULL) //创建 userinfo.dat 文本文件
    {
        printf("can not open this file\n");
        exit(0);
    }
    fclose(fp);
    Menu3(); // 系统用户登录界面
    scanf("%d", &select);
    switch(select)
    {
        case 1: //登录账号密码
            if((fp = fopen("userinfo.dat", "r")) == NULL)
            {
                printf("can not open this file\n");
                exit(0);
            }
            printf("请输入账号：\n");
            scanf("%s", Accont);
            printf("请输入密码：\n");
            scanf("%s", Password);
            while(!feof(fp))
            {
                fscanf(fp, "%s %s", Accont1, Password1, ID1,  People_name1);
                if(strcmp(Accont, "123456") == 0 && strcmp(Password, "000000") == 0 )  // 图书管理系统管理员账户及密码识别
                {
                    sign = 1;   //系统管理员标识符
                    fclose(fp);
                    printf("账号登录成功！！尊敬的管理员欢迎你使用\n - 黑 大 宿 舍 管 理 员 处 理 系 统 - \n");
                    printf("\n输入任意键前往 *系统管理员功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    return;
                }
                if(strcmp(Accont, Accont1) == 0 && strcmp(Password, Password1) == 0)  // 图书管理系统普通用户账号及密码识别
                {
                    strcpy(ACCOUNT, Accont);
                    sign = 2;  //普通用户标识符
                    fclose(fp);
                    printf("账号登录成功！！尊敬的用户欢迎你使用 - 黑 大 宿 舍 管 理 员 处 理 系 统 -\n");
                    printf("\n输入任意键前往 *系统用户功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    return;
                }
            }
            if(sign == 0)
            {
                printf("账号密码错误！！ 请重新输入......\n");
                printf("如若忘记账号密码可携带本人身份证到寝室一楼值班室找回账号密码。\n");
                printf("\n输入任意键返回 *系统用户登录界面* ...\n");
                scanf("%*c%*c");
                User_enter();
                return;
            }
        case 2: //返回上界面
            printf("\n输入任意键返回 *系统用户登录注册界面* ...\n");
            scanf("%*c%*c");
            system("clear");
            Register_system();
            return ;
        case 0: //退出系统
            printf("\n成功退出系统！\n");
            exit(0);
        default: //重新输入
            printf("\n输入错误！无该菜单，输入任意键返回 *系统用户登录界面* ...\n");
            scanf("%*c%*c");
            User_enter();
            return;
    }
}

//新用户注册函数
void User_reg()
{
    int select;
    char Accont[N], Password1[N], Password2[N], ID[N], People_name[N];
    FILE *fp;
    Menu2(); // 新用户注册功能菜单
    if((fp = fopen("userinfo.dat", "a")) == NULL) //创建 userinfo.dat 文本文件
    {
        printf("can not open this file\n");
        exit(0);
    }
    fclose(fp);
    scanf("%d", &select);
    switch(select)
    {
        case 1:	    // 注册账号密码 ， 并检验注册账号是否符合规定，是否被注册 。
            while(1)
            {
                FILE *fp;
                int i;
                char Accont1[N], password1[N], ID[N], People_name[N];
                int sign1 = 0; // 检查账号是否为数字账号，0：是  1：否
                system("clear");
                Menu2();
                printf("1\n");
                printf("请输入注册账号（九位数数字）:\n");
                scanf("%s", Accont);
                if((fp = fopen("userinfo.dat", "r")) == NULL)
                {
                    printf("can not open this file\n");
                    exit(0);
                }
                for(i = 0; Accont[i] != '\0'; i++) // 检查是否为九位账号
                {
                    if(isdigit(Accont[i]) == 0)  // 检查账号是否为数字账号
                    {
                        sign1 = 1; break;
                    }
                }
                if(i >= 10 || sign1 == 1 || i < 9)
                {
                    sign1 = 1;
                    printf("未按要求注册账号，请重新注册！ \n");
                    printf("\n输入任意键返回 *系统用户注册界面* ...\n");
                    scanf("%*c%*c");
                    User_reg();
                    return;
                }
                while(!feof(fp)) // 检查账号是否被注册
                {
                    fscanf(fp, "%s %s %s %s", Accont1, password1, ID,  People_name);
                    if(strcmp(Accont, Accont1) == 0)
                    {
                        fclose(fp);
                        printf("该账号已被注册，请重新注册!\n");
                        printf("\n输入任意键返回 *系统用户注册界面* ...\n");
                        scanf("%*c%*c");
                        sign1 = 1;
                        User_reg();
                        return;
                    }
                }
                if(i == 9 && sign1 == 0)
                {
                    printf("注册账号符合要求。");
                    break;
                }

            }
            if((fp = fopen("userinfo.dat", "a")) == NULL)
            {
                printf("can not open this file\n");
                exit(0);
            }
            printf("请输入你的身份证号:\n");
            scanf("%s", ID);
            printf("请输入你的姓名：\n");
            scanf("%s", People_name);
            printf("请输入账号密码：\n");
            scanf("%s", Password1);
            printf("请再次输入密码：\n");
            scanf("%s", Password2);
            if(strcmp(Password1, Password2) == 0)
            {
                fprintf(fp, "\n%s  %s  %s  %s\n", Accont, Password1, ID, People_name);
                fclose(fp);
                printf("****新用户创建成功 qwq **** \n");
                printf("\n输入任意键返回 *系统用户登录注册界面* ...\n");
                scanf("%*c%*c");
                system("clear");
                Register_system();
                return;
            }else
            {
                printf("\n****两次输入密码不一致!!!! 请重新注册****\n");
                printf("\n输入任意键返回 *系统用户注册界面* ...\n");
                scanf("%*c%*c");
                User_reg();
                return;
            }
        case 2: //返回上一界面
            printf("\n输入任意键返回 *系统用户登录注册界面* ...\n");
            scanf("%*c%*c");
            system("clear");
            Register_system();
            return;
        case 0:  //退出系统
            printf("\n成功退出系统！期待你的下次使用QAQ，祝你生活愉快！\n");
            exit(0);
        default:  //重新输入
            printf("\n输入错误，无该菜单，输入任意键返回 *系统用户注册界面* ...\n");
            scanf("%*c%*c");
            system("clear");
            User_reg();
            return;
    }
}

//系统用户注册界面
void Menu2()
{
    system("clear");
    printf("====================================\n");
    printf("                                 \n");
    printf("   该界面为：*系统用户注册界面*       \n");
    printf("     1: 注册账号                   \n");
    printf("     2：返回 *用户登录注册界面*      \n");
    printf("     0： 退出系统                  \n");
    printf("                                 \n");
    printf("====================================\n");
    printf("请输入选项：\n");
}

//用户登录注册界面
void Menu3()
{
    system("clear");
    printf("====================================\n");
    printf("                                  \n");
    printf("   该界面为：*系统用户登录界面*       \n");
    printf("      1：登录                      \n");
    printf("      2：返回 *用户登录注册界面*      \n");
    printf("      0: 退出系统                   \n");
    printf("                                   \n");
    printf("====================================\n");
    printf("请输入选项：\n");
}
// 管理员菜单界面
void Menu_admist()
{
    system("clear");
    printf("==========================================\n");
    printf("                                        \n");
    printf("   欢迎来到 *系统管理员功能菜单界面*         \n");
    printf("     1: 批量创建普通用户账号               \n");
    printf("     2: 批量删除普通用户账号                \n");
    printf("     3: 修改单个用户密码或查看用户密码       \n");
    printf("     4：重制单个用户密码                   \n");
    printf("     5：显示全部住宿信息，排序              \n");
    printf("     6：添加一条住宿信息                   \n");
    printf("     7：修改一条住宿信息                   \n");
    printf("     8：删除一条住宿信息                   \n");
    printf("     9：根据姓名查找                     \n");
    printf("     10：根据学号查找                     \n");
    printf("     11：根据宿舍号查找                   \n");
    printf("     0: 退出系统                         \n");
    printf("                                   \n");
    printf("==========================================\n");
}

void PrintTitle()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("      宿舍号 |        学号 |        名字 |       性别|      电话号码｜    寝室长\n");
}

/*
@brife 下列函数是输出结点 p 所代表的住宿信息的内容（宿舍号、学号、姓名）。
*/
void PrintDormitory(dormitory p)
{
    printf(" %10s ", p.dormID);
    printf("| %10s  ", p.studentID);
    printf(" | %10s", p.Name);
    if (strcmp(p.sex, "0") == 0) {
        char *s = "男";
        printf(" | %10s", s);
    } else {
        char *s = "女";
        printf(" | %10s", s);
    }
    printf(" | %10s    ", p.phonenumber);
    printf(" | %8s", p.vip);
    printf("\n");
    printf("\n");
}

// 普通用户菜单界面
void Menu_user()
{
    system("clear");
    printf("============================================\n");
    printf("                                          \n");
    printf("   欢迎来到 *系统普通用户功能菜单界面*         \n");
    printf("     1: 重置密码                           \n");
    printf("     2: 根据姓名查找                        \n");
    printf("     3：根据学号查找                        \n");
    printf("     4：根据宿舍号查找                      \n");
    printf("     0: 退出系统                           \n");
    printf("                                          \n");
    printf("============================================\n");
}