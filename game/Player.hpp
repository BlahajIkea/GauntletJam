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
        
        void StartingUI();
        int score;
        bool isAlive;

    private:
        Texture2D m_spriteUp; 
        Texture2D m_spriteDown;
        Texture2D m_mainMenuUI;
        Texture2D  m_spriteDead;
        Vector2 m_position;
        float m_playerMoveSpeed;
        int finalScore;
        float goToHospital;
};