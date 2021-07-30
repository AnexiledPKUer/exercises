#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> &v);
void printVector(vector<vector<int>> &v);
void queueReconstruction(vector <vector <int > > & people);
bool mycmp(const vector<int> & a,const vector<int> & b);
bool fine(int k,vector<int> & tempQueue,vector <vector <int > > & people);
void update(int k,vector<int> & tempQueue,vector <int > & remains);
//int main() {
//    vector <vector <int > > people={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
//    queueReconstruction(people);
//    return 0;
//}







void printVector(vector<int> &v){
    vector<int >::iterator p;
    for (p=v.begin();p!=v.end();++p)
        cout<<*p<<" ";
    cout<<endl;
}
void printVector(vector<vector<int>> &v){
    vector<vector<int> >::iterator p1;
    vector<int >::iterator p2;
    for (p1=v.begin();p1!=v.end();++p1){
        for (p2=(*p1).begin();p2!=(*p1).end();++p2)
            cout<<*p2<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool mycmp(const vector<int> & a,const vector<int> & b){
    if (a[0]==b[0]) return a[1]<b[1];
    else return a[0]<b[0];
}


void queueReconstruction(vector <vector <int > > & people){
    //printVector(people);
    sort(people.begin(),people.end(),mycmp);
    //printVector(people);
    vector<int > tempQueue,remains,heads;
    vector<int> ::iterator h;

    //heads
    for (int i=0;i<people.size();i++) {
        if (fine(i,tempQueue,people)){
            heads.push_back(i);
        }
    }
    //
    int success;
    for(h=heads.begin();h!=heads.end();h++){
        //init
        remains.clear();
        for (int i=0;i<people.size();i++) {if (i!=*h){remains.push_back(i);}}
        tempQueue.clear();
        tempQueue.push_back(*h);
        //loop
        while (!remains.empty()){
            success=0;
            for(int i : remains){
                if (fine(i,tempQueue,people)){
                    success=1;
                    update(i,tempQueue,remains);
                    break;
                }
            }
            if (success!=1){
                break;
            }
        }
        if (success==1){//complete the queue
            cout<<"Complete the queue:"<<endl;
            printVector(tempQueue);
        }else{
            cout<<"Failed to complete the following queue: "<<endl;
            printVector(tempQueue);
        }
    }

}


bool fine(int k,vector<int> & tempQueue,vector <vector <int > > & people){
    int nums = 0;
    for (int i : tempQueue) {
        if (people[i][0] >= people[k][0]) nums++;
    }
    if (nums == people[k][1]) {
        return true;
    }
    return false;
}


void update(int k,vector<int> & tempQueue,vector <int > & remains){
    tempQueue.push_back(k);
    vector <int >::iterator p;
    for(p=remains.begin();p!=remains.end();++p){
        if ((*p)==k){
            remains.erase(p);
            break;
        }
    }
}



