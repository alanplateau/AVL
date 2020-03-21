#include <iostream>
#include"userAVLtree.h"
using namespace std;

int main()
{
    //�����û���AVL��
    ifstream infileuser("userdata.txt",ios::in);
    if(!infileuser)
    {
        cout<<"open user's txt failed"<<endl;
        exit(1);
    }
    userAVLtree users;
    users.readfile(infileuser);
    infileuser.close();

    //��������Ա��AVL��
    ifstream infilemanager("manager.txt",ios::in);
    if(!infilemanager)
    {
        cout<<"open manager's txt failed"<<endl;
        exit(1);
    }
    userAVLtree managers;
    managers.readfile(infilemanager);
    infilemanager.close();

    //���������û�������˺ź�����
    string account;
    string password;

    //��¼�û����еĲ���
    int first,second,third,fourth;

    for(;;)
    {
        //��ʼ����
        cout<<"-------------------------------------------"<<endl;
        cout<<"                ��¼��֤ϵͳ               "<<endl;
        cout<<"1.�û���¼                                 "<<endl;
        cout<<"2.����Ա��¼                               "<<endl;
        cout<<"3.ע���û�                                 "<<endl;
        cout<<"4.�˳�                                     "<<endl;
        cout<<"       ������1��2��3��4��������һ������    "<<endl;
        cout<<"-------------------------------------------"<<endl;
        cin>>first;

        //�������Ϊ4���˳�ϵͳ
        if(first==4)
            break;

        switch(first)
        {
        case 1:
            {
                //�û���¼
                system("cls");
                cout<<"�������û�����";
                cin>>account;
                cout<<"���������룺";
                cin>>password;

                //����û���������ȷ
                if(users.loginverify(account,password))
                {
                    system("cls");
                    cout<<"��¼�ɹ�"<<endl;
                    system("pause");

                    for(;;)
                   {
                    system("cls");
                    //�û�����
                    cout<<"------------------------------------------"<<endl;
                    cout<<"             �û�����                     "<<endl;
                    cout<<"1.�޸�����                                "<<endl;
                    cout<<"2.ע�����˺�(����������˺�,������ѡ��)   "<<endl;
                    cout<<"3.������һ��                              "<<endl;
                    cout<<"    ������1��2��3����������һ������       "<<endl;
                    cout<<"------------------------------------------"<<endl;
                    cin>>second;

                    if(second==3)
                        break;
                    else if(second==2)
                    {
                        //ע���û�
                        system("cls");
                        users.deleteuser(account);
                        system("pause");
                        break;
                    }

                        switch(second)
                        {
                        case 1:
                            {
                                //������
                                system("cls");
                                string newpassword;
                                cout<<"�����������:";
                                cin>>password;
                                cout<<"������������:";
                                cin>>newpassword;
                                system("cls");
                                users.updatepassword(account,password,newpassword);
                                system("pause");
                                break;
                            }
                        default:
                            {
                                system("cls");
                                cout<<"�������,�������ϼ�ҳ��";
                                system("pause");
                            }

                        }
                   }

                }
                else//�����û������벻��ȷ��
                {
                    system("cls");
                    cout<<"�����û������벻��ȷ"<<endl;
                    system("pause");
                }
                break;
            }
        case 2:
            {
                //����Ա��¼
                system("cls");
                cout<<"�������û�����";
                cin>>account;
                cout<<"���������룺";
                cin>>password;
                if(managers.loginverify(account,password))
                {
                    system("cls");
                    cout<<"��¼�ɹ�"<<endl;
                    system("pause");

                    for(;;)
                    {
                        system("cls");
                        //����Ա����
                        cout<<"---------------------------------------"<<endl;
                        cout<<"             ����Ա����                "<<endl;
                        cout<<"1.�޸�����                             "<<endl;
                        cout<<"2.ע���µĹ���Ա�˻�                   "<<endl;
                        cout<<"3.ɾ���û�                             "<<endl;
                        cout<<"4.�����û�                             "<<endl;
                        cout<<"5.������һ��                           "<<endl;
                        cout<<"   ������1��2��3��4��5 ��������һ������"<<endl;
                        cout<<"---------------------------------------"<<endl;
                        cin>>third;
                        if(third==5)
                            break;

                        switch(third)
                        {
                        case 1:
                            {
                                //������
                                system("cls");
                                string newpassword;
                                cout<<"�����������:";
                                cin>>password;
                                cout<<"������������:";
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
                                cout<<"�������û���:";
                                cin>>tempaccount;
                                cout<<"����������:";
                                cin>>temppassword;
                                if(managers.search(tempaccount)!=0)
                                {
                                    system("cls");
                                    cout<<"����ʧ�ܣ��û�����ͬ"<<endl;

                                }
                                else
                                {
                                    managers.insert(tempaccount,temppassword);
                                    system("cls");
                                    cout<<"�����ɹ�"<<endl;
                                }
                                system("pause");
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                string targetaccount;
                                cout<<"������Ҫɾ���û����û���:";
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
                                cout<<"�������û���:";
                                cin>>tempaccount1;
                                cout<<"����������:";
                                cin>>temppassword1;
                                if(users.search(tempaccount1)!=0)
                                {
                                  system("cls");
                                  cout<<"����ʧ�ܣ��û�����ͬ"<<endl;
                                }
                                else
                                {
                                   users.insert(tempaccount1,temppassword1);
                                   system("cls");
                                   cout<<"�����ɹ�"<<endl;
                                }
                                system("pause");
                                break;
                            }
                        default:
                            {
                                system("cls");
                                cout<<"�������,�������ϼ�ҳ��";
                                system("pause");
                            }
                        }
                    }
                }
                else//�û������벻��ȷ
                {
                    system("cls");
                    cout<<"�����û������벻��ȷ"<<endl;
                    system("pause");
                }
                break;
            }
        case 3:
            {
                system("cls");
                string tempaccount1;
                string temppassword1;
                cout<<"�������û���:";
                cin>>tempaccount1;
                cout<<"����������:";
                cin>>temppassword1;
                if(users.search(tempaccount1)!=0)
                {
                    system("cls");
                    cout<<"����ʧ�ܣ��û�����ͬ"<<endl;
                }
                else
                {
                    users.insert(tempaccount1,temppassword1);
                    system("cls");
                    cout<<"�����ɹ�"<<endl;
                }
                system("pause");
                break;
            }
        default:
            system("cls");
            cout<<"���������"<<endl;
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
