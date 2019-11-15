
#include "SurvislandGameMode.h"
#include "SurvislandCharacter.h"


void ASurvislandGameMode::Menu()
{
	State = EGameState::Menu;
}

void ASurvislandGameMode::Game()
{
	State = EGameState::Game;
}