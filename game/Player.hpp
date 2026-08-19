#pragma once

class Player {

    
    public:
        Player();
        ~Player();
        void Draw();
        void Update();
        Rectangle GetRect();
        void DrawHitbox(bool isColliding);
        void outOfBounds();
        int points;
    private:
        Texture2D m_spriteUp;
        Texture2D m_spriteDown;

        bool m_movingUp;
        bool m_movingDown;

        bool m_isFacingDown;
        bool m_isFacingUp;
        bool m_isAlive;

        Vector2 m_position;
        float m_playerMoveSpeed;





};