#pragma once
#include "Data_.h"
#include "Main.h"
#include "ManualWrite.h"
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <algorithm>

namespace S2048 {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Ñâîäêà äëÿ Leaderboard
	/// </summary>
	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
		std::vector<Data_>* listdata2;
		std::vector<Data_>* listdataSQL;





		   BindingList<ManagedData^>^ managedDataList;
	public:
		Leaderboard(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}
		Leaderboard(std::vector<Data_>* listdata) {
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//

			connectionString = "Server=(localdb)\\MyFirstLocalDB;Database=DungeonMaster;Trusted_Connection=True;";
			//connectionString = "Server=(localdb)\\MSSQLLocalDB;Database=master;Trusted_Connection=True;";
			//connectionString = "Server=(localdb)\\MyLocalDB;Database=master;Trusted_Connection=True;"; // - Äîëæíî áûòü fail

			listdataSQL = new std::vector<Data_>;
			listdata2 = listdata;
			managedDataList = gcnew BindingList<ManagedData^>();


			this->LoadDataFromDatabase(this);
			for (auto& item : *listdata2) {
				listdataSQL->push_back(item);
			}

			for (auto& item : *listdataSQL)
			{
				managedDataList->Add(gcnew ManagedData(item.GetNick(), item.GetScore()));
			}

			this->SaveDataToDatabase(this);
			listdata2->clear();


			dataGridView1->DataSource = managedDataList;
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~Leaderboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âçàèìîäåéñòâèÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ èìïîğòÔàéëàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ıêñïîğòÔàéëàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğó÷íîéÂâîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ èçìåíåíèåÄàííûõToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ çàêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñîğòèğîâêàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîÍèêíåéìóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîÎ÷êàìToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container^ components;
		static bool CompareByNickname(const Data_& a, const Data_& b)
		{
			return a.GetNick() < b.GetNick();
		}
		static bool CompareByScore(const Data_& a, const Data_& b)
		{
			return a.GetScore() < b.GetScore();
		}

#pragma region Helper functions
		//bool CompareByNick(const Data_& a, const Data_& b) {
		//	return a.GetNick() < b.GetNick();
		//}
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âçàèìîäåéñòâèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èìïîğòÔàéëàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ıêñïîğòÔàéëàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğó÷íîéÂâîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èçìåíåíèåÄàííûõToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîğòèğîâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîÍèêíåéìóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîÎ÷êàìToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âçàèìîäåéñòâèÿToolStripMenuItem,
					this->çàêğûòüToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(691, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âçàèìîäåéñòâèÿToolStripMenuItem
			// 
			this->âçàèìîäåéñòâèÿToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->èìïîğòÔàéëàToolStripMenuItem,
					this->ıêñïîğòÔàéëàToolStripMenuItem, this->ğó÷íîéÂâîäToolStripMenuItem, this->èçìåíåíèåÄàííûõToolStripMenuItem, this->ñîğòèğîâêàToolStripMenuItem
			});
			this->âçàèìîäåéñòâèÿToolStripMenuItem->Name = L"âçàèìîäåéñòâèÿToolStripMenuItem";
			this->âçàèìîäåéñòâèÿToolStripMenuItem->Size = System::Drawing::Size(109, 20);
			this->âçàèìîäåéñòâèÿToolStripMenuItem->Text = L"Âçàèìîäåéñòâèÿ";
			// 
			// èìïîğòÔàéëàToolStripMenuItem
			// 
			this->èìïîğòÔàéëàToolStripMenuItem->Name = L"èìïîğòÔàéëàToolStripMenuItem";
			this->èìïîğòÔàéëàToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->èìïîğòÔàéëàToolStripMenuItem->Text = L"Èìïîğò ôàéëà";
			this->èìïîğòÔàéëàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::ImportCsvToDatabase);
			// 
			// ıêñïîğòÔàéëàToolStripMenuItem
			// 
			this->ıêñïîğòÔàéëàToolStripMenuItem->Name = L"ıêñïîğòÔàéëàToolStripMenuItem";
			this->ıêñïîğòÔàéëàToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ıêñïîğòÔàéëàToolStripMenuItem->Text = L"İêñïîğò ôàéëà";
			this->ıêñïîğòÔàéëàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::ExportDatabaseToFile);
			// 
			// ğó÷íîéÂâîäToolStripMenuItem
			// 
			this->ğó÷íîéÂâîäToolStripMenuItem->Name = L"ğó÷íîéÂâîäToolStripMenuItem";
			this->ğó÷íîéÂâîäToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ğó÷íîéÂâîäToolStripMenuItem->Text = L"Ğó÷íîé ââîä";
			this->ğó÷íîéÂâîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::ManualInput);
			// 
			// èçìåíåíèåÄàííûõToolStripMenuItem
			// 
			this->èçìåíåíèåÄàííûõToolStripMenuItem->Name = L"èçìåíåíèåÄàííûõToolStripMenuItem";
			this->èçìåíåíèåÄàííûõToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->èçìåíåíèåÄàííûõToolStripMenuItem->Text = L"Èçìåíåíèå äàííûõ";
			this->èçìåíåíèåÄàííûõToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::ChangeInput);
			// 
			// ñîğòèğîâêàToolStripMenuItem
			// 
			this->ñîğòèğîâêàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ïîÍèêíåéìóToolStripMenuItem,
					this->ïîÎ÷êàìToolStripMenuItem
			});
			this->ñîğòèğîâêàToolStripMenuItem->Name = L"ñîğòèğîâêàToolStripMenuItem";
			this->ñîğòèğîâêàToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ñîğòèğîâêàToolStripMenuItem->Text = L"Ñîğòèğîâêà";
			// 
			// ïîÍèêíåéìóToolStripMenuItem
			// 
			this->ïîÍèêíåéìóToolStripMenuItem->Name = L"ïîÍèêíåéìóToolStripMenuItem";
			this->ïîÍèêíåéìóToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->ïîÍèêíåéìóToolStripMenuItem->Text = L"Ïî íèêíåéìó";
			this->ïîÍèêíåéìóToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::SortDataNickname);
			// 
			// ïîÎ÷êàìToolStripMenuItem
			// 
			this->ïîÎ÷êàìToolStripMenuItem->Name = L"ïîÎ÷êàìToolStripMenuItem";
			this->ïîÎ÷êàìToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->ïîÎ÷êàìToolStripMenuItem->Text = L"Ïî î÷êàì";
			this->ïîÎ÷êàìToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::SortDataScore);
			// 
			// çàêğûòüToolStripMenuItem
			// 
			this->çàêğûòüToolStripMenuItem->Name = L"çàêğûòüToolStripMenuItem";
			this->çàêğûòüToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->çàêğûòüToolStripMenuItem->Text = L"Çàêğûòü";
			this->çàêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Leaderboard::CloseLeaderboard);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ScrollBar;
			this->dataGridView1->Location = System::Drawing::Point(12, 79);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(667, 260);
			this->dataGridView1->TabIndex = 1;
			// 
			// Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 373);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Leaderboard";
			this->Text = L"Leaderboard";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CloseLeaderboard(Object^ sender, EventArgs^ e) {
		this->Close();
	}


		   // Sort Data
	private: System::Void SortDataNickname(System::Object^ sender, System::EventArgs^ e)
		   {
			   std::sort(listdataSQL->begin(), listdataSQL->end(), CompareByNickname);
			   managedDataList->Clear();
			   for (auto& item : *listdataSQL)
			   {
				   managedDataList->Add(gcnew ManagedData(item.GetNick(), item.GetScore()));
			   }
			   MessageBox::Show("Data sorted by nickname.", "Sort Data");
			   this->SaveDataToDatabase(this);
		   }
	private: System::Void SortDataScore(System::Object^ sender, System::EventArgs^ e)
		   {
			   std::sort(listdataSQL->begin(), listdataSQL->end(), CompareByScore);
			   managedDataList->Clear();
			   for (auto& item : *listdataSQL)
			   {
				   managedDataList->Add(gcnew ManagedData(item.GetNick(), item.GetScore()));
			   }
			   MessageBox::Show("Data sorted by score.", "Sort Data");
			   this->SaveDataToDatabase(this);
		   }

	private: System::Void ExportFile(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		saveFileDialog1->Title = "Export Leaderboard";

		int nn = managedDataList->Count;
		int n = 0, counter = 0;
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
			while (counter <= nn) {

				if (counter == 0) {
					n = managedDataList->Count;
					sw->WriteLine(n);
				}
				else {
					sw->WriteLine(managedDataList[counter - 1]->Score);
					sw->WriteLine(managedDataList[counter - 1]->Nickname);
				}

				counter++;
			}// end while 
			sw->Close();
		}
	};
	private: System::Void ImportFile(System::Object ^ sender, System::EventArgs ^ e){
		String^ fileName;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "(*.txt)|*.txt";
		openFileDialog1->ShowDialog();
		fileName = openFileDialog1->FileName;

		

		String^ dataFrom;
		int n = 0, counter = 0;
		StreamReader^ reader = File::OpenText(fileName);
		dataFrom = reader->ReadLine();
		if (Convert::ToInt32(dataFrom) == 0) {
			MessageBox::Show("Íåò èíôîğìàöèè äëÿ èìïîğòà");
			return;
		}
		listdata2->clear();
		managedDataList->Clear();
		for (int i = 0; i < Convert::ToInt32(dataFrom); i++) {
			int score = Convert::ToInt32(reader->ReadLine());
			std::string nickname = msclr::interop::marshal_as<std::string>(reader->ReadLine());

			listdata2->push_back(Data_(nickname, score));
			managedDataList->Add(gcnew ManagedData(nickname, score));
		}
		reader->Close();
		MessageBox::Show("Data imported successfully.", "Import File");
	};
	private: System::Void ManualInput(System::Object^ sender, System::EventArgs^ e)
	{
		ManualWrite^ formad = gcnew ManualWrite(listdataSQL, false, managedDataList);  // 
		//this->Hide();
		formad->ShowDialog();

		this->SaveDataToDatabase(this);
		dataGridView1->DataSource = nullptr;
		dataGridView1->DataSource = managedDataList;
		this->Refresh();

	}
	private: System::Void ChangeInput(System::Object^ sender, System::EventArgs^ e) {
		ManualWrite^ formad = gcnew ManualWrite(listdataSQL, true, managedDataList);  // 
		formad->ShowDialog();
		dataGridView1->DataSource = nullptr;
		managedDataList->Clear();
		for (auto& item : *listdataSQL)
		{
			managedDataList->Add(gcnew ManagedData(item.GetNick(), item.GetScore()));
		}
		this->SaveDataToDatabase(this);
		dataGridView1->DataSource = managedDataList;
		//this->Refresh();
		}




	// SQL ïîäêëş÷àåì


	//private: System::Void TrySqlConnecton(System::Object^ sender, System::EventArgs^ e) {
	//	//connectionString = "Server=(localdb)\\MSSQLLocalDB;Database=master;Trusted_Connection=True;";
	//	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	//	try {
	//		connection->Open();
	//		MessageBox::Show("Connected to database successfully.", "SQL Connection");
	//	}
	//	catch (SqlException^ ex) {
	//		MessageBox::Show("Error connecting to database: " + ex->Message, "SQL Error");
	//	}
	//	connection->Close();
	//}

	private: System::Void ExportDatabaseToFile(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "CSV Files (*.csv)|*.csv|All Files (*.*)|*.*";
		saveFileDialog->Title = "Export Database to File";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ filePath = saveFileDialog->FileName;

				// Open database connection
				SqlConnection^ connection = gcnew SqlConnection(connectionString);
				connection->Open();

				// Fetch data from the database
				SqlCommand^ command = gcnew SqlCommand("SELECT Nickname, Score FROM Leaderboard;", connection);
				SqlDataReader^ reader = command->ExecuteReader();

				// Open a file to write
				StreamWriter^ writer = gcnew StreamWriter(filePath);

				// Write data to file
				writer->WriteLine("Nickname,Score"); // Header for CSV
				while (reader->Read()) {
					writer->WriteLine(reader["Nickname"]->ToString() + "," + reader["Score"]->ToString());
				}

				// Close resources
				reader->Close();
				connection->Close();
				writer->Close();

				MessageBox::Show("Database exported successfully to: " + filePath, "Export Successful");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error exporting database: " + ex->Message, "Export Error");
			}
		}
	}



	private: System::Void LoadDataFromDatabase(System::Object^ sender) {
			   try {
				   SqlConnection^ connection = gcnew SqlConnection(connectionString);
				   connection->Open();

				   SqlCommand^ command = gcnew SqlCommand("SELECT Nickname, Score FROM Leaderboard;", connection);
				   SqlDataReader^ reader = command->ExecuteReader();

				   //listdata2->clear();
				   //managedDataList->Clear();

				   while (reader->Read()) {
					   std::string nickname = msclr::interop::marshal_as<std::string>(reader["Nickname"]->ToString());
					   int score = Convert::ToInt32(reader["Score"]);

					   listdataSQL->push_back(Data_(nickname, score));
					   //managedDataList->Add(gcnew ManagedData(nickname, score));
				   }

				   connection->Close();
				   //dataGridView1->DataSource = managedDataList;
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error loading data from database: " + ex->Message, "Database Error");
			   }
		   }


	private: System::Void SaveDataToDatabase(System::Object^ sender) {
			   try {
				   SqlConnection^ connection = gcnew SqlConnection(connectionString);
				   connection->Open();
				   this->ClearDatabase(this);
				   for (int i = 0; i < managedDataList->Count; i++) {
					   SqlCommand^ command = gcnew SqlCommand(
						   "INSERT INTO Leaderboard (Nickname, Score) VALUES (@Nickname, @Score);", connection);
					   //command->Parameters->AddWithValue("@Id", i);
					   command->Parameters->AddWithValue("@Nickname", managedDataList[i]->Nickname);
					   command->Parameters->AddWithValue("@Score", managedDataList[i]->Score);
					   command->ExecuteNonQuery();
				   }

				   connection->Close();
				   //MessageBox::Show("Data saved to database.", "Save Data");
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error saving data to database: " + ex->Message, "Database Error");
			   }
		   }
	private: System::Void ClearDatabase(System::Object^ sender) {
		try {
			SqlConnection^ connection = gcnew SqlConnection(connectionString);
			connection->Open();

			SqlCommand^ command = gcnew SqlCommand("DELETE FROM Leaderboard;", connection);
			command->ExecuteNonQuery();

			connection->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error clearing database: " + ex->Message, "Database Error");
		}
	}




	private: System::Void ImportCsvToDatabase(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "CSV Files (*.csv)|*.csv|All Files (*.*)|*.*";
		openFileDialog->Title = "Import CSV File to Database";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ filePath = openFileDialog->FileName;

				// Open the CSV file for reading
				StreamReader^ reader = gcnew StreamReader(filePath);

				// Read the header line
				reader->ReadLine(); // Skip the CSV header

				// Open database connection
				SqlConnection^ connection = gcnew SqlConnection(connectionString);
				connection->Open();

				// Clear existing data in the database
				SqlCommand^ clearCommand = gcnew SqlCommand("DELETE FROM Leaderboard;", connection);
				clearCommand->ExecuteNonQuery();

				// Read each line from the CSV
				while (!reader->EndOfStream) {
					String^ line = reader->ReadLine();
					cli::array<String^>^ fields = line->Split(',');

					if (fields->Length == 2) {
						String^ nickname = fields[0]->Trim();
						int score = Convert::ToInt32(fields[1]->Trim());

						// Insert data into the database
						SqlCommand^ insertCommand = gcnew SqlCommand(
							"INSERT INTO Leaderboard (Nickname, Score) VALUES (@Nickname, @Score);", connection);
						insertCommand->Parameters->AddWithValue("@Nickname", nickname);
						insertCommand->Parameters->AddWithValue("@Score", score);
						insertCommand->ExecuteNonQuery();
					}
				}

				// Close resources
				reader->Close();
				connection->Close();

				managedDataList->Clear();
				listdataSQL->clear();
				this->LoadDataFromDatabase(this);
				for (auto& item : *listdataSQL)
				{
					managedDataList->Add(gcnew ManagedData(item.GetNick(), item.GetScore()));
				}
				dataGridView1->DataSource = nullptr;
				dataGridView1->DataSource = managedDataList;

				MessageBox::Show("File imported successfully into the database.", "Import Successful");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error importing file: " + ex->Message, "Import Error");
			}
		}
	}



	};
}


// C:\Users\<UserName>\AppData\Local\Microsoft\Microsoft SQL Server Local DB\Instances - Òóò õğàíÿòñÿ âñå ëîêàëüíûå ñåğâà÷êè