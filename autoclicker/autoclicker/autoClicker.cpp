#include <iostream>
#include <Windows.h>

const void autoClicking()
{
	int x = 0;
	int y = 0;

	while (true)
	{

		if (GetAsyncKeyState(VK_F2)) // getting the cursorposition
		{
			std::cout << "Getting cursorposition!\n";
			Sleep(100);
			POINT cursPos;
			GetCursorPos(&cursPos);

			x = cursPos.x;
			y = cursPos.y;

			std::cout << "CursorPos X = " << x << '\n';
			std::cout << "CursorPos Y = " << y << '\n';
		}

		if (GetAsyncKeyState(VK_ESCAPE)) // closing
		{
			std::cout << "Bye!\n";
			Sleep(500);
			system("exit");

			break;
		}

		if (GetAsyncKeyState(VK_INSERT)) // injecting autoclicker
		{
			std::cout << "Injecting autoclicker!\n";
			Sleep(100);
			bool clicker;
			clicker = true;

			while (true)
			{

				if (!clicker)
				{
					break;
				}

				SetCursorPos(x, y);
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, x, y, 0, 0);

				if (GetAsyncKeyState(VK_F3)) // stopping session
				{
					std::cout << "Stopping clicker!\n";
					Sleep(100);
					system("pause");
				}


				if (GetAsyncKeyState(VK_ESCAPE)) // closing
				{
					std::cout << "Bye!\n";
					Sleep(500);
					system("exit");

					break;
				}
			}

		}
	}
}

const void display()
{
	bool clicker;
	clicker = false;
	system("autoclicker");
	std::cout << "[HOTKEYS] - made by dunken20\n";
	std::cout << "=======================\n";
	std::cout << "F2 = cursorPosition\n";
	std::cout << "INSERT = injecting\n";
	std::cout << "F3 = Stop\n";
	std::cout << "ESC = closing\n";
	std::cout << "=======================\n";
	autoClicking();
}


int main()
{
	display();


	return 0;
}