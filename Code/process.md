//this is a Visual Studio 2017 TeamManagertest.

```c++
    class process{
    private:
        string pName;       //进程名
        int serveTime;      //总共所需的时间
        int runTime;        //已经运行的时间
        int timeChip;       //需要的时间片
        int serveinQueue;   //在队列里已经运行的时间
        int endTime;        //程序结束时间
    public:
        process(string name,int servetime,int runtime,int timechip,int serveinqueue);
        int getserveTime();
        int getrunTime();
        int gettimeChip();
        int getserveinQueue();
        void setserveTime(int time);
        void setrunTime(int time);
        void settimeChip(int time);
        void setserveinQueue(int time);
        void setendTime(int time);
        bool run(int chip);     //运行完成则返回true


        
    }