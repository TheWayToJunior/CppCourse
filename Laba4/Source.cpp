#include <iostream>
#include "Game.h"

int main()
{
    setlocale(0, "rus");

    float balance, bet;

    std::cout << "Ваш баланс: "; std::cin >> balance;

    auto player = new Player("PlayerName", balance);
    Game game(player);

    while (true)
    {
        if (player->GetBalance() <= 0.0f)
        {
            std::cout << "Ваш баланс пуст!";
            break;
        }

        std::cout << "Ваша ставка: "; std::cin >> bet;
        std::cout << std::endl;

        try
        {
            game.Play(bet);
            game.Dispose();
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;

            game.Dispose();
            break;
        }
        /// Here could be your "finally"
    }

    delete player;
}
