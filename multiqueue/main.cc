#include"process.h"

#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<process> ** pQueue;		
    int queueNum(0);				
    int pNum(0);					
    
    cout<<"input the number of queues:";
    cin>>queueNum;
    pQueue=new queue<process>*[queueNum];	
    for(int i=0;i<queueNum;++i){
        pQueue[i]=new queue<process>;		
    }
    cout<<"input the number of processes:";
    cin>>pNum;
    for(int i=0;i<pNum;++i){
        char str[100];
        _itoa_s(i,str,10);
        string name(str);
        process tmp(name,i+1,5*(i+1));
        pQueue[0]->push(tmp);
    }

    while(true){
        bool finished=true;															//for judging whether all the queues are empty
        int index=0;
		while (index < queueNum ){
			if (!pQueue[index++]->empty()) {
				finished = false;
				break;
			}
		}
		if(!finished){
            if(pQueue[index-1]->front().run(2*index)){                              //若以将时间片花完，则还要判断进程是否结束
                cout<<(pQueue[index-1]->front()).getName()<<" served in "<< index - 1<<endl;
                if(pQueue[index-1]->front().finished()){                            //若进程已经结束，则直接pop
                    cout<<(pQueue[index-1]->front()).getName()<<" is over!"<<endl;
                    pQueue[index-1]->pop();
                }else{                                                              //若进程还未结束，则将其插入下一个队列
                    if(index!=queueNum){                                           //若已经是最后一个队列，则直接插入队列尾
                        pQueue[index]->push(pQueue[index-1]->front());
                        pQueue[index-1]->pop();
                    }else{
                        pQueue[index-1]->push(pQueue[index-1]->front());
                        pQueue[index-1]->pop();
                    }
                }
            }else{                                                                  //若时间片未花完，则还应该判断进程是否结束                                                                 
                cout<<(pQueue[index-1]->front()).getName()<<" served in "<<index-1<<endl;
                if(pQueue[index-1]->front().finished()){                            //若结束则直接pop，否则不做任何处理
                    cout<<(pQueue[index-1]->front()).getName()<<" is over!"<<endl;
                    pQueue[index-1]->pop();
                }
            }
		} else {
			break;
		}
		
    }

    for(int i=0;i<queueNum;++i){
        delete pQueue[i];
    }
    delete[] pQueue;
    return 0;
}