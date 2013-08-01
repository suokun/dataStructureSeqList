//
//  SeqList.h
//  SeqList
//
//  Created by Suo Kun on 7/31/13.
//  Copyright (c) 2013 Suo Kun. All rights reserved.
//

#ifndef SeqList_SeqList_h
#define SeqList_SeqList_h

using namespace std;

const int DefaultSize=100;

template <typename Type>
class SeqList{
public:
    SeqList(int sz=DefaultSize):maxSize(sz),currentSize(-1){
        if(sz>0){
            elements=new Type[maxSize];
        }
    }
    
    ~SeqList(){
        delete[] elements;
    }
    
    int Length() const{     //get the length
        return currentSize+1;
    }
    
    int Find(Type x) const;    //find the position of x
    
    int IsElement(Type x) const;  //is it in the list
    
    int Insert(Type x,int i);   //insert data
    
    int Remove(Type x);     //delete data
    
    int IsEmpty(){
        return currentSize==-1;
    }
    
    int IsFull(){
        return currentSize==maxSize-1;
    }
    
    Type Get(int i){     //get the ith data
        return i<0||i>currentSize?(cout<<"can't find the element"<<endl,0):elements[i];
    }
    
    void Print();
    
    
private:
    Type *elements;
    const int maxSize;  //Maximum size of sequence List
    int currentSize;   //current size of sequence List
};


template <typename Type> int SeqList<Type>::Find(Type x) const{
    for(int i=0;i<currentSize;i++)
        if(elements[i]==x)
            return i;
    cout<<"can't find the element you want to find"<<endl;
    return -1;
}


template <typename Type> int SeqList<Type>::IsElement(Type x) const{
    if(Find(x)==-1)
        return 0;
    return 1;
}


//insert x in ith position
template <typename Type> int SeqList<Type>::Insert(Type x, int i){
    if(i<0||i>currentSize+1||currentSize==maxSize-1){
        cout<<"the operate is illegal"<<endl;
        return 0;
    }
    currentSize++;
    for(int j=currentSize;j>i;j--){
        elements[j]=elements[j-1];
    }
    elements[i]=x;
    return 1;
}


//remove element x
template <typename Type> int SeqList<Type>::Remove(Type x){
    int size=currentSize;
    for(int i=0;i<currentSize;){
        if(elements[i]==x){
            for(int j=i;j<currentSize;j++){
                elements[j]=elements[j+1];
            }
            currentSize--;
            continue;
        }
        i++;
    }
    if(size==currentSize){
        cout<<"can't find the element you want to remove"<<endl;
        return 0;
    }
    return 1;
}


template <typename Type> void SeqList<Type>::Print(){
    for(int i=0;i<=currentSize;i++)
        cout<<i+1<<":\t"<<elements[i]<<endl;
    cout<<endl<<endl;
}

#endif
