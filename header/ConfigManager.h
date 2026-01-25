#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace config
{
    struct Rectangle
    {
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color innerColor;
        sf::Color outerColor;
        float thickness;
    };

    struct RectangleX2 // Correction Typo: Recatangle -> Rectangle
    {
        Rectangle outer;
        Rectangle inner;
    }; // Correction: Point-virgule ajouté ici

    struct Circle 
    {
        sf::Vector2f position;
        float radius;
        sf::Color innerColor;
        sf::Color outerColor;
        float thickness;
    };

    // Data Storage
    inline std::string m_fileName;
    inline std::map<std::string, Rectangle> m_rectangle;
    inline std::map<std::string, RectangleX2> m_rectangleX2;
    inline std::map<std::string, Circle> m_circle;
    inline std::string m_form = "";

    // Default Values
    inline const Rectangle DEFAULT_RECTANGLE = { {0.f, 0.f}, {0.f, 0.f}, sf::Color::Red, sf::Color::Black, 2.0f };
    inline const RectangleX2 DEFAULT_RECTANGLEX2 = { DEFAULT_RECTANGLE, DEFAULT_RECTANGLE };
    inline const Circle DEFAULT_CIRCLE = { {0.f, 0.f}, 0.f, sf::Color::Red, sf::Color::Black, 2.0f };

    // Getters
    inline Rectangle getRectangle(const std::string& key)
    {
        auto it = m_rectangle.find(key);
        return (it != m_rectangle.end()) ? it->second : DEFAULT_RECTANGLE;
    }

    inline RectangleX2 getRectangleX2(const std::string& key)
    {
        auto it = m_rectangleX2.find(key);
        return (it != m_rectangleX2.end()) ? it->second : DEFAULT_RECTANGLEX2;
    }

    inline Circle getCircle(const std::string& key)
    {
        auto it = m_circle.find(key);
        return (it != m_circle.end()) ? it->second : DEFAULT_CIRCLE;
    }

    // Helper to safely parse strings to float/int
    inline float toF(const std::string& s) { return s.empty() ? 0.f : std::stof(s); }
    inline sf::Uint8 toU8(const std::string& s) { return s.empty() ? 0 : static_cast<sf::Uint8>(std::stoi(s)); }

    inline void parseRectangle(std::stringstream& ss, const std::string& key)
    {
        std::string x, y, w, h, r1, g1, b1, a1, r2, g2, b2, a2, t;
        
        std::getline(ss, x, ';'); std::getline(ss, y, ';');
        std::getline(ss, w, ';'); std::getline(ss, h, ';');
        std::getline(ss, r1, ';'); std::getline(ss, g1, ';'); std::getline(ss, b1, ';'); std::getline(ss, a1, ';');
        std::getline(ss, r2, ';'); std::getline(ss, g2, ';'); std::getline(ss, b2, ';'); std::getline(ss, a2, ';');
        std::getline(ss, t, ';');

        m_rectangle[key] = {
            {toF(x), toF(y)},
            {toF(w), toF(h)},
            {toU8(r1), toU8(g1), toU8(b1), toU8(a1)},
            {toU8(r2), toU8(g2), toU8(b2), toU8(a2)},
            toF(t)
        };
    }

    inline void parseRectangleX2(std::stringstream& ss, const std::string& key)
    {
        auto readRect = [&](std::stringstream& source) -> Rectangle {
            std::string x, y, w, h, r1, g1, b1, a1, r2, g2, b2, a2, t;
            std::getline(source, x, ';');  std::getline(source, y, ';');
            std::getline(source, w, ';');  std::getline(source, h, ';');
            std::getline(source, r1, ';'); std::getline(source, g1, ';'); std::getline(source, b1, ';'); std::getline(source, a1, ';');
            std::getline(source, r2, ';'); std::getline(source, g2, ';'); std::getline(source, b2, ';'); std::getline(source, a2, ';');
            std::getline(source, t, ';');

            return {
                {toF(x), toF(y)},
                {toF(w), toF(h)},
                {toU8(r1), toU8(g1), toU8(b1), toU8(a1)},
                {toU8(r2), toU8(g2), toU8(b2), toU8(a2)},
                toF(t)
            };
        };

        m_rectangleX2[key] = { readRect(ss), readRect(ss) };
    }

    inline void parseCircle(std::stringstream& ss, const std::string& key)
    {
        std::string x, y, rad, r1, g1, b1, a1, r2, g2, b2, a2, t;
        
        std::getline(ss, x, ';'); std::getline(ss, y, ';');
        std::getline(ss, rad, ';');
        std::getline(ss, r1, ';'); std::getline(ss, g1, ';'); std::getline(ss, b1, ';'); std::getline(ss, a1, ';');
        std::getline(ss, r2, ';'); std::getline(ss, g2, ';'); std::getline(ss, b2, ';'); std::getline(ss, a2, ';');
        std::getline(ss, t, ';');

        m_circle[key] = {
            {toF(x), toF(y)},
            toF(rad),
            {toU8(r1), toU8(g1), toU8(b1), toU8(a1)},
            {toU8(r2), toU8(g2), toU8(b2), toU8(a2)},
            toF(t)
        };
    }

    inline bool load(const std::string& fileName)
    {
        m_fileName = fileName;
        std::ifstream file(fileName);
        if (!file.is_open()) return false;

        m_rectangle.clear();
        m_rectangleX2.clear();
        m_circle.clear();
        m_form = "";

        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty() || line[0] == '#') continue;

            std::stringstream ss(line);
            std::string firstToken;
            std::getline(ss, firstToken, ';');

            if (firstToken == "RECTANGLE" || firstToken == "CIRCLE" || firstToken == "RECTANGLEX2") {
                m_form = firstToken;
                continue;
            }

            if (m_form == "RECTANGLE") parseRectangle(ss, firstToken);
            else if (m_form == "CIRCLE") parseCircle(ss, firstToken);
            else if (m_form == "RECTANGLEX2") parseRectangleX2(ss, firstToken);
        }

        file.close();
        return true;
    }

    inline void reload() { if (!m_fileName.empty()) load(m_fileName); }
}

#endif
