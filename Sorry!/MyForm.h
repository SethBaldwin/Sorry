#pragma once

#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include "Cell.h"
#include "pawns.h"
using namespace std;



int Board = 592; // Must be Divisible by 16. Cur = 592
int CellSize = Board/16; // = 37

int lastOc; //Stores last occupied pawn number for mouse up 

int mouseX,mouseY; // Get Click location
int pawnLoc; // Used in makeMove button to keep track of the pawns location in the board vector.


int turn = 0;

int pawn_number;
int card_number;

vector<int> cardInts;


vector<Cell> b;

vector<Pawns> red_Pawns;
vector<Cell> red_Start;
vector<Cell> red_Home;

vector<Pawns> blue_Pawns;
vector<Cell> blue_Start;
vector<Cell> blue_Home;

vector<Pawns> yellow_Pawns;
vector<Cell> yellow_Start;
vector<Cell> yellow_Home;

vector<Pawns> green_Pawns;
vector<Cell> green_Start;
vector<Cell> green_Home;


void MakeBoard();
void MakeStart();
void pawnSetup();
void makeDeck();

namespace Sorry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int getPawn(int, int);
	int getCell(int, int);
	Brush ^convertColor(int); //----------

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
	private: System::Windows::Forms::NumericUpDown^  pawnNum;

	private: System::Windows::Forms::Button^  drawCard;
	private: System::Windows::Forms::NumericUpDown^  cardNum;
	private: System::Windows::Forms::Button^  makeMove;
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
			this->pawnNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->drawCard = (gcnew System::Windows::Forms::Button());
			this->cardNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->makeMove = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pawnNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cardNum))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(560, 560);
			this->panel1->TabIndex = 0;
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// draw
			// 
			this->draw->Tick += gcnew System::EventHandler(this, &MyForm::draw_Tick);
			// 
			// pawnNum
			// 
			this->pawnNum->Location = System::Drawing::Point(635, 177);
			this->pawnNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, System::Int32::MinValue});
			this->pawnNum->Name = L"pawnNum";
			this->pawnNum->Size = System::Drawing::Size(72, 20);
			this->pawnNum->TabIndex = 1;
			// 
			// drawCard
			// 
			this->drawCard->Location = System::Drawing::Point(617, 36);
			this->drawCard->Name = L"drawCard";
			this->drawCard->Size = System::Drawing::Size(105, 31);
			this->drawCard->TabIndex = 2;
			this->drawCard->Text = L"Draw";
			this->drawCard->UseVisualStyleBackColor = true;
			this->drawCard->Click += gcnew System::EventHandler(this, &MyForm::drawCard_Click);
			// 
			// cardNum
			// 
			this->cardNum->Location = System::Drawing::Point(635, 82);
			this->cardNum->Name = L"cardNum";
			this->cardNum->Size = System::Drawing::Size(72, 20);
			this->cardNum->TabIndex = 3;
			// 
			// makeMove
			// 
			this->makeMove->Location = System::Drawing::Point(617, 118);
			this->makeMove->Name = L"makeMove";
			this->makeMove->Size = System::Drawing::Size(105, 35);
			this->makeMove->TabIndex = 4;
			this->makeMove->Text = L"Move";
			this->makeMove->UseVisualStyleBackColor = true;
			this->makeMove->Click += gcnew System::EventHandler(this, &MyForm::makeMove_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 560);
			this->Controls->Add(this->makeMove);
			this->Controls->Add(this->cardNum);
			this->Controls->Add(this->drawCard);
			this->Controls->Add(this->pawnNum);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Sorry!";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Move += gcnew System::EventHandler(this, &MyForm::draw_Tick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pawnNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cardNum))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Graphics ^gp1;
		Brush ^yellow, ^green, ^blue, ^red;
		Pen ^black_p;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 MakeBoard();
				 MakeStart();
				 pawnSetup();
				 makeDeck();

				 ClientSize = System::Drawing::Size(Board+200, Board+2);
				 panel1->Size = System::Drawing::Size(Board+2, Board+2);

				 gp1 = panel1->CreateGraphics();

				 yellow = gcnew SolidBrush(Color::Yellow);
				 green = gcnew SolidBrush(Color::Green);
				 blue = gcnew SolidBrush(Color::Blue);
				 red = gcnew SolidBrush(Color::Red);

				 black_p = gcnew Pen(Color::Black, 3); // 3 is importatne


				 draw -> Enabled = true;

			 }
	private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {
				 for (int i = 0; i < b.size(); i++)
					 gp1 -> DrawRectangle(black_p,b[i].getLoc_x(),b[i].getLoc_y(),CellSize,CellSize);

				 for (int i = 0; i < b.size(); i++)
					 gp1 -> FillRectangle(convertColor(b[i].getColor()), b[i].getLoc_x()+2, b[i].getLoc_y()+2, CellSize-3,CellSize-3);


				 for (int i = 0; i < red_Start.size(); i++)
					 gp1 -> DrawRectangle(black_p, red_Start[i].getLoc_x(), red_Start[i].getLoc_y(),CellSize,CellSize);
				 for (int i = 0; i < red_Home.size(); i++)
					 gp1 -> DrawRectangle(black_p, red_Home[i].getLoc_x(), red_Home[i].getLoc_y(),CellSize,CellSize);

				 for (int i = 0; i < blue_Start.size(); i++)
					 gp1 -> DrawRectangle(black_p, blue_Start[i].getLoc_x(), blue_Start[i].getLoc_y(),CellSize,CellSize);
				 for (int i = 0; i < blue_Home.size(); i++)
					 gp1 -> DrawRectangle(black_p, blue_Home[i].getLoc_x(), blue_Home[i].getLoc_y(),CellSize,CellSize);

				 for (int i = 0; i < yellow_Start.size(); i++)
					 gp1 -> DrawRectangle(black_p, yellow_Start[i].getLoc_x(), yellow_Start[i].getLoc_y(),CellSize,CellSize);
				 for (int i = 0; i < yellow_Home.size(); i++)
					 gp1 -> DrawRectangle(black_p, yellow_Home[i].getLoc_x(), yellow_Home[i].getLoc_y(), CellSize,CellSize);

				 for (int i = 0; i < green_Start.size(); i++)
					 gp1 -> DrawRectangle(black_p, green_Start[i].getLoc_x(), green_Start[i].getLoc_y(),CellSize,CellSize);
				 for (int i = 0; i < green_Home.size(); i++)
					 gp1 -> DrawRectangle(black_p, green_Home[i].getLoc_x(), green_Home[i].getLoc_y(), CellSize,CellSize);


				 //TODO, GET rid of all the shit above this todo. ie get bg picture

				 //
				 //////      PAWNS
				 //

				 for (int i = 0; i < red_Pawns.size(); i++)
					 gp1 -> FillRectangle(convertColor(red_Pawns[i].getCol()), red_Pawns[i].getLoc_x()+2, red_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);

				 for (int i = 0; i < blue_Pawns.size(); i++)
					 gp1 -> FillRectangle(convertColor(blue_Pawns[i].getCol()), blue_Pawns[i].getLoc_x()+2, blue_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);
				 
				 for (int i = 0; i < yellow_Pawns.size(); i++)
					 gp1 -> FillRectangle(convertColor(yellow_Pawns[i].getCol()), yellow_Pawns[i].getLoc_x()+2, yellow_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);
				 
				 for (int i = 0; i < green_Pawns.size(); i++)
					 gp1 -> FillRectangle(convertColor(green_Pawns[i].getCol()), green_Pawns[i].getLoc_x()+2, green_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);


				 draw -> Enabled = false;
			 }

	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mouseX = (e->X);
				 mouseY = (e->Y);

				 pawn_number = getPawn(mouseX,mouseY);

				 if (pawn_number >= 1 && pawn_number < 5)
					red_Pawns[pawn_number-1].setCol(5);
				 else if (pawn_number >= 5 && pawn_number < 9)
					blue_Pawns[pawn_number-5].setCol(5);
				 else if (pawn_number >= 9 && pawn_number < 13)
					yellow_Pawns[pawn_number-9].setCol(5);
				 else if (pawn_number >= 13)
					green_Pawns[pawn_number-13].setCol(5);

				 pawnNum->Value = pawn_number;

				 draw -> Enabled = true;

			 }

private: System::Void drawCard_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (cardInts.size() > 0)
			 {
				card_number = cardInts.back();
				cardNum -> Value = card_number; // For GUI to show what card was 'drawn'
				cardInts.pop_back();
			 }
			 else
				 makeDeck();
		 }
private: System::Void makeMove_Click(System::Object^  sender, System::EventArgs^  e) {
			 //IF for 4 colors.

			 //needs to check if a pawn is selected at all.

			 if (pawn_number >= 0 && pawn_number < 4)
			 {
				 int rpl = red_Pawns[pawn_number-1].getLoc(); //So i dont have to type that out every time.


				 //
				 //  FOR LEAVING START
				 //
				 if (red_Pawns[pawn_number-1].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 red_Pawns[pawn_number-1].setLoc_x( b[i+4].getLoc_x() );
							 red_Pawns[pawn_number-1].setLoc_y( b[i+4].getLoc_y() );
						 }
						 red_Pawns[pawn_number-1].setLoc(card_number+4);
						 //Todo isOccupied
					 }
					 else{}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }
				 //
				 // For Going around brim of board
				 //
				 else if (red_Pawns[pawn_number-1].getLoc() >= 0)
				 {
					 if (rpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-rpl); i++)
						 {
							 
							 red_Pawns[pawn_number-1].setLoc_x( b[rpl+i].getLoc_x() );
							 red_Pawns[pawn_number-1].setLoc_y( b[rpl+i].getLoc_y() );
							 //Todo IsSlide, Is Occupied
						 }
						 int tempPawnLocation = 0;
						 for (int i = 0; i < card_number-(59-rpl)-1; i++) // -1 because vector begins at 0
						 {
							 red_Pawns[pawn_number-1].setLoc_x( b[i].getLoc_x() );
							 red_Pawns[pawn_number-1].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
							 //Todo IsSafe -> So set pawn vector Location = -2 
							 
						 }

					 //Todo IsSlide -> which slide it is, and move accordingly and bump all non-teammate pawns
					 //Todo Is Occupied -> Bump(send other piece start) 
					 red_Pawns[pawn_number-1].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 red_Pawns[pawn_number-1].setLoc_x( b[rpl+i].getLoc_x() );
							 red_Pawns[pawn_number-1].setLoc_y( b[rpl+i].getLoc_y() );
						 }
					 red_Pawns[pawn_number-1].setLoc(rpl+card_number);
					 }

				 }
			 }

			 //
			 //////////////////////////////// BLUE //////////////////////////////////
			 //
			 else if (pawn_number >= 4 && pawn_number < 8)
			 {
				 int bpl = blue_Pawns[pawn_number-5].getLoc(); //So i dont have to type that out every time.

				 if (blue_Pawns[pawn_number-5].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 blue_Pawns[pawn_number-5].setLoc_x( b[i+19].getLoc_x() ); // + 19 because 1st space out of blue start is b[19].
							 blue_Pawns[pawn_number-5].setLoc_y( b[i+19].getLoc_y() );
						 }
						 blue_Pawns[pawn_number-5].setLoc(card_number+19);
					 }
					 else{}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }

				 else if (blue_Pawns[pawn_number-4].getLoc() >= 0)
				 {
					 if (bpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-bpl); i++)
						 {
							 blue_Pawns[pawn_number-4].setLoc_x( b[bpl+i].getLoc_x() );
							 blue_Pawns[pawn_number-4].setLoc_y( b[bpl+i].getLoc_y() );
						 }
						 int tempPawnLocation = 0;
						 for (int i = 0; i < card_number-(59-bpl)-1; i++) // -1 because vector begins at 0
						 {
							 blue_Pawns[pawn_number-4].setLoc_x( b[i].getLoc_x() );
							 blue_Pawns[pawn_number-4].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
						 }
					 blue_Pawns[pawn_number-4].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 blue_Pawns[pawn_number-4].setLoc_x( b[bpl+i].getLoc_x() );
							 blue_Pawns[pawn_number-4].setLoc_y( b[bpl+i].getLoc_y() );
						 }
					 blue_Pawns[pawn_number-4].setLoc(bpl+card_number);
					 }
				 }
			 }
			 //
			 ////////////////// YELLOW //////////////////////
			 //
			 else if (pawn_number >= 8 && pawn_number < 12)
			 {
				 int gpl = yellow_Pawns[pawn_number-8].getLoc(); //So i dont have to type that out every time.

				 if (yellow_Pawns[pawn_number-8].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 yellow_Pawns[pawn_number-8].setLoc_x( b[i+34].getLoc_x() ); // + 19 because 1st space out of yellow start is b[19].
							 yellow_Pawns[pawn_number-8].setLoc_y( b[i+34].getLoc_y() );
						 }
						 yellow_Pawns[pawn_number-8].setLoc(card_number+34);
					 }
					 else{}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }

				 else if (yellow_Pawns[pawn_number-8].getLoc() >= 0)
				 {
					 if (gpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-gpl); i++)
						 {
							 yellow_Pawns[pawn_number-8].setLoc_x( b[gpl+i].getLoc_x() );
							 yellow_Pawns[pawn_number-8].setLoc_y( b[gpl+i].getLoc_y() );
						 }
						 int tempPawnLocation = 0;
						 for (int i = 0; i < card_number-(59-gpl)-1; i++) // -1 because vector begins at 0
						 {
							 yellow_Pawns[pawn_number-8].setLoc_x( b[i].getLoc_x() );
							 yellow_Pawns[pawn_number-8].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
						 }
					 yellow_Pawns[pawn_number-8].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 yellow_Pawns[pawn_number-8].setLoc_x( b[gpl+i].getLoc_x() );
							 yellow_Pawns[pawn_number-8].setLoc_y( b[gpl+i].getLoc_y() );
						 }
					 yellow_Pawns[pawn_number-8].setLoc(gpl+card_number);
					 }
				 }
			 }
			 //
			 ////////////////// GREEN //////////////////////
			 //
			 else if (pawn_number >= 13)
			 {
				 int gpl = green_Pawns[pawn_number-13].getLoc(); //So i dont have to type that out every time.

				 if (green_Pawns[pawn_number-13].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[i+49].getLoc_x() ); // + 19 because 1st space out of green start is b[19].
							 green_Pawns[pawn_number-13].setLoc_y( b[i+49].getLoc_y() );
						 }
						 green_Pawns[pawn_number-13].setLoc(card_number+49);
					 }
					 else{}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }

				 else if (green_Pawns[pawn_number-13].getLoc() >= 0)
				 {
					 if (gpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-gpl); i++)
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[gpl+i].getLoc_x() );
							 green_Pawns[pawn_number-13].setLoc_y( b[gpl+i].getLoc_y() );
						 }
						 int tempPawnLocation = 0;
						 for (int i = 0; i < card_number-(59-gpl)-1; i++) // -1 because vector begins at 0
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[i].getLoc_x() );
							 green_Pawns[pawn_number-13].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
						 }
					 green_Pawns[pawn_number-13].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 0; i < card_number; i++)
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[gpl+i].getLoc_x() );
							 green_Pawns[pawn_number-13].setLoc_y( b[gpl+i].getLoc_y() );
						 }
					 green_Pawns[pawn_number-13].setLoc(gpl+card_number);
					 }
				 }
			 }



			 draw -> Enabled = true;
		 }
};


Brush ^convertColor(int c)
{
	Brush ^col; // TODO Fucking pictures or somthing god dammit
	if (c == 1)
		col = gcnew SolidBrush(Color::Red);
	else if (c == 2)
		col = gcnew SolidBrush(Color::Blue);
	else if (c == 3)
		col = gcnew SolidBrush(Color::Yellow);
	else if (c == 4)
		col = gcnew SolidBrush(Color::Green);
	else if (c == 5)
		col = gcnew SolidBrush(Color::Pink);

	return col;
}

int getCell(int x, int y)
{
	for (int i = 0; i < 60; i++)
	{
		if (  ((x - b[i].getLoc_x() < 37) && (y - b[i].getLoc_y()) < 37)  &&  ((x - b[i].getLoc_x() > 0) && (y - b[i].getLoc_y()) > 0) )
			return i;
	}
	return -1;
}

int getPawn(int x, int y)
{
	for (int i = 0; i < red_Pawns.size(); i++)
	{
		if (  ((x - red_Pawns[i].getLoc_x() < 37) && (y - red_Pawns[i].getLoc_y()) < 37)  &&  ((x - red_Pawns[i].getLoc_x() > 0) && (y - red_Pawns[i].getLoc_y()) > 0) )
			return red_Pawns[i].getNum();
	}

	for (int i = 0; i < blue_Pawns.size(); i++)
	{
		if (  ((x - blue_Pawns[i].getLoc_x() < 37) && (y - blue_Pawns[i].getLoc_y()) < 37)  &&  ((x - blue_Pawns[i].getLoc_x() > 0) && (y - blue_Pawns[i].getLoc_y()) > 0) )
			return blue_Pawns[i].getNum();
	}

	for (int i = 0; i < yellow_Pawns.size(); i++)
	{
		if (  ((x - yellow_Pawns[i].getLoc_x() < 37) && (y - yellow_Pawns[i].getLoc_y()) < 37)  &&  ((x - yellow_Pawns[i].getLoc_x() > 0) && (y - yellow_Pawns[i].getLoc_y()) > 0) )
			return yellow_Pawns[i].getNum();
	}

	for (int i = 0; i < green_Pawns.size(); i++)
	{
		if (  ((x - green_Pawns[i].getLoc_x() < 37) && (y - green_Pawns[i].getLoc_y()) < 37)  &&  ((x - green_Pawns[i].getLoc_x() > 0) && (y - green_Pawns[i].getLoc_y()) > 0) )
			return green_Pawns[i].getNum();
	}


	return -1;
}

}


void MakeBoard() // Makes the brim cells of the playing board
{
	int y = 0;
	for (int x = 0; x < 60; x++)
	{
		if (y%15==0)
			y=0;

		if(x < 15)
		{
			b.push_back(Cell (1, Board-CellSize*(x+1), Board-CellSize, 0));//(x+1)
		}
		else if(x < 30)
		{
			b.push_back(Cell (2, 0, Board-CellSize*(y+1), 0));//(y+1)
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

void MakeStart()
{
	///////////////////////// RED

	red_Start.push_back(Cell (1, (Board-CellSize*5), (Board-CellSize*2), 0));
	red_Start.push_back(Cell (1, (Board-CellSize*6)+(CellSize/2), (Board-CellSize*3)+(CellSize/2), 0));
	red_Start.push_back(Cell (1, (Board-CellSize*5)+(CellSize/2), (Board-CellSize*3)+(CellSize/2), 0));
	red_Start.push_back(Cell (1, (Board-CellSize*5), (Board-CellSize*3), 0));

	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*3), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*4), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*5), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*6), 0));

	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*8), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*4)+(CellSize/2), (Board-CellSize*8)+(CellSize/2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3)+(CellSize/2), (Board-CellSize*8)+(CellSize/2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*7), 0));

	////////////////////////// BLUE

	blue_Start.push_back(Cell (2, (Board-CellSize*15), (Board-CellSize*5), 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*15)+(CellSize/2), (Board-CellSize*6)+(CellSize/2), 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*15)+(CellSize/2), (Board-CellSize*5)+(CellSize/2), 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*14), (Board-CellSize*5), 0));

	blue_Home.push_back(Cell (2, (Board-CellSize*15), (Board-CellSize*3), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*14), (Board-CellSize*3), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*13), (Board-CellSize*3), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*12), (Board-CellSize*3), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*11), (Board-CellSize*3), 0));

	blue_Home.push_back(Cell (2, (Board-CellSize*10), (Board-CellSize*3), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*10)+(CellSize/2), (Board-CellSize*3)+(CellSize/2), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*10)+(CellSize/2), (Board-CellSize*4)+(CellSize/2), 0));
	blue_Home.push_back(Cell (2, (Board-CellSize*9), (Board-CellSize*3), 0));

	////////////////////////// YELLOW

	yellow_Start.push_back(Cell (3, (Board-CellSize*12), (Board-CellSize*15), 0));
	yellow_Start.push_back(Cell (3, (Board-CellSize*13)+(CellSize/2), (Board-CellSize*15)+(CellSize/2), 0));
	yellow_Start.push_back(Cell (3, (Board-CellSize*12)+(CellSize/2), (Board-CellSize*15)+(CellSize/2), 0));
	yellow_Start.push_back(Cell (3, (Board-CellSize*12), (Board-CellSize*14), 0));

	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*15), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*14), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*13), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*12), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*11), 0));

	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*10), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14)+(CellSize/2), (Board-CellSize*10)+(CellSize/2), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*15)+(CellSize/2), (Board-CellSize*10)+(CellSize/2), 0));
	yellow_Home.push_back(Cell (3, (Board-CellSize*14), (Board-CellSize*9), 0));

	////////////////////////// GREEN

	green_Start.push_back(Cell (4, (Board-CellSize*2), (Board-CellSize*12), 0));
	green_Start.push_back(Cell (4, (Board-CellSize*3)+(CellSize/2), (Board-CellSize*13)+(CellSize/2), 0));
	green_Start.push_back(Cell (4, (Board-CellSize*3)+(CellSize/2), (Board-CellSize*12)+(CellSize/2), 0));
	green_Start.push_back(Cell (4, (Board-CellSize*3), (Board-CellSize*12), 0));

	green_Home.push_back(Cell (4, (Board-CellSize*2), (Board-CellSize*14), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*3), (Board-CellSize*14), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*4), (Board-CellSize*14), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*5), (Board-CellSize*14), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*6), (Board-CellSize*14), 0));

	green_Home.push_back(Cell (4, (Board-CellSize*8), (Board-CellSize*14), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*8)+(CellSize/2), (Board-CellSize*14)+(CellSize/2), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*8)+(CellSize/2), (Board-CellSize*15)+(CellSize/2), 0));
	green_Home.push_back(Cell (4, (Board-CellSize*7), (Board-CellSize*14), 0));
}

void pawnSetup()
{
	//todo MAKE ALL OF THEM
	red_Pawns.push_back(Pawns (1, red_Start[0].getLoc_x(), red_Start[0].getLoc_y(), 1, -1));
	red_Pawns.push_back(Pawns (1, red_Start[1].getLoc_x(), red_Start[1].getLoc_y(), 2, -1));
	red_Pawns.push_back(Pawns (1, red_Start[2].getLoc_x(), red_Start[2].getLoc_y(), 3, -1));
	red_Pawns.push_back(Pawns (1, red_Start[3].getLoc_x(), red_Start[3].getLoc_y(), 4, -1));

	blue_Pawns.push_back(Pawns (2, blue_Start[0].getLoc_x(), blue_Start[0].getLoc_y(), 5, -1));
	blue_Pawns.push_back(Pawns (2, blue_Start[1].getLoc_x(), blue_Start[1].getLoc_y(), 6, -1));
	blue_Pawns.push_back(Pawns (2, blue_Start[2].getLoc_x(), blue_Start[2].getLoc_y(), 7, -1));
	blue_Pawns.push_back(Pawns (2, blue_Start[3].getLoc_x(), blue_Start[3].getLoc_y(), 8, -1));

	yellow_Pawns.push_back(Pawns (3, yellow_Start[0].getLoc_x(), yellow_Start[0].getLoc_y(), 9, -1));
	yellow_Pawns.push_back(Pawns (3, yellow_Start[1].getLoc_x(), yellow_Start[1].getLoc_y(), 10, -1));
	yellow_Pawns.push_back(Pawns (3, yellow_Start[2].getLoc_x(), yellow_Start[2].getLoc_y(), 11, -1));
	yellow_Pawns.push_back(Pawns (3, yellow_Start[3].getLoc_x(), yellow_Start[3].getLoc_y(), 12, -1));
	
	green_Pawns.push_back(Pawns (4, green_Start[0].getLoc_x(), green_Start[0].getLoc_y(), 13, -1));
	green_Pawns.push_back(Pawns (4, green_Start[1].getLoc_x(), green_Start[1].getLoc_y(), 14, -1));
	green_Pawns.push_back(Pawns (4, green_Start[2].getLoc_x(), green_Start[2].getLoc_y(), 15, -1));
	green_Pawns.push_back(Pawns (4, green_Start[3].getLoc_x(), green_Start[3].getLoc_y(), 16, -1));
}


void makeDeck()
{
	int cr[] = {1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,7,7,7,7,8,8,8,8,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
	cardInts.assign(cr, cr + sizeof cr / sizeof cr[0]);
	random_shuffle( cardInts.begin(), cardInts.end() );
}