#include "MyForm.h"

using namespace Sorry;

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew MyForm());



	return 0;

}


