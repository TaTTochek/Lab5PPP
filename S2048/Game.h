#include "Main.h"
#include "Class.h"
#include "Data_.h"
#include <msclr/marshal_cppstd.h>
#pragma once

namespace S2048 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	std::vector<Data_>* listData2;
	public:
		Game(void)
		{
			InitializeComponent();
			Game2048 = new mainGame2048();
			this->labels[17]->Visible = false;
			//
			//TODO: добавьте код конструктора
			//
			//experiment
			isGameOver = false;
			UpdateLabels(); // Update labels with initial grid values
		}
		Game(String^ Nickname, std::vector<Data_>* listData)
		{
			InitializeComponent();
			Game2048 = new mainGame2048();
			this->labels[17]->Text = Nickname;
			//
			//TODO: добавьте код конструктора
			//
			//experiment
			isGameOver = false;
			UpdateLabels(); // Update labels with initial grid values
			listData2 = listData;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
			delete Game2048;
		}








	protected:

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		mainGame2048* Game2048;
		bool isGameOver; 
		//
		array<System::Windows::Forms::Label^>^ labels;
		//



#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			//experiment

			this->labels = gcnew array<System::Windows::Forms::Label^>(18); // Create an array for labels
			for (int i = 0; i < 16; i++) {
				this->labels[i] = gcnew System::Windows::Forms::Label();
				this->labels[i]->BackColor = System::Drawing::SystemColors::ActiveBorder;
				this->labels[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
				this->labels[i]->Size = System::Drawing::Size(60, 60);
				this->labels[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

				// Calculate position based on index
				int row = i / 4;
				int col = i % 4;
				this->labels[i]->Location = System::Drawing::Point(105 + col * 66, 135 + row * 72);

				this->Controls->Add(this->labels[i]); // Add label to the form
			}
			this->labels[16] = gcnew System::Windows::Forms::Label();
			this->labels[16]->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->labels[16]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labels[16]->Size = System::Drawing::Size(258, 60);
			this->labels[16]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labels[16]->Location = System::Drawing::Point(105, 50);
			this->Controls->Add(this->labels[16]); // Add label to the form

			//experiment






			this->SuspendLayout();
			// 
			// labelExample
			// 

			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 505);
			//this->Controls->Add(this->label18);
			//this->Controls->Add(this->labelExample);
			this->Name = L"Game";
			this->Text = L"2048";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Move);
			this->ResumeLayout(false);

		
			this->labels[17] = gcnew System::Windows::Forms::Label();
			this->labels[17]->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->labels[17]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labels[17]->Size = System::Drawing::Size(463, 30);
			this->labels[17]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labels[17]->Location = System::Drawing::Point(0, 0);
			//this->labels[17]->Text = Nickname + "'s Game";
			this->Controls->Add(this->labels[17]); // Add label to the form





			this->SuspendLayout();
			// 
			// labelExample
			// 

			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 505);
			//this->Controls->Add(this->label18);
			//this->Controls->Add(this->labelExample);
			this->Name = L"Game";
			this->Text = L"2048";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Move);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Move(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (isGameOver) return;
		System::Char IsEnd = ' ';
		switch (e->KeyCode) {// == Keys::Left || e->KeyCode == Keys::Down || e->KeyCode == Keys::Up || e->KeyCode == Keys::Right) {
		case Keys::Up:
			IsEnd = Game2048->playGame2048('w'); break;
		case Keys::Down:
			IsEnd = Game2048->playGame2048('s'); break;
		case Keys::Left:
			IsEnd = Game2048->playGame2048('a');break;
		case Keys::Right:
			IsEnd = Game2048->playGame2048('d');break;
		case Keys::Q:
			IsEnd = Game2048->playGame2048('q'); break;

		}
		if (IsEnd == 'L') {
			MessageBox::Show("Game Over!");
			Data_ newData(msclr::interop::marshal_as<std::string>(labels[17]->Text), Game2048->GetScore());
			this->Close();
			isGameOver = true;
			if (!(labels[17]->Text == "")) listData2->push_back(newData);
		}
		else UpdateLabels();
	}
	void UpdateLabels()	{
	   for (int i = 0; i < 16; i++) {
		   int row = i / 4;
		   int col = i % 4;
		   int value = Game2048->displaycell(row, col); // Get cell value from mainGame2048
		   this->labels[i]->Text = value > 0 ? value.ToString() : ""; // Display value or empty string
	   }
	   this->labels[16]->Text = Game2048->GetScore() > 0 ? Game2048->GetScore().ToString() : "";
	   
    }
};

}
