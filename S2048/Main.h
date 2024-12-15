#pragma once
#include "Data_.h"
#include "vector"
namespace S2048 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	std::vector<Data_>* listData;
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			listData = new std::vector<Data_>();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

//#pragma region Helper Methods
//	private:
//		// Convert managed String^ to std::string
//		std::string ConvertToStdString(String^ managedStr)
//		{
//			return msclr::interop::marshal_as<std::string>(managedStr);
//		}
//
//		// Convert std::string to managed String^
//		String^ ConvertToManagedString(const std::string& nativeStr)
//		{
//			return gcnew String(nativeStr.c_str());
//		}
//#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(245, 95);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Начать игру";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::OpenGame);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(101, 236);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 95);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Статистика";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::OpenLeaderboard);
			// 
			// button3
			// 
			this->button3->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button3->Location = System::Drawing::Point(101, 337);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(245, 95);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Выйти";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::ExitApp);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->textBox1->Location = System::Drawing::Point(142, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(157, 61);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"2048";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 109);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(245, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(25, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nickname";
			this->label1->Click += gcnew System::EventHandler(this, &Main::label1_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(460, 441);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: System::Void OpenGame(Object^ sender, EventArgs^ e);
		private: System::Void OpenLeaderboard(Object^ sender, EventArgs^ e);
		System::Void ExitApp(Object^ sender, EventArgs^ e);



#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
