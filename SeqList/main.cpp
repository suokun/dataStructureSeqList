//
//  main.cpp
//  SeqList
//
//  Created by Suo Kun on 7/31/13.
//  Copyright (c) 2013 Suo Kun. All rights reserved.
//

#include <iostream>
#include "SeqList.h"

using namespace std;

int main(int argc, const char * argv[])
{
    SeqList<int> test(15);
    int array[15]={2,5,8,0,9,9,7,6,4,3,2,9,7,7,9};
    for(int i=0;i<15;i++){
        test.Insert(array[i],0);
    }
    test.Insert(1,0);
    cout<<(test.Find(0)?"can't be found ":"Be found ")<< 0 << endl<<endl;
    test.Remove(7);
    test.Print();
    test.Remove(9);
    test.Print();
    test.Remove(0);
    test.Print();
    
    // insert code here...
    return 0;
}

