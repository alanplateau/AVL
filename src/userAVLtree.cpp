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
 *�����ĵĸ߶�
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
 *�Ƚ�������С
 */
int userAVLtree::max(int a,int b)
{
    return (a>b?a:b);
}
/*
 *����
 *������ת��ĸ��ڵ�
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
 *����
 *������ת��ĸ��ڵ�
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
 *��-����
 *������ת��ĸ��ڵ�
 */
user *userAVLtree::leftrightRotation(user* k1)
{
    k1->left=rightrightRotation(k1->left);
    return leftleftRotation(k1);
}

/*
 *��-����
 *������ת��ĸ��ڵ�
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
 *����һ���û��ڵ�
 *���ظ��ڵ�
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
         cout<<"���ʧ�ܣ������������ͬ�Ľڵ�"<<endl;
     }
     subtree->height=max(height(subtree->left),height(subtree->right))+1;
     return subtree;
 }

 /*
  *��account���ҽڵ�
  *����Ŀ��ڵ��user *
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
  *����search������֤�û�������
  *������ȷ���
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
  *ǰ��:�����û����������룬������
  *����:����������ȷ������£���֮������
  */
  void userAVLtree::updatepassword(string ac,string oldpassword,string newpassword)
  {
      if(loginverify(ac,oldpassword))
      {
          user *target=search(ac);
          target->password=newpassword;
          cout<<"���³ɹ�"<<endl;
      }
      else
        cout<<"�������������"<<endl;
  }

  /*
  *ǰ��:����ڵ�ָ��
  *����:�����Ը�ָ��Ϊ�����������ڵ�
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
  *ǰ��:����ڵ�ָ��
  *����:�����Ը�ָ��Ϊ�����������ڵ�
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
          cout<<"ɾ���ɹ�"<<endl;
      }
      else
       cout<<"�û�������"<<endl;
  }

  /*
  *ǰ��:�����ɾ���ڵ��user *�͸�
  *����:ɾ���ڵ㣬����AVL���ĸ�
  */
  user * userAVLtree::deleteuserAux(user *target,user *subtree)
  {
      if(target->account<subtree->account)//��ɾ���ڵ���subtree��������
      {
          subtree->left=deleteuserAux(target,subtree->left);
          //ɾ���ڵ����AVL��ʧȥƽ���������Ӧ����
          if(height(subtree->right)-height(subtree->left)==2)
          {
              user * temp=subtree->right;
              if(height(temp->right)>height(temp->left))
                subtree=rightrightRotation(subtree);
              else
                subtree=rightleftRotation(subtree);
          }
      }
      else if(target->account>subtree->account)//��ɾ���ڵ���subtree��������
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
      else//��ɾ���ڵ�Ϊsubtree
      {
          //subtree��Ů�ڵ�Բ�Ϊ��
          if(subtree->left!=0&&subtree->right!=0)
          {
              //�����������
              //��subtree���������ڵ���˺����븳��subtree
              //ɾ�������ڵ�
              if(height(subtree->left)>height(subtree->right))
              {
                  user * max1=maximum(subtree->left);
                  subtree->account=max1->account;
                  subtree->password=max1->password;
                  subtree->left=deleteuserAux(max1,subtree->left);
              }
              else
              {
                  //����������߻����߸߶����
                  //��subtree��������С�ڵ���˺����븳��subtree
                  //ɾ�������ڵ�
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
 *ɾ������ȫ���ڵ�
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
 *����ifstream��ָ���ļ�һ��һ�ж�ȡ�û���������
 *�γ�һ��AVL�û���
 */
 void userAVLtree::readfile(ifstream &infile)
 {
     string ac;
     string pa;
     while(!infile.eof())
     {
         infile>>ac>>pa;
         //��ֹ���һ�����ݶ�ȡ����
         if(!infile)
            break;
         insert(ac,pa);
     }
 }

 /*
  *�����е�ȫ���ڵ�����д�뵽�ļ���
  */
  void userAVLtree::writetofile(ofstream &outfile)
  {
      writetofileAux(outfile,root);
  }

  void userAVLtree::writetofileAux(ofstream &outfile,user *tree)
  {
      if(tree!=0)
      {
        //ǰ��������
        if(tree->account.length()!=0&&tree->password.length()!=0)
        {
            outfile<<tree->account<<"  "<<tree->password<<endl;
        }
        writetofileAux(outfile,tree->left);
        writetofileAux(outfile,tree->right);
      }
  }






