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


int turn = 0; // Starts on 0 for red

int pawn_number;// 1-
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
	bool isSafe();
	bool isSafe(int);

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


	private: System::Windows::Forms::Button^  drawCard;

	private: System::Windows::Forms::Button^  makeMove;




	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Label^  lblPlayer;
	private: System::Windows::Forms::Label^  lblInstruction;
	private: System::Windows::Forms::Label^  lblPawn;
	private: System::Windows::Forms::Label^  lblError;
	private: System::Windows::Forms::Timer^  check;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  title_panel;

	private: System::Windows::Forms::Button^  begin;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->draw = (gcnew System::Windows::Forms::Timer(this->components));
			this->drawCard = (gcnew System::Windows::Forms::Button());
			this->makeMove = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblPlayer = (gcnew System::Windows::Forms::Label());
			this->lblInstruction = (gcnew System::Windows::Forms::Label());
			this->lblPawn = (gcnew System::Windows::Forms::Label());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->check = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->title_panel = (gcnew System::Windows::Forms::Panel());
			this->begin = (gcnew System::Windows::Forms::Button());
			this->title_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(593, 594);
			this->panel1->TabIndex = 0;
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// draw
			// 
			this->draw->Tick += gcnew System::EventHandler(this, &MyForm::draw_Tick);
			// 
			// drawCard
			// 
			this->drawCard->Cursor = System::Windows::Forms::Cursors::Default;
			this->drawCard->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->drawCard->Location = System::Drawing::Point(623, 60);
			this->drawCard->Margin = System::Windows::Forms::Padding(1, 3, 1, 3);
			this->drawCard->Name = L"drawCard";
			this->drawCard->Size = System::Drawing::Size(123, 40);
			this->drawCard->TabIndex = 2;
			this->drawCard->Text = L"Draw Card";
			this->drawCard->UseVisualStyleBackColor = true;
			this->drawCard->Click += gcnew System::EventHandler(this, &MyForm::drawCard_Click);
			// 
			// makeMove
			// 
			this->makeMove->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->makeMove->Enabled = false;
			this->makeMove->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->makeMove->Location = System::Drawing::Point(604, 255);
			this->makeMove->Name = L"makeMove";
			this->makeMove->Size = System::Drawing::Size(173, 45);
			this->makeMove->TabIndex = 4;
			this->makeMove->Text = L"Move";
			this->makeMove->UseVisualStyleBackColor = true;
			this->makeMove->Click += gcnew System::EventHandler(this, &MyForm::makeMove_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(641, 515);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 35);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Bump!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::bump);
			// 
			// lblPlayer
			// 
			this->lblPlayer->BackColor = System::Drawing::Color::Silver;
			this->lblPlayer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblPlayer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblPlayer->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPlayer->ForeColor = System::Drawing::Color::Red;
			this->lblPlayer->Location = System::Drawing::Point(604, 9);
			this->lblPlayer->Name = L"lblPlayer";
			this->lblPlayer->Size = System::Drawing::Size(173, 37);
			this->lblPlayer->TabIndex = 12;
			this->lblPlayer->Text = L"Red\'s Turn";
			this->lblPlayer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblInstruction
			// 
			this->lblInstruction->BackColor = System::Drawing::Color::Silver;
			this->lblInstruction->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblInstruction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblInstruction->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblInstruction->Location = System::Drawing::Point(604, 114);
			this->lblInstruction->Name = L"lblInstruction";
			this->lblInstruction->Size = System::Drawing::Size(173, 88);
			this->lblInstruction->TabIndex = 13;
			this->lblInstruction->Text = L"Draw a card";
			this->lblInstruction->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblPawn
			// 
			this->lblPawn->BackColor = System::Drawing::Color::Silver;
			this->lblPawn->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblPawn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblPawn->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPawn->Location = System::Drawing::Point(604, 202);
			this->lblPawn->Name = L"lblPawn";
			this->lblPawn->Size = System::Drawing::Size(173, 37);
			this->lblPawn->TabIndex = 14;
			this->lblPawn->Text = L"No pawn selected";
			this->lblPawn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblError
			// 
			this->lblError->BackColor = System::Drawing::Color::Silver;
			this->lblError->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblError->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblError->Location = System::Drawing::Point(604, 338);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(173, 119);
			this->lblError->TabIndex = 15;
			this->lblError->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// check
			// 
			this->check->Tick += gcnew System::EventHandler(this, &MyForm::check_Tick);
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Location = System::Drawing::Point(604, 323);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(173, 149);
			this->panel2->TabIndex = 16;
			// 
			// title_panel
			// 
			this->title_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"title_panel.BackgroundImage")));
			this->title_panel->Controls->Add(this->begin);
			this->title_panel->Location = System::Drawing::Point(0, 0);
			this->title_panel->Name = L"title_panel";
			this->title_panel->Size = System::Drawing::Size(799, 594);
			this->title_panel->TabIndex = 17;
			// 
			// begin
			// 
			this->begin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"begin.BackgroundImage")));
			this->begin->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->begin->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->begin->Location = System::Drawing::Point(140, 166);
			this->begin->Name = L"begin";
			this->begin->Size = System::Drawing::Size(172, 73);
			this->begin->TabIndex = 0;
			this->begin->Text = L"Begin";
			this->begin->UseVisualStyleBackColor = true;
			this->begin->Click += gcnew System::EventHandler(this, &MyForm::begin_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(784, 594);
			this->Controls->Add(this->title_panel);
			this->Controls->Add(this->lblPawn);
			this->Controls->Add(this->lblInstruction);
			this->Controls->Add(this->lblPlayer);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->makeMove);
			this->Controls->Add(this->drawCard);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->panel2);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Sorry!";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->title_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		Graphics ^gp1;
		Brush ^yellow, ^green, ^blue, ^red;
		Pen ^black_p;
		Image ^redPawn, ^bluePawn, ^yellowPawn, ^greenPawn;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 MakeBoard();
				 MakeStart();
				 pawnSetup();
				 makeDeck();

				 ClientSize = System::Drawing::Size(Board+200, Board+2);
				 panel1->Size = System::Drawing::Size(Board+2, Board+2);

				 gp1 = panel1->CreateGraphics();


				 redPawn = System::Drawing::Image::FromFile("images\\redPawn.png");
				 bluePawn = System::Drawing::Image::FromFile("images\\bluePawn.png");
				 yellowPawn = System::Drawing::Image::FromFile("images\\yellowPawn.png");
				 greenPawn = System::Drawing::Image::FromFile("images\\greenPawn.png");

				 yellow = gcnew SolidBrush(Color::Yellow);
				 green = gcnew SolidBrush(Color::Green);
				 blue = gcnew SolidBrush(Color::Blue);
				 red = gcnew SolidBrush(Color::Red);

				 black_p = gcnew Pen(Color::Black, 3); // 3 is importatne


				 draw -> Enabled = true;


			 }
	private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {

				 //
				 //////      PAWNS
				 //

				 Refresh();// TODO

				 //TODO show pawns moving every space

				 for (int i = 0; i < red_Pawns.size(); i++)
					 gp1 -> DrawImage(redPawn, red_Pawns[i].getLoc_x()+1, red_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);

				 for (int i = 0; i < blue_Pawns.size(); i++)
					 gp1 -> DrawImage(bluePawn, blue_Pawns[i].getLoc_x()+2, blue_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);

				 for (int i = 0; i < yellow_Pawns.size(); i++)
					 gp1 -> DrawImage(yellowPawn, yellow_Pawns[i].getLoc_x()+2, yellow_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);
				 
				 for (int i = 0; i < green_Pawns.size(); i++)
					 gp1 -> DrawImage(greenPawn, green_Pawns[i].getLoc_x()+2, green_Pawns[i].getLoc_y()+2, CellSize-3,CellSize-3);




				 draw -> Enabled = false;
			 }

	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mouseX = (e->X);
				 mouseY = (e->Y);

				 pawn_number = getPawn(mouseX,mouseY);

				 if (pawn_number >= 1 && pawn_number < 5)
					 lblPawn -> Text = "Red pawn " + pawn_number;
				 else if (pawn_number >= 5 && pawn_number < 9)
					 lblPawn -> Text = "Blue pawn " + (pawn_number-4);
				 else if (pawn_number >= 9 && pawn_number < 13)
					 lblPawn -> Text = "Yellow pawn " + (pawn_number-8);
				 else if (pawn_number >= 13)
					 lblPawn -> Text = "Green pawn " + (pawn_number-12);
				 else
					 lblPawn -> Text = "No Pawn Selected ";



			 }
private: System::Void bump(System::Object^  sender, System::EventArgs^  e){
		 
		

			 if (pawn_number >= 1 && pawn_number < 5)
			 {
				 red_Pawns[pawn_number-1].setLoc(-1);
				 red_Pawns[pawn_number-1].setLoc_x( red_Start[pawn_number-1].getLoc_x() );
				 red_Pawns[pawn_number-1].setLoc_y( red_Start[pawn_number-1].getLoc_y() );
			 }
			 else if (pawn_number >= 5 && pawn_number < 9)
			 {
				 blue_Pawns[pawn_number-5].setLoc(-1);
				 blue_Pawns[pawn_number-5].setLoc_x( blue_Start[pawn_number-5].getLoc_x() );
				 blue_Pawns[pawn_number-5].setLoc_y( blue_Start[pawn_number-5].getLoc_y() );
			 }
			 else if (pawn_number >= 9 && pawn_number < 13)
			 {
				 yellow_Pawns[pawn_number-9].setLoc(-1);
				 yellow_Pawns[pawn_number-9].setLoc_x( yellow_Start[pawn_number-9].getLoc_x() );
				 yellow_Pawns[pawn_number-9].setLoc_y( yellow_Start[pawn_number-9].getLoc_y() );
			 }
			 else if (pawn_number >= 13 && pawn_number < 17)
			 {
				 green_Pawns[pawn_number-13].setLoc(-1);
				 green_Pawns[pawn_number-13].setLoc_x( green_Start[pawn_number-13].getLoc_x() );
				 green_Pawns[pawn_number-13].setLoc_y( green_Start[pawn_number-13].getLoc_y() );
			 }
			 draw -> Enabled = true;
		 
		 }

private: System::Void drawCard_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (cardInts.size() > 0)
			 {
				card_number = cardInts.back();
				cardInts.pop_back();
			 }
			 else
				 makeDeck();

			 lblError -> Text = "";

			 switch(turn)
			 {
			 case 0:
				 //lblPlayer -> Text = "Red's Turn";
				 lblInstruction -> Text = "You drew a " + card_number + "\n Select pawn to move"; // For GUI to show what card was 'drawn'

				 break;
			 case 1:
				 //lblPlayer -> Text = "Blue's Turn";
				 lblInstruction -> Text = "You drew a " + card_number + "\n Select pawn to move";
				 break;
			 case 2:
				 //lblPlayer -> Text = "Yellow's Turn";
				 lblInstruction -> Text = "You drew a " + card_number + "\n Select pawn to move";
				 break;
			 case 3:
				 //lblPlayer -> Text = "Green's Turn";
				 lblInstruction -> Text = "You drew a " + card_number + "\n Select pawn to move";
				 break;
			 }

			 check -> Enabled = true;


		 }
private: System::Void makeMove_Click(System::Object^  sender, System::EventArgs^  e) {
			 //IF for 4 colors.


			 //needs to check if a pawn is selected at all.


			 //
			 //////////////////////////////// RED //////////////////////////////////
			 //

			 if (pawn_number >= 1 && pawn_number < 5)
			 {
				 int rpl = red_Pawns[pawn_number-1].getLoc(); //So i dont have to type that out every time.

				 //
				 //  FOR LEAVING START
				 //
				 if (red_Pawns[pawn_number-1].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 1; i <= card_number; i++)// Continue for other colors
						 {
							 red_Pawns[pawn_number-1].setLoc_x( b[i+3].getLoc_x() );// Continue for other colors
							 red_Pawns[pawn_number-1].setLoc_y( b[i+3].getLoc_y() );// Continue for other colors
						 }
						 red_Pawns[pawn_number-1].setLoc(card_number+3);// Continue for other colors
						 //Todo isOccupied
					 }
					 else{
						 lblError -> Text = "You can only leave start on a 1 or 2.";
					 }//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }
				 //
				 // For Going around brim of board
				 //

				 else if (red_Pawns[pawn_number-1].getLoc() >= 0 && red_Pawns[pawn_number-1].getLoc() < 60)
				 {
					 if (rpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-rpl); i++)
						 {
							 
							 red_Pawns[pawn_number-1].setLoc_x( b[rpl+i].getLoc_x() );
							 red_Pawns[pawn_number-1].setLoc_y( b[rpl+i].getLoc_y() );
							 //Todo IsSlide, Is Occupied
						 }

						 int tempPawnLocation = -1;
						 int iC = 0; // The counter used for moving into the safe zone
						 red_Pawns[pawn_number-1].setLoc(0);

						 for (int i = 0; i < card_number-(59-rpl); i++) // -1 because vector begins at 0  // Continue for other colors and removed -1
						 {
							 if (i <= 2)
							 {
								 red_Pawns[pawn_number-1].setLoc_x( b[i].getLoc_x() );
								 red_Pawns[pawn_number-1].setLoc_y( b[i].getLoc_y() );
								 red_Pawns[pawn_number-1].setLoc(i);
								 tempPawnLocation++;
							 }
							 //Todo IsSafe -> So set pawn vector Location = -2 
							 else if (isSafe(1))
							 {
								 red_Pawns[pawn_number-1].setLoc_x( red_Home[iC].getLoc_x() );
								 red_Pawns[pawn_number-1].setLoc_y( red_Home[iC].getLoc_y() );
								 iC++;
							 }
							 
						 }

						 //Todo IsSlide -> which slide it is, and move accordingly and bump all non-teammate pawns
						 //Todo Is Occupied -> Bump(send other piece start) 
						 if (!isSafe())
							red_Pawns[pawn_number-1].setLoc(tempPawnLocation);
						 else if (isSafe(1))
							 red_Pawns[pawn_number-1].setLoc(99+iC);
					 }

					 else
					 {
						 int iC = 0;
						 for (int i = 1; i <= card_number; i++)// Continue for other colors
						 {
							 if (!isSafe())
							 {
								 red_Pawns[pawn_number-1].setLoc_x( b[rpl+i].getLoc_x() );
								 red_Pawns[pawn_number-1].setLoc_y( b[rpl+i].getLoc_y() );
							 }
							 else if (isSafe())
							 {
								 red_Pawns[pawn_number-1].setLoc_x( red_Home[iC].getLoc_x() );
								 red_Pawns[pawn_number-1].setLoc_y( red_Home[iC].getLoc_y() );
								 iC++;
							 }

							 
						 }
						 if (!isSafe())
							 red_Pawns[pawn_number-1].setLoc(rpl+card_number);
						 else if (isSafe())
							 red_Pawns[pawn_number-1].setLoc(99+iC);
					 }
				 }
				 else if (rpl >= 100 && rpl <= 104)
				 {
					 if ( rpl + card_number <= 104)
					 {
						 for (int i = 1; i <= card_number; i++)// Continue for other colors
							 {
								 red_Pawns[pawn_number-1].setLoc_x( red_Home[(rpl+i)-100].getLoc_x() );
								 red_Pawns[pawn_number-1].setLoc_y( red_Home[(rpl+i)-100].getLoc_y() );
							 }
						 red_Pawns[pawn_number-1].setLoc(rpl+card_number);
					 }
					 else if (rpl + card_number == 105)
					 {
						 red_Pawns[pawn_number-1].setLoc_x( red_Home[5+pawn_number-1].getLoc_x() );
						 red_Pawns[pawn_number-1].setLoc_y( red_Home[5+pawn_number-1].getLoc_y() );
					 }

				 }
			 }
			 //if (pawn_number < 4 && pawn_number >= 0)


			 //
			 //////////////////////////////// BLUE //////////////////////////////////
			 //
			 else if (pawn_number >= 5 && pawn_number < 9)
			 {
				 int bpl = blue_Pawns[pawn_number-5].getLoc(); //So i dont have to type that out every time.

				 if (blue_Pawns[pawn_number-5].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 1; i <= card_number; i++)
						 {
							 blue_Pawns[pawn_number-5].setLoc_x( b[i+18].getLoc_x() ); // + 18 because 1st space out of blue start is b[19].
							 blue_Pawns[pawn_number-5].setLoc_y( b[i+18].getLoc_y() );
						 }
						 blue_Pawns[pawn_number-5].setLoc(card_number+18);
					 }
					 else{}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }
				 //
				 // For Going around brim of board
				 //
				 else if (blue_Pawns[pawn_number-5].getLoc() >= 0)
				 {
					 if (bpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-bpl); i++)
						 {
							 blue_Pawns[pawn_number-5].setLoc_x( b[bpl+i].getLoc_x() );
							 blue_Pawns[pawn_number-5].setLoc_y( b[bpl+i].getLoc_y() );
							 //Todo IsSlide, Is Occupied
						 }
						 int tempPawnLocation = -1;
						 for (int i = 0; i < card_number-(59-bpl); i++) // -1 because vector begins at 0
						 {
							 blue_Pawns[pawn_number-5].setLoc_x( b[i].getLoc_x() );
							 blue_Pawns[pawn_number-5].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
							 //Todo IsSafe -> So set pawn vector Location = -2 
						 }
					 //Todo IsSlide -> which slide it is, and move accordingly and bump all non-teammate pawns
					 //Todo Is Occupied -> Bump(send other piece start) 
					 blue_Pawns[pawn_number-5].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 1; i <= card_number; i++)
						 {
							 blue_Pawns[pawn_number-5].setLoc_x( b[bpl+i].getLoc_x() );
							 blue_Pawns[pawn_number-5].setLoc_y( b[bpl+i].getLoc_y() );
						 }
					 blue_Pawns[pawn_number-5].setLoc(bpl+card_number);
					 }
				 }
			 }
			 //
			 ////////////////// YELLOW //////////////////////
			 //
			 else if (pawn_number >= 9 && pawn_number < 13)
			 {
				 int gpl = yellow_Pawns[pawn_number-9].getLoc(); //So i dont have to type that out every time.

				 if (yellow_Pawns[pawn_number-9].getLoc() == -1)// For exiting Start
				 {
					 if (card_number <= 2) // Pawn can only leave if a 1 or 2 is drawn.
					 {
						 for (int i = 1; i <= card_number; i++)
						 {
							 yellow_Pawns[pawn_number-9].setLoc_x( b[i+33].getLoc_x() ); // + 33 because 1st space out of yellow start is b[19].
							 yellow_Pawns[pawn_number-9].setLoc_y( b[i+33].getLoc_y() );
						 }
						 yellow_Pawns[pawn_number-9].setLoc(card_number+33);
					 }
					 else{lblError -> Text = "You can only leave start on a 1 or 2.";}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
				 }

				 else if (yellow_Pawns[pawn_number-9].getLoc() >= 0)
				 {
					 if (gpl+card_number > 59)
					 {
						 for (int i = 0; i < (59-gpl); i++)
						 {
							 yellow_Pawns[pawn_number-9].setLoc_x( b[gpl+i].getLoc_x() );
							 yellow_Pawns[pawn_number-9].setLoc_y( b[gpl+i].getLoc_y() );
							 //Todo IsSlide, Is Occupied
						 }
						 int tempPawnLocation = -1;
						 for (int i = 0; i < card_number-(59-gpl); i++) // -1 because vector begins at 0
						 {
							 yellow_Pawns[pawn_number-9].setLoc_x( b[i].getLoc_x() );
							 yellow_Pawns[pawn_number-9].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
							 //Todo IsSafe -> So set pawn vector Location = -2 
						 }
						 //Todo IsSlide -> which slide it is, and move accordingly and bump all non-teammate pawns
						 //Todo Is Occupied -> Bump(send other piece start)
						 yellow_Pawns[pawn_number-9].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 1; i <= card_number; i++)
						 {
							 yellow_Pawns[pawn_number-9].setLoc_x( b[gpl+i].getLoc_x() );
							 yellow_Pawns[pawn_number-9].setLoc_y( b[gpl+i].getLoc_y() );
						 }
						 yellow_Pawns[pawn_number-9].setLoc(gpl+card_number);
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
						 for (int i = 1; i <= card_number; i++)
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[i+48].getLoc_x() ); // + 19 because 1st space out of green start is b[19].
							 green_Pawns[pawn_number-13].setLoc_y( b[i+48].getLoc_y() );
						 }
						 green_Pawns[pawn_number-13].setLoc(card_number+48);
					 }
					 else{lblError -> Text = "You can only leave start on a 1 or 2.";}//TODO ERROR "Can only exit home on 1 or 2" -> next turn
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
						 int tempPawnLocation = -1;
						 for (int i = 0; i < card_number-(59-gpl); i++) // -1 because vector begins at 0
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[i].getLoc_x() );
							 green_Pawns[pawn_number-13].setLoc_y( b[i].getLoc_y() );
							 tempPawnLocation++;
						 }
					 green_Pawns[pawn_number-13].setLoc(tempPawnLocation);
					 }

					 else
					 {
						 for (int i = 1; i <= card_number; i++)
						 {
							 green_Pawns[pawn_number-13].setLoc_x( b[gpl+i].getLoc_x() );
							 green_Pawns[pawn_number-13].setLoc_y( b[gpl+i].getLoc_y() );
						 }
					 green_Pawns[pawn_number-13].setLoc(gpl+card_number);
					 }
				 }
			 }


			 if (turn == 3)
				 turn = 0;
			 else 
				 turn++;


			 switch(turn)
			 {
			 case 0:
				 lblPlayer -> ForeColor = Color(Color::Red);
				 lblPlayer -> Text = "Red's Turn";
				 lblInstruction -> Text = "Draw a card"; // For GUI to show what card was 'drawn'

				 break;
			 case 1:
				 lblPlayer -> ForeColor = Color(Color::Blue);
				 lblPlayer -> Text = "Blue's Turn";
				 lblInstruction -> Text = "Draw a card";
				 break;
			 case 2:
				 lblPlayer -> ForeColor = Color(Color::Yellow);
				 lblPlayer -> Text = "Yellow's Turn";
				 lblInstruction -> Text = "Draw a card";
				 break;
			 case 3:
				 lblPlayer -> ForeColor = Color(Color::Green);
				 lblPlayer -> Text = "Green's Turn";
				 lblInstruction -> Text = "Draw a card";
				 break;
			 }


			 makeMove -> Enabled = false;
			 check -> Enabled = false;
			 draw -> Enabled = true;
		 }
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 //nudX -> Value = (e->X);
			 //nudY -> Value = (e->Y);


		 }
private: System::Void check_Tick(System::Object^  sender, System::EventArgs^  e) {
			 switch (turn)
			 {
			 case 0:
				 if (pawn_number < 5 && pawn_number >= 1)
					 makeMove -> Enabled = true;
				 else 
					 makeMove -> Enabled = false;
				 break;
			 case 1:
				 if (pawn_number < 9 && pawn_number >= 5)
					 makeMove -> Enabled = true;
				 else 
					 makeMove -> Enabled = false;
				 break;
			 case 2:
				 if (pawn_number < 13 && pawn_number >= 9)
					 makeMove -> Enabled = true;
				 else 
					 makeMove -> Enabled = false;
				 break;
			 case 3:
				 if (pawn_number < 213 && pawn_number >= 13)
					 makeMove -> Enabled = true;
				 else 
					 makeMove -> Enabled = false;
				 break;
			 }
		 }
private: System::Void begin_Click(System::Object^  sender, System::EventArgs^  e) {

			 title_panel -> Visible = false;
			 title_panel -> Enabled = false;
			 begin -> Visible = false;

			 draw -> Enabled = true;
		 }
};


Brush ^convertColor(int c)
{
	Brush ^col; // TODO pictures or somthing god dammit
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
bool isSafe(int num)
{
	if (pawn_number >= 1 && pawn_number < 5) // card_number <=  8 - loc
	{
		if ((red_Pawns[pawn_number-1].getLoc() == 2 ))
		{
			//red_Pawns[pawn_number-1].setLoc(-2);
			return true;
		}
	}
	return false;
}
bool isSafe()
{
		if (pawn_number >= 1 && pawn_number < 5) // card_number <=  8 - loc
		{
			if ((red_Pawns[pawn_number-1].getLoc() < 3 ) && ( card_number <= 8 - red_Pawns[pawn_number-1].getLoc()) && (card_number + red_Pawns[pawn_number-1].getLoc() > 2))
			{
				//red_Pawns[pawn_number-1].setLoc(-2);
				return true;
			}
		}
			
		else if (pawn_number >= 5 && pawn_number < 9)
		{
			if (blue_Pawns[pawn_number-5].getLoc() < 18 && card_number <= 8 -blue_Pawns[pawn_number-5].getLoc())
			{
				//blue_Pawns[pawn_number-5].setLoc(-2);
				return true;
			}
		}
			
		else if (pawn_number >= 9 && pawn_number < 13)
		{
			if (yellow_Pawns[pawn_number-9].getLoc() < 33 && card_number <= 8 - yellow_Pawns[pawn_number-9].getLoc())
			{
				//yellow_Pawns[pawn_number-9].setLoc(-2);
				return true;
			}
		}
			
		else if (pawn_number >= 13)
		{
			if (green_Pawns[pawn_number-13].getLoc() < 48 && card_number <= 8 - green_Pawns[pawn_number-13].getLoc())
			{
				//green_Pawns[pawn_number-13].setLoc(-2);
				return true;
			}
		}
		return false;
			
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
	red_Start.push_back(Cell (1, (Board-CellSize*6)+(CellSize/3)+2, (Board-CellSize*3)+(CellSize/2)-5, 0));
	red_Start.push_back(Cell (1, (Board-CellSize*5)+(CellSize/1.5)-2, (Board-CellSize*3)+(CellSize/2)-5, 0));
	red_Start.push_back(Cell (1, (Board-CellSize*5), (Board-CellSize*3)-10, 0));

	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*3), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*4), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*5), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*6), 0));

	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*8), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*4)+(CellSize/3), (Board-CellSize*8)+(CellSize/2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3)+(CellSize/1.5), (Board-CellSize*8)+(CellSize/2), 0));
	red_Home.push_back(Cell (1, (Board-CellSize*3), (Board-CellSize*7)-4, 0));

	////////////////////////// BLUE

	blue_Start.push_back(Cell (2, (Board-CellSize*15), (Board-CellSize*5), 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*15)+(CellSize/2)+5, (Board-CellSize*6)+(CellSize/3)+2, 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*15)+(CellSize/2)+5, (Board-CellSize*5)+(CellSize/1.5)-2, 0));
	blue_Start.push_back(Cell (2, (Board-CellSize*14)+8, (Board-CellSize*5), 0));

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
	yellow_Start.push_back(Cell (3, (Board-CellSize*13)+(CellSize/3), (Board-CellSize*15)+(CellSize/2)+2, 0));
	yellow_Start.push_back(Cell (3, (Board-CellSize*12)+(CellSize/1.5), (Board-CellSize*15)+(CellSize/2)+2, 0));
	yellow_Start.push_back(Cell (3, (Board-CellSize*12), (Board-CellSize*14)+5, 0));

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
	green_Start.push_back(Cell (4, (Board-CellSize*3)+(CellSize/2)-2, (Board-CellSize*13)+(CellSize/3), 0));
	green_Start.push_back(Cell (4, (Board-CellSize*3)+(CellSize/2)-2, (Board-CellSize*12)+(CellSize/1.5), 0));
	green_Start.push_back(Cell (4, (Board-CellSize*3)-7, (Board-CellSize*12), 0));

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
	//int cr[] = {1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,7,7,7,7,8,8,8,8,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
	int cr[] = {7,4,1,3,2,10,3,1,8,5,1,5,2,1,11,7,8,4,1,10};
	cardInts.assign(cr, cr + sizeof cr / sizeof cr[0]);
	//random_shuffle( cardInts.begin(), cardInts.end() );
}

//1. Title Page
//		subtitle description
//		contributors
//2. Description of project
//		goals
//		what it has
//3. Results
//4. Interesting technical aspects
//		specific problems and how they were delt with
//5. Slides of game
//6. What did we learn