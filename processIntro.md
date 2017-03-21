
# process
## 主要属性：
```c++
    string pName;        //进程名
    int arriveTime;      //进程到达时间
    int serveTime;       //进程所需的服务时间
    int runTime;         //进程已经运行的时间
    int serveinQueue;    //进程在某个队列中运行的时间
    int endTime;         //进程结束时间
    int rotTime;         //进程周转时间
    int wrotTime;        //进程带权周转时间       
```

## 主要方法：
```c++
    bool run(int chip);     //以所在的时间片大小为参数，若已经花完时间片，则返回true，否则返回false，在队列控制里可根据该返回值确定是否需要将进程移入下一个队列
    bool finished();        //判断进程是否执行完成，若已经完成，则返回true，否则返回false
    //对于所有属性，均有set和get方法，供设置与获取
```