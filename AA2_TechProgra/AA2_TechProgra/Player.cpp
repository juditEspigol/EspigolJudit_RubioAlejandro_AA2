#include "Player.h"

// CONSTRUCTOR
Player::Player(int health)
{
	m_name = "Link";
	m_sprite = PLAYER_UP;
	m_score = 0;
	m_health = health;
}

 // GETTERS 
std::string Player::GetName() const
 {
	 return m_name;
 }

int Player::GetPosX() const
 {
	 return m_posX;
 }

int Player::GetPosY() const
 {
	 return m_posY;
 }

 // PRIVATE METHODS 
void Player::SetPosition(char** myRoom)
 {
	 myRoom[m_posY][m_posX] = m_sprite;
 }

bool Player::CheckNextPos(char** myRoom)
 {
	 bool canMove = true;

	 switch (m_move)
	 {
	 case Movement::UP:
		 if (myRoom[m_posY - 1][m_posX] == CHAR_WALL || myRoom[m_posY - 1][m_posX] == CHAR_POT)
			 canMove = false;
		 break;
	 case Movement::LEFT:
		 if (myRoom[m_posY][m_posX - 1] == CHAR_WALL || myRoom[m_posY][m_posX - 1] == CHAR_POT)
			 canMove = false;
		 break;
	 case Movement::RIGHT:
		 if (myRoom[m_posY][m_posX + 1] == CHAR_WALL || myRoom[m_posY][m_posX + 1] == CHAR_POT)
			 canMove = false;
		 break;
	 case Movement::DOWN:
		 if (myRoom[m_posY + 1][m_posX] == CHAR_WALL || myRoom[m_posY + 1][m_posX] == CHAR_POT)
			 canMove = false;
		 break;
	 default:
		 break;
	 }

	 return canMove;
 }

void Player::ClearPosPlayer(char** myRoom)
 {
	 myRoom[m_posY][m_posX] = CHAR_EMPTY;
 }

 // PUBLIC METHODS 
void Player::PrintPlayer(const Movement& movement)
 {

	 switch (movement)
	 {
	 case Movement::UP:
		 m_sprite = PLAYER_UP;
		 break;
	 case Movement::LEFT:
		 m_sprite = PLAYER_LEFT;
		 break;
	 case Movement::RIGHT:
		 m_sprite = PLAYER_RIGHT;
		 break;
	 case Movement::DOWN:
		 m_sprite = PLAYER_DOWN;
		 break;
	 default:
		 break;
	 }
	 std::cout << m_sprite;
 }

void Player::MovementPlayer(char** myRoom, const int& width, const int& height)
{

	if (GetAsyncKeyState(VK_UP))
	{
		m_move = Movement::UP;
		m_sprite = PLAYER_UP;

		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			AddScore(myRoom,m_move);
			m_posY--;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_move = Movement::LEFT;
		m_sprite = PLAYER_LEFT;

		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			AddScore(myRoom, m_move);
			m_posX--;
		}
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_move = Movement::RIGHT;
		m_sprite = PLAYER_RIGHT;
		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			AddScore(myRoom, m_move);
			m_posX++;
		}
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_move = Movement::DOWN;
		m_sprite = PLAYER_DOWN;

		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			AddScore(myRoom, m_move);
			m_posY++;
		}
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		Attack(myRoom, m_move);
	}

	SetPosition(myRoom);
}

void Player::PosPlayerPrevRoom(char** myRoom, const int& width, const int& height)
{
	m_posY = 1;
	m_posX = width / 2;

	SetPosition(myRoom); 
}

void Player::PosPlayerNextRoom(char** myRoom, const int& width, const int& height)
{
	m_posY = height - 2;
	m_posX = width / 2;

	SetPosition(myRoom);
}

bool Player::CollidesWithPrevDoor(const int& prevDoorX, const int& height)
{
	if (m_posX == prevDoorX && m_posY == height - 1)
		return true;
	return false;
}

bool Player::CollidesWithNextDoor(const int& nextDoorX)
{
	if (m_posX == nextDoorX && m_posY == 0)
		return true; 
	return false; 
}

void Player::Attack(char** myRoom,const Movement& move)
{
	switch (move)
	{
	case Movement::UP:
		if (myRoom[m_posY - 1][m_posX] == CHAR_POT)
			myRoom[m_posY - 1][m_posX] = spawnRandomGem(); //myRoom[m_posY - 1][m_posX] = CHAR_EMPTY;
		break;
	case Movement::LEFT:
		if (myRoom[m_posY][m_posX - 1] == CHAR_POT)
			myRoom[m_posY][m_posX - 1] = spawnRandomGem();
		break;
	case Movement::RIGHT:
		if (myRoom[m_posY][m_posX + 1] == CHAR_POT)
			myRoom[m_posY][m_posX + 1] = spawnRandomGem();
		break;
	case Movement::DOWN:
		if (myRoom[m_posY + 1][m_posX] == CHAR_POT)
			myRoom[m_posY + 1][m_posX] = spawnRandomGem();
		break;
	default:
		break;
	}
}

int Player::GetScore()const
{
	return m_score;
}

void Player::AddScore(char** myRoom, const Movement& move)
{
	switch (move)
	{
	case Movement::UP:
		if (myRoom[m_posY - 1][m_posX] == CHAR_GEM_GREEN)
			m_score++;
		else if (myRoom[m_posY - 1][m_posX] == CHAR_GEM_BLUE)
			m_score += 5;
		else if (myRoom[m_posY - 1][m_posX] == CHAR_GEM_RED)
			m_score += 20;
		break;
	case Movement::LEFT:
		if (myRoom[m_posY][m_posX - 1] == CHAR_GEM_GREEN)
			m_score++;
		else if (myRoom[m_posY][m_posX - 1] == CHAR_GEM_BLUE)
			m_score += 5;
		else if (myRoom[m_posY][m_posX - 1] == CHAR_GEM_RED)
			m_score += 20;
		break;
	case Movement::RIGHT:
		if (myRoom[m_posY][m_posX + 1] == CHAR_GEM_GREEN)
			m_score++;
		else if (myRoom[m_posY][m_posX + 1] == CHAR_GEM_BLUE)
			m_score += 5;
		else if (myRoom[m_posY][m_posX + 1] == CHAR_GEM_RED)
			m_score += 20;
		break;
	case Movement::DOWN:
		if (myRoom[m_posY + 1][m_posX] == CHAR_GEM_GREEN)
			m_score++;
		else if (myRoom[m_posY + 1][m_posX] == CHAR_GEM_BLUE)
			m_score += 5;
		else if (myRoom[m_posY + 1][m_posX] == CHAR_GEM_RED)
			m_score += 20;
		break;
	default:
		break;
	}


	
}


int Player::GetHealth()const
{
	return m_health;
}

void Player::SubstractHealth(const int& value)
{
	m_health -= value;
}

Movement Player::GetDirection()const
{
	return m_move;
}

