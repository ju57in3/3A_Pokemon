//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_HEALTHBAR_H
#define PROJECT_HEALTHBAR_H

#pragma once
#include <SFML/Graphics.hpp>

class HealthBar {
public:
    explicit HealthBar(const sf::Texture& gaugeTex) {
        sprite.setTexture(gaugeTex);
        sprite.setScale(0.5f, 0.5f); // ajuste à ta fenêtre
    }
    void setMax(int m) { max = m; value = std::min(value, max); }
    void setValue(int v) { value = std::max(0, std::min(v, max)); }
    void setPosition(float x, float y) { sprite.setPosition(x, y); }
    void draw(sf::RenderTarget& rt) const {
        // on “rognent” le sprite en fonction du pourcentage
        sf::Sprite sub = sprite;
        float ratio = max > 0 ? (float)value / (float)max : 0.f;
        sf::IntRect r = sub.getTextureRect();
        if (r.width == 0) { // première fois
            r = sf::IntRect(0, 0, sub.getTexture()->getSize().x, sub.getTexture()->getSize().y);
        }
        r.width = static_cast<int>(r.width * ratio);
        sub.setTextureRect(r);
        rt.draw(sub);
    }
private:
    mutable sf::Sprite sprite;
    int max{100}, value{100};
};


#endif //PROJECT_HEALTHBAR_H