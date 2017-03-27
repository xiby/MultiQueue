//
// MainPage.xaml.cpp
// MainPage 类的实现。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace TestWFP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

MainPage::MainPage():list_control(3)
{
	InitializeComponent();
	

	//测试使用
	//以下均为测试数据
	//先将1个进程加入到缓冲区中
	//我把一下代码从初始化中移出，为了保持类的封闭性。
	for (int i = 0; i < 4; ++i)
	{
		std::stringstream sname;
		sname << "process" << i;
		process tmp(sname.str(), list_control.system_time(), 4 * (i + 1));
		list_control.set_process(tmp);
	}
	//测试代码
}


void TestWFP::MainPage::click_pause(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void TestWFP::MainPage::sys_Time_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}


void TestWFP::MainPage::go(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int queue_index = 0;
	list_control.system_time();
	while (list_control.is_pause() || list_control.has_new_process())
	{
		while (list_control.has_new_process())
		{
			//界面获取数据
			list_control.push(list_control.get());
			//push方法，如果new_process为空，需要修改标记位
		}
	}
	if (list_control.which_queue(queue_index))
	{
		stringstream s;
		string name = list_control.getQueue(queue_index).front().getName();
		s << name << " is running in queue " << queue_index << endl;
		int num = list_control.run(queue_index);
		if (num == 0) {								//返回值为0，不做任何处理


		} else if (num == 1) {						//返回值为1，进入下一个队列
			s << name << " moved to tail of queue " << queue_index + 1 << endl;
		} else if (num == 2) {
			s << name << " moved to tail of queue " << queue_index << endl;
		} else {
			s << name << " finished in queue " << queue_index << endl;
		}

		wchar_t * wc = new wchar_t[s.str().size()];
		swprintf(wc, 100, L"%S", s.str().c_str());
		Platform::String^ msg = ref new String(wc);
		this->show_msg->Text = this->show_msg->Text+msg;
		//this->sys_Time->Text = msg;
	}
}
