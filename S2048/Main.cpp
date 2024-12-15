#include "Main.h"
#include "Game.h"
#include "Windows.h"
#include "Class.h"
#include "Functions.h"
#include "Leaderboard.h"

using namespace System::IO;

using namespace System;
using namespace System::Windows::Forms;

[System::STAThread]

void main(cli::array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	
	S2048::Main form;
	System::Windows::Forms::Application::Run(% form);
}
System::Void S2048::Main::OpenGame(Object^ sender, EventArgs^ e) {
	if (textBox2->Text == "") { Game^ forma = gcnew Game();forma->ShowDialog(); }
	else if(textBox2->Text->Length < 20){ Game^ forma = gcnew Game(textBox2->Text, listData); forma->ShowDialog(); }
	else {
		MessageBox::Show("Your nickname >= 20 symbols");
	}
	//this->Hide();
	// 
	//mainGame2048 game;
}
System::Void S2048::Main::OpenLeaderboard(Object^ sender, EventArgs^ e) {
	Leaderboard^ formac = gcnew Leaderboard(listData);
	formac->ShowDialog();
}

System::Void S2048::Main::ExitApp(Object^ sender, EventArgs^ e) {
	Application::Exit();
}
