#include "../../include/bot/PlayerFactory.hpp"

#include <memory>

#include "../../include/bot/Human.hpp"


std::unique_ptr<Player> PlayerFactory::createPlayer(char type, Color color)
{
	switch (type)
	{
	default/*Human*/:
		return std::make_unique<Human>(color);
	}
}
