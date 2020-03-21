#include "userAVLtree.h"

userAVLtree::userAVLtree()
{
    root=0;
}

userAVLtree::~userAVLtree()
{
    destroy();
}
/*
 *求树的的高度
 */
int userAVLtree::height()
{
    return height(root);
}

int userAVLtree::height(user * subtree)
{
    if(subtree==0)
    {
        return 0;
    }
    return subtree->height;
}

/*
 *比较两数大小
 */
int userAVLtree::max(int a,int b)
{
    return (a>b?a:b);
}
/*
 *右旋
 *返回旋转后的根节点
 */
user * userAVLtree::leftleftRotation(user * k2)
{
    user *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->right),height(k2->left))+1;
    k1->height=max(height(k1->right),height(k1->left))+1;
    return k1;
}

/*
 *左旋
 *返回旋转后的根节点
 */
user * userAVLtree::rightrightRotation(user *k2)
{
    user *k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->right),height(k1->left))+1;
    return k1;
}

/*
 *左-右旋
 *返回旋转后的根节点
 */
user *userAVLtree::leftrightRotation(user* k1)
{
    k1->left=rightrightRotation(k1->left);
    return leftleftRotation(k1);
}

/*
 *右-左旋
 *返回旋转后的根节点
 */
user *userAVLtree::rightleftRotation(user * k1)
{
    k1->right=leftleftRotation(k1->right);
    return rightrightRotation(k1);
}

void userAVLtree::insert(string ac,string pa)
{
    root=insertAux(ac,pa,root);
}

/*
 *插入一个用户节点
 *返回根节点
 */
 user *userAVLtree::insertAux(string ac,string pa,user* subtree)
 {
     if(subtree==0)
     {
         subtree=new user(ac,pa);
         if(subtree==0)
         {
             cout<<"creat node failed"<<endl;
             return 0;
         }
     }
     else if(ac<subtree->account)
     {
         subtree->left=insertAux(ac,pa,subtree->left);
         if(height(subtree->left)-height(subtree->right)==2)
         {
             if(ac<subtree->left->account)
                subtree=leftleftRotation(subtree);
             else
                subtree=leftrightRotation(subtree);
         }
     }
     else if(ac>subtree->account)
     {
         subtree->right=insertAux(ac,pa,subtree->right);
         if(height(subtree->right)-height(subtree->left)==2)
         {
             if(ac>subtree->right->account)
                subtree=rightrightRotation(subtree);
             else
                subtree=rightleftRotation(subtree);
         }
     }
     else//account=subtree->account
     {
         cout<<"添加失败，不允许添加相同的节点"<<endl;
     }
     subtree->height=max(height(subtree->left),height(subtree->right))+1;
     return subtree;
 }

 /*
  *按account查找节点
  *返回目标节点的user *
  */
  user * userAVLtree::search(string ac)
  {
      user* locptr=root;
      while(locptr!=0)
      {
          if(ac<locptr->account)
            locptr=locptr->left;
          else if(ac>locptr->account)
            locptr=locptr->right;
          else
            return locptr;
      }
      return 0;
  }

  /*
  *运用search函数验证用户名密码
  *返回正确与否
  */
  bool userAVLtree::loginverify(string ac,string pa)
  {
      user * target;
      target=search(ac);
      if(target==0)
        return false;
      else if(target->password==pa)
        return true;
      else
        return false;
  }

  /*
  *前置:输入用户名，旧密码，新密码
  *后置:若旧密码正确，则更新，反之不更新
  */
  void userAVLtree::updatepassword(string ac,string oldpassword,string newpassword)
  {
      if(loginverify(ac,oldpassword))
      {
          user *target=search(ac);
          target->password=newpassword;
          cout<<"更新成功"<<endl;
      }
      else
        cout<<"旧密码输入错误"<<endl;
  }

  /*
  *前置:输入节点指针
  *后置:返回以该指针为根的树的最大节点
  */
  user * userAVLtree::maximum(user *subtree)
  {
      if(subtree!=0)
      {
          while(subtree->right!=0)
          {
              subtree=subtree->right;
          }
          return subtree;
      }
      else
        return 0;
  }

  /*
  *前置:输入节点指针
  *后置:返回以该指针为根的树的最大节点
  */
  user * userAVLtree::minimum(user *subtree)
  {
      if(subtree!=0)
      {
          while(subtree->left!=0)
          {
              subtree=subtree->left;
          }
          return subtree;
      }
      else
        return 0;
  }

  void userAVLtree::deleteuser(string ac)
  {
      user *target;
      if((target=search(ac))!=0)
      {
          root=deleteuserAux(target,root);
          cout<<"删除成功"<<endl;
      }
      else
       cout<<"用户不存在"<<endl;
  }

  /*
  *前置:传入待删除节点的user *和根
  *后置:删除节点，返回AVL树的根
  */
  user * userAVLtree::deleteuserAux(user *target,user *subtree)
  {
      if(target->account<subtree->account)//待删除节点在subtree左子树中
      {
          subtree->left=deleteuserAux(target,subtree->left);
          //删除节点后，若AVL树失去平衡则进行相应调节
          if(height(subtree->right)-height(subtree->left)==2)
          {
              user * temp=subtree->right;
              if(height(temp->right)>height(temp->left))
                subtree=rightrightRotation(subtree);
              else
                subtree=rightleftRotation(subtree);
          }
      }
      else if(target->account>subtree->account)//待删除节点在subtree右子树中
      {
          subtree->right=deleteuserAux(target,subtree->right);
          if(height(subtree->left)-height(subtree->right)==2)
          {
              user * temp2=subtree->left;
              if(height(temp2->left)>height(temp2->right))
                subtree=leftleftRotation(subtree);
              else
                subtree=leftrightRotation(subtree);
          }
      }
      else//待删除节点为subtree
      {
          //subtree子女节点皆不为空
          if(subtree->left!=0&&subtree->right!=0)
          {
              //如果左子树高
              //将subtree左子树最大节点的账号密码赋给subtree
              //删除该最大节点
              if(height(subtree->left)>height(subtree->right))
              {
                  user * max1=maximum(subtree->left);
                  subtree->account=max1->account;
                  subtree->password=max1->password;
                  subtree->left=deleteuserAux(max1,subtree->left);
              }
              else
              {
                  //如果右子树高或两边高度相等
                  //将subtree右子树最小节点的账号密码赋给subtree
                  //删除该最大节点
                  user * min1=minimum(subtree->right);
                  subtree->account=min1->account;
                  subtree->password=min1->password;
                  subtree->right=deleteuserAux(min1,subtree->right);
              }
          }
          else
          {
              user * temp2=subtree;
              subtree=(subtree->left==0)?subtree->right:subtree->left;
              delete temp2;
          }
      }
      return subtree;
  }

void userAVLtree::display()
{
    displayAux(root);
}

void userAVLtree::displayAux(user *subtree)
{
    if(subtree!=0)
    {
        displayAux(subtree->left);
        displayAux(subtree->right);
        if(subtree->account.length()!=0&&subtree->password.length()!=0)
        {
            cout<<subtree->account<<"  "<<subtree->password<<endl;
        }
    }
}

/*
 *删除树的全部节点
 */
void userAVLtree::destroy()
{
    destroy(root);
}

void userAVLtree::destroy(user * tree)
{
    if (tree==NULL)
        return ;

     if (tree->left != NULL)
         destroy(tree->left);
     if (tree->right != NULL)
         destroy(tree->right);

     delete tree;

}

/*
 *运用ifstream从指定文件一行一行读取用户名和密码
 *形成一个AVL用户树
 */
 void userAVLtree::readfile(ifstream &infile)
 {
     string ac;
     string pa;
     while(!infile.eof())
     {
         infile>>ac>>pa;
         //防止最后一行数据读取两次
         if(!infile)
            break;
         insert(ac,pa);
     }
 }

 /*
  *将树中的全部节点数据写入到文件中
  */
  void userAVLtree::writetofile(ofstream &outfile)
  {
      writetofileAux(outfile,root);
  }

  void userAVLtree::writetofileAux(ofstream &outfile,user *tree)
  {
      if(tree!=0)
      {
        //前序遍历输出
        if(tree->account.length()!=0&&tree->password.length()!=0)
        {
            outfile<<tree->account<<"  "<<tree->password<<endl;
        }
        writetofileAux(outfile,tree->left);
        writetofileAux(outfile,tree->right);
      }
  }






