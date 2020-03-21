#ifndef USERAVLTREE_H
#define USERAVLTREE_H
#include<iostream>
#include<fstream>
using namespace std;
class user
{
public:
    string account;
    string password;
    //���ĸ߶�
    int height;
    user *left;
    user *right;
    user(string ac,string pa):account(ac),password(pa),height(0),left(0),right(0){}
    user():account(0),password(0),height(0),left(0),right(0){}
};

class userAVLtree
{
    public:
        userAVLtree();
        virtual ~userAVLtree();

        //��ȡ�����ܸ߶�
        int height();
        int max(int a,int b);


        //���û���Ϣ���ļ�д�뵽����
        void readfile(ifstream & infile);

        //��avl���е���Ϣд���ļ���
        void writetofile(ofstream & outfile);

        //�����µ��û�������
        void insert(string ac,string pa);
        //ɾ���û�
        void deleteuser(string ac);

        //�û���¼��֤
        bool loginverify(string ac,string pa);

        //�û��������룻
        void updatepassword(string ac,string oldpassword,string newpassword);

        //���Һ�������Ŀ���user *������������¼��֤�͸�������
        user *search(string ac);

        void display();

        void displayAux(user *subtree);

        void destroy();

    private:
        //������subtreeΪ�������µ���С�ڵ㣬����user *
        user * maximum(user *subtree);
        //������subtreeΪ����������С�ڵ㣬����user *
        user * minimum(user *subtree);

        //��ȡ�Ըýڵ�Ϊ�������ĸ߶�
        int height(user *subtree);

        //���뺯����������
        user *insertAux(string ac,string pa,user *subtree);

        //ɾ���ڵ㺯����������
        user *deleteuserAux(user *target,user *subtree);


        //Ҫ����Ľڵ�λ��k2���ӵ�������
        user *leftleftRotation(user *k2);
        //Ҫ����ڵ�λ��k2�Һ��ӵ�������
        user *rightrightRotation(user *k2);
        //λ�����ӵ�������
        user *leftrightRotation(user *k1);
        //λ���Һ��ӵ�������
        user *rightleftRotation(user *k1);

        //����ɾ������ȫ���ڵ�
        void destroy(user * tree);

        //���������Ľڵ��������뵽�ļ���
        void writetofileAux(ofstream & outfile,user * tree);

        user * root;
};



#endif // USERAVLTREE_H
