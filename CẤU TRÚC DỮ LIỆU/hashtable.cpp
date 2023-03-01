#include<iostream>
using namespace std;
class hashtable{
    public:
    int data;
    int key;
};
int hashCode(int key)
{
    return key%size;
}
void insert(int key, int data)
{
    hashtable *p = new hashtable();
    p->data = data;
    p->key = key;
    int hashindex = hashCode(key);
    {
        while(hashArray[hashindex]!=NULL&& hashArray[hashindex]->key!=-1)
        {
            hashindex++;
            hashindex %= size;
        }
        {

        }
    }
}
int main()
{
    
}