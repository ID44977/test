/*D
#include<iostream>
#include<stack>
using namespace std;
const int maxx= 100;
int shu[maxx][maxx];
int n;
int path(int i, int j){
    if(j+ 1< n&&!shu[i][j+ 1])
        return 1;
    else if(i+ 1< n&& !shu[i+ 1][j])
        return 2;
    else if(j- 1>= 0&&!shu[i][j- 1])
        return 3;
    else if(i- 1>= 0&&!shu[i- 1][j])
        return 4;
    return 0;
}
int main(){

    int t;
    int ii[]= {0, 0, 1, 0, -1};
    int jj[]= {0, 1, 0, -1, 0};
    cin>>t;
    while(t--){

        cin>>n;

        stack<int> stx;
        stack<int> sty;


        for(int i= 0; i< n; i++)
            for(int j= 0; j< n; j++)
                cin>>shu[i][j];


        stx.push(0);
        sty.push(0);
        shu[0][0]= 1;
        int i= 0;
        int j= 0;
        while(1){
            int k= path(i, j);

            if(k){
                i+= ii[k];
                j+= jj[k];
                shu[i][j]= 1;
                stx.push(i);
                sty.push(j);

            }
            else if(!stx.empty()&&!sty.empty()){
                i= stx.top();
                j= sty.top();
                if(!path(i, j)){
                    stx.pop();
                    sty.pop();
                }



            }

            if((stx.empty()&&sty.empty())|| (i== n-1&&j== n-1))
                break;
        }

        if(stx.empty()&&sty.empty())
        {
            cout<<"no path"<<endl;
        }
        else{
            int zuo[1000];
            int len= 0;
            int l= 0;

            while(!stx.empty()&&!sty.empty()){
                len+= 2;
                zuo[l++]= stx.top();
                zuo[l++]= sty.top();
                stx.pop();
                sty.pop();
            }

            int flag= 1;
            for(int i= len- 1; i>= 0;){

                cout<<'['<<zuo[i--]<<','<<zuo[i--]<<']'<<"--";
                if((flag++)%4== 0)
                    cout<<endl;
            }
            cout<<"END"<<endl;
        }
    }
    return 0;
}
*/
/*A
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int t;
    queue<int> myque[4];

    cin>>t;
    int n= t;
    int i= 0;
    vector<int> num(4,0);
    while(n--){
        char s;
        cin>>s;
        if(s== 'A'){
            myque[0].push(1);
            num[1]++;
        }
        else if(s== 'B'){
            myque[0].push(2);
            num[2]++;
        }

        else{
            myque[0].push(3);
            num[3]++;
        }

    }

    i= 0;
    n= t;
    while(n--){
        int in;
        cin>>in;
        myque[myque[0].front()].push(in);//存储排队的时间
        myque[0].pop();
    }
    vector<int> sum(4, 0);
    while(!myque[1].empty()){
        sum[1]+= myque[1].front();
        myque[1].pop();
    }

    while(!myque[2].empty()){
        sum[2]+= myque[2].front();
        myque[2].pop();
    }

    while(!myque[3].empty()){
        sum[3]+= myque[3].front();
        myque[3].pop();
    }


    cout<<sum[1]/num[1]<<endl<<sum[2]/num[2]<<endl<<sum[3]/num[3]<<endl;
    return 0;
}
 */

/*B
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<iomanip>
#include<map>
using namespace std;
const int maxx= 100+20;
int shu[maxx];
int sh= 0;

int getsh(int a){//判断该组的数据是否已经输入过了，如果没有则记录顺序
    for(int i= 0; i< sh; i++)
        if(shu[i]== a)
            return 1;

    return 0;
}
int main(){

    int t;
    int n;
    cin>>t;
    int o= t;
    map<string, int> ma;
    queue<string> que[maxx];

    for(int i= 0; i< maxx; i++)//初始数组
        shu[i]= -1;

    int i= 0;
    while(t--){
        cin>>n;
        while(n--){
            string s;
            cin>>s;

            ma[s]= i;
        }
        i++;

    }

    int flag= 0;

    while(1){
        string str;
        string in;
        cin>>str;

        if(str== "STOP")
            break;

        if(str== "ENQUEUE"){
            map<string, int>::iterator it;
            cin>>in;
            it= ma.find(in);//查找组队列中是否有该数据，如果没有则输出最后位置的地址

            if(it!= ma.end()){//找到数据则进入
                ma.insert(pair<string, int>(in, it->second));
                que[it->second].push(in);

                if(!getsh(it->second)){
                    shu[sh++]= it->second;
                }

            }
            else{
                ma.insert(pair<string, int>(in, o- 1));
                que[o- 1].push(in);

                if(!getsh(o- 1)){
                    shu[sh++]= o- 1;
                }
            }
        }

        if(str== "DEQUEUE"){
            int i =0;
            int j= 0;
            while(true){
                if(que[shu[j]].empty())
                    j++;
                else{
                    if(!flag){
                        cout<<que[shu[j]].front();
                        flag++;
                    }
                    else
                        cout<<' '<<que[shu[j]].front();
                    que[shu[j]].pop();
                    break;
                }
            }
        }
    }
    cout<<endl;
    return 0;
}
*/

/*C
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char boy, temp;
    int end = 0, num = 0;
    char a[55];
    scanf("%c", &boy);
    a[0] = 0;
    while (scanf("%c", &temp) != EOF)
    {
        if (temp == boy)
        {
            end++;
            num++;
            a[end] = num;
        }
        else
        {
            num++;
            printf("%d %d\n", a[end], num);
            end--;
            if (end < 0) return 0;
        }
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x=91;
    int y=100;
    int n=0;
    x=91;y=100;
    while(y>0)
        if (x>10) {y--;n++;}

        cout<<n<<endl;
}
 */
//2018.10.15 实验05 串应用【李延红】【10月15日周一下午】
/*
//A
#include <iostream>
#include <string>

using namespace std;

class myString
{
private:
    string mainstr;
    int size;

    void GetNext(string p,int next[])
    {
        next[0]=-1;
        for(int i=1; i<p.length();i++)
        {
            int j=next[i-1];
            while(p[i-1]!=p[j] && j >= 0)
                j = next[j];
            if(p[i-1] == p[j])
                next[i] = j+1;
            else
                next[i] = 0;
        }
    }
    int KMPFind(string p,int pos,int next[])
    {
        int n, m;
        m = p.length();
        GetNext(p, next);
        for (int i = pos-1, q = 0; i < size; i++)
        {
            while (q > 0 && p[q] != mainstr[i])
                q = next[q - 1];
            if(q==-1)
            {
                q=0;
            }
            if (p[q] == mainstr[i])
                q++;
            if (q == m)
            {
                return (i-m+2);
            }
        }
        return 0;
    }


public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p,int pos);
};

myString::myString()
{
    size=0;
    mainstr="";
}

myString::~myString()
{
    size=0;
    mainstr="";
}

void myString::SetVal(string sp)
{
    mainstr="";
    mainstr.assign(sp);
    size=mainstr.length();
}

int myString::KMPFindSubstr(string p,int pos)
{
    int i;
    int L=p.length();
    int *next=new int[L];
    GetNext(p,next);
    for (i = 0; i < L; i++)
        cout<<next[i]<<' ';
    cout<<endl;
    int v = -1;
    v = KMPFind(p,pos,next);

    delete []next;

    return v;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        myString str;
        string p,t;
        cin>>p>>t;
        str.SetVal(p);
        int flag=str.KMPFindSubstr(t,1);
        cout<<flag<<endl;
    }
    return 0;
}
*/
/*
//C
#include <iostream>
#include <string>
using namespace std;

#define max 100
string matched_Prefix_Postfix(string str)
{
    int len=str.length();
    string s1[max];
    string s2[max];
    for(int i=0;i<len-1;i++)
    {
        s1[i]=str.substr(0,len-i-1);
        s2[i]=str.substr(1+i,len-i-1);
        //cout<<s1[i]<<' '<<endl;
        //cout<<s2[i]<<' '<<endl;
    }
    for(int i=0;i<len-1;i++)
    {
        if(s1[i]==s2[i])
        {
            return s1[i];
        }
    }
    return "empty";
}
int main()
{
    int T;
    cin>>T;
    string str;
    while(T--)
    {
        cin>>str;
        cout<<matched_Prefix_Postfix(str)<<endl;
    }
    return 0;
}
*/
/*
//B
#include <iostream>
#include <string>

using namespace std;

class myString
{
private:
    string mainstr;
    int size;

    void GetNext(string p,int next[])
    {
        next[0]=-1;
        for(int i=1; i<p.length();i++)
        {
            int j=next[i-1];
            while(p[i-1]!=p[j] && j >= 0)
                j = next[j];
            if(p[i-1] == p[j])
                next[i] = j+1;
            else
                next[i] = 0;
        }
    }
    int KMPFind(string p,int pos,int next[])
    {
        int n, m;
        m = p.length();
        GetNext(p, next);
        for (int i = pos-1, q = 0; i < size; i++)
        {
            while (q > 0 && p[q] != mainstr[i])
                q = next[q - 1];
            if(q==-1)
            {
                q=0;
            }
            if (p[q] == mainstr[i])
                q++;
            if (q == m)
            {
                return (i-m+2);
            }
        }
        return 0;
    }

public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p,int pos);
};

myString::myString()
{
    size=0;
    mainstr="";
}
myString::~myString()
{
    size=0;
    mainstr="";
}

void myString::SetVal(string sp)
{
    mainstr="";
    mainstr.assign(sp);
    size=mainstr.length();
}

int myString::KMPFindSubstr(string p,int pos)
{
    int i;
    int L=p.length();
    int *next=new int[L];
    GetNext(p,next);
    int v=-1;
    v=KMPFind(p,pos,next);

    delete []next;

    return v;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        myString str;
        string p,t,l;
        cin>>p>>t>>l;
        str.SetVal(p);
        int flag=str.KMPFindSubstr(t,1);
        cout<<p<<endl;
        if(flag)
        {
            for(int i=0;i<flag-1;i++)
            {
                cout<<p[i];
            }
            cout<<l;
            for(int i=flag+t.length()-1;i<p.length();i++)
            {
                cout<<p[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<p<<endl;
        }
    }
    return 0;
}
 */
/*
//D
#include <iostream>
#include <string>

using namespace std;


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string a,b,c,d;
        cin>>a;
        int max=-1;
        int len=(int)a.length();
        len=len/2;
        do
        {
            for(int i=0;i<a.length()-len;i++)
            {
                //cout<<i<<endl;
                //cout<<len<<endl;
                d=a.substr(0,i);
                b=a.substr(i,len);
                c=a.substr(i+len,a.length()-i-len);
                //cout<<d<<' '<<b<<' '<<c<<endl;
                if(c.find(b)!=-1&&len>max)
                {
                    max=len;
                }
                else if(d.find(b)!=-1&&len>max)
                {
                    max=len;
                }
            }
            if(max==len) break;
        }while(len--);
        if(max==0) max=-1;
        cout<<max<<endl;
    }
    return 0;
}
*/

//20181022
/*
//A
#include<bits/stdc++.h>
using namespace std;
void show(int pos,int *arr,int n){
    if(pos >= n)
        return;
    else{
        if(arr[pos] != 0)
            cout<<arr[pos]<<" ";
        show(2*pos+1,arr,n);
        show(2*pos+2,arr,n);
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1;
        cin>>n1;
        int *a = new int [n1];
        for(int i = 0; i < n1; i++){
            cin>>a[i];
        }
        show(0,a,n1);
        cout<<endl;
    }
    return 0;
}
 */
/*
//B
#include<iostream>
#include<string>
using namespace std;

class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode(){}
};
class BiTree{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
};
void BiTree::CreateTree(string TreeArray){
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}
BiTreeNode* BiTree::CreateBiTree(){
    BiTreeNode *T;
    char ch;
    ch=strTree[pos++];
    if(ch=='0')
        T=NULL;
    else{
        T=new BiTreeNode();
        T->data=ch;
        T->LeftChild= CreateBiTree();
        T->RightChild= CreateBiTree();
    }
    return T;
}
void BiTree::PreOrder(){
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        cout<<t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    return;
}
void BiTree::InOrder(){
    InOrder(Root);
}
void BiTree::InOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        InOrder(t->LeftChild);
        cout<<t->data;
        InOrder(t->RightChild);
    }
    return;
}
void BiTree::PostOrder(){
    PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data;
    }
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        string s;
        cin>>s;
        BiTree b1;
        b1.CreateTree(s);
        b1.PreOrder();
        cout<<endl;
        b1.InOrder();
        cout<<endl;
        b1.PostOrder();
        cout<<endl;
    }
    return 0;
}
 */
/*
//c
#include<iostream>
#include<string>
using namespace std;
class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode();
};
class BiTree{
private:
    BiTreeNode *Root;
    int pos;
    int leaves;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);
    void countLeaves(BiTreeNode *t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void countLeaves();
    int getLeaves(){
        return leaves;
    }
};
void BiTree::CreateTree(string TreeArray){
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
    leaves = 0;
}
BiTreeNode* BiTree::CreateBiTree(){
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if(ch =='0')
        T = NULL;
    else{
        T = new BiTreeNode();
        T->data = ch;
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
    }
    return T;
}
void BiTree::PreOrder(){
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode *t){
    if(t == NULL){
        return;
    }
    else{
        cout<<t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    return;
}
void BiTree::InOrder(){
    InOrder(Root);
}
void BiTree::InOrder(BiTreeNode *t){
    if(t == NULL)
        return;
    else{
        InOrder(t->LeftChild);
        cout<<t->data;
        InOrder(t->RightChild);
    }
    return;
}
void BiTree::PostOrder(){
    PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode *t){
    if(t == NULL)
        return;
    else{
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data;
    }
    return;
}
void BiTree::countLeaves(){
    countLeaves(Root);
}
void BiTree::countLeaves(BiTreeNode *t){
    if(t == NULL)
        return;
    else if(t->LeftChild != NULL||t->RightChild != NULL){
        countLeaves(t->LeftChild);
        countLeaves(t->RightChild);
    }
    else{
        leaves++;
    }
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i < t; i++)
    {
        string s;
        cin>>s;
        BiTree b1;
        b1.CreateTree(s);
        b1.countLeaves();
        cout<<b1.getLeaves()<<endl;
    }
    return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
int sum=0;
class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode(){}
};

class BiTree{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
};

void BiTree::CreateTree(string TreeArray)
{
    pos=0;
    strTree.assign(TreeArray);
    Root=CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree()
{
    BiTreeNode* T;
    char ch;
    ch=strTree[pos++];
    if(ch=='0')
        T=NULL;
    else
    {
        T=new BiTreeNode();
        T->data=ch;
        T->LeftChild=CreateBiTree();
        T->RightChild=CreateBiTree();
    }
    return T;
}

void BiTree::PreOrder()
{
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode* t)
{
    if(t)
    {
        if(t->LeftChild){
            PreOrder(t->LeftChild);
        }
        else if(!t->RightChild)  sum++;
        if(t->RightChild&&t->RightChild->LeftChild) PreOrder(t->RightChild->LeftChild);
    }
}

void BiTree::InOrder()
{
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode* t)
{
    if(t)
    {
        InOrder(t->LeftChild);
        cout<<t->data;
        InOrder(t->RightChild);
    }
}

void BiTree::PostOrder()
{
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode*t)
{
    if(t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data;
    }
}


int main()
{
    int t;
    string str;
    BiTree BT;
    BiTreeNode BTN;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>str;
        BT.CreateTree(str);
        BT.PreOrder();
        cout<<sum<<endl;
    }
    return 0;
}
*/
/*
//IPv6
#include<stdio.h>
#include<string.h>

int f1(char str[],int l,int pk,int pi)
{
    int n=40;
    int i,j,flag=0;
    str[39-l-pi]=':';
    while(str[0]=='0'&&str[1]!=':')
    {
        for(i=0; i<n-1; i++)
            str[i]=str[i+1];
        flag++;
    }
    for(i=0; i<n; i++)
    {
        if((str[i]==':'||str[i]=='*'||str[i]=='#')&&str[i+1]=='0'&&str[i+2]!=':')
        {
            str[i+1]='*';
        }
    }
    return (flag);
}
int main()
{
    int t;
    int flag;
    int n=39;
    int lp,po,pk;
    int i1,j,k,p,f,r;
    scanf("%d",&t);
    while(t--)
    {
        char str1[40]={'!'};
        pk=0;
        po=0;
        f=0;
        k=0;
        int got=0;
        int pi=0;
        int l=0;
        lp=0;
        char str[39]= {0};
        char x[39]= {'@'};
        int b[10]={0};
        scanf("%s",str);
        strcpy(str1,str);
        for(i1=0; i1<n; i1++)
        {
            if(str[i1]=='0'&&str[i1+1]=='0'&&str[i1+2]=='0'&&str[i1+3]=='0')
            {
                b[k]=i1;
                k++;
            }
        }
        //printf("%d\n",k);
        for(p=0; p<k; p++)
        {
            if(b[p+1]-b[p]!=5)
            {
                pk=(b[p]-b[0])/5+1;
                for(int o=b[0]; o<b[p]+4; o++)
                {

                    if(str[o]=='0')
                    {	str[o]='$';//str[o+(b[p]+4-b[0])];
                        l++;}
                }
                if(b[p]==b[0]&&b[0]==0)
                {
                    str[0]=':';
                    str[1]='$';
                    str[2]='$';
                    str[3]='$';
                    pi=3;
                    l=0;
                }
                if(b[p]==b[0]&&b[0]==35)
                {
                    str[36]=':';
                    str[37]='$';
                    str[38]='$';
                    str[39]='$';
                    pi=3;
                    l=0;
                }
                int w=0;
                for(int u=0; u<39; u++)
                {
                    if(str[u]!='$')
                    {
                        x[w]=str[u];
                        w++;
                    }
                }
                goto A;
            }
        }
        A:
        while(po<39-l+pk)
        {
            if(x[po]!=':')
                po++;
            else if(x[po]==':')
            {
                if(x[po+1]!=':')
                    lp=1;
                else if(x[po+1]==':'&&x[po+2]!=':')
                    lp=2;
                else if(x[po+1]==':'&&x[po+2]==':')
                {
                    for(r=po+2; r<39-l+pk; r++)
                    {
                        if(x[r]==':')
                            x[r]='#';
                        else
                            break;
                    }
                    lp=r;
                }
            }
            po=po+lp;
        }
        if(k!=0){
            flag=f1(x,l,pk,pi);
            for(int i=0;i<39-l-flag-pi; i++)
            {
                if(x[i]!='*'&&x[i]!='#')
                    printf("%c",x[i]);
            }
        }

        if(k==0)
        {
            l=0;
            pk=1;
            flag=f1(str1,l,pk,pi);
            for(int i=0; i<39-flag; i++)
            {
                if(str1[i]!='*'&&str1[i]!='#')
                    printf("%c",str1[i]);
            }
        }
        printf("\n");
//	printf("\n\npi=%d\npk=%d\nflag=%d\nl=%d\nb=%d\n",pi,pk,flag,l,b[0]);
        //	f2(str);
        //	printf("%s\n",str);
    }
    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MaxW = 9999;

class HuffNode{
public:
    int weight;
    int parent;
    int leftchild;
    int rightchild;
};

class HuffMan{
private:
    void MakeTree();
    void SelectMin(int pos, int *s1, int *s2);

public:
    int len;
    int lnum;
    HuffNode *huffTree;
    string * huffCode;
    void MakeTree(int n, int wt[]);
    void Coding();
    void Destroy();
    int Decode(const string codestr, char txtstr[]);
};

void HuffMan::MakeTree(int n, int *wt) {
    int i;
    lnum = n;
    len = 2*n-1;
    huffTree = new HuffNode[2*n];
    huffCode = new string[lnum+1];

    for(i=1;i<=n;i++){
        huffTree[i].weight = wt[i-1];
    }
    for(i=1;i<=len;i++){
        if(i>n)
            huffTree[i].weight=0;
            huffTree[i].parent=0;
            huffTree[i].leftchild=0;
            huffTree[i].rightchild=0;
    }
    MakeTree();
}

void HuffMan::SelectMin(int pos, int *s1, int *s2) {
    int w1,w2,i;
    w1 = w2 = MaxW;
    *s1 = *s2 = 0;
    for(i=1;i<=pos;i++){
        if(huffTree[i].weight<w1 && huffTree[i].parent==0){
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else if(huffTree[i].weight<w2 && huffTree[i].parent==0){
            w2 =huffTree[i].weight;
            *s2 = i;
        }
    }
}

void HuffMan::MakeTree() {
    int i,s1,s2;
    for(i=lnum+1;i<=len;i++){
        SelectMin(i-1,&s1,&s2);
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}

void HuffMan::Destroy() {
    len = 0;
    lnum = 0;
    delete []huffTree;
    delete []huffCode;
}

void HuffMan::Coding() {
    char *cd;
    int i,c,f,start;

    cd = new char[lnum];
    cd[lnum-1] = '\0';
    for(i=1;i<=lnum;++i){
        start = lnum-1;
        for(c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[f].parent){
            if(huffTree[f].leftchild==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        huffCode[i].assign(&cd[start]);
    }
    delete []cd;
}

int HuffMan::Decode(const string codestr, char txtstr[]) {
    int i,k,c;
    char ch;
    c = len;
    k = 0;
    for(i=0;i<codestr.length();i++){
        ch = codestr[i];
        if(ch=='0')
            c = huffTree[c].leftchild;
        else
            if(ch=='1')
                c = huffTree[c].rightchild;
            else
                return -1;
        if (hufftree[c].leftchild == 0 && huffTree[c].rightchild == 0){
            txtstr[k] = huffTree[c].txt;
            k++;
            c = len;
        } else
            ch = '\0';
    }
    if(ch=='\0')
        return -1;
    else
        txtstr[k] = '\0';
    return 1;
}















#include <iostream>
#include <string>
#include<queue>
using namespace std;
class treeNode{
public:
    char data;
    int weight;
    int parent,lchild,rchild;
};
void selectMin(treeNode HN[],int n,int &s1,int &s2){
    for(int i=0;i<n;i++){
        if(HN[i].parent==-1){//初始化s1,遍历未组成树的节点
            s1=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(HN[i].parent==-1 && HN[s1].weight>HN[i].weight)
            s1=i;
    }
    for(int i=0;i<n;i++){
        if(HN[i].parent==-1 &&i!=s1){//初始化s1的双亲
            s2=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(HN[i].parent==-1 && HN[s2].weight>HN[i].weight &&i!=s1)
            s2=i;
    }
}
void HuffmanTree(treeNode HN[],int w[],int n,char ch[]){
    for(int i=0;i<2*n-1;i++){//节点初始化
        HN[i].parent=-1;
        HN[i].lchild=-1;
        HN[i].rchild=-1;
        HN[i].data='0';
    }
    for(int i=0;i<n;i++){
        HN[i].weight=w[i];//赋予权值
        HN[i].data=ch[i];
    }
    for(int i=n;i<2*n-1;i++){
        int i1,i2;
        selectMin(HN,i,i1,i2);//查找最小的权值节点
        HN[i1].parent=i;//i1,i2合并
        HN[i2].parent=i;
        HN[i].lchild=i1;
        HN[i].rchild=i2;
        HN[i].weight=HN[i1].weight+HN[i2].weight;
    }
}
void getCode(treeNode HN[],char *ch[20],int n){
    int k=0;
    for(int j=0,t=0;j<n;j++)
    {
        k=0;
        t=j;
        while(true){
            if(HN[t].parent!=-1){
                if(HN[HN[t].parent].lchild==t) {//验证是否为左节点
                    ch[j][k]='0';
                    k++;
                }
                if(HN[HN[t].parent].rchild==t){//验证是否为右节点
                    ch[j][k]='1';
                    k++;
                }
                t=HN[t].parent;
            }
            else{
                ch[j][k]='\0';
                break;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char *ch1=new char[n];
        for(int i=0;i<n;i++)
            cin>>ch1[i];
        int *w=new int[n];
        for(int i=0;i<n;i++)
            cin>>w[i];
        treeNode *t1=new treeNode[2*n-1];
        HuffmanTree(t1,w,n,ch1);
        char **ch2=new char*[n];
        for(int i=0;i<n;i++)
            ch2[i]=new char[20];
        getCode(t1,ch2,n);
        for(int i=0;i<n;i++){
            cout<<t1[i].data<<" :";
            int a=0;
            while(1){//找到终止符位置，反向输出
                if(ch2[i][a]!='\0')
                    a++;
                else
                    break;
            }
            for(int j=a-1;j>=0;j--){
                cout<<ch2[i][j];
            }
            cout<<endl;
        }
        //编码
        string s1;
        cin>>s1;
        for(int i=0;i<s1.length();i++){
            char ch=s1[i];
            //cout<<ch<<endl;
            for(int j=0;j<n;j++){
                if(ch==t1[j].data){
                    //cout<<t1[i].data<<" :";
                    int a=0;
                    while(1){//找到终止符位置，反向输出
                        if(ch2[j][a]!='\0')
                            a++;
                        else
                            break;
                    }
                    for(int k=a-1;k>=0;k--){
                        cout<<ch2[j][k];
                    }
                }
            }
        }
        cout<<endl;
        //解码
        string s2;
        cin>>s2;
        int t=2*n-2,j;
        queue<char> q_ch;
        for(j=0;j<s2.length();j++){
            if(s2[j]=='0')
                t=t1[t].lchild;//走向左孩子；
            else
                t=t1[t].rchild;//走向右孩子；
            if(t1[t].lchild==-1) {
                q_ch.push(t1[t].data);
                t=2*n-2;
            }
        }
        if(t!=2*n-2)
            cout<<"error!"<<endl;
        else
        {
            while(!q_ch.empty()){
                cout<<q_ch.front();
                q_ch.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
*/

/*
//B
#include<iostream>
#include<string>
#include <queue>
#include <math.h>
using namespace std;
class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode();
};
class BiTree{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    int isFather;
    int leftLeaves;
    int i;
    int sum;
    char deepestL,deepestR;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void PreOrder(BiTreeNode *t,int d,int &count);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);
    void levelTraverse(BiTreeNode *t);
    int PreLeave(BiTreeNode *t,int a[],int depth);
    void PreFather(BiTreeNode *t);
    int getHeight(BiTreeNode *t);
    void getLeftChild(BiTreeNode *t);
    int getMaxDistance(BiTreeNode *t);
public:
    BiTree(){};
    ~BiTree(){};
    void CreateTree(string TreeArray);
    void PreOrder();
    void PreOrder(int d,int &count);
    void InOrder();
    void PostOrder();
    void levelTraverse();
    int PreLeave(int a[]);
    void PreFather();
    int getHeight();
    void getLeftChild();
    int getMaxDistance();
    int getLeftLeaves(){
        return leftLeaves;
    }
};
void BiTree::CreateTree(string TreeArray){
    pos=0;
    strTree.assign(TreeArray);
    Root= CreateBiTree();
    leftLeaves=0;
    i=0;
    sum=0;
}
BiTreeNode* BiTree::CreateBiTree(){
    BiTreeNode *T;
    char ch;
    ch=strTree[pos++];
    if(ch=='0'||ch=='#')
        T=NULL;
    else{
        T=new BiTreeNode();
        T->data=ch;
        T->LeftChild= CreateBiTree();
        T->RightChild= CreateBiTree();
    }
    return T;
}
void BiTree::levelTraverse() {
    levelTraverse(Root);
}
void BiTree::levelTraverse(BiTreeNode *t) {
    if(t==NULL){
        return;
    }
    queue<BiTreeNode*> q;
    q.push(t);
    while(!q.empty()){
        BiTreeNode *p=q.front();
        q.pop();
        cout<<p->data;
        if(p->LeftChild!=NULL){
            q.push(p->LeftChild);
        }
        if(p->RightChild!=NULL){
            q.push(p->RightChild);
        }
    }
}
int BiTree::PreLeave(int a[]){
    return PreLeave(Root,a,-1);
}
int BiTree::PreLeave(BiTreeNode *t,int a[],int level){
    if(t==NULL)
        return 0;
    else{
        level++;
        if(t->LeftChild==NULL && t->RightChild==NULL && t->data>='A'&&t->data<='Z'){
            //cout<<t->data<<" ";
            sum+=a[i]*level;
            i++;
        }
        PreLeave(t->LeftChild,a,level);
        PreLeave(t->RightChild,a,level);
    }
    return sum;
}
void BiTree::PreFather(){
    PreFather(Root);
}
void BiTree::PreFather(BiTreeNode *t){
    if(t==NULL)
        return;
    else if(t->LeftChild!=NULL || t->RightChild!=NULL) {
        PreFather(t->LeftChild);
        if (isFather == 1) {
            cout << t->data << " ";
            isFather = 0;
        }
        PreFather(t->RightChild);
        if (isFather == 1) {
            cout << t->data << " ";
            isFather = 0;
        }
    }
    else{
        isFather=1;
    }
}
int BiTree::getHeight() {
    return getHeight(Root);
}
int BiTree::getHeight(BiTreeNode *t) {
    if(t!=NULL){
        return max(getHeight(t->LeftChild),getHeight(t->RightChild))+1;
    }
}
void BiTree::PreOrder(){
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        cout<<t->data<<" ";
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
    return;
}
void BiTree::PreOrder(int d,int &count){
    PreOrder(Root,d,count);
}
void BiTree::PreOrder(BiTreeNode *t,int d,int &count){
    if(t==NULL)
        return;
    else{
        count++;
        if(count==d)
            if(t->LeftChild==NULL && t->RightChild==NULL)
                cout<<t->data;
            else
                count--;
        PreOrder(t->LeftChild,d,count);
        PreOrder(t->RightChild,d,count);
    }
    return;
}

void BiTree::InOrder(){
    InOrder(Root);
}
void BiTree::InOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        InOrder(t->LeftChild);
        cout<<t->data<<" ";
        InOrder(t->RightChild);
    }
    return;
}
void BiTree::PostOrder(){
    PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data<<" ";
    }
    return;
}
void BiTree::getLeftChild(){
    getLeftChild(Root);
}

void BiTree::getLeftChild(BiTreeNode *t){
    if(t==NULL)
        return;
    else{
        if(t->LeftChild!=NULL && t->LeftChild->LeftChild==NULL &&t->LeftChild->RightChild==NULL){
            leftLeaves++;
        }
        getLeftChild(t->LeftChild);
        getLeftChild(t->RightChild);
    }
    return;
}
int BiTree::getMaxDistance() {
    if(Root->RightChild==NULL && Root->LeftChild==NULL)//单节点
        cout<<"0:"<<endl;
    else if(Root->LeftChild==NULL && Root->RightChild!=NULL){
        int maxDistance,d1,d2,c1=0;
        d1=getMaxDistance(Root->RightChild->LeftChild);
        d2=getMaxDistance(Root->RightChild->RightChild);
        maxDistance=d1+d2;
        cout<<maxDistance<<":";
        PreOrder(Root->RightChild->LeftChild,d1,c1);
        c1=0;
        cout<<" ";
        PreOrder(Root->RightChild->RightChild,d1,c1);
        cout<<endl;
        return 1;
    }//左子树为空，遍历右子树
    else if(Root->LeftChild!=NULL && Root->RightChild==NULL){
        int maxDistance,d1,d2,c1=0;
        d1=getMaxDistance(Root->LeftChild->LeftChild);
        d2=getMaxDistance(Root->LeftChild->RightChild);
        maxDistance=d1+d2;
        cout<<maxDistance<<":";
        PreOrder(Root->LeftChild->LeftChild,d1,c1);
        c1=0;
        cout<<" ";
        PreOrder(Root->LeftChild->RightChild,d1,c1);
        cout<<endl;
        return 1;
    }//右子树为空，遍历左子树
    else{//左右均不为空
        int maxDistance,d1,d2,d3;
        int d11,d12,d21,d22,d31,d32,c1=0;
        d11=getMaxDistance(Root->RightChild->LeftChild);
        d12=getMaxDistance(Root->RightChild->RightChild);
        d1=d11+d12;
        d21=getMaxDistance(Root->LeftChild->LeftChild);
        d22=getMaxDistance(Root->LeftChild->RightChild);
        d2=d21+d22;
        d31=getMaxDistance(Root->LeftChild);
        d32=getMaxDistance(Root->RightChild);
        d3=d31+d32;//左加右
        if(d1>d2){
            if(d1>d3){
                maxDistance=d1;
                cout<<maxDistance<<":";
                PreOrder(Root->RightChild->LeftChild,d11,c1);
                c1=0;
                cout<<" ";
                PreOrder(Root->RightChild->RightChild,d12,c1);
                cout<<endl;
            }
            else{
                maxDistance=d3;
                cout<<maxDistance<<":";
                PreOrder(Root->LeftChild,d31,c1);
                c1=0;
                cout<<" ";
                PreOrder(Root->RightChild,d32,c1);
                cout<<endl;
            }
        }
        else{
            if(d2>d3){
                maxDistance=d2;
                cout<<maxDistance<<":";
                PreOrder(Root->LeftChild->LeftChild,d21,c1);
                c1=0;
                cout<<" ";
                PreOrder(Root->LeftChild->RightChild,d22,c1);
                cout<<endl;
            }
            else{
                maxDistance=d3;
                cout<<maxDistance<<":";
                PreOrder(Root->LeftChild,d31,c1);
                c1=0;
                cout<<" ";
                PreOrder(Root->RightChild,d32,c1);
                cout<<endl;
            }
        }
        return maxDistance;
    }//左右均都不为空子树

}
int BiTree::getMaxDistance(BiTreeNode *t) {
    if(t!=NULL){
        return max(getMaxDistance(t->LeftChild),getMaxDistance(t->RightChild))+1;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        BiTree b1;
        b1.CreateTree(s);
        //b1.PreOrder();
        int a[100],n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<b1.PreLeave(a)<<endl;
    }
    return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;

class BiTreeNode{
public:
    char data;
    int weight;
    BiTreeNode *L;
    BiTreeNode *R;
    BiTreeNode():L(NULL),R(NULL){}
    ~BiTreeNode(){}
};

class BiTree{
private:
    BiTreeNode *Root;
    int pos1,pos2,pos3,n;
    string strTree;
    int wt[50];
    BiTreeNode* CreateBiTree(){
        BiTreeNode *T;
        char ch;
        ch=strTree[pos1++];
        if(ch=='0')
            T=NULL;
        else{
            T=new BiTreeNode();
            T->data=ch;
            T->weight=wt[pos2++];
            T->L=CreateBiTree();
            T->R=CreateBiTree();
        }
        return T;
    }
    void destroy(BiTreeNode* t){
        if(t){
            destroy(t->L);
            destroy(t->R);
            delete t;
        }
    }
    void getWP(BiTreeNode* t,int wp[],int wp1){
        if(t){
            wp1+=t->weight;
            if(!t->L && !t->R)
                wp[pos3++]=wp1;
            getWP(t->L,wp,wp1);
            getWP(t->R,wp,wp1);
        }
    }
public:
    BiTree(){}
    ~BiTree(){destroy(Root);}
    void CreatTree(int n1,string TreeArray,int wt1[]){
        int i;
        pos1=pos2=0;
        n=n1;
        strTree.assign(TreeArray);
        for(i=0;i<n;i++)
            wt[i]=wt1[i];
        Root=CreateBiTree();
    }
    int getMaxWP(){
        int i,wp[50],maxwp,wp1=0;
        pos3=0;
        getWP(Root,wp,wp1);
        maxwp=wp[0];
        for(i=1;i<pos3;i++)
            if(maxwp<wp[i])
                maxwp=wp[i];
        return maxwp;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,wt[50];
        string str;
        BiTree bitree;

        cin>>str;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>wt[i];

        bitree.CreatTree(n,str,wt);
        cout<<bitree.getMaxWP()<<endl;
    }
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int m,i,l[1000],w[1000];
    long b[1000];
    scanf("%d",&m);

    for(i=0;i<=m-1;i++){
        scanf("%d",&l[i]);
        scanf("%d",&w[i]);
        scanf("%ld",&b[i]);



    }
}
 */
/*
#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        char typeOfGraph;
        cin>>typeOfGraph;
        int n;//n阶
        cin>>n;
        int **ajmax=new int *[n];
        for(int i=0;i<n;i++)
            ajmax[i]=new int[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ajmax[i][j]=0;
        string node[n];
        for(int i=0;i<n;i++)
            cin>>node[i];
        int line;
        cin>>line;
        while(line--){
            string node1,node2;
            int l1,l2;
            cin>>node1>>node2;
            for(int i=0;i<n;i++)
                if(node1==node[i]){
                    l1=i;
                    break;
                }
            for(int i=0;i<n;i++)
                if(node2==node[i]){
                    l2=i;
                    break;
                }
            ajmax[l1][l2]=1;
            if(typeOfGraph=='U')
                ajmax[l2][l1]=1;
        }
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++) {
                if(j!=n-1)
                    cout<<ajmax[i][j]<<" ";
                else
                    cout<<ajmax[i][n-1];
            }
            cout<<endl;
        }
        if(typeOfGraph=='D'){
            for(int i=0;i<n;i++){
                cout<<node[i];
                int count=0;
                for(int j=0;j<n;j++){//出度
                    if(ajmax[i][j]==1)
                        count++;
                }
                int count1=count;
                int count2;
                count=0;
                for(int j=0;j<n;j++){//入度
                    if(ajmax[j][i]==1)
                        count++;
                }
                count2=count;
                if((count1+count2)!=0){
                    cout<<": "<<count1;
                    cout<<' '<<count2;
                    cout<<' '<<count2+count1<<endl;
                }
            }
        }
        else{
            for(int i=0;i<n;i++) {
                cout << node[i];
                int count = 0;
                for (int j = 0; j < n; j++) {//出度
                    if (ajmax[i][j] == 1)
                        count++;
                }
                if(count==0)
                    break;
                else
                    cout<<": "<<count<<endl;
            }
        }
    }
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
class edgeNode{
public:
    int adjvex;
    edgeNode *next;
    edgeNode():next(NULL){}
    ~edgeNode(){}
};
class graph{
    edgeNode **head;
    int nodeNum,arcNum;
    string *headInfo;
public:
    graph(int nN,int aN){
        nodeNum=nN;
        arcNum=aN;
        head=new edgeNode*[nodeNum];
        headInfo=new string[nodeNum];
    }
    void create(){
        int l1,l2;
        string info,h,t;
        for(int i=0;i<nodeNum;i++){//初始化头节点
            cin>>info;
            head[i]=new edgeNode();
            head[i]->adjvex=i;
            headInfo[i]=info;
        }
        for(int i=0;i<arcNum;i++){
            cin>>h>>t;
            for(int j=0;j<nodeNum;j++){
                if(h==headInfo[j])
                    l1=j;
                if(t==headInfo[j])
                    l2=j;
            }
            edgeNode *node=new edgeNode();
            node->adjvex=l2;
            edgeNode *h1=head[l1];
            while(h1!=NULL){
                if(h1->next==NULL){
                    h1->next=node;
                    break;
                }
                h1=h1->next;
            }
        }
    }
    void print(){
        for(int i=0;i<nodeNum;i++){
            cout<<i<<" ";
            cout<<headInfo[i]<<'-';
            edgeNode *p=head[i]->next;
            while(p!=NULL){
                cout<<p->adjvex<<'-';
                p=p->next;
            }
            cout<<"^"<<endl;
        }
    }
};
int main() {
    int t;
    int verNum,arcNum;
    cin>>t;
    while(t--){
        cin>>verNum>>arcNum;
        graph g1(verNum,arcNum);
        g1.create();
        g1.print();
    }
    return 0;
}
*/

//20181112
/*
//A
#include <iostream>
#include <cstring>
using namespace std;
const int maxx = 100;
int n;
int array[maxx][maxx];

class Kru{
public:
    int bef;
    int aft;
    int data;
    int flag;
    Kru(){
        bef = -1;
        aft = -1;
        data = 0;
        flag = 0;
    }
};
void prim(string str[], int n, int po){
    int index = po;
    int sum = 0;

    int visited[n + 5];
    int dist[n + 5];
    int pos[n + 5];
    memset(visited, false, sizeof(visited));

    visited[index] = true;
    int bef = index;
    for(int i = 0; i < n; i++){
        dist[i] = array[index][i];
        pos[i] = index * 100 + i;
    }

    string Begin[n + 5];
    string End[n + 5];
    int Weight[n + 5];
    int r = 0;
    for(int i = 1; i < n; i++){
        int minn = 10000;

        for(int j = 0; j < n; j ++){
            if(!visited[j] && dist[j] < minn){
                minn = dist[j];

                index = j;
            }
        }
        visited[index] = true;
        Begin[r] = str[pos[index]/100];
        End[r] = str[index];
        Weight[r++] = dist[index];
        sum += dist[index];

        for(int j = 0; j < n; j ++){
            if(!visited[j]&&dist[j]> array[index][j]){
                dist[j] = array[index][j];
                pos[j] = index * 100 + j;
            }
        }
    }

    cout<<sum<<endl<<"prim:"<<endl;

    for(int i = 0; i < r; i ++){
        cout<<Begin[i]<<' '<<End[i]<<" "<<Weight[i]<<endl;
    }
}

int FindMin(Kru kr[], int in){
    int minn = 10000;
    int index = 0;
    int flag = 0;
    for(int i = 0; i < in; i ++){
        if(!kr[i].flag && kr[i].data < minn){
            minn = kr[i].data;
            index = i;
            flag = 1;
        }
    }
    return index;
}
int find(string str[], int n, string st){
    for(int i = 0; i < n; i ++)
        if(str[i] == st)
            return i;
}
void change(int visit[], int n, int a, int b){
    for(int i = 0; i < n; i ++)
        if(visit[i] == a)
            visit[i] = b;

}
void kruskal(string str[], int in, int n, Kru kr[]){
    int visit[n + 5];
    for(int i = 0; i < n; i ++)
        visit[i] = i;
    cout<<"kruskal:"<<endl;
    int k = 0;
    while(true){
        int minn = FindMin(kr, in);

        kr[minn].flag= 1;
        int t1= kr[minn].bef;
        int t2= kr[minn].aft;

        if(visit[t1] != visit[t2]){

            if(t1 > t2){
                int t = t1;
                t1 = t2;
                t2 = t;
            }
            cout<<str[t1]<<" "<<str[t2]<<" "<<kr[minn].data<<endl;
            change(visit, n, visit[t1], visit[t2]);
        }
        k++;
        if(k >= in)
            break;
    }

}

int main(){

    cin>>n;

    string str[100];

    for(int i = 0; i < n; i ++)
        cin>>str[i];

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            array[i][j] = 10000;
    int in;
    cin>>in;
    Kru kr[in+5];
    for(int j = 0; j < in; j ++){
        string s1;
        string s2;
        int weight;
        cin>>s1>>s2>>weight;

        //prim
        int t1= find(str, n, s1);
        int t2= find(str, n, s2);
        array[t1][t2]= weight;
        array[t2][t1]= weight;

        //krushal
        kr[j].bef= t1;
        kr[j].aft= t2;
        kr[j].data= weight;
        kr[j].flag= 0;
    }


    string s;
    cin>>s;
    int d = find(str, n, s);
    prim(str, n, d) ;
    kruskal(str, in, n, kr);

    return 0;
}
*/
/*
7
0 1 2 3 4 5 6
9
0 1 28
0 5 10
1 2 16
1 6 14
3 2 12
3 6 18
4 6 24
4 5 25
3 4 22
6
*/


/*
#include <bits/stdc++.h>
#define INFINITY 65536
#define MAXVEX 100

void MiniSpanTree_Prim(MGragph G){
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    lowcost[0] = 0;
    adjvex[0] = 0;
    for(i = 0; i < G.numVertexes; i++){
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    for(i = 1; i < G.numVertexes; i++){
        min = INFINITY;
        j = 1;k = 0;
        while(j < G.numVertexes){
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k] = 0;
        for(j = 1; j < G.numVertexes; j++){
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j]){
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}

int main(){
    int
}
*/
/*
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MaxLen = 110;

class Map {
private:
    bool Visit[MaxLen];
    int Matrix[MaxLen][MaxLen];
    int Vexnum;

    bool BFS(int q, int p);

public:
    void SetMatrix(int vnum, int **mx);

    bool BFSTraverse(int q, int p);
};

bool Map::BFSTraverse(int q, int p) {
    Visit[q] = true;
    bool res = BFS(q, p);
    for (int i = 0; i < Vexnum; i++)        //每次调用完BFS后要将Visit重置，方便下一次使用
        Visit[i] = false;
    return res;
}

bool Map::BFS(int q, int p) {
    if (Matrix[q][p] == 1)             //如果可以判断出2个结点相连，就直接返回1表示找到
        return 1;
    queue<int> Q;
    for (int i = 0; i < Vexnum; i++)     //如果无法判断，则将此结点上所连的结点入队，继续递归BFS
    {
        if (Matrix[q][i] != 0 && !Visit[i]) {
            Visit[i] = true;
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        if (BFS(Q.front(), p))        //但凡有一个结点可以连通，都代表可以找到，所以直接返回1
            return 1;
        Q.pop();
    }
    return 0;                //都没连通的话，就是找不到了，返回0
}

void Map::SetMatrix(int vnum, int **mx)        //初始化图
{
    for (int i = 0; i < Vexnum; i++)
        Visit[i] = false;
    int i, j;
    Vexnum = vnum;
    for (i = 0; i < MaxLen; i++)
        for (j = 0; j < MaxLen; j++)
            Matrix[i][j] = 0;
    for (i = 0; i < Vexnum; i++)
        for (j = 0; j < Vexnum; j++)
            Matrix[i][j] = mx[i][j];
}

int distance(int x1, int y1, int x2, int y2) {
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void test(int n) {
    int d;
    cin >> d;
    struct P {
        int x;
        int y;
    } point[n];
    for (int i = 0; i < n; i++)                //输入每个点的坐标
        cin >> point[i].x >> point[i].y;
    int **m;
    m = new int *[n];
    int *flag = new int[n];            //用一个flag数组表示计算机是否修复，初始化为0表示未修复
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;               //二维数组初始化为0，表示点和点之间不通
        }
    }
    string s1;
    int t1, t2;
    Map mmap;
    while (cin >> s1) {
        if (s1 == "O")             //如果输入的第一个字符是“O”,则更新flag数组，并更新图
        {
            cin >> t1;
            flag[t1 - 1] = 1;
            for (int j = 0; j < n; j++) {
                if (j != t1 - 1 && flag[j] == 1 &&
                    distance(point[t1 - 1].x, point[t1 - 1].y, point[j].x, point[j].y) <= d * d) {
                    m[t1 - 1][j] = 1;
                    m[j][t1 - 1] = 1;
                }
            }
        } else {                           //如果输入的是S,则调用图的BFS输出判定是否可以找到点
            cin >> t1 >> t2;
            mmap.SetMatrix(n, m);
            if (!flag[t1 - 1] || !flag[t2 - 1])
                cout << "FAIL" << endl;
            else if (mmap.BFSTraverse(t1 - 1, t2 - 1))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    test(t);
    return 0;
}
*/

//20181119
/*
//ADS图应用--最短路径
#include <iostream>

using namespace std;
const int MaxLen = 20;
const int MaxDist = 9999;

class Map {
private:
    int Matrix[MaxLen][MaxLen];
    int Vexnum;
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);

    void ShortestPath_DIJ(int v0);
};

void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen]) {
    int i, j;
    Vexnum = vnum;
    for (i = 0; i < MaxLen; i++) {
        for (j = 0; j < MaxLen; j++) {
            Matrix[i][j] = MaxDist;
        }
    }

    for (i = 0; i < Vexnum; i++) {
        for (j = 0; j < Vexnum; j++) {
            if (mx[i][j])
                Matrix[i][j] = mx[i][j];
        }
    }
}

void Map::ShortestPath_DIJ(int v0) {
    int i, j;
    int *dist = new int[Vexnum];
    bool *final = new bool[Vexnum];
    int path[MaxLen][MaxLen];
    int len[MaxLen];

    for (i = 0; i < Vexnum; i++) {
        final[i] = false;
        dist[i] = Matrix[v0][i];
    }

    for (i = 0; i < MaxLen; i++)
        for (j = 0; j < MaxLen; j++)
            path[i][j] = -1;

    for (i = 0; i < MaxLen; i++) {
        path[i][0] = v0;
        path[i][1] = i;
        len[i] = 2;
    }

    dist[v0] = 0;
    final[v0] = true;

    for (i = 0; i < Vexnum; i++) {
        if (i == v0) continue;
        int min = MaxDist;
        int v;
        for (int j = 0; j < Vexnum; j++)
            if (!final[j] && min > dist[j]) {
                min = dist[j];
                v = j;
            }
        final[v] = true;
        for (int s = 0; s < Vexnum; s++)
            if (!final[s] && (min + Matrix[v][s]) < dist[s]) {
                dist[s] = min + Matrix[v][s];
                int k;
                for (k = 0; k < len[v]; k++)
                    path[s][k] = path[v][k];
                path[s][k] = s;
                len[s] = len[v] + 1;
            }
    }

    for (i = 0; i < Vexnum; i++) {
        if (i != v0) {
            cout << v0 << "-" << i << "-" << dist[i] << "----[";
            for (j = 0; j < len[i]; j++) {
                cout << path[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }
    delete[]dist;
    delete[]final;
}

int main() {
    int i, j, k, t;
    int vnum, v0;
    int mx[MaxLen][MaxLen];
    Map myMap;
    cin >> t;
    for (k = 0; k < t; k++) {
        for (i = 0; i < MaxLen; i++) {
            for (j = 0; j < MaxLen; j++) {
                mx[i][j] = 0;
            }
        }
        cin >> vnum;
        for (i = 0; i < vnum; i++) {
            for (j = 0; j < vnum; j++) {
                cin >> mx[i][j];
            }
        }
        myMap.SetMatrix(vnum, mx);

        cin >> v0;
        myMap.ShortestPath_DIJ(v0);
    }
    return 0;
}
 */
/*
//B拓扑排序-STL版
#include <iostream>
#include <vector>
using namespace std;
class Graph {
public:
    vector<bool> isFinished;      //索引号所指示的顶点是否已处理过
    vector<vector<int> > adjMat;  //邻接矩阵
    int n;                        //顶点数 as 成员变量
public:
    void readAdjMatrix() {
        //从输入读入邻接矩阵，存入this->adjMat
        cin >> this->n;           //顶点数
        int i=0;
        for(; i<n; ++i) {
            //TODO：设置this->isFinished数组：每个顶点未曾访问过
            //提示：调用vector::push_back方法
            vector<int> row;
            int j=0;
            for(; j<n; ++j) {
                int edge;
                cin >> edge;    //读入顶点对i,j之间是否有一条边
                //TODO：将边信息增加入row
            }
            //TODO：将row增加入this->adjMat
            //提示：以row为参数，调用adjMat的push_back方法
        }
    }
    bool isZeroInDegrees(int vertexNo) {
        //判定顶点vertexNo是否没有入度
        int i=0;
        //this->adjMat[i][vertexNo] == 0
        //表示顶点i与vertexNo之间没有边相连
        for(; i<n && this->adjMat[i][vertexNo] == 0; ++i);
        //TODO：返回true if 顶点vertexNo没有入度; false [otherwise]
    }
    int select() {
        //从所有顶点中，选出一个顶点i，满足：
        //1) i没有处理过，即isFinished[i]=false
        //2) i的入度为0
        int i = 0;
        for (; i < n; ++i) {
            //TODO：若顶点i的已经处理过，则pass
            //TODO：若顶点度>0，则pass
            //提示：调用isZeroInDegrees
            //TODO: 设置顶点i已经处理过，即isFinished[i]为正确值
            //TODO: 返回i
        }
        //TODO: 返回-1, 表示未找到满足1)+2)条件的顶点
    }
    void update(int rootNo) {
        //更新顶点rootNo的出弧，即将顶点rootNo从图中断开
        int j=0;
        for(;j<n; ++j) {
            //TODO： 设置adjMat[rootNo][j]为0
        }
    }
    /////////////////////////////////////////////////////
    // 拓扑排序主算法
    void topologySort() {
        int i=0;
        for(; i<n; ++i) {  //遍历n次：即按拓扑序，依次选择（排出）n个顶点
            int root;  // 声明顶点索引号（编号）用于存放本次选出的顶点
            //TODO： 调用select方法，并将其返回值存入root
            //TODO： 若root=-1，则break;
            // root=-1表示没有可以排出的顶点
            //TODO: 以root为参数，调用update方法
            //TODO：输出当前选出的顶点root 和一个空格
        }
        //TODO：输出一行
    }
    void main() {
        readAdjMatrix();
        topologySort();
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}
 */
/*
#include<iostream>
using namespace std;
const int maxx= 200;
class Graph{
public :
    int isFinished[maxx];
    int adjMat[maxx][maxx];
    int n;
public :
    void readAdjMatrix(){

        cin>>n;
        for(int i= 0; i< n; i++)
            isFinished[i]= false;


        for(int i= 0; i< n; i++){

            for(int j= 0; j< n; j++){
                cin>>adjMat[i][j];
            }
        }
    }
    bool isZeroInDegree(int vertexNo){
        int i;
        for(i= 0; i< n&&!adjMat[i][vertexNo]; i++){
            if(i==n- 1&&!adjMat[i][vertexNo])
                return true;
        }
        return false;
    }
    int select(){
        for(int i= 0; i< n; i++){
            if(!isFinished[i]&&isZeroInDegree(i)){
                isFinished[i]= true;
                return i;
            }
        }
        return -1;
    }
    void update(int rootNo){
        for(int j= 0; j< n; j++){
            adjMat[rootNo][j]= 0;
        }
    }
    void topologySort(){
        for(int i= 0; i< n; i++){
            int root= select();
            if(root== -1)
                break;

            update(root);
            cout<<root<<" ";
        }

    }

    void graphMain(){
        readAdjMatrix();
        topologySort();
        cout<<endl;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        Graph g;
        g.graphMain();
    }

    return 0;
}

*/
/*
#include <iostream>

using namespace std;
const int MAX_VERT = 10;
struct Graphic {
    int vertNum;
    int VertValue[MAX_VERT];
    int AdjMatrix[MAX_VERT][MAX_VERT];
    bool visited[MAX_VERT];
};

void initGraphic(Graphic &G, int n) {
    G.vertNum = n;
    int i, j;
    for (i = 0; i < G.vertNum; i++) {
        for (j = 0; j < G.vertNum; j++)
            cin >> G.AdjMatrix[i][j];
    }
    for (i = 0; i < G.vertNum; i++) {
        G.VertValue[i] = i;
        G.visited[i] = false;
    }
}

void TopoSort(Graphic G) {
    int i, j, k, m;
    for (m = 0; m < G.vertNum; m++) {
        for (i = 0; i < G.vertNum; i++) {
            for (j = 0; j < G.vertNum; j++) {
                if (G.AdjMatrix[j][i])
                    break;
            }
            if (j == G.vertNum && !G.visited[i])
                break;
        }
        cout << i << " ";
        for (k = 0; k < G.vertNum; k++)
            G.AdjMatrix[i][k] = 0;
     G.visited[i] = true;
    }
    cout << endl;
}

int main() {
    int t, n, i;
    Graphic G[2];
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;

        initGraphic(G[i], n);

        TopoSort(G[i]);
    }
    return 0;
}
*/
#include <iostream>
using namespace std;

class Account
{
private  Object thisLock = new Object();
    int balance;
public Account (int initial)
    {
        balance = initial ;
    }
public void Withdraw(object amount)
    {
        {
            if (balance >=(int)amount)
            {
                Thread.Sleep (500);
                balance =balance -(int)amount;
                Console .WriteLine ("{0}操作成功。余额={1}",Thread.CurrentThread.Name,balance);
            }
            else
            {
                Console .WriteLine ("{0}操作失败。账户余额不足。余额={1}",Thread.CurrentThread.Name,balance);
            }
        }
    }
}
class Test
{
    static void Main()
    {
        Account acc = new Account(1000);
        Thread t1 = new Thread(acc.Withdraw);t1.Name="小明";
        Thread t2 = new Thread(acc.Withdraw);t2.Name="小红";
        t1.Start(600);t2.Start(600);Console.ReadKey();
    }
}

