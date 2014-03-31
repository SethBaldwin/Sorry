#pragma once

#include <vector>
#include <string>
#include "Cell.h"

//vector<Cell> board_perim[2] = {(Cell p1(1, 569, 518, 0)),

int Board = 592; // Must be Divisible by 16.
int CellSize = Board/16;

int mouseX,mouseY; // Get Click location

vector<Cell> b;


void MakeBoard();
//Brush ^convertColor(int);

namespace Sorry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  draw;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->draw = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(560, 560);
			this->panel1->TabIndex = 0;
			// 
			// draw
			// 
			this->draw->Tick += gcnew System::EventHandler(this, &MyForm::draw_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 560);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Sorry!";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Graphics ^gp1;
		Brush ^yellow, ^green, ^blue, ^red;
		Pen ^black_p;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 MakeBoard();

				 ClientSize = System::Drawing::Size(Board+2, Board+2);
				 panel1->Size = System::Drawing::Size(Board+2, Board+2);

				 gp1 = panel1->CreateGraphics();

				 yellow = gcnew SolidBrush(Color::Yellow);
				 green = gcnew SolidBrush(Color::Green);
				 blue = gcnew SolidBrush(Color::Blue);
				 red = gcnew SolidBrush(Color::Red);

				 black_p = gcnew Pen(Color::Black, 3);


				 draw -> Enabled = true;

			 }
	private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {
				 for (int i = 0; i < b.size(); i++)
					 gp1 -> DrawRectangle(black_p,b[i].getLoc_x(),b[i].getLoc_y(),CellSize,CellSize);

				 //for (int i = 0; i < b.size(); i++)
					 //gp1 -> FillRectangle(convertColor(b[i].getColor()),b[i].getLoc_x(),b[i].getLoc_y(),CellSize,CellSize);

				 draw -> Enabled = false;
			 }

	};
}




void MakeBoard()
{
	int y = 0;
	for (int x = 0; x < 60; x++)
	{
		
		if (y%15==0)
			y=0;

		if(x < 15)
		{
			b.push_back(Cell (1, Board-CellSize*(x+1), Board-CellSize, 0));
		}
		else if(x < 30)
		{
			b.push_back(Cell (2, 0, Board-CellSize*(y+1), 0));
		}
		else if(x < 45)
		{
			b.push_back(Cell (3, Board-CellSize*(16-y), 0, 0));
		}
		else if(x < 60)
		{
			b.push_back(Cell (4, Board-CellSize, Board-CellSize*(16-y), 0));
		}
		y++;
	}


}

/*
Brush ^convertColor(int c)
{
	Brush ^col;
	if (c <= 4)
		col = gcnew SolidBrush(Color::Red);
	else if (c <= 8)
		col = gcnew SolidBrush(Color::Blue);
	else if (c <= 12)
		col = gcnew SolidBrush(Color::Yellow);
	else if (c <=16)
		col = gcnew SolidBrush(Color::Green);

	return col;
}
*/