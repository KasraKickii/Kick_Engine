#include <Kick_Engine/Inc/Kick_Engine.h>

#include "GameState.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ int nCmdShow)
{
	App& myApp = Kick_Engine::MainApp();
	myApp.AddState<GameState>("GameState");

	AppConfig config;
	config.appName = L"Grass";
	config.winHeight = 1080;
	config.winWidth = 1920;

	myApp.Run(config);

	return (0);
}