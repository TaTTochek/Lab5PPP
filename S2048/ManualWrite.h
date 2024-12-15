#pragma once
#include "Data_.h"
#include <vector>
#include <msclr/marshal_cppstd.h>
//#include "Leaderboard.h"
//#include "Main.h"
namespace S2048 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ManualWrite
	/// </summary>
	public ref class ManualWrite : public System::Windows::Forms::Form
	{
	private:
		//Leaderboard^ parentForm;
		std::vector<Data_>* listdata2;
		BindingList<ManagedData^>^ managedDataList;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	public:
		ManualWrite(std::vector<Data_>* listdata, bool Visible_, BindingList<ManagedData^>^ managedDataList_)
		{
			InitializeComponent();

			// Initialize member variables
			//parentForm = parentF;
			listdata2 = listdata;

			// Initialize the BindingList
			managedDataList = managedDataList_;
			//for (const auto& data : *listdata2)
			//{
			//	managedDataList->Add(gcnew ManagedData(data.GetNick(), data.GetScore()));
			//}

			// Bind the managed data list to the ComboBox
			comboBox1->DataSource = managedDataList;
			comboBox1->DisplayMember = "Nickname";

			// Set visibility of buttons
			button2->Visible = Visible_;
			button3->Visible = Visible_;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ManualWrite()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(104, 161);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(268, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Score";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 164);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nickname";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 225);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 64);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ManualWrite::AddDataGrid);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(46, 225);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 64);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ManualWrite::ChangeButton);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(297, 225);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 64);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ManualWrite::deleteButton);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(46, 31);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(326, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(104, 107);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(268, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Minimum = 0;
			this->numericUpDown1->Maximum = 100000;
			// 
			// ManualWrite
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 346);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Name = L"ManualWrite";
			this->Text = L"ManualWrite";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SelectedIndex(System::Object^ sender, System::EventArgs^ e) {
		// Get the selected index from the ComboBox
		int selectedIndex = comboBox1->SelectedIndex;

		if (selectedIndex < 0 || selectedIndex >= listdata2->size())
		{
			MessageBox::Show("No valid item selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Retrieve the selected ManagedData from the BindingList
		ManagedData^ selectedPerson = managedDataList[selectedIndex];

		// Optionally retrieve the corresponding native Data_ object
		Data_ nativePerson = (*listdata2)[selectedIndex];

		// Display details or perform actions with the selected item
		textBox2->Text = selectedPerson->Nickname;
		numericUpDown1->Value = selectedPerson->Score;
	}
	private: System::Void AddDataGrid(System::Object^ sender, System::EventArgs^ e)
	{
		String^ nickname = textBox2->Text;
		int score = Decimal::ToInt32(numericUpDown1->Value);
		if (String::IsNullOrWhiteSpace(nickname) || nickname->Length > 20)
		{
			MessageBox::Show("Nickname cannot be empty.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		Data_ newData(msclr::interop::marshal_as<std::string>(nickname), score);
		// Add to std::vector<Data_>
		listdata2->push_back(newData);

		// Add to BindingList<ManagedData^>
		managedDataList->Add(gcnew ManagedData(msclr::interop::marshal_as<std::string>(nickname), score));

		// Clear inputs
		textBox2->Clear();
		numericUpDown1->Value = 0;
	};
	private: System::Void deleteButton(System::Object^ sender, System::EventArgs^ e)
	{
		int selectedIndex = comboBox1->SelectedIndex;
		if (selectedIndex >= 0) {
			// Remove from std::vector<Data_>
			listdata2->erase(listdata2->begin() + selectedIndex);

			// Remove from BindingList<ManagedData^>
			managedDataList->RemoveAt(selectedIndex);
		}
	};
	private: System::Void ChangeButton(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the selected index from the ComboBox
		int selectedIndex = comboBox1->SelectedIndex;

		if (selectedIndex < 0 || selectedIndex >= listdata2->size())
		{
			MessageBox::Show("Please select a valid item to edit.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Retrieve the updated values from the inputs
		String^ updatedNickname = textBox2->Text;
		int updatedScore = Decimal::ToInt32(numericUpDown1->Value);

		if (String::IsNullOrWhiteSpace(updatedNickname) || updatedNickname->Length > 20)
		{
			MessageBox::Show("Nickname cannot be empty.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Update the native std::vector<Data_>
		(*listdata2)[selectedIndex] = Data_(msclr::interop::marshal_as<std::string>(updatedNickname), updatedScore);

		// Update the BindingList<ManagedData^>
		managedDataList[selectedIndex] = gcnew ManagedData(msclr::interop::marshal_as<std::string>(updatedNickname), updatedScore);

		MessageBox::Show("Data updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Optionally clear inputs
		textBox2->Clear();
		numericUpDown1->Value = 0;
	}
	};
}