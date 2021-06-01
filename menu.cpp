#include "menu.hpp"

int menu::ID = 0;

menu::menu(int id, std::string name) : m_name(name), m_disabled(false), m_selected(false), m_id(id) {
    
}

menu& menu::operator[](const std::string& name) {
    if(m_indexes.count(name) == 0) {
        m_indexes[name] = m_options.size();
        m_options.push_back(menu(++ID, name));
    }
    return m_options[m_indexes[name]];
}

menu& menu::option(const int index) {
    return m_options[index];
}

menu& menu::setDissabled(bool dissabled) {
    m_disabled = dissabled;
    return *this;
}

std::string menu::getName() const {
    return m_name;
}

long menu::getNameLength() const {
    return m_name.length();
}

int menu::getItemsCount() const {
    return m_options.size();
}

int menu::getSelected() const {
    for (int i = 0; i < m_options.size(); i++) {
        if (m_options[i].isSelected()) return i;
    }
    return 0;
}

int menu::getID() const {
    return m_id;
}

void menu::setSelected(const bool value) {
    m_selected = value;
}

bool menu::isDisabled() const {
    return m_disabled;
}

std::vector<menu>::iterator menu::begin() {
    return m_options.begin();
}

std::vector<menu>::iterator menu::end() {
    return m_options.end();
}

bool menu::isSelected() const {
    return m_selected;
}