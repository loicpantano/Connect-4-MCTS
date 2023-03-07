#include "../../include/bot/PlayerFactory.hpp"

#include <memory>

#include "../../include/bot/Human.hpp"
#include "bot/Bot.hpp"


std::unique_ptr<Player> PlayerFactory::createPlayer(char type, Color color)
{
	switch (type)
	{
        case 'b':
            return std::make_unique<Bot>(color);
        default/*Human*/:
            return std::make_unique<Human>(color);
	}
}
