#define list_controller__
#ifdef list_controller__

class list_controller
{
	//�����
	//�������飬STL

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
	bool set_exit();
	//�ж��Ƿ��˳�����true=TRUE
	void is_exit();
	//�жϻ�������Ƿ����µ�����
	bool has_new_process();
	//���ڽ���������ã���Ӧ����¼�����process���뻺���
	void set_process();
	//�ӻ�����л�ȡһ���µ�process
	process get();
	//�ж����е���һ�����У����ض��еı��
	int which_queue();
	//��ʱ��ͣʱ��
	void sleep(int time);
};

#endif // list_controller__