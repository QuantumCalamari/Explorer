#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <sstream>

int main()
{
	float aspect = 0.75;
	int m_Width = 800;
	int m_Height = m_Width * aspect;

	int GameState = 0;
	srand(time(0));

	std::string window_title;
	int title_select = rand() % 2;

	int village = 0;
	int target_village = 0;

	sf::Vector2f current_position;
	sf::Vector2f target_position;
	float del_x;
	float del_y;

	std::vector<std::string> village_names;
	std::stringstream stream;

	//0
	village_names.push_back("Sieblin");
	//1
	village_names.push_back("Roudenfal");
	//2
	village_names.push_back("Hahkdauzhad");
	//3
	village_names.push_back("Bardrack");
	//4
	village_names.push_back("Schedinhor");
	//5
	village_names.push_back("Hesental");
	//6
	village_names.push_back("Arraibeg");
	//7
	village_names.push_back("Budtelstie");
	//8
	village_names.push_back("Galfar");
	//9
	village_names.push_back("Fiogar");
	//10
	village_names.push_back("Galeb");
	//11
	village_names.push_back("Uinn");
	//12
	village_names.push_back("Habruk");

	sf::Vector2i village_map_coordinates[13];

	village_map_coordinates[0] = sf::Vector2i(572, 238);
	village_map_coordinates[1] = sf::Vector2i(725, 281);
	village_map_coordinates[2] = sf::Vector2i(764, 526);
	village_map_coordinates[3] = sf::Vector2i(415, 442);
	village_map_coordinates[4] = sf::Vector2i(442, 288);
	village_map_coordinates[5] = sf::Vector2i(362, 247);
	village_map_coordinates[6] = sf::Vector2i(327, 446);
	village_map_coordinates[7] = sf::Vector2i(353, 73);
	village_map_coordinates[8] = sf::Vector2i(260, 285);
	village_map_coordinates[9] = sf::Vector2i(147, 44);
	village_map_coordinates[10] = sf::Vector2i(154, 202);
	village_map_coordinates[11] = sf::Vector2i(265, 517);
	village_map_coordinates[12] = sf::Vector2i(151, 380);

	std::vector<int> sieblin_targets;
	sieblin_targets.push_back(1);
	sieblin_targets.push_back(4);
	sieblin_targets.push_back(5);

	std::vector<int> sieblin_distances;
	sieblin_distances.push_back(2);
	sieblin_distances.push_back(2);
	sieblin_distances.push_back(3);


	std::vector<int> roudenfal_targets;
	roudenfal_targets.push_back(0);
	roudenfal_targets.push_back(2);

	std::vector<int> roudenfal_distances;
	roudenfal_distances.push_back(3);
	roudenfal_distances.push_back(4);

	std::vector<int> hahk_targets;
	hahk_targets.push_back(1);

	std::vector<int> hahk_distances;
	hahk_distances.push_back(4);

	std::vector<int> bard_targets;
	bard_targets.push_back(4);
	bard_targets.push_back(6);
	bard_targets.push_back(8);
	bard_targets.push_back(9);
	bard_targets.push_back(10);

	std::vector<int> bard_distances;
	bard_distances.push_back(2);
	bard_distances.push_back(1);
	bard_distances.push_back(2);
	bard_distances.push_back(13);
	bard_distances.push_back(11);

	std::vector<int> sched_targets;
	sched_targets.push_back(0);
	sched_targets.push_back(1);
	sched_targets.push_back(3);

	std::vector<int> sched_distances;
	sched_distances.push_back(2);
	sched_distances.push_back(4);
	sched_distances.push_back(2);

	std::vector<int> hesen_targets;
	hesen_targets.push_back(0);
	hesen_targets.push_back(7);
	hesen_targets.push_back(8);

	std::vector<int> hesen_distances;
	hesen_distances.push_back(2);
	hesen_distances.push_back(3);
	hesen_distances.push_back(2);

	std::vector<int> arra_targets;
	arra_targets.push_back(3);
	arra_targets.push_back(8);
	arra_targets.push_back(9);
	arra_targets.push_back(10);
	arra_targets.push_back(11);

	std::vector<int> arra_distances;
	arra_distances.push_back(1);
	arra_distances.push_back(2);
	arra_distances.push_back(13);
	arra_distances.push_back(11);
	arra_distances.push_back(3);

	std::vector<int> bud_targets;
	bud_targets.push_back(5);
	bud_targets.push_back(9);

	std::vector<int> bud_distances;
	bud_distances.push_back(3);
	bud_distances.push_back(3);

	std::vector<int> galf_targets;
	galf_targets.push_back(5);
	galf_targets.push_back(10);
	galf_targets.push_back(12);

	std::vector<int> galf_distances;
	galf_distances.push_back(2);
	galf_distances.push_back(3);
	galf_distances.push_back(8);

	std::vector<int> fiog_targets;
	fiog_targets.push_back(3);
	fiog_targets.push_back(6);
	fiog_targets.push_back(7);
	fiog_targets.push_back(10);

	std::vector<int> fiog_distances;
	fiog_distances.push_back(13);
	fiog_distances.push_back(13);
	fiog_distances.push_back(3);
	fiog_distances.push_back(4);

	std::vector<int> galeb_targets;
	galeb_targets.push_back(3);
	galeb_targets.push_back(6);
	galeb_targets.push_back(8);
	galeb_targets.push_back(9);

	std::vector<int> galeb_distances;
	galeb_distances.push_back(11);
	galeb_distances.push_back(11);
	galeb_distances.push_back(3);
	galeb_distances.push_back(4);

	std::vector<int> uinn_targets;
	uinn_targets.push_back(6);

	std::vector<int> uinn_distances;
	uinn_distances.push_back(3);

	std::vector<int> hab_targets;
	hab_targets.push_back(8);

	std::vector<int> hab_distances;
	hab_distances.push_back(8);

	//fill in the rest of the distances

	std::vector<int> targets;
	std::vector<int> distances;

	sf::Texture map_texture;
	if (!map_texture.loadFromFile("map_background.png")) {

	}	

	sf::Texture sieblin_texture;
	if (!sieblin_texture.loadFromFile("test.png")) {

	}

	sf::Texture highlighter_texture;
	if (!highlighter_texture.loadFromFile("highlighter.png")) {

	}

	sf::Texture cart;

	if (!cart.loadFromFile("cart.png"))
	{
		std::cout << "Menu Background failed to load" << std::endl;
	}

	sf::Texture menu_background;
	sf::Texture title_texture;
	sf::Texture new_game_txt;
	sf::Texture continue_txt;
	sf::Texture exit_game_txt;


	if (!menu_background.loadFromFile("menu_background.png"))
	{
		std::cout << "Menu Background failed to load" << std::endl;
	}

	if (!title_texture.loadFromFile("title_name.png"))
	{
		std::cout << "Title text failed to load" << std::endl;
	}

	if (!new_game_txt.loadFromFile("new_game.png")) {
		std::cout << "New Game text failed to load" << std::endl;
	}

	if (!continue_txt.loadFromFile("continue.png")) {
		std::cout << "Continue text failed to load" << std::endl;
	}

	if (!exit_game_txt.loadFromFile("exit_game.png")) {
		std::cout << "Exit game text failed to load" << std::endl;
	}

	sf::Sprite highlighter(highlighter_texture);

	// Declare and load a font
	sf::Font font;
	font.loadFromFile("GenghisKhan.otf");

	switch(title_select) {
	case 0:
		window_title = "Some bullshit";
		break;
	case 1:
		window_title = "different bullshit";
		break;
	}

	sf::RenderWindow window(sf::VideoMode(m_Width, m_Height), window_title);	
	float buttonPressed = 0;
	

	while (window.isOpen())
	{

		sf::Clock clock;
		float startFrame = clock.getElapsedTime().asMilliseconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (GameState == 1002) {

				targets.clear();
				distances.clear();

				switch (village) {
				case(0):
					for (int i = 0; i < sieblin_targets.size(); i++) {
						targets.push_back(sieblin_targets.at(i));
						distances.push_back(sieblin_distances.at(i));
					}
					break;
				case (1):
					for (int i = 0; i < roudenfal_targets.size(); i++) {
						targets.push_back(roudenfal_targets.at(i));
						distances.push_back(roudenfal_distances.at(i));
					}
					break;
				case (2):
					for (int i = 0; i < hahk_targets.size(); i++) {
						targets.push_back(hahk_targets.at(i));
						distances.push_back(hahk_distances.at(i));
					}
					break;
				case (3):
					for (int i = 0; i < bard_targets.size(); i++) {
						targets.push_back(bard_targets.at(i));
						distances.push_back(bard_distances.at(i));
					}
					break;
				case (4):
					for (int i = 0; i < sched_targets.size(); i++) {
						targets.push_back(sched_targets.at(i));
						distances.push_back(sched_distances.at(i));
					}
					break;
				case (5):
					for (int i = 0; i < hesen_targets.size(); i++) {
						targets.push_back(hesen_targets.at(i));
						distances.push_back(hesen_distances.at(i));
					}
					break;
				case (6):
					for (int i = 0; i < arra_targets.size(); i++) {
						targets.push_back(arra_targets.at(i));
						distances.push_back(arra_distances.at(i));
					}
					break;
				case (7):
					for (int i = 0; i < bud_targets.size(); i++) {
						targets.push_back(bud_targets.at(i));
						distances.push_back(bud_distances.at(i));
					}
					break;
				case (8):
					for (int i = 0; i < galf_targets.size(); i++) {
						targets.push_back(galf_targets.at(i));
						distances.push_back(galf_distances.at(i));
					}
					break;
				case (9):
					for (int i = 0; i < fiog_targets.size(); i++) {
						targets.push_back(fiog_targets.at(i));
						distances.push_back(fiog_distances.at(i));
					}
					break;
				case (10):
					for (int i = 0; i < galeb_targets.size(); i++) {
						targets.push_back(galeb_targets.at(i));
						distances.push_back(galeb_distances.at(i));
					}
					break;
				case (11):
					for (int i = 0; i < uinn_targets.size(); i++) {
						targets.push_back(uinn_targets.at(i));
						distances.push_back(uinn_distances.at(i));
					}
					break;
				case (12):
					for (int i = 0; i < hab_targets.size(); i++) {
						targets.push_back(hab_targets.at(i));
						distances.push_back(hab_distances.at(i));
					}
					break;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && buttonPressed > 80.0f) {								
					buttonPressed = 0;
					if (target_village < targets.size()-1) {
						target_village++;
					}
					else {
						target_village = 0;
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && buttonPressed > 80.0f) {

					buttonPressed = 0;
					if (target_village >= 1) {
						target_village--;
					}
					else {
						for (int i = 0; i < targets.size(); i++) {
							std::cout << village_names[targets.at(i)] << std::endl;
						}
						target_village = targets.size()-1;
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && buttonPressed > 80.0f) {
					buttonPressed = 0;
					GameState = 1100;
					current_position = sf::Vector2f(village_map_coordinates[village].x, village_map_coordinates[village].y);
					target_position = sf::Vector2f(village_map_coordinates[targets.at(target_village)].x, village_map_coordinates[targets.at(target_village)].y);
					del_x = ((float)current_position.x - (float)target_position.x) / (120 * distances.at(target_village));
					del_y = ((float)current_position.y - (float)target_position.y) / (120 * distances.at(target_village));
					//village = targets.at(target_village);
					std::cout << village << std::endl;
					target_village = 0;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && buttonPressed > 80.0f) {

				}
			}
		}

		

		if (GameState == 0) {

			window.clear();

			sf::Sprite background(menu_background);
			sf::Sprite title(title_texture);
			sf::Sprite new_game(new_game_txt);
			sf::Sprite continue_menu(continue_txt);
			sf::Sprite exit_game(exit_game_txt);

			title.setPosition(sf::Vector2f((m_Width / 2 - title.getTexture()->getSize().x / 2), m_Height / 4));
			new_game.setPosition(sf::Vector2f((m_Width / 2 - new_game.getTexture()->getSize().x / 2), title.getPosition().y + title.getTexture()->getSize().y));
			continue_menu.setPosition(sf::Vector2f((m_Width / 2 - continue_menu.getTexture()->getSize().x / 2), new_game.getPosition().y + new_game.getTexture()->getSize().y));
			exit_game.setPosition(sf::Vector2f((m_Width / 2 - exit_game.getTexture()->getSize().x / 2), continue_menu.getPosition().y + continue_menu.getTexture()->getSize().y));

			window.draw(background);
			window.draw(title);
			window.draw(new_game);
			window.draw(continue_menu);
			window.draw(exit_game);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (sf::Mouse::getPosition(window).x > new_game.getPosition().x && sf::Mouse::getPosition(window).x < new_game.getPosition().x + new_game.getTexture()->getSize().x)
					if (sf::Mouse::getPosition(window).y > new_game.getPosition().y && sf::Mouse::getPosition(window).y < new_game.getPosition().y + new_game.getTexture()->getSize().y) {
						GameState = 1001;
					}

				if (sf::Mouse::getPosition(window).x > continue_menu.getPosition().x && sf::Mouse::getPosition(window).x < continue_menu.getPosition().x + continue_menu.getTexture()->getSize().x)
					if (sf::Mouse::getPosition(window).y > continue_menu.getPosition().y && sf::Mouse::getPosition(window).y < continue_menu.getPosition().y + continue_menu.getTexture()->getSize().y) {
						GameState = 1002;
					}

				if (sf::Mouse::getPosition(window).x > exit_game.getPosition().x && sf::Mouse::getPosition(window).x < exit_game.getPosition().x + exit_game.getTexture()->getSize().x)
					if (sf::Mouse::getPosition(window).y > exit_game.getPosition().y && sf::Mouse::getPosition(window).y < exit_game.getPosition().y + exit_game.getTexture()->getSize().y) {
						GameState = 1003;
					}

			}
			window.display();
			}
			else if (GameState == 1001) {
				GameState = 0;
				std::cout << "new game";
			}
			else if (GameState == 1002) {

			targets.clear();
			distances.clear();

				switch (village) {
				case(0):
					for (int i = 0; i < sieblin_targets.size(); i++) {
						targets.push_back(sieblin_targets.at(i));
						distances.push_back(sieblin_distances.at(i));
					}
					break;
				case (1):
					for (int i = 0; i < roudenfal_targets.size(); i++) {
						targets.push_back(roudenfal_targets.at(i));
						distances.push_back(roudenfal_distances.at(i));
					}
					break;
				case (2):
					for (int i = 0; i < hahk_targets.size(); i++) {
						targets.push_back(hahk_targets.at(i));
						distances.push_back(hahk_distances.at(i));
					}
					break;
				case (3):
					for (int i = 0; i < bard_targets.size(); i++) {
						targets.push_back(bard_targets.at(i));
						distances.push_back(bard_distances.at(i));
					}
					break;
				case (4):
					for (int i = 0; i < sched_targets.size(); i++) {
						targets.push_back(sched_targets.at(i));
						distances.push_back(sched_distances.at(i));
					}
					break;
				case (5):
					for (int i = 0; i < hesen_targets.size(); i++) {
						targets.push_back(hesen_targets.at(i));
						distances.push_back(hesen_distances.at(i));
					}
					break;
				case (6):
					for (int i = 0; i < arra_targets.size(); i++) {
						targets.push_back(arra_targets.at(i));
						distances.push_back(arra_distances.at(i));
					}
					break;
				case (7):
					for (int i = 0; i < bud_targets.size(); i++) {
						targets.push_back(bud_targets.at(i));
						distances.push_back(bud_distances.at(i));
					}
					break;
				case (8):
					for (int i = 0; i < galf_targets.size(); i++) {
						targets.push_back(galf_targets.at(i));
						distances.push_back(galf_distances.at(i));
					}
					break;
				case (9):
					for (int i = 0; i < fiog_targets.size(); i++) {
						targets.push_back(fiog_targets.at(i));
						distances.push_back(fiog_distances.at(i));
					}
					break;
				case (10):
					for (int i = 0; i < galeb_targets.size(); i++) {
						targets.push_back(galeb_targets.at(i));
						distances.push_back(galeb_distances.at(i));
					}
					break;
				case (11):
					for (int i = 0; i < uinn_targets.size(); i++) {
						targets.push_back(uinn_targets.at(i));
						distances.push_back(uinn_distances.at(i));
					}
					break;
				case (12):
					for (int i = 0; i < hab_targets.size(); i++) {
						targets.push_back(hab_targets.at(i));
						distances.push_back(hab_distances.at(i));
					}
					break;
				}

			//	window.clear();
				sf::Sprite map_background(map_texture);

				highlighter.setPosition(village_map_coordinates[targets.at(target_village)].x - 7, village_map_coordinates[targets.at(target_village)].y - 7);

				sf::Text target_village_text(village_names[targets.at(target_village)], font);
				target_village_text.setCharacterSize(30);
				target_village_text.setStyle(sf::Text::Bold);
				target_village_text.setFillColor(sf::Color::Yellow);

				stream.str(std::string());
				stream << "travel time: " << distances.at(target_village) << " days";
				
				sf::Text travel_time_text(stream.str(), font);
				travel_time_text.setPosition(sf::Vector2f(0, 40));
				travel_time_text.setCharacterSize(30);
				travel_time_text.setStyle(sf::Text::Bold);
				travel_time_text.setFillColor(sf::Color::Yellow);

				sf::Sprite cart_sprite(cart);
				cart_sprite.setPosition(sf::Vector2f(village_map_coordinates[village].x, village_map_coordinates[village].y));

				window.clear();
				window.draw(map_background);
				window.draw(target_village_text);
				window.draw(travel_time_text);
				window.draw(highlighter);
				window.draw(cart_sprite);
				window.display();
			}
			else if (GameState == 1003) {
				window.close();
			}
			else if (GameState == 1100) {

			std::cout << std::abs(current_position.x) << std::endl;
			std::cout << std::abs(target_position.x) << std::endl;
			
			if (std::abs(current_position.x) - std::abs(target_position.x) < 0 || std::abs(current_position.y) - std::abs(target_position.y) < 0) {
				current_position.x -= del_x;
				current_position.y -= del_y;
			}
			else {
				village = targets.at(target_village);
				GameState = 1002;

			}

			sf::Sprite map_background(map_texture);

			highlighter.setPosition(village_map_coordinates[targets.at(target_village)].x - 7, village_map_coordinates[targets.at(target_village)].y - 7);

			sf::Sprite cart_sprite(cart);
			cart_sprite.setPosition(sf::Vector2f(current_position.x, current_position.y));

			window.clear();
			window.draw(map_background);
		//	window.draw(target_village_text);
		//	window.draw(travel_time_text);
			window.draw(highlighter);
			window.draw(cart_sprite);
			window.display();
			}
		
		float endFrame = clock.getElapsedTime().asMilliseconds();

		while (endFrame - startFrame < 16.667f) {
			endFrame = clock.getElapsedTime().asMilliseconds();
		}
		buttonPressed += clock.getElapsedTime().asMilliseconds();
	}

	return 0;
}