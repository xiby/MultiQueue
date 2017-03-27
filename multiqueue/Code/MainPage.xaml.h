//
// MainPage.xaml.h
// MainPage 类的声明。
//

#pragma once

#include "MainPage.g.h"

namespace TestWFP
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		process  process_contor;   //进程控制模块
		list_controller  list_control;         //队列控制模块
		void click_pause(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void sys_Time_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void go(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
