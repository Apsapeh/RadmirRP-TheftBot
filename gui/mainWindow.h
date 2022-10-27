#pragma once

namespace gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainWindow
	/// </summary>
	public ref class mainWindow : public System::Windows::Forms::Form
	{
	public:
		mainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainWindow()
		{
			if (components)
			{
				delete components;
			}
		}





	private: System::Windows::Forms::Button^ btn_run;


	private: System::Windows::Forms::Button^ btn_donut;

	private: System::ComponentModel::BackgroundWorker^ BW1;
	private: System::Windows::Forms::TabControl^ tab_control;
	private: System::Windows::Forms::TabPage^ tab_menu;
	private: System::Windows::Forms::TabPage^ tab_settings;
	private: System::Windows::Forms::TabPage^ tab_about;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_close;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ Settings_trans_CB;
	private: System::Windows::Forms::Label^ lbl_res_trans;


	private: System::Windows::Forms::Button^ btn_save_cng;
	private: System::Windows::Forms::Label^ change_res;
	private: System::Windows::Forms::Label^ lbl_run;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ Settings_crowbar_CB;
	private: System::Windows::Forms::Label^ lbl_res_crowbar;











	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainWindow::typeid));
			this->btn_run = (gcnew System::Windows::Forms::Button());
			this->btn_donut = (gcnew System::Windows::Forms::Button());
			this->BW1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tab_control = (gcnew System::Windows::Forms::TabControl());
			this->tab_menu = (gcnew System::Windows::Forms::TabPage());
			this->lbl_run = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->tab_settings = (gcnew System::Windows::Forms::TabPage());
			this->btn_save_cng = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->change_res = (gcnew System::Windows::Forms::Label());
			this->lbl_res_crowbar = (gcnew System::Windows::Forms::Label());
			this->lbl_res_trans = (gcnew System::Windows::Forms::Label());
			this->Settings_crowbar_CB = (gcnew System::Windows::Forms::ComboBox());
			this->Settings_trans_CB = (gcnew System::Windows::Forms::ComboBox());
			this->tab_about = (gcnew System::Windows::Forms::TabPage());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tab_control->SuspendLayout();
			this->tab_menu->SuspendLayout();
			this->tab_settings->SuspendLayout();
			this->tab_about->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_run
			// 
			this->btn_run->BackColor = System::Drawing::Color::Transparent;
			this->btn_run->FlatAppearance->BorderColor = System::Drawing::Color::Purple;
			this->btn_run->FlatAppearance->BorderSize = 2;
			this->btn_run->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Purple;
			this->btn_run->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_run->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_run->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btn_run->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_run->Location = System::Drawing::Point(24, 128);
			this->btn_run->Name = L"btn_run";
			this->btn_run->Size = System::Drawing::Size(120, 30);
			this->btn_run->TabIndex = 1;
			this->btn_run->Text = L"Запустить";
			this->btn_run->UseVisualStyleBackColor = false;
			this->btn_run->Click += gcnew System::EventHandler(this, &mainWindow::btn_run_Click);
			// 
			// btn_donut
			// 
			this->btn_donut->FlatAppearance->BorderColor = System::Drawing::Color::Gold;
			this->btn_donut->FlatAppearance->BorderSize = 2;
			this->btn_donut->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gold;
			this->btn_donut->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_donut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_donut->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
			this->btn_donut->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_donut->Location = System::Drawing::Point(247, 175);
			this->btn_donut->Name = L"btn_donut";
			this->btn_donut->Size = System::Drawing::Size(120, 27);
			this->btn_donut->TabIndex = 1;
			this->btn_donut->Text = L"Донат";
			this->btn_donut->UseVisualStyleBackColor = false;
			this->btn_donut->Click += gcnew System::EventHandler(this, &mainWindow::btn_donut_Click);
			// 
			// BW1
			// 
			this->BW1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &mainWindow::BW1_DoWork);
			// 
			// tab_control
			// 
			this->tab_control->Controls->Add(this->tab_menu);
			this->tab_control->Controls->Add(this->tab_settings);
			this->tab_control->Controls->Add(this->tab_about);
			this->tab_control->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tab_control->Location = System::Drawing::Point(0, 0);
			this->tab_control->Name = L"tab_control";
			this->tab_control->SelectedIndex = 0;
			this->tab_control->Size = System::Drawing::Size(400, 250);
			this->tab_control->TabIndex = 3;
			// 
			// tab_menu
			// 
			this->tab_menu->Controls->Add(this->lbl_run);
			this->tab_menu->Controls->Add(this->label1);
			this->tab_menu->Controls->Add(this->btn_donut);
			this->tab_menu->Controls->Add(this->btn_close);
			this->tab_menu->Controls->Add(this->btn_run);
			this->tab_menu->Location = System::Drawing::Point(4, 24);
			this->tab_menu->Name = L"tab_menu";
			this->tab_menu->Padding = System::Windows::Forms::Padding(3);
			this->tab_menu->Size = System::Drawing::Size(392, 222);
			this->tab_menu->TabIndex = 0;
			this->tab_menu->Text = L"Меню";
			this->tab_menu->UseVisualStyleBackColor = true;
			// 
			// lbl_run
			// 
			this->lbl_run->AutoSize = true;
			this->lbl_run->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbl_run->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_run->Location = System::Drawing::Point(156, 90);
			this->lbl_run->Name = L"lbl_run";
			this->lbl_run->Size = System::Drawing::Size(0, 20);
			this->lbl_run->TabIndex = 3;
			this->lbl_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(20, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(372, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Добро пожаловать в Apsapeh`s hack";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::Color::Transparent;
			this->btn_close->FlatAppearance->BorderColor = System::Drawing::Color::Purple;
			this->btn_close->FlatAppearance->BorderSize = 2;
			this->btn_close->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Purple;
			this->btn_close->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->btn_close->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_close->Location = System::Drawing::Point(247, 128);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(120, 30);
			this->btn_close->TabIndex = 1;
			this->btn_close->Text = L"Выход";
			this->btn_close->UseVisualStyleBackColor = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &mainWindow::btn_close_Click);
			// 
			// tab_settings
			// 
			this->tab_settings->Controls->Add(this->btn_save_cng);
			this->tab_settings->Controls->Add(this->label6);
			this->tab_settings->Controls->Add(this->change_res);
			this->tab_settings->Controls->Add(this->lbl_res_crowbar);
			this->tab_settings->Controls->Add(this->lbl_res_trans);
			this->tab_settings->Controls->Add(this->Settings_crowbar_CB);
			this->tab_settings->Controls->Add(this->Settings_trans_CB);
			this->tab_settings->Location = System::Drawing::Point(4, 22);
			this->tab_settings->Name = L"tab_settings";
			this->tab_settings->Padding = System::Windows::Forms::Padding(3);
			this->tab_settings->Size = System::Drawing::Size(392, 224);
			this->tab_settings->TabIndex = 1;
			this->tab_settings->Text = L"Настройки";
			this->tab_settings->UseVisualStyleBackColor = true;
			// 
			// btn_save_cng
			// 
			this->btn_save_cng->BackColor = System::Drawing::Color::Transparent;
			this->btn_save_cng->FlatAppearance->BorderColor = System::Drawing::Color::Purple;
			this->btn_save_cng->FlatAppearance->BorderSize = 2;
			this->btn_save_cng->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Purple;
			this->btn_save_cng->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_save_cng->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save_cng->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btn_save_cng->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_save_cng->Location = System::Drawing::Point(12, 173);
			this->btn_save_cng->Name = L"btn_save_cng";
			this->btn_save_cng->Size = System::Drawing::Size(203, 30);
			this->btn_save_cng->TabIndex = 2;
			this->btn_save_cng->Text = L"Сохранить изменения";
			this->btn_save_cng->UseVisualStyleBackColor = false;
			this->btn_save_cng->Click += gcnew System::EventHandler(this, &mainWindow::btn_save_cng_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->label6->Location = System::Drawing::Point(8, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(198, 19);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Разрешение монтировки";
			// 
			// change_res
			// 
			this->change_res->AutoSize = true;
			this->change_res->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->change_res->Location = System::Drawing::Point(8, 70);
			this->change_res->Name = L"change_res";
			this->change_res->Size = System::Drawing::Size(216, 19);
			this->change_res->TabIndex = 1;
			this->change_res->Text = L"Разрешение транспондера";
			// 
			// lbl_res_crowbar
			// 
			this->lbl_res_crowbar->AutoSize = true;
			this->lbl_res_crowbar->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
			this->lbl_res_crowbar->Location = System::Drawing::Point(8, 40);
			this->lbl_res_crowbar->Name = L"lbl_res_crowbar";
			this->lbl_res_crowbar->Size = System::Drawing::Size(264, 17);
			this->lbl_res_crowbar->TabIndex = 1;
			this->lbl_res_crowbar->Text = L"Текущее разрешение монтировки : ";
			// 
			// lbl_res_trans
			// 
			this->lbl_res_trans->AutoSize = true;
			this->lbl_res_trans->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
			this->lbl_res_trans->Location = System::Drawing::Point(8, 17);
			this->lbl_res_trans->Name = L"lbl_res_trans";
			this->lbl_res_trans->Size = System::Drawing::Size(264, 17);
			this->lbl_res_trans->TabIndex = 1;
			this->lbl_res_trans->Text = L"Текущее разрешение трансподера: ";
			// 
			// Settings_crowbar_CB
			// 
			this->Settings_crowbar_CB->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Settings_crowbar_CB->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->Settings_crowbar_CB->Location = System::Drawing::Point(230, 108);
			this->Settings_crowbar_CB->Name = L"Settings_crowbar_CB";
			this->Settings_crowbar_CB->Size = System::Drawing::Size(143, 27);
			this->Settings_crowbar_CB->TabIndex = 0;
			// 
			// Settings_trans_CB
			// 
			this->Settings_trans_CB->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Settings_trans_CB->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
			this->Settings_trans_CB->Location = System::Drawing::Point(230, 67);
			this->Settings_trans_CB->Name = L"Settings_trans_CB";
			this->Settings_trans_CB->Size = System::Drawing::Size(143, 27);
			this->Settings_trans_CB->TabIndex = 0;
			// 
			// tab_about
			// 
			this->tab_about->Controls->Add(this->label5);
			this->tab_about->Controls->Add(this->label4);
			this->tab_about->Controls->Add(this->label3);
			this->tab_about->Controls->Add(this->label2);
			this->tab_about->Location = System::Drawing::Point(4, 24);
			this->tab_about->Name = L"tab_about";
			this->tab_about->Padding = System::Windows::Forms::Padding(3);
			this->tab_about->Size = System::Drawing::Size(392, 222);
			this->tab_about->TabIndex = 2;
			this->tab_about->Text = L"О Программе";
			this->tab_about->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->label5->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->label5->Location = System::Drawing::Point(81, 204);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(223, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Контакт для связи: apsapeh@gmail.com";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(8, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(179, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Разработчик: Apsapeh";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(6, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(200, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Версия: Release 1.6 (C++)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Leelawadee UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(50, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(295, 30);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Apsapeh`s Hack (C++ Version)";
			// 
			// mainWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(400, 250);
			this->Controls->Add(this->tab_control);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"mainWindow";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Apsapeh`s Hack";
			this->Load += gcnew System::EventHandler(this, &mainWindow::MyForm_Load);
			this->tab_control->ResumeLayout(false);
			this->tab_menu->ResumeLayout(false);
			this->tab_menu->PerformLayout();
			this->tab_settings->ResumeLayout(false);
			this->tab_settings->PerformLayout();
			this->tab_about->ResumeLayout(false);
			this->tab_about->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_run_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BW1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
private: System::Void btn_donut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_save_cng_Click(System::Object^ sender, System::EventArgs^ e);

public: void change_lbl_res(System::String^, System::String^);
public: void change_cb_comps(int trans, int crow);
};
}
