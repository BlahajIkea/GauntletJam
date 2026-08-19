#pragma once

class Player {
    public:
        Player();
        ~Player();
        void Draw();
        void Update();
        Rectangle GetKillRect();
        void DrawHitbox(bool isColliding);
        void OutOfBounds();
        void RotateThePlayerAfterDeath();
        void DrawScore();
        void DrawFinalScore();
        void GainPoints();
        int score;
        bool isAlive;

    private:
        Texture2D m_spriteUp; 
        Texture2D m_spriteDown;
        Vector2 m_position;
        float m_playerMoveSpeed;
        int finalScore;
};