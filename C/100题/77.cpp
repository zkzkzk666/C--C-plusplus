/*写几个函数：①输入 10 个职工的姓名和职工号；②按职工号由小到大顺序排序，姓
名顺序也随之调整；③要求输入一个职工号，用折半查找法找出该职工的姓名，从主函
数输入要查找的职工号，输出该职工姓名*/
#include<iostream>
#include<string>
using namespace std;
//职工个数
#define N 10

class Worker
{
private:
    string m_name;//职工姓名
    int m_id;//职工号
public:
    Worker(){};//无参构造函数
    //有参构造函数
    Worker(string name,int id){
        this->m_id=id;
        this->m_name=name;
    }
    //获取职工的姓名
    string getName(){
        return this->m_name;
    }
    //获取职工号
    int getId(){
        return this->m_id;
    }
    //设置职工的姓名
    void setName(string name){
        this->m_name=name;
    }
    //设置职工号
    void setId(int id){
        this->m_id=id;
    }
    //打印职工姓名
    void printName(){
        cout<<this->m_name<<endl;
    }
};
//输入 10 个职工的姓名和职工号，存入到数组arr中
void inputMessage(Worker *arr){
    for (int i = 0; i < N; i++)
    {
        string name;
        int id;
        cout<<"请输入第"<<i+1<<"个职工的姓名"<<endl;
        cin>>name;
        cout<<"请输入第"<<i+1<<"个职工的职工号"<<endl;
        cin>>id;
        arr[i]=Worker(name,id);
    }
}
//交换两个对象的值
void swap(Worker &w1,Worker &w2){
    Worker temp(w1.getName(),w1.getId());
    w1.setName(w2.getName());
    w1.setId(w2.getId());
    w2.setName(temp.getName());
    w2.setId(temp.getId());
}
//冒泡排序，按职工号由小到大顺序排序
void sort(Worker *arr){
    for (int i = 0; i <N; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            //让职工号大的往数组后面移动
            if (arr[j].getId()>arr[j+1].getId())
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//折半查找法，id是输入的那一个职工号，arr是职工数组，arr必须按照职工号由小到大排序
int binarySearch(int id,Worker *arr){
    //定义三个指针分别指向数组前中后
    int low=0;
    int high=N-1;
    int mid=(low+high)/2;
    //如果这个数比数组中最大数还要大，比最小数还要小时，在数组中肯定找不到该数，返回-1
    if (id<arr[low].getId()||id>arr[high].getId())
    {
        return -1;
    }
    //当数组的头指针比尾指针小时，说明查询未结束，继续进行折半查找
    while (low<=high)
    {
        //相等时说明已经找到，返回此时mid值，也就是数组中该数的下标
        if (id==arr[mid].getId())
        {
            return mid;
        }
        //要找的数比数组中间的数大时，说明该数可能在数组的右边
        //此时应该改变low的值，使之指向mid之后的那个数
        else if (id>arr[mid].getId())
        {
            low=mid+1;
            
        }
        //要找的数比数组中间的数小时，说明该数可能在数组的左边
        //此时应该改变high的值，使之指向mid之前的那个数
        else if (id<arr[mid].getId())
        {
            high=mid-1;
        }
        //改变mid的指向，使之指向当前数组的中间
        mid=(low+high)/2;
    }
    //若循环结束之后，还是没有找到，说明数组中无此数
    return -1;
}

int main(){
    //创建职工数组
    Worker arr[N];
    inputMessage(arr);
    printf("数组中有以下员工\n");
    for (int i = 0; i < N; i++)
    {
        arr[i].printName();
    }
    printf("排序后数组中有以下员工\n");
    sort(arr);
    for (int i = 0; i < N; i++)
    {
        arr[i].printName();
    }
    printf("----------\n");
    int id;
    cout<<"请输入一个职工号"<<endl;
    cin>>id;
    int flag=binarySearch(id,arr);
    if (flag!=-1)
    {
        cout<<"该职工号对应职工的姓名为：";
        arr[flag].printName();
    }
    return 0;
}