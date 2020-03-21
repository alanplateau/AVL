#include <iostream>
#include"userAVLtree.h"
using namespace std;

int main()
{
    //建立用户的AVL树
    ifstream infileuser("userdata.txt",ios::in);
    if(!infileuser)
    {
        cout<<"open user's txt failed"<<endl;
        exit(1);
    }
    userAVLtree users;
    users.readfile(infileuser);
    infileuser.close();

    //建立管理员的AVL树
    ifstream infilemanager("manager.txt",ios::in);
    if(!infilemanager)
    {
        cout<<"open manager's txt failed"<<endl;
        exit(1);
    }
    userAVLtree managers;
    managers.readfile(infilemanager);
    infilemanager.close();

    //用来保存用户输入的账号和密码
    string account;
    string password;

    //记录用户进行的操作
    int first,second,third,fourth;

    for(;;)
    {
        //初始界面
        cout<<"-------------------------------------------"<<endl;
        cout<<"                登录认证系统               "<<endl;
        cout<<"1.用户登录                                 "<<endl;
        cout<<"2.管理员登录                               "<<endl;
        cout<<"3.注册用户                                 "<<endl;
        cout<<"4.退出                                     "<<endl;
        cout<<"       请输入1，2，3，4来进行下一步操作    "<<endl;
        cout<<"-------------------------------------------"<<endl;
        cin>>first;

        //如果输入为4则退出系统
        if(first==4)
            break;

        switch(first)
        {
        case 1:
            {
                //用户登录
                system("cls");
                cout<<"请输入用户名：";
                cin>>account;
                cout<<"请输入密码：";
                cin>>password;

                //如果用户名密码正确
                if(users.loginverify(account,password))
                {
                    system("cls");
                    cout<<"登录成功"<<endl;
                    system("pause");

                    for(;;)
                   {
                    system("cls");
                    //用户界面
                    cout<<"------------------------------------------"<<endl;
                    cout<<"             用户界面                     "<<endl;
                    cout<<"1.修改密码                                "<<endl;
                    cout<<"2.注销此账号(永久清除该账号,请慎重选择)   "<<endl;
                    cout<<"3.返回上一级                              "<<endl;
                    cout<<"    请输入1，2，3，来进行下一步操作       "<<endl;
                    cout<<"------------------------------------------"<<endl;
                    cin>>second;

                    if(second==3)
                        break;
                    else if(second==2)
                    {
                        //注销用户
                        system("cls");
                        users.deleteuser(account);
                        system("pause");
                        break;
                    }

                        switch(second)
                        {
                        case 1:
                            {
                                //改密码
                                system("cls");
                                string newpassword;
                                cout<<"请输入旧密码:";
                                cin>>password;
                                cout<<"请输入新密码:";
                                cin>>newpassword;
                                system("cls");
                                users.updatepassword(account,password,newpassword);
                                system("pause");
                                break;
                            }
                        default:
                            {
                                system("cls");
                                cout<<"输入错误,将跳回上级页面";
                                system("pause");
                            }

                        }
                   }

                }
                else//输入用户名密码不正确；
                {
                    system("cls");
                    cout<<"输入用户名密码不正确"<<endl;
                    system("pause");
                }
                break;
            }
        case 2:
            {
                //管理员登录
                system("cls");
                cout<<"请输入用户名：";
                cin>>account;
                cout<<"请输入密码：";
                cin>>password;
                if(managers.loginverify(account,password))
                {
                    system("cls");
                    cout<<"登录成功"<<endl;
                    system("pause");

                    for(;;)
                    {
                        system("cls");
                        //管理员界面
                        cout<<"---------------------------------------"<<endl;
                        cout<<"             管理员界面                "<<endl;
                        cout<<"1.修改密码                             "<<endl;
                        cout<<"2.注册新的管理员账户                   "<<endl;
                        cout<<"3.删除用户                             "<<endl;
                        cout<<"4.增加用户                             "<<endl;
                        cout<<"5.返回上一级                           "<<endl;
                        cout<<"   请输入1，2，3，4，5 来进行下一步操作"<<endl;
                        cout<<"---------------------------------------"<<endl;
                        cin>>third;
                        if(third==5)
                            break;

                        switch(third)
                        {
                        case 1:
                            {
                                //改密码
                                system("cls");
                                string newpassword;
                                cout<<"请输入旧密码:";
                                cin>>password;
                                cout<<"请输入新密码:";
                                cin>>newpassword;
                                system("cls");
                                users.updatepassword(account,password,newpassword);
                                system("pause");
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                string tempaccount;
                                string temppassword;
                                cout<<"请输入用户名:";
                                cin>>tempaccount;
                                cout<<"请输入密码:";
                                cin>>temppassword;
                                if(managers.search(tempaccount)!=0)
                                {
                                    system("cls");
                                    cout<<"创建失败，用户名相同"<<endl;

                                }
                                else
                                {
                                    managers.insert(tempaccount,temppassword);
                                    system("cls");
                                    cout<<"创建成功"<<endl;
                                }
                                system("pause");
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                string targetaccount;
                                cout<<"请输入要删除用户的用户名:";
                                cin>>targetaccount;
                                system("cls");
                                users.deleteuser(targetaccount);
                                system("pause");
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                string tempaccount1;
                                string temppassword1;
                                cout<<"请输入用户名:";
                                cin>>tempaccount1;
                                cout<<"请输入密码:";
                                cin>>temppassword1;
                                if(users.search(tempaccount1)!=0)
                                {
                                  system("cls");
                                  cout<<"创建失败，用户名相同"<<endl;
                                }
                                else
                                {
                                   users.insert(tempaccount1,temppassword1);
                                   system("cls");
                                   cout<<"创建成功"<<endl;
                                }
                                system("pause");
                                break;
                            }
                        default:
                            {
                                system("cls");
                                cout<<"输入错误,将跳回上级页面";
                                system("pause");
                            }
                        }
                    }
                }
                else//用户名密码不正确
                {
                    system("cls");
                    cout<<"输入用户名密码不正确"<<endl;
                    system("pause");
                }
                break;
            }
        case 3:
            {
                system("cls");
                string tempaccount1;
                string temppassword1;
                cout<<"请输入用户名:";
                cin>>tempaccount1;
                cout<<"请输入密码:";
                cin>>temppassword1;
                if(users.search(tempaccount1)!=0)
                {
                    system("cls");
                    cout<<"创建失败，用户名相同"<<endl;
                }
                else
                {
                    users.insert(tempaccount1,temppassword1);
                    system("cls");
                    cout<<"创建成功"<<endl;
                }
                system("pause");
                break;
            }
        default:
            system("cls");
            cout<<"错误的输入"<<endl;
            system("pause");
        }
        system("cls");
    }
    ofstream outfileuser("userdata.txt",ios::out);
    if(!outfileuser)
    {
        cout<<"write user data failed"<<endl;
        exit(1);
    }
    users.writetofile(outfileuser);
    outfileuser.close();

    ofstream outfilemanager("manager.txt",ios::out);
    if(!outfilemanager)
    {
        cout<<"write manager data failed"<<endl;
        exit(1);
    }
    managers.writetofile(outfilemanager);
    outfilemanager.close();


}
