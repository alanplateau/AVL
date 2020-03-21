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
    //树的高度
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

        //获取树的总高度
        int height();
        int max(int a,int b);


        //将用户信息从文件写入到树里
        void readfile(ifstream & infile);

        //将avl树中的信息写到文件里
        void writetofile(ofstream & outfile);

        //插入新的用户至树里
        void insert(string ac,string pa);
        //删除用户
        void deleteuser(string ac);

        //用户登录验证
        bool loginverify(string ac,string pa);

        //用户更新密码；
        void updatepassword(string ac,string oldpassword,string newpassword);

        //查找函数返回目标的user *，用来辅助登录验证和更新密码
        user *search(string ac);

        void display();

        void displayAux(user *subtree);

        void destroy();

    private:
        //查找以subtree为根的树下的最小节点，返回user *
        user * maximum(user *subtree);
        //查找以subtree为根的树的最小节点，返回user *
        user * minimum(user *subtree);

        //获取以该节点为根的树的高度
        int height(user *subtree);

        //插入函数辅助函数
        user *insertAux(string ac,string pa,user *subtree);

        //删除节点函数辅助函数
        user *deleteuserAux(user *target,user *subtree);


        //要插入的节点位于k2左孩子的左子树
        user *leftleftRotation(user *k2);
        //要插入节点位于k2右孩子的右子树
        user *rightrightRotation(user *k2);
        //位于左孩子的右子树
        user *leftrightRotation(user *k1);
        //位于右孩子的左子树
        user *rightleftRotation(user *k1);

        //辅助删除树的全部节点
        void destroy(user * tree);

        //辅助将树的节点数据输入到文件中
        void writetofileAux(ofstream & outfile,user * tree);

        user * root;
};



#endif // USERAVLTREE_H
