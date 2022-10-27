#include "mainWindow.h"
#include "Header.h"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>


using namespace System;
using namespace msclr::interop;
using namespace System::Windows::Forms;
using json = nlohmann::json;

bool run_bool = false;
bool run_bool_cout = false;


std::string tab_string = "    ";
std::string bool_string = "";
char comma = ',';

extern int st_count[2];
extern default_res deff_res;
extern set_set s_set;
extern json readed;

void read_sett_json(custom_res_trans*, custom_res_crow*); // Чтение settings.json
void save_sett_json(custom_res_trans*, custom_res_crow*); // Сохранение settings.json



////////////////////////////////////////////// Основные кнопки /////////////////////////////////////////////////

//Кнопка запуска основного цикла
System::Void gui::mainWindow::btn_run_Click(System::Object^ sender, System::EventArgs^ e)
{

	//  Изменяет надпись на кнопке и упрвляет циклом
	if (run_bool)
	{
		btn_run->Text = "Продолжить";
		lbl_run->Text = "На паузе";
		run_bool = false;
	}
	else if (!run_bool_cout)
	{
		if (s_set.show_donut)
		{
			// Создаёт временную переменную
			custom_res_trans* cust_res_trans = new custom_res_trans;
			custom_res_crow* cust_res_crowbar = new custom_res_crow;


			MessageBox::Show("Привет!\nЭта программа полностью бесплатна, но если ты вдруг хочешь поддержать автора,\
то нажами на кнопку \"Донат\".\n\nP.S. Это сообщение больше не появится", "Поддержать автора");

			s_set.show_donut = false;

			// Читает settings.json отключает вывод окошка с донатом и сохраняет
			read_sett_json(cust_res_trans, cust_res_crowbar);
			save_sett_json(cust_res_trans, cust_res_crowbar);
		}

		btn_run->Text = "Пауза";
		lbl_run->Text = "Работает";
		BW1->RunWorkerAsync();
		run_bool = true;
		run_bool_cout = true;
	}
	else
	{
		btn_run->Text = "Пауза";
		lbl_run->Text = "Работает";
		run_bool = true;
	}

	return System::Void();
}

// Аснихронность, чтобы интерфейс не вис
System::Void gui::mainWindow::BW1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
	t_c_func();
	return System::Void();
}

// Кнопка закрывающая программу
System::Void gui::mainWindow::btn_close_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();

	return System::Void();
}

// Кнопка открывающая окно с донатом
System::Void gui::mainWindow::btn_donut_Click(System::Object^ sender, System::EventArgs^ e)
{
	ShellExecute(0, L"open", L"https://www.donationalerts.com/r/apsapeh", 0, 0, SW_SHOWNORMAL);
	return System::Void();
}

// Кнопка сохраняющая выбранное разрешение в settings.json
System::Void gui::mainWindow::btn_save_cng_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string str;
	String^ cb_trans_text;
	String^ cb_crow_text;

	String^ cb_trans = Settings_trans_CB->Text;
	String^ cb_crow = Settings_crowbar_CB->Text;
	
	// Создаёт временную переменную
	custom_res_trans* cust_res_trans = new custom_res_trans;
	custom_res_crow* cust_res_crowbar = new custom_res_crow;

	read_sett_json(cust_res_trans, cust_res_crowbar);
	setting_count(readed);
	
	// Ищет выбранный элемент
	for (int st_num = 0; st_num < st_count[0]; ++st_num)
	{
		str = readed["custom_res_trans"][st_num]["name_trans"];
		cb_trans_text = marshal_as<String^>(str);

		if (cb_trans_text == cb_trans)
		{
			deff_res.name_trans		=	readed["custom_res_trans"][st_num]["name_trans"];
			deff_res.x_trans		=	readed["custom_res_trans"][st_num]["x_trans"];
			deff_res.y_trans		=	readed["custom_res_trans"][st_num]["y_trans"];
			deff_res.width_trans	=	readed["custom_res_trans"][st_num]["width_trans"];
			deff_res.height_trans	=	readed["custom_res_trans"][st_num]["height_trans"];

			break;
		}
	}

	// Ищет выбранный элемент
	for (int st_num = 0; st_num < st_count[1]; ++st_num)
	{
		str = readed["custom_res_crow"][st_num]["name_crowbar"];
		cb_crow_text = marshal_as<String^>(str);

		if (cb_crow_text == cb_crow)
		{
			deff_res.name_crowbar	= readed["custom_res_crow"][st_num]["name_crowbar"];
			deff_res.x_crowbar		= readed["custom_res_crow"][st_num]["x_crowbar"];
			deff_res.y_crowbar		= readed["custom_res_crow"][st_num]["y_crowbar"];
			deff_res.width_crowbar	= readed["custom_res_crow"][st_num]["width_crowbar"];
			deff_res.height_crowbar = readed["custom_res_crow"][st_num]["height_crowbar"];
			deff_res.box_size		= readed["custom_res_crow"][st_num]["box_size"];
			deff_res.lock_box_size	= readed["custom_res_crow"][st_num]["lock_box_size"];

			break;
		}
	}

	// Изменение вывода текущего разрешения
	cb_trans_text = marshal_as<String^>(deff_res.name_trans);
	cb_crow_text = marshal_as<String^>(deff_res.name_crowbar);
	this->change_lbl_res(cb_trans_text, cb_crow_text);

	// Сохраняет изменения
	save_sett_json(cust_res_trans, cust_res_crowbar);

	return System::Void();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void read_sett_json(custom_res_trans* cust_res_trans, custom_res_crow* cust_res_crowbar )
{
	// Чтение json файла
	try
	{
		std::ifstream r_file("settings.json");
		readed = json::parse(r_file);
		r_file.close();
	}
	catch (...)
	{
		MessageBox::Show("Файл settings.json отстутствует или повреждён", "Что с settings.json?");
		Application::Exit();
	}

	// Проверка структуры файла
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

			while (true)
			{	
				// Проверяет правильность пользовательских значений транспондера
				if (readed["custom_res_trans"][*n_temp]["name_trans"]		== nullptr ||
					readed["custom_res_trans"][*n_temp]["x_trans"]			== nullptr ||
					readed["custom_res_trans"][*n_temp]["y_trans"]			== nullptr ||
					readed["custom_res_trans"][*n_temp]["width_trans"]		== nullptr ||
					readed["custom_res_trans"][*n_temp]["height_trans"]		== nullptr)
				{
					MessageBox::Show("Структура файла settings.json повреждена", "Зачем?");

					Application::Exit();
					exit(0);
				}
				else
					++ *n_temp;

				*n_temp = 0;

				// Проверяет правмльность пользовательских значения монтировки
				if (readed["custom_res_crow"][*n_temp]["name_crowbar"]		== nullptr ||
					readed["custom_res_crow"][*n_temp]["x_crowbar"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["y_crowbar"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["width_crowbar"]		== nullptr ||
					readed["custom_res_crow"][*n_temp]["height_crowbar"]	== nullptr ||
					readed["custom_res_crow"][*n_temp]["box_size"]			== nullptr ||
					readed["custom_res_crow"][*n_temp]["lock_box_size"]		== nullptr)
				{
					MessageBox::Show("Структура файла settings.json повреждена", "Зачем?");

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
		MessageBox::Show("Структура файла settings.json повреждена", "Зачем?");

		Application::Exit();
		exit(0);
	}


	// Подсчёт кол-ва элементов в файле
	setting_count(readed);

	// Ну тут и ежу понятно
	deff_res = { readed["default"]["name_trans"],
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


	*cust_res_trans = { 
							readed["custom_res_trans"][0]["name_trans"],
				 			readed["custom_res_trans"][0]["x_trans"],
							readed["custom_res_trans"][0]["y_trans"],
							readed["custom_res_trans"][0]["width_trans"],
							readed["custom_res_trans"][0]["height_trans"],
					  };

	*cust_res_crowbar = {
							readed["custom_res_crow"][0]["name_crowbar"],
							readed["custom_res_crow"][0]["x_crowbar"],
							readed["custom_res_crow"][0]["y_crowbar"],
							readed["custom_res_crow"][0]["width_crowbar"],
							readed["custom_res_crow"][0]["height_crowbar"],
							readed["custom_res_crow"][0]["box_size"], 
							readed["custom_res_crow"][0]["lock_box_size"] 
						};
}

// Функцмя сохраняющаяя красивый файл с настройками
void save_sett_json(custom_res_trans* cust_res_trans, custom_res_crow* cust_res_crowbar)
{
	if (s_set.show_donut)
		bool_string = "true";
	else
		bool_string = "false";

	//////////////////////////////////////////// Форматирование json //////////////////////////////////////////////

	std::string json_str = "\
{\n\n\
\
\"system\" : \n\
	{\n\
		\"show_donut\"	  : " + bool_string + ",\n\
		\"crowbar_sleep\"	  : " + std::to_string(s_set.crowbar_sleep) + ",\n\
		\"min_color\"		  : {\"Red\" : " + std::to_string(s_set.min_r) + ", \"Green\" : "
		+ std::to_string(s_set.min_g) + ", \"Blue\" : "
		+ std::to_string(s_set.min_b) + "},\n\
		\"max_color\"		  : {\"Red\" : " + std::to_string(s_set.max_r) + ", \"Green\" : "
		+ std::to_string(s_set.max_g) + ", \"Blue\" : "
		+ std::to_string(s_set.max_b) + "}\n\
	},\n\n\
\
\"default\" : \n\
	{\n\
		\"name_trans\"	 : \"" + deff_res.name_trans + "\",\n\
		\"x_trans\"	     : " + std::to_string(deff_res.x_trans) + ",\n\
		\"y_trans\"	     : " + std::to_string(deff_res.y_trans) + ",\n\
		\"width_trans\"    : " + std::to_string(deff_res.width_trans) + ",\n\
		\"height_trans\"   : " + std::to_string(deff_res.height_trans) + ",\n\n\
\
		\"name_crowbar\"	 : \"" + deff_res.name_crowbar + "\",\n\
		\"x_crowbar\"	     : " + std::to_string(deff_res.x_crowbar) + ",\n\
		\"y_crowbar\"	     : " + std::to_string(deff_res.y_crowbar) + ",\n\
		\"width_crowbar\"  : " + std::to_string(deff_res.width_crowbar) + ",\n\
		\"height_crowbar\" : " + std::to_string(deff_res.height_crowbar) + ",\n\
		\"box_size\"		 : " + std::to_string(deff_res.box_size) + ",\n\
		\"lock_box_size\"  : " + std::to_string(deff_res.lock_box_size) + "\n\
	},\n\n\n\
\
\
\"custom_res_trans\" : \n\
[\n";
	for (int st_num = 0; st_num < st_count[0]; ++st_num)
	{
		*cust_res_trans =	{ 
								readed["custom_res_trans"][st_num]["name_trans"],
				 				readed["custom_res_trans"][st_num]["x_trans"],
								readed["custom_res_trans"][st_num]["y_trans"],
								readed["custom_res_trans"][st_num]["width_trans"],
								readed["custom_res_trans"][st_num]["height_trans"],
							};

		if (st_num + 1 == st_count[0])
			comma = ' ';
		else
			comma = ',';


		json_str += "\
" + tab_string + "{\n\
		\"name_trans\"	 : \"" + cust_res_trans->name_trans + "\",\n\
		\"x_trans\"	     : " + std::to_string(cust_res_trans->x_trans) + ",\n\
		\"y_trans\"	     : " + std::to_string(cust_res_trans->y_trans) + ",\n\
		\"width_trans\"    : " + std::to_string(cust_res_trans->width_trans) + ",\n\
		\"height_trans\"   : " + std::to_string(cust_res_trans->height_trans) + "\n\
	}" + comma + "\n\n\
";
	}
	json_str += "],\n\n\
\
\"custom_res_crow\" : \n\
[\n\n\
";

	for (int st_num = 0; st_num < st_count[1]; ++st_num)
	{
		*cust_res_crowbar = {
								readed["custom_res_crow"][st_num]["name_crowbar"],
								readed["custom_res_crow"][st_num]["x_crowbar"],
								readed["custom_res_crow"][st_num]["y_crowbar"],
								readed["custom_res_crow"][st_num]["width_crowbar"],
								readed["custom_res_crow"][st_num]["height_crowbar"],
								readed["custom_res_crow"][st_num]["box_size"],
								readed["custom_res_crow"][st_num]["lock_box_size"]
		};

		if (st_num + 1 == st_count[1])
			comma = ' ';
		else
			comma = ',';


		json_str += "\
" + tab_string + "{\n\
		\"name_crowbar\"	 : \"" + cust_res_crowbar->name_crowbar + "\",\n\
		\"x_crowbar\"	     : " + std::to_string(cust_res_crowbar->x_crowbar) + ",\n\
		\"y_crowbar\"	     : " + std::to_string(cust_res_crowbar->y_crowbar) + ",\n\
		\"width_crowbar\"  : " + std::to_string(cust_res_crowbar->width_crowbar) + ",\n\
		\"height_crowbar\" : " + std::to_string(cust_res_crowbar->height_crowbar) + ",\n\
		\"box_size\"		 : " + std::to_string(cust_res_crowbar->box_size) + ",\n\
		\"lock_box_size\"  : " + std::to_string(cust_res_crowbar->lock_box_size) + "\n\
	}" + comma + "\n\n\
";
	}
	
	json_str += "]\n}";

	delete cust_res_trans;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Запись в json отформатированного текста
	std::ofstream w_file("settings.json");
	w_file << json_str;
	w_file.close();
}