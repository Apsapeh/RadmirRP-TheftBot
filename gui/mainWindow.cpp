#include "mainWindow.h"
#include "Header.h"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;
using namespace System::Windows::Forms;
using json = nlohmann::json;

int st_count[2];

default_res deff_res;
set_set s_set;
json readed;

//int main()                                                                   // � ��������
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR cmd, int iShow)		   // ��� �������
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	gui::mainWindow form;

	// ������ json �����
	try
	{
		std::ifstream r_file("settings.json");
		readed = json::parse(r_file);
		r_file.close();
	}
	catch (...)
	{
		MessageBox::Show("���� settings.json ������������ ��� ��������", "��� � settings.json?");
		return 0;
	}

	// �������� ��������� �����
	try
	{
		if (
			(readed["system"]["show_donut"]		== nullptr ||
			 readed["system"]["crowbar_sleep"]  == nullptr ||
			 readed["system"]["min_color"]		== nullptr ||
			 readed["system"]["max_color"]		== nullptr)
			 ||
			(readed["default"]["name_trans"]	== nullptr ||
			 readed["default"]["x_trans"]		== nullptr ||
			 readed["default"]["y_trans"]		== nullptr ||
			 readed["default"]["width_trans"]	== nullptr ||
			 readed["default"]["height_trans"]	== nullptr ||
			
			 readed["default"]["name_crowbar"]	== nullptr ||
			 readed["default"]["x_crowbar"]		== nullptr ||
			 readed["default"]["y_crowbar"]		== nullptr ||
			 readed["default"]["width_crowbar"]	== nullptr ||
			 readed["default"]["height_crowbar"]== nullptr ||
			 readed["default"]["box_size"]		== nullptr ||
			 readed["default"]["lock_box_size"]	== nullptr)
		   )

		{
			int* n_temp = new int;
			*n_temp = 0;

			// ����������� �������� ��������� �����
			while (true)
			{	
				// ��������� ������������ ���������������� �������� ������������
				if (readed["custom_res_trans"][*n_temp]["name_trans"]		== nullptr ||
					readed["custom_res_trans"][*n_temp]["x_trans"]			== nullptr ||
					readed["custom_res_trans"][*n_temp]["y_trans"]			== nullptr ||
					readed["custom_res_trans"][*n_temp]["width_trans"]		== nullptr ||
					readed["custom_res_trans"][*n_temp]["height_trans"]		== nullptr)
				{
					MessageBox::Show("��������� ����� settings.json ����������", "�����?");

					Application::Exit();
					exit(0);
				}
				else
					++ *n_temp;

				*n_temp = 0;

				// ��������� ������������ ���������������� �������� ����������
				if (readed["custom_res_crow"][*n_temp]["name_crowbar"]		== nullptr ||
					readed["custom_res_crow"][*n_temp]["x_crowbar"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["y_crowbar"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["width_crowbar"]		== nullptr ||
					readed["custom_res_crow"][*n_temp]["height_crowbar"]	== nullptr ||
					readed["custom_res_crow"][*n_temp]["box_size"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["lock_box_size"]		== nullptr)
				{
					MessageBox::Show("��������� ����� settings.json ����������", "�����?");

					Application::Exit();
					exit(0);
				}
				else
					++* n_temp;
			}

			delete n_temp;
		}
	}
	catch (...)
	{
		MessageBox::Show("��������� ����� settings.json ����������", "�����?");

		return 0;
	}

	try
	{
		// ��������� ���������� �������� � json
		deff_res = { 
						readed["default"]["name_trans"],
						readed["default"]["x_trans"],
						readed["default"]["y_trans"],
						readed["default"]["width_trans"],
						readed["default"]["height_trans"],
				 
						readed["default"]["name_crowbar"],
						readed["default"]["x_crowbar"],
						readed["default"]["y_crowbar"],
						readed["default"]["width_crowbar"],
						readed["default"]["height_crowbar"],
						readed["default"]["box_size"],
						readed["default"]["lock_box_size"]
				   };

		s_set = { 
					readed["system"]["show_donut"],
					readed["system"]["crowbar_sleep"],

					readed["system"]["min_color"]["Red"],
					readed["system"]["min_color"]["Green"],
					readed["system"]["min_color"]["Blue"],

					readed["system"]["max_color"]["Red"],
					readed["system"]["max_color"]["Green"],
					readed["system"]["max_color"]["Blue"], 
				};
	}
	catch (...)
	{
		MessageBox::Show("� settings.json ������������ ������������ ���� ������", "������� ����������");
		return 0;
	}


	// ������������ �� std::string � System::String
	std::string temp1 = readed["default"]["name_trans"];
	std::string temp2 = readed["default"]["name_crowbar"];

	String^ trans = marshal_as<String^>(temp1);
	String^ crow = marshal_as<String^>(temp2);
	
	// �������� �������� ���������� � ��������� ���������� � ������
	setting_count(readed);
	form.change_lbl_res(trans, crow);
	form.change_cb_comps(st_count[0], st_count[1]);
	
	Application::Run(% form);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ������ ����� �������� ���������� � GUI
void gui::mainWindow::change_lbl_res(System::String^ trans, System::String^ crow)
{
	this->lbl_res_trans->Text::set("������� ���������� �����������: " + trans);
	this->lbl_res_crowbar->Text::set("������� ���������� ���������� : " + crow);
}

// ������������ ���-�� ���������� � json
int* setting_count(json set)
{
	st_count[0] = 0;
	st_count[1] = 0;

	while (true)
	{
		if (set["custom_res_trans"][st_count[0]] != nullptr)
			++st_count[0];
		else
			break;
	}

	while (true)
	{
		if (set["custom_res_crow"][st_count[1]] != nullptr)
			++st_count[1];
		else
			break;
	}
	return st_count;
}

// ��������� ���������� � ���������� ������
void gui::mainWindow::change_cb_comps(int trans, int crow)
{
	std::string str;
	String^ text;
	
	// ��������� �����������
	for (int st_num = 0; st_num < trans; ++st_num)
	{
		str = readed["custom_res_trans"][st_num]["name_trans"];
		text = marshal_as<String^>(str);

		this->Settings_trans_CB->Items->Add(text);
	}

	// ��������� ����������
	for (int st_num = 0; st_num < crow; ++st_num)
	{
		str = readed["custom_res_crow"][st_num]["name_crowbar"];
		text = marshal_as<String^>(str);

		this->Settings_crowbar_CB->Items->Add(text);
	}
}