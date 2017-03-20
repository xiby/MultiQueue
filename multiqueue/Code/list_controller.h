
#ifndef list_controller__
#define list_controller__
#include"process.h"
#include<queue>
using namespace std;

class list_controller
{
private:
	//�洢ϵͳʱ��
	int Time;
	//�����
	queue<process> buffer_list;
	//�������飬STL
	int multi_list_count;
	queue<process> *multi_list;
	//flags
	bool exit_flag;
	bool pause_flag;
	bool new_prcess_flag;

public:
	list_controller();
	~list_controller();

	//�޸�ϵͳʱ�䣬�����ص�ǰϵͳʱ��
	int system_time();
	// ����������÷������޸�pause���λ״̬
	void set_pause();
	//�ж�ϵͳ�Ƿ���Ҫ��ͣ��true=TRUE
	bool is_pause();
	//����������÷������޸�exit���λ״̬
	void set_exit();
	//�ж��Ƿ��˳�����true=TRUE
	bool is_exit();
	//�жϻ�������Ƿ����µ�����
	bool has_new_process();
	//���ڽ���������ã���Ӧ����¼�����process���뻺���
	void set_process();
	//�ӻ�����л�ȡһ���µ�process
	process get();
	//��new_process�����һ������
	void push(process new_process);
	//�ж����е���һ�����У����ض��еı��
	int which_queue();
	//��ʱ��ͣʱ��
	void sleep_(int time);
	//ִ��һ�Σ�һ�룩���̡�
	void run(int);
};

#endif // list_controller__