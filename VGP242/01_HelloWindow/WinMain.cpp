#include <Kick_Engine/Inc/Kick_Engine.h>

using namespace Kick_Engine;
using namespace Kick_Engine::Graphics;

class MainState : public AppState
{
public:
	void Initialize()
	{	
		LOG("MAIN STATE INITIALIZED");
		GraphicsSystem::Get()->SetClearColor(Colors::Red);
		mLifeTime = 2.0f;
	}

	void Terminate()
	{
		LOG("MAIN STATE TERMINATED");
	}

	void Update(float deltaTime)
	{
		mLifeTime -= deltaTime;
		if (mLifeTime <= 0.0f)
		{
			App& myApp = Kick_Engine::MainApp();
			myApp.ChangeState("GameState");
		}
	}

private:
	float mLifeTime = 0.0f;
};

class GameState : public AppState
{
public:
	void Initialize()
	{
		LOG("GAME STATE INITIALIZED");
		GraphicsSystem::Get()->SetClearColor(Colors::Blue);
		mLifeTime = 2.0f;
	}

	void Terminate()
	{
		LOG("GAME STATE TERMINATED");
	}

	void Update(float deltaTime)
	{
		mLifeTime -= deltaTime;
		if (mLifeTime <= 0.0f)
		{
			App& myApp = Kick_Engine::MainApp();
			myApp.ChangeState("MainState");
		}
	}

private:
	float mLifeTime = 0.0f;
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ int nCmdShow)
{
	App& myApp = Kick_Engine::MainApp();
	myApp.AddState<MainState>("MainState");
	myApp.AddState<GameState>("GameState");

	AppConfig config;
	config.appName = L"Hello Window";

	myApp.Run(config);

	return (0);
}