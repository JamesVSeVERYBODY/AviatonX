#include "game.h"

Game::Game(RenderWindow* win) {
    window = win;

    Texture tex, tex2;

    tex.loadFromFile("Sprites/player.png");
    tex2.loadFromFile("Sprites/bullet.png");

    player.Start(tex, tex2);

    font.loadFromFile("fonts/Roboto-Regular.ttf");
}

void Game::Start() {
    MainMenu();

    int timer = 0;
    int enemyTimer = 50;

    Texture texbg;
    texbg.loadFromFile("Sprites/bg.png");

    Sprite bg;
    bg.setTexture(texbg);
    bg.setTextureRect(IntRect(0, 0, 683, 384));

    Texture tex;
    tex.loadFromFile("Sprites/saucer.png");

    Sprite enemySprite;
    enemySprite.setTexture(tex);
    enemySprite.setTextureRect(IntRect(0, 0, 60, 35));

    enemies.clear();

    int score = 0;

    Text scoreText;
    scoreText.setFont(font);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer <= 0) {
            player.Tembak();
            timer = 10;
        } timer--;

        if (enemyTimer <= 0) {
            while(1){
                int r = rand() % 100;
                if (r < 50) break;

                enemies.push_back(Vector2f(rand() % 100 + 690, rand() % 150 + 50));
            }
            

            enemyTimer = 50;
        } enemyTimer--;

        Vector2f mousePos = Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

        scoreText.setString("Score : " + std::to_string(score));

        player.SetPosition(mousePos);
        player.Update();

        window->clear();
        window->draw(bg);

        FloatRect playerBox(player.GetSprite().getPosition().x, player.GetSprite().getPosition().y, 60, 49);
        for (int i = enemies.size() - 1; i >= 0 ; i--) {
            enemies[i].x -= 5;
            float y = enemies[i].y + 50 * sin(enemies[i].x / 100);

            enemySprite.setPosition(Vector2f(enemies[i].x, y));

            FloatRect enemyBox(enemies[i].x, y, 60, 35);

            if (player.CollidePeluru(enemyBox)) {
                score += 10;
                enemies.erase(enemies.begin() + i);
                continue;
            }

            if (playerBox.intersects(enemyBox)) {
                GameOver();
                return;
            }

            if (enemies[i].x < -60) {
                enemies.erase(enemies.begin() + i);
                continue;
            }

            window->draw(enemySprite);
        }

        player.Draw(*window);

        window->draw(scoreText);

        window->display();
    }
}

void Game::MainMenu() {
    Text text;
    text.setFont(font);
    text.setString("Press Space to Start");

    Texture tex;
    tex.loadFromFile("Sprites/menu.jpg");

    Sprite bg;
    bg.setTexture(tex);
    bg.setTextureRect(IntRect(0, 0, 3840, 2160));

    bg.setScale(window->getSize().x / 3840.f, window->getSize().y / 2160.f);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                return;
            }
        }

        window->clear();
        window->draw(bg);
        window->draw(text);
        window->display();
    }
}

void Game::GameOver() {
    Text text;
    text.setFont(font);
    text.setString("Game Over");

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                return;
            }
        }

        window->clear();
        window->draw(text);
        window->display();
    }
}