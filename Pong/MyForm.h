#pragma once

namespace Pong
{

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
	private: System::Windows::Forms::PictureBox^  player;
	protected:
	private: System::Windows::Forms::PictureBox^  cpu;
	private: System::Windows::Forms::PictureBox^  ball;
	private: System::Windows::Forms::Timer^  gameTimer;
	private: System::Windows::Forms::Label^  displayPlayerScore;
	private: System::Windows::Forms::Label^  displayCPUScore;
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
			this->player = (gcnew System::Windows::Forms::PictureBox());
			this->cpu = (gcnew System::Windows::Forms::PictureBox());
			this->ball = (gcnew System::Windows::Forms::PictureBox());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->displayPlayerScore = (gcnew System::Windows::Forms::Label());
			this->displayCPUScore = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cpu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball))->BeginInit();
			this->SuspendLayout();
			// 
			// player
			// 
			this->player->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->player->Location = System::Drawing::Point(124, 126);
			this->player->Name = L"player";
			this->player->Size = System::Drawing::Size(27, 127);
			this->player->TabIndex = 1;
			this->player->TabStop = false;
			// 
			// cpu
			// 
			this->cpu->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cpu->Location = System::Drawing::Point(775, 151);
			this->cpu->Name = L"cpu";
			this->cpu->Size = System::Drawing::Size(27, 127);
			this->cpu->TabIndex = 2;
			this->cpu->TabStop = false;
			// 
			// ball
			// 
			this->ball->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ball->Location = System::Drawing::Point(468, 188);
			this->ball->Name = L"ball";
			this->ball->Size = System::Drawing::Size(27, 27);
			this->ball->TabIndex = 3;
			this->ball->TabStop = false;
			// 
			// gameTimer
			// 
			this->gameTimer->Enabled = true;
			this->gameTimer->Interval = 20;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &MyForm::timerTick);
			// 
			// displayPlayerScore
			// 
			this->displayPlayerScore->AutoSize = true;
			this->displayPlayerScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayPlayerScore->Location = System::Drawing::Point(302, 48);
			this->displayPlayerScore->Name = L"displayPlayerScore";
			this->displayPlayerScore->Size = System::Drawing::Size(70, 25);
			this->displayPlayerScore->TabIndex = 4;
			this->displayPlayerScore->Text = L"label1";
			// 
			// displayCPUScore
			// 
			this->displayCPUScore->AutoSize = true;
			this->displayCPUScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayCPUScore->Location = System::Drawing::Point(654, 48);
			this->displayCPUScore->Name = L"displayCPUScore";
			this->displayCPUScore->Size = System::Drawing::Size(70, 25);
			this->displayCPUScore->TabIndex = 5;
			this->displayCPUScore->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(962, 502);
			this->Controls->Add(this->displayCPUScore);
			this->Controls->Add(this->displayPlayerScore);
			this->Controls->Add(this->ball);
			this->Controls->Add(this->cpu);
			this->Controls->Add(this->player);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyisdown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyisup);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cpu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//keys
		bool goUp;
		bool goDown;

		//scores
		int playerScore = 0;    //player score
		int cpuScore = 0;       //cpu score

		int cpuSpeed = 5;       //CPU speed
		int playerSpeed = 7;    //player speed
		int ballX = 8;          //ball horizontal speed
		int ballY = 8;          //ball vertical speed

		int timer = 0;          //for counting ticks


	private: System::Void keyisdown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		//key is pressed
		if (e->KeyCode == Keys::Up)   //up arrow key
		{
			goUp = true;
		}
		if (e->KeyCode == Keys::Down) //down arrow key
		{
			goDown = true;
		}

		//Esc. pause, continue or exit
		if (e->KeyCode == Keys::Escape)
		{
			gameTimer->Stop();	//pause

			//messagebox asking if player wants to close the game
			if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Shut down?", "Game paused", MessageBoxButtons::YesNo))
			{
				Application::Exit(); //shut down
			}
			else
			{
				gameTimer->Start(); //restart
			}
		}
	}

	private: System::Void keyisup(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		//key is released
		if (e->KeyCode == Keys::Up)   //up arrow key
		{
			goUp = false;
		}
		if (e->KeyCode == Keys::Down) //down arrow key
		{
			goDown = false;
		}
	}

	//main timer event, triggered every 20ms
	private: System::Void timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		ballControls();
		cpuControls();
		playerControls();
		score();
	}

			 void ballControls()
			 {
				 timer++;	//how many ticks has passed

				 //move the ball
				 ball->Left -= ballX;
				 ball->Top -= ballY;

				 //if the ball has reached top or bottom of the screen
				 if (ball->Top < 0 || ball->Top + ball->Height > ClientSize.Height)
				 {
					 //reverse the speed
					 ballY = -ballY;
				 }

				 //if the ball hits the player or the CPU and more than 25 ticks from last bounce has passed
				 if ((ball->Bounds.IntersectsWith(player->Bounds) || ball->Bounds.IntersectsWith(cpu->Bounds)) && timer > 25)
				 {
					 //reset timer
					 timer = 0;

					 //reverse the speed
					 ballX = -ballX;
				 }
			 }

			 void playerControls()
			 {
				 //horizontal position of the player
				 player->Left = ClientSize.Width / 50;

				 //if key is held down and player is within the boundaries
				 if (goUp && player->Top > 0)     //up
				 {
					 //move player up
					 player->Top -= playerSpeed;
				 }
				 if (goDown && player->Bottom < ClientSize.Height)    //down
				 {
					 //move player down
					 player->Top += playerSpeed;
				 }
			 }

			 void cpuControls()
			 {
				 //horizontal position of the CPU
				 cpu->Left = ClientSize.Width - ClientSize.Width / 50 - cpu->Width;

				 //if cpu is within the boundaries and...
				 //...cpu is below the ball
				 if (cpu->Top + cpu->Height / 2 > ball->Top + ball->Height / 2 && cpu->Top > 0)
				 {
					 //move CPU up
					 cpu->Top -= cpuSpeed;
				 }
				 //...cpu is above the ball
				 else if (cpu->Top + cpu->Height / 2 < ball->Top + ball->Height / 2 && cpu->Bottom < ClientSize.Height)
				 {
					 //move CPU down
					 cpu->Top += cpuSpeed;
				 }
			 }

			 void score()
			 {
				 //CPU scores
				 if (ball->Left < 0)
				 {
					 ball->Left = ClientSize.Width / 2 - ball->Width / 2;    //reset the ball
					 ballX = -ballX;										 //change direction
					 //ballx -= 2;											 //increase speed
					 timer = 0;												 //reset timer
					 cpuScore++;											 //increase CPU score
				 }

				 //player scores
				 if (ball->Left + ball->Width > ClientSize.Width)
				 {
					 ball->Left = ClientSize.Width / 2 - ball->Width / 2;    //reset the ball
					 ballX = -ballX;										 //change direction
					 //ballx += 2;											 //increase speed
					 timer = 0;												 //reset timer
					 playerScore++;											 //increase player score
				 }

				 //display player score
				 displayPlayerScore->Text = "" + playerScore;
				 displayPlayerScore->Left = ClientSize.Width / 3;
				 displayPlayerScore->Top = ClientSize.Height / 10;

				 //display CPU score
				 displayCPUScore->Text = "" + cpuScore;
				 displayCPUScore->Left = ClientSize.Width - ClientSize.Width / 3;
				 displayCPUScore->Top = ClientSize.Height / 10;

				 //final score and ending the game
				 if (playerScore == 10)
				 {
					 gameOver("Player won.");
				 }
				 if (cpuScore == 10)
				 {
					 gameOver("CPU won.");
				 }

			 }

			 //Game over. Ask if player wants to continue
			 void gameOver(System::String^ message)
			 {
				 gameTimer->Stop(); //pause

				 if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show(message +" Restart?", "Game over", MessageBoxButtons::YesNo))
				 {
					 reset();
					 gameTimer->Start(); //restart
				 }
				 else
				 {
					 Application::Exit(); //shut down
				 }
			 }

			 void reset()
			 {
				 //reset scores
				 playerScore = 0;
				 cpuScore = 0;

				 //reset ball
				 ball->Top = ClientSize.Height / 2 - ball->Height / 2;
				 ball->Left = ClientSize.Width / 2 - ball->Width / 2;
				 timer = 0;

				 //reset player / CPU
				 player->Top = ClientSize.Height / 2 - player->Height / 2;
				 cpu->Top = ClientSize.Height / 2 - cpu->Height / 2;
			 }
	};
}
